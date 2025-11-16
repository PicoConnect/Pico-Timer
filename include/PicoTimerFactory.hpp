#include <IPicoTimerFactory.hpp>
#include "IPicoTimer.hpp"

class PicoTimerFactory : public IPicoTimerFactory
{
private:
    ILog* m_pLog;

public:
    PicoTimerFactory(ILog* pLog);
    ~PicoTimerFactory();

    // IPicoTimerFactory
    IPicoTimer* CreateTimer() override; 
};