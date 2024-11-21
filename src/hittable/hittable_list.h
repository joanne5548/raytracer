#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include <vector>
#include "hittable.h"

class hittable_list {
    std::vector<hittable> list;

    public:
        hittable_list() {}

        // list shouldn't be const since it can change
        hittable_list(std::vector<hittable>& list) : list(list) {}

        hittable_list(const hittable& object) {
            list.push_back(object);
        }

        void clear() {
            list.clear();
        }

        void add(const hittable& object) {
            list.push_back(object);
        }

        // I guess there isn't really a good way to determine return type...
        // I will follow the convention so far and return a bool
        // TODO: change the return type
        std::vector<hit_record> hit(const ray& r, double t_min, double t_max) {
            std::vector<hit_record> hit_list;
            for (int i = 0; i < list.size(); ++i) {
                hit_record rec;
                list.at(i).hit(r, t_min, t_max, rec);
                hit_list.push_back(rec);
            }

            return hit_list;
        }

};

#endif