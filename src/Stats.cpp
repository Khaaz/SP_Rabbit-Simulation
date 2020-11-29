#include "Stats.h"
#include "FemaleRabbit.h"
#include <numeric>

StatsYear::StatsYear(int pop) : startingPop(pop), pop(0), deaths(0), births(0) {}

int StatsYear::getStartingPop() const {
    return startingPop;
};

int StatsYear::getPop() const {
    return pop;
}

int StatsYear::getBirths() const {
    return births;
}

int StatsYear::getDeaths() const {
    return deaths;
}

void StatsYear::increment(int deaths, int births) {
    this->deaths += deaths;
    this->births += births;
}

void StatsYear::endYear(int pop) {
    this->pop = pop;
}

// Stats

float Stats::getAverageAgeOfDeath() const {
    return (float)std::accumulate(ageOfDeaths.begin(), ageOfDeaths.end(), 0) / (float)ageOfDeaths.size();
}

int Stats::getTotalDeaths() const {
    int sum = 0;
    for (auto& year : yearlyStats) {
        sum += year->getDeaths();
    }
    return sum;
}

int Stats::getTotalBirths() const {
    int sum = 0;
    for (auto& year : yearlyStats) {
        sum += year->getBirths();
    }
    return sum;
}

int Stats::getStartingPop(int year) const {
    return yearlyStats[year]->getStartingPop();
}

int Stats::getPop(int year) const {
    return yearlyStats[year]->getPop();
}

int Stats::getDeaths(int year) const {
    return yearlyStats[year]->getDeaths();
}

int Stats::getBirths(int year) const {
    return yearlyStats[year]->getBirths();
}

void Stats::addLitter(int litters) {
    this->litters.push_back(litters);
}

float Stats::getAverageLitters() const {
    return (float)std::accumulate(litters.begin(), litters.end(), 0) / (float)litters.size();
}

void Stats::addDeath(int age) {
    ageOfDeaths.push_back(age);
}
void Stats::addYear(StatsYear *year) {
    yearlyStats.push_back(year);
}
