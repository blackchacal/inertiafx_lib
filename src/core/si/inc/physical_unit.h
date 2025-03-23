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
 * @file physical_unit.h
 * @brief Declaration of the PhysicalUnit class.
 *
 * @date 16, Mar 2025
 */

#ifndef INERTIAFX_CORE_SI_PHYSICALUNIT_H
#define INERTIAFX_CORE_SI_PHYSICALUNIT_H

#include "decimal_prefix.h"
#include "iphysical_unit.h"
#include <string>

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @class PhysicalUnit
         * @brief A base class that implements the IPhysicalUnit interface.
         *
         * This class provides a generic implementation for a physical unit by storing
         * basic attributes such as name, symbol, and description. It also provides
         * string representations of the unit with or without decimal prefixes.
         */
        class PhysicalUnit : public IPhysicalUnit
        {
          private:
            std::string _name;        /**< The full name of the unit. */
            std::string _pluralName;  /**< The full name of the unit in plural form. */
            std::string _description; /**< A brief description of the unit. */

          protected:
            std::string _symbol; /**< The symbol of the unit. */

          public:
            /**
             * @brief Constructs a PhysicalUnit with given name, symbol, and description.
             * @param name A string representing the full name of the unit (e.g., "metre").
             * @param namePlural A string representing the full name of the unit in plural form
             * (e.g., "metres").
             * @param symbol A string representing the symbol of the unit (e.g., "m").
             * @param description A short description of the unit's purpose or usage.
             */
            PhysicalUnit(const std::string &name, const std::string &namePlural,
                         const std::string &symbol, const std::string &description);

            /**
             * @brief Destructor.
             */
            virtual ~PhysicalUnit() = 0;

            /**
             * @copydoc IPhysicalUnit::getName()
             */
            virtual std::string getName() const override;

            /**
             * @copydoc IPhysicalUnit::getPluralName()
             */
            virtual std::string getPluralName() const override;

            /**
             * @copydoc IPhysicalUnit::getSymbol()
             */
            virtual std::string getSymbol() const override;

            /**
             * @copydoc IPhysicalUnit::getDescription()
             */
            virtual std::string getDescription() const override;

            /**
             * @copydoc IPhysicalUnit::toString()
             */
            virtual std::string toString() const override;

            /**
             * @copydoc IPhysicalUnit::toString(DecimalPrefix::Name) const
             */
            virtual std::string toString(DecimalPrefix::Name prefixName) const override;

            /**
             * @copydoc IPhysicalUnit::toString(DecimalPrefix::Symbol) const
             */
            virtual std::string toString(DecimalPrefix::Symbol prefixSymbol) const override;
        };

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_PHYSICALUNIT_H
