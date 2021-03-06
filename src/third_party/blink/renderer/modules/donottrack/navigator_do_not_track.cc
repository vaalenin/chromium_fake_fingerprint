/*
 * Copyright (C) 2013 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "third_party/blink/renderer/modules/donottrack/navigator_do_not_track.h"

#include "third_party/blink/renderer/core/frame/local_frame.h"
#include "third_party/blink/renderer/core/frame/local_frame_client.h"
#include "third_party/blink/renderer/core/frame/navigator.h"

#include "fakefingerprint/FakeFingerprint.h"

namespace blink {

NavigatorDoNotTrack::NavigatorDoNotTrack(Navigator& navigator)
    : Supplement<Navigator>(navigator) {}

void NavigatorDoNotTrack::Trace(Visitor* visitor) {
  Supplement<Navigator>::Trace(visitor);
}

const char NavigatorDoNotTrack::kSupplementName[] = "NavigatorDoNotTrack";

NavigatorDoNotTrack& NavigatorDoNotTrack::From(Navigator& navigator) {
  NavigatorDoNotTrack* supplement =
      Supplement<Navigator>::From<NavigatorDoNotTrack>(navigator);
  if (!supplement) {
    supplement = MakeGarbageCollected<NavigatorDoNotTrack>(navigator);
    ProvideTo(navigator, supplement);
  }
  return *supplement;
}

String NavigatorDoNotTrack::doNotTrack(Navigator& navigator) {
  return NavigatorDoNotTrack::From(navigator).doNotTrack();
}

String NavigatorDoNotTrack::doNotTrack() {
    const auto& ff = FakeFingerprint::Instance();
    if (ff)
        return ff.GetDoNotTrack().c_str();

  LocalFrame* frame = GetSupplementable()->GetFrame();
  if (!frame || !frame->Client())
    return String();
  return frame->Client()->DoNotTrackValue();
}

}  // namespace blink
