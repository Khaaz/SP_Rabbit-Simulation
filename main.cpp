#include <iostream>
#include <chrono>

#include "src/Simulation.h"
#include "src/Constant.h"

void runOne(int duration, int startingCouple, int seed) {
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "Simulation sur " << duration << "ans. Couples de depart: " << startingCouple << std::endl;

    Simulation simulation(duration, startingCouple, seed);
    simulation.run();
    simulation.displayStats();

    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << "ms" << std::endl << std::endl;
}

void runMany(int numberToRun, int duration, int startingCouple, int baseSeed = SEED) {
    int seed = baseSeed;
    for (int i = 0; i < numberToRun; ++i) {
        runOne(duration, startingCouple, seed);
        ++seed;
    }
}

int main() {
    runMany(2, 6, 20, 2);
    return 0;
}

