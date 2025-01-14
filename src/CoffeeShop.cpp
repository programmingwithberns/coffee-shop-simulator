//
// Created by Longho Bernard on 2025-01-13.
//

#include "CoffeeShop.h"

void CoffeeShop::showMenu() const {
    std::cout << "----------------------\n";
    std::cout << "===== MAVINS COFFEE ==== \n"
            << "Choose a number below for your choice\n"
            << " 1. Buy coffee \n"
            << " 2. Show total Cups sold \n"
            << " 3. Total Coffee sold (in ounces) \n"
            << " 4. Show Total Revenue\n"
            << " 5. Show Receipt\n"
            << " 0. Quit the program\n";
    std::cout << "----------------------\n\n";
}

std::string CoffeeShop::getUserChoice(const std::set<std::string> &validValues) const {
    std::string choice;
    while (true) {
        std::getline(std::cin, choice);
        // check for validity
        if (validValues.find(choice) != validValues.end()) {
            return choice;
        } else {
            std::cout << "Please enter a valid choice\n";
        }
    }
}

CoffeeShop::CoffeeShop()
    : coffeeOrder{std::make_unique<CoffeeOrder>()} {
}

void CoffeeShop::run() const {
    bool stop = false;
    while (!stop) {
        showMenu();
        std::cout << "Please enter your choice: ";

        const auto userInput = getUserChoice({"0", "1", "2", "3", "4", "5"});

        // perform actions
        if (userInput == "1") {
            buyCoffee();
        } else if (userInput == "2") {
            showTotalCupsSold();
        } else if (userInput == "3") {
            showTotalVolumeSold();
        } else if (userInput == "4") {
            showTotalRevenueMade();
        } else if (userInput == "5") {
            showReceipt();
        } else if (userInput == "0") {
            std::cout << "\n Thanks for shopping with us. Bye for now. \n";
            stop = true;
        }
    }
}

void CoffeeShop::buyCoffee() const {
    while (true) {
        // get type of coffee to be added
        std::cout << "\nBuying Coffee\n"
                << " 1. Small Coffee\n"
                << " 2. Medium Coffee\n"
                << " 3. Large Coffee\n"
                << "\nPlease choose the type of coffee (1,2,3): ";

        const auto typeOfCoffee = getUserChoice({"1", "2", "3"});

        std::shared_ptr<Coffee> coffeeToBuy = nullptr;

        std::string coffeeType;
        if (typeOfCoffee == "1") {
            coffeeToBuy = std::make_shared<SmallCoffee>();
            coffeeType = "Small";
        } else if (typeOfCoffee == "2") {
            coffeeToBuy = std::make_shared<MediumCoffee>();
            coffeeType = "Medium";
        } else if (typeOfCoffee == "3") {
            coffeeType = "Large";
            coffeeToBuy = std::make_shared<LargeCoffee>();
        }

        // get number of cups coffee to be added
        std::cout << "\nPlease enter the number of cups of " << coffeeType << ": ";

        bool isValidNumber = false;

        std::string number;
        int numberOfCups{};

        do {
            std::getline(std::cin, number);
            try {
                numberOfCups = std::stoi(number);
                isValidNumber = true;
            } catch (const std::exception &e) {
                std::cout << "\nEnter a valid number"
                        << "\nPlease enter the number of cups: ";
            }
        } while (!isValidNumber);

        // add the coffee
        coffeeOrder->add(coffeeToBuy, numberOfCups);

        std::cout << "\nDo you wish to buy more cups of coffee? [Yy/Nn]: ";
        const auto answer = getUserChoice({"y", "Y","n", "N"});
        if (answer == "N" || answer == "n" ) {
            break;
        }
    }
}

void CoffeeShop::showTotalCupsSold() const {
    std::cout << "\nTotal cups sold: "
            << coffeeOrder->getNumberOfCupsSold() << std::endl << std::endl;
}

void CoffeeShop::showTotalVolumeSold() const {
    std::cout << "\nTotal volume sold: "
            << coffeeOrder->getTotalVolumeSold() << std::endl << std::endl;
}

void CoffeeShop::showTotalRevenueMade() const {
    std::cout << "\nTotal revenue made: "
            << coffeeOrder->getTotalRevenue() << std::endl << std::endl;
}

void CoffeeShop::showReceipt() const {
    std::cout << "Receipt: ";
    coffeeOrder->displayReceipt();
}
