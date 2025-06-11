#include "MouseControlAbility.hpp"
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <iostream>

void MouseControlAbility::run() {
    moveMouse(100, 100);
}

void MouseControlAbility::moveMouse(int x, int y) {
    Display* display = XOpenDisplay(nullptr);
    if (!display) {
        std::cerr << "Cannot open display\n";
        return;
    }

    XTestFakeMotionEvent(display, -1, x, y, CurrentTime);
    XFlush(display);
    XCloseDisplay(display);
}

std::string MouseControlAbility::getPurpose() const {
    return "Simulate and move mouse pointer";
}