#include "FemaleRabbit.h"
#include "Util.h"
#include "Constant.h"

FemaleRabbit::FemaleRabbit() : Rabbit(), littersThisYear(0), theoricalNbLitters(0) {}

SEX FemaleRabbit::getSex() const {
    return SEX::FEMALE;
}

int FemaleRabbit::getLittersThisYear() const {
    return littersThisYear;
}

// Return a random between 3 and 7 if it is a month where it's supposed to give birth, else return 0
int FemaleRabbit::reproduce(int curMonth) {
    if (birthCalendar[curMonth]) {
        ++littersThisYear;
        return randomBetween(3, 7);
    } else {
        return 0;
    }
}

void FemaleRabbit::grow() {
    Rabbit::grow();
    if ((getAge() % 12) == 0) {
        littersThisYear = 0;
        generateCalendar();
    }
}

void FemaleRabbit::generateCalendar(){
    int i = 0, selectedMonth;
    int monthsIndex[12];
    float r = randomBetween(0, 1);

    for (int j = 0; j < 12; ++j){
        monthsIndex[j] = j;
        birthCalendar[j] = false;
    }
    while (r > LITTERS_CUMULATIVE_PROBAS[i] && i < LITTERS_ARRAYS_SIZE) {
        ++i;
    }

    theoricalNbLitters = LITTERS_VALUES[i];
    for (int j = 0; j < theoricalNbLitters; ++j) {
        selectedMonth = (int)randomBetween(0, 12 - j);
        birthCalendar[monthsIndex[selectedMonth]] = true;
        monthsIndex[selectedMonth] = monthsIndex[11 - j];
    }
}