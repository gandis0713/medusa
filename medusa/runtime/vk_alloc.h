
#ifndef VK_ALLOC_H
#define VK_ALLOC_H

#include <vulkan/vulkan_core.h>

#ifdef __cplusplus
extern "C"
{
#endif

    const VkAllocationCallbacks* vk_default_allocator(void);

    static inline void*
    vk_alloc(const VkAllocationCallbacks* alloc,
             size_t size, size_t align,
             VkSystemAllocationScope scope)
    {
        return alloc->pfnAllocation(alloc->pUserData, size, align, scope);
    }

    static inline void*
    vk_realloc(const VkAllocationCallbacks* alloc,
               void* ptr, size_t size, size_t align,
               VkSystemAllocationScope scope)
    {
        return alloc->pfnReallocation(alloc->pUserData, ptr, size, align, scope);
    }

    static inline void
    vk_free(const VkAllocationCallbacks* alloc, void* data)
    {
        if (data == NULL)
            return;

        alloc->pfnFree(alloc->pUserData, data);
    }

    static inline void*
    vk_alloc2(const VkAllocationCallbacks* parent_alloc,
              const VkAllocationCallbacks* alloc,
              size_t size, size_t align,
              VkSystemAllocationScope scope)
    {
        if (alloc)
            return vk_alloc(alloc, size, align, scope);
        else
            return vk_alloc(parent_alloc, size, align, scope);
    }

    static inline void*
    vk_realloc2(const VkAllocationCallbacks* parent_alloc,
                const VkAllocationCallbacks* alloc,
                void* ptr, size_t size, size_t align,
                VkSystemAllocationScope scope)
    {
        if (alloc)
            return vk_realloc(alloc, ptr, size, align, scope);
        else
            return vk_realloc(parent_alloc, ptr, size, align, scope);
    }

    static inline void
    vk_free2(const VkAllocationCallbacks* parent_alloc,
             const VkAllocationCallbacks* alloc,
             void* data)
    {
        if (alloc)
            vk_free(alloc, data);
        else
            vk_free(parent_alloc, data);
    }

#ifdef __cplusplus
}
#endif

#endif
