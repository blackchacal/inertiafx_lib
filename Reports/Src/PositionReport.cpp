/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file PositionReport.cpp                                                   *
 * \brief Position Report class.                                              *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 19th 2024                                                   *
 *                                                                            *
 * \namespace InertiaFX::Reports                                              *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#include "PositionReport.hpp"

using namespace InertiaFX::Reports;

PositionReport::PositionReport(IBody *body, RefDimensions dimensions, PlotType type) : Report(body, dimensions, type)
{
    std::vector<std::string> plot_titles({std::string("X vs Time"), std::string("Y vs Time"), std::string("Z vs Time")});
    this->setReportTitle("Position Report");
    for (size_t ii = 0; ii < this->plots.size(); ii++)
    {
        this->setPlotTitle(ii, plot_titles.at(ii));
    }
}

PositionReport::PositionReport(IBody *body, RefDimensions dimensions, PlotType type, std::string title) : Report(body, dimensions, type, title)
{
    std::vector<std::string> plot_titles({std::string("X vs Time"), std::string("Y vs Time"), std::string("Z vs Time")});

    for (size_t ii = 0; ii < this->plots.size(); ii++)
    {
        this->setPlotTitle(ii, plot_titles.at(ii));
    }
}

PositionReport::~PositionReport()
{
}

void PositionReport::updateData(uint32_t t)
{
    switch (this->dimensions)
    {
    case RefDimensions::DIM_1D:
        this->plots.at(0)->addToXValues(static_cast<double>(t));
        this->plots.at(0)->addToYValues(this->body->getPosition().x());
        break;

    case RefDimensions::DIM_2D:
        this->plots.at(0)->addToXValues(static_cast<double>(t));
        this->plots.at(0)->addToYValues(this->body->getPosition().x());
        this->plots.at(1)->addToXValues(static_cast<double>(t));
        this->plots.at(1)->addToYValues(this->body->getPosition().y());
        break;

    case RefDimensions::DIM_3D:
        this->plots.at(0)->addToXValues(static_cast<double>(t));
        this->plots.at(0)->addToYValues(this->body->getPosition().x());
        this->plots.at(1)->addToXValues(static_cast<double>(t));
        this->plots.at(1)->addToYValues(this->body->getPosition().y());
        this->plots.at(2)->addToXValues(static_cast<double>(t));
        this->plots.at(2)->addToYValues(this->body->getPosition().z());
        break;
    
    default:
        break;
    }
}