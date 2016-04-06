/**
  * Class definition for a MicroBitEvent
  *
  * It represents a common event that is generated by the various components on the micro:bit.
  */
#include "MicroBitConfig.h"
#include "MicroBitEvent.h"
#include "MicroBitSystemTimer.h"
#include "EventModel.h"

EventModel* EventModel::defaultEventBus = NULL;

/**
  * Constructor.
  *
  * @param src The id of the MicroBit Component that generated the event e.g. MICROBIT_ID_BUTTON_A.
  *
  * @param value A component specific code indicating the cause of the event.
  *
  * @param mode Optional definition of how the event should be processed after construction (if at all):
  *                 CREATE_ONLY: MicroBitEvent is initialised, and no further processing takes place.
  *                 CREATE_AND_FIRE: MicroBitEvent is initialised, and its event handlers are immediately fired (not suitable for use in interrupts!).
  *
  * @code
  * // Create and launch an event using the default configuration
  * MicrobitEvent evt(id,MICROBIT_BUTTON_EVT_CLICK);
  *
  * // Create an event only, do not fire onto an EventModel.
  * MicrobitEvent evt(id,MICROBIT_BUTTON_EVT_CLICK,CREATE_AND_FIRE);
  * @endcode
  */
MicroBitEvent::MicroBitEvent(uint16_t source, uint16_t value, MicroBitEventLaunchMode mode)
{
    this->source = source;
    this->value = value;
    this->timestamp = system_timer_current_time();

    if(mode != CREATE_ONLY)
        this->fire();
}

/**
  * Default constructor - initialises all values, and sets timestamp to the current time.
  */
MicroBitEvent::MicroBitEvent()
{
    this->source = 0;
    this->value = 0;
    this->timestamp = system_timer_current_time();
}

/**
  * Fires this MicroBitEvent onto the Default EventModel, or a custom one!
  */
void MicroBitEvent::fire()
{
	if(EventModel::defaultEventBus)
		EventModel::defaultEventBus->send(*this);
}


/**
  * Constructor.
  * Create a new MicroBitEventQueueItem.
  *
  * @param evt The event to be queued.
  */
MicroBitEventQueueItem::MicroBitEventQueueItem(MicroBitEvent evt)
{
    this->evt = evt;
	this->next = NULL;
}