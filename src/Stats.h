#ifndef SP_RABBIT_SIMULATION_STATS_H
#define SP_RABBIT_SIMULATION_STATS_H

#include <vector>
#include <memory>
#include "Rabbit.h"

class StatsYear {
    int startingPop;
    int pop; // nombre d'individu dans la population a la fin de l'annee
    int deaths; // nombre de mort cette annee
    int births; // nombre de naissance cette annee
    std::vector<int> litters; // liste de tous les nombres de portees cette annee

    public:
    explicit StatsYear(int pop);
    int getStartingPop() const;
    int getPop() const;
    int getBirths() const;
    int getDeaths() const;
    float getAverageLitters() const; // moyenne des portees cette annee
    int getTotalLitters() const; // nombre total de portee cette annee
    int getNumberLitters() const; // nombre d'elements
    void increment(int deaths, int births); // appelle chaque mois
    void endYear(const std::vector<std::unique_ptr<Rabbit>>&); // appelle chaque fin d'annee
};

class Stats {
    std::vector<int> ageOfDeaths; // liste de tous les ages de mort des lapins
    std::vector<StatsYear*> yearlyStats; // liste des stats par an

    public:
    float getAverageAgeOfDeath() const; // nombre moyen de l'age de mort
    int getTotalDeaths() const; // nombre total de mort
    int getTotalBirths() const; // nombre total de naissance
    int getStartingPop(int year) const; // nombre d'individu dans la pop pour l'annee X
    int getPop(int year) const; // nombre d'individu dans la pop pour l'annee X
    int getDeaths(int year) const; // nombre de mort pour l'annee X
    int getBirths(int year) const; // nombre de naissance pour l'annee X
    float getAverageLitters(int year) const; // moyenne des portees pour l'annee X
    float getTotalAverageLitters() const; // moyenne des portees totales

    void addDeath(int age);
    void addYear(StatsYear* year);
};


#endif //SP_RABBIT_SIMULATION_STATS_H
