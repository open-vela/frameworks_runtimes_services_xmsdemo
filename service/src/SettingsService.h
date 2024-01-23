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
#pragma once

#include <app/Service.h>
namespace os {
namespace app {
namespace xmsservice {

class SettingsService : public Service {
public:
    void onCreate();
    void onStartCommand(const Intent &intent);
    void onDestroy();
    sp<IBinder> onBind(const Intent &intent);
    bool onUnbind();
};

} // namespace xmsservice
} // namespace app
} // namespace os