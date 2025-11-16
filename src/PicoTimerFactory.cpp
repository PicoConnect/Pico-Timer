#include <PicoTimerFactory.hpp>

PicoTimerFactory::PicoTimerFactory(ILog* pLog) : m_pLog(pLog)
{

}

PicoTimerFactory::~PicoTimerFactory()
{

}

IPicoTimer *PicoTimerFactory::CreateTimer()
{
   return new PicoTimer(m_pLog);
}
