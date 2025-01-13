#ifndef SMALLCOFFEE_H
#define SMALLCOFFEE_H

#include "Coffee.h"

class SmallCoffee final : public Coffee {
  public:
    SmallCoffee();
    void display() const override;
};



#endif //SMALLCOFFEE_H
