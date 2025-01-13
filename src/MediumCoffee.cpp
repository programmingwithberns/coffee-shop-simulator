#include "MediumCoffee.h"

MediumCoffee::MediumCoffee()
        : Coffee(CoffeeSize::MEDIUM, 1.9, 12) {

}

void MediumCoffee::display() const {
    std::cout << "Medium cup: $" << std::fixed << std::setprecision(2)
              << getPrice() << " (" << getVolume() << " oz)" << "\n";
}
