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

#include "HomeActivity.h"

#include <BaseWindow.h>
#include <lvgl/lvgl.h>
#include <pm/PackageManager.h>

namespace os {
namespace app {
namespace launcher {

using namespace xmsdemo;

void HomeActivity::onCreate() {
    ALOGI("HomeActivity onCreate");
    os::pm::PackageManager pm;
    std::vector<os::pm::PackageInfo> allPackageInfo;
    lvObj root((lv_obj_t *)getWindow()->getRoot());

    if (pm.getAllPackageInfo(&allPackageInfo) == 0) {
        const int start_x = 20;
        const int start_y = 20;
        const int height = 50;
        const int width = 120;
        int x_index = 0;
        int y_index = 0;
        for (auto app : allPackageInfo) {
            if (app.packageName == getPackageName() || app.entry == "") {
                continue;
            }
            const int pos_x = start_x + x_index * width;
            const int pos_y = start_y + y_index * height;
            const string packagename = app.packageName;
            mBtns.push_back(lvUtils::createLabelButton(&root, app.name.c_str(),
                                                       {LV_ALIGN_DEFAULT, pos_x, pos_y},
                                                       [this, packagename](lv_event_t *) {
                                                           Intent intent(packagename);
                                                           startActivity(intent);
                                                       }));
            if (++y_index > 5) {
                x_index++;
                y_index = 0;
            }
        }
    }
    {
        // create package dialog
        uint32_t widthSize = 0;
        uint32_t heightSize = 0;
        getWindowManager()->getDisplayInfo(&widthSize, &heightSize);
        mDialog = Dialog::createDialog(this);
        auto layout = mDialog->getLayout();
        layout.mX = widthSize - 120;
        layout.mY = 20;
        const int validcnt = allPackageInfo.size() > 6 ? 6 : allPackageInfo.size();
        layout.mHeight = validcnt * 40 + 10;
        layout.mWidth = 120;
        mDialog->setLayout(layout);

        lvObj dialogRoot((lv_obj_t *)mDialog->getRoot());
        // dialog package list
        const int start_x = 0;
        const int start_y = 10;
        const int height = 40;
        const int width = 110;
        int x_index = 0;
        int y_index = 1;
        for (auto app : allPackageInfo) {
            if (app.packageName == getPackageName() || app.entry == "") {
                continue;
            }
            const int pos_x = start_x + x_index * width;
            const int pos_y = start_y + y_index * height;
            const string packagename = app.packageName;
            mBtns.push_back(lvUtils::createLabelButton(&dialogRoot, app.name.c_str(),
                                                       {LV_ALIGN_DEFAULT, pos_x, pos_y},
                                                       [this, packagename](lv_event_t *) {
                                                           Intent intent(packagename);
                                                           startActivity(intent);
                                                       }));
            if (++y_index > 6) {
                break;
            }
        }

        mBtns.push_back(lvUtils::createLabelButton(&dialogRoot, "<< hide",
                                                   {LV_ALIGN_DEFAULT, 0, 0},
                                                   [this](lv_event_t *) { mDialog->hide(); }));
        mDialog->hide();
    }

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

void HomeActivity::onStart() {
    ALOGI("HomeActivity onStart");
}

void HomeActivity::onResume() {
    ALOGI("HomeActivity onResume");
    if (mDialog) {
        mDialog->hide();
    }
}

void HomeActivity::onRestart() {
    ALOGI("HomeActivity onRestart");
}

void HomeActivity::onPause() {
    ALOGI("HomeActivity onPause");
}

void HomeActivity::onStop() {
    ALOGI("HomeActivity onStop");
    if (mDialog) {
        mDialog->show();
    }
}

void HomeActivity::onDestroy() {
    ALOGI("HomeActivity onDestroy");
}

} // namespace launcher
} // namespace app
} // namespace os
