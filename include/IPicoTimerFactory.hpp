#pragma once
#include <PicoTimer.hpp>

class IPicoTimerFactory
{
public:
    virtual IPicoTimer* CreateTimer() = 0;
};