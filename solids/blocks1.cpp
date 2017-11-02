#include "cube1.h"
#include "cylinder1.h"
#include "friends.h"

int main()
{
    Cube cube {3.0, 0.9};
    Cylinder cyl {2.0, 1.0, 1.1};
    cout << Density(cube) << endl;
    cout << Density(cyl) << endl;
    Solid solid {0.8};
    solid = cube;
    cout << Density(solid) << endl;
}

