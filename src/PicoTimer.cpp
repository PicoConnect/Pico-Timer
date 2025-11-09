#include <PicoTimer.hpp>
#include <pico/time.h>
#include <memory>

PicoTimer::PicoTimer(ILog* pLog) : m_pLog(pLog)
{
}


int64_t alarm_callback(alarm_id_t id, void *user_data) 
{
    // Convert back to the shared_ptr pointer
    auto* sharedPtrPtr = static_cast<std::shared_ptr<std::function<void()>>*>(user_data);

    // Copy the shared_ptr so we can safely delete the heap copy
    auto callbackPtr = *sharedPtrPtr;

    // Free the heap copy of the shared_ptr (not the actual function)
    delete sharedPtrPtr;

    // Now invoke the stored callback
    (*callbackPtr)();

    return 0;
}

void PicoTimer::SetTimer(int timeMs, std::function<void()> pCallbackFunction)
{
    m_pLog->Debug("PicoTimer::SetTimer() Creating timer for: " + std::to_string(timeMs) + "ms");
    if (timeMs <= 0)
    {   
        m_pLog->Error("PicoTimer::SetTimer() Timer for was 0 or less ms.");
        return;
    }
    auto callbackPtr = std::make_shared<std::function<void()>>(std::move(pCallbackFunction));
    add_alarm_in_ms(timeMs, alarm_callback, new auto(callbackPtr), false);
}

