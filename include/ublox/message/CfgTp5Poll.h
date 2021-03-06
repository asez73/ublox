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

/// @file
/// @brief Contains definition of CFG-TP5 (@b poll) message and its fields.

#pragma once

#include "ublox/Message.h"

namespace ublox
{

namespace message
{

/// @brief Accumulates details of all the CFG-TP5 (@b poll) message fields.
/// @see CfgTp5Poll
struct CfgTp5PollFields
{
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<>;
};

/// @brief Definition of CFG-TP5 (@b poll) message
/// @details Inherits from @b comms::MessageBase
///     while providing @b TMsgBase as common interface class as well as
///     various implementation options. @n
///     See @ref CfgTp5PollFields and for definition of the fields this message contains.
/// @tparam TMsgBase Common interface class for all the messages.
template <typename TMsgBase = Message>
class CfgTp5Poll : public
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_CFG_TP5>,
        comms::option::FieldsImpl<CfgTp5PollFields::All>,
        comms::option::MsgType<CfgTp5Poll<TMsgBase> >
    >
{

public:

    /// @brief Default constructor
    CfgTp5Poll() = default;

    /// @brief Copy constructor
    CfgTp5Poll(const CfgTp5Poll&) = default;

    /// @brief Move constructor
    CfgTp5Poll(CfgTp5Poll&& other) = default;

    /// @brief Destructor
    ~CfgTp5Poll() = default;

    /// @brief Copy assignment
    CfgTp5Poll& operator=(const CfgTp5Poll&) = default;

    /// @brief Move assignment
    CfgTp5Poll& operator=(CfgTp5Poll&&) = default;
};


}  // namespace message

}  // namespace ublox

