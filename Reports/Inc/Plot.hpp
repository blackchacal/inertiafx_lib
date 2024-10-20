/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file Plot.hpp                                                             *
 * \brief Plot abstract class.                                                *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 18th 2024                                                   *
 *                                                                            *
 * \namespace InertiaFX::Reports                                              *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#ifndef _IFX_REPORTS_PLOT_HPP
#define _IFX_REPORTS_PLOT_HPP

#include <string>
#include <vector>

namespace InertiaFX
{
    namespace Reports
    {
        class Plot
        {
        public:
            Plot() = default;
            Plot(std::string title);
            ~Plot();

            virtual void show() = 0;
            void setTitle(std::string title);
            void setXAxisLabel(std::string label);
            void setYAxisLabel(std::string label);
            void setZAxisLabel(std::string label);
            void setXValues(std::vector<double> values);
            void setYValues(std::vector<double> values);
            void setZValues(std::vector<double> values);
            void addToXValues(double value);
            void addToYValues(double value);
            void addToZValues(double value);

            std::string getTitle();
            std::string getXAxisLabel();
            std::string getYAxisLabel();

        protected:
            std::string title;
            std::string x_axis_label;
            std::string y_axis_label;
            std::string z_axis_label;
            std::vector<double> x_values;
            std::vector<double> y_values;
            std::vector<double> z_values;
        };
    }
}
namespace ifx = InertiaFX;
#endif /* _IFX_REPORTS_PLOT_HPP */