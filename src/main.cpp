#include <iostream>
#include <vector>
#include <quill/Quill.h>
#include <hackathonbot.h>

int main() {
    //logging setup start
    quill::start();
    quill::Logger *logger = quill::create_logger("HackathonBotLogger");
    logger->set_log_level(quill::LogLevel::TraceL2);
    // logging setup end

    HackathonBot hackathonbot;
    Action action;
    QUILL_LOG_INFO(logger, "Current status: {}", hackathonbot.isHolding());
    hackathonbot.takeAction(188);
    QUILL_LOG_INFO(logger, "Current status: {}", hackathonbot.isHolding());
    hackathonbot.takeAction(190);
    QUILL_LOG_INFO(logger, "Current status: {}", hackathonbot.isHolding());

    return 0;
}
