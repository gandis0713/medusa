#pragma once

#include <spdlog/spdlog.h>
#include <memory>

namespace medusa {
namespace utils {

/**
 * @brief Logger wrapper for medusa project
 *
 * Provides a centralized logging interface using spdlog
 */
class Logger {
public:
    /**
     * @brief Initialize the logger
     *
     * @param name Logger name
     * @param level Log level (trace, debug, info, warn, error, critical)
     */
    static void init(const std::string& name = "medusa",
                     spdlog::level::level_enum level = spdlog::level::info);

    /**
     * @brief Get the logger instance
     *
     * @return std::shared_ptr<spdlog::logger> Logger instance
     */
    static std::shared_ptr<spdlog::logger> get();

    /**
     * @brief Set log level
     *
     * @param level Log level
     */
    static void set_level(spdlog::level::level_enum level);

private:
    static std::shared_ptr<spdlog::logger> logger_;
};

// Convenience macros for logging
#define LOG_TRACE(...)    ::medusa::utils::Logger::get()->trace(__VA_ARGS__)
#define LOG_DEBUG(...)    ::medusa::utils::Logger::get()->debug(__VA_ARGS__)
#define LOG_INFO(...)     ::medusa::utils::Logger::get()->info(__VA_ARGS__)
#define LOG_WARN(...)     ::medusa::utils::Logger::get()->warn(__VA_ARGS__)
#define LOG_ERROR(...)    ::medusa::utils::Logger::get()->error(__VA_ARGS__)
#define LOG_CRITICAL(...) ::medusa::utils::Logger::get()->critical(__VA_ARGS__)

} // namespace utils
} // namespace medusa
