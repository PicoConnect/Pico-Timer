#pragma once
#include <functional>

class IPicoTimer
{
public:
    virtual void SetTimer(int timeMs, std::function<void()> pCallbackFunction) = 0;
};