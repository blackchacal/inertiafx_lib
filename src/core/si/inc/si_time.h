/**
 * InertiaFX_Lib - Physics Simulation Library.
 * Copyright (C) 2025  Ricardo Tonet <https://github.com/blackchacal>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
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
 * @file si_time.h
 * @brief Declaration of the Time class.
 *
 * @date 23, Mar 2025
 */

#ifndef INERTIAFX_CORE_SI_TIME_H
#define INERTIAFX_CORE_SI_TIME_H

#include "fundamental_qty.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @class Time
         * @brief Concrete fundamental quantity representing time.
         */
        class Time : public FundamentalQty
        {
          public:
            /**
             * @brief Constructs a new Time object.
             *
             * The time is initialized to 1.0 and stored in base prefix value.
             */
            Time();

            /**
             * @brief Constructs a new Time object.
             * @param value The numeric value of time in the specified prefix.
             * @param prefix The decimal prefix name (e.g., "kilo", "milli") in which 'value' is
             * expressed. It defaults to base which is 10^0.
             *
             * Internally, the time is stored in base prefix value.
             */
            Time(double value, DecimalPrefix::Name prefix = DecimalPrefix::Name::base);

            /**
             * @brief Constructs a new Time object.
             * @param value The numeric value of time in the specified prefix.
             * @param prefix The decimal prefix symbol (e.g., "k", "m") in which 'value' is
             * expressed. It defaults to base which is 10^0.
             *
             * Internally, the time is stored in base prefix value.
             */
            Time(double value, DecimalPrefix::Symbol prefix = DecimalPrefix::Symbol::base);

            /**
             * @brief Copy constructor.
             * @details Constructs a new Time object from an existing one.
             *
             * @param other The other Time object to copy from.
             */
            Time(const Time &other);

            /**
             * @brief Copy assignment operator.
             * @details Constructs a new Time object from an existing one.
             *
             * @param other The other Time object to copy from.
             * @return A reference to this object.
             *
             * @note This operator performs a deep copy of the object.
             */
            Time &operator=(const Time &other);

            /**
             * @brief Addition operator.
             * @details Adds two Time objects together.
             *
             * @param other The other Time object to add.
             * @return A new Time object representing the sum.
             */
            Time operator+(const Time &other) const;
        };

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_TIME_H
