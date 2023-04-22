// File: main.cpp
// Description: Detect face location, and rotate/scale a cube based on viewing position.
// Author: Tony Fu
// Date: 2023-04-18

#include <iostream>
#include <unistd.h>
#include "Cube.h"
#include "Face.h"
#include "Display.h"
#include "FaceDetector.h"
#include "Viewer.h"
#include "geometry_types.h"

const int CANVAS_HEIGHT = 50;
const int CANVAS_WIDTH = 200;
const float VIEWER_SMOOTHING_FACTOR = 0.1;

int main() {
    FaceDetector fd;
    Viewer viewer(VIEWER_SMOOTHING_FACTOR);
    Display display(CANVAS_HEIGHT, CANVAS_WIDTH);
    Cube cube(CANVAS_HEIGHT, CANVAS_WIDTH);

    cv::Rect face_location;
    Rotations cube_rotations;
    float cube_size;

    while (true) {
        face_location = fd.getFaceRect();
        viewer.updateLocation(face_location);
        cube_rotations = viewer.getRotation();
        cube_size = viewer.getSize();

        cube.draw(cube_rotations, cube_size);
        display.display(cube.get_canvas());

        int key = cv::waitKey(100);
        if (key == 'q' || key == 'Q') {
            break;
        }
        usleep(8000);
    }
    return 0;
}
