// File: Display.h
// Description: Declaration of the Display class
// Author: Tony Fu
// Date: 2023-04-18

#pragma once

#include <vector>

// The Display class is responsible for outputting the canvas onto screen.
// Currently, the display is the terminal.
class Display
{
public:
    Display(int height, int width);
    void display(const std::vector<char>& canvas_buffer);

private:
    int height_, width_;
};
