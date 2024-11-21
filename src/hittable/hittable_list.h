#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include <vector>
#include <memory>
#include "hittable.h"

// below allows omitting std:: in front of make_shared and shared_ptr every time we use it
using std::make_shared;
using std::shared_ptr;

class hittable_list : public hittable {
    std::vector<shared_ptr<hittable>> list; // uhh why is this public?

    public:
        hittable_list() {}

        // list shouldn't be const since it can change
        hittable_list(std::vector<shared_ptr<hittable>>& list) : list(list) {}

        hittable_list(shared_ptr<hittable> object) {
            add(object);
        }

        void clear() {
            list.clear();
        }

        void add(shared_ptr<hittable> object) {
            list.push_back(object);
        }

        // You actually just need one hitpoint!!!
        // cause we only care about the frontmost intersection to color things
        bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override {
            bool object_was_hit = false;
            double closest_hit_t = t_max;

            for (const auto& object : list) {
                hit_record current_rec;

                // If you use t to determine the distance, it's much faster than
                // comparing the length of the vectors
                if (object->hit(r, t_min, closest_hit_t, current_rec)) {
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