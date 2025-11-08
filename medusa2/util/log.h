/*
 * Copyright 2017 Google
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef MEDUSA_LOG_H
#define MEDUSA_LOG_H

#include <stdarg.h>
#include <stdio.h>

#include "util/macros.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef MEDUSA_LOG_TAG
#define MEDUSA_LOG_TAG "MESA"
#endif

    enum medusa_log_level
    {
        MEDUSA_LOG_ERROR,
        MEDUSA_LOG_WARN,
        MEDUSA_LOG_INFO,
        MEDUSA_LOG_DEBUG,

        MESA_NUM_LOG_LEVELS,
    };

#if MESA_DEBUG
#define MESA_DEFAULT_LOG_LEVEL MEDUSA_LOG_DEBUG
#else
#define MESA_DEFAULT_LOG_LEVEL MEDUSA_LOG_INFO
#endif

#define MAX_LOG_MESSAGE_LENGTH 4096

    FILE*
    medusa_log_get_file(void);

    void PRINTFLIKE(3, 4)
        medusa_log(enum medusa_log_level, const char* tag, const char* format, ...);

    void
    medusa_log_v(enum medusa_log_level, const char* tag, const char* format,
                 va_list va);

    void
    _medusa_log(const char* fmtString, ...) PRINTFLIKE(1, 2);

    void
    _medusa_log_direct(const char* string);

    void
    medusa_log_if_debug(enum medusa_log_level level, const char* outputString);

#define medusa_loge(fmt, ...) medusa_log(MEDUSA_LOG_ERROR, (MEDUSA_LOG_TAG), (fmt), ##__VA_ARGS__)
#define medusa_logw(fmt, ...) medusa_log(MEDUSA_LOG_WARN, (MEDUSA_LOG_TAG), (fmt), ##__VA_ARGS__)
#define medusa_logi(fmt, ...) medusa_log(MEDUSA_LOG_INFO, (MEDUSA_LOG_TAG), (fmt), ##__VA_ARGS__)
#if MESA_DEBUG
#define medusa_logd(fmt, ...) medusa_log(MEDUSA_LOG_DEBUG, (MEDUSA_LOG_TAG), (fmt), ##__VA_ARGS__)
#else
#define medusa_logd(fmt, ...) __medusa_log_use_args((fmt), ##__VA_ARGS__)
#endif

#define medusa_loge_v(fmt, va) medusa_log_v(MEDUSA_LOG_ERROR, (MEDUSA_LOG_TAG), (fmt), (va))
#define medusa_logw_v(fmt, va) medusa_log_v(MEDUSA_LOG_WARN, (MEDUSA_LOG_TAG), (fmt), (va))
#define medusa_logi_v(fmt, va) medusa_log_v(MEDUSA_LOG_INFO, (MEDUSA_LOG_TAG), (fmt), (va))
#if MESA_DEBUG
#define medusa_logd_v(fmt, va) medusa_log_v(MEDUSA_LOG_DEBUG, (MEDUSA_LOG_TAG), (fmt), (va))
#else
#define medusa_logd_v(fmt, va) __medusa_log_use_args((fmt), (va))
#endif

#define medusa_log_once(level, fmt, ...)                             \
    do                                                               \
    {                                                                \
        static bool once;                                            \
        if (!once)                                                   \
        {                                                            \
            once = true;                                             \
            medusa_log(level, (MEDUSA_LOG_TAG), fmt, ##__VA_ARGS__); \
        }                                                            \
    } while (0)

#define medusa_loge_once(fmt, ...) medusa_log_once(MEDUSA_LOG_ERROR, fmt, ##__VA_ARGS__)
#define medusa_logw_once(fmt, ...) medusa_log_once(MEDUSA_LOG_WARN, fmt, ##__VA_ARGS__)
#define medusa_logi_once(fmt, ...) medusa_log_once(MEDUSA_LOG_INFO, fmt, ##__VA_ARGS__)
#define medusa_logd_once(fmt, ...) medusa_log_once(MEDUSA_LOG_DEBUG, fmt, ##__VA_ARGS__)

    struct log_stream
    {
        char* msg;
        const char* tag;
        size_t pos;
        enum medusa_log_level level;
    };

    struct log_stream* _medusa_log_stream_create(enum medusa_log_level level, const char* tag);
#define medusa_log_streame() _medusa_log_stream_create(MEDUSA_LOG_ERROR, (MEDUSA_LOG_TAG))
#define medusa_log_streamw() _medusa_log_stream_create(MEDUSA_LOG_WARN, (MEDUSA_LOG_TAG))
#define medusa_log_streami() _medusa_log_stream_create(MEDUSA_LOG_INFO, (MEDUSA_LOG_TAG))
    void medusa_log_stream_destroy(struct log_stream* stream);
    void medusa_log_stream_printf(struct log_stream* stream, const char* format, ...) PRINTFLIKE(2, 3);

    void _medusa_log_multiline(enum medusa_log_level level, const char* tag, const char* lines);
#define medusa_log_multiline(level, lines) _medusa_log_multiline(level, (MEDUSA_LOG_TAG), lines)

#if !MESA_DEBUG
    /* Suppres -Wunused */
    static inline void PRINTFLIKE(1, 2)
        __medusa_log_use_args(UNUSED const char* format, ...)
    {
    }
#endif

#ifdef __cplusplus
}
#endif

#endif /* MEDUSA_LOG_H */
