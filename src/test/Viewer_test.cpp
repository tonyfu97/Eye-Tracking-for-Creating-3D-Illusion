#include <cmath>
#include "TestHarness.h"
#include "../main/Viewer.h"

TEST(ViewerTest, updateLocation)
{
    float smoothing_factor = 1;
    Viewer viewer(smoothing_factor);
    cv::Rect face_location(30, 40, 100, 100);

    viewer.updateLocation(face_location);
    Coordinates actual_location = viewer.getViewerLocation();

    CHECK_DOUBLES_EQUAL(0, actual_location.x, 1e-6);
    CHECK_DOUBLES_EQUAL(0, actual_location.y, 1e-6);
    CHECK_DOUBLES_EQUAL(0, actual_location.z, 1e-6);
}

TEST(ViewerTest, getSize)
{
    float smoothing_factor = 0.5;
    Viewer viewer(smoothing_factor);
    cv::Rect face_location(30, 40, 100, 100);
    
    viewer.updateLocation(face_location);
    float actual_size = viewer.getSize();
    
    CHECK_DOUBLES_EQUAL(1.0, actual_size, 1e-6);
}
