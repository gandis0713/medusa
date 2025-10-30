#include "log.h"

#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>

/* ANSI color codes */
#define COLOR_RESET   "\033[0m"
#define COLOR_GRAY    "\033[90m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_RED     "\033[31m"
#define COLOR_MAGENTA "\033[35m"

/* Global logger state */
static struct {
    char name[256];
    int level;
    int initialized;
} g_logger = {
    .name = "medusa",
    .level = LOG_LEVEL_INFO,
    .initialized = 0
};

void log_init(const char* name, int level)
{
    if (name && name[0] != '\0')
    {
        strncpy(g_logger.name, name, sizeof(g_logger.name) - 1);
        g_logger.name[sizeof(g_logger.name) - 1] = '\0';
    }

    g_logger.level = level;
    g_logger.initialized = 1;
}

/* Helper function to get current timestamp */
static void get_timestamp(char* buffer, size_t size)
{
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    strftime(buffer, size, "%H:%M:%S", tm_info);
}

/* Helper function to get level string and color */
static const char* get_level_string(int level)
{
    switch (level)
    {
        case LOG_LEVEL_TRACE:    return "trace";
        case LOG_LEVEL_DEBUG:    return "debug";
        case LOG_LEVEL_INFO:     return "info";
        case LOG_LEVEL_WARN:     return "warn";
        case LOG_LEVEL_ERROR:    return "error";
        case LOG_LEVEL_CRITICAL: return "critical";
        default:                 return "unknown";
    }
}

static const char* get_level_color(int level)
{
    switch (level)
    {
        case LOG_LEVEL_TRACE:    return COLOR_GRAY;
        case LOG_LEVEL_DEBUG:    return COLOR_CYAN;
        case LOG_LEVEL_INFO:     return COLOR_GREEN;
        case LOG_LEVEL_WARN:     return COLOR_YELLOW;
        case LOG_LEVEL_ERROR:    return COLOR_RED;
        case LOG_LEVEL_CRITICAL: return COLOR_MAGENTA;
        default:                 return COLOR_RESET;
    }
}

/* Internal logging function */
static void log_message(int level, const char* fmt, va_list args)
{
    /* Initialize logger if not already done */
    if (!g_logger.initialized)
    {
        log_init(NULL, LOG_LEVEL_INFO);
    }

    /* Check if this message should be logged */
    if (level < g_logger.level)
    {
        return;
    }

    char timestamp[32];
    get_timestamp(timestamp, sizeof(timestamp));

    /* Print formatted log message: [name] [timestamp] [level] message */
    fprintf(stderr, "[%s] %s[%s] [%s]%s ",
            g_logger.name,
            get_level_color(level),
            timestamp,
            get_level_string(level),
            COLOR_RESET);

    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    fflush(stderr);
}

void log_trace(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    log_message(LOG_LEVEL_TRACE, fmt, args);
    va_end(args);
}

void log_debug(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    log_message(LOG_LEVEL_DEBUG, fmt, args);
    va_end(args);
}

void log_info(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    log_message(LOG_LEVEL_INFO, fmt, args);
    va_end(args);
}

void log_warn(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    log_message(LOG_LEVEL_WARN, fmt, args);
    va_end(args);
}

void log_error(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    log_message(LOG_LEVEL_ERROR, fmt, args);
    va_end(args);
}

void log_critical(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    log_message(LOG_LEVEL_CRITICAL, fmt, args);
    va_end(args);
}
