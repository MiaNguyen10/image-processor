#ifndef IMAGE_ENHANCER_H
#define IMAGE_ENHANCER_H

#include <opencv2/opencv.hpp>

class ImageEnhancer {
public:
    static void enhanceBrightness(cv::Mat& image, double alpha);
    static void enhanceContrast(cv::Mat& image, double beta);
    static void enhanceSharpness(cv::Mat& image, double sigma, double strength);

    static void processImage(cv::Mat& image, double brightnessFactor, double contrastFactor, double sigmaFactor, double sharpnessStrength);
    static void processImages(std::vector<cv::Mat>& images, double brightnessFactor, double contrastFactor, double sigmaFactor, double sharpnessStrength);
};

#endif // IMAGE_ENHANCER_H