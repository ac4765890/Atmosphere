/*
 * Copyright (c) 2018-2019 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stratosphere.hpp>
#include "ldr_ams.h"

namespace ams::ldr::pm {

    /* Information API. */
    Result CreateProcess(Handle *out, PinId pin_id, u32 flags, Handle reslimit) {
        return ldrPmCreateProcess(pin_id.value, flags, reslimit, out);
    }

    Result GetProgramInfo(ProgramInfo *out, const ncm::ProgramLocation &loc) {
        return ldrPmGetProgramInfo(reinterpret_cast<const NcmProgramLocation *>(&loc), reinterpret_cast<LoaderProgramInfo *>(out));
    }

    Result PinProgram(PinId *out, const ncm::ProgramLocation &loc) {
        static_assert(sizeof(*out) == sizeof(u64), "PinId definition!");
        return ldrPmPinProgram(reinterpret_cast<const NcmProgramLocation *>(&loc), reinterpret_cast<u64 *>(out));
    }

    Result UnpinProgram(PinId pin_id) {
        return ldrPmUnpinProgram(pin_id.value);
    }

    Result HasLaunchedProgram(bool *out, ncm::ProgramId program_id) {
        return ldrPmAtmosphereHasLaunchedProgram(out, static_cast<u64>(program_id));
    }

}
