#ifndef V3DV_ENTRYPOINTS_H
#define V3DV_ENTRYPOINTS_H

#include "vk_dispatch_table.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* Entrypoint symbols are optional, and resolves to NULL if undefined.
 * On Unix, this semantics is achieved through weak symbols.
 * Note that we only declare the symbols as weak when it needs to be optional;
 * otherwise, the symbol is declared as a regular symbol.
 * This is to workaround a MinGW limitation: on MinGW, the definition for a
 * weak symbol must be regular, or the linker will end up resolving to one of
 * the fallback symbols with the absolute value of 0.
 * On MSVC, weak symbols are not well supported, so we use the functionally
 * equivalent /alternatename.
 */
#if !defined(_MSC_VER) && defined(VK_ENTRY_USE_WEAK)
#define VK_ENTRY_WEAK __attribute__((weak))
#else
#define VK_ENTRY_WEAK
#endif

/* On Unix, we explicitly declare the symbols as hidden, as -fvisibility=hidden
 * only applies to definitions, not declarations.
 * Windows uses hidden visibility by default (requiring dllexport for public
 * symbols), so we don't need to deal with visibility there.
 */
#ifndef _WIN32
#define VK_ENTRY_HIDDEN __attribute__((visibility("hidden")))
#else
#define VK_ENTRY_HIDDEN
#endif

    extern const struct vk_instance_entrypoint_table v3dv_instance_entrypoints;

    extern const struct vk_physical_device_entrypoint_table v3dv_physical_device_entrypoints;

    extern const struct vk_device_entrypoint_table v3dv_device_entrypoints;
    extern const struct vk_device_entrypoint_table ver42_device_entrypoints;
    extern const struct vk_device_entrypoint_table ver71_device_entrypoints;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_EnumeratePhysicalDevices(VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL v3dv_GetInstanceProcAddr(VkInstance instance, const char* pName) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_EnumerateInstanceVersion(uint32_t* pApiVersion) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_EnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_EnumerateInstanceExtensionProperties(const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateAndroidSurfaceKHR(VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_OHOS
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateSurfaceOHOS(VkInstance instance, const VkSurfaceCreateInfoOHOS* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_OHOS
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateDisplayPlaneSurfaceKHR(VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_DestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#ifdef VK_USE_PLATFORM_VI_NN
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateViSurfaceNN(VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_VI_NN
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateWaylandSurfaceKHR(VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateWin32SurfaceKHR(VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_XLIB_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateXlibSurfaceKHR(VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateXcbSurfaceKHR(VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateDirectFBSurfaceEXT(VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
#ifdef VK_USE_PLATFORM_FUCHSIA
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateImagePipeSurfaceFUCHSIA(VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_GGP
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateStreamDescriptorSurfaceGGP(VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_GGP
#ifdef VK_USE_PLATFORM_SCREEN_QNX
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateScreenSurfaceQNX(VkInstance instance, const VkScreenSurfaceCreateInfoQNX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_SCREEN_QNX
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_DebugReportMessageEXT(VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_EnumeratePhysicalDeviceGroups(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_EnumeratePhysicalDeviceGroupsKHR(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#ifdef VK_USE_PLATFORM_IOS_MVK
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateIOSSurfaceMVK(VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_IOS_MVK
#ifdef VK_USE_PLATFORM_MACOS_MVK
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateMacOSSurfaceMVK(VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_MACOS_MVK
#ifdef VK_USE_PLATFORM_METAL_EXT
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateMetalSurfaceEXT(VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_METAL_EXT
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_SubmitDebugUtilsMessageEXT(VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateHeadlessSurfaceEXT(VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetExternalComputeQueueDataNV(VkExternalComputeQueueNV externalQueue, VkExternalComputeQueueDataParamsNV* params, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_EnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkLayerProperties* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_EnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    VKAPI_ATTR VkBool32 VKAPI_CALL v3dv_GetPhysicalDeviceWaylandPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display* display) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkBool32 VKAPI_CALL v3dv_GetPhysicalDeviceWin32PresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_XLIB_KHR
    VKAPI_ATTR VkBool32 VKAPI_CALL v3dv_GetPhysicalDeviceXlibPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display* dpy, VisualID visualID) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
    VKAPI_ATTR VkBool32 VKAPI_CALL v3dv_GetPhysicalDeviceXcbPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
    VKAPI_ATTR VkBool32 VKAPI_CALL v3dv_GetPhysicalDeviceDirectFBPresentationSupportEXT(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB* dfb) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
#ifdef VK_USE_PLATFORM_SCREEN_QNX
    VKAPI_ATTR VkBool32 VKAPI_CALL v3dv_GetPhysicalDeviceScreenPresentationSupportQNX(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct _screen_window* window) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_SCREEN_QNX
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceExternalImageFormatPropertiesNV(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceFeatures2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceFormatProperties2KHR(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceQueueFamilyProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceMemoryProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceSparseImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceExternalBufferPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceExternalSemaphorePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceExternalFencePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_ReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_AcquireXlibDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, VkDisplayKHR display) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetRandROutputDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput, VkDisplayKHR* pDisplay) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
#ifdef VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_AcquireWinrtDisplayNV(VkPhysicalDevice physicalDevice, VkDisplayKHR display) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetWinrtDisplayNV(VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId, VkDisplayKHR* pDisplay) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayProperties2KHR* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceCalibrateableTimeDomainsKHR(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainKHR* pTimeDomains) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainKHR* pTimeDomains) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceCooperativeMatrixPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#ifdef VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceSurfacePresentModes2EXT(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
#endif // VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceFragmentShadingRatesKHR(VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceVideoCapabilitiesKHR(VkPhysicalDevice physicalDevice, const VkVideoProfileInfoKHR* pVideoProfile, VkVideoCapabilitiesKHR* pCapabilities) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceVideoFormatPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo, uint32_t* pVideoFormatPropertyCount, VkVideoFormatPropertiesKHR* pVideoFormatProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* pQualityLevelInfo, VkVideoEncodeQualityLevelPropertiesKHR* pQualityLevelProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_AcquireDrmDisplayEXT(VkPhysicalDevice physicalDevice, int32_t drmFd, VkDisplayKHR display) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetDrmDisplayEXT(VkPhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId, VkDisplayKHR* display) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceOpticalFlowImageFormatsNV(VkPhysicalDevice physicalDevice, const VkOpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo, uint32_t* pFormatCount, VkOpticalFlowImageFormatPropertiesNV* pImageFormatProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceCooperativeMatrixPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesKHR* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixFlexibleDimensionsPropertiesNV* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceCooperativeVectorPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeVectorPropertiesNV* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceExternalTensorPropertiesARM(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalTensorInfoARM* pExternalTensorInfo, VkExternalTensorPropertiesARM* pExternalTensorProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pQueueFamilyDataGraphPropertyCount, VkQueueFamilyDataGraphPropertiesARM* pQueueFamilyDataGraphProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL v3dv_GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM* pQueueFamilyDataGraphProcessingEngineInfo, VkQueueFamilyDataGraphProcessingEnginePropertiesARM* pQueueFamilyDataGraphProcessingEngineProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL v3dv_GetDeviceProcAddr(VkDevice device, const char* pName) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL ver42_GetDeviceProcAddr(VkDevice device, const char* pName) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL ver71_GetDeviceProcAddr(VkDevice device, const char* pName) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_QueueWaitIdle(VkQueue queue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_QueueWaitIdle(VkQueue queue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_QueueWaitIdle(VkQueue queue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_DeviceWaitIdle(VkDevice device) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_DeviceWaitIdle(VkDevice device) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_DeviceWaitIdle(VkDevice device) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_AllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_AllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_AllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_FreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_FreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_FreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_MapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_MapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_MapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_UnmapMemory(VkDevice device, VkDeviceMemory memory) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_UnmapMemory(VkDevice device, VkDeviceMemory memory) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_UnmapMemory(VkDevice device, VkDeviceMemory memory) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_FlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_FlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_FlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_InvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_InvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_InvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_BindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_BindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_BindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_BindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_BindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_BindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetImageSparseMemoryRequirements(VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetImageSparseMemoryRequirements(VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetImageSparseMemoryRequirements(VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_QueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_QueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_QueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_ResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_ResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_ResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetFenceStatus(VkDevice device, VkFence fence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetFenceStatus(VkDevice device, VkFence fence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetFenceStatus(VkDevice device, VkFence fence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_WaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_WaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_WaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetEventStatus(VkDevice device, VkEvent event) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetEventStatus(VkDevice device, VkEvent event) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetEventStatus(VkDevice device, VkEvent event) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_SetEvent(VkDevice device, VkEvent event) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_SetEvent(VkDevice device, VkEvent event) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_SetEvent(VkDevice device, VkEvent event) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_ResetEvent(VkDevice device, VkEvent event) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_ResetEvent(VkDevice device, VkEvent event) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_ResetEvent(VkDevice device, VkEvent event) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_ResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_ResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_ResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_ResetQueryPoolEXT(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_ResetQueryPoolEXT(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_ResetQueryPoolEXT(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_MergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_MergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_MergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreatePipelineBinariesKHR(VkDevice device, const VkPipelineBinaryCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineBinaryHandlesInfoKHR* pBinaries) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreatePipelineBinariesKHR(VkDevice device, const VkPipelineBinaryCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineBinaryHandlesInfoKHR* pBinaries) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreatePipelineBinariesKHR(VkDevice device, const VkPipelineBinaryCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineBinaryHandlesInfoKHR* pBinaries) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyPipelineBinaryKHR(VkDevice device, VkPipelineBinaryKHR pipelineBinary, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyPipelineBinaryKHR(VkDevice device, VkPipelineBinaryKHR pipelineBinary, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyPipelineBinaryKHR(VkDevice device, VkPipelineBinaryKHR pipelineBinary, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPipelineKeyKHR(VkDevice device, const VkPipelineCreateInfoKHR* pPipelineCreateInfo, VkPipelineBinaryKeyKHR* pPipelineKey) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetPipelineKeyKHR(VkDevice device, const VkPipelineCreateInfoKHR* pPipelineCreateInfo, VkPipelineBinaryKeyKHR* pPipelineKey) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetPipelineKeyKHR(VkDevice device, const VkPipelineCreateInfoKHR* pPipelineCreateInfo, VkPipelineBinaryKeyKHR* pPipelineKey) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPipelineBinaryDataKHR(VkDevice device, const VkPipelineBinaryDataInfoKHR* pInfo, VkPipelineBinaryKeyKHR* pPipelineBinaryKey, size_t* pPipelineBinaryDataSize, void* pPipelineBinaryData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetPipelineBinaryDataKHR(VkDevice device, const VkPipelineBinaryDataInfoKHR* pInfo, VkPipelineBinaryKeyKHR* pPipelineBinaryKey, size_t* pPipelineBinaryDataSize, void* pPipelineBinaryData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetPipelineBinaryDataKHR(VkDevice device, const VkPipelineBinaryDataInfoKHR* pInfo, VkPipelineBinaryKeyKHR* pPipelineBinaryKey, size_t* pPipelineBinaryDataSize, void* pPipelineBinaryData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_ReleaseCapturedPipelineDataKHR(VkDevice device, const VkReleaseCapturedPipelineDataInfoKHR* pInfo, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_ReleaseCapturedPipelineDataKHR(VkDevice device, const VkReleaseCapturedPipelineDataInfoKHR* pInfo, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_ReleaseCapturedPipelineDataKHR(VkDevice device, const VkReleaseCapturedPipelineDataInfoKHR* pInfo, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(VkDevice device, VkRenderPass renderpass, VkExtent2D* pMaxWorkgroupSize) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(VkDevice device, VkRenderPass renderpass, VkExtent2D* pMaxWorkgroupSize) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(VkDevice device, VkRenderPass renderpass, VkExtent2D* pMaxWorkgroupSize) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_ResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_ResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_ResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_AllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_AllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_AllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_FreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_FreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_FreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_UpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_UpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_UpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetRenderingAreaGranularity(VkDevice device, const VkRenderingAreaInfo* pRenderingAreaInfo, VkExtent2D* pGranularity) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetRenderingAreaGranularity(VkDevice device, const VkRenderingAreaInfo* pRenderingAreaInfo, VkExtent2D* pGranularity) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetRenderingAreaGranularity(VkDevice device, const VkRenderingAreaInfo* pRenderingAreaInfo, VkExtent2D* pGranularity) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetRenderingAreaGranularityKHR(VkDevice device, const VkRenderingAreaInfo* pRenderingAreaInfo, VkExtent2D* pGranularity) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetRenderingAreaGranularityKHR(VkDevice device, const VkRenderingAreaInfo* pRenderingAreaInfo, VkExtent2D* pGranularity) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetRenderingAreaGranularityKHR(VkDevice device, const VkRenderingAreaInfo* pRenderingAreaInfo, VkExtent2D* pGranularity) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_ResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_ResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_ResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_AllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_AllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_AllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_FreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_FreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_FreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_BeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_BeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_BeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_EndCommandBuffer(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_EndCommandBuffer(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_EndCommandBuffer(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_ResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_ResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_ResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyMemoryIndirectKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryIndirectInfoKHR* pCopyMemoryIndirectInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyMemoryIndirectKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryIndirectInfoKHR* pCopyMemoryIndirectInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyMemoryIndirectKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryIndirectInfoKHR* pCopyMemoryIndirectInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride, VkImage dstImage, VkImageLayout dstImageLayout, const VkImageSubresourceLayers* pImageSubresources) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride, VkImage dstImage, VkImageLayout dstImageLayout, const VkImageSubresourceLayers* pImageSubresources) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride, VkImage dstImage, VkImageLayout dstImageLayout, const VkImageSubresourceLayers* pImageSubresources) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyMemoryToImageIndirectKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToImageIndirectInfoKHR* pCopyMemoryToImageIndirectInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyMemoryToImageIndirectKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToImageIndirectInfoKHR* pCopyMemoryToImageIndirectInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyMemoryToImageIndirectKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToImageIndirectInfoKHR* pCopyMemoryToImageIndirectInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdEndRenderPass(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdEndRenderPass(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdEndRenderPass(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_AcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_AcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_AcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_QueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_QueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_QueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_DebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_DebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_DebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_DebugMarkerSetObjectTagEXT(VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_DebugMarkerSetObjectTagEXT(VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_DebugMarkerSetObjectTagEXT(VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#ifdef VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetMemoryWin32HandleNV(VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetMemoryWin32HandleNV(VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetMemoryWin32HandleNV(VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR void VKAPI_CALL v3dv_CmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetGeneratedCommandsMemoryRequirementsNV(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetGeneratedCommandsMemoryRequirementsNV(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetGeneratedCommandsMemoryRequirementsNV(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateIndirectCommandsLayoutNV(VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateIndirectCommandsLayoutNV(VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateIndirectCommandsLayoutNV(VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyIndirectCommandsLayoutNV(VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyIndirectCommandsLayoutNV(VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyIndirectCommandsLayoutNV(VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo, VkCommandBuffer stateCommandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo, VkCommandBuffer stateCommandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo, VkCommandBuffer stateCommandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetGeneratedCommandsMemoryRequirementsEXT(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoEXT* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetGeneratedCommandsMemoryRequirementsEXT(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoEXT* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetGeneratedCommandsMemoryRequirementsEXT(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoEXT* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateIndirectCommandsLayoutEXT(VkDevice device, const VkIndirectCommandsLayoutCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutEXT* pIndirectCommandsLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateIndirectCommandsLayoutEXT(VkDevice device, const VkIndirectCommandsLayoutCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutEXT* pIndirectCommandsLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateIndirectCommandsLayoutEXT(VkDevice device, const VkIndirectCommandsLayoutCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutEXT* pIndirectCommandsLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyIndirectCommandsLayoutEXT(VkDevice device, VkIndirectCommandsLayoutEXT indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyIndirectCommandsLayoutEXT(VkDevice device, VkIndirectCommandsLayoutEXT indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyIndirectCommandsLayoutEXT(VkDevice device, VkIndirectCommandsLayoutEXT indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateIndirectExecutionSetEXT(VkDevice device, const VkIndirectExecutionSetCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectExecutionSetEXT* pIndirectExecutionSet) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateIndirectExecutionSetEXT(VkDevice device, const VkIndirectExecutionSetCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectExecutionSetEXT* pIndirectExecutionSet) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateIndirectExecutionSetEXT(VkDevice device, const VkIndirectExecutionSetCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectExecutionSetEXT* pIndirectExecutionSet) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyIndirectExecutionSetEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyIndirectExecutionSetEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyIndirectExecutionSetEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_UpdateIndirectExecutionSetPipelineEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, uint32_t executionSetWriteCount, const VkWriteIndirectExecutionSetPipelineEXT* pExecutionSetWrites) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_UpdateIndirectExecutionSetPipelineEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, uint32_t executionSetWriteCount, const VkWriteIndirectExecutionSetPipelineEXT* pExecutionSetWrites) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_UpdateIndirectExecutionSetPipelineEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, uint32_t executionSetWriteCount, const VkWriteIndirectExecutionSetPipelineEXT* pExecutionSetWrites) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_UpdateIndirectExecutionSetShaderEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, uint32_t executionSetWriteCount, const VkWriteIndirectExecutionSetShaderEXT* pExecutionSetWrites) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_UpdateIndirectExecutionSetShaderEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, uint32_t executionSetWriteCount, const VkWriteIndirectExecutionSetShaderEXT* pExecutionSetWrites) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_UpdateIndirectExecutionSetShaderEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, uint32_t executionSetWriteCount, const VkWriteIndirectExecutionSetShaderEXT* pExecutionSetWrites) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdPushDescriptorSet(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdPushDescriptorSet(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdPushDescriptorSet(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_TrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_TrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_TrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_TrimCommandPoolKHR(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_TrimCommandPoolKHR(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_TrimCommandPoolKHR(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#ifdef VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetMemoryWin32HandleKHR(VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetMemoryWin32HandleKHR(VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetMemoryWin32HandleKHR(VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetMemoryWin32HandlePropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetMemoryWin32HandlePropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetMemoryWin32HandlePropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#ifdef VK_USE_PLATFORM_FUCHSIA
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetMemoryZirconHandleFUCHSIA(VkDevice device, const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetMemoryZirconHandleFUCHSIA(VkDevice device, const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetMemoryZirconHandleFUCHSIA(VkDevice device, const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetMemoryZirconHandlePropertiesFUCHSIA(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetMemoryZirconHandlePropertiesFUCHSIA(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetMemoryZirconHandlePropertiesFUCHSIA(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_FUCHSIA
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetMemoryRemoteAddressNV(VkDevice device, const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo, VkRemoteAddressNV* pAddress) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetMemoryRemoteAddressNV(VkDevice device, const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo, VkRemoteAddressNV* pAddress) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetMemoryRemoteAddressNV(VkDevice device, const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo, VkRemoteAddressNV* pAddress) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#ifdef VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetSemaphoreWin32HandleKHR(VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetSemaphoreWin32HandleKHR(VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetSemaphoreWin32HandleKHR(VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_ImportSemaphoreWin32HandleKHR(VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_ImportSemaphoreWin32HandleKHR(VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_ImportSemaphoreWin32HandleKHR(VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_ImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_ImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_ImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#ifdef VK_USE_PLATFORM_FUCHSIA
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetSemaphoreZirconHandleFUCHSIA(VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetSemaphoreZirconHandleFUCHSIA(VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetSemaphoreZirconHandleFUCHSIA(VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_ImportSemaphoreZirconHandleFUCHSIA(VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_ImportSemaphoreZirconHandleFUCHSIA(VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_ImportSemaphoreZirconHandleFUCHSIA(VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetFenceWin32HandleKHR(VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetFenceWin32HandleKHR(VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetFenceWin32HandleKHR(VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_ImportFenceWin32HandleKHR(VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_ImportFenceWin32HandleKHR(VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_ImportFenceWin32HandleKHR(VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_ImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_ImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_ImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_DisplayPowerControlEXT(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_DisplayPowerControlEXT(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_DisplayPowerControlEXT(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_RegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_RegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_RegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_RegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_RegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_RegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDeviceGroupPeerMemoryFeaturesKHR(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDeviceGroupPeerMemoryFeaturesKHR(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDeviceGroupPeerMemoryFeaturesKHR(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_BindBufferMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_BindBufferMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_BindBufferMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_BindBufferMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_BindBufferMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_BindBufferMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_BindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_BindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_BindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_BindImageMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_BindImageMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_BindImageMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetDeviceGroupPresentCapabilitiesKHR(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetDeviceGroupPresentCapabilitiesKHR(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetDeviceGroupPresentCapabilitiesKHR(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_AcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_AcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_AcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateDescriptorUpdateTemplate(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateDescriptorUpdateTemplate(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateDescriptorUpdateTemplate(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateDescriptorUpdateTemplateKHR(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateDescriptorUpdateTemplateKHR(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateDescriptorUpdateTemplateKHR(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyDescriptorUpdateTemplate(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyDescriptorUpdateTemplate(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyDescriptorUpdateTemplate(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyDescriptorUpdateTemplateKHR(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyDescriptorUpdateTemplateKHR(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyDescriptorUpdateTemplateKHR(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_UpdateDescriptorSetWithTemplate(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_UpdateDescriptorSetWithTemplate(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_UpdateDescriptorSetWithTemplate(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_UpdateDescriptorSetWithTemplateKHR(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_UpdateDescriptorSetWithTemplateKHR(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_UpdateDescriptorSetWithTemplateKHR(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdPushDescriptorSetWithTemplate(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdPushDescriptorSetWithTemplate(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdPushDescriptorSetWithTemplate(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_SetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_SetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_SetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetRefreshCycleDurationGOOGLE(VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetRefreshCycleDurationGOOGLE(VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetRefreshCycleDurationGOOGLE(VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPastPresentationTimingGOOGLE(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetPastPresentationTimingGOOGLE(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetPastPresentationTimingGOOGLE(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetBufferMemoryRequirements2KHR(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetBufferMemoryRequirements2KHR(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetBufferMemoryRequirements2KHR(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetImageMemoryRequirements2KHR(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetImageMemoryRequirements2KHR(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetImageMemoryRequirements2KHR(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetImageSparseMemoryRequirements2(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetImageSparseMemoryRequirements2(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetImageSparseMemoryRequirements2(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetImageSparseMemoryRequirements2KHR(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetImageSparseMemoryRequirements2KHR(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetImageSparseMemoryRequirements2KHR(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDeviceBufferMemoryRequirements(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDeviceBufferMemoryRequirements(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDeviceBufferMemoryRequirements(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDeviceBufferMemoryRequirementsKHR(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDeviceBufferMemoryRequirementsKHR(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDeviceBufferMemoryRequirementsKHR(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDeviceImageMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDeviceImageMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDeviceImageMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDeviceImageMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDeviceImageMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDeviceImageMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDeviceImageSparseMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDeviceImageSparseMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDeviceImageSparseMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDeviceImageSparseMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDeviceImageSparseMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDeviceImageSparseMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateSamplerYcbcrConversionKHR(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateSamplerYcbcrConversionKHR(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateSamplerYcbcrConversionKHR(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroySamplerYcbcrConversionKHR(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroySamplerYcbcrConversionKHR(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroySamplerYcbcrConversionKHR(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateValidationCacheEXT(VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateValidationCacheEXT(VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateValidationCacheEXT(VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyValidationCacheEXT(VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyValidationCacheEXT(VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyValidationCacheEXT(VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetValidationCacheDataEXT(VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetValidationCacheDataEXT(VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetValidationCacheDataEXT(VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_MergeValidationCachesEXT(VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_MergeValidationCachesEXT(VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_MergeValidationCachesEXT(VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDescriptorSetLayoutSupportKHR(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDescriptorSetLayoutSupportKHR(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDescriptorSetLayoutSupportKHR(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#ifdef VK_USE_PLATFORM_ANDROID_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetSwapchainGrallocUsageANDROID(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, int* grallocUsage) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetSwapchainGrallocUsageANDROID(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, int* grallocUsage) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetSwapchainGrallocUsageANDROID(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, int* grallocUsage) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetSwapchainGrallocUsage2ANDROID(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, VkSwapchainImageUsageFlagsANDROID swapchainImageUsage, uint64_t* grallocConsumerUsage, uint64_t* grallocProducerUsage) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetSwapchainGrallocUsage2ANDROID(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, VkSwapchainImageUsageFlagsANDROID swapchainImageUsage, uint64_t* grallocConsumerUsage, uint64_t* grallocProducerUsage) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetSwapchainGrallocUsage2ANDROID(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, VkSwapchainImageUsageFlagsANDROID swapchainImageUsage, uint64_t* grallocConsumerUsage, uint64_t* grallocProducerUsage) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_AcquireImageANDROID(VkDevice device, VkImage image, int nativeFenceFd, VkSemaphore semaphore, VkFence fence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_AcquireImageANDROID(VkDevice device, VkImage image, int nativeFenceFd, VkSemaphore semaphore, VkFence fence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_AcquireImageANDROID(VkDevice device, VkImage image, int nativeFenceFd, VkSemaphore semaphore, VkFence fence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_QueueSignalReleaseImageANDROID(VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore* pWaitSemaphores, VkImage image, int* pNativeFenceFd) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_QueueSignalReleaseImageANDROID(VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore* pWaitSemaphores, VkImage image, int* pNativeFenceFd) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_QueueSignalReleaseImageANDROID(VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore* pWaitSemaphores, VkImage image, int* pNativeFenceFd) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_ANDROID_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetShaderInfoAMD(VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetShaderInfoAMD(VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetShaderInfoAMD(VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_SetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_SetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_SetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetCalibratedTimestampsKHR(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoKHR* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetCalibratedTimestampsKHR(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoKHR* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetCalibratedTimestampsKHR(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoKHR* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetCalibratedTimestampsEXT(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoKHR* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetCalibratedTimestampsEXT(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoKHR* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetCalibratedTimestampsEXT(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoKHR* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_SetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_SetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_SetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_SetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_SetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_SetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_QueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_QueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_QueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_QueueEndDebugUtilsLabelEXT(VkQueue queue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_QueueEndDebugUtilsLabelEXT(VkQueue queue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_QueueEndDebugUtilsLabelEXT(VkQueue queue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_QueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_QueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_QueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateRenderPass2KHR(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateRenderPass2KHR(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateRenderPass2KHR(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_WaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_WaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_WaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_WaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_WaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_WaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_SignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_SignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_SignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_SignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_SignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_SignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#ifdef VK_USE_PLATFORM_ANDROID_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetAndroidHardwareBufferPropertiesANDROID(VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetAndroidHardwareBufferPropertiesANDROID(VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetAndroidHardwareBufferPropertiesANDROID(VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetMemoryAndroidHardwareBufferANDROID(VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetMemoryAndroidHardwareBufferANDROID(VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetMemoryAndroidHardwareBufferANDROID(VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_ANDROID_KHR
    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetQueueCheckpointDataNV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetQueueCheckpointDataNV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetQueueCheckpointDataNV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CompileDeferredNV(VkDevice device, VkPipeline pipeline, uint32_t shader) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CompileDeferredNV(VkDevice device, VkPipeline pipeline, uint32_t shader) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CompileDeferredNV(VkDevice device, VkPipeline pipeline, uint32_t shader) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateAccelerationStructureNV(VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateAccelerationStructureNV(VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateAccelerationStructureNV(VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyAccelerationStructureKHR(VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyAccelerationStructureKHR(VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyAccelerationStructureKHR(VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyAccelerationStructureNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyAccelerationStructureNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyAccelerationStructureNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetAccelerationStructureMemoryRequirementsNV(VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetAccelerationStructureMemoryRequirementsNV(VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetAccelerationStructureMemoryRequirementsNV(VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_BindAccelerationStructureMemoryNV(VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_BindAccelerationStructureMemoryNV(VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_BindAccelerationStructureMemoryNV(VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CopyAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CopyAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CopyAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CopyAccelerationStructureToMemoryKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CopyAccelerationStructureToMemoryKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CopyAccelerationStructureToMemoryKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CopyMemoryToAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CopyMemoryToAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CopyMemoryToAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_WriteAccelerationStructuresPropertiesKHR(VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, size_t dataSize, void* pData, size_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_WriteAccelerationStructuresPropertiesKHR(VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, size_t dataSize, void* pData, size_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_WriteAccelerationStructuresPropertiesKHR(VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, size_t dataSize, void* pData, size_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdTraceRaysKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdTraceRaysKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdTraceRaysKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetRayTracingShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetRayTracingShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetRayTracingShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetRayTracingShaderGroupHandlesNV(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetRayTracingShaderGroupHandlesNV(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetRayTracingShaderGroupHandlesNV(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetRayTracingCaptureReplayShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetRayTracingCaptureReplayShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetRayTracingCaptureReplayShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetAccelerationStructureHandleNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetAccelerationStructureHandleNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetAccelerationStructureHandleNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateRayTracingPipelinesNV(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateRayTracingPipelinesNV(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateRayTracingPipelinesNV(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateRayTracingPipelinesKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateRayTracingPipelinesKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateRayTracingPipelinesKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetClusterAccelerationStructureBuildSizesNV(VkDevice device, const VkClusterAccelerationStructureInputInfoNV* pInfo, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetClusterAccelerationStructureBuildSizesNV(VkDevice device, const VkClusterAccelerationStructureInputInfoNV* pInfo, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetClusterAccelerationStructureBuildSizesNV(VkDevice device, const VkClusterAccelerationStructureInputInfoNV* pInfo, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBuildClusterAccelerationStructureIndirectNV(VkCommandBuffer commandBuffer, const VkClusterAccelerationStructureCommandsInfoNV* pCommandInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBuildClusterAccelerationStructureIndirectNV(VkCommandBuffer commandBuffer, const VkClusterAccelerationStructureCommandsInfoNV* pCommandInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBuildClusterAccelerationStructureIndirectNV(VkCommandBuffer commandBuffer, const VkClusterAccelerationStructureCommandsInfoNV* pCommandInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDeviceAccelerationStructureCompatibilityKHR(VkDevice device, const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDeviceAccelerationStructureCompatibilityKHR(VkDevice device, const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDeviceAccelerationStructureCompatibilityKHR(VkDevice device, const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkDeviceSize VKAPI_CALL v3dv_GetRayTracingShaderGroupStackSizeKHR(VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkDeviceSize VKAPI_CALL ver42_GetRayTracingShaderGroupStackSizeKHR(VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkDeviceSize VKAPI_CALL ver71_GetRayTracingShaderGroupStackSizeKHR(VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR uint32_t VKAPI_CALL v3dv_GetImageViewHandleNVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR uint32_t VKAPI_CALL ver42_GetImageViewHandleNVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR uint32_t VKAPI_CALL ver71_GetImageViewHandleNVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR uint64_t VKAPI_CALL v3dv_GetImageViewHandle64NVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR uint64_t VKAPI_CALL ver42_GetImageViewHandle64NVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR uint64_t VKAPI_CALL ver71_GetImageViewHandle64NVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetImageViewAddressNVX(VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetImageViewAddressNVX(VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetImageViewAddressNVX(VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#ifdef VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetDeviceGroupSurfacePresentModes2EXT(VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetDeviceGroupSurfacePresentModes2EXT(VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetDeviceGroupSurfacePresentModes2EXT(VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_AcquireFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_AcquireFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_AcquireFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_ReleaseFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_ReleaseFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_ReleaseFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_WIN32_KHR
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_AcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_AcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_AcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_ReleaseProfilingLockKHR(VkDevice device) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_ReleaseProfilingLockKHR(VkDevice device) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_ReleaseProfilingLockKHR(VkDevice device) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR uint64_t VKAPI_CALL v3dv_GetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR uint64_t VKAPI_CALL ver42_GetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR uint64_t VKAPI_CALL ver71_GetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR uint64_t VKAPI_CALL v3dv_GetBufferOpaqueCaptureAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR uint64_t VKAPI_CALL ver42_GetBufferOpaqueCaptureAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR uint64_t VKAPI_CALL ver71_GetBufferOpaqueCaptureAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkDeviceAddress VKAPI_CALL v3dv_GetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkDeviceAddress VKAPI_CALL ver42_GetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkDeviceAddress VKAPI_CALL ver71_GetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkDeviceAddress VKAPI_CALL v3dv_GetBufferDeviceAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkDeviceAddress VKAPI_CALL ver42_GetBufferDeviceAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkDeviceAddress VKAPI_CALL ver71_GetBufferDeviceAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkDeviceAddress VKAPI_CALL v3dv_GetBufferDeviceAddressEXT(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkDeviceAddress VKAPI_CALL ver42_GetBufferDeviceAddressEXT(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkDeviceAddress VKAPI_CALL ver71_GetBufferDeviceAddressEXT(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_InitializePerformanceApiINTEL(VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_InitializePerformanceApiINTEL(VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_InitializePerformanceApiINTEL(VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_UninitializePerformanceApiINTEL(VkDevice device) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_UninitializePerformanceApiINTEL(VkDevice device) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_UninitializePerformanceApiINTEL(VkDevice device) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_AcquirePerformanceConfigurationINTEL(VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_AcquirePerformanceConfigurationINTEL(VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_AcquirePerformanceConfigurationINTEL(VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_ReleasePerformanceConfigurationINTEL(VkDevice device, VkPerformanceConfigurationINTEL configuration) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_ReleasePerformanceConfigurationINTEL(VkDevice device, VkPerformanceConfigurationINTEL configuration) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_ReleasePerformanceConfigurationINTEL(VkDevice device, VkPerformanceConfigurationINTEL configuration) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_QueueSetPerformanceConfigurationINTEL(VkQueue queue, VkPerformanceConfigurationINTEL configuration) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_QueueSetPerformanceConfigurationINTEL(VkQueue queue, VkPerformanceConfigurationINTEL configuration) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_QueueSetPerformanceConfigurationINTEL(VkQueue queue, VkPerformanceConfigurationINTEL configuration) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPerformanceParameterINTEL(VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetPerformanceParameterINTEL(VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetPerformanceParameterINTEL(VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR uint64_t VKAPI_CALL v3dv_GetDeviceMemoryOpaqueCaptureAddress(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR uint64_t VKAPI_CALL ver42_GetDeviceMemoryOpaqueCaptureAddress(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR uint64_t VKAPI_CALL ver71_GetDeviceMemoryOpaqueCaptureAddress(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR uint64_t VKAPI_CALL v3dv_GetDeviceMemoryOpaqueCaptureAddressKHR(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR uint64_t VKAPI_CALL ver42_GetDeviceMemoryOpaqueCaptureAddressKHR(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR uint64_t VKAPI_CALL ver71_GetDeviceMemoryOpaqueCaptureAddressKHR(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPipelineExecutablePropertiesKHR(VkDevice device, const VkPipelineInfoKHR* pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetPipelineExecutablePropertiesKHR(VkDevice device, const VkPipelineInfoKHR* pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetPipelineExecutablePropertiesKHR(VkDevice device, const VkPipelineInfoKHR* pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPipelineExecutableStatisticsKHR(VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetPipelineExecutableStatisticsKHR(VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetPipelineExecutableStatisticsKHR(VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPipelineExecutableInternalRepresentationsKHR(VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetPipelineExecutableInternalRepresentationsKHR(VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetPipelineExecutableInternalRepresentationsKHR(VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetLineStipple(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetLineStipple(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetLineStipple(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateAccelerationStructureKHR(VkDevice device, const VkAccelerationStructureCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureKHR* pAccelerationStructure) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateAccelerationStructureKHR(VkDevice device, const VkAccelerationStructureCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureKHR* pAccelerationStructure) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateAccelerationStructureKHR(VkDevice device, const VkAccelerationStructureCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureKHR* pAccelerationStructure) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBuildAccelerationStructuresKHR(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBuildAccelerationStructuresKHR(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBuildAccelerationStructuresKHR(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides, const uint32_t* const* ppMaxPrimitiveCounts) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides, const uint32_t* const* ppMaxPrimitiveCounts) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides, const uint32_t* const* ppMaxPrimitiveCounts) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_BuildAccelerationStructuresKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_BuildAccelerationStructuresKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_BuildAccelerationStructuresKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkDeviceAddress VKAPI_CALL v3dv_GetAccelerationStructureDeviceAddressKHR(VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkDeviceAddress VKAPI_CALL ver42_GetAccelerationStructureDeviceAddressKHR(VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkDeviceAddress VKAPI_CALL ver71_GetAccelerationStructureDeviceAddressKHR(VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateDeferredOperationKHR(VkDevice device, const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateDeferredOperationKHR(VkDevice device, const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateDeferredOperationKHR(VkDevice device, const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyDeferredOperationKHR(VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyDeferredOperationKHR(VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyDeferredOperationKHR(VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR uint32_t VKAPI_CALL v3dv_GetDeferredOperationMaxConcurrencyKHR(VkDevice device, VkDeferredOperationKHR operation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR uint32_t VKAPI_CALL ver42_GetDeferredOperationMaxConcurrencyKHR(VkDevice device, VkDeferredOperationKHR operation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR uint32_t VKAPI_CALL ver71_GetDeferredOperationMaxConcurrencyKHR(VkDevice device, VkDeferredOperationKHR operation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetDeferredOperationResultKHR(VkDevice device, VkDeferredOperationKHR operation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetDeferredOperationResultKHR(VkDevice device, VkDeferredOperationKHR operation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetDeferredOperationResultKHR(VkDevice device, VkDeferredOperationKHR operation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_DeferredOperationJoinKHR(VkDevice device, VkDeferredOperationKHR operation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_DeferredOperationJoinKHR(VkDevice device, VkDeferredOperationKHR operation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_DeferredOperationJoinKHR(VkDevice device, VkDeferredOperationKHR operation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetPipelineIndirectMemoryRequirementsNV(VkDevice device, const VkComputePipelineCreateInfo* pCreateInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetPipelineIndirectMemoryRequirementsNV(VkDevice device, const VkComputePipelineCreateInfo* pCreateInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetPipelineIndirectMemoryRequirementsNV(VkDevice device, const VkComputePipelineCreateInfo* pCreateInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkDeviceAddress VKAPI_CALL v3dv_GetPipelineIndirectDeviceAddressNV(VkDevice device, const VkPipelineIndirectDeviceAddressInfoNV* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkDeviceAddress VKAPI_CALL ver42_GetPipelineIndirectDeviceAddressNV(VkDevice device, const VkPipelineIndirectDeviceAddressInfoNV* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkDeviceAddress VKAPI_CALL ver71_GetPipelineIndirectDeviceAddressNV(VkDevice device, const VkPipelineIndirectDeviceAddressInfoNV* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_AntiLagUpdateAMD(VkDevice device, const VkAntiLagDataAMD* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_AntiLagUpdateAMD(VkDevice device, const VkAntiLagDataAMD* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_AntiLagUpdateAMD(VkDevice device, const VkAntiLagDataAMD* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindIndexBuffer2(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindIndexBuffer2(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindIndexBuffer2(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits rasterizationSamples) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits rasterizationSamples) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits rasterizationSamples) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples, const VkSampleMask* pSampleMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples, const VkSampleMask* pSampleMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples, const VkSampleMask* pSampleMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkBool32* pColorBlendEnables) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkBool32* pColorBlendEnables) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkBool32* pColorBlendEnables) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendEquationEXT* pColorBlendEquations) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendEquationEXT* pColorBlendEquations) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendEquationEXT* pColorBlendEquations) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetConservativeRasterizationModeEXT(VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetConservativeRasterizationModeEXT(VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetConservativeRasterizationModeEXT(VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendAdvancedEXT* pColorBlendAdvanced) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendAdvancedEXT* pColorBlendAdvanced) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendAdvancedEXT* pColorBlendAdvanced) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreatePrivateDataSlot(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreatePrivateDataSlot(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreatePrivateDataSlot(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyPrivateDataSlot(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyPrivateDataSlot(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyPrivateDataSlot(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_SetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_SetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_SetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_SetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_SetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_SetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetAccelerationStructureBuildSizesKHR(VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo, const uint32_t* pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetAccelerationStructureBuildSizesKHR(VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo, const uint32_t* pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetAccelerationStructureBuildSizesKHR(VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo, const uint32_t* pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkBool32* pColorWriteEnables) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkBool32* pColorWriteEnables) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkBool32* pColorWriteEnables) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_QueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_QueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_QueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetQueueCheckpointData2NV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetQueueCheckpointData2NV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetQueueCheckpointData2NV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CopyMemoryToImage(VkDevice device, const VkCopyMemoryToImageInfo* pCopyMemoryToImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CopyMemoryToImage(VkDevice device, const VkCopyMemoryToImageInfo* pCopyMemoryToImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CopyMemoryToImage(VkDevice device, const VkCopyMemoryToImageInfo* pCopyMemoryToImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CopyMemoryToImageEXT(VkDevice device, const VkCopyMemoryToImageInfo* pCopyMemoryToImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CopyMemoryToImageEXT(VkDevice device, const VkCopyMemoryToImageInfo* pCopyMemoryToImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CopyMemoryToImageEXT(VkDevice device, const VkCopyMemoryToImageInfo* pCopyMemoryToImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CopyImageToMemory(VkDevice device, const VkCopyImageToMemoryInfo* pCopyImageToMemoryInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CopyImageToMemory(VkDevice device, const VkCopyImageToMemoryInfo* pCopyImageToMemoryInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CopyImageToMemory(VkDevice device, const VkCopyImageToMemoryInfo* pCopyImageToMemoryInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CopyImageToMemoryEXT(VkDevice device, const VkCopyImageToMemoryInfo* pCopyImageToMemoryInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CopyImageToMemoryEXT(VkDevice device, const VkCopyImageToMemoryInfo* pCopyImageToMemoryInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CopyImageToMemoryEXT(VkDevice device, const VkCopyImageToMemoryInfo* pCopyImageToMemoryInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CopyImageToImage(VkDevice device, const VkCopyImageToImageInfo* pCopyImageToImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CopyImageToImage(VkDevice device, const VkCopyImageToImageInfo* pCopyImageToImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CopyImageToImage(VkDevice device, const VkCopyImageToImageInfo* pCopyImageToImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CopyImageToImageEXT(VkDevice device, const VkCopyImageToImageInfo* pCopyImageToImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CopyImageToImageEXT(VkDevice device, const VkCopyImageToImageInfo* pCopyImageToImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CopyImageToImageEXT(VkDevice device, const VkCopyImageToImageInfo* pCopyImageToImageInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_TransitionImageLayout(VkDevice device, uint32_t transitionCount, const VkHostImageLayoutTransitionInfo* pTransitions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_TransitionImageLayout(VkDevice device, uint32_t transitionCount, const VkHostImageLayoutTransitionInfo* pTransitions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_TransitionImageLayout(VkDevice device, uint32_t transitionCount, const VkHostImageLayoutTransitionInfo* pTransitions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_TransitionImageLayoutEXT(VkDevice device, uint32_t transitionCount, const VkHostImageLayoutTransitionInfo* pTransitions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_TransitionImageLayoutEXT(VkDevice device, uint32_t transitionCount, const VkHostImageLayoutTransitionInfo* pTransitions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_TransitionImageLayoutEXT(VkDevice device, uint32_t transitionCount, const VkHostImageLayoutTransitionInfo* pTransitions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateVideoSessionKHR(VkDevice device, const VkVideoSessionCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionKHR* pVideoSession) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateVideoSessionKHR(VkDevice device, const VkVideoSessionCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionKHR* pVideoSession) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateVideoSessionKHR(VkDevice device, const VkVideoSessionCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionKHR* pVideoSession) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyVideoSessionKHR(VkDevice device, VkVideoSessionKHR videoSession, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyVideoSessionKHR(VkDevice device, VkVideoSessionKHR videoSession, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyVideoSessionKHR(VkDevice device, VkVideoSessionKHR videoSession, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateVideoSessionParametersKHR(VkDevice device, const VkVideoSessionParametersCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionParametersKHR* pVideoSessionParameters) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateVideoSessionParametersKHR(VkDevice device, const VkVideoSessionParametersCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionParametersKHR* pVideoSessionParameters) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateVideoSessionParametersKHR(VkDevice device, const VkVideoSessionParametersCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionParametersKHR* pVideoSessionParameters) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_UpdateVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_UpdateVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_UpdateVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetEncodedVideoSessionParametersKHR(VkDevice device, const VkVideoEncodeSessionParametersGetInfoKHR* pVideoSessionParametersInfo, VkVideoEncodeSessionParametersFeedbackInfoKHR* pFeedbackInfo, size_t* pDataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetEncodedVideoSessionParametersKHR(VkDevice device, const VkVideoEncodeSessionParametersGetInfoKHR* pVideoSessionParametersInfo, VkVideoEncodeSessionParametersFeedbackInfoKHR* pFeedbackInfo, size_t* pDataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetEncodedVideoSessionParametersKHR(VkDevice device, const VkVideoEncodeSessionParametersGetInfoKHR* pVideoSessionParametersInfo, VkVideoEncodeSessionParametersFeedbackInfoKHR* pFeedbackInfo, size_t* pDataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetVideoSessionMemoryRequirementsKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t* pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetVideoSessionMemoryRequirementsKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t* pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetVideoSessionMemoryRequirementsKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t* pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_BindVideoSessionMemoryKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_BindVideoSessionMemoryKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_BindVideoSessionMemoryKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdControlVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdControlVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdControlVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount, const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount, const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount, const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress, VkDeviceAddress indirectCommandsCountAddress, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress, VkDeviceAddress indirectCommandsCountAddress, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress, VkDeviceAddress indirectCommandsCountAddress, uint32_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetPartitionedAccelerationStructuresBuildSizesNV(VkDevice device, const VkPartitionedAccelerationStructureInstancesInputNV* pInfo, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetPartitionedAccelerationStructuresBuildSizesNV(VkDevice device, const VkPartitionedAccelerationStructureInstancesInputNV* pInfo, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetPartitionedAccelerationStructuresBuildSizesNV(VkDevice device, const VkPartitionedAccelerationStructureInstancesInputNV* pInfo, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBuildPartitionedAccelerationStructuresNV(VkCommandBuffer commandBuffer, const VkBuildPartitionedAccelerationStructureInfoNV* pBuildInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBuildPartitionedAccelerationStructuresNV(VkCommandBuffer commandBuffer, const VkBuildPartitionedAccelerationStructureInfoNV* pBuildInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBuildPartitionedAccelerationStructuresNV(VkCommandBuffer commandBuffer, const VkBuildPartitionedAccelerationStructureInfoNV* pBuildInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateCuModuleNVX(VkDevice device, const VkCuModuleCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuModuleNVX* pModule) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateCuModuleNVX(VkDevice device, const VkCuModuleCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuModuleNVX* pModule) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateCuModuleNVX(VkDevice device, const VkCuModuleCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuModuleNVX* pModule) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateCuFunctionNVX(VkDevice device, const VkCuFunctionCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuFunctionNVX* pFunction) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateCuFunctionNVX(VkDevice device, const VkCuFunctionCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuFunctionNVX* pFunction) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateCuFunctionNVX(VkDevice device, const VkCuFunctionCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuFunctionNVX* pFunction) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyCuModuleNVX(VkDevice device, VkCuModuleNVX module, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyCuModuleNVX(VkDevice device, VkCuModuleNVX module, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyCuModuleNVX(VkDevice device, VkCuModuleNVX module, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyCuFunctionNVX(VkDevice device, VkCuFunctionNVX function, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyCuFunctionNVX(VkDevice device, VkCuFunctionNVX function, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyCuFunctionNVX(VkDevice device, VkCuFunctionNVX function, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDescriptorSetLayoutSizeEXT(VkDevice device, VkDescriptorSetLayout layout, VkDeviceSize* pLayoutSizeInBytes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDescriptorSetLayoutSizeEXT(VkDevice device, VkDescriptorSetLayout layout, VkDeviceSize* pLayoutSizeInBytes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDescriptorSetLayoutSizeEXT(VkDevice device, VkDescriptorSetLayout layout, VkDeviceSize* pLayoutSizeInBytes) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDescriptorSetLayoutBindingOffsetEXT(VkDevice device, VkDescriptorSetLayout layout, uint32_t binding, VkDeviceSize* pOffset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDescriptorSetLayoutBindingOffsetEXT(VkDevice device, VkDescriptorSetLayout layout, uint32_t binding, VkDeviceSize* pOffset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDescriptorSetLayoutBindingOffsetEXT(VkDevice device, VkDescriptorSetLayout layout, uint32_t binding, VkDeviceSize* pOffset) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDescriptorEXT(VkDevice device, const VkDescriptorGetInfoEXT* pDescriptorInfo, size_t dataSize, void* pDescriptor) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDescriptorEXT(VkDevice device, const VkDescriptorGetInfoEXT* pDescriptorInfo, size_t dataSize, void* pDescriptor) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDescriptorEXT(VkDevice device, const VkDescriptorGetInfoEXT* pDescriptorInfo, size_t dataSize, void* pDescriptor) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount, const VkDescriptorBufferBindingInfoEXT* pBindingInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount, const VkDescriptorBufferBindingInfoEXT* pBindingInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount, const VkDescriptorBufferBindingInfoEXT* pBindingInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount, const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount, const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount, const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetBufferOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkBufferCaptureDescriptorDataInfoEXT* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetBufferOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkBufferCaptureDescriptorDataInfoEXT* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetBufferOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkBufferCaptureDescriptorDataInfoEXT* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetImageOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageCaptureDescriptorDataInfoEXT* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetImageOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageCaptureDescriptorDataInfoEXT* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetImageOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageCaptureDescriptorDataInfoEXT* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetImageViewOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageViewCaptureDescriptorDataInfoEXT* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetImageViewOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageViewCaptureDescriptorDataInfoEXT* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetImageViewOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageViewCaptureDescriptorDataInfoEXT* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetSamplerOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkSamplerCaptureDescriptorDataInfoEXT* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetSamplerOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkSamplerCaptureDescriptorDataInfoEXT* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetSamplerOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkSamplerCaptureDescriptorDataInfoEXT* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetAccelerationStructureOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkAccelerationStructureCaptureDescriptorDataInfoEXT* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetAccelerationStructureOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkAccelerationStructureCaptureDescriptorDataInfoEXT* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetAccelerationStructureOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkAccelerationStructureCaptureDescriptorDataInfoEXT* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_SetDeviceMemoryPriorityEXT(VkDevice device, VkDeviceMemory memory, float priority) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_SetDeviceMemoryPriorityEXT(VkDevice device, VkDeviceMemory memory, float priority) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_SetDeviceMemoryPriorityEXT(VkDevice device, VkDeviceMemory memory, float priority) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_WaitForPresent2KHR(VkDevice device, VkSwapchainKHR swapchain, const VkPresentWait2InfoKHR* pPresentWait2Info) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_WaitForPresent2KHR(VkDevice device, VkSwapchainKHR swapchain, const VkPresentWait2InfoKHR* pPresentWait2Info) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_WaitForPresent2KHR(VkDevice device, VkSwapchainKHR swapchain, const VkPresentWait2InfoKHR* pPresentWait2Info) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_WaitForPresentKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t presentId, uint64_t timeout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_WaitForPresentKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t presentId, uint64_t timeout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_WaitForPresentKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t presentId, uint64_t timeout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#ifdef VK_USE_PLATFORM_FUCHSIA
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateBufferCollectionFUCHSIA(VkDevice device, const VkBufferCollectionCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferCollectionFUCHSIA* pCollection) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateBufferCollectionFUCHSIA(VkDevice device, const VkBufferCollectionCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferCollectionFUCHSIA* pCollection) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateBufferCollectionFUCHSIA(VkDevice device, const VkBufferCollectionCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferCollectionFUCHSIA* pCollection) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_SetBufferCollectionBufferConstraintsFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkBufferConstraintsInfoFUCHSIA* pBufferConstraintsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_SetBufferCollectionBufferConstraintsFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkBufferConstraintsInfoFUCHSIA* pBufferConstraintsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_SetBufferCollectionBufferConstraintsFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkBufferConstraintsInfoFUCHSIA* pBufferConstraintsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_SetBufferCollectionImageConstraintsFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkImageConstraintsInfoFUCHSIA* pImageConstraintsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_SetBufferCollectionImageConstraintsFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkImageConstraintsInfoFUCHSIA* pImageConstraintsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_SetBufferCollectionImageConstraintsFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkImageConstraintsInfoFUCHSIA* pImageConstraintsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyBufferCollectionFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyBufferCollectionFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyBufferCollectionFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetBufferCollectionPropertiesFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, VkBufferCollectionPropertiesFUCHSIA* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetBufferCollectionPropertiesFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, VkBufferCollectionPropertiesFUCHSIA* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetBufferCollectionPropertiesFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, VkBufferCollectionPropertiesFUCHSIA* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_FUCHSIA
    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdEndRendering(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdEndRendering(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdEndRendering(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdEndRendering2EXT(VkCommandBuffer commandBuffer, const VkRenderingEndInfoEXT* pRenderingEndInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdEndRendering2EXT(VkCommandBuffer commandBuffer, const VkRenderingEndInfoEXT* pRenderingEndInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdEndRendering2EXT(VkCommandBuffer commandBuffer, const VkRenderingEndInfoEXT* pRenderingEndInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdEndRenderingKHR(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdEndRenderingKHR(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdEndRenderingKHR(VkCommandBuffer commandBuffer) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDescriptorSetLayoutHostMappingInfoVALVE(VkDevice device, const VkDescriptorSetBindingReferenceVALVE* pBindingReference, VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDescriptorSetLayoutHostMappingInfoVALVE(VkDevice device, const VkDescriptorSetBindingReferenceVALVE* pBindingReference, VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDescriptorSetLayoutHostMappingInfoVALVE(VkDevice device, const VkDescriptorSetBindingReferenceVALVE* pBindingReference, VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDescriptorSetHostMappingVALVE(VkDevice device, VkDescriptorSet descriptorSet, void** ppData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDescriptorSetHostMappingVALVE(VkDevice device, VkDescriptorSet descriptorSet, void** ppData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDescriptorSetHostMappingVALVE(VkDevice device, VkDescriptorSet descriptorSet, void** ppData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateMicromapEXT(VkDevice device, const VkMicromapCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkMicromapEXT* pMicromap) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateMicromapEXT(VkDevice device, const VkMicromapCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkMicromapEXT* pMicromap) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateMicromapEXT(VkDevice device, const VkMicromapCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkMicromapEXT* pMicromap) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_BuildMicromapsEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_BuildMicromapsEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_BuildMicromapsEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyMicromapEXT(VkDevice device, VkMicromapEXT micromap, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyMicromapEXT(VkDevice device, VkMicromapEXT micromap, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyMicromapEXT(VkDevice device, VkMicromapEXT micromap, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CopyMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapInfoEXT* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CopyMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapInfoEXT* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CopyMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapInfoEXT* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CopyMicromapToMemoryEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapToMemoryInfoEXT* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CopyMicromapToMemoryEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapToMemoryInfoEXT* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CopyMicromapToMemoryEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapToMemoryInfoEXT* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CopyMemoryToMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToMicromapInfoEXT* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CopyMemoryToMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToMicromapInfoEXT* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CopyMemoryToMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToMicromapInfoEXT* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_WriteMicromapsPropertiesEXT(VkDevice device, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, size_t dataSize, void* pData, size_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_WriteMicromapsPropertiesEXT(VkDevice device, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, size_t dataSize, void* pData, size_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_WriteMicromapsPropertiesEXT(VkDevice device, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, size_t dataSize, void* pData, size_t stride) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDeviceMicromapCompatibilityEXT(VkDevice device, const VkMicromapVersionInfoEXT* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDeviceMicromapCompatibilityEXT(VkDevice device, const VkMicromapVersionInfoEXT* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDeviceMicromapCompatibilityEXT(VkDevice device, const VkMicromapVersionInfoEXT* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetMicromapBuildSizesEXT(VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkMicromapBuildInfoEXT* pBuildInfo, VkMicromapBuildSizesInfoEXT* pSizeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetMicromapBuildSizesEXT(VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkMicromapBuildInfoEXT* pBuildInfo, VkMicromapBuildSizesInfoEXT* pSizeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetMicromapBuildSizesEXT(VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkMicromapBuildInfoEXT* pBuildInfo, VkMicromapBuildSizesInfoEXT* pSizeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetShaderModuleIdentifierEXT(VkDevice device, VkShaderModule shaderModule, VkShaderModuleIdentifierEXT* pIdentifier) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetShaderModuleIdentifierEXT(VkDevice device, VkShaderModule shaderModule, VkShaderModuleIdentifierEXT* pIdentifier) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetShaderModuleIdentifierEXT(VkDevice device, VkShaderModule shaderModule, VkShaderModuleIdentifierEXT* pIdentifier) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetShaderModuleCreateInfoIdentifierEXT(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModuleIdentifierEXT* pIdentifier) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetShaderModuleCreateInfoIdentifierEXT(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModuleIdentifierEXT* pIdentifier) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetShaderModuleCreateInfoIdentifierEXT(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModuleIdentifierEXT* pIdentifier) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetImageSubresourceLayout2(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetImageSubresourceLayout2(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetImageSubresourceLayout2(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetImageSubresourceLayout2KHR(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetImageSubresourceLayout2KHR(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetImageSubresourceLayout2KHR(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetImageSubresourceLayout2EXT(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetImageSubresourceLayout2EXT(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetImageSubresourceLayout2EXT(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetPipelinePropertiesEXT(VkDevice device, const VkPipelineInfoEXT* pPipelineInfo, VkBaseOutStructure* pPipelineProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetPipelinePropertiesEXT(VkDevice device, const VkPipelineInfoEXT* pPipelineInfo, VkBaseOutStructure* pPipelineProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetPipelinePropertiesEXT(VkDevice device, const VkPipelineInfoEXT* pPipelineInfo, VkBaseOutStructure* pPipelineProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#ifdef VK_USE_PLATFORM_METAL_EXT
    VKAPI_ATTR void VKAPI_CALL v3dv_ExportMetalObjectsEXT(VkDevice device, VkExportMetalObjectsInfoEXT* pMetalObjectsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_ExportMetalObjectsEXT(VkDevice device, VkExportMetalObjectsInfoEXT* pMetalObjectsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_ExportMetalObjectsEXT(VkDevice device, VkExportMetalObjectsInfoEXT* pMetalObjectsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_METAL_EXT
    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindTileMemoryQCOM(VkCommandBuffer commandBuffer, const VkTileMemoryBindInfoQCOM* pTileMemoryBindInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindTileMemoryQCOM(VkCommandBuffer commandBuffer, const VkTileMemoryBindInfoQCOM* pTileMemoryBindInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindTileMemoryQCOM(VkCommandBuffer commandBuffer, const VkTileMemoryBindInfoQCOM* pTileMemoryBindInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetFramebufferTilePropertiesQCOM(VkDevice device, VkFramebuffer framebuffer, uint32_t* pPropertiesCount, VkTilePropertiesQCOM* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetFramebufferTilePropertiesQCOM(VkDevice device, VkFramebuffer framebuffer, uint32_t* pPropertiesCount, VkTilePropertiesQCOM* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetFramebufferTilePropertiesQCOM(VkDevice device, VkFramebuffer framebuffer, uint32_t* pPropertiesCount, VkTilePropertiesQCOM* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetDynamicRenderingTilePropertiesQCOM(VkDevice device, const VkRenderingInfo* pRenderingInfo, VkTilePropertiesQCOM* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetDynamicRenderingTilePropertiesQCOM(VkDevice device, const VkRenderingInfo* pRenderingInfo, VkTilePropertiesQCOM* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetDynamicRenderingTilePropertiesQCOM(VkDevice device, const VkRenderingInfo* pRenderingInfo, VkTilePropertiesQCOM* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateOpticalFlowSessionNV(VkDevice device, const VkOpticalFlowSessionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkOpticalFlowSessionNV* pSession) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateOpticalFlowSessionNV(VkDevice device, const VkOpticalFlowSessionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkOpticalFlowSessionNV* pSession) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateOpticalFlowSessionNV(VkDevice device, const VkOpticalFlowSessionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkOpticalFlowSessionNV* pSession) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyOpticalFlowSessionNV(VkDevice device, VkOpticalFlowSessionNV session, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyOpticalFlowSessionNV(VkDevice device, VkOpticalFlowSessionNV session, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyOpticalFlowSessionNV(VkDevice device, VkOpticalFlowSessionNV session, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_BindOpticalFlowSessionImageNV(VkDevice device, VkOpticalFlowSessionNV session, VkOpticalFlowSessionBindingPointNV bindingPoint, VkImageView view, VkImageLayout layout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_BindOpticalFlowSessionImageNV(VkDevice device, VkOpticalFlowSessionNV session, VkOpticalFlowSessionBindingPointNV bindingPoint, VkImageView view, VkImageLayout layout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_BindOpticalFlowSessionImageNV(VkDevice device, VkOpticalFlowSessionNV session, VkOpticalFlowSessionBindingPointNV bindingPoint, VkImageView view, VkImageLayout layout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV* pExecuteInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV* pExecuteInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV* pExecuteInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetDeviceFaultInfoEXT(VkDevice device, VkDeviceFaultCountsEXT* pFaultCounts, VkDeviceFaultInfoEXT* pFaultInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetDeviceFaultInfoEXT(VkDevice device, VkDeviceFaultCountsEXT* pFaultCounts, VkDeviceFaultInfoEXT* pFaultInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetDeviceFaultInfoEXT(VkDevice device, VkDeviceFaultCountsEXT* pFaultCounts, VkDeviceFaultInfoEXT* pFaultInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_ReleaseSwapchainImagesKHR(VkDevice device, const VkReleaseSwapchainImagesInfoKHR* pReleaseInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_ReleaseSwapchainImagesKHR(VkDevice device, const VkReleaseSwapchainImagesInfoKHR* pReleaseInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_ReleaseSwapchainImagesKHR(VkDevice device, const VkReleaseSwapchainImagesInfoKHR* pReleaseInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_ReleaseSwapchainImagesEXT(VkDevice device, const VkReleaseSwapchainImagesInfoKHR* pReleaseInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_ReleaseSwapchainImagesEXT(VkDevice device, const VkReleaseSwapchainImagesInfoKHR* pReleaseInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_ReleaseSwapchainImagesEXT(VkDevice device, const VkReleaseSwapchainImagesInfoKHR* pReleaseInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDeviceImageSubresourceLayout(VkDevice device, const VkDeviceImageSubresourceInfo* pInfo, VkSubresourceLayout2* pLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDeviceImageSubresourceLayout(VkDevice device, const VkDeviceImageSubresourceInfo* pInfo, VkSubresourceLayout2* pLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDeviceImageSubresourceLayout(VkDevice device, const VkDeviceImageSubresourceInfo* pInfo, VkSubresourceLayout2* pLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDeviceImageSubresourceLayoutKHR(VkDevice device, const VkDeviceImageSubresourceInfo* pInfo, VkSubresourceLayout2* pLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDeviceImageSubresourceLayoutKHR(VkDevice device, const VkDeviceImageSubresourceInfo* pInfo, VkSubresourceLayout2* pLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDeviceImageSubresourceLayoutKHR(VkDevice device, const VkDeviceImageSubresourceInfo* pInfo, VkSubresourceLayout2* pLayout) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_MapMemory2(VkDevice device, const VkMemoryMapInfo* pMemoryMapInfo, void** ppData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_MapMemory2(VkDevice device, const VkMemoryMapInfo* pMemoryMapInfo, void** ppData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_MapMemory2(VkDevice device, const VkMemoryMapInfo* pMemoryMapInfo, void** ppData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_MapMemory2KHR(VkDevice device, const VkMemoryMapInfo* pMemoryMapInfo, void** ppData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_MapMemory2KHR(VkDevice device, const VkMemoryMapInfo* pMemoryMapInfo, void** ppData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_MapMemory2KHR(VkDevice device, const VkMemoryMapInfo* pMemoryMapInfo, void** ppData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_UnmapMemory2(VkDevice device, const VkMemoryUnmapInfo* pMemoryUnmapInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_UnmapMemory2(VkDevice device, const VkMemoryUnmapInfo* pMemoryUnmapInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_UnmapMemory2(VkDevice device, const VkMemoryUnmapInfo* pMemoryUnmapInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_UnmapMemory2KHR(VkDevice device, const VkMemoryUnmapInfo* pMemoryUnmapInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_UnmapMemory2KHR(VkDevice device, const VkMemoryUnmapInfo* pMemoryUnmapInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_UnmapMemory2KHR(VkDevice device, const VkMemoryUnmapInfo* pMemoryUnmapInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateShadersEXT(VkDevice device, uint32_t createInfoCount, const VkShaderCreateInfoEXT* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkShaderEXT* pShaders) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateShadersEXT(VkDevice device, uint32_t createInfoCount, const VkShaderCreateInfoEXT* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkShaderEXT* pShaders) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateShadersEXT(VkDevice device, uint32_t createInfoCount, const VkShaderCreateInfoEXT* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkShaderEXT* pShaders) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyShaderEXT(VkDevice device, VkShaderEXT shader, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyShaderEXT(VkDevice device, VkShaderEXT shader, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyShaderEXT(VkDevice device, VkShaderEXT shader, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetShaderBinaryDataEXT(VkDevice device, VkShaderEXT shader, size_t* pDataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetShaderBinaryDataEXT(VkDevice device, VkShaderEXT shader, size_t* pDataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetShaderBinaryDataEXT(VkDevice device, VkShaderEXT shader, size_t* pDataSize, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#ifdef VK_USE_PLATFORM_SCREEN_QNX
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetScreenBufferPropertiesQNX(VkDevice device, const struct _screen_buffer* buffer, VkScreenBufferPropertiesQNX* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetScreenBufferPropertiesQNX(VkDevice device, const struct _screen_buffer* buffer, VkScreenBufferPropertiesQNX* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetScreenBufferPropertiesQNX(VkDevice device, const struct _screen_buffer* buffer, VkScreenBufferPropertiesQNX* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_SCREEN_QNX
    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindDescriptorSets2(VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfo* pBindDescriptorSetsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindDescriptorSets2(VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfo* pBindDescriptorSetsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindDescriptorSets2(VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfo* pBindDescriptorSetsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfo* pBindDescriptorSetsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfo* pBindDescriptorSetsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfo* pBindDescriptorSetsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdPushConstants2(VkCommandBuffer commandBuffer, const VkPushConstantsInfo* pPushConstantsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdPushConstants2(VkCommandBuffer commandBuffer, const VkPushConstantsInfo* pPushConstantsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdPushConstants2(VkCommandBuffer commandBuffer, const VkPushConstantsInfo* pPushConstantsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdPushConstants2KHR(VkCommandBuffer commandBuffer, const VkPushConstantsInfo* pPushConstantsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdPushConstants2KHR(VkCommandBuffer commandBuffer, const VkPushConstantsInfo* pPushConstantsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdPushConstants2KHR(VkCommandBuffer commandBuffer, const VkPushConstantsInfo* pPushConstantsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdPushDescriptorSet2(VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfo* pPushDescriptorSetInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdPushDescriptorSet2(VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfo* pPushDescriptorSetInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdPushDescriptorSet2(VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfo* pPushDescriptorSetInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfo* pPushDescriptorSetInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfo* pPushDescriptorSetInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfo* pPushDescriptorSetInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdPushDescriptorSetWithTemplate2(VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfo* pPushDescriptorSetWithTemplateInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdPushDescriptorSetWithTemplate2(VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfo* pPushDescriptorSetWithTemplateInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdPushDescriptorSetWithTemplate2(VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfo* pPushDescriptorSetWithTemplateInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdPushDescriptorSetWithTemplate2KHR(VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfo* pPushDescriptorSetWithTemplateInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdPushDescriptorSetWithTemplate2KHR(VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfo* pPushDescriptorSetWithTemplateInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdPushDescriptorSetWithTemplate2KHR(VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfo* pPushDescriptorSetWithTemplateInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDescriptorBufferOffsets2EXT(VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDescriptorBufferOffsets2EXT(VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDescriptorBufferOffsets2EXT(VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBindDescriptorBufferEmbeddedSamplers2EXT(VkCommandBuffer commandBuffer, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBindDescriptorBufferEmbeddedSamplers2EXT(VkCommandBuffer commandBuffer, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBindDescriptorBufferEmbeddedSamplers2EXT(VkCommandBuffer commandBuffer, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_SetLatencySleepModeNV(VkDevice device, VkSwapchainKHR swapchain, const VkLatencySleepModeInfoNV* pSleepModeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_SetLatencySleepModeNV(VkDevice device, VkSwapchainKHR swapchain, const VkLatencySleepModeInfoNV* pSleepModeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_SetLatencySleepModeNV(VkDevice device, VkSwapchainKHR swapchain, const VkLatencySleepModeInfoNV* pSleepModeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_LatencySleepNV(VkDevice device, VkSwapchainKHR swapchain, const VkLatencySleepInfoNV* pSleepInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_LatencySleepNV(VkDevice device, VkSwapchainKHR swapchain, const VkLatencySleepInfoNV* pSleepInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_LatencySleepNV(VkDevice device, VkSwapchainKHR swapchain, const VkLatencySleepInfoNV* pSleepInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_SetLatencyMarkerNV(VkDevice device, VkSwapchainKHR swapchain, const VkSetLatencyMarkerInfoNV* pLatencyMarkerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_SetLatencyMarkerNV(VkDevice device, VkSwapchainKHR swapchain, const VkSetLatencyMarkerInfoNV* pLatencyMarkerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_SetLatencyMarkerNV(VkDevice device, VkSwapchainKHR swapchain, const VkSetLatencyMarkerInfoNV* pLatencyMarkerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetLatencyTimingsNV(VkDevice device, VkSwapchainKHR swapchain, VkGetLatencyMarkerInfoNV* pLatencyMarkerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetLatencyTimingsNV(VkDevice device, VkSwapchainKHR swapchain, VkGetLatencyMarkerInfoNV* pLatencyMarkerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetLatencyTimingsNV(VkDevice device, VkSwapchainKHR swapchain, VkGetLatencyMarkerInfoNV* pLatencyMarkerInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_QueueNotifyOutOfBandNV(VkQueue queue, const VkOutOfBandQueueTypeInfoNV* pQueueTypeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_QueueNotifyOutOfBandNV(VkQueue queue, const VkOutOfBandQueueTypeInfoNV* pQueueTypeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_QueueNotifyOutOfBandNV(VkQueue queue, const VkOutOfBandQueueTypeInfoNV* pQueueTypeInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetRenderingAttachmentLocations(VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfo* pLocationInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetRenderingAttachmentLocations(VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfo* pLocationInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetRenderingAttachmentLocations(VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfo* pLocationInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfo* pLocationInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfo* pLocationInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfo* pLocationInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetRenderingInputAttachmentIndices(VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetRenderingInputAttachmentIndices(VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetRenderingInputAttachmentIndices(VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetRenderingInputAttachmentIndicesKHR(VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetRenderingInputAttachmentIndicesKHR(VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetRenderingInputAttachmentIndicesKHR(VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode, const VkDepthClampRangeEXT* pDepthClampRange) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode, const VkDepthClampRangeEXT* pDepthClampRange) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode, const VkDepthClampRangeEXT* pDepthClampRange) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#ifdef VK_USE_PLATFORM_METAL_EXT
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetMemoryMetalHandleEXT(VkDevice device, const VkMemoryGetMetalHandleInfoEXT* pGetMetalHandleInfo, void** pHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetMemoryMetalHandleEXT(VkDevice device, const VkMemoryGetMetalHandleInfoEXT* pGetMetalHandleInfo, void** pHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetMemoryMetalHandleEXT(VkDevice device, const VkMemoryGetMetalHandleInfoEXT* pGetMetalHandleInfo, void** pHandle) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetMemoryMetalHandlePropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHandle, VkMemoryMetalHandlePropertiesEXT* pMemoryMetalHandleProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetMemoryMetalHandlePropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHandle, VkMemoryMetalHandlePropertiesEXT* pMemoryMetalHandleProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetMemoryMetalHandlePropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHandle, VkMemoryMetalHandlePropertiesEXT* pMemoryMetalHandleProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#endif // VK_USE_PLATFORM_METAL_EXT
    VKAPI_ATTR VkResult VKAPI_CALL v3dv_ConvertCooperativeVectorMatrixNV(VkDevice device, const VkConvertCooperativeVectorMatrixInfoNV* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_ConvertCooperativeVectorMatrixNV(VkDevice device, const VkConvertCooperativeVectorMatrixInfoNV* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_ConvertCooperativeVectorMatrixNV(VkDevice device, const VkConvertCooperativeVectorMatrixInfoNV* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdConvertCooperativeVectorMatrixNV(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkConvertCooperativeVectorMatrixInfoNV* pInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdConvertCooperativeVectorMatrixNV(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkConvertCooperativeVectorMatrixInfoNV* pInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdConvertCooperativeVectorMatrixNV(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkConvertCooperativeVectorMatrixInfoNV* pInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDispatchTileQCOM(VkCommandBuffer commandBuffer, const VkDispatchTileInfoQCOM* pDispatchTileInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDispatchTileQCOM(VkCommandBuffer commandBuffer, const VkDispatchTileInfoQCOM* pDispatchTileInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDispatchTileQCOM(VkCommandBuffer commandBuffer, const VkDispatchTileInfoQCOM* pDispatchTileInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdBeginPerTileExecutionQCOM(VkCommandBuffer commandBuffer, const VkPerTileBeginInfoQCOM* pPerTileBeginInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdBeginPerTileExecutionQCOM(VkCommandBuffer commandBuffer, const VkPerTileBeginInfoQCOM* pPerTileBeginInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdBeginPerTileExecutionQCOM(VkCommandBuffer commandBuffer, const VkPerTileBeginInfoQCOM* pPerTileBeginInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdEndPerTileExecutionQCOM(VkCommandBuffer commandBuffer, const VkPerTileEndInfoQCOM* pPerTileEndInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdEndPerTileExecutionQCOM(VkCommandBuffer commandBuffer, const VkPerTileEndInfoQCOM* pPerTileEndInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdEndPerTileExecutionQCOM(VkCommandBuffer commandBuffer, const VkPerTileEndInfoQCOM* pPerTileEndInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateExternalComputeQueueNV(VkDevice device, const VkExternalComputeQueueCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkExternalComputeQueueNV* pExternalQueue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateExternalComputeQueueNV(VkDevice device, const VkExternalComputeQueueCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkExternalComputeQueueNV* pExternalQueue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateExternalComputeQueueNV(VkDevice device, const VkExternalComputeQueueCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkExternalComputeQueueNV* pExternalQueue) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyExternalComputeQueueNV(VkDevice device, VkExternalComputeQueueNV externalQueue, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyExternalComputeQueueNV(VkDevice device, VkExternalComputeQueueNV externalQueue, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyExternalComputeQueueNV(VkDevice device, VkExternalComputeQueueNV externalQueue, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateTensorARM(VkDevice device, const VkTensorCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkTensorARM* pTensor) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateTensorARM(VkDevice device, const VkTensorCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkTensorARM* pTensor) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateTensorARM(VkDevice device, const VkTensorCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkTensorARM* pTensor) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyTensorARM(VkDevice device, VkTensorARM tensor, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyTensorARM(VkDevice device, VkTensorARM tensor, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyTensorARM(VkDevice device, VkTensorARM tensor, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateTensorViewARM(VkDevice device, const VkTensorViewCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkTensorViewARM* pView) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateTensorViewARM(VkDevice device, const VkTensorViewCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkTensorViewARM* pView) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateTensorViewARM(VkDevice device, const VkTensorViewCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkTensorViewARM* pView) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyTensorViewARM(VkDevice device, VkTensorViewARM tensorView, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyTensorViewARM(VkDevice device, VkTensorViewARM tensorView, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyTensorViewARM(VkDevice device, VkTensorViewARM tensorView, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetTensorMemoryRequirementsARM(VkDevice device, const VkTensorMemoryRequirementsInfoARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetTensorMemoryRequirementsARM(VkDevice device, const VkTensorMemoryRequirementsInfoARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetTensorMemoryRequirementsARM(VkDevice device, const VkTensorMemoryRequirementsInfoARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_BindTensorMemoryARM(VkDevice device, uint32_t bindInfoCount, const VkBindTensorMemoryInfoARM* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_BindTensorMemoryARM(VkDevice device, uint32_t bindInfoCount, const VkBindTensorMemoryInfoARM* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_BindTensorMemoryARM(VkDevice device, uint32_t bindInfoCount, const VkBindTensorMemoryInfoARM* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDeviceTensorMemoryRequirementsARM(VkDevice device, const VkDeviceTensorMemoryRequirementsARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDeviceTensorMemoryRequirementsARM(VkDevice device, const VkDeviceTensorMemoryRequirementsARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDeviceTensorMemoryRequirementsARM(VkDevice device, const VkDeviceTensorMemoryRequirementsARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdCopyTensorARM(VkCommandBuffer commandBuffer, const VkCopyTensorInfoARM* pCopyTensorInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdCopyTensorARM(VkCommandBuffer commandBuffer, const VkCopyTensorInfoARM* pCopyTensorInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdCopyTensorARM(VkCommandBuffer commandBuffer, const VkCopyTensorInfoARM* pCopyTensorInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetTensorOpaqueCaptureDescriptorDataARM(VkDevice device, const VkTensorCaptureDescriptorDataInfoARM* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetTensorOpaqueCaptureDescriptorDataARM(VkDevice device, const VkTensorCaptureDescriptorDataInfoARM* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetTensorOpaqueCaptureDescriptorDataARM(VkDevice device, const VkTensorCaptureDescriptorDataInfoARM* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetTensorViewOpaqueCaptureDescriptorDataARM(VkDevice device, const VkTensorViewCaptureDescriptorDataInfoARM* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetTensorViewOpaqueCaptureDescriptorDataARM(VkDevice device, const VkTensorViewCaptureDescriptorDataInfoARM* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetTensorViewOpaqueCaptureDescriptorDataARM(VkDevice device, const VkTensorViewCaptureDescriptorDataInfoARM* pInfo, void* pData) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateDataGraphPipelinesARM(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkDataGraphPipelineCreateInfoARM* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateDataGraphPipelinesARM(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkDataGraphPipelineCreateInfoARM* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateDataGraphPipelinesARM(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkDataGraphPipelineCreateInfoARM* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateDataGraphPipelineSessionARM(VkDevice device, const VkDataGraphPipelineSessionCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDataGraphPipelineSessionARM* pSession) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_CreateDataGraphPipelineSessionARM(VkDevice device, const VkDataGraphPipelineSessionCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDataGraphPipelineSessionARM* pSession) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_CreateDataGraphPipelineSessionARM(VkDevice device, const VkDataGraphPipelineSessionCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDataGraphPipelineSessionARM* pSession) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetDataGraphPipelineSessionBindPointRequirementsARM(VkDevice device, const VkDataGraphPipelineSessionBindPointRequirementsInfoARM* pInfo, uint32_t* pBindPointRequirementCount, VkDataGraphPipelineSessionBindPointRequirementARM* pBindPointRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetDataGraphPipelineSessionBindPointRequirementsARM(VkDevice device, const VkDataGraphPipelineSessionBindPointRequirementsInfoARM* pInfo, uint32_t* pBindPointRequirementCount, VkDataGraphPipelineSessionBindPointRequirementARM* pBindPointRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetDataGraphPipelineSessionBindPointRequirementsARM(VkDevice device, const VkDataGraphPipelineSessionBindPointRequirementsInfoARM* pInfo, uint32_t* pBindPointRequirementCount, VkDataGraphPipelineSessionBindPointRequirementARM* pBindPointRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_GetDataGraphPipelineSessionMemoryRequirementsARM(VkDevice device, const VkDataGraphPipelineSessionMemoryRequirementsInfoARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_GetDataGraphPipelineSessionMemoryRequirementsARM(VkDevice device, const VkDataGraphPipelineSessionMemoryRequirementsInfoARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_GetDataGraphPipelineSessionMemoryRequirementsARM(VkDevice device, const VkDataGraphPipelineSessionMemoryRequirementsInfoARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_BindDataGraphPipelineSessionMemoryARM(VkDevice device, uint32_t bindInfoCount, const VkBindDataGraphPipelineSessionMemoryInfoARM* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_BindDataGraphPipelineSessionMemoryARM(VkDevice device, uint32_t bindInfoCount, const VkBindDataGraphPipelineSessionMemoryInfoARM* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_BindDataGraphPipelineSessionMemoryARM(VkDevice device, uint32_t bindInfoCount, const VkBindDataGraphPipelineSessionMemoryInfoARM* pBindInfos) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_DestroyDataGraphPipelineSessionARM(VkDevice device, VkDataGraphPipelineSessionARM session, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_DestroyDataGraphPipelineSessionARM(VkDevice device, VkDataGraphPipelineSessionARM session, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_DestroyDataGraphPipelineSessionARM(VkDevice device, VkDataGraphPipelineSessionARM session, const VkAllocationCallbacks* pAllocator) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR void VKAPI_CALL v3dv_CmdDispatchDataGraphARM(VkCommandBuffer commandBuffer, VkDataGraphPipelineSessionARM session, const VkDataGraphPipelineDispatchInfoARM* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver42_CmdDispatchDataGraphARM(VkCommandBuffer commandBuffer, VkDataGraphPipelineSessionARM session, const VkDataGraphPipelineDispatchInfoARM* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR void VKAPI_CALL ver71_CmdDispatchDataGraphARM(VkCommandBuffer commandBuffer, VkDataGraphPipelineSessionARM session, const VkDataGraphPipelineDispatchInfoARM* pInfo) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetDataGraphPipelineAvailablePropertiesARM(VkDevice device, const VkDataGraphPipelineInfoARM* pPipelineInfo, uint32_t* pPropertiesCount, VkDataGraphPipelinePropertyARM* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetDataGraphPipelineAvailablePropertiesARM(VkDevice device, const VkDataGraphPipelineInfoARM* pPipelineInfo, uint32_t* pPropertiesCount, VkDataGraphPipelinePropertyARM* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetDataGraphPipelineAvailablePropertiesARM(VkDevice device, const VkDataGraphPipelineInfoARM* pPipelineInfo, uint32_t* pPropertiesCount, VkDataGraphPipelinePropertyARM* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

    VKAPI_ATTR VkResult VKAPI_CALL v3dv_GetDataGraphPipelinePropertiesARM(VkDevice device, const VkDataGraphPipelineInfoARM* pPipelineInfo, uint32_t propertiesCount, VkDataGraphPipelinePropertyQueryResultARM* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver42_GetDataGraphPipelinePropertiesARM(VkDevice device, const VkDataGraphPipelineInfoARM* pPipelineInfo, uint32_t propertiesCount, VkDataGraphPipelinePropertyQueryResultARM* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;
    VKAPI_ATTR VkResult VKAPI_CALL ver71_GetDataGraphPipelinePropertiesARM(VkDevice device, const VkDataGraphPipelineInfoARM* pPipelineInfo, uint32_t propertiesCount, VkDataGraphPipelinePropertyQueryResultARM* pProperties) VK_ENTRY_WEAK VK_ENTRY_HIDDEN;

#ifdef __cplusplus
}
#endif

#endif /* V3DV_ENTRYPOINTS_H */
