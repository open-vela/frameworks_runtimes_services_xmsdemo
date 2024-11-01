# Vela XMSDEMO Module

XMSDEMO is a Vela example module that demonstrates how to use XMS for package management and application management. This module includes sample code, documentation, and use cases, making it suitable for developers to learn from and reference.

## Table of Contents

- [Introduction](#introduction)
- [Sample Code](#sample-code)
- [Contributions](#contributions)
- [License](#license)
- [Contact](#contact)

## Introduction

The XMSDEMO module provides several complete handling examples that illustrate how to use XMS in Vela for package management and activity management, among others. This module is ideal for beginners and developers to get started quickly.

## Sample Code

This section mainly demonstrates how to use Vela's AMS module to implement a quick application, with specific implementations available in the XMS demo's launcher module.

First, define a `LauncherApplication.cpp`, with the core implementation as follows:

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

**It is essential to include the following two lines of code:**
```c++
#define APPLICATION LauncherApplication
#include <app/AppMain.h>
```

Next, we need to define a `HomeActivity`, with the core implementation as follows:

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

## Contributions

## License

## Contact