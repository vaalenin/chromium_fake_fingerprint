// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// The following macros are used to declare both the color id enumerations and
// the stringized names of the enumeration elements for use in dump_colors. To
// stringize the element names, define STRINGIZE_COLOR_IDS prior to including
// this file. This file is intended to be included just before and just after
// the enumeration or string array declarations.

#if !defined(COLOR_ID_MACROS_DEFINED)
#define COLOR_ID_MACROS_DEFINED
#if defined(STRINGIZE_COLOR_IDS)
// Convert first token to string, throw away the rest.
#define D1(enum_name) #enum_name
#define D2(enum_name, enum_value) #enum_name
#else
// Declare enum with optional assigned value.
#define D1(enum_name) enum_name
#define D2(enum_name, enum_value) enum_name = enum_value
#endif  // defined(STRINGIZE_COLOR_IDS)
// Select which token in the declaration is the assigned value.
#if BUILDFLAG(USE_COLOR_PIPELINE)
// Use first and optional third token, ignore optional second.
#define E1(enum_name) D1(enum_name)
#define E2(enum_name, old_enum_name) D1(enum_name)
#define E3(enum_name, old_enum_name, enum_value) D2(enum_name, enum_value)
#define E_CPONLY(...) E(__VA_ARGS__)
#else
// Use first and mandatory second token, ignore optional third.
#define E1(enum_name) \
  static_assert(false, "New-style color compiled for !USE_COLOR_PIPELINE")
#define E2(enum_name, old_enum_name) D2(enum_name, old_enum_name)
#define E3(enum_name, old_enum_name, enum_value) D2(enum_name, old_enum_name)
// Ignore any new color id defined only for color pipeline enabled.
#define E_CPONLY(...)
#endif  // BUILDFLAG(USE_COLOR_PIPELINE)
#define GET_E(_1, _2, _3, macro_name, ...) macro_name
#define E(...) GET_E(__VA_ARGS__, E3, E2, E1)(__VA_ARGS__),
#else
#undef D1
#undef D2
#undef E1
#undef E2
#undef E3
#undef E_CPONLY
#undef GET_E
#undef E
#undef COLOR_ID_MACROS_DEFINED
#endif
