#include <chrono>
#include "TestHarness.h"
#include "../main/FaceDetector.h"


TEST(FaceDetectorTest, FaceDetector)
{
    FaceDetector face_detector;
    cv::Rect face_rect;

    auto start_time = std::chrono::steady_clock::now();
    auto elapsed_time = std::chrono::steady_clock::now() - start_time;

    bool face_detected = false;

    while (elapsed_time < std::chrono::seconds(1))
    {
        face_rect = face_detector.getFaceRect();
        if (face_rect.area() > 0)
        {
            face_detected = true;
            break;
        }

        elapsed_time = std::chrono::steady_clock::now() - start_time;
    }

    CHECK(face_detected);
}

