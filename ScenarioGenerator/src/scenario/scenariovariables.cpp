/*
 * This file is part of the random scenario generator for Disciples 2.
 * (https://github.com/VladimirMakeev/D2RSG)
 * Copyright (C) 2023 Vladimir Makeev.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "scenariovariables.h"
#include "serializer.h"

namespace rsg {

void ScenarioVariables::serialize(Serializer& serializer, const Map& scenario) const
{
    serializer.enterRecord();

    CMidgardID::String idString{};
    objectId.toString(idString);

    serializer.serialize(idString.data(), static_cast<std::uint32_t>(variables.size()));

    for (int i = 0; i < variables.size(); i++) {
        serializer.serialize("ID", static_cast<std::uint32_t>(i));
        serializer.serialize("NAME", variables[i].name.c_str());
        serializer.serialize("VALUE", static_cast<std::uint32_t>(variables[i].value));
    }

    serializer.leaveRecord();
}

 void ScenarioVariables::add(std::string name, std::uint32_t value)
{
     variables.push_back({name, value});
 }

} // namespace rsg
