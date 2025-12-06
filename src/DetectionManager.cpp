#include "DetectionManager.h"

DetectionManager::DetectionManager() : detectionCount(0) {}

void DetectionManager::registerDetectionEvent() {
    detectionCount++;
}

int DetectionManager::getDetectionCount() const {
    return detectionCount;
}
