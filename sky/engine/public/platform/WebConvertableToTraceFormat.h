// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SKY_ENGINE_PUBLIC_PLATFORM_WEBCONVERTABLETOTRACEFORMAT_H_
#define SKY_ENGINE_PUBLIC_PLATFORM_WEBCONVERTABLETOTRACEFORMAT_H_

#include "sky/engine/public/platform/WebPrivatePtr.h"
#include "sky/engine/public/platform/WebString.h"

namespace blink {

namespace TraceEvent {
class ConvertableToTraceFormat;
}

class WebConvertableToTraceFormat {
public:
    WebConvertableToTraceFormat() { }
#if INSIDE_BLINK
    WebConvertableToTraceFormat(TraceEvent::ConvertableToTraceFormat*);
#endif
    ~WebConvertableToTraceFormat() { reset(); }

    BLINK_PLATFORM_EXPORT WebString asTraceFormat() const;
    BLINK_PLATFORM_EXPORT void assign(const WebConvertableToTraceFormat&);
    BLINK_PLATFORM_EXPORT void reset();

    WebConvertableToTraceFormat(const WebConvertableToTraceFormat& r) { assign(r); }
    WebConvertableToTraceFormat& operator=(const WebConvertableToTraceFormat& r)
    {
        assign(r);
        return *this;
    }

private:
    WebPrivatePtr<TraceEvent::ConvertableToTraceFormat> m_private;
};

} // namespace blink

#endif  // SKY_ENGINE_PUBLIC_PLATFORM_WEBCONVERTABLETOTRACEFORMAT_H_
