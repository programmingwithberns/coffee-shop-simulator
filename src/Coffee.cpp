#include "Coffee.h"

Coffee::Coffee(const CoffeeSize &size, const double &price, const double& volume)
: size(size), price(price),volume(volume) {}


CoffeeSize Coffee::getSize() const {
    return size;
}

double Coffee::getPrice() const {
    return price;
}

double Coffee::getVolume() const {
    return volume;
}
