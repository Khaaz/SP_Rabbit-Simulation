#include <iostream>
#include "src/Simulation.h"

int main() {
    std::cout << "Simulation sur 10 ans. Couple de depart: 2" << std::endl;
    Simulation simulation(5, 2);
    simulation.run();
    simulation.displayStats();
    return 0;
}
