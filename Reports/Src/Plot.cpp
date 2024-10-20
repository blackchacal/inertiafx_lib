/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file Plot.cpp                                                             *
 * \brief Plot abstract class.                                                *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 18th 2024                                                   *
 *                                                                            *
 * \namespace InertiaFX::Reports                                              *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#include "Plot.hpp"

using namespace InertiaFX::Reports;

Plot::Plot(std::string title)
{
    this->title = title;
    this->x_axis_label = "";
    this->y_axis_label = "";

    this->x_values = std::vector<double>();
    this->y_values = std::vector<double>();
    this->z_values = std::vector<double>();
}

Plot::~Plot()
{
    
}

void Plot::setTitle(std::string title)
{
    this->title = title;
}

void Plot::setXAxisLabel(std::string label)
{
    this->x_axis_label = label;
}

void Plot::setYAxisLabel(std::string label)
{
    this->y_axis_label = label;
}

void Plot::setZAxisLabel(std::string label)
{
    this->z_axis_label = label;
}

void Plot::setXValues(std::vector<double> values)
{
    this->x_values = values;
}

void Plot::setYValues(std::vector<double> values)
{
    this->y_values = values;
}

void Plot::setZValues(std::vector<double> values)
{
    this->z_values = values;
}

void Plot::addToXValues(double value)
{
    this->x_values.insert(this->x_values.cend(), value);
}

void Plot::addToYValues(double value)
{
    this->y_values.insert(this->y_values.cend(), value);
}

void Plot::addToZValues(double value)
{
    this->z_values.insert(this->z_values.cend(), value);
}

std::string Plot::getTitle()
{
    return this->title;
}

std::string Plot::getXAxisLabel()
{
    return this->x_axis_label;
}

std::string Plot::getYAxisLabel()
{
    return this->y_axis_label;
}