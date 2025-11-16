#ifndef MEDUSA2_BUFFER_OBJECT_H
#define MEDUSA2_BUFFER_OBJECT_H

#include "util/list.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef PAGE_SIZE
#define PAGE_SIZE 4096
#endif

    struct medusa_device;
    struct medusa_memory
    {
        struct medusa_device* device;

        struct list_head list_link;

        uint32_t handle; // DRM이 할당한 고유 핸들 (ID)
        uint64_t handle_bit;
        uint32_t size;   // 버퍼 크기
        uint32_t offset; // GPU 주소 공간에서의 오프셋

        uint32_t map_size;
        void* map; // CPU 매핑된 주소

        const char* name; // 디버깅용 이름
    };

    struct medusa_memory* medusa_memory_alloc(struct medusa_device* dev, uint32_t size, const char* name);
    bool medusa_memory_free(struct medusa_memory* memory);
    bool medusa_memory_wait(struct medusa_memory* memory, uint64_t timeout_ns);
    bool medusa_memory_map(struct medusa_memory* memory, uint32_t size);
    void medusa_memory_unmap(struct medusa_memory* memory);

#ifdef __cplusplus
}
#endif

#endif // MEDUSA2_BUFFER_OBJECT_H