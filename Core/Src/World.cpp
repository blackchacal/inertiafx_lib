/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file World.cpp                                                            *
 * \brief Generic World abstract class.                                       *
 *                                                                            *
 * \details This class represents a generic world.                            *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 7th 2024                                                    *
 *                                                                            *
 * \namespace InertiaFX::Core                                                 *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#include <numbers>

#include "World.h"
#include "Body.h"

using namespace InertiaFX::Core;

IWorld::~IWorld() {}

World::World()
{
    this->gravity_vect = Eigen::Vector3d(0.0f, 0.0f, -1.0f);
    this->min_dim = std::array<double, 3>{-10.0f, -10.0f, -10.0f};
    this->max_dim = std::array<double, 3>{10.0f, 10.0f, 10.0f};
    this->mediums_list = std::vector<IMedium *>();
    this->bodies_list = std::vector<IBody *>();
    this->shape = WorldShape::DIM_1D_Line;
}

World::~World()
{
}

unsigned int World::getTotalNumberOfBodies()
{
    return this->bodies_list.size();
}

unsigned int World::getTotalNumberOfMediums()
{
    return this->mediums_list.size();
}

double World::getVolume()
{
    switch (this->shape)
    {
    case WorldShape::DIM_3D_Box:
        /* V = length * width * height */
        return (this->max_dim[0] - this->min_dim[0]) * 
                (this->max_dim[1] - this->min_dim[1]) * 
                (this->max_dim[2] - this->min_dim[2]);
        break;

    case WorldShape::DIM_3D_Sphere:
    {

        /* V = (4/3) * PI * r^3 */

        /** 
         * Since we have a sphere it is assumed that any direction 
         * can provide the radius. Here we are choosing the X direction.
         */
        double r = this->max_dim[0] - this->min_dim[0];
        return ((4.0f/3.0f) * std::numbers::pi * r * r * r);
        break;
    }

    default:
        break;
    }
    return 0;
}

std::array<double, 3> World::getMaxDimensions()
{
    std::array<double, 3> max_dim{(this->max_dim[0] - this->min_dim[0]), 
                (this->max_dim[1] - this->min_dim[1]), 
                (this->max_dim[2] - this->min_dim[2])};
    return max_dim;
}

Eigen::Vector3d World::getGravityVector()
{
    return this->gravity_vect;
}

void World::setShape(WorldShape shape)
{
    this->shape = shape;
}

void World::addBody(IBody *body, Eigen::Vector3d position)
{
    /* TODO: Validate position */
    body->setPosition(position);
    this->bodies_list.insert(this->bodies_list.end(), body);
}

void World::addMedium(IMedium *medium, Eigen::Vector3d position)
{
    /* TODO: Validate position */
    medium->setPosition(position);
    this->mediums_list.insert(this->mediums_list.end(), medium);
}

void World::generateRandomBodies(unsigned int n_bodies)
{
    /* TODO: */
}

void World::generateBodiesAtRandomPositions(unsigned int n_bodies)
{
    /* TODO: */
}
