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

#include "MainActivity.h"

#include <BaseWindow.h>
#include <lvgl/lvgl.h>

namespace os {
namespace app {
namespace example {

using namespace xmsdemo;

void MainActivity::onCreate() {
    ALOGI("MainActivity onCreate\n");
    lvObj root((lv_obj_t *)getWindow()->getRoot());

    mBtns.push_back(lvUtils::createLabelButton(&root, "Standard Window", {LV_ALIGN_CENTER, -100, 0},
                                               [this](lv_event_t *) {
                                                   Intent intent(getPackageName() +
                                                                 "/StandardWindow");
                                                   startActivity(intent);
                                               }));

    mBtns.push_back(lvUtils::createLabelButton(&root, "Single Window", {LV_ALIGN_CENTER, 100, 0},
                                               [this](lv_event_t *) {
                                                   Intent intent(getPackageName() +
                                                                 "/SingleWindow");
                                                   startActivity(intent);
                                               }));

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

void MainActivity::onResume() {
    ALOGI("MainActivity onResume");
}

void MainActivity::onStart() {
    ALOGI("MainActivity onStart");
}

void MainActivity::onRestart() {
    ALOGI("MainActivity onRestart");
}

void MainActivity::onPause() {
    ALOGI("MainActivity onPause");
}

void MainActivity::onStop() {
    ALOGI("MainActivity onStop");
}

void MainActivity::onDestroy() {
    ALOGI("MainActivity onDestroy");
}

} // namespace example
} // namespace app
} // namespace os
