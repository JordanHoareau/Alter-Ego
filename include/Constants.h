#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants{
    const int IntroState(1);
    const int CinematicState(2);
    const int PlayState(3);
    const int MoveState(4);
    const int BattleState(5);
    const int MenuState(6);
    const int QuestState(7);
    const int InventoryState(8);
    const int SettingsState(9);

    const int StrengthHealthRatio(10);
    const int StrengthSpellDmgRatio(5);
    const int StrengthWeaponDmgRatio(5);
    const int StrengthResistanceRatio(5);
    const int StrengthCritChanceRatio(0);
    const int StrengthSpeedRatio(0);

    const int AgilityHealthRatio(0);
    const int AgilitySpellDmgRatio(10);
    const int AgilityWeaponDmgRatio(10);
    const int AgilityResistanceRatio(0);
    const int AgilityCritChanceRatio(0);
    const int AgilitySpeedRatio(5);

    const int ToughnessHealthRatio(20);
    const int ToughnessSpellDmgRatio(0);
    const int ToughnessWeaponDmgRatio(0);
    const int ToughnessResistanceRatio(20);
    const int ToughnessCritChanceRatio(0);
    const int ToughnessSpeedRatio(0);
};

#endif // CONSTANTS_H
