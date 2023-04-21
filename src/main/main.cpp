#include "Cube.h"
#include "Face.h"
#include "Display.h"
#include "FaceDetector.h"
#include "Viewer.h"
#include "Controller.h"

int main() {
    // // Initialize classes
    // EyeDetector eyeDetector;
    // Viewer viewer;
    // Controller controller(viewer);
    // Display display;
    // Cube cube;

    // // Main loop
    // while (true) {
    //     // Update eye position using EyeDetector
    //     eyeDetector.update();

    //     // Update viewer's angle and distance based on eye position
    //     viewer.update(eyeDetector.getEyePosition());

    //     // Update the cube's position and rotation based on the viewer
    //     cube.update(viewer.getViewingAngle(), viewer.getViewingDistance());

    //     // Render the cube using the Display class
    //     display.render(cube.getAsciiRepresentation());

    //     // Process user input (e.g., keyboard input)
    //     controller.processInput();
    // }

    return 0;
}
