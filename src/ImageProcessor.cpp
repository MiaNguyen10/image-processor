#include "ImageProcessor.h"
#include "ImageEnhancer.h"
#include <opencv2/opencv.hpp>
#include <filesystem>
#include <vector>
#include <string>


void ImageProcessor::loadImages(const std::string& inputFolder) {
    for (const auto& entry : std::filesystem::directory_iterator(inputFolder)) {
        if (entry.is_regular_file()) {
            cv::Mat image = cv::imread(entry.path().string());
            if (!image.empty()) {
                images.push_back(image);
                imageNames.push_back(entry.path().filename().string());
            }
        }
    }
}

void ImageProcessor::processImages(double alpha, double beta, double sigma, double strength) {
    for (auto& image : images) {
        ImageEnhancer::enhanceBrightness(image, alpha);
        ImageEnhancer::enhanceContrast(image, beta);
        ImageEnhancer::enhanceSharpness(image, sigma, strength);
    }
}

void ImageProcessor::saveImages(const std::string& outputFolder) {
    for (size_t i = 0; i < images.size(); ++i) {
        cv::imwrite(outputFolder + "/" + imageNames[i], images[i]);
    }
}