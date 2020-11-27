#ifndef SP_RABBIT_SIMULATION_FEMALERABBIT_H
#define SP_RABBIT_SIMULATION_FEMALERABBIT_H

#include "Rabbit.h"

class MaleRabbit;

class FemaleRabbit : public Rabbit {
    int littersThisYear;
    int theoricalNbLitters;
    bool birthCalendar[12];
    void generateCalendar();
    public:
    static const int GESTATION = 1;

    FemaleRabbit();

    SEX getSex() const override;
    int getLittersThisYear() const;

    int reproduce(int);
    void grow() override;
};


#endif //SP_RABBIT_SIMULATION_FEMALERABBIT_H
