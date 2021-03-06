//
// Copyright 2017 (C). Alex Robenko. All rights reserved.
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

#include <cassert>

#include "UpdSosAck.h"
#include "cc_plugin/field/common.h"

template class ublox::message::UpdSosAck<ublox::cc_plugin::Message>;
template class ublox::cc_plugin::ProtocolMessageBase<
    ublox::message::UpdSosAck<ublox::cc_plugin::Message>,
    ublox::cc_plugin::message::UpdSosAck>;

namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

using ublox::message::UpdSosAckFields;

QVariantMap createProps_response()
{
    using Field = UpdSosAckFields::response;
    auto props =
        cc::property::field::ForField<Field>()
            .name("response")
            .add("Not acknowledged")
            .add("Acknowledged");
    assert(props.values().size() == (int)Field::ValueType::NumOfValues);
    return props.asMap();
}

QVariantList createFieldsProperties()
{
    QVariantList props;
    props.append(
        cc::property::field::ForField<UpdSosAckFields::cmd>().name("cmd").readOnly().asMap());
    props.append(cc_plugin::field::common::props_reserved(1));
    props.append(createProps_response());
    props.append(cc_plugin::field::common::props_reserved(2));

    assert(props.size() == UpdSosAck::FieldIdx_numOfValues);
    return props;
}

}  // namespace

UpdSosAck::UpdSosAck() = default;
UpdSosAck::~UpdSosAck() = default;

UpdSosAck& UpdSosAck::operator=(const UpdSosAck&) = default;
UpdSosAck& UpdSosAck::operator=(UpdSosAck&&) = default;

const char* UpdSosAck::nameImpl() const
{
    static const char* Str = "UPD-SOS (Ack)";
    return Str;
}

const QVariantList& UpdSosAck::fieldsPropertiesImpl() const
{
    static const auto Props = createFieldsProperties();
    return Props;
}

}  // namespace message

}  // namespace cc_plugin

}  // namespace ublox

