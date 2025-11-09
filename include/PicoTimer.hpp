#pragma once
#include <ILog.h>
#include <functional>

class PicoTimer
{
private:
    ILog* m_pLog;

public:
    PicoTimer(ILog* pLog);

    void SetTimer(int timeMs, std::function<void()> pCallbackFunction);
};