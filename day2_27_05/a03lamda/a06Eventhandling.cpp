#include <iostream>
#include <functional>

// Simulate an event-driven system
class EventSystem {
public:
    void registerHandler(std::function<void()> handler) {
        handlers.push_back(handler);
    }

    void triggerEvents() {
        for (auto& handler : handlers) {
            handler();
        }
    }

private:
    std::vector<std::function<void()>> handlers;
};

int main() {
    EventSystem eventSystem;

    // Define a stateful lambda as an event handler
    int eventCount = 0;
    eventSystem.registerHandler([&eventCount]() {
        std::cout << "Event occurred. Total events: " << ++eventCount << std::endl;
    });

    // Trigger events
    eventSystem.triggerEvents();
    eventSystem.triggerEvents();
    eventSystem.triggerEvents();

    return 0;
}
