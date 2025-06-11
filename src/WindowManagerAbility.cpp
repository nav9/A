#include "WindowManagerAbility.hpp"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>

void WindowManagerAbility::run() {
    listWindows();
}

void WindowManagerAbility::listWindows() {
    Display* display = XOpenDisplay(nullptr);
    if (!display) {
        std::cerr << "Cannot open display\n";
        return;
    }

    Window root = DefaultRootWindow(display);
    Window parent;
    Window* children;
    unsigned int nchildren;

    if (XQueryTree(display, root, &root, &parent, &children, &nchildren)) {
        std::cout << "Found " << nchildren << " windows:\n";
        for (unsigned int i = 0; i < nchildren; ++i) {
            XWindowAttributes attr;
            XGetWindowAttributes(display, children[i], &attr);
            if (attr.map_state == IsViewable) {
                std::cout << "  Window ID: " << children[i] << " at ("
                          << attr.x << ", " << attr.y << ")\n";
            }
        }
    }
    XCloseDisplay(display);
}

void WindowManagerAbility::moveWindow(unsigned long windowId, int x, int y) {
    Display* display = XOpenDisplay(nullptr);
    if (!display) return;
    XMoveWindow(display, static_cast<Window>(windowId), x, y);
    XFlush(display);
    XCloseDisplay(display);
}

std::string WindowManagerAbility::getPurpose() const {
    return "List and reposition windows";
}