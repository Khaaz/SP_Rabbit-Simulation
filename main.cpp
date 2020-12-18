#include <iostream>
#include <chrono>
#include <sstream>
#include <cmath>

#include "src/Simulation.h"
#include "src/Constant.h"

float STUDENT[34] = { 12.706, 4.303, 3.182, 2.776, 2.571, 2.447, 2.365, 2.308, 2.262, 2.228, 2.201,
                      2.179, 2.160, 2.145, 2.131, 2.120, 2.110, 2.101, 2.093, 2.086, 2.080, 2.074,
                      2.069, 2.064, 2.060, 2.056, 2.052, 2.048,2.045, 2.042, 2.021, 2.000, 1.980, 1.960 };

double* trustInterval(double mean, long* pop, int nbExperiments) {
    double s = 0, r = 0, t = 0;
    double* interval = new double[2] {0};

    for(int i = 0; i < nbExperiments; ++i) {
        s += pow(pop[i] - mean, 2);
    }
    s = s / (nbExperiments - 1);

    if (nbExperiments <= 30) {
        t = STUDENT[nbExperiments - 1];
    } else if(nbExperiments < 40) {
        t = STUDENT[30];
    } else if(nbExperiments < 80) {
        t = STUDENT[31];
    } else if(nbExperiments < 120) {
        t = STUDENT[32];
    } else {
        t = STUDENT[33];
    }

    r = t * sqrt(s / nbExperiments);

    interval[0] = mean - r;
    interval[1] = mean + r;
    return interval;
}

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

long runOne(int duration, int startingCouple, int seed) {
    auto start = std::chrono::high_resolution_clock::now();
    long pop = 0;

    std::cout << "Simulation sur " << duration << "ans. Couples de depart: " << startingCouple << std::endl;

    Simulation simulation(duration, startingCouple, seed);
    pop = simulation.run();
    simulation.displayStats();
    writeFile(seed, startingCouple, duration, simulation);

    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << "ms" << std::endl << std::endl;

    return pop;
}

void runMany(int numberToRun, int duration, int startingCouple, int baseSeed = SEED) {
    int seed = baseSeed;
    double mean = 0;
    double* interval;
    long* pop = new long[numberToRun];
    long popTotal = 0;

    for (int i = 0; i < numberToRun; ++i) {
        pop[i] = runOne(duration, startingCouple, seed);
        popTotal += pop[i];
        ++seed;
    }

    mean = (float)popTotal / (float)numberToRun;

    interval = trustInterval(mean, pop, numberToRun);

    std::cout << std::endl;
    std::cout << "Intervalle de confiance à 95%:" << std::endl;
    std::cout << "[" << interval[0] << " ; " << interval[1] << "]" << std::endl;
}



int main() {
    runMany(120, 6, 10, 999999);
    return 0;
}
