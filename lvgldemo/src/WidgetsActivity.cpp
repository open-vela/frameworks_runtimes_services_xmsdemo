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

#include "WidgetsActivity.h"

#include <BaseWindow.h>
#include <lvgl/demos/lv_demos.h>
#include <lvgl/lvgl.h>

namespace os {
namespace app {
namespace lvgldemo {

using namespace xmsdemo;

void WidgetsActivity::onCreate() {
    ALOGI("WidgetsActivity onCreate");
    lvObj root((lv_obj_t *)getWindow()->getRoot());

    // lvgl demo widgets
    lv_demo_widgets();

    mBtns.push_back(lvUtils::createLabelButton(&root, "back", {LV_ALIGN_BOTTOM_LEFT, 20, -20},
                                               [this](lv_event_t *) { finish(); }));

    mBtns.push_back(lvUtils::createLabelButton(&root, "home", {LV_ALIGN_BOTTOM_MID, 0, -20},
                                               [this](lv_event_t *) {
                                                   Intent intent;
                                                   intent.setAction(Intent::ACTION_HOME);
                                                   startActivity(intent);
                                               }));

    mBtns.push_back(lvUtils::createLabelButton(&root, "hide", {LV_ALIGN_BOTTOM_RIGHT, -20, -20},
                                               [this](lv_event_t *) { moveToBackground(); }));
}

void WidgetsActivity::onResume() {
    ALOGI("WidgetsActivity onResume");
}

void WidgetsActivity::onStart() {
    ALOGI("WidgetsActivity onStart");
}

void WidgetsActivity::onRestart() {
    ALOGI("WidgetsActivity onRestart");
}

void WidgetsActivity::onPause() {
    ALOGI("WidgetsActivity onPause");
}

void WidgetsActivity::onStop() {
    ALOGI("WidgetsActivity onStop");
}

void WidgetsActivity::onDestroy() {
    ALOGI("WidgetsActivity onDestroy");
}

} // namespace lvgldemo
} // namespace app
} // namespace os
