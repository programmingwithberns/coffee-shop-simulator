#ifndef COFFEESHOPPROGRAM_LARGECOFFEE_H
#define COFFEESHOPPROGRAM_LARGECOFFEE_H


#include "Coffee.h"

class LargeCoffee final : public Coffee {
public:
    LargeCoffee();

    void display() const override;
};

#endif //COFFEESHOPPROGRAM_LARGECOFFEE_H
