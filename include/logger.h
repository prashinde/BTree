#pragma once

#include <memory>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/fmt/fmt.h>

#define LOG BTreeLogger::Logger::getLogger();
namespace BTreeLogger {

class Logger {

public:
    static std::shared_ptr<spdlog::logger> getLogger()
    {
        static Logger logger;
        return logger.spdlogger;
    }

private:
    Logger()
    {
        spdlogger = spdlog::rotating_logger_mt("btreelogger", "logs/btree_log.txt", 1048576 * 5, 3);
    }
    static std::shared_ptr<spdlog::logger> spdlogger;  
};

} // BTreeLogger
