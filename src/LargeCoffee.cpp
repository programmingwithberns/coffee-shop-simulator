//
// Created by Longho Bernard on 2024-11-18.
//

#include "LargeCoffee.h"

LargeCoffee::LargeCoffee()
        : Coffee(CoffeeSize::LARGE, 2, 15){

}
void LargeCoffee::display() const {
    std::cout << "Large cup: $" << std::fixed << std::setprecision(2)
              << getPrice() << " (" << getVolume() << " oz)" << "\n";
}

