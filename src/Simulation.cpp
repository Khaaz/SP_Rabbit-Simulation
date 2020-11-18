#include "Simulation.h"

#include "iostream"

Simulation::Simulation(int duration, int startingCouple) : duration(duration * 12),adultFemale(0),adultMale(0) {
    for(int i = 0; i < startingCouple; i++) {
        rabbits.push_back(MaleRabbit{} );
        rabbits.push_back(FemaleRabbit{} );
    }
    rabbits.push_back(Rabbit::createRabbit());
}

void Simulation::deleteRabbit(int index) {
    rabbits[index].getSex() == SEX::MALE
        ? --adultMale
        : --adultFemale;

    rabbits.erase(rabbits.begin() + index);
}

void Simulation::run() {
    int j, size;
    for(int i = 0; i < duration ; i++) {
        j = 0;
        // verif qu'ils meurent ou pas
        while (j < rabbits.size()) {

            if (rabbits[j].shouldDie()) {
                deleteRabbit(j);
            } else {
                j++;
            }
        }
        while(rabbits.size() > j && rabbits[j].canReproduce()) {

        }
        // verif qu'ils se reproduisent
        // ++age
    }
}