#include "Generator.h"
#include "Constant.h"

/**
 * @brief Genere un nombre aléatoire entre deux nombres.
 * Utilises le generateur de mersenne twister
 *
 * @param a float
 * @param b float
 * @return float
 */
double Generator::randomBetween(float a, float b) {
    std::uniform_real_distribution<double> dis(a, b);

    return dis(Generator::get());
}

/**
 * @brief The generateur mersenne twister
 *
 * @return
 */
std::mt19937& Generator::get() {
    static std::mt19937 generator(SEED);
    return generator;
}

/**
 * @brief Change la seed du generateur
 *
 * @param seed
 */
void Generator::seed(int seed) {
    Generator::get().seed(seed);
}