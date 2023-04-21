// File: Face.h
// Description: Declaration of the Face class
// Author: Tony Fu
// Date: 2023-04-18

#pragma once

#include <array>
#include <vector>
#include "geometry_types.h"

// Each instance of the Face class is responsible for one face of the Cube.
// (Not to be confused with the user's face that is detected by the FaceDetector.)
// It is responsible for all the linear algebra needed for rotation and scaling.
// The idea comes from: https://github.com/servetgulnaroglu/cube.c
class Face {
public:
    Face(const Rotations& init_rotation, char texture, int canvas_height, int canvas_width);
    
    void draw(std::vector<char>& canvas_buffer,
              std::vector<float>& depth_buffer,
              const Rotations& r,
              float size);

private:
    Rotations r0;
    char texture_;
    int canvas_height_, canvas_width_;
    
    Coordinates rotate3d(const Coordinates& p, const Rotations& r);
    Coordinates prospectiveProjection(const Coordinates& p);
};
