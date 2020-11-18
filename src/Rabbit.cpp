#include "random"

#include "Rabbit.h"
#include "FemaleRabbit.h"
#include "MaleRabbit.h"


Rabbit::Rabbit() : age(0), survivalRate(0.35) {}

//TODO faire un rand avec mastumoBOSS

Rabbit& Rabbit::createRabbit() {
    Rabbit* rabbit;
    float r = rand();

    if(r > 0.5){
        rabbit = new FemaleRabbit();
    }
    else {
        rabbit = new MaleRabbit();
    }
    rabbit->survivalRate = 0.35;
    return *rabbit;
}

int Rabbit::getAge() {
    return age;
}

bool Rabbit::shouldDie(){
    float r = rand();
    return (r > survivalRate);
}

bool Rabbit::canReproduce() {
    return age >= Rabbit::MATURITY;
}