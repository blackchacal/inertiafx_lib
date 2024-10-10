#include <iostream>
#include "Engine.h"
#include "VacuumWorld.h"

using namespace InertiaFX::Core;

int main()
{
    VacuumWorld world;
    Engine engine(&world);

    Body body;
    world.addBody(&body, Eigen::Vector3d{1, 0, 0});

    engine.run(10);

    return 0;
}