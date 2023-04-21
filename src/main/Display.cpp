#include <vector>
#include <iostream>
#include "Display.h"

Display::Display(int height, int width)
    : height_(height), width_(width) {}

void Display::display(std::vector<char>& canvas_buffer)
{
    std::cout << "\x1b[H";
    for (int idx{0}; idx < canvas_buffer.size(); ++idx) {
        if (idx % width_ == 0) {
            std::cout << '\n';
        } else {
            std::cout << canvas_buffer[idx];
        }
    }
}
