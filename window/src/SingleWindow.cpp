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

#include "SingleWindow.h"

#include <BaseWindow.h>
#include <lvgl/lvgl.h>

namespace os {
namespace app {
namespace example {

using namespace xmsdemo;

static int gSingleWindow = 0;

void SingleWindow::onCreate() {
    ALOGI("SingleWindow onCreate");
    lvObj root((lv_obj_t *)getWindow()->getRoot());

    lv_style_init(&style_title);
    lv_style_set_text_color(&style_title, lv_color_hex(0xff0000));
    lv_style_init(&style2);
    lv_style_set_text_color(&style2, lv_color_hex(0xff));

    mStartLabel = lv_label_create(root.obj_);
    lv_obj_align(mStartLabel, LV_ALIGN_DEFAULT, 50, 50);
    lv_obj_add_style(mStartLabel, &style_title, 0);

    mLabel = lv_label_create(root.obj_);
    lv_obj_align(mLabel, LV_ALIGN_DEFAULT, 50, 80);
    lv_label_set_text(mLabel, "click the reflush button to reflush current window");
    lv_obj_add_style(mLabel, &style2, 0);

    gSingleWindow++;
    mStartCnt = 0;
    mClickCnt = 0;

    mBtns.push_back(lvUtils::createLabelButton(&root, "Reflush Window", {LV_ALIGN_DEFAULT, 50, 120},
                                               [this](lv_event_t *) {
                                                   mClickCnt++;
                                                   std::string text = "you reflush window " +
                                                           std::to_string(mClickCnt) + " times";
                                                   lv_label_set_text(mLabel, text.c_str());
                                               }));

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

void SingleWindow::onRestart() {
    ALOGI("SingleWindow onRestart");
}

void SingleWindow::onStart() {
    ALOGI("SingleWindow onStart");
    char buf[256];
    sprintf(buf, "I am a SingleWindow, onStart cnt:%d. all SingleWindow cnt:%d", ++mStartCnt,
            gSingleWindow);
    lv_label_set_text(mStartLabel, buf);
}

void SingleWindow::onResume() {
    ALOGI("SingleWindow onResume");
}

void SingleWindow::onPause() {
    ALOGI("SingleWindow onPause");
}

void SingleWindow::onStop() {
    ALOGI("SingleWindow onStop");
}

void SingleWindow::onDestroy() {
    ALOGI("SingleWindow onDestroy");
    lv_style_reset(&style_title);
    lv_style_reset(&style2);
    gSingleWindow--;
}

} // namespace example
} // namespace app
} // namespace os
