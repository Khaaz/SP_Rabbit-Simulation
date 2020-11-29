#include "Rabbit.h"
#include "FemaleRabbit.h"
#include "MaleRabbit.h"
#include "Util.h"
#include "Constant.h"

Rabbit::Rabbit() : age(0), deathRate(DEATH_RATE_INFANT / 12) {}

Rabbit* Rabbit::createRabbit() {
    Rabbit* rabbit;
    float r = randomBetween(0, 1);

    if(r > 0.5){
        rabbit = new FemaleRabbit();
    }
    else {
        rabbit = new MaleRabbit();
    }
    return rabbit;
}

int Rabbit::getAge() const {
    return age;
}

bool Rabbit::shouldDie() const {
    float r = randomBetween(0, 1);
    return (r < deathRate);
}

bool Rabbit::isMature() const {
    return age >= Rabbit::MATURITY;
}

void Rabbit::grow(Stats &stats) {
    ++age;
    if(age == Rabbit::MATURITY){
        deathRate = DEATH_RATE_ADULT / 12 ;
    }
    if (age > 10 * 12 && (age % 12) == 0 ) {
        deathRate = deathRate + (DEATH_RATE_INCREASE / 12);
    }
}