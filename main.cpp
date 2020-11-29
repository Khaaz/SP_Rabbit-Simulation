#include <iostream>
#include <chrono>
#include "src/Simulation.h"

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Simulation sur 10 ans. Couple de depart: 2" << std::endl;
    Simulation simulation(20, 2);
    simulation.run();
    simulation.displayStats();
    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << "ms" << std::endl;
    return 0;
}
