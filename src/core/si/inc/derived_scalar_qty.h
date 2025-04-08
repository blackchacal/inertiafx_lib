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
 * @file derived_scalar_qty.h
 * @brief Declaration of the DerivedScalarQty abstract class.
 *
 * @date 25, Mar 2025
 */

#ifndef INERTIAFX_CORE_SI_DERIVED_SCALAR_QTY_H
#define INERTIAFX_CORE_SI_DERIVED_SCALAR_QTY_H

#include "decimal_prefix.h"
#include "iphysical_unit.h"
#include "iscalar_qty.h"
#include <string>

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @class DerivedScalarQty
         * @brief Represents a derived scalar physical quantity in the system (e.g., area, volume).
         */
        class DerivedScalarQty : public IScalarQty
        {
          public:
            /**
             * @brief Constructs a new DerivedScalarQty object.
             * @param name The name of the physical quantity (e.g., "Area", "Volume").
             * @param symbol The symbol of the physical quantity (e.g., "A", "V").
             * @param description A short description of this quantity.
             * @param unit The IPhysicalUnit defining the base unit info for this quantity.
             */
            DerivedScalarQty(const std::string &name, const std::string &symbol,
                             const std::string &description, std::unique_ptr<IPhysicalUnit> unit) :
                _name(name), _symbol(symbol), _description(description),
                _value(static_cast<double>(0)), _unit(std::move(unit)),
                _prefix(DecimalPrefix::Name::base)
            {
            }

            /**
             * @brief Constructs a new FundamentalQty object by copying another instance.
             * @param other The other instance to copy from.
             */
            DerivedScalarQty(const DerivedScalarQty &other)
            {
                // If other._unit is not null, clone it; else store null
                _unit =
                    other._unit ? std::unique_ptr<IPhysicalUnit>(other._unit->clone()) : nullptr;
            }

            DerivedScalarQty &operator=(const DerivedScalarQty &other)
            {
                if (this != &other)
                {
                    // If there's an existing owned object, remove it
                    _unit.reset();

                    // Deep-copy from other
                    if (other._unit)
                    {
                        _unit = std::unique_ptr<IPhysicalUnit>(other._unit->clone());
                    }
                }
                return *this;
            }

            /**
             * @brief Virtual destructor.
             */
            virtual ~DerivedScalarQty() = default;

            /**
             * @copydoc IPhysicalQty::getName()
             */
            std::string getName() const override
            {
                return _name;
            }

            /**
             * @copydoc IPhysicalQty::getSymbol()
             */
            std::string getSymbol() const override
            {
                return _symbol;
            }

            /**
             * @copydoc IPhysicalQty::getDescription()
             */
            std::string getDescription() const override
            {
                return _description;
            }

            /**
             * @copydoc IPhysicalQty::isFundamental()
             */
            bool isFundamental() const override
            {
                return false;
            }

            /**
             * @copydoc IPhysicalQty::getUnitName()
             */
            std::string getUnitName() const override
            {
                return _unit->getName();
            }

            /**
             * @copydoc IPhysicalQty::getUnitPluralName()
             */
            std::string getUnitPluralName() const override
            {
                return _unit->getPluralName();
            }

            /**
             * @copydoc IPhysicalQty::getUnitSymbol()
             */
            std::string getUnitSymbol() const override
            {
                return _unit->getSymbol();
            }

            /**
             * @copydoc IPhysicalQty::getUnitDescription()
             */
            std::string getUnitDescription() const override
            {
                return _unit->getDescription();
            }

            /**
             * @copydoc IScalarQty::getValue()
             */
            double getValue() const
            {
                return _value;
            }

            /**
             * @copydoc IScalarQty::getValueIn(DecimalPrefix::Name)
             */
            double getValueIn(DecimalPrefix::Name prefix) const
            {
                return _value / DecimalPrefix::getMultiplier(prefix);
            }

            /**
             * @copydoc IScalarQty::getValueIn(DecimalPrefix::Symbol)
             */
            double getValueIn(DecimalPrefix::Symbol prefix) const
            {
                return _value / DecimalPrefix::getMultiplier(prefix);
            }

            /**
             * @copydoc IScalarQty::setValue(double)
             */
            void setValue(double newValue)
            {
                _value  = newValue;
                _prefix = DecimalPrefix::Name::base;
            }

            /**
             * @copydoc IScalarQty::setValueFrom(double, DecimalPrefix::Name)
             */
            void setValueFrom(double newValue, DecimalPrefix::Name prefix)
            {
                _value  = newValue * DecimalPrefix::getMultiplier(prefix);
                _prefix = prefix;
            }

            /**
             * @copydoc IScalarQty::setValueFrom(T newValue, DecimalPrefix::Symbol prefix)
             */
            void setValueFrom(double newValue, DecimalPrefix::Symbol prefix)
            {
                _value  = newValue * DecimalPrefix::getMultiplier(prefix);
                _prefix = static_cast<DecimalPrefix::Name>(prefix);
            }

            // toString()
            std::string toString() const
            {
                // Format as "value [base unit_symbol]"
                // e.g., "12.345 m"
                return std::to_string(_value) + " " + this->getUnitSymbol();
            }

            // toString(DecimalPrefix::Name)
            std::string toString(DecimalPrefix::Name prefix) const
            {
                double scaledValue = _value / DecimalPrefix::getMultiplier(prefix);

                // Build something like: "12.3 km"
                return std::to_string(scaledValue) + " " + DecimalPrefix::getSymbol(prefix) +
                       this->getUnitSymbol();
            }

            // toString(DecimalPrefix::Symbol)
            std::string toString(DecimalPrefix::Symbol prefix) const
            {
                double scaledValue = _value / DecimalPrefix::getMultiplier(prefix);

                // Build something like: "12.3 km"
                return std::to_string(scaledValue) + " " + DecimalPrefix::getSymbol(prefix) +
                       this->getUnitSymbol();
            }

          protected:
            std::string _name;         //!< @brief Name of the quantity
            std::string _symbol;       //!< @brief Symbol of the quantity
            std::string _description;  //!< @brief Description of the quantity
            double _value;             //!< @brief Internal value storage
            std::unique_ptr<IPhysicalUnit>
                _unit;                    //!< @brief Defines the base unit of this quantity
            DecimalPrefix::Name _prefix;  //!< @brief Current decimal prefix
        };

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_DERIVED_SCALAR_QTY_H
