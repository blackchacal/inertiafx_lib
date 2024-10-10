/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file VacuumWorld.cpp                                                      *
 * \brief Vacuum World class.                                                 *
 *                                                                            *
 * \details This class represents an empty vacuum world. It just empty space. *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 8th 2024                                                    *
 *                                                                            *
 * \namespace InertiaFX::Core                                                 *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#include "VacuumWorld.h"

using namespace InertiaFX::Core;

VacuumWorld::VacuumWorld()
{
    this->gravity_vect = Eigen::Vector3d(0.0f, 0.0f, 0.0f);
}

VacuumWorld::~VacuumWorld()
{

}
