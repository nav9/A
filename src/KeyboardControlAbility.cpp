#include "KeyboardControlAbility.hpp"
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <iostream>

void KeyboardControlAbility::run() {
    simulateKeyPress(XKeysymToKeycode(XOpenDisplay(nullptr), XStringToKeysym("A")));
}

void KeyboardControlAbility::simulateKeyPress(int keycode) {
    Display* display = XOpenDisplay(nullptr);
    if (!display) {
        std::cerr << "Cannot open display\n";
        return;
    }

    XTestFakeKeyEvent(display, keycode, True, 0);
    XTestFakeKeyEvent(display, keycode, False, 0);
    XFlush(display);
    XCloseDisplay(display);
}

std::string KeyboardControlAbility::getPurpose() const {
    return "Simulate keypresses on the system";
}