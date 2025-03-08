/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file VectorPlot.hpp                                                       *
 * \brief Vector Plot class.                                                  *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 21th 2024                                                   *
 *                                                                            *
 * \namespace InertiaFX::Reports                                              *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#ifndef _IFX_REPORTS_VECTOR_PLOT_HPP
#define _IFX_REPORTS_VECTOR_PLOT_HPP

#include "Plot.hpp"
#include <TGraph2D.h>

namespace InertiaFX
{
    namespace Reports
    {
        class VectorPlot : public Plot
        {
        public:
            VectorPlot(std::string title);
            VectorPlot(std::string title, std::vector<double> x_values, std::vector<double> y_values, std::vector<double> z_values);
            ~VectorPlot();

            void show() override;

        private:
            TGraph2D *plot_graph;
        };
    }
}
namespace ifx = InertiaFX;
#endif /* _IFX_REPORTS_VECTOR_PLOT_HPP */