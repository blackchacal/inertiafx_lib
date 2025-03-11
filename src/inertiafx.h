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
 * @file inertiafx.h
 * @brief InertiaFX library entry-point class.
 *
 * @date 10, Mar 2025
 */

#ifndef INERTIAFX_H
#define INERTIAFX_H

#include <string>

namespace InertiaFX
{
/**
 * @class InertiaFX
 * @brief The main class of the project.
 *
 * @details The InertiaFX class manages the core functionalities of the library.
 * It provides a static method to retrieve the current library version
 * defined via CMake.
 */
class InertiaFX
{
  public:
    /**
     * @brief Retrieves the current version of the InertiaFX library.
     * @return A std::string containing the library version.
     *
     * The version value should be defined by a macro at compile time
     * (e.g., via the CMakeLists.txt). For example:
     * @code
     * add_definitions(-DINERTIAFX_VERSION="1.0.0")
     * @endcode
     */
    static std::string getVersion();

    /**
     * @brief Default constructor.
     */
    InertiaFX();

    /**
     * @brief Destructor.
     */
    ~InertiaFX();

  private:
};
}  // namespace InertiaFX

#endif  // INERTIAFX_H
