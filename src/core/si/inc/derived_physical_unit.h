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
 * @file derived_physical_unit.h
 * @brief Declaration of the DerivedPhysicalUnit class.
 *
 * @date 03, Apr 2025
 */

#ifndef INERTIAFX_CORE_SI_DERIVED_PHYSICAL_UNIT_H
#define INERTIAFX_CORE_SI_DERIVED_PHYSICAL_UNIT_H

#include "decimal_prefix.h"
#include "iphysical_unit.h"
#include <string>
#include <vector>

using namespace InertiaFX::Core::SI;

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @struct PhysicalUnitPower
         * @brief A structure to represent a physical unit and its power.
         *
         * This structure is used to represent a physical unit along with the power to which it is
         * raised. It is primarily used in the context of derived physical units.
         */
        struct PhysicalUnitPower
        {
            /** Unit. */
            std::unique_ptr<IPhysicalUnit> unit;
            /** Power to which the unit is raised. */
            int power;

            /**
             * @brief Constructs a PhysicalUnitPower with a given unit and power.
             * @param u A unique pointer to an IPhysicalUnit representing the unit.
             * @param p An integer representing the power of the unit.
             */
            PhysicalUnitPower(std::unique_ptr<IPhysicalUnit> u, int p) :
                unit(std::move(u)), power(p)
            {
            }

            /**
             * @brief Copy constructor for PhysicalUnitPower.
             * @param other The PhysicalUnitPower object to copy from.
             */
            PhysicalUnitPower(const PhysicalUnitPower &other) :
                unit(other.unit ? other.unit->clone() : nullptr), power(other.power)
            {
            }

            /**
             * @brief Move constructor for PhysicalUnitPower.
             * @param other The PhysicalUnitPower object to move from.
             */
            PhysicalUnitPower &operator=(const PhysicalUnitPower &other)
            {
                if (this != &other)
                {
                    unit  = (other.unit ? other.unit->clone() : nullptr);
                    power = other.power;  // Ensure power is copied
                }
                return *this;
            }
        };

        /**
         * @class DerivedPhysicalUnit
         * @brief A class to represent derived physical units that implements the IPhysicalUnit
         * interface.
         *
         * This class provides a generic implementation for a derived physical unit by obtaining
         * the basic attributes such as name, symbol through a combination of the names and symbols
         * of the base units that form the derived unit.
         */
        class DerivedPhysicalUnit : public IPhysicalUnit
        {
          public:
            /**
             * @brief Constructs a DerivedPhysicalUnit from a list of base units.
             * @param baseUnits A vector of PhysicalUnitPower objects representing the base units
             * and their powers.
             * @param description A short description of the derived unit's purpose or usage.
             */
            DerivedPhysicalUnit(std::vector<PhysicalUnitPower> baseUnits,
                                const std::string &description);

            /**
             * @brief Destructor.
             */
            virtual ~DerivedPhysicalUnit() = default;

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

            std::unique_ptr<IPhysicalUnit> clone() const override
            {
                return std::make_unique<DerivedPhysicalUnit>(*this);
            }

          protected:
            /** The symbol of the unit. */
            std::string _symbol;

          private:
            std::string _name;        /** The full name of the unit. */
            std::string _pluralName;  /** The full name of the unit in plural form. */
            std::string _description; /** A brief description of the unit. */

            std::string buildBaseUnitName(PhysicalUnitPower baseUnit) const;
            std::string buildBaseUnitPluralName(PhysicalUnitPower baseUnit) const;
        };

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_DERIVED_PHYSICAL_UNIT_H
