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

#include "MusicService.h"

#include <utils/Log.h>

namespace os {
namespace app {
namespace xmsservice {

void MusicService::onCreate() {
    ALOGW("MusicService create");
}

void MusicService::onBindExt(const Intent &intent) {
    ALOGW("MusicService onBind");
}

void MusicService::onStartCommand(const Intent &intent) {
    ALOGW("MusicService onStartCommand");
}

bool MusicService::onUnbind() {
    ALOGW("MusicService onUnbind");
    return true;
}

void MusicService::onDestroy() {
    ALOGW("MusicService onDestroy");
}

std::string MusicService::receiveMessageAndReply(const string &request) {
    ALOGW("receiveMessageAndReply: %s", request.c_str());
    return "reply" + request;
}

void MusicService::receiveMessage(const std::string &request,
                                  const std::shared_ptr<ReplySender> &reply) {
    ALOGW("receiveMessage: %s", request.c_str());
    reply->reply("nihao:" + request);
}

} // namespace xmsservice
} // namespace app
} // namespace os
