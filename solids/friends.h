#ifndef SOLIDS_FRIENDS_H
#define SOLIDS_FRIENDS_H

#include "cube1.h"
#include "cylinder1.h"

float Density(Solid &s) {
    return s._d;
}

bool SameVol(Cube &a, Cylinder&b) {
    return a._s*a._s*a._s == PI*b._r*b._r*b._h;
}



#endif //SOLIDS_FRIENDS_H
