#include "device.h"

#include "utils/log.h"
#include <sys/sysinfo.h>

void print_memory_info()
{
    struct sysinfo info;
    sysinfo(&info);

    uint64_t total_ram = (uint64_t)info.totalram * (uint64_t)info.mem_unit;
    uint64_t free_ram = (uint64_t)info.freeram * (uint64_t)info.mem_unit;

    LOG_INFO("Device Memory Information:");
    LOG_INFO("  Total RAM: %llu MB", total_ram / (1024 * 1024));
    LOG_INFO("  Free RAM:  %llu MB", free_ram / (1024 * 1024));
}