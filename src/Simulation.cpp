#include "iostream"

#include "Generator.h"
#include "Simulation.h"

/**
 * @brief Construct a new Simulation:: Simulation object
 * Genere le couple initial dans la population initiale.
 * 
 * @param duration int - la duree en mois
 * @param startingCouple int - le nombre de couple de depart
 * @param seed ind - la seed a utiliser pour cette simulation
 */
Simulation::Simulation(int duration, int startingCouple, int seed) : duration(duration * 12), femaleAdults(0), maleAdults(0) {
    Generator::seed(seed);

    for(int i = 0; i < startingCouple; i++) {
        rabbits.push_back(std::unique_ptr<Rabbit>(new MaleRabbit) );
        rabbits.push_back(std::unique_ptr<Rabbit>(new FemaleRabbit) );
    }
}

/**
 * @brief Supprime un lapin de la population. Ajuste aussi les compteurs d'adultes males et femelles
 * 
 * @param index 
 */
void Simulation::deleteRabbit(int index) {
    rabbits[index]->getSex() == SEX::MALE
        ? --maleAdults
        : --femaleAdults;

    rabbits.erase(rabbits.begin() + index);
}


/**
 * @brief Run the simulation.
 * 
 */
void Simulation::run() {
    int j, nbReproductions, nbBabies, curPop;
    auto *yearStat = new StatsYear(this->rabbits.size());

    std::cout << "SIMULATION::RUN - start" << std::endl;

    for(int i = 0; i < this->duration; i++) {
        std::cout << "SIMULATION::RUN - time: " << (i / 12) << "y " << i % 12 << "m" << std::endl;

        // chaque annee -> stats
        if (i % 12 == 0 && i != 0) {
            yearStat->endYear(this->rabbits.size());
            this->stats.addYear(yearStat);

            yearStat = new StatsYear(this->rabbits.size());
        }

        j = 0;
        nbBabies = 0;
        nbReproductions = 0;
        curPop = this->rabbits.size();

        // verif qu'ils meurent ou pas
        while (j < rabbits.size()) {
            // mort => delete
            if (this->rabbits[j]->shouldDie()) {
                this->stats.addDeath(this->rabbits[j]->getAge());
                this->deleteRabbit(j);
            }
            // pas mort
            else {

                // reproduce
                if(this->rabbits[j]->getSex() == SEX::FEMALE
                    && this->rabbits[j]->isMature()
                    && nbReproductions < (this->maleAdults * Rabbit::FEMALES_PER_MALE)
                    ) {

                    nbBabies += (dynamic_cast<FemaleRabbit*>(this->rabbits[j].get()))->reproduce(i % 12);
                    nbReproductions++;
                }

                // grow
                this->rabbits[j]->grow(this->stats);
                if (this->rabbits[j]->isMature()) {
                    this->rabbits[j]->getSex() == SEX::MALE
                        ? ++maleAdults
                        : ++femaleAdults;
                }
                ++j;
            }
        }
        // stats
        yearStat->increment( curPop - this->rabbits.size(), nbBabies);

        // ajoute les bebes
        for(j = 0; j < nbBabies ; j++) {
            this->rabbits.push_back(std::unique_ptr<Rabbit>(Rabbit::createRabbit()));
        }
    }

    yearStat->endYear(this->rabbits.size());
    this->stats.addYear(yearStat);

    std::cout << "SIMULATION::RUN - end" << std::endl;
}

/**
 * @brief Display the statistics gathered from the simulation.
 */
void Simulation::displayStats() {
    int durationYears = duration / 12;
    std::cout << std::endl << "Simulation sur "<< durationYears << " annees." << std::endl << std::endl;

    std::cout << "Esperance de vie: " << stats.getAverageAgeOfDeath() << std::endl;
    std::cout << "Population finale: " << rabbits.size() << std::endl;
    std::cout << "Nombre de mort total: " << stats.getTotalDeaths() << std::endl;
    std::cout << "Nombre de naissances total: " << stats.getTotalBirths() << std::endl;
    std::cout << "Moyenne du nombre de portees: " << stats.getAverageLitters() << std::endl;

// doyen
// nombre de bebe par portee
    for (int i = 0; i < durationYears; ++i) {
        std::cout << std::endl << "ANNEE: " << i + 1 << std::endl;
        std::cout << "Population: " << stats.getPop(i) << std::endl;
        std::cout << "Nombre de naissances: " << stats.getBirths(i) << std::endl;
        std::cout << "Nombre de morts: " << stats.getDeaths(i) << std::endl;
        int diff = stats.getPop(i) - stats.getStartingPop(i);
        std::cout << "% accroissement de la pop: " << (float)diff / (float)stats.getPop(i) * 100 << std::endl;
        std::cout << "Multiplicateur de la pop: " << (float)diff / (float)stats.getPop(i) * 100 << std::endl;
    }
}