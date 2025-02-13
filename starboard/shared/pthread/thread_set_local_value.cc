// Copyright 2015 The Cobalt Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#if SB_API_VERSION < 16

#include "starboard/thread.h"

#include <pthread.h>

#include "starboard/shared/pthread/thread_local_key_internal.h"

bool SbThreadSetLocalValue(SbThreadLocalKey key, void* value) {
  if (!SbThreadIsValidLocalKey(key)) {
    return false;
  }

  if (IsSuccess(pthread_setspecific(key->key, value))) {
    return true;
  }

  return false;
}

#endif  // SB_API_VERSION < 16
