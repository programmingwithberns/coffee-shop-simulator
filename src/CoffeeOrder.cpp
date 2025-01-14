#include "CoffeeOrder.h"
#include <algorithm>

[[nodiscard]] std::size_t CoffeeOrder::coffeeSoldBySize(CoffeeSize size)  const{
    std::size_t count{0};
    for (const auto& cup : coffees) {
        if (cup->getSize() == size) {
            count+=1;
        }
    }
    return count;
}

[[nodiscard]] std::size_t CoffeeOrder::getNumberOfCupsSold() const {
    return coffees.size();
}

[[nodiscard]] std::size_t CoffeeOrder::getNumberOfLargeCupsSold() const {
    return coffeeSoldBySize(CoffeeSize::LARGE);
}

[[nodiscard]] std::size_t CoffeeOrder::getNumberOfMediumCupsSold() const {
    return coffeeSoldBySize(CoffeeSize::MEDIUM);
}

[[nodiscard]] std::size_t CoffeeOrder::getNumberOfSmallCupsSold() const {
    return coffeeSoldBySize(CoffeeSize::SMALL);
}

[[nodiscard]] double CoffeeOrder::getTotalRevenue() const {
    double revenue{0.0};

    for (const auto& cup : coffees) {
        revenue += cup->getPrice();
    }
    return revenue;
}

[[nodiscard]] double CoffeeOrder::getTotalVolumeSold() const {
    double volume{0.0};
    for (const auto& cup : coffees) {
        volume += cup->getVolume();
    }
    return volume;
}

void CoffeeOrder::add(const CoffeePtr &coffee, std::size_t quantity) {
    for (std::size_t i = 0; i < quantity; ++i) {
        coffees.push_back(coffee);
    }
}

void CoffeeOrder::displayReceipt() const {
    if (coffees.empty()) {
        std::cout << "No orders made. No receipt to print!\n";
    } else {
        std::cout << "\n--- Receipt ---\n";
        const auto smallCupCoffee = std::find_if(coffees.begin(), coffees.end(),
                                                 [](const CoffeePtr &coffee) {
                                                     return coffee->getSize() == CoffeeSize::SMALL;
                                                 });
        if(smallCupCoffee != coffees.end()){
            const auto smallCupsSold = getNumberOfSmallCupsSold();
            std::cout << std::setw(2) << std::right <<smallCupsSold << " ";
            smallCupCoffee->get()->display();
        }
        const auto mediumCupCoffee = std::find_if(coffees.begin(), coffees.end(),[](const CoffeePtr &coffee){return coffee->getSize() ==CoffeeSize::MEDIUM;} );

        if(mediumCupCoffee != coffees.end()){
            auto mediumCups = getNumberOfMediumCupsSold();
            std::cout << std::setw(2) << std::right<< mediumCups << " ";
            mediumCupCoffee->get()->display();
        }

        const auto largeCupCoffee = std::find_if(coffees.begin(), coffees.end(),[](const CoffeePtr &coffee){return coffee->getSize() ==CoffeeSize::LARGE;} );

        if(largeCupCoffee != coffees.end()){
            auto largeCups = getNumberOfLargeCupsSold();
            std::cout << std::setw(2) << std::right << largeCups << " ";
            largeCupCoffee->get()->display();
        }
        std::cout << "Total Amount: $" << getTotalRevenue() << "\n";
        std::cout << "------- END OF RECEIPT ------" << "\n";
    }
}
