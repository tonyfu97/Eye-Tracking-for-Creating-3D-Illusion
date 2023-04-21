// File: FaceDetector.h
// Description: Declaration of the FaceDetector class
// Author: Tony Fu
// Date: 2023-04-18

#pragma once

#include <array>
#include <opencv2/opencv.hpp>
#include "geometry_types.h"

class FaceDetector
{
public:
    FaceDetector();
    ~FaceDetector();
    cv::Rect getFaceRect();

private:
    void processFrame(cv::Mat& frame);
    void updateFaceLocation(const std::vector<cv::Rect>& faces);

    cv::VideoCapture cap_;
    cv::dnn::Net net_;
    cv::Rect face_rect_;
};
