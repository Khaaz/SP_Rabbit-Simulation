#ifndef SP_RABBIT_SIMULATION_RABBIT_H
#define SP_RABBIT_SIMULATION_RABBIT_H

// https://perso.isima.fr/~dahill/Simu-ZZ2/Lab%20%23%204%20-%20Rabbit%20Population%20growth%20in%20C++.pdf

enum class SEX { FEMALE, MALE };

class Stats;

/**
 * @brief Represente un lapin
 */
class Rabbit {
    int age; // age en mois
    float deathRate; // probabilite de mourir
    int maturity; // age en mois de maturite d'un lapin (age auquel il peut procreer)

    public:
    static const int FEMALES_PER_MALE = 15; // nombre de femelles pouvant etre fecondee par un male

    static Rabbit* createRabbit();

    Rabbit();

    virtual SEX getSex() const = 0;
    int getAge() const;
    bool shouldDie() const;
    bool isMature() const;
    virtual void grow(Stats &stats);
};

#endif //SP_RABBIT_SIMULATION_RABBIT_H