#ifndef SP_RABBIT_SIMULATION_STATS_H
#define SP_RABBIT_SIMULATION_STATS_H

#include <vector>
#include <memory>

class Rabbit;

/**
 * @brief Les statistiques pour une annee
 */
class StatsYear {
    long startingPop; // population initiale au debut de l'annee
    long pop; // nombre d'individu dans la population a la fin de l'annee
    long deaths; // nombre de mort cette annee
    long births; // nombre de naissance cette annee

    public:
    explicit StatsYear(int pop);
    long getStartingPop() const; // population initiale au debut de l'annee
    long getPop() const; // population finale de l'annee
    long getBirths() const; // nombre de naissances dans l'annee
    long getDeaths() const; // nombre de morts dans l'annee
    void increment(int deaths, int births); // appelle chaque mois
    void endYear(int pop); // appelle chaque fin d'annee
};

/**
 * @brief Les statistiques globales
 */
class Stats {
    std::vector<int> ageOfDeaths; // liste de tous les ages de mort des lapins
    std::vector<StatsYear*> yearlyStats; // liste des stats par an
    std::vector<int> litters; // liste de tous les nombres de portees cette annee
    int dean = 0; // Le plus vieux lapin de cette simulation

    public:
    ~Stats();
    float getAverageAgeOfDeath() const; // nombre moyen de l'age de mort
    long getTotalDeaths() const; // nombre total de mort
    long getTotalBirths() const; // nombre total de naissance
    long getStartingPop(int year) const; // nombre d'individu dans la pop pour l'annee X
    long getPop(int year) const; // nombre d'individu dans la pop pour l'annee X
    long getDeaths(int year) const; // nombre de mort pour l'annee X
    long getBirths(int year) const; // nombre de naissance pour l'annee X
    float getAverageLitters() const; // moyenne des portees totales
    int getDean() const; // l'age du plus vieux lapin de cette simulation

    void addLitter(int litters);
    void addDeath(int age);
    void addYear(StatsYear* year);
    void setEldest(int age);
    void endStats(const std::vector<std::unique_ptr<Rabbit>>& rabbits);
};


#endif //SP_RABBIT_SIMULATION_STATS_H
