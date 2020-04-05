// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/core/frame/navigator_concurrent_hardware.h"

#include "base/system/sys_info.h"

#include "fakefingerprint/FakeFingerprint.h"

namespace blink {

unsigned NavigatorConcurrentHardware::hardwareConcurrency() const {
    const auto& ff = FakeFingerprint::Instance();
    if (ff)
        return ff.GetConcurrency();

  return static_cast<unsigned>(base::SysInfo::NumberOfProcessors());
}

}  // namespace blink
