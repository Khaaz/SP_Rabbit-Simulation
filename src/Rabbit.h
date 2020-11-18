#ifndef SP_RABBIT_SIMULATION_RABBIT_H
#define SP_RABBIT_SIMULATION_RABBIT_H

// https://perso.isima.fr/~dahill/Simu-ZZ2/Lab%20%23%204%20-%20Rabbit%20Population%20growth%20in%20C++.pdf
enum SEX { FEMALE, MALE };

class Rabbit {
    int age; // en mois
    float survivalRate;

    public:
    //Nombre de mois avant d'attendre la maturite
    static const int MATURITY = 12; // TODO: random between 5 - 8?
    static const int FEMALES_PER_MALE = 15;

    Rabbit();
    // ~Rabbit();
    //Rabbit(const Rabbit& rabbit);
    static Rabbit& createRabbit();

    virtual SEX getSex() const = 0;
    int getAge();
    bool shouldDie();
    bool canReproduce();
};

// les gros baiseurs (adulte): 60 % survival rate
// petits minus: 35% survival rate
// vieux croutons (10 year old): 10 % en moins par an , peut baiser des 1 ans ou plus , taux fertilité qui baisse
// 16 = mort

// female = 4 - 8 litters per year
// more chance to have 5 6 7 litters than 4 and 8
// litter = 3 to 6 rabbit
// taux de lapinou trop chou qui meurent instant
// taux mortalite lapine qui pond un lapinou

// proba de se faire bouffer la gueule
// proba de mourir comme une merde
// proba de mourir du covid

// varier initial pop

//12 * x = 0.35
  //      0.35 / 12
//

#endif //SP_RABBIT_SIMULATION_RABBIT_H