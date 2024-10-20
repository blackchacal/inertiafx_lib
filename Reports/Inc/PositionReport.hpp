/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file PositionReport.hpp                                                   *
 * \brief Position Report class.                                              *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 19th 2024                                                   *
 *                                                                            *
 * \namespace InertiaFX::Reports                                              *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#ifndef _IFX_REPORTS_POSITION_REPORT_HPP
#define _IFX_REPORTS_POSITION_REPORT_HPP

#include "Report.hpp"

namespace InertiaFX
{
    namespace Reports
    {
        class PositionReport : public Report
        {
        public:
            PositionReport(IBody *body, RefDimensions dimensions, PlotType type);
            PositionReport(IBody *body, RefDimensions dimensions, PlotType type, std::string title);
            ~PositionReport();

            void updateData(uint32_t t) override;
        };
    }
}
namespace ifx = InertiaFX;
#endif /* _IFX_REPORTS_POSITION_REPORT_HPP */