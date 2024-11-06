# Vela XMSDEMO 模块


## 目录

- [简介](#简介)
- [示例代码](#示例代码)

## 简介

XMSDEMO 模块提供了几个完整的处理示例，展示了如何在 Vela 中使用 XMS 进行包管理和activity的管理等。该模块适合初学者和开发者快速上手。

## 示例代码

本部分主要展示如何使用Vela的ams模块来实现一个快应用，具体的实现可参考XMS demo的launcher模块。

1. 定义一个LauncherApplication.cpp, 核心实现如下

```c++
class LauncherApplication : public Application {
    void onCreate() override {
        REGISTER_ACTIVITY(HomeActivity)
    }

    void onForeground() override {}
    void onBackground() override {}
    void onDestroy() override {}
};

#define APPLICATION LauncherApplication
#include <app/AppMain.h>
````

**要加上
#define APPLICATION LauncherApplication
#include <app/AppMain.h>
这两行代码**

2. 需要定义一个HomeActivity, 核心实现如下

```c++
class HomeActivity : public Activity {
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
    std::shared_ptr<Dialog> mDialog;
};
```

