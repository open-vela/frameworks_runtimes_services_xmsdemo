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

#include <app/Activity.h>

#include "LvglCpp.h"

namespace os {
namespace app {
namespace example {

class MainActivity : public Activity {
public:
    void onCreate() override;
    void onStart() override;
    void onResume() override;
    void onPause() override;
    void onStop() override;
    void onDestroy() override;
    void onRestart() override;

private:
    std::vector<xmsdemo::ButtonHandler> mBtns;
    lv_obj_t *mLabel;
    lv_style_t style_title;
    lv_style_t style2;
};

} // namespace example
} // namespace app
} // namespace os