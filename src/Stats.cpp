#include "Stats.h"
#include "FemaleRabbit.h"
#include <numeric>
#include <iostream>

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

float StatsYear::getAverageLitters() const {
    return (float)getTotalLitters() / (float)getNumberLitters();
}

int StatsYear::getNumberLitters() const {
    return litters.size();
}

int StatsYear::getTotalLitters() const {
    std::cout << std::accumulate(litters.begin(), litters.end(), 0) << std::endl;
    return std::accumulate(litters.begin(), litters.end(), 0);
}

void StatsYear::increment(int deaths, int births) {
    this->deaths += deaths;
    this->births += births;
}

void StatsYear::endYear(const std::vector<std::unique_ptr<Rabbit>>& rabbits) {
    int i = 0;
    this->pop = rabbits.size();
    while (i < rabbits.size() && rabbits[i]->isMature()) {
        if (rabbits[i]->getSex() == SEX::FEMALE ) {
            litters.push_back(dynamic_cast<FemaleRabbit *>(rabbits[i].get())->getLittersThisYear());
        }
        ++i;
    }

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

float Stats::getAverageLitters(int year) const {
    return yearlyStats[year]->getAverageLitters();
}

float Stats::getTotalAverageLitters() const {
    float sum = 0;
    float numberElems = 0;
    for (auto& year : yearlyStats) {
        sum += year->getTotalLitters();
        numberElems += year->getNumberLitters();
    }
    return sum / numberElems;
}

void Stats::addDeath(int age) {
    ageOfDeaths.push_back(age);
}
void Stats::addYear(StatsYear *year) {
    yearlyStats.push_back(year);
}
