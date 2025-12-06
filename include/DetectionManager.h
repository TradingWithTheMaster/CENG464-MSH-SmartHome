#ifndef DETECTION_MANAGER_H
#define DETECTION_MANAGER_H

#include <vector>

class DetectionManager {
public:
    DetectionManager();

    void registerDetectionEvent();
    int getDetectionCount() const;

private:
    int detectionCount;
};

#endif
