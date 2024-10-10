/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file Body.cpp                                                             *
 * \brief Generic Body base class.                                            *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 8th 2024                                                    *
 *                                                                            *
 * \namespace InertiaFX::Core                                                 *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#include "Body.h"

using namespace InertiaFX::Core;

IBody::~IBody() {}

Body::Body()
{
    this->is_point_mass = true;
    this->mass = 1;
    this->position = Eigen::Vector3d{0, 0, 0};
    this->velocity = Eigen::Vector3d{0, 0, 0};
    this->acceleration = Eigen::Vector3d{0, 0, 0};
    this->force_sum = Eigen::Vector3d{0, 0, 0};
}

Body::~Body()
{

}

void Body::applyForce(Eigen::Vector3d force)
{

}

void Body::setPosition(Eigen::Vector3d position)
{
    this->position = position;
}

Eigen::Vector3d Body::getPosition()
{
    return this->position;
}

Eigen::Vector3d Body::getVelocity()
{
    return this->velocity;
}

Eigen::Vector3d Body::getAcceleration()
{
    return this->acceleration;
}

double Body::getMass()
{
    return this->mass;
}

bool Body::isPointMass()
{
    return this->is_point_mass;
}
            