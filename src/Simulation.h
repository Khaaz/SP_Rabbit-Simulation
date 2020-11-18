#ifndef SP_RABBIT_SIMULATION_SIMULATION_H
#define SP_RABBIT_SIMULATION_SIMULATION_H

#include <vector>
#include "Rabbit.h"
#include "MaleRabbit.h"
#include "FemaleRabbit.h"

class Simulation {
    int duration;
    int adultFemale;
    int adultMale;
    std::vector<Rabbit> rabbits;
    void deleteRabbit(int index);
    public:
        Simulation(int duration, int startingCouple);
        void run();
};


#endif //SP_RABBIT_SIMULATION_SIMULATION_H
