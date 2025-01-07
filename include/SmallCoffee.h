//
// Created by Longho Bernard on 2024-12-19.
//

#ifndef SMALLCOFFEE_H
#define SMALLCOFFEE_H

#include "Coffee.h"

class SmallCoffee : public Coffee {
  public:
    SmallCoffee();
    void display() const override;
};



#endif //SMALLCOFFEE_H
