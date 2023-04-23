#include <cmath>
#include "Viewer.h"
#include "geometry_types.h"

// Rotation sensitivity: Larger sensitivity = cube more sensitive to head movement.
const float UP_DOWN_SENSITIVITY = 1 / 1200.0f;
const float LEFT_RIGHT_SENSITIVITY = 1 / 6400.0f;
// Size sensitivity: larger value = cube change size more dramatically
const float FORWARD_BACKWARD_SENSITIVITY = 1 / 5.0f;

Viewer::Viewer(float smoothing_factor)
    : smoothing_factor_(smoothing_factor), viewer_location{ 0.0f, 0.0f, 0.0f } {}

void Viewer::updateLocation(const cv::Rect& face_location)
{
    float x_center = face_location.x + face_location.width / 2.0f;
    float y_center = face_location.y + face_location.height / 2.0f;
    float rect_size = face_location.width;
    float z_estimate = rect_size / 10.0f;

    viewer_location.x = viewer_location.x * smoothing_factor_
                        + x_center * (1 - smoothing_factor_);
    viewer_location.y = viewer_location.y * smoothing_factor_
                        + y_center * (1 - smoothing_factor_);
    viewer_location.z = viewer_location.z * smoothing_factor_
                        + z_estimate * (1 - smoothing_factor_);
}

Rotations Viewer::getRotation() const
{
    Rotations r;
    r.A = (viewer_location.y * UP_DOWN_SENSITIVITY) * M_PI;
    r.B = (viewer_location.x * LEFT_RIGHT_SENSITIVITY) * M_PI;
    return r;
}

float Viewer::getSize() const
{
    return viewer_location.z * FORWARD_BACKWARD_SENSITIVITY;
}

const Coordinates Viewer::getViewerLocation() const
{
    return viewer_location;
}
