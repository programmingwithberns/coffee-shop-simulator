#ifndef COFFEESHOP_H
#define COFFEESHOP_H
#include "CoffeeOrder.h"
#include <iostream>
#include <set>
class CoffeeShop {
private:
  std::unique_ptr<CoffeeOrder> coffeeOrder = nullptr;

  void buyCoffee() const;

  void showTotalCupsSold() const;

  void showTotalVolumeSold() const;

  void showTotalRevenueMade() const;

  void showReceipt() const;

  void showMenu() const;

  std::string getUserChoice(const std::set<std::string> &validValues) const;

public:
  CoffeeShop();
  void run() const;
  ~CoffeeShop() = default;

};



#endif //COFFEESHOP_H
