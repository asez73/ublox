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


#pragma once

#include "comms_champion/comms_champion.h"
#include "ublox/message/NavAopstatusU8.h"
#include "cc_plugin/Message.h"
#include "cc_plugin/ProtocolMessageBase.h"

namespace ublox
{

namespace cc_plugin
{

namespace message
{

class NavAopstatusU8 : public
    ProtocolMessageBase<
        ublox::message::NavAopstatusU8<ublox::cc_plugin::Message>,
        NavAopstatusU8>
{
public:
    NavAopstatusU8();
    NavAopstatusU8(const NavAopstatusU8&) = delete;
    NavAopstatusU8(NavAopstatusU8&&) = delete;
    virtual ~NavAopstatusU8();

    NavAopstatusU8& operator=(const NavAopstatusU8&);
    NavAopstatusU8& operator=(NavAopstatusU8&&);

protected:
    virtual const char* nameImpl() const override;
    virtual const QVariantList& fieldsPropertiesImpl() const override;
};

}  // namespace message

}  // namespace cc_plugin

}  // namespace ublox

extern template class ublox::message::NavAopstatusU8<ublox::cc_plugin::Message>;
extern template class ublox::cc_plugin::ProtocolMessageBase<
    ublox::message::NavAopstatusU8<ublox::cc_plugin::Message>,
    ublox::cc_plugin::message::NavAopstatusU8>;

