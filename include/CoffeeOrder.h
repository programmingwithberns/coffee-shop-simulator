#ifndef COFFEEORDER_H
#define COFFEEORDER_H

#include "SmallCoffee.h"
#include "MediumCoffee.h"
#include "LargeCoffee.h"
#include <vector>
#include <memory>

class CoffeeOrder final {
    using CoffeePtr = std::shared_ptr<Coffee>;

    std::vector<CoffeePtr> coffees;

    [[nodiscard]] std::size_t coffeeSoldBySize(CoffeeSize size) const;

public:
    [[nodiscard]] std::size_t getNumberOfCupsSold() const;
    [[nodiscard]] std::size_t getNumberOfLargeCupsSold() const;
    [[nodiscard]] std::size_t getNumberOfMediumCupsSold() const;
    [[nodiscard]] std::size_t getNumberOfSmallCupsSold() const;
    [[nodiscard]] double getTotalRevenue() const;
    [[nodiscard]] double getTotalVolumeSold() const;
    void add(const CoffeePtr& coffee, std::size_t quantity);
    void displayReceipt() const;
};



#endif //COFFEEORDER_H
