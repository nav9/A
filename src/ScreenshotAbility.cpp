#include "ScreenshotAbility.hpp"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>

void ScreenshotAbility::run() {
    Display* display = XOpenDisplay(nullptr);
    if (!display) {
        std::cerr << "Cannot open display\n";
        return;
    }

    Window root = DefaultRootWindow(display);
    XWindowAttributes gwa;
    XGetWindowAttributes(display, root, &gwa);

    int width = gwa.width;
    int height = gwa.height;

    XImage* image = XGetImage(display, root, 0, 0, width, height, AllPlanes, ZPixmap);
    if (!image) {
        std::cerr << "Failed to get image\n";
        XCloseDisplay(display);
        return;
    }

    lastScreenshot.clear();
    lastScreenshot.reserve(width * height * 4);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned long pixel = XGetPixel(image, x, y);
            lastScreenshot.push_back((pixel & 0xff0000) >> 16); // Red
            lastScreenshot.push_back((pixel & 0x00ff00) >> 8);  // Green
            lastScreenshot.push_back((pixel & 0x0000ff));       // Blue
            lastScreenshot.push_back(255);                      // Alpha
        }
    }

    std::cout << "Screenshot taken: " << width << "x" << height << "\n";
    XDestroyImage(image);
    XCloseDisplay(display);
}

std::string ScreenshotAbility::getPurpose() const {
    return "Take screen captures and store in memory";
}