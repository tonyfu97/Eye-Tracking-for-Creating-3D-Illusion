#include "Viewer.h"
#include "geometry_types.h"

Viewer::Viewer(float smoothing_factor): smoothing_factor_(smoothing_factor)
{
    viewer_location.x = 0;
    viewer_location.y = 0;
    viewer_location.z = 0;
};

void Viewer::updateLocation(const cv::Rect& face_location)
{
    float x_center = face_location.x + face_location.width / 2.0f;
    float y_center = face_location.y + face_location.height / 2.0f;
    float rect_size = face_location.width;
    float z_estimate = rect_size / 10;

    viewer_location.x = viewer_location.x * smoothing_factor_
                        + x_center * (1 - smoothing_factor_);
    viewer_location.y = viewer_location.y * smoothing_factor_
                        + y_center * (1 - smoothing_factor_);
    viewer_location.z = viewer_location.z * smoothing_factor_
                        + z_estimate * (1 - smoothing_factor_);
}

const Coordinates Viewer::getViewerLocation() const
{
    return viewer_location;
}
