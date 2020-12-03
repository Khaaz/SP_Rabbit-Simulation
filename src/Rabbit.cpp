#include "Rabbit.h"
#include "FemaleRabbit.h"
#include "MaleRabbit.h"
#include "Generator.h"
#include "Constant.h"

Rabbit::Rabbit() : age(0), deathRate(DEATH_RATE_INFANT / 12) {
    maturity = Generator::randomBetween(MATURITY_MIN_AGE, MATURITY_MAX_AGE);
}

/**
 * @brief Creer un lapin aleatoirement Male ou Femelle
 * 
 * @return Rabbit* 
 */
Rabbit* Rabbit::createRabbit() {
    Rabbit* rabbit;
    float r = Generator::randomBetween(0, 1);

    if(r > 0.5){
        rabbit = new FemaleRabbit();
    }
    else {
        rabbit = new MaleRabbit();
    }
    return rabbit;
}

/**
 * @brief Age du lapi
 * 
 * @return int 
 */
int Rabbit::getAge() const {
    return age;
}

/**
 * @brief Si le lapin doit mourir ou non. Base sur un random en fonction de ses chances de mourir.
 * 
 * @return true 
 * @return false 
 */
bool Rabbit::shouldDie() const {
    return Generator::randomBetween(0, 1) < deathRate;
}

/**
 * @brief Si le lapin a passe le seuil de maturite (est apte a se reproduire).
 * 
 * @return true 
 * @return false 
 */
bool Rabbit::isMature() const {
    return age >= maturity;
}

/**
 * @brief Incremente l'age du lapin, fait varier ses probabilités de mort si besoin.
 * 
 * @param stats 
 */
void Rabbit::grow(Stats &stats) {
    ++age;
    if(age == maturity){
        deathRate = DEATH_RATE_ADULT / 12;
    }
    if (age > 10 * 12 && (age % 12) == 0 ) {
        deathRate = deathRate + (DEATH_RATE_INCREASE / 12);
    }
}