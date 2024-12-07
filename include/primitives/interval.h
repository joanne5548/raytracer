#ifndef INTERVAL_H
#define INTERVAL_H

#include "constants.h"

class interval {
    public:
        double min, max;

        // default interval is empty
        interval() : min(infinity), max(-infinity) {}

        interval(double min, double max) : min(min), max(max) {}

        double size() {
            return max - min;
        }

        bool contains(double x) {
            return x >= min && x <= max;
        }

        bool surrounds(double x) {
            return x > min && x < max;
        }

        static const interval empty, universe;
};

const interval interval::empty = interval(infinity, -infinity);
const interval interval::universe = interval(-infinity, infinity);

#endif