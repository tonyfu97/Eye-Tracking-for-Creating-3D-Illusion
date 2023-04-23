#include <string>
#include <opencv2/opencv.hpp>
#include "FaceDetector.h"
#include "geometry_types.h"

// change the following based on your system.
const int CAMERA_NUMBER = 1;
const std::string REPO_DIR = "/Users/tonyfu/Desktop/OnlineCourses/C++Certificate/Eye-Tracking-for-Creating-3D-Illusion/";

FaceDetector::FaceDetector()
    : cap_(CAMERA_NUMBER)
{
    net_ = cv::dnn::readNetFromCaffe(REPO_DIR + "models/deploy.prototxt",
                                     REPO_DIR + "models/res10_300x300_ssd_iter_140000.caffemodel");

    // Check if the camera was opened successfully
    if (!cap_.isOpened())
    {
        throw std::runtime_error("Failed to open camera");
    }
}

FaceDetector::~FaceDetector()
{
    cap_.release();
    cv::destroyAllWindows();
}

cv::Rect FaceDetector::getFaceRect()
{
    cv::Mat frame;
    cap_.read(frame);
    processFrame(frame);
    return face_rect_;
}

void FaceDetector::processFrame(cv::Mat& frame)
{
    cv::Mat blob = cv::dnn::blobFromImage(frame, 1.0, cv::Size(300, 300), cv::Scalar(104.0, 177.0, 123.0));
    net_.setInput(blob);
    cv::Mat detections = net_.forward();

    int num_detections = detections.size[2];

    std::vector<cv::Rect> face_rects;

    for (int i = 0; i < num_detections; ++i)
    {
        float* data = detections.ptr<float>(0, 0, i);
        float confidence = data[2];

        if (confidence > 0.5)
        {
            int x1 = static_cast<int>(data[3] * frame.cols);
            int y1 = static_cast<int>(data[4] * frame.rows);
            int x2 = static_cast<int>(data[5] * frame.cols);
            int y2 = static_cast<int>(data[6] * frame.rows);

            cv::Rect face_rect(x1, y1, x2 - x1, y2 - y1);
            cv::rectangle(frame, face_rect, cv::Scalar(0, 255, 0), 2);

            face_rects.push_back(face_rect);
        }
    }

    updateFaceLocation(face_rects);
}

void FaceDetector::updateFaceLocation(const std::vector<cv::Rect>& faces)
{
    if (!faces.empty())
    {
        face_rect_ = faces[0];
    }
}
