
#include <catch2/catch_test_macros.hpp>

#include "SmallCoffee.h"
#include "MediumCoffee.h"
#include "LargeCoffee.h"
SCENARIO("Testing an instance of SMALL Coffee", "[SmallCoffee]"){
    GIVEN("An instance of coffee"){
        SmallCoffee coffee;

        WHEN("When it's properties are called"){
            THEN("It should return them correctly"){
                REQUIRE(coffee.getSize() == CoffeeSize::SMALL);
                REQUIRE(coffee.getVolume() == 9);
                REQUIRE(coffee.getPrice() == 1.75);
            }
        }
    }
}

SCENARIO("Testing an instance of Medium Coffee", "[MediumCoffee]"){
    GIVEN("An instance of coffee"){
        MediumCoffee coffee;

        WHEN("When it's properties are called"){
            THEN("It should return them correctly"){
                REQUIRE(coffee.getSize() == CoffeeSize::MEDIUM);
                REQUIRE(coffee.getVolume() == 12);
                REQUIRE(coffee.getPrice() == 1.9);
            }
        }
    }
}

SCENARIO("Testing an instance of Large Coffee", "[LargeCoffee]"){
    GIVEN("An instance of coffee"){
        LargeCoffee coffee;

        WHEN("When it's properties are called"){
            THEN("It should return them correctly"){
                REQUIRE(coffee.getSize() == CoffeeSize::LARGE);
                REQUIRE(coffee.getVolume() == 15);
                REQUIRE(coffee.getPrice() == 2);
            }
        }
    }
}
