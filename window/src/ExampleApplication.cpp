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

#include <app/ApplicationThread.h>

#include "MainActivity.h"
#include "SingleWindow.h"
#include "StandardWindow.h"

namespace os {
namespace app {
namespace example {

class ExampleApplication : public Application {
    void onCreate() override {
        REGISTER_ACTIVITY(MainActivity)
        REGISTER_ACTIVITY(StandardWindow)
        REGISTER_ACTIVITY(SingleWindow)
    }

    void onForeground() override {}
    void onBackground() override {}
    void onDestroy() override {}
};

#define APPLICATION ExampleApplication
#include <app/AppMain.h>

} // namespace example
} // namespace app
} // namespace os