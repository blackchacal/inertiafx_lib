/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file ScalarPlot.cpp                                                       *
 * \brief Scalar Plot class.                                                  *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 18th 2024                                                   *
 *                                                                            *
 * \namespace InertiaFX::Reports                                              *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#include <sstream>
#include "ScalarPlot.hpp"

using namespace InertiaFX::Reports;

ScalarPlot::ScalarPlot(std::string title) : Plot(title)
{
    this->plot_graph = nullptr;
}

ScalarPlot::ScalarPlot(std::string title, std::vector<double> x_values, std::vector<double> y_values) : Plot(title)
{
    this->setXValues(x_values);
    this->setYValues(y_values);

    if (this->x_values.size() != this->y_values.size())
    {
        /* Throw exception! */
    }

    this->plot_graph = new TGraph(this->x_values.size(), this->x_values.data(), this->y_values.data());
}

ScalarPlot::~ScalarPlot()
{
    delete this->plot_graph;
    this->plot_graph = nullptr;
}

void ScalarPlot::show()
{
    if (this->plot_graph == nullptr)
    {
        this->plot_graph = new TGraph(this->x_values.size(), this->x_values.data(), this->y_values.data());
    }

    std::stringstream graph_titles;
    graph_titles << this->title << ";" << this->x_axis_label << ";" << this->y_axis_label;
    this->plot_graph->SetTitle(graph_titles.str().c_str());

    this->plot_graph->Draw("ALP"); // Option "A" draws axes, "L" draws a line connecting points

    // Customize the plot (optional)
    this->plot_graph->SetMarkerStyle(21); // Set marker style
    this->plot_graph->SetMarkerSize(1);
    this->plot_graph->SetMarkerColor(kBlue); // Set marker color
}