#include <iostream>
#include "Engine.h"
#include "VacuumWorld.h"

using namespace InertiaFX;
using namespace Core;

int main()
{
    std::cout << "InertiaFX\n";

    VacuumWorld world;
    Engine engine(&world);

    Body body;
    world.addBody(&body, Eigen::Vector3d{1, 0, 0});

    engine.run(10);

    return 0;
}