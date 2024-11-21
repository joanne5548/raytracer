#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include <vector>
#include "hittable.h"

class hittable_list : public hittable {
    public:
        std::vector<hittable> list;

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

        // You actually just need one hitpoint!!! cause we only care about the frontmost intersection
        bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override {
            bool object_was_hit = false;
            double closest_hit_t = t_max;

            for (int i = 0; i < list.size(); ++i) {
                hit_record current_rec;

                // If you use t to determine the distance, it's much faster than
                // comparing the length of the vectors
                if (list.at(i).hit(r, t_min, closest_hit_t, current_rec)) {
                    // only store the closest hit record from the camera center
                    if (current_rec.t < closest_hit_t) {
                        rec = current_rec;
                        closest_hit_t = current_rec.t;
                    }

                    object_was_hit = true;
                }
            }

            return object_was_hit;
        }

};

#endif