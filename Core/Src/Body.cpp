/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file Body.cpp                                                             *
 * \brief Generic Body abstract class.                                        *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 8th 2024                                                    *
 *                                                                            *
 * \namespace InertiaFX::Core                                                 *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#include <sstream>
#include "Body.h"

using namespace InertiaFX::Core;

IBody::~IBody() {}

Body::Body()
{
    this->is_point_mass = false;
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

void Body::setVelocity(Eigen::Vector3d velocity)
{
    this->velocity = velocity;
}

void Body::setAcceleration(Eigen::Vector3d acceleration)
{
    this->acceleration = acceleration;
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

std::string Body::toString()
{
    std::stringstream ss;
    Eigen::Vector3d pos = this->getPosition();
    Eigen::Vector3d vel = this->getVelocity();
    Eigen::Vector3d acc = this->getAcceleration();

    ss << this->getName() << ":" << std::endl
        << "> Position: (" << pos.x() << ", " << pos.y() << ", " << pos.z() << ")" << std::endl
        << "> Velocity: (" << vel.x() << ", " << vel.y() << ", " << vel.z() << ")" << std::endl
        << "> Acceleration: (" << acc.x() << ", " << acc.y() << ", " << acc.z() << ")" << std::endl;
    return ss.str();
}
            