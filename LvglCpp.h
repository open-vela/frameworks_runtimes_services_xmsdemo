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

#include <lvgl/lvgl.h>

#include <functional>
#include <memory>
#include <string>

namespace xmsdemo {

using LvglEventCB = std::function<void(lv_event_t *e)>;

struct Align {
    _lv_align_t type;
    int x;
    int y;
};

struct lvEvent {
    LvglEventCB cb;
};

class lvStyle {
public:
    lvStyle() {
        lv_style_init(&style_);
    }
    void setTextColor(int32_t coler) {
        lv_style_set_text_color(&style_, lv_color_hex(coler));
    }
    lv_style_t style_;
};

class lvObj {
public:
    lvObj(lv_obj_t *obj) {
        obj_ = obj;
    }

    void align(const Align &align) {
        lv_obj_align(obj_, align.type, align.x, align.y);
    }
    void alignCenter() {
        lv_obj_center(obj_);
    }

    void addStyle(const lvStyle &style) {
        lv_obj_add_style(obj_, &style.style_, 0);
    }

    void addEvent(lv_event_code_t filter, const lvEvent &event) {
        lv_obj_add_event(
                obj_,
                [](lv_event_t *e) {
                    auto et = (lvEvent *)lv_event_get_user_data(e);
                    et->cb(e);
                },
                filter, (void *)&event);
    }

    lv_obj_t *obj_;
};

class Label : public lvObj {
public:
    Label(const lvObj *parent) : lvObj(lv_label_create(parent->obj_)) {}

    void setText(const std::string &text) {
        lv_label_set_text(obj_, text.c_str());
    }
};

class Button : public lvObj {
public:
    Button(const lvObj *parent) : lvObj(lv_btn_create(parent->obj_)) {}

    void onClicked(const LvglEventCB &cb) {
        event_.cb = cb;
        addEvent(LV_EVENT_CLICKED, event_);
    }

    lvEvent event_;
};

class TextArea : public lvObj {
    TextArea(const lvObj *parent) : lvObj(lv_textarea_create(parent->obj_)) {}
    void setText(const std::string &text) {
        lv_textarea_set_text(obj_, text.c_str());
    }
};

using ButtonHandler = std::shared_ptr<Button>;
using TextAreaHandler = std::shared_ptr<TextArea>;

class lvUtils {
public:
    static ButtonHandler createLabelButton(const lvObj *parent, const char *name,
                                           const Align &align, const LvglEventCB &cb) {
        auto btn = std::make_shared<Button>(parent);
        btn->align(align);
        auto text = Label(btn.get());
        text.setText(name);
        text.alignCenter();
        btn->onClicked(cb);
        return btn;
    }
};

} // namespace xmsdemo
