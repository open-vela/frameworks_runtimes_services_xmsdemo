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
    lvObj root((lv_obj_t*)getWindow()->getRoot());

    uint32_t widthSize = 0;
    uint32_t heightSize = 0;
    getWindowManager()->getDisplayInfo(&widthSize, &heightSize);

    const int line = 6;
    const int column = 5;
    const int minWidth = 120;
    const int minHeight = 50;
    const int offset = 10;
    const int double_offset = 2 * offset;

    int height = heightSize / (line + 2);
    int width = widthSize / column;
    if (height < minHeight) height = minHeight;
    if (width < minWidth) width = minWidth;

    if (pm.getAllPackageInfo(&allPackageInfo) == 0) {
        int x_index = 0;
        int y_index = 0;
        for (auto app : allPackageInfo) {
            if (app.packageName == getPackageName() || app.entry == "") {
                continue;
            }
            const int pos_x = double_offset + x_index * width;
            const int pos_y = double_offset + y_index * height;
            const string packagename = app.packageName;
            mBtns.push_back(lvUtils::createLabelButton(&root, app.name.c_str(),
                                                       {LV_ALIGN_DEFAULT, pos_x, pos_y},
                                                       [this, packagename](lv_event_t*) {
                                                           Intent intent(packagename);
                                                           startActivity(intent);
                                                       }));
            if (++y_index >= line) {
                x_index++;
                y_index = 0;
            }
        }
    }
    {
        // create package dialog
        mDialog = Dialog::createDialog(this);
        auto layout = mDialog->getLayout();
        layout.mX = widthSize - width - double_offset;
        layout.mY = double_offset;
        const int validcnt = allPackageInfo.size() > 6 ? 6 : allPackageInfo.size();
        layout.mHeight = validcnt * height + double_offset;
        layout.mWidth = widthSize - layout.mX;
        mDialog->setLayout(layout);

        lvObj dialogRoot((lv_obj_t*)mDialog->getRoot());
        // dialog package list
        int y_index = 1;
        for (auto app : allPackageInfo) {
            if (app.packageName == getPackageName() || app.entry == "") {
                continue;
            }
            const int pos_x = offset;
            const int pos_y = offset + y_index * height;
            const string packagename = app.packageName;
            mBtns.push_back(lvUtils::createLabelButton(&dialogRoot, app.name.c_str(),
                                                       {LV_ALIGN_DEFAULT, pos_x, pos_y},
                                                       [this, packagename](lv_event_t*) {
                                                           Intent intent(packagename);
                                                           startActivity(intent);
                                                       }));
            if (++y_index > line) {
                break;
            }
        }

        mBtns.push_back(lvUtils::createLabelButton(&dialogRoot, "<< hide",
                                                   {LV_ALIGN_DEFAULT, offset, offset},
                                                   [this](lv_event_t*) { mDialog->hide(); }));
        mDialog->hide();
    }

    mBtns.push_back(
            lvUtils::createLabelButton(&root, "back",
                                       {LV_ALIGN_BOTTOM_LEFT, double_offset, -double_offset},
                                       [this](lv_event_t*) { finish(); }));

    mBtns.push_back(lvUtils::createLabelButton(&root, "home",
                                               {LV_ALIGN_BOTTOM_MID, 0, -double_offset},
                                               [this](lv_event_t*) {
                                                   Intent intent;
                                                   intent.setAction(Intent::ACTION_HOME);
                                                   startActivity(intent);
                                               }));

    mBtns.push_back(
            lvUtils::createLabelButton(&root, "hide",
                                       {LV_ALIGN_BOTTOM_RIGHT, -double_offset, -double_offset},
                                       [this](lv_event_t*) { moveToBackground(); }));
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
    if (mDialog) {
        mDialog = nullptr;
    }
}

} // namespace launcher
} // namespace app
} // namespace os
