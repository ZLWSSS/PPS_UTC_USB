cmake_minimum_required(VERSION 3.5)
project(Communication)

set(INC_DIR /usr/local/include)
set(LINK_DIR /usr/local/lib /home/lwchong/CLionProjects/usb_camera/)

set(CMAKE_CXX_STANDARD 14)
include_directories(${INC_DIR})
link_directories(${LINK_DIR})
add_library(USBSharedLib SHARED USB_COM.cpp USB_COM.h Inter_Board_Com.h Inter_Board_Com.cpp)
add_executable(Communication main.cpp)
target_link_libraries(Communication libusb-1.0.so USBSharedLib)
