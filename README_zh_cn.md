# XMSDEMO 模块

\[ [English](README.md) | 简体中文 \]

## 目录

- [简介](#简介)
- [示例代码](#示例代码)

## 简介

XMSDEMO 模块提供了几个完整的处理示例，展示了如何在 openvela 中使用 XMS 进行包管理和 activity 的管理等。该模块适合初学者和开发者快速上手。

## 示例代码

本部分主要展示如何使用 openvela的 xms 模块来实现一个快应用，具体实现可参考 XMS demo 的 `launcher` 模块。

1. 定义一个 `LauncherApplication.cpp`, 核心实现如下：

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
    ```

    说明：需要添加如下两行。
    ```c++
    #define APPLICATION LauncherApplication
    #include <app/AppMain.h>
    ```


2. 需要定义一个 `HomeActivity,` 核心实现如下：

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

