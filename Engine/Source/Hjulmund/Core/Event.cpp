#include "Hjulmund/Core/Event.hpp"

namespace Hjulmund::Core {

void EventQueue::Push(Event event)
{
    events_.push(event);
}

std::optional<Event> EventQueue::Pop()
{
    if (events_.empty()) {
        return std::nullopt;
    }

    Event event = events_.front();
    events_.pop();
    return event;
}

bool EventQueue::Empty() const noexcept
{
    return events_.empty();
}

std::size_t EventQueue::Size() const noexcept
{
    return events_.size();
}

void EventQueue::Clear() noexcept
{
    std::queue<Event> empty;
    events_.swap(empty);
}

} // namespace Hjulmund::Core
