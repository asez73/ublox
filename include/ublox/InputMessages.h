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
/// @brief Contains definition of ublox::InputMessages bundle.

#pragma once

#include <tuple>

#include "Message.h"

#include "message/NavPosecef.h"
#include "message/NavPosllh.h"
#include "message/NavStatus.h"
#include "message/NavDop.h"
#include "message/NavSol.h"
#include "message/NavPvt.h"
#include "message/NavOdo.h"
#include "message/NavVelecef.h"
#include "message/NavVelned.h"
#include "message/NavTimegps.h"
#include "message/NavTimeutc.h"
#include "message/NavClock.h"
#include "message/NavTimeglo.h"
#include "message/NavTimebds.h"
#include "message/NavTimegal.h"
#include "message/NavTimels.h"
#include "message/NavSvinfo.h"
#include "message/NavDgps.h"
#include "message/NavSbas.h"
#include "message/NavOrb.h"
#include "message/NavSat.h"
#include "message/NavGeofence.h"
#include "message/NavEkfstatus.h"
#include "message/NavAopstatus.h"
#include "message/NavAopstatusU8.h"
#include "message/NavEoe.h"

#include "message/RxmRaw.h"
#include "message/RxmSfrb.h"
#include "message/RxmSfrbx.h"
#include "message/RxmMeasx.h"
#include "message/RxmRawx.h"
#include "message/RxmSvsi.h"
#include "message/RxmAlm.h"
#include "message/RxmEph.h"
#include "message/RxmRlmShort.h"
#include "message/RxmRlmLong.h"
#include "message/RxmImes.h"

#include "message/InfError.h"
#include "message/InfWarning.h"
#include "message/InfNotice.h"
#include "message/InfTest.h"
#include "message/InfDebug.h"

#include "message/AckNak.h"
#include "message/AckAck.h"

#include "message/CfgPrtUart.h"
#include "message/CfgPrtUsb.h"
#include "message/CfgPrtSpi.h"
#include "message/CfgPrtDdc.h"
#include "message/CfgMsg.h"
#include "message/CfgMsgCurrent.h"
#include "message/CfgInf.h"
#include "message/CfgDat.h"
#include "message/CfgTp.h"
#include "message/CfgRate.h"
#include "message/CfgFxn.h"
#include "message/CfgRxm.h"
#include "message/CfgEkf.h"
#include "message/CfgAnt.h"
#include "message/CfgSbas.h"
#include "message/CfgNmeaExt.h"
#include "message/CfgNmea.h"
#include "message/CfgUsb.h"
#include "message/CfgTmode.h"
#include "message/CfgOdo.h"
#include "message/CfgNavx5.h"
#include "message/CfgNav5.h"
#include "message/CfgEsfgwt.h"
#include "message/CfgTp5.h"
#include "message/CfgPm.h"
#include "message/CfgRinv.h"
#include "message/CfgItfm.h"
#include "message/CfgPm2.h"
#include "message/CfgTmode2.h"
#include "message/CfgGnss.h"
#include "message/CfgLogfilter.h"
#include "message/CfgEsrc.h"
#include "message/CfgDosc.h"
#include "message/CfgSmgr.h"
#include "message/CfgGeofence.h"
#include "message/CfgPms.h"

#include "message/UpdSosRestored.h"
#include "message/UpdSosAck.h"

#include "message/MonIo.h"
#include "message/MonVer.h"
#include "message/MonMsgpp.h"
#include "message/MonRxbuf.h"
#include "message/MonTxbuf.h"
#include "message/MonHw.h"
#include "message/MonHw2.h"
#include "message/MonRxr.h"
#include "message/MonPatch.h"
#include "message/MonGnss.h"
#include "message/MonSmgr.h"

#include "message/AidIni.h"
#include "message/AidHui.h"
#include "message/AidAlm.h"
#include "message/AidEph.h"
#include "message/AidAlpsrv.h"
#include "message/AidAlpsrvUpdate.h"
#include "message/AidAopU8.h"
#include "message/AidAop.h"
#include "message/AidAlp.h"
#include "message/AidAlpStatus.h"

#include "message/TimTp.h"
#include "message/TimTm2.h"
#include "message/TimSvin.h"
#include "message/TimVrfy.h"
#include "message/TimDosc.h"
#include "message/TimTos.h"
#include "message/TimSmeas.h"
#include "message/TimVcocal.h"
#include "message/TimFchg.h"

#include "message/EsfStatus.h"

#include "message/MgaFlashAck.h"
#include "message/MgaAck.h"
#include "message/MgaDbd.h"

#include "message/LogInfo.h"
#include "message/LogRetrievepos.h"
#include "message/LogRetrievestring.h"
#include "message/LogFindtime.h"
#include "message/LogRetrieveposextra.h"

#include "message/SecSign.h"
#include "message/SecUniqid.h"

