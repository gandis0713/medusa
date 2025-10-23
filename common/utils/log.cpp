#include "log.hpp"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace medusa
{
namespace utils
{

std::shared_ptr<spdlog::logger> Logger::logger_ = nullptr;

void Logger::init(const std::string& name, spdlog::level::level_enum level)
{
    if (logger_)
    {
        return; // Already initialized
    }

    // Create console logger with color
    logger_ = spdlog::stdout_color_mt(name);
    logger_->set_level(level);
    // logger_->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%n] [%^%l%$] %v");
    logger_->set_pattern("[%n] [%^%l%$] %v");

    logger_->info("Logger initialized: {}", name);
}

std::shared_ptr<spdlog::logger> Logger::get()
{
    if (!logger_)
    {
        init(); // Auto-initialize with defaults if not already done
    }
    return logger_;
}

void Logger::set_level(spdlog::level::level_enum level)
{
    if (logger_)
    {
        logger_->set_level(level);
    }
}

} // namespace utils
} // namespace medusa
