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
    this->setReportTitle("Position Report");
    std::vector<std::string> plot_titles({std::string("X vs Time"), std::string("Y vs Time"), std::string("Z vs Time")});

    switch (this->type)
    {
    case PlotType::Scalar:
        for (size_t ii = 0; ii < this->plots.size(); ii++)
        {
            this->setPlotTitle(ii, plot_titles.at(ii));
        }
        break;

    case PlotType::Vector:
        this->setPlotTitle(0, std::string("Position vs Time"));
        break;
    
    default:
        break;
    }
    
}

PositionReport::PositionReport(IBody *body, RefDimensions dimensions, PlotType type, std::string title) : Report(body, dimensions, type, title)
{
    std::vector<std::string> plot_titles({std::string("X vs Time"), std::string("Y vs Time"), std::string("Z vs Time")});
    
    switch (this->type)
    {
    case PlotType::Scalar:
        for (size_t ii = 0; ii < this->plots.size(); ii++)
        {
            this->setPlotTitle(ii, plot_titles.at(ii));
        }
        break;

    case PlotType::Vector:
        this->setPlotTitle(0, std::string("Position vs Time"));
        break;
    
    default:
        break;
    }
}

PositionReport::~PositionReport()
{
}

void PositionReport::updateData(uint32_t t)
{
    switch (this->type)
    {
    case PlotType::Scalar:
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
        break;

    case PlotType::Vector:
        switch (this->dimensions)
        {
        case RefDimensions::DIM_1D:
            /* TODO: Throw exception invalid dimensions */
            break;

        case RefDimensions::DIM_2D:
            /* TODO: Throw exception invalid dimensions */
            break;

        case RefDimensions::DIM_3D:
            this->plots.at(0)->addToXValues(this->body->getPosition().x());
            this->plots.at(0)->addToYValues(this->body->getPosition().y());
            this->plots.at(0)->addToZValues(this->body->getPosition().z());
            break;

        default:
            break;
        }
        break;

    default:
        break;
    }
}