#include <vector>
#include <iostream>
#include "Display.h"

Display::Display(int width): width_(width)
{
    std::cout << "\x1b[2J";
}

void Display::display(const std::vector<char>& canvas_buffer) const
{
    std::cout << "\x1b[H";
    for (size_t idx{0}; idx < canvas_buffer.size(); ++idx) {
        if (idx % width_ == 0) {
            std::cout << '\n';
        } else {
            std::cout << canvas_buffer[idx];
        }
    }
}
