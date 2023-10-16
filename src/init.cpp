#include "logger.h"

std::shared_ptr<spdlog::logger> BTreeLogger::Logger::spdlogger;

static void initialize() __attribute__((constructor));

void initialize()
{
    auto logger = BTreeLogger::Logger::getLogger();
    logger->info("initializing library");
}
