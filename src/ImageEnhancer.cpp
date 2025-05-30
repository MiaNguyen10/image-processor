#include "ImageEnhancer.h"
#include <opencv2/opencv.hpp>
#include <omp.h>
#include <iostream>

void ImageEnhancer::enhanceBrightness(cv::Mat& image, double alpha) {
    if (alpha < 0.0 || alpha > 3.0) {
        std::cout << "[WARNING] Brightness alpha out of range (0.0 - 3.0): " << alpha << std::endl;
    }
    std::cout << "Enhance brightness called with alpha = " << alpha << std::endl;
    image.convertTo(image, CV_8UC3, alpha, 0);
}

void ImageEnhancer::enhanceContrast(cv::Mat& image, double beta) {
    if (beta < -100.0 || beta > 100.0) {
        std::cout << "[WARNING] Contrast beta out of range (-100 - 100): " << beta << std::endl;
    }
    std::cout << "Enhance contrast called with beta = " << beta << std::endl;
    image.convertTo(image, CV_8UC3, 1, beta);
}

void ImageEnhancer::enhanceSharpness(cv::Mat& image, double sigma, double strength) {
    if (sigma <= 0.0 || sigma > 10.0) {
        std::cout << "[WARNING] Sharpness sigma out of range (0.1 - 10.0): " << sigma << std::endl;
    }
    if (strength < 0.0 || strength > 5.0) {
        std::cout << "[WARNING] Sharpness strength out of range (0.0 - 5.0): " << strength << std::endl;
    }
    std::cout << "Enhance sharpness called with sigma = " << sigma << ", strength = " << strength << std::endl;
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