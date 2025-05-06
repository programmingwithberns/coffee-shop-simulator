#include "CoffeeOrder.h"
#include <algorithm>
#include <numeric> // std::accumulate

[[nodiscard]] std::size_t CoffeeOrder::coffeeSoldBySize(CoffeeSize size)  const{
    return std::count_if(coffees.begin(), coffees.end(), [&](const auto &cptr){ return cptr->getSize() == size;});
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

    return std::accumulate(coffees.begin(), coffees.end(),0.0, [&](double revenue, const auto &cptr){return revenue + cptr->getPrice();});
}

[[nodiscard]] double CoffeeOrder::getTotalVolumeSold() const {
    return std::accumulate(coffees.begin(), coffees.end(),0.0, [&](double volume, const auto &cptr){return volume + cptr->getVolume();});
}

void CoffeeOrder::add(const CoffeePtr &coffee, std::size_t quantity) {
    for (std::size_t i = 0; i < quantity; ++i) {
        coffees.push_back(coffee);
    }
}

std::vector<std::shared_ptr<Coffee>>::const_iterator CoffeeOrder::isCoffeeTypePresent(const CoffeeSize &coffeeSize)  const {
    return std::find_if(coffees.begin(), coffees.end(),[&](const auto &coffee) {
        return coffee->getSize() == coffeeSize;
    });
}
void CoffeeOrder::displayReceipt() const {
    if (coffees.empty()) {
        std::cout << "No orders made. No receipt to print!\n";
    } else {
        std::cout << "\n--- Receipt ---\n";

        const auto smallCupCoffeePresence = isCoffeeTypePresent(CoffeeSize::SMALL);

        if(smallCupCoffeePresence != coffees.end()){
            const auto smallCupsSold = getNumberOfSmallCupsSold();
            std::cout << std::setw(2) << std::right <<smallCupsSold << " ";
            smallCupCoffeePresence->get()->display();
        }
        const auto mediumCupCoffeePresence = isCoffeeTypePresent(CoffeeSize::MEDIUM);

        if(mediumCupCoffeePresence != coffees.end()){
            auto mediumCups = getNumberOfMediumCupsSold();
            std::cout << std::setw(2) << std::right<< mediumCups << " ";
            mediumCupCoffeePresence->get()->display();
        }

        const auto largeCupCoffeePresence = isCoffeeTypePresent(CoffeeSize::LARGE);

        if(largeCupCoffeePresence != coffees.end()){
            auto largeCups = getNumberOfLargeCupsSold();
            std::cout << std::setw(2) << std::right << largeCups << " ";
            largeCupCoffeePresence->get()->display();
        }
        std::cout << "Total Amount: $" << getTotalRevenue() << "\n";
        std::cout << "------- END OF RECEIPT ------" << "\n";
    }
}
