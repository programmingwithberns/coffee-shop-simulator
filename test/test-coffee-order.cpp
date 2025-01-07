#include <catch2/catch_test_macros.hpp>
#include "CoffeeOrder.h"
/**
 * Coffee(CoffeeSize::SMALL, 1.75, 9)
 * Coffee(CoffeeSize::MEDIUM, 1.90, 12)
 * Coffee(CoffeeSize::LARGE,2.00, 15)
 */
SCENARIO("Testing the CoffeeOrder", "[CoffeeOrderTest]") {
    GIVEN("A coffee order") {
        CoffeeOrder order;
        WHEN("An item is not added to it") {
            THEN("The number of cups sold should be zero") {
                REQUIRE(order.getNumberOfCupsSold() == 0);
                REQUIRE(order.getNumberOfLargeCupsSold() == 0);
                REQUIRE(order.getNumberOfMediumCupsSold() == 0);
                REQUIRE(order.getNumberOfSmallCupsSold() == 0);
            }AND_THEN("The cost of the order should be zero") {
                REQUIRE(order.getTotalRevenue() == 0);
            }AND_THEN("The volume of coffee sold should be zero") {
                REQUIRE(order.getTotalVolumeSold() == 0);
            }
        }AND_WHEN("Items (coffee) are added to it") {
            THEN("The order should hold the information") {
                order.add(std::make_shared<SmallCoffee>(), 1);

                REQUIRE(order.getNumberOfCupsSold() == 1);
                REQUIRE(order.getTotalRevenue() == 1.75);
                REQUIRE(order.getTotalVolumeSold() == 9);

// Query number of cups for each
                REQUIRE(order.getNumberOfSmallCupsSold() == 1);
                REQUIRE(order.getNumberOfMediumCupsSold() == 0);
                REQUIRE(order.getNumberOfLargeCupsSold() == 0);

                order.displayReceipt();

                order.add(std::make_shared<MediumCoffee>(), 5);
                REQUIRE(order.getNumberOfCupsSold() == 6);
                REQUIRE(order.getTotalRevenue() == 11.25); //  1*1.75 +5*1.9
                REQUIRE(order.getTotalVolumeSold() == 69); // 1*9 + 5*12

                order.displayReceipt();
// Query number of cups for each
                REQUIRE(order.getNumberOfSmallCupsSold() == 1);
                REQUIRE(order.getNumberOfMediumCupsSold() == 5);
                REQUIRE(order.getNumberOfLargeCupsSold() == 0);

// add a large cup of coffee
                order.add(std::make_shared<LargeCoffee>(), 1);
                REQUIRE(order.getNumberOfCupsSold() == 7);
                REQUIRE(order.getTotalRevenue() == 13.25); // 1*1.75 +5*1.9 + 1*2
                REQUIRE(order.getTotalVolumeSold() == 84); // 5*12 + 1*9 + 1*15

// Query number of cups for each
                REQUIRE(order.getNumberOfSmallCupsSold() == 1);
                REQUIRE(order.getNumberOfMediumCupsSold() == 5);
                REQUIRE(order.getNumberOfLargeCupsSold() == 1);

                order.displayReceipt();
            }
        }
    }
}