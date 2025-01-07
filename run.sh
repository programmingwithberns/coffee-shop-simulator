#!/bin/bash

# Define color codes
GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m" # No color

# Check if the build directory exists
if [ ! -d "build" ]; then
    echo -e "${GREEN}Creating build directory...${NC}"
    mkdir build
else
    echo -e "${GREEN}Build directory already exists.${NC}"
fi

# Move into the build directory
cd build || exit

# Run cmake, make, and ctest
echo -e "${GREEN}Running cmake...${NC}"
cmake ..

if [ $? -ne 0 ]; then
    echo -e "${RED}CMake configuration failed. Exiting.${NC}"
    exit 1
fi

echo -e "${GREEN}Running make...${NC}"
make -j8

if [ $? -ne 0 ]; then
    echo -e "${RED}Build process failed. Exiting.${NC}"
    exit 1
fi

echo -e "${GREEN}Running tests...${NC}"
ctest -V

if [ $? -ne 0 ]; then
    echo -e "${RED}Tests failed. Exiting.${NC}"
    exit 1
fi

echo -e "${GREEN}Build and tests completed successfully.${NC}"
