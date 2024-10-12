#include <iostream>
#include "Engine.h"
#include "VacuumWorld.h"
#include "PointMass.h"

using namespace InertiaFX::Core;

int main()
{
    VacuumWorld world;
    Engine engine(&world);

    PointMass pmass;
    pmass.applyForce(Eigen::Vector3d{1, 0, 0});

    world.addBody(&pmass, Eigen::Vector3d{1, 0, 0});

    engine.run(10);

    return 0;
}