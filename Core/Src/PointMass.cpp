/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file PointMass.cpp                                                        *
 * \brief Point Mass class.                                                   *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 12th 2024                                                   *
 *                                                                            *
 * \namespace InertiaFX::Core                                                 *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#include "PointMass.h"

using namespace InertiaFX::Core;

PointMass::PointMass() : Body()
{
    this->is_point_mass = true;
}

PointMass::~PointMass()
{

}

std::string PointMass::getName()
{
    return std::string("Point Mass");
}
            