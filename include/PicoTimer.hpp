#pragma once
#include <ILog.h>
#include <functional>
#include <IPicoTimer.hpp>

class PicoTimer : public IPicoTimer
{
private:
    ILog* m_pLog;

public:
    PicoTimer(ILog* pLog);

    void SetTimer(int timeMs, std::function<void()> pCallbackFunction);
};