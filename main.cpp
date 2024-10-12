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
    std::cout << pmass.toString() << std::endl;
    world.addBody(&pmass, Eigen::Vector3d{1, 0, 0});
    std::cout << pmass.toString() << std::endl;

    engine.run(10);

    return 0;
}