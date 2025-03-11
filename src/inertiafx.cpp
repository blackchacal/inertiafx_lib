/**
 * InertiaFX_Lib - Physics Simulation Library.
 * Copyright (C) 2025  Ricardo Tonet <https://github.com/blackchacal>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/**
 * @file inertiafx.cpp
 * @brief Implementation of the InertiaFX library entry-point class.
 *
 * @date 10, Mar 2025
 */

#include "inertiafx.h"

namespace InertiaFX
{

std::string InertiaFX::getVersion()
{
#ifdef INERTIAFX_VERSION
    return INERTIAFX_VERSION;
#else
    return "UnknownVersion";
#endif
}

InertiaFX::InertiaFX()
{
    // Constructor code (if needed)
}

InertiaFX::~InertiaFX()
{
    // Destructor code (if needed)
}

}  // namespace InertiaFX