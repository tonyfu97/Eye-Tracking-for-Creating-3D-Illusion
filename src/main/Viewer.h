// File: Viewer.h
// Description: Declaration of the Viewer class
// Author: Tony Fu
// Date: 2023-04-18

#pragma once

#include <array>
#include <opencv2/opencv.hpp>
#include "geometry_types.h"


// This Viewer class tries to estimate the viewer's position using the face
// location.
class Viewer
{
public:
    Viewer(float smoothing_factor);
    void updateLocation(const cv::Rect& face_location);
    const Coordinates getViewerLocation() const;

private:
    float smoothing_factor_;
    Coordinates viewer_location;
};
