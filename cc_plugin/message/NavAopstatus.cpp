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

#include <cassert>

#include "NavAopstatus.h"
#include "cc_plugin/field/common.h"
#include "cc_plugin/field/nav.h"

template class ublox::message::NavAopstatus<ublox::cc_plugin::Message>;
template class ublox::cc_plugin::ProtocolMessageBase<
    ublox::message::NavAopstatus<ublox::cc_plugin::Message>,
    ublox::cc_plugin::message::NavAopstatus>;

namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

using ublox::message::NavAopstatusFields;

QVariantMap createProps_aopCfg()
{
    cc::property::field::ForField<NavAopstatusFields::aopCfg> props;
    props.name("aopCfg")
         .add("useAOP");
    assert(props.bits().size() == NavAopstatusFields::aopCfg::BitIdx_numOfValues);
    return props.asMap();
}

QVariantMap createProps_availGPS()
{
    cc::property::field::ForField<NavAopstatusFields::availGPS> props;
    props.name("availGPS");
    for (auto gps = 1; gps <= 32; ++gps) {
        props.add(QString("PRN %1").arg(gps, 1, 10, QChar('0')));
    }
    return props.asMap();
}


QVariantList createFieldsProperties()
{
    QVariantList props;
    props.append(cc_plugin::field::nav::props_iTOW());
    props.append(createProps_aopCfg());
    props.append(cc::property::field::ForField<NavAopstatusFields::status>().name("status").asMap());
    props.append(cc_plugin::field::common::props_reserved(0));
    props.append(cc_plugin::field::common::props_reserved(1));
    props.append(createProps_availGPS());
    props.append(cc_plugin::field::common::props_reserved(2));
    props.append(cc_plugin::field::common::props_reserved(3));

    assert(props.size() == NavAopstatus::FieldIdx_numOfValues);
    return props;
}

}  // namespace

NavAopstatus::NavAopstatus() = default;
NavAopstatus::~NavAopstatus() = default;

NavAopstatus& NavAopstatus::operator=(const NavAopstatus&) = default;
NavAopstatus& NavAopstatus::operator=(NavAopstatus&&) = default;

const char* NavAopstatus::nameImpl() const
{
    static const char* Str = "NAV-AOPSTATUS";
    return Str;
}

const QVariantList& NavAopstatus::fieldsPropertiesImpl() const
{
    static const auto Props = createFieldsProperties();
    return Props;
}

}  // namespace message

}  // namespace cc_plugin

}  // namespace ublox

