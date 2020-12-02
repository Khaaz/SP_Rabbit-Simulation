#ifndef SP_RABBIT_SIMULATION_FEMALERABBIT_H
#define SP_RABBIT_SIMULATION_FEMALERABBIT_H

#include "Rabbit.h"

class FemaleRabbit : public Rabbit {
    int littersThisYear; // nombre de portee reelle durant l'annee
    int theoricalNbLitters; // nombre de portee theorique durant l'annee (4 a 8)
    bool birthCalendar[12]; // calendrier des portees
    void generateCalendar();

    public:
    FemaleRabbit();
    SEX getSex() const override;

    int reproduce(int);
    void grow(Stats &stats) override;
};


#endif //SP_RABBIT_SIMULATION_FEMALERABBIT_H
