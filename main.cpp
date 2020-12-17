#include <iostream>
#include <chrono>
#include <sstream>

#include "src/Simulation.h"
#include "src/Constant.h"

void writeFile(int seed, int startPop, int duration, Simulation& simulation) {

    std::ostringstream oss;
    oss << "results/" << "p" << startPop << "_" << duration << "y_s" << seed << ".txt";
    std::string name = oss.str();

    std::ofstream outfile (name);

    outfile << "Seed: " << seed << std::endl;
    outfile << "startPop: " << startPop << std::endl;
    outfile << "duration: " << duration << std::endl << std::endl << std::endl;
    simulation.writeStats(outfile);

    outfile.close();
}

void runOne(int duration, int startingCouple, int seed) {
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "Simulation sur " << duration << "ans. Couples de depart: " << startingCouple << std::endl;

    Simulation simulation(duration, startingCouple, seed);
    simulation.run();
    simulation.displayStats();
    writeFile(seed, startingCouple, duration, simulation);

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
    runMany(1, 7, 10, 100);
    return 0;
}
