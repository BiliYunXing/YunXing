#include "avz.h"

using namespace AvZ;

void Script()
{
    SetZombies({CG_3,
                TT_4,
                QQ_16,
                FT_21,
                TL_22,
                BY_23,
                HY_32,
                TT_18,
                CG_3,
                WW_8,
                BC_12,
                KG_17,
                HT_14,
                QS_11});

    SelectCards({ICE_SHROOM,
                 JALAPENO,
                 PUFF_SHROOM,
                 STARFRUIT,
                 FUME_SHROOM,
                 FLOWER_POT,
                 CHERRY_BOMB,
                 DOOM_SHROOM,
                 M_ICE_SHROOM,
                 LILY_PAD});
    pao_operator.autoGetPaoList();
    AvZ::MaidCheats::callPartner();
    for (auto wave : {1, 2, 3, 7})
    {
        SetTime(-147, wave);
        pao_operator.pao({{2, 9}, {5, 9}});
        Delay(109);
        pao_operator.pao({{1, 7.8}, {5, 7.8}});
    }

    for (auto wave : {4})
    {
        SetTime(-14, wave);
        pao_operator.pao({{2, 9}, {5, 9}});
        Delay(107);
        pao_operator.pao({{1, 7.8}, {5, 7.8}});
    }
    for (auto wave : {5})
    {
        SetTime(-99, wave);
        Card(ICE_SHROOM, 2, 1);
        SetTime(1200 - 200 - 100, wave);
        Card({{LILY_PAD, 3, 9}, {DOOM_SHROOM, 3, 9}});
        SetTime(1200 - 573 + 213);
        pao_operator.pao({{1, 8.475}, {5, 8.475}});
    }
    for (auto wave : {6})
    {
        SetTime(-147, wave);
        pao_operator.pao({{2, 8.75}, {5, 8.65}});
        Delay(250);
        pao_operator.pao({{1, 2.5}, {5, 2.5}});
        SetTime(-147 + 373 - 100, wave);
        Card(JALAPENO, 1, 8);
    }
    for (auto wave : {8})
    {
        SetTime(-14, wave);
        pao_operator.pao({{2, 9}, {5, 9}});
        Delay(107);
        pao_operator.pao({{1, 7.8}, {5, 7.8}});
        SetTime(605 - 420, wave);
        Card(M_ICE_SHROOM, 2, 1);
        SetPlantActiveTime(M_ICE_SHROOM, 420);
    }
    for (auto wave : {9})
    {
        SetTime(1310 - 573, wave);
        pao_operator.pao({{2, 8.8}, {5, 8.8}});
        Delay(213);
        pao_operator.pao({{1, 8.4}, {5, 8.4}});
        Delay(365);
        pao_operator.pao({{1, 2.5}, {5, 2.5}});
        pao_operator.recoverPao({{2, 9}, {5, 9}, {2, 8}, {5, 8}});
    }
    // 2f
    for (auto wave : {10})
    {
        SetTime(-95, wave);
        pao_operator.pao({{2, 9}, {5, 9}, {2, 9}, {5, 9}});
        Delay(109);
        pao_operator.pao({{1, 8.8}, {5, 8.8}});
        SetTime(605 - 420, wave);
        Card(M_ICE_SHROOM, 2, 1);
        SetPlantActiveTime(M_ICE_SHROOM, 420);
    }
    for (auto wave : {11, 17})
    {
        SetTime(1300 - 573, wave);
        pao_operator.pao({{2, 9}, {5, 9}});
        Delay(213);
        pao_operator.pao({{1, 8.4}, {5, 8.4}});
    }
    for (auto wave : {12, 18})
    {
        SetTime(-147, wave);
        pao_operator.pao({{2, 8.65}, {5, 8.65}});
        Delay(250);
        pao_operator.pao({{1, 2.5}, {5, 2.5}});
        SetTime(-147 + 373 - 100, wave);
        Card(JALAPENO, 1, 8);
    }
    for (auto wave : {13})
    {
        SetTime(-99, wave);
        Card(ICE_SHROOM, 1, 1);
        SetTime(1300 - 573, wave);
        pao_operator.pao({{2, 8.8}, {5, 8.8}});
        Delay(213);
        pao_operator.pao({{1, 8.4}, {5, 8.4}});
    }
    for (auto wave : {14})
    {
        SetTime(-147, wave);
        pao_operator.pao({{2, 8.75}, {5, 8.65}});
        Delay(250);
        pao_operator.pao({{1, 2.5}, {5, 2.5}});
        SetTime(-147 + 373 - 100, wave);
        Card(CHERRY_BOMB, 1, 8);
    }
    for (auto wave : {15})
    {
        SetTime(-147 + 373 - 100, wave);
        Card({{LILY_PAD, 4, 9}, {DOOM_SHROOM, 4, 9}});
        SetTime(-147 + 109, wave);
        pao_operator.pao({{1, 7.8}, {5, 7.8}});
        SetTime(567, wave);
        Card({{FLOWER_POT, 1, 8}, {PUFF_SHROOM, 6, 8}});
    }
    for (auto wave : {16})
    {
        SetTime(-147 + 51, wave);
        pao_operator.pao({{2, 8.8}, {5, 8.8}});
        Delay(109);
        pao_operator.pao({{1, 7.8}, {5, 7.8}});
        SetTime(605 - 420, wave);
        Card(M_ICE_SHROOM, 2, 1);
        SetPlantActiveTime(M_ICE_SHROOM, 420);
    }
    for (auto wave : {19})
    {
        SetTime(-99, wave);
        Card(ICE_SHROOM, 1, 1);
        SetTime(1300 - 573, wave);
        pao_operator.pao({{2, 8.8}, {5, 8.8}});
        Delay(213);
        pao_operator.pao({{1, 8.4}, {5, 8.4}});
        Delay(213);
        pao_operator.pao({{1, 8.8}, {5, 8.8}});
        pao_operator.recoverPao({{1, 9}, {5, 9}, {1, 8.5}, {5, 8.5}});
    }
    for (auto wave : {20})
    {
        SetTime(-75, wave);
        Card(ICE_SHROOM, 1, 1);
    }
}