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
 * @file derived_qty.h
 * @brief Declaration of the DerivedQty abstract class.
 *
 * @date 22, Mar 2025
 */

#ifndef INERTIAFX_CORE_SI_DERIVEDQTY_H
#define INERTIAFX_CORE_SI_DERIVEDQTY_H

#include "decimal_prefix.h"
#include "iphysical_qty.h"
#include "iphysical_unit.h"
#include <string>

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @class DerivedQty
         * @brief Represents a derived physical quantity in the system (e.g., velocity,
         * acceleration).
         * @tparam T Numeric type used to store the value of the physical quantity.
         *
         * This class implements only a subset of the IPhysicalQty interface:
         * - getName()
         * - getSymbol()
         * - getDescription()
         * - getUnitName()
         * - getUnitSymbol()
         * - getUnitDescription()
         * - isFundamental()
         *
         * All other methods remain pure virtual for further specialized classes.
         */
        template <typename T>
        class DerivedQty : public IPhysicalQty
        {
          public:
            /**
             * @brief Constructs a new DerivedQty object.
             * @param name The name of the physical quantity (e.g., "Velocity", "Acceleration").
             * @param symbol The symbol of the physical quantity (e.g., "v", "a").
             * @param description A short description of this quantity.
             * @param unit The IPhysicalUnit defining the base unit info for this quantity.
             */
            DerivedQty(const std::string &name, const std::string &symbol,
                       const std::string &description, const IPhysicalUnit &unit) :
                _name(name), _symbol(symbol), _description(description), _value(static_cast<T>(0)),
                _unit(unit), _prefix(DecimalPrefix::Name::base), _isFundamental(false)
            {
            }

            /**
             * @brief Virtual destructor.
             */
            virtual ~DerivedQty() = default;

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
             * @copydoc IPhysicalQty::getUnitName()
             */
            std::string getUnitName() const override
            {
                return _unit.getName();
            }

            /**
             * @copydoc IPhysicalQty::getUnitSymbol()
             */
            std::string getUnitSymbol() const override
            {
                return _unit.getSymbol();
            }

            /**
             * @copydoc IPhysicalQty::getUnitDescription()
             */
            std::string getUnitDescription() const override
            {
                return _unit.getDescription();
            }

            /**
             * @copydoc IPhysicalQty::isFundamental()
             */
            bool isFundamental() const override
            {
                return _isFundamental;
            }

            // ---------------------------------------------------------------------
            // Methods from IPhysicalQty that remain pure virtual for further derived classes:
            //
            // - template <typename T> T getValue() const
            // - template <typename T> T getValueIn(DecimalPrefix::Name) const
            // - template <typename T> T getValueIn(DecimalPrefix::Symbol) const
            // - template <typename T> void setValueFrom(T, DecimalPrefix::Name)
            // - template <typename T> void setValueFrom(T, DecimalPrefix::Symbol)
            // - std::string toString() const
            // - std::string toString(DecimalPrefix::Name) const
            // - std::string toString(DecimalPrefix::Symbol) const
            // ---------------------------------------------------------------------

          protected:
            std::string _name;         //!< @brief Name of the quantity
            std::string _symbol;       //!< @brief Symbol of the quantity
            std::string _description;  //!< @brief Description of the quantity
            T _value;                  //!< @brief Internal value storage
            std::unique_ptr<IPhysicalUnit>
                _unit;                    //!< @brief Defines the base unit of this quantity
            DecimalPrefix::Name _prefix;  //!< @brief Current decimal prefix
            bool _isFundamental;  //!< @brief Indicates if this quantity is fundamental (false)
        };

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_DERIVEDQTY_H
