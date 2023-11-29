## 项目概述

本项目开发环境基于Qt6，利用Clion IDE进行开发，使用CMake进行构建。本项目利用Qt多线程
实现了同时画圆画方的功能，利用Qt的信号与槽机制实现了线程间的通信。

## 项目结构

```angular2html

├── CMakeLists.txt // cmake构建文件
├── README.md      // 项目说明
├── cmake-build-debug // cmake构建目录
│   ├── mission3.exe        // 可执行文件
│   ├── Qt6Core.dll         // Qt6运行库
│   ├── Qt6Gui.dll          // Qt6运行库
│   ├── Qt6Widgets.dll      // Qt6运行库
│   ├── cmake_install.cmake // cmake安装文件
│   ├── build.ninja         // ninja构建文件
│   ├── .ninja_deps         // ninja依赖
│   ├── .ninja_log          // ninja日志
│   ├── ...
├── main.cpp           // 主函数
├── mainwindow.cpp     // 主窗口
├── mainwindow.h       // 主窗口头文件
├── mainwindow.ui      // 主窗口ui文件
├── ui_mainwindow.h    // 主窗口ui头文件
├── CircleThread.cpp   // 画圆线程
├── CircleThread.h     // 画圆线程头文件
├── SquareThread.cpp   // 画方线程
├── SquareThread.h     // 画方线程头文件
```

## 运行效果

![程序运行效果图](https://raw.githubusercontent.com/hustlixiang21/blog-image/main/双线程画圆方.gif)
