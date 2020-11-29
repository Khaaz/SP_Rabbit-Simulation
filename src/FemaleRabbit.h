#ifndef SP_RABBIT_SIMULATION_FEMALERABBIT_H
#define SP_RABBIT_SIMULATION_FEMALERABBIT_H

#include "Rabbit.h"

class FemaleRabbit : public Rabbit {
    int littersThisYear;
    int theoricalNbLitters;
    bool birthCalendar[12];
    void generateCalendar();

public:
    FemaleRabbit();
    SEX getSex() const override;

    int reproduce(int);
    void grow(Stats &stats) override;
};


#endif //SP_RABBIT_SIMULATION_FEMALERABBIT_H
