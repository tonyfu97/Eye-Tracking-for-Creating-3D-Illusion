// File: Cube.h
// Description: Declaration of the Cube class
// Author: Tony Fu
// Date: 2023-04-18

#pragma once

#include <array>
#include <vector>
#include "Face.h"
#include "geometry_types.h"

// The Cube class manages 6 Faces and two buffers: (1) a "canvas buffer" that
// is actually plotted, and (2) a "depth buffer" that resolves conflict when
// two or more Faces are plotted on the same pixel.
class Cube
{
public:
    Cube(int canvas_height, int canvas_width);
    Cube(int canvas_height, int canvas_width, const std::array<char, 6>& textures);

    void draw(const Rotations& r, float size);
    const std::vector<char>& get_canvas() const;

private:
    int canvas_height_, canvas_width_;
    std::array<char, 6> textures_;
    static const std::array<Rotations, 6> init_rotations;
    std::array<Face, 6> faces;
    std::vector<char> canvas_buffer;
    std::vector<float> depth_buffer;
};
