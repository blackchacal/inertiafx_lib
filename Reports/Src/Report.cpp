/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file Report.cpp                                                           *
 * \brief Report abstract class.                                              *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 18th 2024                                                   *
 *                                                                            *
 * \namespace InertiaFX::Reports                                              *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#include "Report.hpp"
#include "ScalarPlot.hpp"
#include "VectorPlot.hpp"

using namespace InertiaFX::Core;
using namespace InertiaFX::Reports;

Report::Report(IBody *body, RefDimensions dimensions, PlotType type)
{
    this->plot_canvas = new TCanvas("canvas", this->title.c_str(), 800, 600);

    switch (dimensions)
    {
    case RefDimensions::DIM_1D:
        this->plot_canvas->Divide(1,1);
        break;

    case RefDimensions::DIM_2D:
        this->plot_canvas->Divide(2,1);
        break;

    case RefDimensions::DIM_3D:
        this->plot_canvas->Divide(3,1);
        break;
    
    default:
        break;
    }

    this->body = body;
    this->dimensions = dimensions;
    this->setReportTitle("");
    this->setPlotType(type);

}

Report::Report(IBody *body, RefDimensions dimensions, PlotType type, std::string title)
{
    this->plot_canvas = new TCanvas("canvas", this->title.c_str(), 800, 600);

    switch (dimensions)
    {
    case RefDimensions::DIM_1D:
        this->plot_canvas->Divide(1,1);
        break;

    case RefDimensions::DIM_2D:
        this->plot_canvas->Divide(2,1);
        break;

    case RefDimensions::DIM_3D:
        this->plot_canvas->Divide(3,1);
        break;
    
    default:
        break;
    }

    this->body = body;
    this->dimensions = dimensions;
    this->setReportTitle(title);
    this->setPlotType(type);
}

Report::~Report()
{
    /* Delete Plot Canvas (TCanvas) instance */
    delete this->plot_canvas;
    this->plot_canvas = nullptr;

    /* Delete all plots instances */
    for (auto ptr : this->plots)
    {
        delete ptr;
        ptr = nullptr;
    }
    this->plots.clear();
    this->plots.shrink_to_fit();
}

void Report::showFullReport()
{
}

void Report::showPlots()
{
    uint8_t idx = 1;
    for (auto plot : this->plots)
    {
        this->plot_canvas->cd(idx);
        plot->show();
        this->plot_canvas->Update();
        idx++;
    }
}

void Report::setReportTitle(std::string title)
{
    this->title = title;
    this->plot_canvas->SetTitle(title.c_str());
}

void Report::setPlotTitle(uint8_t idx, std::string title)
{
    this->plots.at(idx)->setTitle(title);
}

void Report::setPlotXAxisLabel(uint8_t idx, std::string label)
{
    this->plots.at(idx)->setXAxisLabel(label);
}

void Report::setPlotYAxisLabel(uint8_t idx, std::string label)
{
    this->plots.at(idx)->setYAxisLabel(label);
}

void Report::setPlotZAxisLabel(uint8_t idx, std::string label)
{
    this->plots.at(idx)->setZAxisLabel(label);
}

void Report::setPlotType(PlotType type)
{
    this->type = type;

    /* Delete all plots instances */
    for (auto ptr : this->plots)
    {
        delete ptr;
        ptr = nullptr;
    }
    this->plots.clear();
    this->plots.shrink_to_fit();

    switch (this->type)
    {
    case PlotType::Scalar:
        for (size_t ii = 0; ii < ((size_t)dimensions + 1); ii++)
        {
            this->plots.insert(this->plots.cend(), new ScalarPlot(this->title));
        }
        break;

    case PlotType::Vector:
        this->plots.insert(this->plots.cend(), new VectorPlot(this->title));
        break;

    default:
        break;
    }
}