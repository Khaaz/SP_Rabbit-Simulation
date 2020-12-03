#ifndef SP_RABBIT_SIMULATION_CONSTANT_HPP
#define SP_RABBIT_SIMULATION_CONSTANT_HPP

// default seed
const int SEED = 1;

// Taux de mortalité infantile
const float DEATH_RATE_INFANT = 0.65;

// Taux de mortalité infantile
const float DEATH_RATE_ADULT = 0.40;

//Taux de mortalité
const float DEATH_RATE_INCREASE = 10;

// borne inferieur de maturite pour un lapin
const int MATURITY_MIN_AGE = 5;

// borne superieur de maturite pour un lapin
const int MATURITY_MAX_AGE = 8;

// Taille du tableau de portées
const int LITTERS_ARRAYS_SIZE = 5;

//Tableau de portées cumulatives
const float LITTERS_CUMULATIVE_PROBAS[LITTERS_ARRAYS_SIZE] = { 0.05 , 0.35 , 0.65 , 0.95 , 1 };

//Tableau des valeurs correspondantes au probas
const int LITTERS_VALUES[LITTERS_ARRAYS_SIZE] = { 4 , 5 , 6 , 7 , 8 };

#endif //SP_RABBIT_SIMULATION_CONSTANT_HPP
