#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cmath>
#include <limits>
#include <memory>
#include <chrono>
#include <random>

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// Random number generator using Mersenne Twister
// generates random integer in range [min, max)
inline int random_number_generator(int min, int max) {
    std::mt19937 gen;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    gen.seed(seed);

    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

inline double random_number_generator(double min, double max) {
    std::mt19937 gen;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    gen.seed(seed);

    std::uniform_real_distribution<double> dist(min, max);
    return dist(gen);
}

inline double random_number_generator() {
    return random_number_generator(0.0, 1.0);
}

#endif