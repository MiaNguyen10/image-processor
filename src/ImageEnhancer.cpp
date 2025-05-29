#include "ImageEnhancer.h"
#include <opencv2/opencv.hpp>
#include <omp.h>

void ImageEnhancer::enhanceBrightness(cv::Mat& image, double alpha) {
    image.convertTo(image, CV_8UC3, alpha, 0);
}

void ImageEnhancer::enhanceContrast(cv::Mat& image, double beta) {
    image.convertTo(image, CV_8UC3, 1, beta);
}

void ImageEnhancer::enhanceSharpness(cv::Mat& image, double sigma, double strength) {
    cv::Mat blurred;
    cv::GaussianBlur(image, blurred, cv::Size(0, 0), sigma);
    cv::addWeighted(image, 1 + strength, blurred, -strength, 0, image);
}

void ImageEnhancer::processImage(cv::Mat& image, double brightnessFactor, double contrastFactor, double sigmaFactor, double sharpnessStrength) {
    enhanceBrightness(image, brightnessFactor);
    enhanceContrast(image, contrastFactor);
    enhanceSharpness(image, sigmaFactor, sharpnessStrength);
}

void ImageEnhancer::processImages(std::vector<cv::Mat>& images, double brightnessFactor, double contrastFactor, double sigmaFactor, double sharpnessStrength) {
    #pragma omp parallel for
    for (int i = 0; i < static_cast<int>(images.size()); ++i) {
        processImage(images[i], brightnessFactor, contrastFactor, sigmaFactor, sharpnessStrength);
    }
}