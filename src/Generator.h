#ifndef SP_RABBIT_SIMULATION_GENERATOR_H
#define SP_RABBIT_SIMULATION_GENERATOR_H

#include <random>

/**
 * @brief Represente un generateur aleatoire utilisant mersenne twister
 */
class Generator {
    static std::mt19937& get();

    public:
    static double randomBetween(float, float);
    static void seed(int seed);
};

#endif