// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_RAND_UTIL_H_
#define BASE_RAND_UTIL_H_
#pragma once

#include <string>

#include "base/base_export.h"


namespace base {

// Returns a random number in range [0, kuint64max]. Thread-safe.
BASE_EXPORT uint64 RandUint64();

// Returns a random number between min and max (inclusive). Thread-safe.
BASE_EXPORT int RandInt(int min, int max);

// Returns a random number in range [0, range).  Thread-safe.
//
// Note that this can be used as an adapter for std::random_shuffle():
// Given a pre-populated |std::vector<int> myvector|, shuffle it as
//   std::random_shuffle(myvector.begin(), myvector.end(), base::RandGenerator);
BASE_EXPORT uint64 RandGenerator(uint64 range);

// Returns a random double in range [0, 1). Thread-safe.
BASE_EXPORT double RandDouble();

// Given input |bits|, convert with maximum precision to a double in
// the range [0, 1). Thread-safe.
BASE_EXPORT double BitsToOpenEndedUnitInterval(uint64 bits);

// Fills |output_length| bytes of |output| with cryptographically strong random
// data.
BASE_EXPORT void RandBytes(void* output, size_t output_length);

// Fills a string of length |length| with with cryptographically strong random
// data and returns it.  |length| should be nonzero.
//
// Note that this is a variation of |RandBytes| with a different return type.
BASE_EXPORT std::string RandBytesAsString(size_t length);

}  // namespace base

#endif  // BASE_RAND_UTIL_H_
