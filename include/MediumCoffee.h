#ifndef COFFEESHOPPROGRAM_MEDIUMCOFFEE_H
#define COFFEESHOPPROGRAM_MEDIUMCOFFEE_H

#include "Coffee.h"

class MediumCoffee final : public Coffee {

public:
    MediumCoffee();

    void display() const override;
};


#endif //COFFEESHOPPROGRAM_MEDIUMCOFFEE_H
