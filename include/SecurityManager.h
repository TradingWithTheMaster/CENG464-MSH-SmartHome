#ifndef SECURITY_MANAGER_H
#define SECURITY_MANAGER_H

#include <vector>

class SecurityManager {
public:
    SecurityManager();

    void armSystem();
    void disarmSystem();
    bool isArmed() const;

private:
    bool armed;
};

#endif
