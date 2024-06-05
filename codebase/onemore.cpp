#if 0

#include <iostream>
#include <queue>
#include <chrono>
#include <thread>

// Define an Event struct to schedule actions
struct Event {
    std::function<void()> action;
    std::chrono::steady_clock::time_point scheduled_time;
};

// Custom comparator for priority queue (earliest event first)
struct EventComparator {
    bool operator()(const Event& e1, const Event& e2) const {
        return e1.scheduled_time > e2.scheduled_time;
    }
};

int main() {
    // Create a priority queue for scheduling events
    std::priority_queue<Event, std::vector<Event>, EventComparator> event_queue;

    // Simulate some events (e.g., sensor readings, control actions)
    event_queue.push({[] { std::cout << "Reading temperature...\n"; }, std::chrono::steady_clock::now()});
    event_queue.push({[] { std::cout << "Adjusting valve...\n"; }, std::chrono::steady_clock::now() + std::chrono::seconds(2)});
    event_queue.push({[] { std::cout << "Monitoring pressure...\n"; }, std::chrono::steady_clock::now() + std::chrono::seconds(5)});

    // Process events in real-time
    while (!event_queue.empty()) {
        const Event& next_event = event_queue.top();
        auto now = std::chrono::steady_clock::now();
        if (next_event.scheduled_time <= now) {
            next_event.action();
            event_queue.pop();
        } else {
            // Wait until the next event is due
            std::this_thread::sleep_for(next_event.scheduled_time - now);
        }
    }

    return 0;
}


#endif