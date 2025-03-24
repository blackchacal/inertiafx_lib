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
 * @file mole.cpp
 * @brief Definition of the Mole unit class.
 *
 * @date 24, Mar 2025
 */

#include "mole.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        // Static description string
        const std::string Mole::DESCRIPTION =
            "The mole, symbol mol, is the SI unit of amount of substance. "
            "One mole contains exactly 6.022 140 76 x 1023 elementary "
            "entities. This number is the fixed numerical value of the "
            "Avogadro constant, NA, when expressed in the unit mol^–1 and "
            "is called the Avogadro number."
            "The amount of substance, symbol n, of a system is a measure "
            "of the number of specified elementary entities. An elementary "
            "entity may be an atom, a molecule, an ion, an electron, any "
            "other particle or specified group of particles.";

        Mole::Mole() : PhysicalUnit("mole", "moles", "mol", DESCRIPTION)
        {
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
