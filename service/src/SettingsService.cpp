/*
 * Copyright (C) 2024 Xiaomi Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "SettingsService.h"

#include <utils/Log.h>

namespace os {
namespace app {
namespace xmsservice {

void SettingsService::onCreate() {
    ALOGW("SettingsService create");
}

sp<IBinder> SettingsService::onBind(const Intent &intent) {
    ALOGW(" SettingsService onBind");
    return nullptr;
}

void SettingsService::onStartCommand(const Intent &intent) {
    ALOGW("SettingsService onStartCommand");
}

bool SettingsService::onUnbind() {
    ALOGW("SettingsService onUnbind");
    return true;
}

void SettingsService::onDestroy() {
    ALOGW("SettingsService onDestroy");
}

} // namespace xmsservice
} // namespace app
} // namespace os