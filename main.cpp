#include <iostream>
#include "Engine.h"
#include "VacuumWorld.h"
#include "PointMass.h"
#include "PositionReport.hpp"

using namespace InertiaFX::Core;
using namespace InertiaFX::Reports;

int main(int argc, char **argv)
{
    PointMass pmass;
    pmass.applyForce(Eigen::Vector3d{1, 0, 0});

    IWorld *world = new VacuumWorld();
    world->addBody(&pmass, Eigen::Vector3d{1, 0, 0});

    Engine engine(argc, argv, world);

    /**
     * The position reports need to be created after the engine because
     * ROOT TApplication context. 
     */
    PositionReport rp(&pmass, RefDimensions::DIM_3D, PlotType::Scalar);

    engine.addReport(&rp);
    engine.run(10);

    return 0;
}