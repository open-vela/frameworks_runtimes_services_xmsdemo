# XMSDEMO Module

\[ English | [简体中文](README_zh_cn.md) \]

## Table of Contents

- [Introduction](#introduction)
- [Sample Code](#sample-code)

## Introduction

The XMSDEMO module provides several complete processing examples, showing how to use XMS in openvela for package management and activity management. This module is suitable for beginners and developers to get started quickly.

## Sample Code

This section mainly demonstrates how to use openvela's AMS module to implement a quick application, with specific implementations available in the XMS demo's launcher module.

1. define a `LauncherApplication.cpp`, with the core implementation as follows:

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

    Note: You need to add the following two lines.
    ```c++
    #define APPLICATION LauncherApplication
    #include <app/AppMain.h>
    ```

2. define a `HomeActivity`, with the core implementation as follows:

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
