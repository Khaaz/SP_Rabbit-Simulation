#ifndef SP_RABBIT_SIMULATION_FEMALERABBIT_H
#define SP_RABBIT_SIMULATION_FEMALERABBIT_H

#include "Rabbit.h"

class MaleRabbit;

class FemaleRabbit : public Rabbit {
    static const int GESTATION = 1;
    bool isPregnant;

    public:
    // FemaleRabbit();
    //~FemaleRabbit();
    //FemaleRabbit(const FemaleRabbit&);

    void reproduce(MaleRabbit &male);
    SEX getSex() const override;
};


#endif //SP_RABBIT_SIMULATION_FEMALERABBIT_H
