#ifndef SP_RABBIT_SIMULATION_SIMULATION_H
#define SP_RABBIT_SIMULATION_SIMULATION_H

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

#include "Rabbit.h"
#include "MaleRabbit.h"
#include "FemaleRabbit.h"
#include "Stats.h"

/**
 * @brief represente une simulation
 */
class Simulation {
    int duration; // duree en mois
    int femaleAdults; // nombre de femelle actuellement dans la population
    int maleAdults; // nombre de males actuellement dans la population
    std::vector<std::unique_ptr<Rabbit>> rabbits; // population actuelle de lapins
    Stats stats; // statistiques pour cette simulation
    void deleteRabbit(int index);

    public:
    Simulation(int duration, int startingCouple, int seed);
    long run();
    void displayStats();
    void writeStats(std::ostream& outfile);
};


#endif //SP_RABBIT_SIMULATION_SIMULATION_H
