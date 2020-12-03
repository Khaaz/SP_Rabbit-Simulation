#include <numeric>
#include <memory>

#include "Stats.h"
#include "FemaleRabbit.h"

StatsYear::StatsYear(int pop) : startingPop(pop), pop(0), deaths(0), births(0) {}

/**
 * @brief Le population de depart pour cette annee
 * 
 * @return int 
 */
long StatsYear::getStartingPop() const {
    return startingPop;
};

/**
 * @brief La population finale pour cette annee.
 * 
 * @return int 
 */
long StatsYear::getPop() const {
    return pop;
}

/**
 * @brief Le nombre de naissance dans l'annee
 * 
 * @return int 
 */
long StatsYear::getBirths() const {
    return births;
}

/**
 * @brief Le nombre de mort dans l'annee
 * 
 * @return int 
 */
long StatsYear::getDeaths() const {
    return deaths;
}

/**
 * @brief Increment le nombre de morts et de naissance par mois
 * 
 * @param deaths 
 * @param births 
 */
void StatsYear::increment(int deaths, int births) {
    this->deaths += deaths;
    this->births += births;
}

/**
 * @brief Appelle a la fin de l'annee, ajoute la population finale
 * 
 * @param pop 
 */
void StatsYear::endYear(int pop) {
    this->pop = pop;
}

// Stats

/**
 * @brief L'esperance de vie: l'age moyen de mort.
 * 
 * @return float 
 */
float Stats::getAverageAgeOfDeath() const {
    return (float)std::accumulate(ageOfDeaths.begin(), ageOfDeaths.end(), 0) / (float)ageOfDeaths.size();
}

/**
 * @brief Le nombre total de mort au cours de la simulation
 * 
 * @return int 
 */
long Stats::getTotalDeaths() const {
    int sum = 0;
    for (auto& year : yearlyStats) {
        sum += year->getDeaths();
    }
    return sum;
}

/**
 * @brief Le nombre total de naissance au cours de la simulation
 * 
 * @return int 
 */
long Stats::getTotalBirths() const {
    int sum = 0;
    for (auto& year : yearlyStats) {
        sum += year->getBirths();
    }
    return sum;
}

/**
 * @brief La population de depart pour l'annee demandee
 * 
 * @param year 
 * @return int 
 */
long Stats::getStartingPop(int year) const {
    return yearlyStats[year]->getStartingPop();
}

/**
 * @brief La population finale pour l'annee demandee
 * 
 * @param year 
 * @return int 
 */
long Stats::getPop(int year) const {
    return yearlyStats[year]->getPop();
}

/**
 * @brief Le nombre de morts au cours de l'annee demandee
 * 
 * @param year 
 * @return int 
 */
long Stats::getDeaths(int year) const {
    return yearlyStats[year]->getDeaths();
}

/**
 * @brief Le nombre de naissances au cours de l'annee demandee
 * 
 * @param year 
 * @return int 
 */
long Stats::getBirths(int year) const {
    return yearlyStats[year]->getBirths();
}

/**
 * @brief Ajoute le nombre de portee qu'un individu a eu au cours d'une annee.
 * 
 * @param litters 
 */
void Stats::addLitter(int litters) {
    this->litters.push_back(litters);
}

/**
 * @brief Le nombre moyen de portee par individu
 * 
 * @return float 
 */
float Stats::getAverageLitters() const {
    return (float)std::accumulate(litters.begin(), litters.end(), 0) / (float)litters.size();
}

/**
 * @brief L'age du plus vieux lapin
 * 
 * @return int 
 */
int Stats::getDean() const {
    return dean;
}

/**
 * @brief Ajoute l'age de mort d'un individu
 * 
 * @param age 
 */
void Stats::addDeath(int age) {
    ageOfDeaths.push_back(age);
}

/**
 * @brief Ajoute les statistiques pour une annee
 * 
 * @param year 
 */
void Stats::addYear(StatsYear *year) {
    yearlyStats.push_back(year);
}

/**
 * @brief Appelle a la fin de la simulation, collecte la bonne stats pour le doyen.
 *
 * @param year
 */
void Stats::endStats(const std::vector<std::unique_ptr<Rabbit>>& rabbits) {
    setEldest(rabbits[0]->getAge());
}

/** Met a jour l'age du doyen si l'age en parametre est plus grand
 *
 * @param age
 */
void Stats::setEldest(int age){
    if(age > dean){
        dean = age;
    }
}


