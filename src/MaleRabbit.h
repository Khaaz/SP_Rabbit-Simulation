#ifndef SP_RABBIT_SIMULATION_MALERABBIT_H
#define SP_RABBIT_SIMULATION_MALERABBIT_H

#include "Rabbit.h"

class MaleRabbit : public Rabbit {

    public:
    MaleRabbit();
    //~MaleRabbit();
    //MaleRabbit(const MaleRabbit&);
    SEX getSex() const override;

};


#endif //SP_RABBIT_SIMULATION_MALERABBIT_H
