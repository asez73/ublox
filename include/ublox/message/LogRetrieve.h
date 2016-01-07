//
// Copyright 2015 (C). Alex Robenko. All rights reserved.
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


#pragma once

#include "comms/Message.h"
#include "ublox/Message.h"
#include "ublox/field/common.h"

namespace ublox
{

namespace message
{

using LogRetrieveField_startNumber = field::common::U4;
using LogRetrieveField_entryCount =
    field::common::U4T<
        comms::option::ValidNumValueRange<0, 256>
    >;

using LogRetrieveField_version =
    field::common::U1T<
        comms::option::ValidNumValueRange<0, 0>
    >;
using LogRetrieveField_reserved = field::common::res3;

using LogRetrieveFields = std::tuple<
    LogRetrieveField_startNumber,
    LogRetrieveField_entryCount,
    LogRetrieveField_version,
    LogRetrieveField_reserved
>;


template <typename TMsgBase = Message>
class LogRetrieve : public
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_LOG_RETRIEVE>,
        comms::option::FieldsImpl<LogRetrieveFields>,
        comms::option::DispatchImpl<LogRetrieve<TMsgBase> >
    >
{
    typedef comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_LOG_RETRIEVE>,
        comms::option::FieldsImpl<LogRetrieveFields>,
        comms::option::DispatchImpl<LogRetrieve<TMsgBase> >
    > Base;
public:
    enum FieldIdx
    {
        FieldIdx_startNumber,
        FieldIdx_entryCount,
        FieldIdx_version,
        FieldIdx_reserved,
        FieldIdx_numOfValues
    };

    static_assert(std::tuple_size<typename Base::AllFields>::value == FieldIdx_numOfValues,
        "Number of fields is incorrect");

    LogRetrieve() = default;
    LogRetrieve(const LogRetrieve&) = default;
    LogRetrieve(LogRetrieve&& other) = default;
    virtual ~LogRetrieve() = default;

    LogRetrieve& operator=(const LogRetrieve&) = default;
    LogRetrieve& operator=(LogRetrieve&&) = default;
};


}  // namespace message

}  // namespace ublox
