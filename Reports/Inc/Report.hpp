/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file Report.hpp                                                           *
 * \brief Report abstract class.                                              *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 18th 2024                                                   *
 *                                                                            *
 * \namespace InertiaFX::Reports                                              *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#ifndef _IFX_REPORTS_REPORT_HPP
#define _IFX_REPORTS_REPORT_HPP

#include <string>

#include <TCanvas.h>

#include "IBody.h"
#include "Plot.hpp"
#include "GenericTypes.h"
#include "ReportTypes.hpp"

using namespace InertiaFX::Core;

namespace InertiaFX
{
    namespace Reports
    {
        class Report
        {
        public:
            Report(IBody *body, RefDimensions dimensions, PlotType type);
            Report(IBody *body, RefDimensions dimensions, PlotType type, std::string title);
            ~Report();

            void showFullReport();
            void showPlots();
            virtual void updateData(uint32_t t) = 0;
            void setReportTitle(std::string title);
            void setPlotTitle(uint8_t idx, std::string title);
            void setPlotXAxisLabel(uint8_t idx, std::string label);
            void setPlotYAxisLabel(uint8_t idx, std::string label);
            void setPlotZAxisLabel(uint8_t idx, std::string label);
            void setPlotType(PlotType type);

        protected:
            IBody *body;
            std::vector<Plot *> plots;
            RefDimensions dimensions;
            PlotType type;
            std::string title;
            TCanvas *plot_canvas;
        };
    }
}
namespace ifx = InertiaFX;
#endif /* _IFX_REPORTS_REPORT_HPP */