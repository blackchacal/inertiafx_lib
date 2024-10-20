/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file ReportTypes.h                                                        *
 * \brief Types used by the Reports module.                                   *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 18th 2024                                                   *
 *                                                                            *
 * \namespace InertiaFX::Reports                                              *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#ifndef _IFX_REPORTS_REPORT_TYPES_H
#define _IFX_REPORTS_REPORT_TYPES_H

namespace InertiaFX
{
    namespace Reports
    {
        enum class PlotType
        {
            Scalar,
            Vector,
        };
    }
}
namespace ifx = InertiaFX;
#endif /* _IFX_REPORTS_REPORT_TYPES_H */