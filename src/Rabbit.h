#ifndef SP_RABBIT_SIMULATION_RABBIT_H
#define SP_RABBIT_SIMULATION_RABBIT_H

// https://perso.isima.fr/~dahill/Simu-ZZ2/Lab%20%23%204%20-%20Rabbit%20Population%20growth%20in%20C++.pdf

#include "Stats.h"

enum SEX { FEMALE, MALE };

class Rabbit {
    int age; // en mois
    float deathRate;

    public:
    // TODO: random between 5 - 8?
    static const int MATURITY = 12; // Nombre de mois avant d'attendre la maturite
    static const int FEMALES_PER_MALE = 15;

    static Rabbit* createRabbit();

    Rabbit();

    virtual SEX getSex() const = 0;
    int getAge() const;
    bool shouldDie() const;
    bool isMature() const;
    virtual void grow(Stats &stats);
};

#endif //SP_RABBIT_SIMULATION_RABBIT_H