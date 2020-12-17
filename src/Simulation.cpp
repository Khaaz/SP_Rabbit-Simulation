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

    for(int i = 0; i < startingCouple; ++i) {
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
    int j, nbReproductions, nbBabies, curPop,age;
    auto *yearStat = new StatsYear(this->rabbits.size());

    std::cout << "SIMULATION::RUN - start" << std::endl;

    for(int i = 0; i < this->duration; ++i) {
        std::cout << "SIMULATION::RUN - time: " << (i / 12) << "y " << i % 12 << "m" << std::endl;

        // chaque annee -> stats
        if (i != 0 && i % 12 == 0) {
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
                age = this->rabbits[j]->getAge();
                this->stats.addDeath(age);
                this->stats.setEldest(age);
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
        for(j = 0; j < nbBabies; ++j) {
            this->rabbits.push_back(std::unique_ptr<Rabbit>(Rabbit::createRabbit()));
        }
    }

    yearStat->endYear(this->rabbits.size());
    this->stats.addYear(yearStat);
    this->stats.endStats(rabbits);

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
    std::cout << "Plus vieux lapin de la simulation: " << stats.getDean() / 12 << " ans et " <<  stats.getDean() % 12 << " mois" << std::endl;

    for (int i = 0; i < durationYears; ++i) {
        std::cout << std::endl << "ANNEE: " << i + 1 << std::endl;
        std::cout << "Population: " << stats.getPop(i) << std::endl;
        std::cout << "Nombre de naissances: " << stats.getBirths(i) << std::endl;
        std::cout << "Nombre de morts: " << stats.getDeaths(i) << std::endl;
        std::cout << "% accroissement de la pop: " << (((float)stats.getPop(i)/ (float) stats.getStartingPop(i)) - 1) * 100 << std::endl;
        std::cout << "Multiplicateur de la pop: " << ((float)stats.getPop(i)/ (float) stats.getStartingPop(i))  << std::endl;
    }
}

void Simulation::writeStats(std::ostream& outfile) {
    int durationYears = duration / 12;

    outfile << "Population: " << rabbits.size() << std::endl;
    for (int i = 0; i < durationYears; ++i) {
        outfile << i << " : " << stats.getPop(i) << std::endl;
    }

    outfile << std::endl << std::endl;

    outfile << "Esperance de vie: " << stats.getAverageAgeOfDeath() << std::endl;
    outfile << "Population finale: " << rabbits.size() << std::endl;
    outfile << "Nombre de mort total: " << stats.getTotalDeaths() << std::endl;
    outfile << "Nombre de naissances total: " << stats.getTotalBirths() << std::endl;
    outfile << "Moyenne du nombre de portees: " << stats.getAverageLitters() << std::endl;
    outfile << "Plus vieux lapin de la simulation: " << stats.getDean() / 12 << " ans et " <<  stats.getDean() % 12 << " mois" << std::endl;

    for (int i = 0; i < durationYears; ++i) {
        outfile << std::endl << "ANNEE: " << i + 1 << std::endl;
        outfile << "Population: " << stats.getPop(i) << std::endl;
        outfile << "Nombre de naissances: " << stats.getBirths(i) << std::endl;
        outfile << "Nombre de morts: " << stats.getDeaths(i) << std::endl;
        outfile << "% accroissement de la pop: " << (((float)stats.getPop(i)/ (float) stats.getStartingPop(i)) - 1) * 100 << std::endl;
        outfile << "Multiplicateur de la pop: " << ((float)stats.getPop(i)/ (float) stats.getStartingPop(i))  << std::endl;
    }
}