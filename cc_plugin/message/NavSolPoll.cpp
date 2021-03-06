//
// Copyright 2015 - 2017 (C). Alex Robenko. All rights reserved.
//

// This file is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "NavSolPoll.h"

template class ublox::message::NavSolPoll<ublox::cc_plugin::Message>;
template class ublox::cc_plugin::ProtocolMessageBase<
    ublox::message::NavSolPoll<ublox::cc_plugin::Message>,
    ublox::cc_plugin::message::NavSolPoll>;

namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

NavSolPoll::NavSolPoll() = default;
NavSolPoll::~NavSolPoll() = default;

NavSolPoll& NavSolPoll::operator=(const NavSolPoll&) = default;
NavSolPoll& NavSolPoll::operator=(NavSolPoll&&) = default;

const char* NavSolPoll::nameImpl() const
{
    static const char* Str = "NAV-SOL (Poll)";
    return Str;
}

}  // namespace message

}  // namespace cc_plugin

}  // namespace ublox

