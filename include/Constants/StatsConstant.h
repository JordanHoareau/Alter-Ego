#ifndef STATSCONSTANT_H
#define STATSCONSTANT_H

enum Gender {female=0, male};
enum Class {ranger, warrior};
enum Weapon {daggers, greatsword};

namespace StatsConstant{

    const int CaracsNumber(3);
    const int StrengthID(0);
    const int AgilityID(1);
    const int ToughnessID(2);

    const int StatsNumber(6);
    const int HealthID(0);
    const int SpellDmgID(1);
    const int WeaponDmgID(2);
    const int ResistanceID(3);
    const int CritChanceID(4);
    const int SpeedID(5);

    const int CaracsRatio[CaracsNumber][StatsNumber] = {{10,5,5,5,0,0},     // Strength
                                                        {10,5,5,5,0,0},     // Agility
                                                        {20,0,0,20,0,0}     // Toughness
                                                       };
}
#endif // STATSCONSTANT_H
