#include <random>
#include "Util.h"
#include "Constant.h"

float randomBetween(float a, float b) {
    static std::mt19937 generator (SEED);
    std::uniform_real_distribution<double> dis(a, b);

    return dis(generator);
}