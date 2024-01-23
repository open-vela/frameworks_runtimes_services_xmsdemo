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
#include <app/MessageService.h>
#include <lvgl/lvgl.h>
#include <utils/Log.h>

namespace os {
namespace app {
namespace xmsservice {

using namespace xmsdemo;

class MyReply : public ReplyReceiver {
    void receiveReply(int seqNo, const std::string &data) {
        ALOGW("onreply:%d %s", seqNo, data.c_str());
    }
};

class MyConn : public ServiceConnection {
public:
    void onConnected(const sp<IBinder> &server) {
        ALOGW("on Connected");
        mChannel =
                std::make_shared<MessageChannel>(android::interface_cast<IMessageChannel>(server));
        std::string ret = mChannel->sendMessageAndReply("Listen music");
        ALOGW("get reply:%s", ret.c_str());
        mReply = sp<MyReply>::make();
        mChannel->sendMessage("One world one dream", 2 /*seqNo*/, mReply);
    }

    void onDisconnected(const sp<IBinder> &server) {
        mChannel = nullptr;
        mReply = nullptr;
        ALOGW("on disconnected");
    }

    string sendMessage(const string &msg) {
        if (mChannel) {
            return mChannel->sendMessageAndReply(msg);
        } else {
            ALOGW("service disconnected");
            return "error:service disconnected";
        }
    }

private:
    std::shared_ptr<MessageChannel> mChannel;
    sp<MyReply> mReply;
};

MainActivity::MainActivity() {
    mConn = sp<MyConn>::make();
}

void MainActivity::onCreate() {
    ALOGI("MainActivity onCreate");

    lvObj root((lv_obj_t *)getWindow()->getRoot());

    mBtns.push_back(lvUtils::createLabelButton(&root, "startservice", {LV_ALIGN_DEFAULT, 20, 20},
                                               [this](lv_event_t *) {
                                                   Intent intent(getPackageName() +
                                                                 "/MusicService");
                                                   startService(intent);
                                               }));

    mBtns.push_back(lvUtils::createLabelButton(&root, "stopservice", {LV_ALIGN_DEFAULT, 20, 60},
                                               [this](lv_event_t *) {
                                                   Intent intent(getPackageName() +
                                                                 "/MusicService");
                                                   stopService(intent);
                                               }));

    mBtns.push_back(lvUtils::createLabelButton(&root, "bindservice", {LV_ALIGN_DEFAULT, 20, 100},
                                               [this](lv_event_t *) {
                                                   Intent intent(getPackageName() +
                                                                 "/MusicService");
                                                   bindService(intent, mConn);
                                               }));

    mBtns.push_back(lvUtils::createLabelButton(&root, "unbindservice", {LV_ALIGN_DEFAULT, 20, 140},
                                               [this](lv_event_t *) { unbindService(mConn); }));

    mBtns.push_back(lvUtils::createLabelButton(&root, "send message", {LV_ALIGN_DEFAULT, 200, 20},
                                               [this](lv_event_t *) {
                                                   static int i = 0;
                                                   mConn->sendMessage("send messge + " +
                                                                      std::to_string(++i));
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
    ALOGI("MainActivity onDestory");
}

void MainActivity::onActivityResult(const int requestCode, const int resultCode,
                                    const Intent &resultData) {
    ALOGW("requestCode:%d", requestCode);
    if (requestCode == 2) {
        ALOGW("MainActivity get result :%d,  %s\n", resultCode, resultData.mData.c_str());
    }
}

} // namespace xmsservice
} // namespace app
} // namespace os
