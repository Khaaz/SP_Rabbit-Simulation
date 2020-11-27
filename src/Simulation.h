#ifndef SP_RABBIT_SIMULATION_SIMULATION_H
#define SP_RABBIT_SIMULATION_SIMULATION_H

#include <vector>
#include <memory>
#include "Rabbit.h"
#include "MaleRabbit.h"
#include "FemaleRabbit.h"
#include "Stats.h"

class Simulation {
    int duration; // mois
    int adultFemale;
    int adultMale;
    std::vector<std::unique_ptr<Rabbit>> rabbits;
    void deleteRabbit(int index);
    Stats stats;

    public:
    Simulation(int duration, int startingCouple);
    void run();
    void displayStats();
};


#endif //SP_RABBIT_SIMULATION_SIMULATION_H
