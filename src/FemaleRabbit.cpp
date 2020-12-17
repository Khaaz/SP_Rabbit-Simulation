#include "FemaleRabbit.h"
#include "Stats.h"
#include "Generator.h"
#include "Constant.h"

FemaleRabbit::FemaleRabbit() : Rabbit(), littersThisYear(0), theoricalNbLitters(0) {}

/**
 * @brief Le sexe du lapin
 * 
 * @return SEX 
 */
SEX FemaleRabbit::getSex() const {
    return SEX::FEMALE;
}

/**
 * @brief Retourne le nombre de bebes que cette lapine fait. 0 si elle ne doit pas donner naissance ce mois ci, sinon un nombre aléatoire entre 3 et 7.
 * 
 * @param curMonth 
 * @return int 
 */
int FemaleRabbit::reproduce(int curMonth) {
    if (birthCalendar[curMonth]) {
        ++littersThisYear;
        return (int)Generator::randomBetween(3, 7);
    } else {
        return 0;
    }
}

/**
 * @brief Incremente l'age du lapin, fait varier ses probabilités de mort si besoin.
 * Ajoute le nombre de portee effectivement donnee par la lapine cette annee dans les stats.
 * 
 * @param stats 
 */
void FemaleRabbit::grow(Stats& stats) {
    Rabbit::grow(stats);
    if ((getAge() % 12) == 0) {
        if (getAge() > 23) {
            stats.addLitter(littersThisYear);
        }
        littersThisYear = 0;
        generateCalendar();
    }
}

/**
 * @brief Genere le calendrier de naissance pour cette lapine. Cette lapine donnera entre 4 et 7 portées reparties aléatoirement dans l'année. 
 */
void FemaleRabbit::generateCalendar() {
    int i = 0, selectedMonth;
    int monthsIndex[12];
    double r = Generator::randomBetween(0, 1);

    for (int j = 0; j < 12; ++j){
        monthsIndex[j] = j;
        birthCalendar[j] = false;
    }
    while (r > LITTERS_CUMULATIVE_PROBAS[i] && i < LITTERS_ARRAYS_SIZE) {
        ++i;
    }

    theoricalNbLitters = LITTERS_VALUES[i];
    for (int j = 0; j < theoricalNbLitters; ++j) {
        selectedMonth = (int)Generator::randomBetween(0, 12 - j);
        birthCalendar[monthsIndex[selectedMonth]] = true;
        monthsIndex[selectedMonth] = monthsIndex[11 - j];
    }
}