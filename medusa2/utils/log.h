#ifndef MEDUSA2_UTILS_LOG_H
#define MEDUSA2_UTILS_LOG_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief C-compatible logging interface for medusa project
 */

/* Log levels */
#define LOG_LEVEL_TRACE 0
#define LOG_LEVEL_DEBUG 1
#define LOG_LEVEL_INFO 2
#define LOG_LEVEL_WARN 3
#define LOG_LEVEL_ERROR 4

    /**
     * @brief Initialize the logger (must be called before any logging)
     *
     * @param name Logger name (can be NULL for default "medusa")
     * @param level Log level (use LOG_LEVEL_* constants)
     */
    void log_init(const char* name, int level);

    /**
     * @brief Logging functions
     */
    void log_trace(const char* fmt, ...);
    void log_debug(const char* fmt, ...);
    void log_info(const char* fmt, ...);
    void log_warn(const char* fmt, ...);
    void log_error(const char* fmt, ...);

/* Convenience macros for C code */
#define LOG_TRACE(...) log_trace(__VA_ARGS__)
#define LOG_DEBUG(...) log_debug(__VA_ARGS__)
#define LOG_INFO(...) log_info(__VA_ARGS__)
#define LOG_WARN(...) log_warn(__VA_ARGS__)
#define LOG_ERROR(...) log_error(__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif // MEDUSA2_UTILS_LOG_H
