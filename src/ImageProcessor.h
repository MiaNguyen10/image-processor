#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include "ImageEnhancer.h"

class ImageProcessor {
public:
    void loadImages(const std::string& inputFolder);
    void processImages(double alpha = 1.0, double beta = 0.0, double sigma = 1.0, double strength = 0.0, bool parallel = true);
    void saveImages(const std::string& outputFolder);

    std::vector<cv::Mat> getImages() const;
    void setImages(const std::vector<cv::Mat>& newImages);


private:
    std::vector<cv::Mat> images;
    std::vector<std::string> imageNames;
    ImageEnhancer enhancer;
};

#endif // IMAGEPROCESSOR_H