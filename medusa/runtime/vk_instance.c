#include "vk_instance.h"
#include "utils/log.h"

#include <stdlib.h>
#include <string.h>

/* Forward declaration of internal function */
static void vk_instance_initialize(vk_instance* instance, const VkInstanceCreateInfo* create_info);

vk_instance* vk_instance_create(const VkInstanceCreateInfo* create_info)
{
    if (!create_info)
    {
        LOG_ERROR("VkInstanceCreateInfo is null");
        return NULL;
    }

    vk_instance* instance = (vk_instance*)malloc(sizeof(vk_instance));
    if (!instance)
    {
        LOG_ERROR("Failed to allocate memory for vk_instance");
        return NULL;
    }

    /* Initialize all fields to zero */
    memset(instance, 0, sizeof(vk_instance));
    instance->api_version = VK_API_VERSION_1_0;

    vk_instance_initialize(instance, create_info);
    if (!instance->valid)
    {
        vk_instance_destroy(instance);
        return NULL;
    }

    return instance;
}

void vk_instance_destroy(vk_instance* instance)
{
    if (!instance)
    {
        return;
    }

    /* Free enabled extensions */
    if (instance->enabled_extensions)
    {
        for (uint32_t i = 0; i < instance->enabled_extensions_count; ++i)
        {
            free(instance->enabled_extensions[i]);
        }
        free(instance->enabled_extensions);
    }

    /* Free enabled layers */
    if (instance->enabled_layers)
    {
        for (uint32_t i = 0; i < instance->enabled_layers_count; ++i)
        {
            free(instance->enabled_layers[i]);
        }
        free(instance->enabled_layers);
    }

    free(instance);
}

static void vk_instance_initialize(vk_instance* instance, const VkInstanceCreateInfo* create_info)
{
    if (!create_info)
    {
        LOG_ERROR("Invalid VkInstanceCreateInfo");
        return;
    }

    LOG_INFO("Creating Vulkan instance...");

    /* Parse application info */
    if (create_info->pApplicationInfo)
    {
        const VkApplicationInfo* app_info = create_info->pApplicationInfo;

        if (app_info->pApplicationName)
        {
            strncpy(instance->app_name, app_info->pApplicationName, sizeof(instance->app_name) - 1);
            instance->app_name[sizeof(instance->app_name) - 1] = '\0';
        }
        instance->app_version = app_info->applicationVersion;

        if (app_info->pEngineName)
        {
            strncpy(instance->engine_name, app_info->pEngineName, sizeof(instance->engine_name) - 1);
            instance->engine_name[sizeof(instance->engine_name) - 1] = '\0';
        }
        instance->engine_version = app_info->engineVersion;
        instance->api_version = app_info->apiVersion;

        LOG_INFO("Application: %s, Version: %d.%d.%d",
                 instance->app_name,
                 VK_VERSION_MAJOR(instance->app_version),
                 VK_VERSION_MINOR(instance->app_version),
                 VK_VERSION_PATCH(instance->app_version));

        LOG_INFO("Engine: %s, API Version: %d.%d.%d",
                 instance->engine_name[0] != '\0' ? instance->engine_name : "None",
                 VK_VERSION_MAJOR(instance->api_version),
                 VK_VERSION_MINOR(instance->api_version),
                 VK_VERSION_PATCH(instance->api_version));
    }

    /* Parse enabled extensions */
    if (create_info->enabledExtensionCount > 0)
    {
        instance->enabled_extensions_count = create_info->enabledExtensionCount;
        instance->enabled_extensions = (char**)malloc(sizeof(char*) * instance->enabled_extensions_count);

        if (!instance->enabled_extensions)
        {
            LOG_ERROR("Failed to allocate memory for enabled extensions");
            return;
        }

        for (uint32_t i = 0; i < instance->enabled_extensions_count; ++i)
        {
            size_t len = strlen(create_info->ppEnabledExtensionNames[i]);
            instance->enabled_extensions[i] = (char*)malloc(len + 1);

            if (!instance->enabled_extensions[i])
            {
                LOG_ERROR("Failed to allocate memory for extension name");
                /* Clean up previously allocated extensions */
                for (uint32_t j = 0; j < i; ++j)
                {
                    free(instance->enabled_extensions[j]);
                }
                free(instance->enabled_extensions);
                instance->enabled_extensions = NULL;
                instance->enabled_extensions_count = 0;
                return;
            }

            strcpy(instance->enabled_extensions[i], create_info->ppEnabledExtensionNames[i]);
            LOG_INFO("Enabled extension: %s", instance->enabled_extensions[i]);
        }
    }

    /* Parse enabled layers */
    if (create_info->enabledLayerCount > 0)
    {
        instance->enabled_layers_count = create_info->enabledLayerCount;
        instance->enabled_layers = (char**)malloc(sizeof(char*) * instance->enabled_layers_count);

        if (!instance->enabled_layers)
        {
            LOG_ERROR("Failed to allocate memory for enabled layers");
            return;
        }

        for (uint32_t i = 0; i < instance->enabled_layers_count; ++i)
        {
            size_t len = strlen(create_info->ppEnabledLayerNames[i]);
            instance->enabled_layers[i] = (char*)malloc(len + 1);

            if (!instance->enabled_layers[i])
            {
                LOG_ERROR("Failed to allocate memory for layer name");
                /* Clean up previously allocated layers */
                for (uint32_t j = 0; j < i; ++j)
                {
                    free(instance->enabled_layers[j]);
                }
                free(instance->enabled_layers);
                instance->enabled_layers = NULL;
                instance->enabled_layers_count = 0;
                return;
            }

            strcpy(instance->enabled_layers[i], create_info->ppEnabledLayerNames[i]);
            LOG_INFO("Enabled layer: %s", instance->enabled_layers[i]);
        }
    }

    instance->valid = true;
    LOG_INFO("Vulkan instance created successfully");
}