namespace ublox
{

/// @brief All input messages (the ones that can be sent out from u-blox receiver)
///     are bundled in std::tuple.
/// @tparam TMessage Common message interface class
template <typename TMessage = Message>
using InputMessages =
    std::tuple<
        message::NavPosecef<TMessage>,
        message::NavPosllh<TMessage>,
        message::NavStatus<TMessage>,
        message::NavDop<TMessage>,
        message::NavSol<TMessage>,
        message::NavPvt<TMessage>,
        message::NavOdo<TMessage>,
        message::NavVelecef<TMessage>,
        message::NavVelned<TMessage>,
        message::NavTimegps<TMessage>,
        message::NavTimeutc<TMessage>,
        message::NavClock<TMessage>,
        message::NavTimeglo<TMessage>,
        message::NavTimebds<TMessage>,
        message::NavTimegal<TMessage>,
        message::NavTimels<TMessage>,
        message::NavSvinfo<TMessage>,
        message::NavDgps<TMessage>,
        message::NavSbas<TMessage>,
        message::NavOrb<TMessage>,
        message::NavSat<TMessage>,
        message::NavGeofence<TMessage>,
        message::NavEkfstatus<TMessage>,
        message::NavAopstatus<TMessage>,
        message::NavAopstatusU8<TMessage>,
        message::RxmRaw<TMessage>,
        message::RxmSfrb<TMessage>,
        message::RxmSfrbx<TMessage>,
        message::RxmMeasx<TMessage>,
        message::RxmRawx<TMessage>,
        message::RxmSvsi<TMessage>,
        message::RxmAlm<TMessage>,
        message::RxmEph<TMessage>,
        message::RxmRlmShort<TMessage>,
        message::RxmRlmLong<TMessage>,
        message::RxmImes<TMessage>,
        message::InfError<TMessage>,
        message::InfWarning<TMessage>,
        message::InfNotice<TMessage>,
        message::InfTest<TMessage>,
        message::InfDebug<TMessage>,
        message::AckNak<TMessage>,
        message::AckAck<TMessage>,
        message::CfgPrtUart<TMessage>,
        message::CfgPrtUsb<TMessage>,
        message::CfgPrtSpi<TMessage>,
        message::CfgPrtDdc<TMessage>,
        message::CfgMsg<TMessage>,
        message::CfgMsgCurrent<TMessage>,
        message::CfgInf<TMessage>,
        message::CfgDat<TMessage>,
        message::CfgTp<TMessage>,
        message::CfgRate<TMessage>,
        message::CfgFxn<TMessage>,
        message::CfgRxm<TMessage>,
        message::CfgEkf<TMessage>,
        message::CfgAnt<TMessage>,
        message::CfgSbas<TMessage>,
        message::CfgNmeaExt<TMessage>,
        message::CfgNmea<TMessage>,
        message::CfgUsb<TMessage>,
        message::CfgTmode<TMessage>,
        message::CfgOdo<TMessage>,
        message::CfgNavx5<TMessage>,
        message::CfgNav5<TMessage>,
        message::CfgEsfgwt<TMessage>,
        message::CfgTp5<TMessage>,
        message::CfgPm<TMessage>,
        message::CfgRinv<TMessage>,
        message::CfgItfm<TMessage>,
        message::CfgPm2<TMessage>,
        message::CfgTmode2<TMessage>,
        message::CfgGnss<TMessage>,
        message::CfgLogfilter<TMessage>,
        message::CfgEsrc<TMessage>,
        message::CfgDosc<TMessage>,
        message::CfgSmgr<TMessage>,
        message::CfgGeofence<TMessage>,
        message::CfgPms<TMessage>,
        message::UpdSosRestored<TMessage>,
        message::UpdSosAck<TMessage>,
        message::MonIo<TMessage>,
        message::MonVer<TMessage>,
        message::MonMsgpp<TMessage>,
        message::MonRxbuf<TMessage>,
        message::MonTxbuf<TMessage>,
        message::MonHw<TMessage>,
        message::MonHw2<TMessage>,
        message::MonRxr<TMessage>,
        message::MonPatch<TMessage>,
        message::MonGnss<TMessage>,
        message::MonSmgr<TMessage>,
        message::AidIni<TMessage>,
        message::AidHui<TMessage>,
        message::AidAlm<TMessage>,
        message::AidEph<TMessage>,
        message::AidAlpsrv<TMessage>,
        message::AidAlpsrvUpdate<TMessage>,
        message::AidAopU8<TMessage>,
        message::AidAop<TMessage>,
        message::AidAlp<TMessage>,
        message::AidAlpStatus<TMessage>,
        message::TimTp<TMessage>,
        message::TimTm2<TMessage>,
        message::TimSvin<TMessage>,
        message::TimVrfy<TMessage>,
        message::TimDosc<TMessage>,
        message::TimTos<TMessage>,
        message::TimSmeas<TMessage>,
        message::TimVcocal<TMessage>,
        message::TimFchg<TMessage>,
        message::EsfStatus<TMessage>,
        message::MgaFlashAck<TMessage>,
        message::MgaAck<TMessage>,
        message::MgaDbd<TMessage>,
        message::LogInfo<TMessage>,
        message::LogRetrievepos<TMessage>,
        message::LogRetrievestring<TMessage>,
        message::LogFindtime<TMessage>,
        message::LogRetrieveposextra<TMessage>,
        message::SecSign<TMessage>,
        message::SecUniqid<TMessage>
    >;

}  // namespace ublox
