#include "avz.h"
#include "Constant.h"
#include "Simplify.h"
#include "dance_cheat.h"
#include "SelectCardsPlus.h"

using namespace AvZ;
using namespace _qrmd;

#define HTQT_Time 419   //正常波海豚最早跳八列炮时机
#define HTQTw10_Time 520//旗子波海豚最早跳八列炮时机

void P(int r, int c)
{
    p.pp(r, c);
}

void PDD()
{
    P(5, 9);
    Delay(DPao_Time);
    P(5, 9);
    Delay(DPao_Time);
    P(5, 9);
}
//快速关
void FastFlag(int wave)
{
    SetTime(HTQT_Time - Pao_Time - 10, wave);
    P(2, 9);
    SetTime(-60, wave);
    P(5, 9);
    SetTime(HTQT_Time - Pao_Time - 10, wave);
    P(5, 9);
    SetTime(485 - 373, wave);
    P(5, 9);
}
//慢速关
void SlowFlag(int wave)
{

    SetTime(HTQT_Time - Pao_Time - 10, wave);
    P(2, 9);
    SetTime(FullHarmPao - Pao_Time, wave);
    PDD();
}
//收尾智能炸剩余僵尸
void SW(int wave)
{
    SetTime(1000 - Pao_Time, wave);
    InsertOperation([=]()
                    {
                        SetNowTime();
                        if (IsZombieExist()) //判断有没有僵尸在场上
                        {
                            P(2,9);
                            P(5,9);
                             //有僵尸就开两炮
                        } });
}

void Script()
{
    /* 多次生效 */
    OpenMultipleEffective('T', MAIN_UI_OR_FIGHT_UI);

    /* 设置倍速*/
    SetGameSpeed(10);

    /* 跳帧 */
    auto condition = [=]()
    {
        std::vector<int> results;
        GetPlantIndices({{6, 7}}, YMJNP_47, results);

        for (auto result : results)
        {
            if (result < 0)
            {
                return false;
            }
        }
        return true;
    };
    auto callback = [=]()
    {
        ShowErrorNotInQueue("什么勾八动静");
    };
    SkipTick(condition, callback);

    /*选卡*/
    SelectCardsPlus({{STARFRUIT,
                      THREEPEATER,
                      CATTAIL,
                      CACTUS,
                      COB_CANNON,
                      SPIKEROCK,
                      GOLD_MAGNET,
                      WINTER_MELON,
                      GLOOM_SHROOM,
                      TWIN_SUNFLOWER}});

    SetTime(-599, 1);
    auto Zombie_Type = GetMainObject()->zombieTypeList(); //获得当前选卡僵尸类型列表
    int WaveType = 2;                                     //由类型决定轨道

    /*三人组加速
    后记
    具体效果见https://tieba.baidu.com/p/7921781826
    最早全收三人组正常波485->308，旗帜波813->533
    海豚起跳419，大春告诉我海豚起跳有概率啃（但是概率有亿点点低）
    我的评价是：你游bug太多，正好这个bug解决了三人组和啃炮的取舍问题（其实就算不全收延迟概率也基本没有，起码几千f下来无延迟）
    顺达一提二爷是什么急八，两次破阵都是二爷搞事*/
    DanceCheat(FAST);

    //慢速关用轨道1
    //快速关用轨道2
    if (!Zombie_Type[HY_32] && !Zombie_Type[BY_23])
        WaveType = 2;
    else
        WaveType = 1;

    /*读取炮列表*/
    p.autoGetPaoList();

    //咆哮珊瑚
    for (auto wave : {20})
    {
        SetTime(-150, wave);
        P(4, 7.5875);
    }

    //慢速关轨道
    if (WaveType == 1)
    {
        //主体循环
        //慢速关
        // P/PDD
        for (auto wave : {1, 2, 3, 4, 5, 6, 7, 8, 11, 12, 13, 14, 15, 16, 17, 18})
        {
            SlowFlag(wave);
        }
        // tips：判断刷新延迟爱用不用，洪水谈刷新延迟就是个笑话
        for (auto wave : {10})
        {
            SetTime(HTQTw10_Time - Pao_Time - 10, wave);
            P(2, 9);
            SetTime(-60, wave);
            PDD();
        }
        //收尾
        for (auto wave : {9, 19, 20})
        {
            SlowFlag(wave);
            SW(wave);
        }
    }
    else if (WaveType == 2)
    {
        //主体循环
        //快速关
        // P/PDD
        for (auto wave : {1, 2, 3, 4, 5, 6, 7, 8, 11, 12, 13, 14, 15, 16, 17, 18})
        {
            FastFlag(wave);
        }
        // tips：判断刷新延迟爱用不用，洪水谈刷新延迟就是个笑话
        for (auto wave : {10})
        {
            SetTime(HTQTw10_Time - Pao_Time - 10, wave);
            P(2, 9);
            SetTime(-60, wave);
            P(5, 9);
            SetTime(HTQTw10_Time - Pao_Time - 10, wave);
            P(5, 9);
        }
        //收尾
        for (auto wave : {9, 19, 20})
        {
            FastFlag(wave);
            SW(wave);
        }
    }
} //感谢您能抽出宝贵的时间看逼人的屑脚本