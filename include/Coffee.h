#ifndef COFFEE_H
#define COFFEE_H

#include <iostream>
#include <iomanip>

enum class CoffeeSize {
    SMALL,
    MEDIUM,
    LARGE
};


class Coffee {
    const CoffeeSize size;
    const double price;
    const double volume;

public:
    /**
     *
     * @param size the size
     * @param price the price
     * @param volume  the volume in ounces
     */
    explicit Coffee(const CoffeeSize &size, const double &price, const double& volume);

    virtual ~Coffee() = default;

    CoffeeSize getSize() const;

    double getPrice() const;

    double getVolume() const;

    virtual void display() const = 0;
};


#endif //COFFEE_H
