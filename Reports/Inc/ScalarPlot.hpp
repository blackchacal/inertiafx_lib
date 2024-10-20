/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file ScalarPlot.hpp                                                       *
 * \brief Scalar Plot class.                                                  *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 18th 2024                                                   *
 *                                                                            *
 * \namespace InertiaFX::Reports                                              *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#ifndef _IFX_REPORTS_SCALAR_PLOT_HPP
#define _IFX_REPORTS_SCALAR_PLOT_HPP

#include "Plot.hpp"
#include <TGraph.h>

namespace InertiaFX
{
    namespace Reports
    {
        class ScalarPlot : public Plot
        {
        public:
            ScalarPlot(std::string title);
            ScalarPlot(std::string title, std::vector<double> x_values, std::vector<double> y_values);
            ~ScalarPlot();

            void show() override;

        private:
            TGraph *plot_graph;
        };
    }
}
namespace ifx = InertiaFX;
#endif /* _IFX_REPORTS_SCALAR_PLOT_HPP */