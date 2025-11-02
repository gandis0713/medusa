
/* Copyright © 2015-2021 Intel Corporation
 * Copyright © 2021 Collabora, Ltd.
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

/* This file generated from vk_cmd_queue_gen.py, don't edit directly. */

#include "vk_cmd_queue.h"

#define VK_PROTOTYPES
#include <vulkan/vulkan_core.h>
#ifdef VK_ENABLE_BETA_EXTENSIONS
#include <vulkan/vulkan_beta.h>
#endif

#include "vk_alloc.h"
#include "vk_cmd_enqueue_entrypoints.h"
#include "vk_command_buffer.h"
#include "vk_dispatch_table.h"
#include "vk_device.h"

const char *vk_cmd_queue_type_names[] = {
   "VK_CMD_BIND_PIPELINE",
   "VK_CMD_SET_ATTACHMENT_FEEDBACK_LOOP_ENABLE_EXT",
   "VK_CMD_SET_VIEWPORT",
   "VK_CMD_SET_SCISSOR",
   "VK_CMD_SET_LINE_WIDTH",
   "VK_CMD_SET_DEPTH_BIAS",
   "VK_CMD_SET_BLEND_CONSTANTS",
   "VK_CMD_SET_DEPTH_BOUNDS",
   "VK_CMD_SET_STENCIL_COMPARE_MASK",
   "VK_CMD_SET_STENCIL_WRITE_MASK",
   "VK_CMD_SET_STENCIL_REFERENCE",
   "VK_CMD_BIND_DESCRIPTOR_SETS",
   "VK_CMD_BIND_INDEX_BUFFER",
   "VK_CMD_BIND_VERTEX_BUFFERS",
   "VK_CMD_DRAW",
   "VK_CMD_DRAW_INDEXED",
   "VK_CMD_DRAW_MULTI_EXT",
   "VK_CMD_DRAW_MULTI_INDEXED_EXT",
   "VK_CMD_DRAW_INDIRECT",
   "VK_CMD_DRAW_INDEXED_INDIRECT",
   "VK_CMD_DISPATCH",
   "VK_CMD_DISPATCH_INDIRECT",
   "VK_CMD_SUBPASS_SHADING_HUAWEI",
   "VK_CMD_DRAW_CLUSTER_HUAWEI",
   "VK_CMD_DRAW_CLUSTER_INDIRECT_HUAWEI",
   "VK_CMD_UPDATE_PIPELINE_INDIRECT_BUFFER_NV",
   "VK_CMD_COPY_BUFFER",
   "VK_CMD_COPY_IMAGE",
   "VK_CMD_BLIT_IMAGE",
   "VK_CMD_COPY_BUFFER_TO_IMAGE",
   "VK_CMD_COPY_IMAGE_TO_BUFFER",
   "VK_CMD_COPY_MEMORY_INDIRECT_NV",
   "VK_CMD_COPY_MEMORY_INDIRECT_KHR",
   "VK_CMD_COPY_MEMORY_TO_IMAGE_INDIRECT_NV",
   "VK_CMD_COPY_MEMORY_TO_IMAGE_INDIRECT_KHR",
   "VK_CMD_UPDATE_BUFFER",
   "VK_CMD_FILL_BUFFER",
   "VK_CMD_CLEAR_COLOR_IMAGE",
   "VK_CMD_CLEAR_DEPTH_STENCIL_IMAGE",
   "VK_CMD_CLEAR_ATTACHMENTS",
   "VK_CMD_RESOLVE_IMAGE",
   "VK_CMD_SET_EVENT",
   "VK_CMD_RESET_EVENT",
   "VK_CMD_WAIT_EVENTS",
   "VK_CMD_PIPELINE_BARRIER",
   "VK_CMD_BEGIN_QUERY",
   "VK_CMD_END_QUERY",
   "VK_CMD_BEGIN_CONDITIONAL_RENDERING_EXT",
   "VK_CMD_END_CONDITIONAL_RENDERING_EXT",
   "VK_CMD_RESET_QUERY_POOL",
   "VK_CMD_WRITE_TIMESTAMP",
   "VK_CMD_COPY_QUERY_POOL_RESULTS",
   "VK_CMD_PUSH_CONSTANTS",
   "VK_CMD_BEGIN_RENDER_PASS",
   "VK_CMD_NEXT_SUBPASS",
   "VK_CMD_END_RENDER_PASS",
   "VK_CMD_EXECUTE_COMMANDS",
   "VK_CMD_DEBUG_MARKER_BEGIN_EXT",
   "VK_CMD_DEBUG_MARKER_END_EXT",
   "VK_CMD_DEBUG_MARKER_INSERT_EXT",
   "VK_CMD_EXECUTE_GENERATED_COMMANDS_NV",
   "VK_CMD_PREPROCESS_GENERATED_COMMANDS_NV",
   "VK_CMD_BIND_PIPELINE_SHADER_GROUP_NV",
   "VK_CMD_EXECUTE_GENERATED_COMMANDS_EXT",
   "VK_CMD_PREPROCESS_GENERATED_COMMANDS_EXT",
   "VK_CMD_PUSH_DESCRIPTOR_SET",
   "VK_CMD_SET_DEVICE_MASK",
   "VK_CMD_DISPATCH_BASE",
   "VK_CMD_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE",
   "VK_CMD_SET_VIEWPORT_WSCALING_NV",
   "VK_CMD_SET_DISCARD_RECTANGLE_EXT",
   "VK_CMD_SET_DISCARD_RECTANGLE_ENABLE_EXT",
   "VK_CMD_SET_DISCARD_RECTANGLE_MODE_EXT",
   "VK_CMD_SET_SAMPLE_LOCATIONS_EXT",
   "VK_CMD_BEGIN_DEBUG_UTILS_LABEL_EXT",
   "VK_CMD_END_DEBUG_UTILS_LABEL_EXT",
   "VK_CMD_INSERT_DEBUG_UTILS_LABEL_EXT",
   "VK_CMD_WRITE_BUFFER_MARKER_AMD",
   "VK_CMD_BEGIN_RENDER_PASS2",
   "VK_CMD_NEXT_SUBPASS2",
   "VK_CMD_END_RENDER_PASS2",
   "VK_CMD_DRAW_INDIRECT_COUNT",
   "VK_CMD_DRAW_INDEXED_INDIRECT_COUNT",
   "VK_CMD_SET_CHECKPOINT_NV",
   "VK_CMD_BIND_TRANSFORM_FEEDBACK_BUFFERS_EXT",
   "VK_CMD_BEGIN_TRANSFORM_FEEDBACK_EXT",
   "VK_CMD_END_TRANSFORM_FEEDBACK_EXT",
   "VK_CMD_BEGIN_QUERY_INDEXED_EXT",
   "VK_CMD_END_QUERY_INDEXED_EXT",
   "VK_CMD_DRAW_INDIRECT_BYTE_COUNT_EXT",
   "VK_CMD_SET_EXCLUSIVE_SCISSOR_NV",
   "VK_CMD_SET_EXCLUSIVE_SCISSOR_ENABLE_NV",
   "VK_CMD_BIND_SHADING_RATE_IMAGE_NV",
   "VK_CMD_SET_VIEWPORT_SHADING_RATE_PALETTE_NV",
   "VK_CMD_SET_COARSE_SAMPLE_ORDER_NV",
   "VK_CMD_DRAW_MESH_TASKS_NV",
   "VK_CMD_DRAW_MESH_TASKS_INDIRECT_NV",
   "VK_CMD_DRAW_MESH_TASKS_INDIRECT_COUNT_NV",
   "VK_CMD_DRAW_MESH_TASKS_EXT",
   "VK_CMD_DRAW_MESH_TASKS_INDIRECT_EXT",
   "VK_CMD_DRAW_MESH_TASKS_INDIRECT_COUNT_EXT",
   "VK_CMD_BIND_INVOCATION_MASK_HUAWEI",
   "VK_CMD_COPY_ACCELERATION_STRUCTURE_NV",
   "VK_CMD_COPY_ACCELERATION_STRUCTURE_KHR",
   "VK_CMD_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_KHR",
   "VK_CMD_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_KHR",
   "VK_CMD_WRITE_ACCELERATION_STRUCTURES_PROPERTIES_KHR",
   "VK_CMD_WRITE_ACCELERATION_STRUCTURES_PROPERTIES_NV",
   "VK_CMD_BUILD_ACCELERATION_STRUCTURE_NV",
   "VK_CMD_TRACE_RAYS_KHR",
   "VK_CMD_TRACE_RAYS_NV",
   "VK_CMD_TRACE_RAYS_INDIRECT_KHR",
   "VK_CMD_TRACE_RAYS_INDIRECT2_KHR",
   "VK_CMD_BUILD_CLUSTER_ACCELERATION_STRUCTURE_INDIRECT_NV",
   "VK_CMD_SET_RAY_TRACING_PIPELINE_STACK_SIZE_KHR",
   "VK_CMD_SET_PERFORMANCE_MARKER_INTEL",
   "VK_CMD_SET_PERFORMANCE_STREAM_MARKER_INTEL",
   "VK_CMD_SET_PERFORMANCE_OVERRIDE_INTEL",
   "VK_CMD_SET_LINE_STIPPLE",
   "VK_CMD_BUILD_ACCELERATION_STRUCTURES_KHR",
   "VK_CMD_BUILD_ACCELERATION_STRUCTURES_INDIRECT_KHR",
   "VK_CMD_SET_CULL_MODE",
   "VK_CMD_SET_FRONT_FACE",
   "VK_CMD_SET_PRIMITIVE_TOPOLOGY",
   "VK_CMD_SET_VIEWPORT_WITH_COUNT",
   "VK_CMD_SET_SCISSOR_WITH_COUNT",
   "VK_CMD_BIND_INDEX_BUFFER2",
   "VK_CMD_BIND_VERTEX_BUFFERS2",
   "VK_CMD_SET_DEPTH_TEST_ENABLE",
   "VK_CMD_SET_DEPTH_WRITE_ENABLE",
   "VK_CMD_SET_DEPTH_COMPARE_OP",
   "VK_CMD_SET_DEPTH_BOUNDS_TEST_ENABLE",
   "VK_CMD_SET_STENCIL_TEST_ENABLE",
   "VK_CMD_SET_STENCIL_OP",
   "VK_CMD_SET_PATCH_CONTROL_POINTS_EXT",
   "VK_CMD_SET_RASTERIZER_DISCARD_ENABLE",
   "VK_CMD_SET_DEPTH_BIAS_ENABLE",
   "VK_CMD_SET_LOGIC_OP_EXT",
   "VK_CMD_SET_PRIMITIVE_RESTART_ENABLE",
   "VK_CMD_SET_TESSELLATION_DOMAIN_ORIGIN_EXT",
   "VK_CMD_SET_DEPTH_CLAMP_ENABLE_EXT",
   "VK_CMD_SET_POLYGON_MODE_EXT",
   "VK_CMD_SET_RASTERIZATION_SAMPLES_EXT",
   "VK_CMD_SET_SAMPLE_MASK_EXT",
   "VK_CMD_SET_ALPHA_TO_COVERAGE_ENABLE_EXT",
   "VK_CMD_SET_ALPHA_TO_ONE_ENABLE_EXT",
   "VK_CMD_SET_LOGIC_OP_ENABLE_EXT",
   "VK_CMD_SET_COLOR_BLEND_ENABLE_EXT",
   "VK_CMD_SET_COLOR_BLEND_EQUATION_EXT",
   "VK_CMD_SET_COLOR_WRITE_MASK_EXT",
   "VK_CMD_SET_RASTERIZATION_STREAM_EXT",
   "VK_CMD_SET_CONSERVATIVE_RASTERIZATION_MODE_EXT",
   "VK_CMD_SET_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT",
   "VK_CMD_SET_DEPTH_CLIP_ENABLE_EXT",
   "VK_CMD_SET_SAMPLE_LOCATIONS_ENABLE_EXT",
   "VK_CMD_SET_COLOR_BLEND_ADVANCED_EXT",
   "VK_CMD_SET_PROVOKING_VERTEX_MODE_EXT",
   "VK_CMD_SET_LINE_RASTERIZATION_MODE_EXT",
   "VK_CMD_SET_LINE_STIPPLE_ENABLE_EXT",
   "VK_CMD_SET_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT",
   "VK_CMD_SET_VIEWPORT_WSCALING_ENABLE_NV",
   "VK_CMD_SET_VIEWPORT_SWIZZLE_NV",
   "VK_CMD_SET_COVERAGE_TO_COLOR_ENABLE_NV",
   "VK_CMD_SET_COVERAGE_TO_COLOR_LOCATION_NV",
   "VK_CMD_SET_COVERAGE_MODULATION_MODE_NV",
   "VK_CMD_SET_COVERAGE_MODULATION_TABLE_ENABLE_NV",
   "VK_CMD_SET_COVERAGE_MODULATION_TABLE_NV",
   "VK_CMD_SET_SHADING_RATE_IMAGE_ENABLE_NV",
   "VK_CMD_SET_COVERAGE_REDUCTION_MODE_NV",
   "VK_CMD_SET_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV",
   "VK_CMD_COPY_BUFFER2",
   "VK_CMD_COPY_IMAGE2",
   "VK_CMD_BLIT_IMAGE2",
   "VK_CMD_COPY_BUFFER_TO_IMAGE2",
   "VK_CMD_COPY_IMAGE_TO_BUFFER2",
   "VK_CMD_RESOLVE_IMAGE2",
   "VK_CMD_SET_FRAGMENT_SHADING_RATE_KHR",
   "VK_CMD_SET_FRAGMENT_SHADING_RATE_ENUM_NV",
   "VK_CMD_SET_VERTEX_INPUT_EXT",
   "VK_CMD_SET_COLOR_WRITE_ENABLE_EXT",
   "VK_CMD_SET_EVENT2",
   "VK_CMD_RESET_EVENT2",
   "VK_CMD_WAIT_EVENTS2",
   "VK_CMD_PIPELINE_BARRIER2",
   "VK_CMD_WRITE_TIMESTAMP2",
   "VK_CMD_WRITE_BUFFER_MARKER2_AMD",
   "VK_CMD_DECODE_VIDEO_KHR",
   "VK_CMD_BEGIN_VIDEO_CODING_KHR",
   "VK_CMD_CONTROL_VIDEO_CODING_KHR",
   "VK_CMD_END_VIDEO_CODING_KHR",
   "VK_CMD_ENCODE_VIDEO_KHR",
   "VK_CMD_DECOMPRESS_MEMORY_NV",
   "VK_CMD_DECOMPRESS_MEMORY_INDIRECT_COUNT_NV",
   "VK_CMD_BUILD_PARTITIONED_ACCELERATION_STRUCTURES_NV",
   "VK_CMD_CU_LAUNCH_KERNEL_NVX",
   "VK_CMD_BIND_DESCRIPTOR_BUFFERS_EXT",
   "VK_CMD_SET_DESCRIPTOR_BUFFER_OFFSETS_EXT",
   "VK_CMD_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_EXT",
   "VK_CMD_BEGIN_RENDERING",
   "VK_CMD_END_RENDERING",
   "VK_CMD_END_RENDERING2_EXT",
   "VK_CMD_BUILD_MICROMAPS_EXT",
   "VK_CMD_COPY_MICROMAP_EXT",
   "VK_CMD_COPY_MICROMAP_TO_MEMORY_EXT",
   "VK_CMD_COPY_MEMORY_TO_MICROMAP_EXT",
   "VK_CMD_WRITE_MICROMAPS_PROPERTIES_EXT",
   "VK_CMD_BIND_TILE_MEMORY_QCOM",
   "VK_CMD_OPTICAL_FLOW_EXECUTE_NV",
   "VK_CMD_SET_DEPTH_BIAS2_EXT",
   "VK_CMD_BIND_SHADERS_EXT",
   "VK_CMD_BIND_DESCRIPTOR_SETS2",
   "VK_CMD_PUSH_CONSTANTS2",
   "VK_CMD_PUSH_DESCRIPTOR_SET2",
   "VK_CMD_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE2",
   "VK_CMD_SET_DESCRIPTOR_BUFFER_OFFSETS2_EXT",
   "VK_CMD_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS2_EXT",
   "VK_CMD_SET_RENDERING_ATTACHMENT_LOCATIONS",
   "VK_CMD_SET_RENDERING_INPUT_ATTACHMENT_INDICES",
   "VK_CMD_SET_DEPTH_CLAMP_RANGE_EXT",
   "VK_CMD_CONVERT_COOPERATIVE_VECTOR_MATRIX_NV",
   "VK_CMD_DISPATCH_TILE_QCOM",
   "VK_CMD_BEGIN_PER_TILE_EXECUTION_QCOM",
   "VK_CMD_END_PER_TILE_EXECUTION_QCOM",
   "VK_CMD_COPY_TENSOR_ARM",
   "VK_CMD_DISPATCH_DATA_GRAPH_ARM",
};

size_t vk_cmd_queue_type_sizes[] = {
   sizeof(struct vk_cmd_bind_pipeline) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_attachment_feedback_loop_enable_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_viewport) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_scissor) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_line_width) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_depth_bias) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_blend_constants) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_depth_bounds) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_stencil_compare_mask) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_stencil_write_mask) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_stencil_reference) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_bind_descriptor_sets) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_bind_index_buffer) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_bind_vertex_buffers) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_draw) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_draw_indexed) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_draw_multi_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_draw_multi_indexed_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_draw_indirect) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_draw_indexed_indirect) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_dispatch) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_dispatch_indirect) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_draw_cluster_huawei) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_draw_cluster_indirect_huawei) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_update_pipeline_indirect_buffer_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_buffer) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_image) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_blit_image) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_buffer_to_image) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_image_to_buffer) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_memory_indirect_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_memory_indirect_khr) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_memory_to_image_indirect_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_memory_to_image_indirect_khr) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_update_buffer) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_fill_buffer) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_clear_color_image) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_clear_depth_stencil_image) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_clear_attachments) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_resolve_image) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_event) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_reset_event) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_wait_events) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_pipeline_barrier) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_begin_query) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_end_query) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_begin_conditional_rendering_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_reset_query_pool) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_write_timestamp) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_query_pool_results) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_push_constants) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_begin_render_pass) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_next_subpass) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_execute_commands) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_debug_marker_begin_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_debug_marker_insert_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_execute_generated_commands_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_preprocess_generated_commands_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_bind_pipeline_shader_group_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_execute_generated_commands_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_preprocess_generated_commands_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_push_descriptor_set) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_device_mask) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_dispatch_base) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_push_descriptor_set_with_template) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_viewport_wscaling_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_discard_rectangle_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_discard_rectangle_enable_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_discard_rectangle_mode_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_sample_locations_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_begin_debug_utils_label_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_insert_debug_utils_label_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_write_buffer_marker_amd) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_begin_render_pass2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_next_subpass2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_end_render_pass2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_draw_indirect_count) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_draw_indexed_indirect_count) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_checkpoint_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_bind_transform_feedback_buffers_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_begin_transform_feedback_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_end_transform_feedback_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_begin_query_indexed_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_end_query_indexed_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_draw_indirect_byte_count_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_exclusive_scissor_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_exclusive_scissor_enable_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_bind_shading_rate_image_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_viewport_shading_rate_palette_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_coarse_sample_order_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_draw_mesh_tasks_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_draw_mesh_tasks_indirect_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_draw_mesh_tasks_indirect_count_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_draw_mesh_tasks_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_draw_mesh_tasks_indirect_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_draw_mesh_tasks_indirect_count_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_bind_invocation_mask_huawei) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_acceleration_structure_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_acceleration_structure_khr) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_acceleration_structure_to_memory_khr) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_memory_to_acceleration_structure_khr) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_write_acceleration_structures_properties_khr) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_write_acceleration_structures_properties_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_build_acceleration_structure_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_trace_rays_khr) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_trace_rays_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_trace_rays_indirect_khr) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_trace_rays_indirect2_khr) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_build_cluster_acceleration_structure_indirect_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_ray_tracing_pipeline_stack_size_khr) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_performance_marker_intel) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_performance_stream_marker_intel) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_performance_override_intel) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_line_stipple) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_build_acceleration_structures_khr) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_build_acceleration_structures_indirect_khr) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_cull_mode) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_front_face) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_primitive_topology) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_viewport_with_count) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_scissor_with_count) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_bind_index_buffer2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_bind_vertex_buffers2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_depth_test_enable) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_depth_write_enable) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_depth_compare_op) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_depth_bounds_test_enable) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_stencil_test_enable) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_stencil_op) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_patch_control_points_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_rasterizer_discard_enable) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_depth_bias_enable) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_logic_op_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_primitive_restart_enable) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_tessellation_domain_origin_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_depth_clamp_enable_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_polygon_mode_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_rasterization_samples_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_sample_mask_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_alpha_to_coverage_enable_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_alpha_to_one_enable_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_logic_op_enable_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_color_blend_enable_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_color_blend_equation_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_color_write_mask_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_rasterization_stream_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_conservative_rasterization_mode_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_extra_primitive_overestimation_size_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_depth_clip_enable_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_sample_locations_enable_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_color_blend_advanced_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_provoking_vertex_mode_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_line_rasterization_mode_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_line_stipple_enable_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_depth_clip_negative_one_to_one_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_viewport_wscaling_enable_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_viewport_swizzle_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_coverage_to_color_enable_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_coverage_to_color_location_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_coverage_modulation_mode_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_coverage_modulation_table_enable_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_coverage_modulation_table_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_shading_rate_image_enable_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_coverage_reduction_mode_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_representative_fragment_test_enable_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_buffer2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_image2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_blit_image2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_buffer_to_image2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_image_to_buffer2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_resolve_image2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_fragment_shading_rate_khr) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_fragment_shading_rate_enum_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_vertex_input_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_color_write_enable_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_event2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_reset_event2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_wait_events2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_pipeline_barrier2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_write_timestamp2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_write_buffer_marker2_amd) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_decode_video_khr) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_begin_video_coding_khr) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_control_video_coding_khr) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_end_video_coding_khr) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_encode_video_khr) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_decompress_memory_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_decompress_memory_indirect_count_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_build_partitioned_acceleration_structures_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_cu_launch_kernel_nvx) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_bind_descriptor_buffers_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_descriptor_buffer_offsets_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_bind_descriptor_buffer_embedded_samplers_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_begin_rendering) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_end_rendering2_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_build_micromaps_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_micromap_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_micromap_to_memory_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_memory_to_micromap_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_write_micromaps_properties_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_bind_tile_memory_qcom) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_optical_flow_execute_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_depth_bias2_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_bind_shaders_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_bind_descriptor_sets2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_push_constants2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_push_descriptor_set2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_push_descriptor_set_with_template2) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_descriptor_buffer_offsets2_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_bind_descriptor_buffer_embedded_samplers2_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_rendering_attachment_locations) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_rendering_input_attachment_indices) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_set_depth_clamp_range_ext) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_convert_cooperative_vector_matrix_nv) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_dispatch_tile_qcom) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_begin_per_tile_execution_qcom) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_end_per_tile_execution_qcom) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_copy_tensor_arm) +
   sizeof(struct vk_cmd_queue_entry_base),
   sizeof(struct vk_cmd_dispatch_data_graph_arm) +
   sizeof(struct vk_cmd_queue_entry_base),
};

static void
vk_free_cmd_bind_pipeline(struct vk_cmd_queue *queue,
                          struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_bind_pipeline(struct vk_cmd_queue *queue
, VkPipelineBindPoint pipelineBindPoint
, VkPipeline pipeline
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BIND_PIPELINE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BIND_PIPELINE;
   cmd->u.bind_pipeline.pipeline_bind_point = pipelineBindPoint;
   cmd->u.bind_pipeline.pipeline = pipeline;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_attachment_feedback_loop_enable_ext(struct vk_cmd_queue *queue,
                                                    struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_attachment_feedback_loop_enable_ext(struct vk_cmd_queue *queue
, VkImageAspectFlags aspectMask
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_ATTACHMENT_FEEDBACK_LOOP_ENABLE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_ATTACHMENT_FEEDBACK_LOOP_ENABLE_EXT;
   cmd->u.set_attachment_feedback_loop_enable_ext.aspect_mask = aspectMask;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_viewport(struct vk_cmd_queue *queue,
                         struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkViewport* )cmd->u.set_viewport.viewports);
}

VkResult vk_enqueue_cmd_set_viewport(struct vk_cmd_queue *queue
, uint32_t firstViewport
, uint32_t viewportCount
, const VkViewport* pViewports
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_VIEWPORT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_VIEWPORT;
   cmd->u.set_viewport.first_viewport = firstViewport;
   cmd->u.set_viewport.viewport_count = viewportCount;
   if (pViewports) {
      cmd->u.set_viewport.viewports = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_viewport.viewports) * (viewportCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_viewport.viewports == NULL) goto err;
      memcpy((void*)cmd->u.set_viewport.viewports, pViewports, sizeof(*cmd->u.set_viewport.viewports) * (viewportCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_viewport(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_scissor(struct vk_cmd_queue *queue,
                        struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkRect2D* )cmd->u.set_scissor.scissors);
}

VkResult vk_enqueue_cmd_set_scissor(struct vk_cmd_queue *queue
, uint32_t firstScissor
, uint32_t scissorCount
, const VkRect2D* pScissors
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_SCISSOR], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_SCISSOR;
   cmd->u.set_scissor.first_scissor = firstScissor;
   cmd->u.set_scissor.scissor_count = scissorCount;
   if (pScissors) {
      cmd->u.set_scissor.scissors = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_scissor.scissors) * (scissorCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_scissor.scissors == NULL) goto err;
      memcpy((void*)cmd->u.set_scissor.scissors, pScissors, sizeof(*cmd->u.set_scissor.scissors) * (scissorCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_scissor(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_line_width(struct vk_cmd_queue *queue,
                           struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_line_width(struct vk_cmd_queue *queue
, float lineWidth
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_LINE_WIDTH], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_LINE_WIDTH;
   cmd->u.set_line_width.line_width = lineWidth;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_depth_bias(struct vk_cmd_queue *queue,
                           struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_depth_bias(struct vk_cmd_queue *queue
, float depthBiasConstantFactor
, float depthBiasClamp
, float depthBiasSlopeFactor
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_DEPTH_BIAS], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_DEPTH_BIAS;
   cmd->u.set_depth_bias.depth_bias_constant_factor = depthBiasConstantFactor;
   cmd->u.set_depth_bias.depth_bias_clamp = depthBiasClamp;
   cmd->u.set_depth_bias.depth_bias_slope_factor = depthBiasSlopeFactor;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_blend_constants(struct vk_cmd_queue *queue,
                                struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_blend_constants(struct vk_cmd_queue *queue
, const float blendConstants[4]
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_BLEND_CONSTANTS], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_BLEND_CONSTANTS;
   memcpy(cmd->u.set_blend_constants.blend_constants, blendConstants, sizeof(*blendConstants) * 4);

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_depth_bounds(struct vk_cmd_queue *queue,
                             struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_depth_bounds(struct vk_cmd_queue *queue
, float minDepthBounds
, float maxDepthBounds
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_DEPTH_BOUNDS], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_DEPTH_BOUNDS;
   cmd->u.set_depth_bounds.min_depth_bounds = minDepthBounds;
   cmd->u.set_depth_bounds.max_depth_bounds = maxDepthBounds;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_stencil_compare_mask(struct vk_cmd_queue *queue,
                                     struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_stencil_compare_mask(struct vk_cmd_queue *queue
, VkStencilFaceFlags faceMask
, uint32_t compareMask
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_STENCIL_COMPARE_MASK], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_STENCIL_COMPARE_MASK;
   cmd->u.set_stencil_compare_mask.face_mask = faceMask;
   cmd->u.set_stencil_compare_mask.compare_mask = compareMask;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_stencil_write_mask(struct vk_cmd_queue *queue,
                                   struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_stencil_write_mask(struct vk_cmd_queue *queue
, VkStencilFaceFlags faceMask
, uint32_t writeMask
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_STENCIL_WRITE_MASK], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_STENCIL_WRITE_MASK;
   cmd->u.set_stencil_write_mask.face_mask = faceMask;
   cmd->u.set_stencil_write_mask.write_mask = writeMask;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_stencil_reference(struct vk_cmd_queue *queue,
                                  struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_stencil_reference(struct vk_cmd_queue *queue
, VkStencilFaceFlags faceMask
, uint32_t reference
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_STENCIL_REFERENCE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_STENCIL_REFERENCE;
   cmd->u.set_stencil_reference.face_mask = faceMask;
   cmd->u.set_stencil_reference.reference = reference;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_bind_descriptor_sets(struct vk_cmd_queue *queue,
                                 struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkDescriptorSet* )cmd->u.bind_descriptor_sets.descriptor_sets);
   vk_free(queue->alloc, ( uint32_t* )cmd->u.bind_descriptor_sets.dynamic_offsets);
}


static void
vk_free_cmd_bind_index_buffer(struct vk_cmd_queue *queue,
                              struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_bind_index_buffer(struct vk_cmd_queue *queue
, VkBuffer buffer
, VkDeviceSize offset
, VkIndexType indexType
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BIND_INDEX_BUFFER], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BIND_INDEX_BUFFER;
   cmd->u.bind_index_buffer.buffer = buffer;
   cmd->u.bind_index_buffer.offset = offset;
   cmd->u.bind_index_buffer.index_type = indexType;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_bind_vertex_buffers(struct vk_cmd_queue *queue,
                                struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkBuffer* )cmd->u.bind_vertex_buffers.buffers);
   vk_free(queue->alloc, ( VkDeviceSize* )cmd->u.bind_vertex_buffers.offsets);
}

VkResult vk_enqueue_cmd_bind_vertex_buffers(struct vk_cmd_queue *queue
, uint32_t firstBinding
, uint32_t bindingCount
, const VkBuffer* pBuffers
, const VkDeviceSize* pOffsets
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BIND_VERTEX_BUFFERS], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BIND_VERTEX_BUFFERS;
   cmd->u.bind_vertex_buffers.first_binding = firstBinding;
   cmd->u.bind_vertex_buffers.binding_count = bindingCount;
   if (pBuffers) {
      cmd->u.bind_vertex_buffers.buffers = vk_zalloc(queue->alloc, sizeof(*cmd->u.bind_vertex_buffers.buffers) * (bindingCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.bind_vertex_buffers.buffers == NULL) goto err;
      memcpy((void*)cmd->u.bind_vertex_buffers.buffers, pBuffers, sizeof(*cmd->u.bind_vertex_buffers.buffers) * (bindingCount));
   }
   if (pOffsets) {
      cmd->u.bind_vertex_buffers.offsets = vk_zalloc(queue->alloc, sizeof(*cmd->u.bind_vertex_buffers.offsets) * (bindingCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.bind_vertex_buffers.offsets == NULL) goto err;
      memcpy((void*)cmd->u.bind_vertex_buffers.offsets, pOffsets, sizeof(*cmd->u.bind_vertex_buffers.offsets) * (bindingCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_bind_vertex_buffers(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_draw(struct vk_cmd_queue *queue,
                 struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_draw(struct vk_cmd_queue *queue
, uint32_t vertexCount
, uint32_t instanceCount
, uint32_t firstVertex
, uint32_t firstInstance
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DRAW], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DRAW;
   cmd->u.draw.vertex_count = vertexCount;
   cmd->u.draw.instance_count = instanceCount;
   cmd->u.draw.first_vertex = firstVertex;
   cmd->u.draw.first_instance = firstInstance;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_draw_indexed(struct vk_cmd_queue *queue,
                         struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_draw_indexed(struct vk_cmd_queue *queue
, uint32_t indexCount
, uint32_t instanceCount
, uint32_t firstIndex
, int32_t vertexOffset
, uint32_t firstInstance
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DRAW_INDEXED], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DRAW_INDEXED;
   cmd->u.draw_indexed.index_count = indexCount;
   cmd->u.draw_indexed.instance_count = instanceCount;
   cmd->u.draw_indexed.first_index = firstIndex;
   cmd->u.draw_indexed.vertex_offset = vertexOffset;
   cmd->u.draw_indexed.first_instance = firstInstance;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_draw_multi_ext(struct vk_cmd_queue *queue,
                           struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkMultiDrawInfoEXT* )cmd->u.draw_multi_ext.vertex_info);
}


static void
vk_free_cmd_draw_multi_indexed_ext(struct vk_cmd_queue *queue,
                                   struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkMultiDrawIndexedInfoEXT* )cmd->u.draw_multi_indexed_ext.index_info);
   vk_free(queue->alloc, (void*)cmd->u.draw_multi_indexed_ext.vertex_offset);

}


static void
vk_free_cmd_draw_indirect(struct vk_cmd_queue *queue,
                          struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_draw_indirect(struct vk_cmd_queue *queue
, VkBuffer buffer
, VkDeviceSize offset
, uint32_t drawCount
, uint32_t stride
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DRAW_INDIRECT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DRAW_INDIRECT;
   cmd->u.draw_indirect.buffer = buffer;
   cmd->u.draw_indirect.offset = offset;
   cmd->u.draw_indirect.draw_count = drawCount;
   cmd->u.draw_indirect.stride = stride;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_draw_indexed_indirect(struct vk_cmd_queue *queue,
                                  struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_draw_indexed_indirect(struct vk_cmd_queue *queue
, VkBuffer buffer
, VkDeviceSize offset
, uint32_t drawCount
, uint32_t stride
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DRAW_INDEXED_INDIRECT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DRAW_INDEXED_INDIRECT;
   cmd->u.draw_indexed_indirect.buffer = buffer;
   cmd->u.draw_indexed_indirect.offset = offset;
   cmd->u.draw_indexed_indirect.draw_count = drawCount;
   cmd->u.draw_indexed_indirect.stride = stride;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_dispatch(struct vk_cmd_queue *queue,
                     struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_dispatch(struct vk_cmd_queue *queue
, uint32_t groupCountX
, uint32_t groupCountY
, uint32_t groupCountZ
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DISPATCH], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DISPATCH;
   cmd->u.dispatch.group_count_x = groupCountX;
   cmd->u.dispatch.group_count_y = groupCountY;
   cmd->u.dispatch.group_count_z = groupCountZ;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_dispatch_indirect(struct vk_cmd_queue *queue,
                              struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_dispatch_indirect(struct vk_cmd_queue *queue
, VkBuffer buffer
, VkDeviceSize offset
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DISPATCH_INDIRECT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DISPATCH_INDIRECT;
   cmd->u.dispatch_indirect.buffer = buffer;
   cmd->u.dispatch_indirect.offset = offset;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_subpass_shading_huawei(struct vk_cmd_queue *queue,
                                   struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_subpass_shading_huawei(struct vk_cmd_queue *queue
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SUBPASS_SHADING_HUAWEI], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SUBPASS_SHADING_HUAWEI;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_draw_cluster_huawei(struct vk_cmd_queue *queue,
                                struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_draw_cluster_huawei(struct vk_cmd_queue *queue
, uint32_t groupCountX
, uint32_t groupCountY
, uint32_t groupCountZ
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DRAW_CLUSTER_HUAWEI], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DRAW_CLUSTER_HUAWEI;
   cmd->u.draw_cluster_huawei.group_count_x = groupCountX;
   cmd->u.draw_cluster_huawei.group_count_y = groupCountY;
   cmd->u.draw_cluster_huawei.group_count_z = groupCountZ;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_draw_cluster_indirect_huawei(struct vk_cmd_queue *queue,
                                         struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_draw_cluster_indirect_huawei(struct vk_cmd_queue *queue
, VkBuffer buffer
, VkDeviceSize offset
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DRAW_CLUSTER_INDIRECT_HUAWEI], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DRAW_CLUSTER_INDIRECT_HUAWEI;
   cmd->u.draw_cluster_indirect_huawei.buffer = buffer;
   cmd->u.draw_cluster_indirect_huawei.offset = offset;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_update_pipeline_indirect_buffer_nv(struct vk_cmd_queue *queue,
                                               struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_update_pipeline_indirect_buffer_nv(struct vk_cmd_queue *queue
, VkPipelineBindPoint           pipelineBindPoint
, VkPipeline                    pipeline
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_UPDATE_PIPELINE_INDIRECT_BUFFER_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_UPDATE_PIPELINE_INDIRECT_BUFFER_NV;
   cmd->u.update_pipeline_indirect_buffer_nv.pipeline_bind_point = pipelineBindPoint;
   cmd->u.update_pipeline_indirect_buffer_nv.pipeline = pipeline;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_copy_buffer(struct vk_cmd_queue *queue,
                        struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkBufferCopy* )cmd->u.copy_buffer.regions);
}

VkResult vk_enqueue_cmd_copy_buffer(struct vk_cmd_queue *queue
, VkBuffer srcBuffer
, VkBuffer dstBuffer
, uint32_t regionCount
, const VkBufferCopy* pRegions
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_BUFFER], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_BUFFER;
   cmd->u.copy_buffer.src_buffer = srcBuffer;
   cmd->u.copy_buffer.dst_buffer = dstBuffer;
   cmd->u.copy_buffer.region_count = regionCount;
   if (pRegions) {
      cmd->u.copy_buffer.regions = vk_zalloc(queue->alloc, sizeof(*cmd->u.copy_buffer.regions) * (regionCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.copy_buffer.regions == NULL) goto err;
      memcpy((void*)cmd->u.copy_buffer.regions, pRegions, sizeof(*cmd->u.copy_buffer.regions) * (regionCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_copy_buffer(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_copy_image(struct vk_cmd_queue *queue,
                       struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkImageCopy* )cmd->u.copy_image.regions);
}

VkResult vk_enqueue_cmd_copy_image(struct vk_cmd_queue *queue
, VkImage srcImage
, VkImageLayout srcImageLayout
, VkImage dstImage
, VkImageLayout dstImageLayout
, uint32_t regionCount
, const VkImageCopy* pRegions
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_IMAGE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_IMAGE;
   cmd->u.copy_image.src_image = srcImage;
   cmd->u.copy_image.src_image_layout = srcImageLayout;
   cmd->u.copy_image.dst_image = dstImage;
   cmd->u.copy_image.dst_image_layout = dstImageLayout;
   cmd->u.copy_image.region_count = regionCount;
   if (pRegions) {
      cmd->u.copy_image.regions = vk_zalloc(queue->alloc, sizeof(*cmd->u.copy_image.regions) * (regionCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.copy_image.regions == NULL) goto err;
      memcpy((void*)cmd->u.copy_image.regions, pRegions, sizeof(*cmd->u.copy_image.regions) * (regionCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_copy_image(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_blit_image(struct vk_cmd_queue *queue,
                       struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkImageBlit* )cmd->u.blit_image.regions);
}

VkResult vk_enqueue_cmd_blit_image(struct vk_cmd_queue *queue
, VkImage srcImage
, VkImageLayout srcImageLayout
, VkImage dstImage
, VkImageLayout dstImageLayout
, uint32_t regionCount
, const VkImageBlit* pRegions
, VkFilter filter
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BLIT_IMAGE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BLIT_IMAGE;
   cmd->u.blit_image.src_image = srcImage;
   cmd->u.blit_image.src_image_layout = srcImageLayout;
   cmd->u.blit_image.dst_image = dstImage;
   cmd->u.blit_image.dst_image_layout = dstImageLayout;
   cmd->u.blit_image.region_count = regionCount;
   if (pRegions) {
      cmd->u.blit_image.regions = vk_zalloc(queue->alloc, sizeof(*cmd->u.blit_image.regions) * (regionCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.blit_image.regions == NULL) goto err;
      memcpy((void*)cmd->u.blit_image.regions, pRegions, sizeof(*cmd->u.blit_image.regions) * (regionCount));
   }
   cmd->u.blit_image.filter = filter;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_blit_image(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_copy_buffer_to_image(struct vk_cmd_queue *queue,
                                 struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkBufferImageCopy* )cmd->u.copy_buffer_to_image.regions);
}

VkResult vk_enqueue_cmd_copy_buffer_to_image(struct vk_cmd_queue *queue
, VkBuffer srcBuffer
, VkImage dstImage
, VkImageLayout dstImageLayout
, uint32_t regionCount
, const VkBufferImageCopy* pRegions
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_BUFFER_TO_IMAGE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_BUFFER_TO_IMAGE;
   cmd->u.copy_buffer_to_image.src_buffer = srcBuffer;
   cmd->u.copy_buffer_to_image.dst_image = dstImage;
   cmd->u.copy_buffer_to_image.dst_image_layout = dstImageLayout;
   cmd->u.copy_buffer_to_image.region_count = regionCount;
   if (pRegions) {
      cmd->u.copy_buffer_to_image.regions = vk_zalloc(queue->alloc, sizeof(*cmd->u.copy_buffer_to_image.regions) * (regionCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.copy_buffer_to_image.regions == NULL) goto err;
      memcpy((void*)cmd->u.copy_buffer_to_image.regions, pRegions, sizeof(*cmd->u.copy_buffer_to_image.regions) * (regionCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_copy_buffer_to_image(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_copy_image_to_buffer(struct vk_cmd_queue *queue,
                                 struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkBufferImageCopy* )cmd->u.copy_image_to_buffer.regions);
}

VkResult vk_enqueue_cmd_copy_image_to_buffer(struct vk_cmd_queue *queue
, VkImage srcImage
, VkImageLayout srcImageLayout
, VkBuffer dstBuffer
, uint32_t regionCount
, const VkBufferImageCopy* pRegions
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_IMAGE_TO_BUFFER], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_IMAGE_TO_BUFFER;
   cmd->u.copy_image_to_buffer.src_image = srcImage;
   cmd->u.copy_image_to_buffer.src_image_layout = srcImageLayout;
   cmd->u.copy_image_to_buffer.dst_buffer = dstBuffer;
   cmd->u.copy_image_to_buffer.region_count = regionCount;
   if (pRegions) {
      cmd->u.copy_image_to_buffer.regions = vk_zalloc(queue->alloc, sizeof(*cmd->u.copy_image_to_buffer.regions) * (regionCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.copy_image_to_buffer.regions == NULL) goto err;
      memcpy((void*)cmd->u.copy_image_to_buffer.regions, pRegions, sizeof(*cmd->u.copy_image_to_buffer.regions) * (regionCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_copy_image_to_buffer(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_copy_memory_indirect_nv(struct vk_cmd_queue *queue,
                                    struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_copy_memory_indirect_nv(struct vk_cmd_queue *queue
, VkDeviceAddress copyBufferAddress
, uint32_t copyCount
, uint32_t stride
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_MEMORY_INDIRECT_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_MEMORY_INDIRECT_NV;
   cmd->u.copy_memory_indirect_nv.copy_buffer_address = copyBufferAddress;
   cmd->u.copy_memory_indirect_nv.copy_count = copyCount;
   cmd->u.copy_memory_indirect_nv.stride = stride;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_copy_memory_indirect_khr(struct vk_cmd_queue *queue,
                                     struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.copy_memory_indirect_khr.copy_memory_indirect_info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.copy_memory_indirect_khr.copy_memory_indirect_info);

}

VkResult vk_enqueue_cmd_copy_memory_indirect_khr(struct vk_cmd_queue *queue
, const VkCopyMemoryIndirectInfoKHR* pCopyMemoryIndirectInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_MEMORY_INDIRECT_KHR], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_MEMORY_INDIRECT_KHR;
   if (pCopyMemoryIndirectInfo) {
      cmd->u.copy_memory_indirect_khr.copy_memory_indirect_info = vk_zalloc(queue->alloc, sizeof(VkCopyMemoryIndirectInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.copy_memory_indirect_khr.copy_memory_indirect_info == NULL) goto err;
      VkCopyMemoryIndirectInfoKHR *tmp_dst1 = (void *)cmd->u.copy_memory_indirect_khr.copy_memory_indirect_info;
      VkCopyMemoryIndirectInfoKHR *tmp_src2 = (void *)pCopyMemoryIndirectInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkCopyMemoryIndirectInfoKHR));
   } else {
      cmd->u.copy_memory_indirect_khr.copy_memory_indirect_info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_copy_memory_indirect_khr(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_copy_memory_to_image_indirect_nv(struct vk_cmd_queue *queue,
                                             struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkImageSubresourceLayers* )cmd->u.copy_memory_to_image_indirect_nv.image_subresources);
}

VkResult vk_enqueue_cmd_copy_memory_to_image_indirect_nv(struct vk_cmd_queue *queue
, VkDeviceAddress copyBufferAddress
, uint32_t copyCount
, uint32_t stride
, VkImage dstImage
, VkImageLayout dstImageLayout
, const VkImageSubresourceLayers* pImageSubresources
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_MEMORY_TO_IMAGE_INDIRECT_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_MEMORY_TO_IMAGE_INDIRECT_NV;
   cmd->u.copy_memory_to_image_indirect_nv.copy_buffer_address = copyBufferAddress;
   cmd->u.copy_memory_to_image_indirect_nv.copy_count = copyCount;
   cmd->u.copy_memory_to_image_indirect_nv.stride = stride;
   cmd->u.copy_memory_to_image_indirect_nv.dst_image = dstImage;
   cmd->u.copy_memory_to_image_indirect_nv.dst_image_layout = dstImageLayout;
   if (pImageSubresources) {
      cmd->u.copy_memory_to_image_indirect_nv.image_subresources = vk_zalloc(queue->alloc, sizeof(*cmd->u.copy_memory_to_image_indirect_nv.image_subresources) * (copyCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.copy_memory_to_image_indirect_nv.image_subresources == NULL) goto err;
      memcpy((void*)cmd->u.copy_memory_to_image_indirect_nv.image_subresources, pImageSubresources, sizeof(*cmd->u.copy_memory_to_image_indirect_nv.image_subresources) * (copyCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_copy_memory_to_image_indirect_nv(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_copy_memory_to_image_indirect_khr(struct vk_cmd_queue *queue,
                                              struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.copy_memory_to_image_indirect_khr.copy_memory_to_image_indirect_info) {
      VkImageSubresourceLayers *pImageSubresources1 = (void *)(cmd->u.copy_memory_to_image_indirect_khr.copy_memory_to_image_indirect_info->pImageSubresources);
      if (cmd->u.copy_memory_to_image_indirect_khr.copy_memory_to_image_indirect_info->copyCount) {
      }
      vk_free(queue->alloc, pImageSubresources1);
   }
   vk_free(queue->alloc, (void*)cmd->u.copy_memory_to_image_indirect_khr.copy_memory_to_image_indirect_info);

}

VkResult vk_enqueue_cmd_copy_memory_to_image_indirect_khr(struct vk_cmd_queue *queue
, const VkCopyMemoryToImageIndirectInfoKHR* pCopyMemoryToImageIndirectInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_MEMORY_TO_IMAGE_INDIRECT_KHR], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_MEMORY_TO_IMAGE_INDIRECT_KHR;
   if (pCopyMemoryToImageIndirectInfo) {
      cmd->u.copy_memory_to_image_indirect_khr.copy_memory_to_image_indirect_info = vk_zalloc(queue->alloc, sizeof(VkCopyMemoryToImageIndirectInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.copy_memory_to_image_indirect_khr.copy_memory_to_image_indirect_info == NULL) goto err;
      VkCopyMemoryToImageIndirectInfoKHR *tmp_dst1 = (void *)cmd->u.copy_memory_to_image_indirect_khr.copy_memory_to_image_indirect_info;
      VkCopyMemoryToImageIndirectInfoKHR *tmp_src2 = (void *)pCopyMemoryToImageIndirectInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkCopyMemoryToImageIndirectInfoKHR));
      if (tmp_src2->pImageSubresources) {
         tmp_dst1->pImageSubresources = vk_zalloc(queue->alloc, sizeof(VkImageSubresourceLayers) * tmp_src2->copyCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pImageSubresources == NULL) goto err;
         VkImageSubresourceLayers *tmp_dst3 = (void *)tmp_dst1->pImageSubresources;
         VkImageSubresourceLayers *tmp_src4 = (void *)tmp_src2->pImageSubresources;
         memcpy(tmp_dst3, tmp_src4, sizeof(VkImageSubresourceLayers) * tmp_src2->copyCount);
         for (uint32_t i5 = 0; i5 < tmp_src2->copyCount; i5++) {
            VkImageSubresourceLayers *tmp_dst6 = tmp_dst3 + i5; (void)tmp_dst6;
            VkImageSubresourceLayers *tmp_src7 = tmp_src4 + i5; (void)tmp_src7;
            }
         } else {
            tmp_dst1->pImageSubresources = NULL;
         }
      } else {
         cmd->u.copy_memory_to_image_indirect_khr.copy_memory_to_image_indirect_info = NULL;
      }

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_copy_memory_to_image_indirect_khr(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_update_buffer(struct vk_cmd_queue *queue,
                          struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( void* )cmd->u.update_buffer.data);
}

VkResult vk_enqueue_cmd_update_buffer(struct vk_cmd_queue *queue
, VkBuffer dstBuffer
, VkDeviceSize dstOffset
, VkDeviceSize dataSize
, const void* pData
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_UPDATE_BUFFER], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_UPDATE_BUFFER;
   cmd->u.update_buffer.dst_buffer = dstBuffer;
   cmd->u.update_buffer.dst_offset = dstOffset;
   cmd->u.update_buffer.data_size = dataSize;
   if (pData) {
      cmd->u.update_buffer.data = vk_zalloc(queue->alloc, 1 * (dataSize), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.update_buffer.data == NULL) goto err;
      memcpy((void*)cmd->u.update_buffer.data, pData, 1 * (dataSize));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_update_buffer(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_fill_buffer(struct vk_cmd_queue *queue,
                        struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_fill_buffer(struct vk_cmd_queue *queue
, VkBuffer dstBuffer
, VkDeviceSize dstOffset
, VkDeviceSize size
, uint32_t data
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_FILL_BUFFER], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_FILL_BUFFER;
   cmd->u.fill_buffer.dst_buffer = dstBuffer;
   cmd->u.fill_buffer.dst_offset = dstOffset;
   cmd->u.fill_buffer.size = size;
   cmd->u.fill_buffer.data = data;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_clear_color_image(struct vk_cmd_queue *queue,
                              struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, (void*)cmd->u.clear_color_image.color);

   vk_free(queue->alloc, ( VkImageSubresourceRange* )cmd->u.clear_color_image.ranges);
}

VkResult vk_enqueue_cmd_clear_color_image(struct vk_cmd_queue *queue
, VkImage image
, VkImageLayout imageLayout
, const VkClearColorValue* pColor
, uint32_t rangeCount
, const VkImageSubresourceRange* pRanges
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_CLEAR_COLOR_IMAGE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_CLEAR_COLOR_IMAGE;
   cmd->u.clear_color_image.image = image;
   cmd->u.clear_color_image.image_layout = imageLayout;
   if (pColor) {
      cmd->u.clear_color_image.color = vk_zalloc(queue->alloc, sizeof(VkClearColorValue), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.clear_color_image.color == NULL) goto err;
      VkClearColorValue *tmp_dst1 = (void *)cmd->u.clear_color_image.color;
      VkClearColorValue *tmp_src2 = (void *)pColor;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkClearColorValue));
   } else {
      cmd->u.clear_color_image.color = NULL;
   }
   cmd->u.clear_color_image.range_count = rangeCount;
   if (pRanges) {
      cmd->u.clear_color_image.ranges = vk_zalloc(queue->alloc, sizeof(*cmd->u.clear_color_image.ranges) * (rangeCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.clear_color_image.ranges == NULL) goto err;
      memcpy((void*)cmd->u.clear_color_image.ranges, pRanges, sizeof(*cmd->u.clear_color_image.ranges) * (rangeCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_clear_color_image(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_clear_depth_stencil_image(struct vk_cmd_queue *queue,
                                      struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.clear_depth_stencil_image.depth_stencil) {
   }
   vk_free(queue->alloc, (void*)cmd->u.clear_depth_stencil_image.depth_stencil);

   vk_free(queue->alloc, ( VkImageSubresourceRange* )cmd->u.clear_depth_stencil_image.ranges);
}

VkResult vk_enqueue_cmd_clear_depth_stencil_image(struct vk_cmd_queue *queue
, VkImage image
, VkImageLayout imageLayout
, const VkClearDepthStencilValue* pDepthStencil
, uint32_t rangeCount
, const VkImageSubresourceRange* pRanges
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_CLEAR_DEPTH_STENCIL_IMAGE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_CLEAR_DEPTH_STENCIL_IMAGE;
   cmd->u.clear_depth_stencil_image.image = image;
   cmd->u.clear_depth_stencil_image.image_layout = imageLayout;
   if (pDepthStencil) {
      cmd->u.clear_depth_stencil_image.depth_stencil = vk_zalloc(queue->alloc, sizeof(VkClearDepthStencilValue), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.clear_depth_stencil_image.depth_stencil == NULL) goto err;
      VkClearDepthStencilValue *tmp_dst1 = (void *)cmd->u.clear_depth_stencil_image.depth_stencil;
      VkClearDepthStencilValue *tmp_src2 = (void *)pDepthStencil;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkClearDepthStencilValue));
   } else {
      cmd->u.clear_depth_stencil_image.depth_stencil = NULL;
   }
   cmd->u.clear_depth_stencil_image.range_count = rangeCount;
   if (pRanges) {
      cmd->u.clear_depth_stencil_image.ranges = vk_zalloc(queue->alloc, sizeof(*cmd->u.clear_depth_stencil_image.ranges) * (rangeCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.clear_depth_stencil_image.ranges == NULL) goto err;
      memcpy((void*)cmd->u.clear_depth_stencil_image.ranges, pRanges, sizeof(*cmd->u.clear_depth_stencil_image.ranges) * (rangeCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_clear_depth_stencil_image(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_clear_attachments(struct vk_cmd_queue *queue,
                              struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkClearAttachment* )cmd->u.clear_attachments.attachments);
   vk_free(queue->alloc, ( VkClearRect* )cmd->u.clear_attachments.rects);
}

VkResult vk_enqueue_cmd_clear_attachments(struct vk_cmd_queue *queue
, uint32_t attachmentCount
, const VkClearAttachment* pAttachments
, uint32_t rectCount
, const VkClearRect* pRects
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_CLEAR_ATTACHMENTS], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_CLEAR_ATTACHMENTS;
   cmd->u.clear_attachments.attachment_count = attachmentCount;
   if (pAttachments) {
      cmd->u.clear_attachments.attachments = vk_zalloc(queue->alloc, sizeof(*cmd->u.clear_attachments.attachments) * (attachmentCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.clear_attachments.attachments == NULL) goto err;
      memcpy((void*)cmd->u.clear_attachments.attachments, pAttachments, sizeof(*cmd->u.clear_attachments.attachments) * (attachmentCount));
   }
   cmd->u.clear_attachments.rect_count = rectCount;
   if (pRects) {
      cmd->u.clear_attachments.rects = vk_zalloc(queue->alloc, sizeof(*cmd->u.clear_attachments.rects) * (rectCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.clear_attachments.rects == NULL) goto err;
      memcpy((void*)cmd->u.clear_attachments.rects, pRects, sizeof(*cmd->u.clear_attachments.rects) * (rectCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_clear_attachments(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_resolve_image(struct vk_cmd_queue *queue,
                          struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkImageResolve* )cmd->u.resolve_image.regions);
}

VkResult vk_enqueue_cmd_resolve_image(struct vk_cmd_queue *queue
, VkImage srcImage
, VkImageLayout srcImageLayout
, VkImage dstImage
, VkImageLayout dstImageLayout
, uint32_t regionCount
, const VkImageResolve* pRegions
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_RESOLVE_IMAGE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_RESOLVE_IMAGE;
   cmd->u.resolve_image.src_image = srcImage;
   cmd->u.resolve_image.src_image_layout = srcImageLayout;
   cmd->u.resolve_image.dst_image = dstImage;
   cmd->u.resolve_image.dst_image_layout = dstImageLayout;
   cmd->u.resolve_image.region_count = regionCount;
   if (pRegions) {
      cmd->u.resolve_image.regions = vk_zalloc(queue->alloc, sizeof(*cmd->u.resolve_image.regions) * (regionCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.resolve_image.regions == NULL) goto err;
      memcpy((void*)cmd->u.resolve_image.regions, pRegions, sizeof(*cmd->u.resolve_image.regions) * (regionCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_resolve_image(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_event(struct vk_cmd_queue *queue,
                      struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_event(struct vk_cmd_queue *queue
, VkEvent event
, VkPipelineStageFlags stageMask
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_EVENT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_EVENT;
   cmd->u.set_event.event = event;
   cmd->u.set_event.stage_mask = stageMask;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_reset_event(struct vk_cmd_queue *queue,
                        struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_reset_event(struct vk_cmd_queue *queue
, VkEvent event
, VkPipelineStageFlags stageMask
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_RESET_EVENT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_RESET_EVENT;
   cmd->u.reset_event.event = event;
   cmd->u.reset_event.stage_mask = stageMask;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_wait_events(struct vk_cmd_queue *queue,
                        struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkEvent* )cmd->u.wait_events.events);
   vk_free(queue->alloc, ( VkMemoryBarrier* )cmd->u.wait_events.memory_barriers);
   vk_free(queue->alloc, ( VkBufferMemoryBarrier* )cmd->u.wait_events.buffer_memory_barriers);
   vk_free(queue->alloc, ( VkImageMemoryBarrier* )cmd->u.wait_events.image_memory_barriers);
}

VkResult vk_enqueue_cmd_wait_events(struct vk_cmd_queue *queue
, uint32_t eventCount
, const VkEvent* pEvents
, VkPipelineStageFlags srcStageMask
, VkPipelineStageFlags dstStageMask
, uint32_t memoryBarrierCount
, const VkMemoryBarrier* pMemoryBarriers
, uint32_t bufferMemoryBarrierCount
, const VkBufferMemoryBarrier* pBufferMemoryBarriers
, uint32_t imageMemoryBarrierCount
, const VkImageMemoryBarrier* pImageMemoryBarriers
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_WAIT_EVENTS], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_WAIT_EVENTS;
   cmd->u.wait_events.event_count = eventCount;
   if (pEvents) {
      cmd->u.wait_events.events = vk_zalloc(queue->alloc, sizeof(*cmd->u.wait_events.events) * (eventCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.wait_events.events == NULL) goto err;
      memcpy((void*)cmd->u.wait_events.events, pEvents, sizeof(*cmd->u.wait_events.events) * (eventCount));
   }
   cmd->u.wait_events.src_stage_mask = srcStageMask;
   cmd->u.wait_events.dst_stage_mask = dstStageMask;
   cmd->u.wait_events.memory_barrier_count = memoryBarrierCount;
   if (pMemoryBarriers) {
      cmd->u.wait_events.memory_barriers = vk_zalloc(queue->alloc, sizeof(*cmd->u.wait_events.memory_barriers) * (memoryBarrierCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.wait_events.memory_barriers == NULL) goto err;
      memcpy((void*)cmd->u.wait_events.memory_barriers, pMemoryBarriers, sizeof(*cmd->u.wait_events.memory_barriers) * (memoryBarrierCount));
   }
   cmd->u.wait_events.buffer_memory_barrier_count = bufferMemoryBarrierCount;
   if (pBufferMemoryBarriers) {
      cmd->u.wait_events.buffer_memory_barriers = vk_zalloc(queue->alloc, sizeof(*cmd->u.wait_events.buffer_memory_barriers) * (bufferMemoryBarrierCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.wait_events.buffer_memory_barriers == NULL) goto err;
      memcpy((void*)cmd->u.wait_events.buffer_memory_barriers, pBufferMemoryBarriers, sizeof(*cmd->u.wait_events.buffer_memory_barriers) * (bufferMemoryBarrierCount));
   }
   cmd->u.wait_events.image_memory_barrier_count = imageMemoryBarrierCount;
   if (pImageMemoryBarriers) {
      cmd->u.wait_events.image_memory_barriers = vk_zalloc(queue->alloc, sizeof(*cmd->u.wait_events.image_memory_barriers) * (imageMemoryBarrierCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.wait_events.image_memory_barriers == NULL) goto err;
      memcpy((void*)cmd->u.wait_events.image_memory_barriers, pImageMemoryBarriers, sizeof(*cmd->u.wait_events.image_memory_barriers) * (imageMemoryBarrierCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_wait_events(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_pipeline_barrier(struct vk_cmd_queue *queue,
                             struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkMemoryBarrier* )cmd->u.pipeline_barrier.memory_barriers);
   vk_free(queue->alloc, ( VkBufferMemoryBarrier* )cmd->u.pipeline_barrier.buffer_memory_barriers);
   vk_free(queue->alloc, ( VkImageMemoryBarrier* )cmd->u.pipeline_barrier.image_memory_barriers);
}

VkResult vk_enqueue_cmd_pipeline_barrier(struct vk_cmd_queue *queue
, VkPipelineStageFlags srcStageMask
, VkPipelineStageFlags dstStageMask
, VkDependencyFlags dependencyFlags
, uint32_t memoryBarrierCount
, const VkMemoryBarrier* pMemoryBarriers
, uint32_t bufferMemoryBarrierCount
, const VkBufferMemoryBarrier* pBufferMemoryBarriers
, uint32_t imageMemoryBarrierCount
, const VkImageMemoryBarrier* pImageMemoryBarriers
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_PIPELINE_BARRIER], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_PIPELINE_BARRIER;
   cmd->u.pipeline_barrier.src_stage_mask = srcStageMask;
   cmd->u.pipeline_barrier.dst_stage_mask = dstStageMask;
   cmd->u.pipeline_barrier.dependency_flags = dependencyFlags;
   cmd->u.pipeline_barrier.memory_barrier_count = memoryBarrierCount;
   if (pMemoryBarriers) {
      cmd->u.pipeline_barrier.memory_barriers = vk_zalloc(queue->alloc, sizeof(*cmd->u.pipeline_barrier.memory_barriers) * (memoryBarrierCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.pipeline_barrier.memory_barriers == NULL) goto err;
      memcpy((void*)cmd->u.pipeline_barrier.memory_barriers, pMemoryBarriers, sizeof(*cmd->u.pipeline_barrier.memory_barriers) * (memoryBarrierCount));
   }
   cmd->u.pipeline_barrier.buffer_memory_barrier_count = bufferMemoryBarrierCount;
   if (pBufferMemoryBarriers) {
      cmd->u.pipeline_barrier.buffer_memory_barriers = vk_zalloc(queue->alloc, sizeof(*cmd->u.pipeline_barrier.buffer_memory_barriers) * (bufferMemoryBarrierCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.pipeline_barrier.buffer_memory_barriers == NULL) goto err;
      memcpy((void*)cmd->u.pipeline_barrier.buffer_memory_barriers, pBufferMemoryBarriers, sizeof(*cmd->u.pipeline_barrier.buffer_memory_barriers) * (bufferMemoryBarrierCount));
   }
   cmd->u.pipeline_barrier.image_memory_barrier_count = imageMemoryBarrierCount;
   if (pImageMemoryBarriers) {
      cmd->u.pipeline_barrier.image_memory_barriers = vk_zalloc(queue->alloc, sizeof(*cmd->u.pipeline_barrier.image_memory_barriers) * (imageMemoryBarrierCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.pipeline_barrier.image_memory_barriers == NULL) goto err;
      memcpy((void*)cmd->u.pipeline_barrier.image_memory_barriers, pImageMemoryBarriers, sizeof(*cmd->u.pipeline_barrier.image_memory_barriers) * (imageMemoryBarrierCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_pipeline_barrier(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_begin_query(struct vk_cmd_queue *queue,
                        struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_begin_query(struct vk_cmd_queue *queue
, VkQueryPool queryPool
, uint32_t query
, VkQueryControlFlags flags
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BEGIN_QUERY], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BEGIN_QUERY;
   cmd->u.begin_query.query_pool = queryPool;
   cmd->u.begin_query.query = query;
   cmd->u.begin_query.flags = flags;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_end_query(struct vk_cmd_queue *queue,
                      struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_end_query(struct vk_cmd_queue *queue
, VkQueryPool queryPool
, uint32_t query
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_END_QUERY], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_END_QUERY;
   cmd->u.end_query.query_pool = queryPool;
   cmd->u.end_query.query = query;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_begin_conditional_rendering_ext(struct vk_cmd_queue *queue,
                                            struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.begin_conditional_rendering_ext.conditional_rendering_begin) {
   }
   vk_free(queue->alloc, (void*)cmd->u.begin_conditional_rendering_ext.conditional_rendering_begin);

}

VkResult vk_enqueue_cmd_begin_conditional_rendering_ext(struct vk_cmd_queue *queue
, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BEGIN_CONDITIONAL_RENDERING_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BEGIN_CONDITIONAL_RENDERING_EXT;
   if (pConditionalRenderingBegin) {
      cmd->u.begin_conditional_rendering_ext.conditional_rendering_begin = vk_zalloc(queue->alloc, sizeof(VkConditionalRenderingBeginInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.begin_conditional_rendering_ext.conditional_rendering_begin == NULL) goto err;
      VkConditionalRenderingBeginInfoEXT *tmp_dst1 = (void *)cmd->u.begin_conditional_rendering_ext.conditional_rendering_begin;
      VkConditionalRenderingBeginInfoEXT *tmp_src2 = (void *)pConditionalRenderingBegin;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkConditionalRenderingBeginInfoEXT));
   } else {
      cmd->u.begin_conditional_rendering_ext.conditional_rendering_begin = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_begin_conditional_rendering_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_end_conditional_rendering_ext(struct vk_cmd_queue *queue,
                                          struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_end_conditional_rendering_ext(struct vk_cmd_queue *queue
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_END_CONDITIONAL_RENDERING_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_END_CONDITIONAL_RENDERING_EXT;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_reset_query_pool(struct vk_cmd_queue *queue,
                             struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_reset_query_pool(struct vk_cmd_queue *queue
, VkQueryPool queryPool
, uint32_t firstQuery
, uint32_t queryCount
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_RESET_QUERY_POOL], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_RESET_QUERY_POOL;
   cmd->u.reset_query_pool.query_pool = queryPool;
   cmd->u.reset_query_pool.first_query = firstQuery;
   cmd->u.reset_query_pool.query_count = queryCount;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_write_timestamp(struct vk_cmd_queue *queue,
                            struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_write_timestamp(struct vk_cmd_queue *queue
, VkPipelineStageFlagBits pipelineStage
, VkQueryPool queryPool
, uint32_t query
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_WRITE_TIMESTAMP], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_WRITE_TIMESTAMP;
   cmd->u.write_timestamp.pipeline_stage = pipelineStage;
   cmd->u.write_timestamp.query_pool = queryPool;
   cmd->u.write_timestamp.query = query;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_copy_query_pool_results(struct vk_cmd_queue *queue,
                                    struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_copy_query_pool_results(struct vk_cmd_queue *queue
, VkQueryPool queryPool
, uint32_t firstQuery
, uint32_t queryCount
, VkBuffer dstBuffer
, VkDeviceSize dstOffset
, VkDeviceSize stride
, VkQueryResultFlags flags
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_QUERY_POOL_RESULTS], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_QUERY_POOL_RESULTS;
   cmd->u.copy_query_pool_results.query_pool = queryPool;
   cmd->u.copy_query_pool_results.first_query = firstQuery;
   cmd->u.copy_query_pool_results.query_count = queryCount;
   cmd->u.copy_query_pool_results.dst_buffer = dstBuffer;
   cmd->u.copy_query_pool_results.dst_offset = dstOffset;
   cmd->u.copy_query_pool_results.stride = stride;
   cmd->u.copy_query_pool_results.flags = flags;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_push_constants(struct vk_cmd_queue *queue,
                           struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( void* )cmd->u.push_constants.values);
}

VkResult vk_enqueue_cmd_push_constants(struct vk_cmd_queue *queue
, VkPipelineLayout layout
, VkShaderStageFlags stageFlags
, uint32_t offset
, uint32_t size
, const void* pValues
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_PUSH_CONSTANTS], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_PUSH_CONSTANTS;
   cmd->u.push_constants.layout = layout;
   cmd->u.push_constants.stage_flags = stageFlags;
   cmd->u.push_constants.offset = offset;
   cmd->u.push_constants.size = size;
   if (pValues) {
      cmd->u.push_constants.values = vk_zalloc(queue->alloc, 1 * (size), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.push_constants.values == NULL) goto err;
      memcpy((void*)cmd->u.push_constants.values, pValues, 1 * (size));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_push_constants(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_begin_render_pass(struct vk_cmd_queue *queue,
                              struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.begin_render_pass.render_pass_begin) {
      const VkBaseInStructure *pnext1 = cmd->u.begin_render_pass.render_pass_begin->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO: {
            VkRect2D *pDeviceRenderAreas2 = (void *)(((VkDeviceGroupRenderPassBeginInfo *)pnext1)->pDeviceRenderAreas);
            if (((VkDeviceGroupRenderPassBeginInfo *)pnext1)->deviceRenderAreaCount) {
            }
            vk_free(queue->alloc, pDeviceRenderAreas2);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT: {
            VkAttachmentSampleLocationsEXT *pAttachmentInitialSampleLocations3 = (void *)(((VkRenderPassSampleLocationsBeginInfoEXT *)pnext1)->pAttachmentInitialSampleLocations);
            if (((VkRenderPassSampleLocationsBeginInfoEXT *)pnext1)->attachmentInitialSampleLocationsCount) {
            }
            vk_free(queue->alloc, pAttachmentInitialSampleLocations3);
            VkSubpassSampleLocationsEXT *pPostSubpassSampleLocations4 = (void *)(((VkRenderPassSampleLocationsBeginInfoEXT *)pnext1)->pPostSubpassSampleLocations);
            if (((VkRenderPassSampleLocationsBeginInfoEXT *)pnext1)->postSubpassSampleLocationsCount) {
            }
            vk_free(queue->alloc, pPostSubpassSampleLocations4);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO: {
            VkImageView *pAttachments5 = (void *)(((VkRenderPassAttachmentBeginInfo *)pnext1)->pAttachments);
            if (((VkRenderPassAttachmentBeginInfo *)pnext1)->attachmentCount) {
            }
            vk_free(queue->alloc, pAttachments5);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM: {
            VkRect2D *pPerViewRenderAreas6 = (void *)(((VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM *)pnext1)->pPerViewRenderAreas);
            if (((VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM *)pnext1)->perViewRenderAreaCount) {
            }
            vk_free(queue->alloc, pPerViewRenderAreas6);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM: {
            VkRenderPassStripeInfoARM *pStripeInfos7 = (void *)(((VkRenderPassStripeBeginInfoARM *)pnext1)->pStripeInfos);
            if (((VkRenderPassStripeBeginInfoARM *)pnext1)->stripeInfoCount) {
            }
            vk_free(queue->alloc, pStripeInfos7);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
      VkClearValue *pClearValues8 = (void *)(cmd->u.begin_render_pass.render_pass_begin->pClearValues);
      if (cmd->u.begin_render_pass.render_pass_begin->clearValueCount) {
      }
      vk_free(queue->alloc, pClearValues8);
   }
   vk_free(queue->alloc, (void*)cmd->u.begin_render_pass.render_pass_begin);

}

VkResult vk_enqueue_cmd_begin_render_pass(struct vk_cmd_queue *queue
, const VkRenderPassBeginInfo* pRenderPassBegin
, VkSubpassContents contents
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BEGIN_RENDER_PASS], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BEGIN_RENDER_PASS;
   if (pRenderPassBegin) {
      cmd->u.begin_render_pass.render_pass_begin = vk_zalloc(queue->alloc, sizeof(VkRenderPassBeginInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.begin_render_pass.render_pass_begin == NULL) goto err;
      VkRenderPassBeginInfo *tmp_dst1 = (void *)cmd->u.begin_render_pass.render_pass_begin;
      VkRenderPassBeginInfo *tmp_src2 = (void *)pRenderPassBegin;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkRenderPassBeginInfo));
      const VkBaseInStructure *pnext = tmp_dst1->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkDeviceGroupRenderPassBeginInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkDeviceGroupRenderPassBeginInfo *tmp_dst3 = (void *)tmp_dst1->pNext;
               VkDeviceGroupRenderPassBeginInfo *tmp_src4 = (void *)pnext;
               memcpy(tmp_dst3, tmp_src4, sizeof(VkDeviceGroupRenderPassBeginInfo));
               if (tmp_src4->pDeviceRenderAreas) {
                  tmp_dst3->pDeviceRenderAreas = vk_zalloc(queue->alloc, sizeof(VkRect2D) * tmp_src4->deviceRenderAreaCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst3->pDeviceRenderAreas == NULL) goto err;
                  VkRect2D *tmp_dst5 = (void *)tmp_dst3->pDeviceRenderAreas;
                  VkRect2D *tmp_src6 = (void *)tmp_src4->pDeviceRenderAreas;
                  memcpy(tmp_dst5, tmp_src6, sizeof(VkRect2D) * tmp_src4->deviceRenderAreaCount);
                  for (uint32_t i7 = 0; i7 < tmp_src4->deviceRenderAreaCount; i7++) {
                     VkRect2D *tmp_dst8 = tmp_dst5 + i7; (void)tmp_dst8;
                     VkRect2D *tmp_src9 = tmp_src6 + i7; (void)tmp_src9;
                     }
                  } else {
                     tmp_dst3->pDeviceRenderAreas = NULL;
                  }
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkRenderPassSampleLocationsBeginInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkRenderPassSampleLocationsBeginInfoEXT *tmp_dst10 = (void *)tmp_dst1->pNext;
                  VkRenderPassSampleLocationsBeginInfoEXT *tmp_src11 = (void *)pnext;
                  memcpy(tmp_dst10, tmp_src11, sizeof(VkRenderPassSampleLocationsBeginInfoEXT));
                  if (tmp_src11->pAttachmentInitialSampleLocations) {
                     tmp_dst10->pAttachmentInitialSampleLocations = vk_zalloc(queue->alloc, sizeof(VkAttachmentSampleLocationsEXT) * tmp_src11->attachmentInitialSampleLocationsCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst10->pAttachmentInitialSampleLocations == NULL) goto err;
                     VkAttachmentSampleLocationsEXT *tmp_dst12 = (void *)tmp_dst10->pAttachmentInitialSampleLocations;
                     VkAttachmentSampleLocationsEXT *tmp_src13 = (void *)tmp_src11->pAttachmentInitialSampleLocations;
                     memcpy(tmp_dst12, tmp_src13, sizeof(VkAttachmentSampleLocationsEXT) * tmp_src11->attachmentInitialSampleLocationsCount);
                     for (uint32_t i14 = 0; i14 < tmp_src11->attachmentInitialSampleLocationsCount; i14++) {
                        VkAttachmentSampleLocationsEXT *tmp_dst15 = tmp_dst12 + i14; (void)tmp_dst15;
                        VkAttachmentSampleLocationsEXT *tmp_src16 = tmp_src13 + i14; (void)tmp_src16;
                        }
                     } else {
                        tmp_dst10->pAttachmentInitialSampleLocations = NULL;
                     }
                     if (tmp_src11->pPostSubpassSampleLocations) {
                        tmp_dst10->pPostSubpassSampleLocations = vk_zalloc(queue->alloc, sizeof(VkSubpassSampleLocationsEXT) * tmp_src11->postSubpassSampleLocationsCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst10->pPostSubpassSampleLocations == NULL) goto err;
                        VkSubpassSampleLocationsEXT *tmp_dst17 = (void *)tmp_dst10->pPostSubpassSampleLocations;
                        VkSubpassSampleLocationsEXT *tmp_src18 = (void *)tmp_src11->pPostSubpassSampleLocations;
                        memcpy(tmp_dst17, tmp_src18, sizeof(VkSubpassSampleLocationsEXT) * tmp_src11->postSubpassSampleLocationsCount);
                        for (uint32_t i19 = 0; i19 < tmp_src11->postSubpassSampleLocationsCount; i19++) {
                           VkSubpassSampleLocationsEXT *tmp_dst20 = tmp_dst17 + i19; (void)tmp_dst20;
                           VkSubpassSampleLocationsEXT *tmp_src21 = tmp_src18 + i19; (void)tmp_src21;
                           }
                        } else {
                           tmp_dst10->pPostSubpassSampleLocations = NULL;
                        }
                     } else {
                        tmp_dst1->pNext = NULL;
                     }
                     break;
                  case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
                     if (pnext) {
                        tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkRenderPassAttachmentBeginInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst1->pNext == NULL) goto err;
                        VkRenderPassAttachmentBeginInfo *tmp_dst22 = (void *)tmp_dst1->pNext;
                        VkRenderPassAttachmentBeginInfo *tmp_src23 = (void *)pnext;
                        memcpy(tmp_dst22, tmp_src23, sizeof(VkRenderPassAttachmentBeginInfo));
                        if (tmp_src23->pAttachments) {
                           tmp_dst22->pAttachments = vk_zalloc(queue->alloc, sizeof(VkImageView) * tmp_src23->attachmentCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst22->pAttachments == NULL) goto err;
                           VkImageView *tmp_dst24 = (void *)tmp_dst22->pAttachments;
                           VkImageView *tmp_src25 = (void *)tmp_src23->pAttachments;
                           memcpy(tmp_dst24, tmp_src25, sizeof(VkImageView) * tmp_src23->attachmentCount);
                           for (uint32_t i26 = 0; i26 < tmp_src23->attachmentCount; i26++) {
                              VkImageView *tmp_dst27 = tmp_dst24 + i26; (void)tmp_dst27;
                              VkImageView *tmp_src28 = tmp_src25 + i26; (void)tmp_src28;
                              }
                           } else {
                              tmp_dst22->pAttachments = NULL;
                           }
                        } else {
                           tmp_dst1->pNext = NULL;
                        }
                        break;
                     case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
                        if (pnext) {
                           tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkRenderPassTransformBeginInfoQCOM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst1->pNext == NULL) goto err;
                           VkRenderPassTransformBeginInfoQCOM *tmp_dst29 = (void *)tmp_dst1->pNext;
                           VkRenderPassTransformBeginInfoQCOM *tmp_src30 = (void *)pnext;
                           memcpy(tmp_dst29, tmp_src30, sizeof(VkRenderPassTransformBeginInfoQCOM));
                        } else {
                           tmp_dst1->pNext = NULL;
                        }
                        break;
                     case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM:
                        if (pnext) {
                           tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst1->pNext == NULL) goto err;
                           VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM *tmp_dst31 = (void *)tmp_dst1->pNext;
                           VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM *tmp_src32 = (void *)pnext;
                           memcpy(tmp_dst31, tmp_src32, sizeof(VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM));
                           if (tmp_src32->pPerViewRenderAreas) {
                              tmp_dst31->pPerViewRenderAreas = vk_zalloc(queue->alloc, sizeof(VkRect2D) * tmp_src32->perViewRenderAreaCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst31->pPerViewRenderAreas == NULL) goto err;
                              VkRect2D *tmp_dst33 = (void *)tmp_dst31->pPerViewRenderAreas;
                              VkRect2D *tmp_src34 = (void *)tmp_src32->pPerViewRenderAreas;
                              memcpy(tmp_dst33, tmp_src34, sizeof(VkRect2D) * tmp_src32->perViewRenderAreaCount);
                              for (uint32_t i35 = 0; i35 < tmp_src32->perViewRenderAreaCount; i35++) {
                                 VkRect2D *tmp_dst36 = tmp_dst33 + i35; (void)tmp_dst36;
                                 VkRect2D *tmp_src37 = tmp_src34 + i35; (void)tmp_src37;
                                 }
                              } else {
                                 tmp_dst31->pPerViewRenderAreas = NULL;
                              }
                           } else {
                              tmp_dst1->pNext = NULL;
                           }
                           break;
                        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM:
                           if (pnext) {
                              tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkRenderPassStripeBeginInfoARM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst1->pNext == NULL) goto err;
                              VkRenderPassStripeBeginInfoARM *tmp_dst38 = (void *)tmp_dst1->pNext;
                              VkRenderPassStripeBeginInfoARM *tmp_src39 = (void *)pnext;
                              memcpy(tmp_dst38, tmp_src39, sizeof(VkRenderPassStripeBeginInfoARM));
                              if (tmp_src39->pStripeInfos) {
                                 tmp_dst38->pStripeInfos = vk_zalloc(queue->alloc, sizeof(VkRenderPassStripeInfoARM) * tmp_src39->stripeInfoCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst38->pStripeInfos == NULL) goto err;
                                 VkRenderPassStripeInfoARM *tmp_dst40 = (void *)tmp_dst38->pStripeInfos;
                                 VkRenderPassStripeInfoARM *tmp_src41 = (void *)tmp_src39->pStripeInfos;
                                 memcpy(tmp_dst40, tmp_src41, sizeof(VkRenderPassStripeInfoARM) * tmp_src39->stripeInfoCount);
                                 for (uint32_t i42 = 0; i42 < tmp_src39->stripeInfoCount; i42++) {
                                    VkRenderPassStripeInfoARM *tmp_dst43 = tmp_dst40 + i42; (void)tmp_dst43;
                                    VkRenderPassStripeInfoARM *tmp_src44 = tmp_src41 + i42; (void)tmp_src44;
                                    }
                                 } else {
                                    tmp_dst38->pStripeInfos = NULL;
                                 }
                              } else {
                                 tmp_dst1->pNext = NULL;
                              }
                              break;
                           }
                        }
                        if (tmp_src2->pClearValues) {
                           tmp_dst1->pClearValues = vk_zalloc(queue->alloc, sizeof(VkClearValue) * tmp_src2->clearValueCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst1->pClearValues == NULL) goto err;
                           VkClearValue *tmp_dst45 = (void *)tmp_dst1->pClearValues;
                           VkClearValue *tmp_src46 = (void *)tmp_src2->pClearValues;
                           memcpy(tmp_dst45, tmp_src46, sizeof(VkClearValue) * tmp_src2->clearValueCount);
                           for (uint32_t i47 = 0; i47 < tmp_src2->clearValueCount; i47++) {
                              VkClearValue *tmp_dst48 = tmp_dst45 + i47; (void)tmp_dst48;
                              VkClearValue *tmp_src49 = tmp_src46 + i47; (void)tmp_src49;
                              }
                           } else {
                              tmp_dst1->pClearValues = NULL;
                           }
                        } else {
                           cmd->u.begin_render_pass.render_pass_begin = NULL;
                        }
                        cmd->u.begin_render_pass.contents = contents;

                        list_addtail(&cmd->cmd_link, &queue->cmds);
                        return VK_SUCCESS;

err:
                        if (cmd)
                           vk_free_cmd_begin_render_pass(queue, cmd);
                        return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_next_subpass(struct vk_cmd_queue *queue,
                         struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_next_subpass(struct vk_cmd_queue *queue
, VkSubpassContents contents
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_NEXT_SUBPASS], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_NEXT_SUBPASS;
   cmd->u.next_subpass.contents = contents;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_end_render_pass(struct vk_cmd_queue *queue,
                            struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_end_render_pass(struct vk_cmd_queue *queue
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_END_RENDER_PASS], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_END_RENDER_PASS;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_execute_commands(struct vk_cmd_queue *queue,
                             struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkCommandBuffer* )cmd->u.execute_commands.command_buffers);
}

VkResult vk_enqueue_cmd_execute_commands(struct vk_cmd_queue *queue
, uint32_t commandBufferCount
, const VkCommandBuffer* pCommandBuffers
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_EXECUTE_COMMANDS], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_EXECUTE_COMMANDS;
   cmd->u.execute_commands.command_buffer_count = commandBufferCount;
   if (pCommandBuffers) {
      cmd->u.execute_commands.command_buffers = vk_zalloc(queue->alloc, sizeof(*cmd->u.execute_commands.command_buffers) * (commandBufferCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.execute_commands.command_buffers == NULL) goto err;
      memcpy((void*)cmd->u.execute_commands.command_buffers, pCommandBuffers, sizeof(*cmd->u.execute_commands.command_buffers) * (commandBufferCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_execute_commands(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_debug_marker_begin_ext(struct vk_cmd_queue *queue,
                                   struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.debug_marker_begin_ext.marker_info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.debug_marker_begin_ext.marker_info);

}

VkResult vk_enqueue_cmd_debug_marker_begin_ext(struct vk_cmd_queue *queue
, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DEBUG_MARKER_BEGIN_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DEBUG_MARKER_BEGIN_EXT;
   if (pMarkerInfo) {
      cmd->u.debug_marker_begin_ext.marker_info = vk_zalloc(queue->alloc, sizeof(VkDebugMarkerMarkerInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.debug_marker_begin_ext.marker_info == NULL) goto err;
      VkDebugMarkerMarkerInfoEXT *tmp_dst1 = (void *)cmd->u.debug_marker_begin_ext.marker_info;
      VkDebugMarkerMarkerInfoEXT *tmp_src2 = (void *)pMarkerInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkDebugMarkerMarkerInfoEXT));
      tmp_dst1->pMarkerName = strdup(tmp_src2->pMarkerName);
   } else {
      cmd->u.debug_marker_begin_ext.marker_info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_debug_marker_begin_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_debug_marker_end_ext(struct vk_cmd_queue *queue,
                                 struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_debug_marker_end_ext(struct vk_cmd_queue *queue
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DEBUG_MARKER_END_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DEBUG_MARKER_END_EXT;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_debug_marker_insert_ext(struct vk_cmd_queue *queue,
                                    struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.debug_marker_insert_ext.marker_info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.debug_marker_insert_ext.marker_info);

}

VkResult vk_enqueue_cmd_debug_marker_insert_ext(struct vk_cmd_queue *queue
, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DEBUG_MARKER_INSERT_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DEBUG_MARKER_INSERT_EXT;
   if (pMarkerInfo) {
      cmd->u.debug_marker_insert_ext.marker_info = vk_zalloc(queue->alloc, sizeof(VkDebugMarkerMarkerInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.debug_marker_insert_ext.marker_info == NULL) goto err;
      VkDebugMarkerMarkerInfoEXT *tmp_dst1 = (void *)cmd->u.debug_marker_insert_ext.marker_info;
      VkDebugMarkerMarkerInfoEXT *tmp_src2 = (void *)pMarkerInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkDebugMarkerMarkerInfoEXT));
      tmp_dst1->pMarkerName = strdup(tmp_src2->pMarkerName);
   } else {
      cmd->u.debug_marker_insert_ext.marker_info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_debug_marker_insert_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_execute_generated_commands_nv(struct vk_cmd_queue *queue,
                                          struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.execute_generated_commands_nv.generated_commands_info) {
      VkIndirectCommandsStreamNV *pStreams1 = (void *)(cmd->u.execute_generated_commands_nv.generated_commands_info->pStreams);
      if (cmd->u.execute_generated_commands_nv.generated_commands_info->streamCount) {
      }
      vk_free(queue->alloc, pStreams1);
   }
   vk_free(queue->alloc, (void*)cmd->u.execute_generated_commands_nv.generated_commands_info);

}

VkResult vk_enqueue_cmd_execute_generated_commands_nv(struct vk_cmd_queue *queue
, VkBool32 isPreprocessed
, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_EXECUTE_GENERATED_COMMANDS_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_EXECUTE_GENERATED_COMMANDS_NV;
   cmd->u.execute_generated_commands_nv.is_preprocessed = isPreprocessed;
   if (pGeneratedCommandsInfo) {
      cmd->u.execute_generated_commands_nv.generated_commands_info = vk_zalloc(queue->alloc, sizeof(VkGeneratedCommandsInfoNV), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.execute_generated_commands_nv.generated_commands_info == NULL) goto err;
      VkGeneratedCommandsInfoNV *tmp_dst1 = (void *)cmd->u.execute_generated_commands_nv.generated_commands_info;
      VkGeneratedCommandsInfoNV *tmp_src2 = (void *)pGeneratedCommandsInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkGeneratedCommandsInfoNV));
      if (tmp_src2->pStreams) {
         tmp_dst1->pStreams = vk_zalloc(queue->alloc, sizeof(VkIndirectCommandsStreamNV) * tmp_src2->streamCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pStreams == NULL) goto err;
         VkIndirectCommandsStreamNV *tmp_dst3 = (void *)tmp_dst1->pStreams;
         VkIndirectCommandsStreamNV *tmp_src4 = (void *)tmp_src2->pStreams;
         memcpy(tmp_dst3, tmp_src4, sizeof(VkIndirectCommandsStreamNV) * tmp_src2->streamCount);
         for (uint32_t i5 = 0; i5 < tmp_src2->streamCount; i5++) {
            VkIndirectCommandsStreamNV *tmp_dst6 = tmp_dst3 + i5; (void)tmp_dst6;
            VkIndirectCommandsStreamNV *tmp_src7 = tmp_src4 + i5; (void)tmp_src7;
            }
         } else {
            tmp_dst1->pStreams = NULL;
         }
      } else {
         cmd->u.execute_generated_commands_nv.generated_commands_info = NULL;
      }

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_execute_generated_commands_nv(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_preprocess_generated_commands_nv(struct vk_cmd_queue *queue,
                                             struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.preprocess_generated_commands_nv.generated_commands_info) {
      VkIndirectCommandsStreamNV *pStreams1 = (void *)(cmd->u.preprocess_generated_commands_nv.generated_commands_info->pStreams);
      if (cmd->u.preprocess_generated_commands_nv.generated_commands_info->streamCount) {
      }
      vk_free(queue->alloc, pStreams1);
   }
   vk_free(queue->alloc, (void*)cmd->u.preprocess_generated_commands_nv.generated_commands_info);

}

VkResult vk_enqueue_cmd_preprocess_generated_commands_nv(struct vk_cmd_queue *queue
, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_PREPROCESS_GENERATED_COMMANDS_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_PREPROCESS_GENERATED_COMMANDS_NV;
   if (pGeneratedCommandsInfo) {
      cmd->u.preprocess_generated_commands_nv.generated_commands_info = vk_zalloc(queue->alloc, sizeof(VkGeneratedCommandsInfoNV), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.preprocess_generated_commands_nv.generated_commands_info == NULL) goto err;
      VkGeneratedCommandsInfoNV *tmp_dst1 = (void *)cmd->u.preprocess_generated_commands_nv.generated_commands_info;
      VkGeneratedCommandsInfoNV *tmp_src2 = (void *)pGeneratedCommandsInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkGeneratedCommandsInfoNV));
      if (tmp_src2->pStreams) {
         tmp_dst1->pStreams = vk_zalloc(queue->alloc, sizeof(VkIndirectCommandsStreamNV) * tmp_src2->streamCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pStreams == NULL) goto err;
         VkIndirectCommandsStreamNV *tmp_dst3 = (void *)tmp_dst1->pStreams;
         VkIndirectCommandsStreamNV *tmp_src4 = (void *)tmp_src2->pStreams;
         memcpy(tmp_dst3, tmp_src4, sizeof(VkIndirectCommandsStreamNV) * tmp_src2->streamCount);
         for (uint32_t i5 = 0; i5 < tmp_src2->streamCount; i5++) {
            VkIndirectCommandsStreamNV *tmp_dst6 = tmp_dst3 + i5; (void)tmp_dst6;
            VkIndirectCommandsStreamNV *tmp_src7 = tmp_src4 + i5; (void)tmp_src7;
            }
         } else {
            tmp_dst1->pStreams = NULL;
         }
      } else {
         cmd->u.preprocess_generated_commands_nv.generated_commands_info = NULL;
      }

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_preprocess_generated_commands_nv(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_bind_pipeline_shader_group_nv(struct vk_cmd_queue *queue,
                                          struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_bind_pipeline_shader_group_nv(struct vk_cmd_queue *queue
, VkPipelineBindPoint pipelineBindPoint
, VkPipeline pipeline
, uint32_t groupIndex
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BIND_PIPELINE_SHADER_GROUP_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BIND_PIPELINE_SHADER_GROUP_NV;
   cmd->u.bind_pipeline_shader_group_nv.pipeline_bind_point = pipelineBindPoint;
   cmd->u.bind_pipeline_shader_group_nv.pipeline = pipeline;
   cmd->u.bind_pipeline_shader_group_nv.group_index = groupIndex;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_execute_generated_commands_ext(struct vk_cmd_queue *queue,
                                           struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.execute_generated_commands_ext.generated_commands_info) {
      const VkBaseInStructure *pnext1 = cmd->u.execute_generated_commands_ext.generated_commands_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT: {
            VkShaderEXT *pShaders2 = (void *)(((VkGeneratedCommandsShaderInfoEXT *)pnext1)->pShaders);
            if (((VkGeneratedCommandsShaderInfoEXT *)pnext1)->shaderCount) {
            }
            vk_free(queue->alloc, pShaders2);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
   }
   vk_free(queue->alloc, (void*)cmd->u.execute_generated_commands_ext.generated_commands_info);

}

VkResult vk_enqueue_cmd_execute_generated_commands_ext(struct vk_cmd_queue *queue
, VkBool32 isPreprocessed
, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_EXECUTE_GENERATED_COMMANDS_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_EXECUTE_GENERATED_COMMANDS_EXT;
   cmd->u.execute_generated_commands_ext.is_preprocessed = isPreprocessed;
   if (pGeneratedCommandsInfo) {
      cmd->u.execute_generated_commands_ext.generated_commands_info = vk_zalloc(queue->alloc, sizeof(VkGeneratedCommandsInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.execute_generated_commands_ext.generated_commands_info == NULL) goto err;
      VkGeneratedCommandsInfoEXT *tmp_dst1 = (void *)cmd->u.execute_generated_commands_ext.generated_commands_info;
      VkGeneratedCommandsInfoEXT *tmp_src2 = (void *)pGeneratedCommandsInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkGeneratedCommandsInfoEXT));
      const VkBaseInStructure *pnext = tmp_dst1->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkGeneratedCommandsPipelineInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkGeneratedCommandsPipelineInfoEXT *tmp_dst3 = (void *)tmp_dst1->pNext;
               VkGeneratedCommandsPipelineInfoEXT *tmp_src4 = (void *)pnext;
               memcpy(tmp_dst3, tmp_src4, sizeof(VkGeneratedCommandsPipelineInfoEXT));
            } else {
               tmp_dst1->pNext = NULL;
            }
            break;
         case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkGeneratedCommandsShaderInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkGeneratedCommandsShaderInfoEXT *tmp_dst5 = (void *)tmp_dst1->pNext;
               VkGeneratedCommandsShaderInfoEXT *tmp_src6 = (void *)pnext;
               memcpy(tmp_dst5, tmp_src6, sizeof(VkGeneratedCommandsShaderInfoEXT));
               if (tmp_src6->pShaders) {
                  tmp_dst5->pShaders = vk_zalloc(queue->alloc, sizeof(VkShaderEXT) * tmp_src6->shaderCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst5->pShaders == NULL) goto err;
                  VkShaderEXT *tmp_dst7 = (void *)tmp_dst5->pShaders;
                  VkShaderEXT *tmp_src8 = (void *)tmp_src6->pShaders;
                  memcpy(tmp_dst7, tmp_src8, sizeof(VkShaderEXT) * tmp_src6->shaderCount);
                  for (uint32_t i9 = 0; i9 < tmp_src6->shaderCount; i9++) {
                     VkShaderEXT *tmp_dst10 = tmp_dst7 + i9; (void)tmp_dst10;
                     VkShaderEXT *tmp_src11 = tmp_src8 + i9; (void)tmp_src11;
                     }
                  } else {
                     tmp_dst5->pShaders = NULL;
                  }
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            }
         }
      } else {
         cmd->u.execute_generated_commands_ext.generated_commands_info = NULL;
      }

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_execute_generated_commands_ext(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_preprocess_generated_commands_ext(struct vk_cmd_queue *queue,
                                              struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.preprocess_generated_commands_ext.generated_commands_info) {
      const VkBaseInStructure *pnext1 = cmd->u.preprocess_generated_commands_ext.generated_commands_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT: {
            VkShaderEXT *pShaders2 = (void *)(((VkGeneratedCommandsShaderInfoEXT *)pnext1)->pShaders);
            if (((VkGeneratedCommandsShaderInfoEXT *)pnext1)->shaderCount) {
            }
            vk_free(queue->alloc, pShaders2);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
   }
   vk_free(queue->alloc, (void*)cmd->u.preprocess_generated_commands_ext.generated_commands_info);

}

VkResult vk_enqueue_cmd_preprocess_generated_commands_ext(struct vk_cmd_queue *queue
, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo
, VkCommandBuffer stateCommandBuffer
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_PREPROCESS_GENERATED_COMMANDS_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_PREPROCESS_GENERATED_COMMANDS_EXT;
   if (pGeneratedCommandsInfo) {
      cmd->u.preprocess_generated_commands_ext.generated_commands_info = vk_zalloc(queue->alloc, sizeof(VkGeneratedCommandsInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.preprocess_generated_commands_ext.generated_commands_info == NULL) goto err;
      VkGeneratedCommandsInfoEXT *tmp_dst1 = (void *)cmd->u.preprocess_generated_commands_ext.generated_commands_info;
      VkGeneratedCommandsInfoEXT *tmp_src2 = (void *)pGeneratedCommandsInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkGeneratedCommandsInfoEXT));
      const VkBaseInStructure *pnext = tmp_dst1->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkGeneratedCommandsPipelineInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkGeneratedCommandsPipelineInfoEXT *tmp_dst3 = (void *)tmp_dst1->pNext;
               VkGeneratedCommandsPipelineInfoEXT *tmp_src4 = (void *)pnext;
               memcpy(tmp_dst3, tmp_src4, sizeof(VkGeneratedCommandsPipelineInfoEXT));
            } else {
               tmp_dst1->pNext = NULL;
            }
            break;
         case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkGeneratedCommandsShaderInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkGeneratedCommandsShaderInfoEXT *tmp_dst5 = (void *)tmp_dst1->pNext;
               VkGeneratedCommandsShaderInfoEXT *tmp_src6 = (void *)pnext;
               memcpy(tmp_dst5, tmp_src6, sizeof(VkGeneratedCommandsShaderInfoEXT));
               if (tmp_src6->pShaders) {
                  tmp_dst5->pShaders = vk_zalloc(queue->alloc, sizeof(VkShaderEXT) * tmp_src6->shaderCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst5->pShaders == NULL) goto err;
                  VkShaderEXT *tmp_dst7 = (void *)tmp_dst5->pShaders;
                  VkShaderEXT *tmp_src8 = (void *)tmp_src6->pShaders;
                  memcpy(tmp_dst7, tmp_src8, sizeof(VkShaderEXT) * tmp_src6->shaderCount);
                  for (uint32_t i9 = 0; i9 < tmp_src6->shaderCount; i9++) {
                     VkShaderEXT *tmp_dst10 = tmp_dst7 + i9; (void)tmp_dst10;
                     VkShaderEXT *tmp_src11 = tmp_src8 + i9; (void)tmp_src11;
                     }
                  } else {
                     tmp_dst5->pShaders = NULL;
                  }
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            }
         }
      } else {
         cmd->u.preprocess_generated_commands_ext.generated_commands_info = NULL;
      }
      cmd->u.preprocess_generated_commands_ext.state_command_buffer = stateCommandBuffer;

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_preprocess_generated_commands_ext(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_push_descriptor_set(struct vk_cmd_queue *queue,
                                struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkWriteDescriptorSet* )cmd->u.push_descriptor_set.descriptor_writes);
}


static void
vk_free_cmd_set_device_mask(struct vk_cmd_queue *queue,
                            struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_device_mask(struct vk_cmd_queue *queue
, uint32_t deviceMask
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_DEVICE_MASK], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_DEVICE_MASK;
   cmd->u.set_device_mask.device_mask = deviceMask;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_dispatch_base(struct vk_cmd_queue *queue,
                          struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_dispatch_base(struct vk_cmd_queue *queue
, uint32_t baseGroupX
, uint32_t baseGroupY
, uint32_t baseGroupZ
, uint32_t groupCountX
, uint32_t groupCountY
, uint32_t groupCountZ
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DISPATCH_BASE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DISPATCH_BASE;
   cmd->u.dispatch_base.base_group_x = baseGroupX;
   cmd->u.dispatch_base.base_group_y = baseGroupY;
   cmd->u.dispatch_base.base_group_z = baseGroupZ;
   cmd->u.dispatch_base.group_count_x = groupCountX;
   cmd->u.dispatch_base.group_count_y = groupCountY;
   cmd->u.dispatch_base.group_count_z = groupCountZ;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_push_descriptor_set_with_template(struct vk_cmd_queue *queue,
                                              struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, (void*)cmd->u.push_descriptor_set_with_template.data);

}


static void
vk_free_cmd_set_viewport_wscaling_nv(struct vk_cmd_queue *queue,
                                     struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkViewportWScalingNV* )cmd->u.set_viewport_wscaling_nv.viewport_wscalings);
}

VkResult vk_enqueue_cmd_set_viewport_wscaling_nv(struct vk_cmd_queue *queue
, uint32_t firstViewport
, uint32_t viewportCount
, const VkViewportWScalingNV* pViewportWScalings
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_VIEWPORT_WSCALING_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_VIEWPORT_WSCALING_NV;
   cmd->u.set_viewport_wscaling_nv.first_viewport = firstViewport;
   cmd->u.set_viewport_wscaling_nv.viewport_count = viewportCount;
   if (pViewportWScalings) {
      cmd->u.set_viewport_wscaling_nv.viewport_wscalings = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_viewport_wscaling_nv.viewport_wscalings) * (viewportCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_viewport_wscaling_nv.viewport_wscalings == NULL) goto err;
      memcpy((void*)cmd->u.set_viewport_wscaling_nv.viewport_wscalings, pViewportWScalings, sizeof(*cmd->u.set_viewport_wscaling_nv.viewport_wscalings) * (viewportCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_viewport_wscaling_nv(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_discard_rectangle_ext(struct vk_cmd_queue *queue,
                                      struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkRect2D* )cmd->u.set_discard_rectangle_ext.discard_rectangles);
}

VkResult vk_enqueue_cmd_set_discard_rectangle_ext(struct vk_cmd_queue *queue
, uint32_t firstDiscardRectangle
, uint32_t discardRectangleCount
, const VkRect2D* pDiscardRectangles
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_DISCARD_RECTANGLE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_DISCARD_RECTANGLE_EXT;
   cmd->u.set_discard_rectangle_ext.first_discard_rectangle = firstDiscardRectangle;
   cmd->u.set_discard_rectangle_ext.discard_rectangle_count = discardRectangleCount;
   if (pDiscardRectangles) {
      cmd->u.set_discard_rectangle_ext.discard_rectangles = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_discard_rectangle_ext.discard_rectangles) * (discardRectangleCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_discard_rectangle_ext.discard_rectangles == NULL) goto err;
      memcpy((void*)cmd->u.set_discard_rectangle_ext.discard_rectangles, pDiscardRectangles, sizeof(*cmd->u.set_discard_rectangle_ext.discard_rectangles) * (discardRectangleCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_discard_rectangle_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_discard_rectangle_enable_ext(struct vk_cmd_queue *queue,
                                             struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_discard_rectangle_enable_ext(struct vk_cmd_queue *queue
, VkBool32 discardRectangleEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_DISCARD_RECTANGLE_ENABLE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_DISCARD_RECTANGLE_ENABLE_EXT;
   cmd->u.set_discard_rectangle_enable_ext.discard_rectangle_enable = discardRectangleEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_discard_rectangle_mode_ext(struct vk_cmd_queue *queue,
                                           struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_discard_rectangle_mode_ext(struct vk_cmd_queue *queue
, VkDiscardRectangleModeEXT discardRectangleMode
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_DISCARD_RECTANGLE_MODE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_DISCARD_RECTANGLE_MODE_EXT;
   cmd->u.set_discard_rectangle_mode_ext.discard_rectangle_mode = discardRectangleMode;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_sample_locations_ext(struct vk_cmd_queue *queue,
                                     struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.set_sample_locations_ext.sample_locations_info) {
      VkSampleLocationEXT *pSampleLocations1 = (void *)(cmd->u.set_sample_locations_ext.sample_locations_info->pSampleLocations);
      if (cmd->u.set_sample_locations_ext.sample_locations_info->sampleLocationsCount) {
      }
      vk_free(queue->alloc, pSampleLocations1);
   }
   vk_free(queue->alloc, (void*)cmd->u.set_sample_locations_ext.sample_locations_info);

}

VkResult vk_enqueue_cmd_set_sample_locations_ext(struct vk_cmd_queue *queue
, const VkSampleLocationsInfoEXT* pSampleLocationsInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_SAMPLE_LOCATIONS_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_SAMPLE_LOCATIONS_EXT;
   if (pSampleLocationsInfo) {
      cmd->u.set_sample_locations_ext.sample_locations_info = vk_zalloc(queue->alloc, sizeof(VkSampleLocationsInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.set_sample_locations_ext.sample_locations_info == NULL) goto err;
      VkSampleLocationsInfoEXT *tmp_dst1 = (void *)cmd->u.set_sample_locations_ext.sample_locations_info;
      VkSampleLocationsInfoEXT *tmp_src2 = (void *)pSampleLocationsInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkSampleLocationsInfoEXT));
      if (tmp_src2->pSampleLocations) {
         tmp_dst1->pSampleLocations = vk_zalloc(queue->alloc, sizeof(VkSampleLocationEXT) * tmp_src2->sampleLocationsCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pSampleLocations == NULL) goto err;
         VkSampleLocationEXT *tmp_dst3 = (void *)tmp_dst1->pSampleLocations;
         VkSampleLocationEXT *tmp_src4 = (void *)tmp_src2->pSampleLocations;
         memcpy(tmp_dst3, tmp_src4, sizeof(VkSampleLocationEXT) * tmp_src2->sampleLocationsCount);
         for (uint32_t i5 = 0; i5 < tmp_src2->sampleLocationsCount; i5++) {
            VkSampleLocationEXT *tmp_dst6 = tmp_dst3 + i5; (void)tmp_dst6;
            VkSampleLocationEXT *tmp_src7 = tmp_src4 + i5; (void)tmp_src7;
            }
         } else {
            tmp_dst1->pSampleLocations = NULL;
         }
      } else {
         cmd->u.set_sample_locations_ext.sample_locations_info = NULL;
      }

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_set_sample_locations_ext(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_begin_debug_utils_label_ext(struct vk_cmd_queue *queue,
                                        struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.begin_debug_utils_label_ext.label_info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.begin_debug_utils_label_ext.label_info);

}

VkResult vk_enqueue_cmd_begin_debug_utils_label_ext(struct vk_cmd_queue *queue
, const VkDebugUtilsLabelEXT* pLabelInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BEGIN_DEBUG_UTILS_LABEL_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BEGIN_DEBUG_UTILS_LABEL_EXT;
   if (pLabelInfo) {
      cmd->u.begin_debug_utils_label_ext.label_info = vk_zalloc(queue->alloc, sizeof(VkDebugUtilsLabelEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.begin_debug_utils_label_ext.label_info == NULL) goto err;
      VkDebugUtilsLabelEXT *tmp_dst1 = (void *)cmd->u.begin_debug_utils_label_ext.label_info;
      VkDebugUtilsLabelEXT *tmp_src2 = (void *)pLabelInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkDebugUtilsLabelEXT));
      tmp_dst1->pLabelName = strdup(tmp_src2->pLabelName);
   } else {
      cmd->u.begin_debug_utils_label_ext.label_info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_begin_debug_utils_label_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_end_debug_utils_label_ext(struct vk_cmd_queue *queue,
                                      struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_end_debug_utils_label_ext(struct vk_cmd_queue *queue
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_END_DEBUG_UTILS_LABEL_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_END_DEBUG_UTILS_LABEL_EXT;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_insert_debug_utils_label_ext(struct vk_cmd_queue *queue,
                                         struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.insert_debug_utils_label_ext.label_info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.insert_debug_utils_label_ext.label_info);

}

VkResult vk_enqueue_cmd_insert_debug_utils_label_ext(struct vk_cmd_queue *queue
, const VkDebugUtilsLabelEXT* pLabelInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_INSERT_DEBUG_UTILS_LABEL_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_INSERT_DEBUG_UTILS_LABEL_EXT;
   if (pLabelInfo) {
      cmd->u.insert_debug_utils_label_ext.label_info = vk_zalloc(queue->alloc, sizeof(VkDebugUtilsLabelEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.insert_debug_utils_label_ext.label_info == NULL) goto err;
      VkDebugUtilsLabelEXT *tmp_dst1 = (void *)cmd->u.insert_debug_utils_label_ext.label_info;
      VkDebugUtilsLabelEXT *tmp_src2 = (void *)pLabelInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkDebugUtilsLabelEXT));
      tmp_dst1->pLabelName = strdup(tmp_src2->pLabelName);
   } else {
      cmd->u.insert_debug_utils_label_ext.label_info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_insert_debug_utils_label_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_write_buffer_marker_amd(struct vk_cmd_queue *queue,
                                    struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_write_buffer_marker_amd(struct vk_cmd_queue *queue
, VkPipelineStageFlagBits pipelineStage
, VkBuffer dstBuffer
, VkDeviceSize dstOffset
, uint32_t marker
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_WRITE_BUFFER_MARKER_AMD], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_WRITE_BUFFER_MARKER_AMD;
   cmd->u.write_buffer_marker_amd.pipeline_stage = pipelineStage;
   cmd->u.write_buffer_marker_amd.dst_buffer = dstBuffer;
   cmd->u.write_buffer_marker_amd.dst_offset = dstOffset;
   cmd->u.write_buffer_marker_amd.marker = marker;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_begin_render_pass2(struct vk_cmd_queue *queue,
                               struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.begin_render_pass2.render_pass_begin) {
      const VkBaseInStructure *pnext1 = cmd->u.begin_render_pass2.render_pass_begin->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO: {
            VkRect2D *pDeviceRenderAreas2 = (void *)(((VkDeviceGroupRenderPassBeginInfo *)pnext1)->pDeviceRenderAreas);
            if (((VkDeviceGroupRenderPassBeginInfo *)pnext1)->deviceRenderAreaCount) {
            }
            vk_free(queue->alloc, pDeviceRenderAreas2);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT: {
            VkAttachmentSampleLocationsEXT *pAttachmentInitialSampleLocations3 = (void *)(((VkRenderPassSampleLocationsBeginInfoEXT *)pnext1)->pAttachmentInitialSampleLocations);
            if (((VkRenderPassSampleLocationsBeginInfoEXT *)pnext1)->attachmentInitialSampleLocationsCount) {
            }
            vk_free(queue->alloc, pAttachmentInitialSampleLocations3);
            VkSubpassSampleLocationsEXT *pPostSubpassSampleLocations4 = (void *)(((VkRenderPassSampleLocationsBeginInfoEXT *)pnext1)->pPostSubpassSampleLocations);
            if (((VkRenderPassSampleLocationsBeginInfoEXT *)pnext1)->postSubpassSampleLocationsCount) {
            }
            vk_free(queue->alloc, pPostSubpassSampleLocations4);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO: {
            VkImageView *pAttachments5 = (void *)(((VkRenderPassAttachmentBeginInfo *)pnext1)->pAttachments);
            if (((VkRenderPassAttachmentBeginInfo *)pnext1)->attachmentCount) {
            }
            vk_free(queue->alloc, pAttachments5);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM: {
            VkRect2D *pPerViewRenderAreas6 = (void *)(((VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM *)pnext1)->pPerViewRenderAreas);
            if (((VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM *)pnext1)->perViewRenderAreaCount) {
            }
            vk_free(queue->alloc, pPerViewRenderAreas6);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM: {
            VkRenderPassStripeInfoARM *pStripeInfos7 = (void *)(((VkRenderPassStripeBeginInfoARM *)pnext1)->pStripeInfos);
            if (((VkRenderPassStripeBeginInfoARM *)pnext1)->stripeInfoCount) {
            }
            vk_free(queue->alloc, pStripeInfos7);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
      VkClearValue *pClearValues8 = (void *)(cmd->u.begin_render_pass2.render_pass_begin->pClearValues);
      if (cmd->u.begin_render_pass2.render_pass_begin->clearValueCount) {
      }
      vk_free(queue->alloc, pClearValues8);
   }
   vk_free(queue->alloc, (void*)cmd->u.begin_render_pass2.render_pass_begin);

   if (cmd->u.begin_render_pass2.subpass_begin_info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.begin_render_pass2.subpass_begin_info);

}

VkResult vk_enqueue_cmd_begin_render_pass2(struct vk_cmd_queue *queue
, const VkRenderPassBeginInfo*      pRenderPassBegin
, const VkSubpassBeginInfo*      pSubpassBeginInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BEGIN_RENDER_PASS2], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BEGIN_RENDER_PASS2;
   if (pRenderPassBegin) {
      cmd->u.begin_render_pass2.render_pass_begin = vk_zalloc(queue->alloc, sizeof(VkRenderPassBeginInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.begin_render_pass2.render_pass_begin == NULL) goto err;
      VkRenderPassBeginInfo *tmp_dst1 = (void *)cmd->u.begin_render_pass2.render_pass_begin;
      VkRenderPassBeginInfo *tmp_src2 = (void *)pRenderPassBegin;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkRenderPassBeginInfo));
      const VkBaseInStructure *pnext = tmp_dst1->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkDeviceGroupRenderPassBeginInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkDeviceGroupRenderPassBeginInfo *tmp_dst3 = (void *)tmp_dst1->pNext;
               VkDeviceGroupRenderPassBeginInfo *tmp_src4 = (void *)pnext;
               memcpy(tmp_dst3, tmp_src4, sizeof(VkDeviceGroupRenderPassBeginInfo));
               if (tmp_src4->pDeviceRenderAreas) {
                  tmp_dst3->pDeviceRenderAreas = vk_zalloc(queue->alloc, sizeof(VkRect2D) * tmp_src4->deviceRenderAreaCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst3->pDeviceRenderAreas == NULL) goto err;
                  VkRect2D *tmp_dst5 = (void *)tmp_dst3->pDeviceRenderAreas;
                  VkRect2D *tmp_src6 = (void *)tmp_src4->pDeviceRenderAreas;
                  memcpy(tmp_dst5, tmp_src6, sizeof(VkRect2D) * tmp_src4->deviceRenderAreaCount);
                  for (uint32_t i7 = 0; i7 < tmp_src4->deviceRenderAreaCount; i7++) {
                     VkRect2D *tmp_dst8 = tmp_dst5 + i7; (void)tmp_dst8;
                     VkRect2D *tmp_src9 = tmp_src6 + i7; (void)tmp_src9;
                     }
                  } else {
                     tmp_dst3->pDeviceRenderAreas = NULL;
                  }
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkRenderPassSampleLocationsBeginInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkRenderPassSampleLocationsBeginInfoEXT *tmp_dst10 = (void *)tmp_dst1->pNext;
                  VkRenderPassSampleLocationsBeginInfoEXT *tmp_src11 = (void *)pnext;
                  memcpy(tmp_dst10, tmp_src11, sizeof(VkRenderPassSampleLocationsBeginInfoEXT));
                  if (tmp_src11->pAttachmentInitialSampleLocations) {
                     tmp_dst10->pAttachmentInitialSampleLocations = vk_zalloc(queue->alloc, sizeof(VkAttachmentSampleLocationsEXT) * tmp_src11->attachmentInitialSampleLocationsCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst10->pAttachmentInitialSampleLocations == NULL) goto err;
                     VkAttachmentSampleLocationsEXT *tmp_dst12 = (void *)tmp_dst10->pAttachmentInitialSampleLocations;
                     VkAttachmentSampleLocationsEXT *tmp_src13 = (void *)tmp_src11->pAttachmentInitialSampleLocations;
                     memcpy(tmp_dst12, tmp_src13, sizeof(VkAttachmentSampleLocationsEXT) * tmp_src11->attachmentInitialSampleLocationsCount);
                     for (uint32_t i14 = 0; i14 < tmp_src11->attachmentInitialSampleLocationsCount; i14++) {
                        VkAttachmentSampleLocationsEXT *tmp_dst15 = tmp_dst12 + i14; (void)tmp_dst15;
                        VkAttachmentSampleLocationsEXT *tmp_src16 = tmp_src13 + i14; (void)tmp_src16;
                        }
                     } else {
                        tmp_dst10->pAttachmentInitialSampleLocations = NULL;
                     }
                     if (tmp_src11->pPostSubpassSampleLocations) {
                        tmp_dst10->pPostSubpassSampleLocations = vk_zalloc(queue->alloc, sizeof(VkSubpassSampleLocationsEXT) * tmp_src11->postSubpassSampleLocationsCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst10->pPostSubpassSampleLocations == NULL) goto err;
                        VkSubpassSampleLocationsEXT *tmp_dst17 = (void *)tmp_dst10->pPostSubpassSampleLocations;
                        VkSubpassSampleLocationsEXT *tmp_src18 = (void *)tmp_src11->pPostSubpassSampleLocations;
                        memcpy(tmp_dst17, tmp_src18, sizeof(VkSubpassSampleLocationsEXT) * tmp_src11->postSubpassSampleLocationsCount);
                        for (uint32_t i19 = 0; i19 < tmp_src11->postSubpassSampleLocationsCount; i19++) {
                           VkSubpassSampleLocationsEXT *tmp_dst20 = tmp_dst17 + i19; (void)tmp_dst20;
                           VkSubpassSampleLocationsEXT *tmp_src21 = tmp_src18 + i19; (void)tmp_src21;
                           }
                        } else {
                           tmp_dst10->pPostSubpassSampleLocations = NULL;
                        }
                     } else {
                        tmp_dst1->pNext = NULL;
                     }
                     break;
                  case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
                     if (pnext) {
                        tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkRenderPassAttachmentBeginInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst1->pNext == NULL) goto err;
                        VkRenderPassAttachmentBeginInfo *tmp_dst22 = (void *)tmp_dst1->pNext;
                        VkRenderPassAttachmentBeginInfo *tmp_src23 = (void *)pnext;
                        memcpy(tmp_dst22, tmp_src23, sizeof(VkRenderPassAttachmentBeginInfo));
                        if (tmp_src23->pAttachments) {
                           tmp_dst22->pAttachments = vk_zalloc(queue->alloc, sizeof(VkImageView) * tmp_src23->attachmentCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst22->pAttachments == NULL) goto err;
                           VkImageView *tmp_dst24 = (void *)tmp_dst22->pAttachments;
                           VkImageView *tmp_src25 = (void *)tmp_src23->pAttachments;
                           memcpy(tmp_dst24, tmp_src25, sizeof(VkImageView) * tmp_src23->attachmentCount);
                           for (uint32_t i26 = 0; i26 < tmp_src23->attachmentCount; i26++) {
                              VkImageView *tmp_dst27 = tmp_dst24 + i26; (void)tmp_dst27;
                              VkImageView *tmp_src28 = tmp_src25 + i26; (void)tmp_src28;
                              }
                           } else {
                              tmp_dst22->pAttachments = NULL;
                           }
                        } else {
                           tmp_dst1->pNext = NULL;
                        }
                        break;
                     case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
                        if (pnext) {
                           tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkRenderPassTransformBeginInfoQCOM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst1->pNext == NULL) goto err;
                           VkRenderPassTransformBeginInfoQCOM *tmp_dst29 = (void *)tmp_dst1->pNext;
                           VkRenderPassTransformBeginInfoQCOM *tmp_src30 = (void *)pnext;
                           memcpy(tmp_dst29, tmp_src30, sizeof(VkRenderPassTransformBeginInfoQCOM));
                        } else {
                           tmp_dst1->pNext = NULL;
                        }
                        break;
                     case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM:
                        if (pnext) {
                           tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst1->pNext == NULL) goto err;
                           VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM *tmp_dst31 = (void *)tmp_dst1->pNext;
                           VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM *tmp_src32 = (void *)pnext;
                           memcpy(tmp_dst31, tmp_src32, sizeof(VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM));
                           if (tmp_src32->pPerViewRenderAreas) {
                              tmp_dst31->pPerViewRenderAreas = vk_zalloc(queue->alloc, sizeof(VkRect2D) * tmp_src32->perViewRenderAreaCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst31->pPerViewRenderAreas == NULL) goto err;
                              VkRect2D *tmp_dst33 = (void *)tmp_dst31->pPerViewRenderAreas;
                              VkRect2D *tmp_src34 = (void *)tmp_src32->pPerViewRenderAreas;
                              memcpy(tmp_dst33, tmp_src34, sizeof(VkRect2D) * tmp_src32->perViewRenderAreaCount);
                              for (uint32_t i35 = 0; i35 < tmp_src32->perViewRenderAreaCount; i35++) {
                                 VkRect2D *tmp_dst36 = tmp_dst33 + i35; (void)tmp_dst36;
                                 VkRect2D *tmp_src37 = tmp_src34 + i35; (void)tmp_src37;
                                 }
                              } else {
                                 tmp_dst31->pPerViewRenderAreas = NULL;
                              }
                           } else {
                              tmp_dst1->pNext = NULL;
                           }
                           break;
                        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM:
                           if (pnext) {
                              tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkRenderPassStripeBeginInfoARM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst1->pNext == NULL) goto err;
                              VkRenderPassStripeBeginInfoARM *tmp_dst38 = (void *)tmp_dst1->pNext;
                              VkRenderPassStripeBeginInfoARM *tmp_src39 = (void *)pnext;
                              memcpy(tmp_dst38, tmp_src39, sizeof(VkRenderPassStripeBeginInfoARM));
                              if (tmp_src39->pStripeInfos) {
                                 tmp_dst38->pStripeInfos = vk_zalloc(queue->alloc, sizeof(VkRenderPassStripeInfoARM) * tmp_src39->stripeInfoCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst38->pStripeInfos == NULL) goto err;
                                 VkRenderPassStripeInfoARM *tmp_dst40 = (void *)tmp_dst38->pStripeInfos;
                                 VkRenderPassStripeInfoARM *tmp_src41 = (void *)tmp_src39->pStripeInfos;
                                 memcpy(tmp_dst40, tmp_src41, sizeof(VkRenderPassStripeInfoARM) * tmp_src39->stripeInfoCount);
                                 for (uint32_t i42 = 0; i42 < tmp_src39->stripeInfoCount; i42++) {
                                    VkRenderPassStripeInfoARM *tmp_dst43 = tmp_dst40 + i42; (void)tmp_dst43;
                                    VkRenderPassStripeInfoARM *tmp_src44 = tmp_src41 + i42; (void)tmp_src44;
                                    }
                                 } else {
                                    tmp_dst38->pStripeInfos = NULL;
                                 }
                              } else {
                                 tmp_dst1->pNext = NULL;
                              }
                              break;
                           }
                        }
                        if (tmp_src2->pClearValues) {
                           tmp_dst1->pClearValues = vk_zalloc(queue->alloc, sizeof(VkClearValue) * tmp_src2->clearValueCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst1->pClearValues == NULL) goto err;
                           VkClearValue *tmp_dst45 = (void *)tmp_dst1->pClearValues;
                           VkClearValue *tmp_src46 = (void *)tmp_src2->pClearValues;
                           memcpy(tmp_dst45, tmp_src46, sizeof(VkClearValue) * tmp_src2->clearValueCount);
                           for (uint32_t i47 = 0; i47 < tmp_src2->clearValueCount; i47++) {
                              VkClearValue *tmp_dst48 = tmp_dst45 + i47; (void)tmp_dst48;
                              VkClearValue *tmp_src49 = tmp_src46 + i47; (void)tmp_src49;
                              }
                           } else {
                              tmp_dst1->pClearValues = NULL;
                           }
                        } else {
                           cmd->u.begin_render_pass2.render_pass_begin = NULL;
                        }
                        if (pSubpassBeginInfo) {
                           cmd->u.begin_render_pass2.subpass_begin_info = vk_zalloc(queue->alloc, sizeof(VkSubpassBeginInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (cmd->u.begin_render_pass2.subpass_begin_info == NULL) goto err;
                           VkSubpassBeginInfo *tmp_dst50 = (void *)cmd->u.begin_render_pass2.subpass_begin_info;
                           VkSubpassBeginInfo *tmp_src51 = (void *)pSubpassBeginInfo;
                           memcpy(tmp_dst50, tmp_src51, sizeof(VkSubpassBeginInfo));
                        } else {
                           cmd->u.begin_render_pass2.subpass_begin_info = NULL;
                        }

                        list_addtail(&cmd->cmd_link, &queue->cmds);
                        return VK_SUCCESS;

err:
                        if (cmd)
                           vk_free_cmd_begin_render_pass2(queue, cmd);
                        return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_next_subpass2(struct vk_cmd_queue *queue,
                          struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.next_subpass2.subpass_begin_info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.next_subpass2.subpass_begin_info);

   if (cmd->u.next_subpass2.subpass_end_info) {
      const VkBaseInStructure *pnext1 = cmd->u.next_subpass2.subpass_end_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT: {
            VkOffset2D *pFragmentDensityOffsets2 = (void *)(((VkRenderPassFragmentDensityMapOffsetEndInfoEXT *)pnext1)->pFragmentDensityOffsets);
            if (((VkRenderPassFragmentDensityMapOffsetEndInfoEXT *)pnext1)->fragmentDensityOffsetCount) {
            }
            vk_free(queue->alloc, pFragmentDensityOffsets2);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
   }
   vk_free(queue->alloc, (void*)cmd->u.next_subpass2.subpass_end_info);

}

VkResult vk_enqueue_cmd_next_subpass2(struct vk_cmd_queue *queue
, const VkSubpassBeginInfo*      pSubpassBeginInfo
, const VkSubpassEndInfo*        pSubpassEndInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_NEXT_SUBPASS2], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_NEXT_SUBPASS2;
   if (pSubpassBeginInfo) {
      cmd->u.next_subpass2.subpass_begin_info = vk_zalloc(queue->alloc, sizeof(VkSubpassBeginInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.next_subpass2.subpass_begin_info == NULL) goto err;
      VkSubpassBeginInfo *tmp_dst1 = (void *)cmd->u.next_subpass2.subpass_begin_info;
      VkSubpassBeginInfo *tmp_src2 = (void *)pSubpassBeginInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkSubpassBeginInfo));
   } else {
      cmd->u.next_subpass2.subpass_begin_info = NULL;
   }
   if (pSubpassEndInfo) {
      cmd->u.next_subpass2.subpass_end_info = vk_zalloc(queue->alloc, sizeof(VkSubpassEndInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.next_subpass2.subpass_end_info == NULL) goto err;
      VkSubpassEndInfo *tmp_dst3 = (void *)cmd->u.next_subpass2.subpass_end_info;
      VkSubpassEndInfo *tmp_src4 = (void *)pSubpassEndInfo;
      memcpy(tmp_dst3, tmp_src4, sizeof(VkSubpassEndInfo));
      const VkBaseInStructure *pnext = tmp_dst3->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT:
            if (pnext) {
               tmp_dst3->pNext = vk_zalloc(queue->alloc, sizeof(VkRenderPassFragmentDensityMapOffsetEndInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst3->pNext == NULL) goto err;
               VkRenderPassFragmentDensityMapOffsetEndInfoEXT *tmp_dst5 = (void *)tmp_dst3->pNext;
               VkRenderPassFragmentDensityMapOffsetEndInfoEXT *tmp_src6 = (void *)pnext;
               memcpy(tmp_dst5, tmp_src6, sizeof(VkRenderPassFragmentDensityMapOffsetEndInfoEXT));
               if (tmp_src6->pFragmentDensityOffsets) {
                  tmp_dst5->pFragmentDensityOffsets = vk_zalloc(queue->alloc, sizeof(VkOffset2D) * tmp_src6->fragmentDensityOffsetCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst5->pFragmentDensityOffsets == NULL) goto err;
                  VkOffset2D *tmp_dst7 = (void *)tmp_dst5->pFragmentDensityOffsets;
                  VkOffset2D *tmp_src8 = (void *)tmp_src6->pFragmentDensityOffsets;
                  memcpy(tmp_dst7, tmp_src8, sizeof(VkOffset2D) * tmp_src6->fragmentDensityOffsetCount);
                  for (uint32_t i9 = 0; i9 < tmp_src6->fragmentDensityOffsetCount; i9++) {
                     VkOffset2D *tmp_dst10 = tmp_dst7 + i9; (void)tmp_dst10;
                     VkOffset2D *tmp_src11 = tmp_src8 + i9; (void)tmp_src11;
                     }
                  } else {
                     tmp_dst5->pFragmentDensityOffsets = NULL;
                  }
               } else {
                  tmp_dst3->pNext = NULL;
               }
               break;
            }
         }
      } else {
         cmd->u.next_subpass2.subpass_end_info = NULL;
      }

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_next_subpass2(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_end_render_pass2(struct vk_cmd_queue *queue,
                             struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.end_render_pass2.subpass_end_info) {
      const VkBaseInStructure *pnext1 = cmd->u.end_render_pass2.subpass_end_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT: {
            VkOffset2D *pFragmentDensityOffsets2 = (void *)(((VkRenderPassFragmentDensityMapOffsetEndInfoEXT *)pnext1)->pFragmentDensityOffsets);
            if (((VkRenderPassFragmentDensityMapOffsetEndInfoEXT *)pnext1)->fragmentDensityOffsetCount) {
            }
            vk_free(queue->alloc, pFragmentDensityOffsets2);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
   }
   vk_free(queue->alloc, (void*)cmd->u.end_render_pass2.subpass_end_info);

}

VkResult vk_enqueue_cmd_end_render_pass2(struct vk_cmd_queue *queue
, const VkSubpassEndInfo*        pSubpassEndInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_END_RENDER_PASS2], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_END_RENDER_PASS2;
   if (pSubpassEndInfo) {
      cmd->u.end_render_pass2.subpass_end_info = vk_zalloc(queue->alloc, sizeof(VkSubpassEndInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.end_render_pass2.subpass_end_info == NULL) goto err;
      VkSubpassEndInfo *tmp_dst1 = (void *)cmd->u.end_render_pass2.subpass_end_info;
      VkSubpassEndInfo *tmp_src2 = (void *)pSubpassEndInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkSubpassEndInfo));
      const VkBaseInStructure *pnext = tmp_dst1->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkRenderPassFragmentDensityMapOffsetEndInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkRenderPassFragmentDensityMapOffsetEndInfoEXT *tmp_dst3 = (void *)tmp_dst1->pNext;
               VkRenderPassFragmentDensityMapOffsetEndInfoEXT *tmp_src4 = (void *)pnext;
               memcpy(tmp_dst3, tmp_src4, sizeof(VkRenderPassFragmentDensityMapOffsetEndInfoEXT));
               if (tmp_src4->pFragmentDensityOffsets) {
                  tmp_dst3->pFragmentDensityOffsets = vk_zalloc(queue->alloc, sizeof(VkOffset2D) * tmp_src4->fragmentDensityOffsetCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst3->pFragmentDensityOffsets == NULL) goto err;
                  VkOffset2D *tmp_dst5 = (void *)tmp_dst3->pFragmentDensityOffsets;
                  VkOffset2D *tmp_src6 = (void *)tmp_src4->pFragmentDensityOffsets;
                  memcpy(tmp_dst5, tmp_src6, sizeof(VkOffset2D) * tmp_src4->fragmentDensityOffsetCount);
                  for (uint32_t i7 = 0; i7 < tmp_src4->fragmentDensityOffsetCount; i7++) {
                     VkOffset2D *tmp_dst8 = tmp_dst5 + i7; (void)tmp_dst8;
                     VkOffset2D *tmp_src9 = tmp_src6 + i7; (void)tmp_src9;
                     }
                  } else {
                     tmp_dst3->pFragmentDensityOffsets = NULL;
                  }
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            }
         }
      } else {
         cmd->u.end_render_pass2.subpass_end_info = NULL;
      }

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_end_render_pass2(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_draw_indirect_count(struct vk_cmd_queue *queue,
                                struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_draw_indirect_count(struct vk_cmd_queue *queue
, VkBuffer buffer
, VkDeviceSize offset
, VkBuffer countBuffer
, VkDeviceSize countBufferOffset
, uint32_t maxDrawCount
, uint32_t stride
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DRAW_INDIRECT_COUNT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DRAW_INDIRECT_COUNT;
   cmd->u.draw_indirect_count.buffer = buffer;
   cmd->u.draw_indirect_count.offset = offset;
   cmd->u.draw_indirect_count.count_buffer = countBuffer;
   cmd->u.draw_indirect_count.count_buffer_offset = countBufferOffset;
   cmd->u.draw_indirect_count.max_draw_count = maxDrawCount;
   cmd->u.draw_indirect_count.stride = stride;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_draw_indexed_indirect_count(struct vk_cmd_queue *queue,
                                        struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_draw_indexed_indirect_count(struct vk_cmd_queue *queue
, VkBuffer buffer
, VkDeviceSize offset
, VkBuffer countBuffer
, VkDeviceSize countBufferOffset
, uint32_t maxDrawCount
, uint32_t stride
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DRAW_INDEXED_INDIRECT_COUNT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DRAW_INDEXED_INDIRECT_COUNT;
   cmd->u.draw_indexed_indirect_count.buffer = buffer;
   cmd->u.draw_indexed_indirect_count.offset = offset;
   cmd->u.draw_indexed_indirect_count.count_buffer = countBuffer;
   cmd->u.draw_indexed_indirect_count.count_buffer_offset = countBufferOffset;
   cmd->u.draw_indexed_indirect_count.max_draw_count = maxDrawCount;
   cmd->u.draw_indexed_indirect_count.stride = stride;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_checkpoint_nv(struct vk_cmd_queue *queue,
                              struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, (void*)cmd->u.set_checkpoint_nv.checkpoint_marker);

}

VkResult vk_enqueue_cmd_set_checkpoint_nv(struct vk_cmd_queue *queue
, const void* pCheckpointMarker
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_CHECKPOINT_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_CHECKPOINT_NV;
   cmd->u.set_checkpoint_nv.checkpoint_marker = ( void* )pCheckpointMarker;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_bind_transform_feedback_buffers_ext(struct vk_cmd_queue *queue,
                                                struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkBuffer* )cmd->u.bind_transform_feedback_buffers_ext.buffers);
   vk_free(queue->alloc, ( VkDeviceSize* )cmd->u.bind_transform_feedback_buffers_ext.offsets);
   vk_free(queue->alloc, ( VkDeviceSize* )cmd->u.bind_transform_feedback_buffers_ext.sizes);
}

VkResult vk_enqueue_cmd_bind_transform_feedback_buffers_ext(struct vk_cmd_queue *queue
, uint32_t firstBinding
, uint32_t bindingCount
, const VkBuffer* pBuffers
, const VkDeviceSize* pOffsets
, const VkDeviceSize* pSizes
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BIND_TRANSFORM_FEEDBACK_BUFFERS_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BIND_TRANSFORM_FEEDBACK_BUFFERS_EXT;
   cmd->u.bind_transform_feedback_buffers_ext.first_binding = firstBinding;
   cmd->u.bind_transform_feedback_buffers_ext.binding_count = bindingCount;
   if (pBuffers) {
      cmd->u.bind_transform_feedback_buffers_ext.buffers = vk_zalloc(queue->alloc, sizeof(*cmd->u.bind_transform_feedback_buffers_ext.buffers) * (bindingCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.bind_transform_feedback_buffers_ext.buffers == NULL) goto err;
      memcpy((void*)cmd->u.bind_transform_feedback_buffers_ext.buffers, pBuffers, sizeof(*cmd->u.bind_transform_feedback_buffers_ext.buffers) * (bindingCount));
   }
   if (pOffsets) {
      cmd->u.bind_transform_feedback_buffers_ext.offsets = vk_zalloc(queue->alloc, sizeof(*cmd->u.bind_transform_feedback_buffers_ext.offsets) * (bindingCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.bind_transform_feedback_buffers_ext.offsets == NULL) goto err;
      memcpy((void*)cmd->u.bind_transform_feedback_buffers_ext.offsets, pOffsets, sizeof(*cmd->u.bind_transform_feedback_buffers_ext.offsets) * (bindingCount));
   }
   if (pSizes) {
      cmd->u.bind_transform_feedback_buffers_ext.sizes = vk_zalloc(queue->alloc, sizeof(*cmd->u.bind_transform_feedback_buffers_ext.sizes) * (bindingCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.bind_transform_feedback_buffers_ext.sizes == NULL) goto err;
      memcpy((void*)cmd->u.bind_transform_feedback_buffers_ext.sizes, pSizes, sizeof(*cmd->u.bind_transform_feedback_buffers_ext.sizes) * (bindingCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_bind_transform_feedback_buffers_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_begin_transform_feedback_ext(struct vk_cmd_queue *queue,
                                         struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkBuffer* )cmd->u.begin_transform_feedback_ext.counter_buffers);
   vk_free(queue->alloc, ( VkDeviceSize* )cmd->u.begin_transform_feedback_ext.counter_buffer_offsets);
}

VkResult vk_enqueue_cmd_begin_transform_feedback_ext(struct vk_cmd_queue *queue
, uint32_t firstCounterBuffer
, uint32_t counterBufferCount
, const VkBuffer* pCounterBuffers
, const VkDeviceSize* pCounterBufferOffsets
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BEGIN_TRANSFORM_FEEDBACK_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BEGIN_TRANSFORM_FEEDBACK_EXT;
   cmd->u.begin_transform_feedback_ext.first_counter_buffer = firstCounterBuffer;
   cmd->u.begin_transform_feedback_ext.counter_buffer_count = counterBufferCount;
   if (pCounterBuffers) {
      cmd->u.begin_transform_feedback_ext.counter_buffers = vk_zalloc(queue->alloc, sizeof(*cmd->u.begin_transform_feedback_ext.counter_buffers) * (counterBufferCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.begin_transform_feedback_ext.counter_buffers == NULL) goto err;
      memcpy((void*)cmd->u.begin_transform_feedback_ext.counter_buffers, pCounterBuffers, sizeof(*cmd->u.begin_transform_feedback_ext.counter_buffers) * (counterBufferCount));
   }
   if (pCounterBufferOffsets) {
      cmd->u.begin_transform_feedback_ext.counter_buffer_offsets = vk_zalloc(queue->alloc, sizeof(*cmd->u.begin_transform_feedback_ext.counter_buffer_offsets) * (counterBufferCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.begin_transform_feedback_ext.counter_buffer_offsets == NULL) goto err;
      memcpy((void*)cmd->u.begin_transform_feedback_ext.counter_buffer_offsets, pCounterBufferOffsets, sizeof(*cmd->u.begin_transform_feedback_ext.counter_buffer_offsets) * (counterBufferCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_begin_transform_feedback_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_end_transform_feedback_ext(struct vk_cmd_queue *queue,
                                       struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkBuffer* )cmd->u.end_transform_feedback_ext.counter_buffers);
   vk_free(queue->alloc, ( VkDeviceSize* )cmd->u.end_transform_feedback_ext.counter_buffer_offsets);
}

VkResult vk_enqueue_cmd_end_transform_feedback_ext(struct vk_cmd_queue *queue
, uint32_t firstCounterBuffer
, uint32_t counterBufferCount
, const VkBuffer* pCounterBuffers
, const VkDeviceSize* pCounterBufferOffsets
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_END_TRANSFORM_FEEDBACK_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_END_TRANSFORM_FEEDBACK_EXT;
   cmd->u.end_transform_feedback_ext.first_counter_buffer = firstCounterBuffer;
   cmd->u.end_transform_feedback_ext.counter_buffer_count = counterBufferCount;
   if (pCounterBuffers) {
      cmd->u.end_transform_feedback_ext.counter_buffers = vk_zalloc(queue->alloc, sizeof(*cmd->u.end_transform_feedback_ext.counter_buffers) * (counterBufferCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.end_transform_feedback_ext.counter_buffers == NULL) goto err;
      memcpy((void*)cmd->u.end_transform_feedback_ext.counter_buffers, pCounterBuffers, sizeof(*cmd->u.end_transform_feedback_ext.counter_buffers) * (counterBufferCount));
   }
   if (pCounterBufferOffsets) {
      cmd->u.end_transform_feedback_ext.counter_buffer_offsets = vk_zalloc(queue->alloc, sizeof(*cmd->u.end_transform_feedback_ext.counter_buffer_offsets) * (counterBufferCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.end_transform_feedback_ext.counter_buffer_offsets == NULL) goto err;
      memcpy((void*)cmd->u.end_transform_feedback_ext.counter_buffer_offsets, pCounterBufferOffsets, sizeof(*cmd->u.end_transform_feedback_ext.counter_buffer_offsets) * (counterBufferCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_end_transform_feedback_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_begin_query_indexed_ext(struct vk_cmd_queue *queue,
                                    struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_begin_query_indexed_ext(struct vk_cmd_queue *queue
, VkQueryPool queryPool
, uint32_t query
, VkQueryControlFlags flags
, uint32_t index
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BEGIN_QUERY_INDEXED_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BEGIN_QUERY_INDEXED_EXT;
   cmd->u.begin_query_indexed_ext.query_pool = queryPool;
   cmd->u.begin_query_indexed_ext.query = query;
   cmd->u.begin_query_indexed_ext.flags = flags;
   cmd->u.begin_query_indexed_ext.index = index;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_end_query_indexed_ext(struct vk_cmd_queue *queue,
                                  struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_end_query_indexed_ext(struct vk_cmd_queue *queue
, VkQueryPool queryPool
, uint32_t query
, uint32_t index
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_END_QUERY_INDEXED_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_END_QUERY_INDEXED_EXT;
   cmd->u.end_query_indexed_ext.query_pool = queryPool;
   cmd->u.end_query_indexed_ext.query = query;
   cmd->u.end_query_indexed_ext.index = index;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_draw_indirect_byte_count_ext(struct vk_cmd_queue *queue,
                                         struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_draw_indirect_byte_count_ext(struct vk_cmd_queue *queue
, uint32_t instanceCount
, uint32_t firstInstance
, VkBuffer counterBuffer
, VkDeviceSize counterBufferOffset
, uint32_t counterOffset
, uint32_t vertexStride
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DRAW_INDIRECT_BYTE_COUNT_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DRAW_INDIRECT_BYTE_COUNT_EXT;
   cmd->u.draw_indirect_byte_count_ext.instance_count = instanceCount;
   cmd->u.draw_indirect_byte_count_ext.first_instance = firstInstance;
   cmd->u.draw_indirect_byte_count_ext.counter_buffer = counterBuffer;
   cmd->u.draw_indirect_byte_count_ext.counter_buffer_offset = counterBufferOffset;
   cmd->u.draw_indirect_byte_count_ext.counter_offset = counterOffset;
   cmd->u.draw_indirect_byte_count_ext.vertex_stride = vertexStride;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_exclusive_scissor_nv(struct vk_cmd_queue *queue,
                                     struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkRect2D* )cmd->u.set_exclusive_scissor_nv.exclusive_scissors);
}

VkResult vk_enqueue_cmd_set_exclusive_scissor_nv(struct vk_cmd_queue *queue
, uint32_t firstExclusiveScissor
, uint32_t exclusiveScissorCount
, const VkRect2D* pExclusiveScissors
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_EXCLUSIVE_SCISSOR_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_EXCLUSIVE_SCISSOR_NV;
   cmd->u.set_exclusive_scissor_nv.first_exclusive_scissor = firstExclusiveScissor;
   cmd->u.set_exclusive_scissor_nv.exclusive_scissor_count = exclusiveScissorCount;
   if (pExclusiveScissors) {
      cmd->u.set_exclusive_scissor_nv.exclusive_scissors = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_exclusive_scissor_nv.exclusive_scissors) * (exclusiveScissorCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_exclusive_scissor_nv.exclusive_scissors == NULL) goto err;
      memcpy((void*)cmd->u.set_exclusive_scissor_nv.exclusive_scissors, pExclusiveScissors, sizeof(*cmd->u.set_exclusive_scissor_nv.exclusive_scissors) * (exclusiveScissorCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_exclusive_scissor_nv(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_exclusive_scissor_enable_nv(struct vk_cmd_queue *queue,
                                            struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkBool32* )cmd->u.set_exclusive_scissor_enable_nv.exclusive_scissor_enables);
}

VkResult vk_enqueue_cmd_set_exclusive_scissor_enable_nv(struct vk_cmd_queue *queue
, uint32_t firstExclusiveScissor
, uint32_t exclusiveScissorCount
, const VkBool32* pExclusiveScissorEnables
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_EXCLUSIVE_SCISSOR_ENABLE_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_EXCLUSIVE_SCISSOR_ENABLE_NV;
   cmd->u.set_exclusive_scissor_enable_nv.first_exclusive_scissor = firstExclusiveScissor;
   cmd->u.set_exclusive_scissor_enable_nv.exclusive_scissor_count = exclusiveScissorCount;
   if (pExclusiveScissorEnables) {
      cmd->u.set_exclusive_scissor_enable_nv.exclusive_scissor_enables = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_exclusive_scissor_enable_nv.exclusive_scissor_enables) * (exclusiveScissorCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_exclusive_scissor_enable_nv.exclusive_scissor_enables == NULL) goto err;
      memcpy((void*)cmd->u.set_exclusive_scissor_enable_nv.exclusive_scissor_enables, pExclusiveScissorEnables, sizeof(*cmd->u.set_exclusive_scissor_enable_nv.exclusive_scissor_enables) * (exclusiveScissorCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_exclusive_scissor_enable_nv(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_bind_shading_rate_image_nv(struct vk_cmd_queue *queue,
                                       struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_bind_shading_rate_image_nv(struct vk_cmd_queue *queue
, VkImageView imageView
, VkImageLayout imageLayout
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BIND_SHADING_RATE_IMAGE_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BIND_SHADING_RATE_IMAGE_NV;
   cmd->u.bind_shading_rate_image_nv.image_view = imageView;
   cmd->u.bind_shading_rate_image_nv.image_layout = imageLayout;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_viewport_shading_rate_palette_nv(struct vk_cmd_queue *queue,
                                                 struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkShadingRatePaletteNV* )cmd->u.set_viewport_shading_rate_palette_nv.shading_rate_palettes);
}

VkResult vk_enqueue_cmd_set_viewport_shading_rate_palette_nv(struct vk_cmd_queue *queue
, uint32_t firstViewport
, uint32_t viewportCount
, const VkShadingRatePaletteNV* pShadingRatePalettes
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_VIEWPORT_SHADING_RATE_PALETTE_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_VIEWPORT_SHADING_RATE_PALETTE_NV;
   cmd->u.set_viewport_shading_rate_palette_nv.first_viewport = firstViewport;
   cmd->u.set_viewport_shading_rate_palette_nv.viewport_count = viewportCount;
   if (pShadingRatePalettes) {
      cmd->u.set_viewport_shading_rate_palette_nv.shading_rate_palettes = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_viewport_shading_rate_palette_nv.shading_rate_palettes) * (viewportCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_viewport_shading_rate_palette_nv.shading_rate_palettes == NULL) goto err;
      memcpy((void*)cmd->u.set_viewport_shading_rate_palette_nv.shading_rate_palettes, pShadingRatePalettes, sizeof(*cmd->u.set_viewport_shading_rate_palette_nv.shading_rate_palettes) * (viewportCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_viewport_shading_rate_palette_nv(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_coarse_sample_order_nv(struct vk_cmd_queue *queue,
                                       struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkCoarseSampleOrderCustomNV* )cmd->u.set_coarse_sample_order_nv.custom_sample_orders);
}

VkResult vk_enqueue_cmd_set_coarse_sample_order_nv(struct vk_cmd_queue *queue
, VkCoarseSampleOrderTypeNV sampleOrderType
, uint32_t customSampleOrderCount
, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_COARSE_SAMPLE_ORDER_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_COARSE_SAMPLE_ORDER_NV;
   cmd->u.set_coarse_sample_order_nv.sample_order_type = sampleOrderType;
   cmd->u.set_coarse_sample_order_nv.custom_sample_order_count = customSampleOrderCount;
   if (pCustomSampleOrders) {
      cmd->u.set_coarse_sample_order_nv.custom_sample_orders = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_coarse_sample_order_nv.custom_sample_orders) * (customSampleOrderCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_coarse_sample_order_nv.custom_sample_orders == NULL) goto err;
      memcpy((void*)cmd->u.set_coarse_sample_order_nv.custom_sample_orders, pCustomSampleOrders, sizeof(*cmd->u.set_coarse_sample_order_nv.custom_sample_orders) * (customSampleOrderCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_coarse_sample_order_nv(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_draw_mesh_tasks_nv(struct vk_cmd_queue *queue,
                               struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_draw_mesh_tasks_nv(struct vk_cmd_queue *queue
, uint32_t taskCount
, uint32_t firstTask
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DRAW_MESH_TASKS_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DRAW_MESH_TASKS_NV;
   cmd->u.draw_mesh_tasks_nv.task_count = taskCount;
   cmd->u.draw_mesh_tasks_nv.first_task = firstTask;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_draw_mesh_tasks_indirect_nv(struct vk_cmd_queue *queue,
                                        struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_draw_mesh_tasks_indirect_nv(struct vk_cmd_queue *queue
, VkBuffer buffer
, VkDeviceSize offset
, uint32_t drawCount
, uint32_t stride
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DRAW_MESH_TASKS_INDIRECT_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DRAW_MESH_TASKS_INDIRECT_NV;
   cmd->u.draw_mesh_tasks_indirect_nv.buffer = buffer;
   cmd->u.draw_mesh_tasks_indirect_nv.offset = offset;
   cmd->u.draw_mesh_tasks_indirect_nv.draw_count = drawCount;
   cmd->u.draw_mesh_tasks_indirect_nv.stride = stride;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_draw_mesh_tasks_indirect_count_nv(struct vk_cmd_queue *queue,
                                              struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_draw_mesh_tasks_indirect_count_nv(struct vk_cmd_queue *queue
, VkBuffer buffer
, VkDeviceSize offset
, VkBuffer countBuffer
, VkDeviceSize countBufferOffset
, uint32_t maxDrawCount
, uint32_t stride
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DRAW_MESH_TASKS_INDIRECT_COUNT_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DRAW_MESH_TASKS_INDIRECT_COUNT_NV;
   cmd->u.draw_mesh_tasks_indirect_count_nv.buffer = buffer;
   cmd->u.draw_mesh_tasks_indirect_count_nv.offset = offset;
   cmd->u.draw_mesh_tasks_indirect_count_nv.count_buffer = countBuffer;
   cmd->u.draw_mesh_tasks_indirect_count_nv.count_buffer_offset = countBufferOffset;
   cmd->u.draw_mesh_tasks_indirect_count_nv.max_draw_count = maxDrawCount;
   cmd->u.draw_mesh_tasks_indirect_count_nv.stride = stride;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_draw_mesh_tasks_ext(struct vk_cmd_queue *queue,
                                struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_draw_mesh_tasks_ext(struct vk_cmd_queue *queue
, uint32_t groupCountX
, uint32_t groupCountY
, uint32_t groupCountZ
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DRAW_MESH_TASKS_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DRAW_MESH_TASKS_EXT;
   cmd->u.draw_mesh_tasks_ext.group_count_x = groupCountX;
   cmd->u.draw_mesh_tasks_ext.group_count_y = groupCountY;
   cmd->u.draw_mesh_tasks_ext.group_count_z = groupCountZ;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_draw_mesh_tasks_indirect_ext(struct vk_cmd_queue *queue,
                                         struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_draw_mesh_tasks_indirect_ext(struct vk_cmd_queue *queue
, VkBuffer buffer
, VkDeviceSize offset
, uint32_t drawCount
, uint32_t stride
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DRAW_MESH_TASKS_INDIRECT_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DRAW_MESH_TASKS_INDIRECT_EXT;
   cmd->u.draw_mesh_tasks_indirect_ext.buffer = buffer;
   cmd->u.draw_mesh_tasks_indirect_ext.offset = offset;
   cmd->u.draw_mesh_tasks_indirect_ext.draw_count = drawCount;
   cmd->u.draw_mesh_tasks_indirect_ext.stride = stride;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_draw_mesh_tasks_indirect_count_ext(struct vk_cmd_queue *queue,
                                               struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_draw_mesh_tasks_indirect_count_ext(struct vk_cmd_queue *queue
, VkBuffer buffer
, VkDeviceSize offset
, VkBuffer countBuffer
, VkDeviceSize countBufferOffset
, uint32_t maxDrawCount
, uint32_t stride
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DRAW_MESH_TASKS_INDIRECT_COUNT_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DRAW_MESH_TASKS_INDIRECT_COUNT_EXT;
   cmd->u.draw_mesh_tasks_indirect_count_ext.buffer = buffer;
   cmd->u.draw_mesh_tasks_indirect_count_ext.offset = offset;
   cmd->u.draw_mesh_tasks_indirect_count_ext.count_buffer = countBuffer;
   cmd->u.draw_mesh_tasks_indirect_count_ext.count_buffer_offset = countBufferOffset;
   cmd->u.draw_mesh_tasks_indirect_count_ext.max_draw_count = maxDrawCount;
   cmd->u.draw_mesh_tasks_indirect_count_ext.stride = stride;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_bind_invocation_mask_huawei(struct vk_cmd_queue *queue,
                                        struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_bind_invocation_mask_huawei(struct vk_cmd_queue *queue
, VkImageView imageView
, VkImageLayout imageLayout
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BIND_INVOCATION_MASK_HUAWEI], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BIND_INVOCATION_MASK_HUAWEI;
   cmd->u.bind_invocation_mask_huawei.image_view = imageView;
   cmd->u.bind_invocation_mask_huawei.image_layout = imageLayout;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_copy_acceleration_structure_nv(struct vk_cmd_queue *queue,
                                           struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_copy_acceleration_structure_nv(struct vk_cmd_queue *queue
, VkAccelerationStructureNV dst
, VkAccelerationStructureNV src
, VkCopyAccelerationStructureModeKHR mode
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_ACCELERATION_STRUCTURE_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_ACCELERATION_STRUCTURE_NV;
   cmd->u.copy_acceleration_structure_nv.dst = dst;
   cmd->u.copy_acceleration_structure_nv.src = src;
   cmd->u.copy_acceleration_structure_nv.mode = mode;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_copy_acceleration_structure_khr(struct vk_cmd_queue *queue,
                                            struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.copy_acceleration_structure_khr.info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.copy_acceleration_structure_khr.info);

}

VkResult vk_enqueue_cmd_copy_acceleration_structure_khr(struct vk_cmd_queue *queue
, const VkCopyAccelerationStructureInfoKHR* pInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_ACCELERATION_STRUCTURE_KHR], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_ACCELERATION_STRUCTURE_KHR;
   if (pInfo) {
      cmd->u.copy_acceleration_structure_khr.info = vk_zalloc(queue->alloc, sizeof(VkCopyAccelerationStructureInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.copy_acceleration_structure_khr.info == NULL) goto err;
      VkCopyAccelerationStructureInfoKHR *tmp_dst1 = (void *)cmd->u.copy_acceleration_structure_khr.info;
      VkCopyAccelerationStructureInfoKHR *tmp_src2 = (void *)pInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkCopyAccelerationStructureInfoKHR));
   } else {
      cmd->u.copy_acceleration_structure_khr.info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_copy_acceleration_structure_khr(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_copy_acceleration_structure_to_memory_khr(struct vk_cmd_queue *queue,
                                                      struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.copy_acceleration_structure_to_memory_khr.info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.copy_acceleration_structure_to_memory_khr.info);

}

VkResult vk_enqueue_cmd_copy_acceleration_structure_to_memory_khr(struct vk_cmd_queue *queue
, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_KHR], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_KHR;
   if (pInfo) {
      cmd->u.copy_acceleration_structure_to_memory_khr.info = vk_zalloc(queue->alloc, sizeof(VkCopyAccelerationStructureToMemoryInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.copy_acceleration_structure_to_memory_khr.info == NULL) goto err;
      VkCopyAccelerationStructureToMemoryInfoKHR *tmp_dst1 = (void *)cmd->u.copy_acceleration_structure_to_memory_khr.info;
      VkCopyAccelerationStructureToMemoryInfoKHR *tmp_src2 = (void *)pInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkCopyAccelerationStructureToMemoryInfoKHR));
   } else {
      cmd->u.copy_acceleration_structure_to_memory_khr.info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_copy_acceleration_structure_to_memory_khr(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_copy_memory_to_acceleration_structure_khr(struct vk_cmd_queue *queue,
                                                      struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.copy_memory_to_acceleration_structure_khr.info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.copy_memory_to_acceleration_structure_khr.info);

}

VkResult vk_enqueue_cmd_copy_memory_to_acceleration_structure_khr(struct vk_cmd_queue *queue
, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_KHR], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_KHR;
   if (pInfo) {
      cmd->u.copy_memory_to_acceleration_structure_khr.info = vk_zalloc(queue->alloc, sizeof(VkCopyMemoryToAccelerationStructureInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.copy_memory_to_acceleration_structure_khr.info == NULL) goto err;
      VkCopyMemoryToAccelerationStructureInfoKHR *tmp_dst1 = (void *)cmd->u.copy_memory_to_acceleration_structure_khr.info;
      VkCopyMemoryToAccelerationStructureInfoKHR *tmp_src2 = (void *)pInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkCopyMemoryToAccelerationStructureInfoKHR));
   } else {
      cmd->u.copy_memory_to_acceleration_structure_khr.info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_copy_memory_to_acceleration_structure_khr(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_write_acceleration_structures_properties_khr(struct vk_cmd_queue *queue,
                                                         struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkAccelerationStructureKHR* )cmd->u.write_acceleration_structures_properties_khr.acceleration_structures);
}

VkResult vk_enqueue_cmd_write_acceleration_structures_properties_khr(struct vk_cmd_queue *queue
, uint32_t accelerationStructureCount
, const VkAccelerationStructureKHR* pAccelerationStructures
, VkQueryType queryType
, VkQueryPool queryPool
, uint32_t firstQuery
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_WRITE_ACCELERATION_STRUCTURES_PROPERTIES_KHR], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_WRITE_ACCELERATION_STRUCTURES_PROPERTIES_KHR;
   cmd->u.write_acceleration_structures_properties_khr.acceleration_structure_count = accelerationStructureCount;
   if (pAccelerationStructures) {
      cmd->u.write_acceleration_structures_properties_khr.acceleration_structures = vk_zalloc(queue->alloc, sizeof(*cmd->u.write_acceleration_structures_properties_khr.acceleration_structures) * (accelerationStructureCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.write_acceleration_structures_properties_khr.acceleration_structures == NULL) goto err;
      memcpy((void*)cmd->u.write_acceleration_structures_properties_khr.acceleration_structures, pAccelerationStructures, sizeof(*cmd->u.write_acceleration_structures_properties_khr.acceleration_structures) * (accelerationStructureCount));
   }
   cmd->u.write_acceleration_structures_properties_khr.query_type = queryType;
   cmd->u.write_acceleration_structures_properties_khr.query_pool = queryPool;
   cmd->u.write_acceleration_structures_properties_khr.first_query = firstQuery;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_write_acceleration_structures_properties_khr(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_write_acceleration_structures_properties_nv(struct vk_cmd_queue *queue,
                                                        struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkAccelerationStructureNV* )cmd->u.write_acceleration_structures_properties_nv.acceleration_structures);
}

VkResult vk_enqueue_cmd_write_acceleration_structures_properties_nv(struct vk_cmd_queue *queue
, uint32_t accelerationStructureCount
, const VkAccelerationStructureNV* pAccelerationStructures
, VkQueryType queryType
, VkQueryPool queryPool
, uint32_t firstQuery
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_WRITE_ACCELERATION_STRUCTURES_PROPERTIES_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_WRITE_ACCELERATION_STRUCTURES_PROPERTIES_NV;
   cmd->u.write_acceleration_structures_properties_nv.acceleration_structure_count = accelerationStructureCount;
   if (pAccelerationStructures) {
      cmd->u.write_acceleration_structures_properties_nv.acceleration_structures = vk_zalloc(queue->alloc, sizeof(*cmd->u.write_acceleration_structures_properties_nv.acceleration_structures) * (accelerationStructureCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.write_acceleration_structures_properties_nv.acceleration_structures == NULL) goto err;
      memcpy((void*)cmd->u.write_acceleration_structures_properties_nv.acceleration_structures, pAccelerationStructures, sizeof(*cmd->u.write_acceleration_structures_properties_nv.acceleration_structures) * (accelerationStructureCount));
   }
   cmd->u.write_acceleration_structures_properties_nv.query_type = queryType;
   cmd->u.write_acceleration_structures_properties_nv.query_pool = queryPool;
   cmd->u.write_acceleration_structures_properties_nv.first_query = firstQuery;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_write_acceleration_structures_properties_nv(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_build_acceleration_structure_nv(struct vk_cmd_queue *queue,
                                            struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.build_acceleration_structure_nv.info) {
      VkGeometryNV *pGeometries1 = (void *)(cmd->u.build_acceleration_structure_nv.info->pGeometries);
      if (cmd->u.build_acceleration_structure_nv.info->geometryCount) {
      }
      vk_free(queue->alloc, pGeometries1);
   }
   vk_free(queue->alloc, (void*)cmd->u.build_acceleration_structure_nv.info);

}

VkResult vk_enqueue_cmd_build_acceleration_structure_nv(struct vk_cmd_queue *queue
, const VkAccelerationStructureInfoNV* pInfo
, VkBuffer instanceData
, VkDeviceSize instanceOffset
, VkBool32 update
, VkAccelerationStructureNV dst
, VkAccelerationStructureNV src
, VkBuffer scratch
, VkDeviceSize scratchOffset
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BUILD_ACCELERATION_STRUCTURE_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BUILD_ACCELERATION_STRUCTURE_NV;
   if (pInfo) {
      cmd->u.build_acceleration_structure_nv.info = vk_zalloc(queue->alloc, sizeof(VkAccelerationStructureInfoNV), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.build_acceleration_structure_nv.info == NULL) goto err;
      VkAccelerationStructureInfoNV *tmp_dst1 = (void *)cmd->u.build_acceleration_structure_nv.info;
      VkAccelerationStructureInfoNV *tmp_src2 = (void *)pInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkAccelerationStructureInfoNV));
      if (tmp_src2->pGeometries) {
         tmp_dst1->pGeometries = vk_zalloc(queue->alloc, sizeof(VkGeometryNV) * tmp_src2->geometryCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pGeometries == NULL) goto err;
         VkGeometryNV *tmp_dst3 = (void *)tmp_dst1->pGeometries;
         VkGeometryNV *tmp_src4 = (void *)tmp_src2->pGeometries;
         memcpy(tmp_dst3, tmp_src4, sizeof(VkGeometryNV) * tmp_src2->geometryCount);
         for (uint32_t i5 = 0; i5 < tmp_src2->geometryCount; i5++) {
            VkGeometryNV *tmp_dst6 = tmp_dst3 + i5; (void)tmp_dst6;
            VkGeometryNV *tmp_src7 = tmp_src4 + i5; (void)tmp_src7;
            }
         } else {
            tmp_dst1->pGeometries = NULL;
         }
      } else {
         cmd->u.build_acceleration_structure_nv.info = NULL;
      }
      cmd->u.build_acceleration_structure_nv.instance_data = instanceData;
      cmd->u.build_acceleration_structure_nv.instance_offset = instanceOffset;
      cmd->u.build_acceleration_structure_nv.update = update;
      cmd->u.build_acceleration_structure_nv.dst = dst;
      cmd->u.build_acceleration_structure_nv.src = src;
      cmd->u.build_acceleration_structure_nv.scratch = scratch;
      cmd->u.build_acceleration_structure_nv.scratch_offset = scratchOffset;

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_build_acceleration_structure_nv(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_trace_rays_khr(struct vk_cmd_queue *queue,
                           struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.trace_rays_khr.raygen_shader_binding_table) {
   }
   vk_free(queue->alloc, (void*)cmd->u.trace_rays_khr.raygen_shader_binding_table);

   if (cmd->u.trace_rays_khr.miss_shader_binding_table) {
   }
   vk_free(queue->alloc, (void*)cmd->u.trace_rays_khr.miss_shader_binding_table);

   if (cmd->u.trace_rays_khr.hit_shader_binding_table) {
   }
   vk_free(queue->alloc, (void*)cmd->u.trace_rays_khr.hit_shader_binding_table);

   if (cmd->u.trace_rays_khr.callable_shader_binding_table) {
   }
   vk_free(queue->alloc, (void*)cmd->u.trace_rays_khr.callable_shader_binding_table);

}

VkResult vk_enqueue_cmd_trace_rays_khr(struct vk_cmd_queue *queue
, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable
, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable
, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable
, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable
, uint32_t width
, uint32_t height
, uint32_t depth
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_TRACE_RAYS_KHR], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_TRACE_RAYS_KHR;
   if (pRaygenShaderBindingTable) {
      cmd->u.trace_rays_khr.raygen_shader_binding_table = vk_zalloc(queue->alloc, sizeof(VkStridedDeviceAddressRegionKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.trace_rays_khr.raygen_shader_binding_table == NULL) goto err;
      VkStridedDeviceAddressRegionKHR *tmp_dst1 = (void *)cmd->u.trace_rays_khr.raygen_shader_binding_table;
      VkStridedDeviceAddressRegionKHR *tmp_src2 = (void *)pRaygenShaderBindingTable;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkStridedDeviceAddressRegionKHR));
   } else {
      cmd->u.trace_rays_khr.raygen_shader_binding_table = NULL;
   }
   if (pMissShaderBindingTable) {
      cmd->u.trace_rays_khr.miss_shader_binding_table = vk_zalloc(queue->alloc, sizeof(VkStridedDeviceAddressRegionKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.trace_rays_khr.miss_shader_binding_table == NULL) goto err;
      VkStridedDeviceAddressRegionKHR *tmp_dst3 = (void *)cmd->u.trace_rays_khr.miss_shader_binding_table;
      VkStridedDeviceAddressRegionKHR *tmp_src4 = (void *)pMissShaderBindingTable;
      memcpy(tmp_dst3, tmp_src4, sizeof(VkStridedDeviceAddressRegionKHR));
   } else {
      cmd->u.trace_rays_khr.miss_shader_binding_table = NULL;
   }
   if (pHitShaderBindingTable) {
      cmd->u.trace_rays_khr.hit_shader_binding_table = vk_zalloc(queue->alloc, sizeof(VkStridedDeviceAddressRegionKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.trace_rays_khr.hit_shader_binding_table == NULL) goto err;
      VkStridedDeviceAddressRegionKHR *tmp_dst5 = (void *)cmd->u.trace_rays_khr.hit_shader_binding_table;
      VkStridedDeviceAddressRegionKHR *tmp_src6 = (void *)pHitShaderBindingTable;
      memcpy(tmp_dst5, tmp_src6, sizeof(VkStridedDeviceAddressRegionKHR));
   } else {
      cmd->u.trace_rays_khr.hit_shader_binding_table = NULL;
   }
   if (pCallableShaderBindingTable) {
      cmd->u.trace_rays_khr.callable_shader_binding_table = vk_zalloc(queue->alloc, sizeof(VkStridedDeviceAddressRegionKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.trace_rays_khr.callable_shader_binding_table == NULL) goto err;
      VkStridedDeviceAddressRegionKHR *tmp_dst7 = (void *)cmd->u.trace_rays_khr.callable_shader_binding_table;
      VkStridedDeviceAddressRegionKHR *tmp_src8 = (void *)pCallableShaderBindingTable;
      memcpy(tmp_dst7, tmp_src8, sizeof(VkStridedDeviceAddressRegionKHR));
   } else {
      cmd->u.trace_rays_khr.callable_shader_binding_table = NULL;
   }
   cmd->u.trace_rays_khr.width = width;
   cmd->u.trace_rays_khr.height = height;
   cmd->u.trace_rays_khr.depth = depth;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_trace_rays_khr(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_trace_rays_nv(struct vk_cmd_queue *queue,
                          struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_trace_rays_nv(struct vk_cmd_queue *queue
, VkBuffer raygenShaderBindingTableBuffer
, VkDeviceSize raygenShaderBindingOffset
, VkBuffer missShaderBindingTableBuffer
, VkDeviceSize missShaderBindingOffset
, VkDeviceSize missShaderBindingStride
, VkBuffer hitShaderBindingTableBuffer
, VkDeviceSize hitShaderBindingOffset
, VkDeviceSize hitShaderBindingStride
, VkBuffer callableShaderBindingTableBuffer
, VkDeviceSize callableShaderBindingOffset
, VkDeviceSize callableShaderBindingStride
, uint32_t width
, uint32_t height
, uint32_t depth
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_TRACE_RAYS_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_TRACE_RAYS_NV;
   cmd->u.trace_rays_nv.raygen_shader_binding_table_buffer = raygenShaderBindingTableBuffer;
   cmd->u.trace_rays_nv.raygen_shader_binding_offset = raygenShaderBindingOffset;
   cmd->u.trace_rays_nv.miss_shader_binding_table_buffer = missShaderBindingTableBuffer;
   cmd->u.trace_rays_nv.miss_shader_binding_offset = missShaderBindingOffset;
   cmd->u.trace_rays_nv.miss_shader_binding_stride = missShaderBindingStride;
   cmd->u.trace_rays_nv.hit_shader_binding_table_buffer = hitShaderBindingTableBuffer;
   cmd->u.trace_rays_nv.hit_shader_binding_offset = hitShaderBindingOffset;
   cmd->u.trace_rays_nv.hit_shader_binding_stride = hitShaderBindingStride;
   cmd->u.trace_rays_nv.callable_shader_binding_table_buffer = callableShaderBindingTableBuffer;
   cmd->u.trace_rays_nv.callable_shader_binding_offset = callableShaderBindingOffset;
   cmd->u.trace_rays_nv.callable_shader_binding_stride = callableShaderBindingStride;
   cmd->u.trace_rays_nv.width = width;
   cmd->u.trace_rays_nv.height = height;
   cmd->u.trace_rays_nv.depth = depth;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_trace_rays_indirect_khr(struct vk_cmd_queue *queue,
                                    struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.trace_rays_indirect_khr.raygen_shader_binding_table) {
   }
   vk_free(queue->alloc, (void*)cmd->u.trace_rays_indirect_khr.raygen_shader_binding_table);

   if (cmd->u.trace_rays_indirect_khr.miss_shader_binding_table) {
   }
   vk_free(queue->alloc, (void*)cmd->u.trace_rays_indirect_khr.miss_shader_binding_table);

   if (cmd->u.trace_rays_indirect_khr.hit_shader_binding_table) {
   }
   vk_free(queue->alloc, (void*)cmd->u.trace_rays_indirect_khr.hit_shader_binding_table);

   if (cmd->u.trace_rays_indirect_khr.callable_shader_binding_table) {
   }
   vk_free(queue->alloc, (void*)cmd->u.trace_rays_indirect_khr.callable_shader_binding_table);

}

VkResult vk_enqueue_cmd_trace_rays_indirect_khr(struct vk_cmd_queue *queue
, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable
, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable
, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable
, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable
, VkDeviceAddress indirectDeviceAddress
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_TRACE_RAYS_INDIRECT_KHR], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_TRACE_RAYS_INDIRECT_KHR;
   if (pRaygenShaderBindingTable) {
      cmd->u.trace_rays_indirect_khr.raygen_shader_binding_table = vk_zalloc(queue->alloc, sizeof(VkStridedDeviceAddressRegionKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.trace_rays_indirect_khr.raygen_shader_binding_table == NULL) goto err;
      VkStridedDeviceAddressRegionKHR *tmp_dst1 = (void *)cmd->u.trace_rays_indirect_khr.raygen_shader_binding_table;
      VkStridedDeviceAddressRegionKHR *tmp_src2 = (void *)pRaygenShaderBindingTable;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkStridedDeviceAddressRegionKHR));
   } else {
      cmd->u.trace_rays_indirect_khr.raygen_shader_binding_table = NULL;
   }
   if (pMissShaderBindingTable) {
      cmd->u.trace_rays_indirect_khr.miss_shader_binding_table = vk_zalloc(queue->alloc, sizeof(VkStridedDeviceAddressRegionKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.trace_rays_indirect_khr.miss_shader_binding_table == NULL) goto err;
      VkStridedDeviceAddressRegionKHR *tmp_dst3 = (void *)cmd->u.trace_rays_indirect_khr.miss_shader_binding_table;
      VkStridedDeviceAddressRegionKHR *tmp_src4 = (void *)pMissShaderBindingTable;
      memcpy(tmp_dst3, tmp_src4, sizeof(VkStridedDeviceAddressRegionKHR));
   } else {
      cmd->u.trace_rays_indirect_khr.miss_shader_binding_table = NULL;
   }
   if (pHitShaderBindingTable) {
      cmd->u.trace_rays_indirect_khr.hit_shader_binding_table = vk_zalloc(queue->alloc, sizeof(VkStridedDeviceAddressRegionKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.trace_rays_indirect_khr.hit_shader_binding_table == NULL) goto err;
      VkStridedDeviceAddressRegionKHR *tmp_dst5 = (void *)cmd->u.trace_rays_indirect_khr.hit_shader_binding_table;
      VkStridedDeviceAddressRegionKHR *tmp_src6 = (void *)pHitShaderBindingTable;
      memcpy(tmp_dst5, tmp_src6, sizeof(VkStridedDeviceAddressRegionKHR));
   } else {
      cmd->u.trace_rays_indirect_khr.hit_shader_binding_table = NULL;
   }
   if (pCallableShaderBindingTable) {
      cmd->u.trace_rays_indirect_khr.callable_shader_binding_table = vk_zalloc(queue->alloc, sizeof(VkStridedDeviceAddressRegionKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.trace_rays_indirect_khr.callable_shader_binding_table == NULL) goto err;
      VkStridedDeviceAddressRegionKHR *tmp_dst7 = (void *)cmd->u.trace_rays_indirect_khr.callable_shader_binding_table;
      VkStridedDeviceAddressRegionKHR *tmp_src8 = (void *)pCallableShaderBindingTable;
      memcpy(tmp_dst7, tmp_src8, sizeof(VkStridedDeviceAddressRegionKHR));
   } else {
      cmd->u.trace_rays_indirect_khr.callable_shader_binding_table = NULL;
   }
   cmd->u.trace_rays_indirect_khr.indirect_device_address = indirectDeviceAddress;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_trace_rays_indirect_khr(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_trace_rays_indirect2_khr(struct vk_cmd_queue *queue,
                                     struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_trace_rays_indirect2_khr(struct vk_cmd_queue *queue
, VkDeviceAddress indirectDeviceAddress
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_TRACE_RAYS_INDIRECT2_KHR], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_TRACE_RAYS_INDIRECT2_KHR;
   cmd->u.trace_rays_indirect2_khr.indirect_device_address = indirectDeviceAddress;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_build_cluster_acceleration_structure_indirect_nv(struct vk_cmd_queue *queue,
                                                             struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.build_cluster_acceleration_structure_indirect_nv.command_infos) {
   }
   vk_free(queue->alloc, (void*)cmd->u.build_cluster_acceleration_structure_indirect_nv.command_infos);

}

VkResult vk_enqueue_cmd_build_cluster_acceleration_structure_indirect_nv(struct vk_cmd_queue *queue
, const VkClusterAccelerationStructureCommandsInfoNV*  pCommandInfos
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BUILD_CLUSTER_ACCELERATION_STRUCTURE_INDIRECT_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BUILD_CLUSTER_ACCELERATION_STRUCTURE_INDIRECT_NV;
   if (pCommandInfos) {
      cmd->u.build_cluster_acceleration_structure_indirect_nv.command_infos = vk_zalloc(queue->alloc, sizeof(VkClusterAccelerationStructureCommandsInfoNV), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.build_cluster_acceleration_structure_indirect_nv.command_infos == NULL) goto err;
      VkClusterAccelerationStructureCommandsInfoNV *tmp_dst1 = (void *)cmd->u.build_cluster_acceleration_structure_indirect_nv.command_infos;
      VkClusterAccelerationStructureCommandsInfoNV *tmp_src2 = (void *)pCommandInfos;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkClusterAccelerationStructureCommandsInfoNV));
   } else {
      cmd->u.build_cluster_acceleration_structure_indirect_nv.command_infos = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_build_cluster_acceleration_structure_indirect_nv(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_ray_tracing_pipeline_stack_size_khr(struct vk_cmd_queue *queue,
                                                    struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_ray_tracing_pipeline_stack_size_khr(struct vk_cmd_queue *queue
, uint32_t pipelineStackSize
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_RAY_TRACING_PIPELINE_STACK_SIZE_KHR], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_RAY_TRACING_PIPELINE_STACK_SIZE_KHR;
   cmd->u.set_ray_tracing_pipeline_stack_size_khr.pipeline_stack_size = pipelineStackSize;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_performance_marker_intel(struct vk_cmd_queue *queue,
                                         struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.set_performance_marker_intel.marker_info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.set_performance_marker_intel.marker_info);

}


static void
vk_free_cmd_set_performance_stream_marker_intel(struct vk_cmd_queue *queue,
                                                struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.set_performance_stream_marker_intel.marker_info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.set_performance_stream_marker_intel.marker_info);

}


static void
vk_free_cmd_set_performance_override_intel(struct vk_cmd_queue *queue,
                                           struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.set_performance_override_intel.override_info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.set_performance_override_intel.override_info);

}


static void
vk_free_cmd_set_line_stipple(struct vk_cmd_queue *queue,
                             struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_line_stipple(struct vk_cmd_queue *queue
, uint32_t lineStippleFactor
, uint16_t lineStipplePattern
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_LINE_STIPPLE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_LINE_STIPPLE;
   cmd->u.set_line_stipple.line_stipple_factor = lineStippleFactor;
   cmd->u.set_line_stipple.line_stipple_pattern = lineStipplePattern;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_build_acceleration_structures_khr(struct vk_cmd_queue *queue,
                                              struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkAccelerationStructureBuildGeometryInfoKHR* )cmd->u.build_acceleration_structures_khr.infos);
   vk_free(queue->alloc, ( VkAccelerationStructureBuildRangeInfoKHR* * )cmd->u.build_acceleration_structures_khr.pp_build_range_infos);
}


static void
vk_free_cmd_build_acceleration_structures_indirect_khr(struct vk_cmd_queue *queue,
                                                       struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkAccelerationStructureBuildGeometryInfoKHR* )cmd->u.build_acceleration_structures_indirect_khr.infos);
   vk_free(queue->alloc, ( VkDeviceAddress*             )cmd->u.build_acceleration_structures_indirect_khr.indirect_device_addresses);
   vk_free(queue->alloc, ( uint32_t*                    )cmd->u.build_acceleration_structures_indirect_khr.indirect_strides);
   vk_free(queue->alloc, ( uint32_t* *             )cmd->u.build_acceleration_structures_indirect_khr.pp_max_primitive_counts);
}

VkResult vk_enqueue_cmd_build_acceleration_structures_indirect_khr(struct vk_cmd_queue *queue
, uint32_t                                           infoCount
, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos
, const VkDeviceAddress*             pIndirectDeviceAddresses
, const uint32_t*                    pIndirectStrides
, const uint32_t* const*             ppMaxPrimitiveCounts
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BUILD_ACCELERATION_STRUCTURES_INDIRECT_KHR], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BUILD_ACCELERATION_STRUCTURES_INDIRECT_KHR;
   cmd->u.build_acceleration_structures_indirect_khr.info_count = infoCount;
   if (pInfos) {
      cmd->u.build_acceleration_structures_indirect_khr.infos = vk_zalloc(queue->alloc, sizeof(*cmd->u.build_acceleration_structures_indirect_khr.infos) * (infoCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.build_acceleration_structures_indirect_khr.infos == NULL) goto err;
      memcpy((void*)cmd->u.build_acceleration_structures_indirect_khr.infos, pInfos, sizeof(*cmd->u.build_acceleration_structures_indirect_khr.infos) * (infoCount));
   }
   if (pIndirectDeviceAddresses) {
      cmd->u.build_acceleration_structures_indirect_khr.indirect_device_addresses = vk_zalloc(queue->alloc, sizeof(*cmd->u.build_acceleration_structures_indirect_khr.indirect_device_addresses) * (infoCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.build_acceleration_structures_indirect_khr.indirect_device_addresses == NULL) goto err;
      memcpy((void*)cmd->u.build_acceleration_structures_indirect_khr.indirect_device_addresses, pIndirectDeviceAddresses, sizeof(*cmd->u.build_acceleration_structures_indirect_khr.indirect_device_addresses) * (infoCount));
   }
   if (pIndirectStrides) {
      cmd->u.build_acceleration_structures_indirect_khr.indirect_strides = vk_zalloc(queue->alloc, sizeof(*cmd->u.build_acceleration_structures_indirect_khr.indirect_strides) * (infoCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.build_acceleration_structures_indirect_khr.indirect_strides == NULL) goto err;
      memcpy((void*)cmd->u.build_acceleration_structures_indirect_khr.indirect_strides, pIndirectStrides, sizeof(*cmd->u.build_acceleration_structures_indirect_khr.indirect_strides) * (infoCount));
   }
   if (ppMaxPrimitiveCounts) {
      cmd->u.build_acceleration_structures_indirect_khr.pp_max_primitive_counts = vk_zalloc(queue->alloc, sizeof(*cmd->u.build_acceleration_structures_indirect_khr.pp_max_primitive_counts) * (infoCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.build_acceleration_structures_indirect_khr.pp_max_primitive_counts == NULL) goto err;
      memcpy((void*)cmd->u.build_acceleration_structures_indirect_khr.pp_max_primitive_counts, ppMaxPrimitiveCounts, sizeof(*cmd->u.build_acceleration_structures_indirect_khr.pp_max_primitive_counts) * (infoCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_build_acceleration_structures_indirect_khr(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_cull_mode(struct vk_cmd_queue *queue,
                          struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_cull_mode(struct vk_cmd_queue *queue
, VkCullModeFlags cullMode
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_CULL_MODE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_CULL_MODE;
   cmd->u.set_cull_mode.cull_mode = cullMode;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_front_face(struct vk_cmd_queue *queue,
                           struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_front_face(struct vk_cmd_queue *queue
, VkFrontFace frontFace
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_FRONT_FACE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_FRONT_FACE;
   cmd->u.set_front_face.front_face = frontFace;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_primitive_topology(struct vk_cmd_queue *queue,
                                   struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_primitive_topology(struct vk_cmd_queue *queue
, VkPrimitiveTopology primitiveTopology
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_PRIMITIVE_TOPOLOGY], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_PRIMITIVE_TOPOLOGY;
   cmd->u.set_primitive_topology.primitive_topology = primitiveTopology;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_viewport_with_count(struct vk_cmd_queue *queue,
                                    struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkViewport* )cmd->u.set_viewport_with_count.viewports);
}

VkResult vk_enqueue_cmd_set_viewport_with_count(struct vk_cmd_queue *queue
, uint32_t viewportCount
, const VkViewport* pViewports
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_VIEWPORT_WITH_COUNT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_VIEWPORT_WITH_COUNT;
   cmd->u.set_viewport_with_count.viewport_count = viewportCount;
   if (pViewports) {
      cmd->u.set_viewport_with_count.viewports = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_viewport_with_count.viewports) * (viewportCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_viewport_with_count.viewports == NULL) goto err;
      memcpy((void*)cmd->u.set_viewport_with_count.viewports, pViewports, sizeof(*cmd->u.set_viewport_with_count.viewports) * (viewportCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_viewport_with_count(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_scissor_with_count(struct vk_cmd_queue *queue,
                                   struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkRect2D* )cmd->u.set_scissor_with_count.scissors);
}

VkResult vk_enqueue_cmd_set_scissor_with_count(struct vk_cmd_queue *queue
, uint32_t scissorCount
, const VkRect2D* pScissors
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_SCISSOR_WITH_COUNT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_SCISSOR_WITH_COUNT;
   cmd->u.set_scissor_with_count.scissor_count = scissorCount;
   if (pScissors) {
      cmd->u.set_scissor_with_count.scissors = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_scissor_with_count.scissors) * (scissorCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_scissor_with_count.scissors == NULL) goto err;
      memcpy((void*)cmd->u.set_scissor_with_count.scissors, pScissors, sizeof(*cmd->u.set_scissor_with_count.scissors) * (scissorCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_scissor_with_count(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_bind_index_buffer2(struct vk_cmd_queue *queue,
                               struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_bind_index_buffer2(struct vk_cmd_queue *queue
, VkBuffer buffer
, VkDeviceSize offset
, VkDeviceSize size
, VkIndexType indexType
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BIND_INDEX_BUFFER2], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BIND_INDEX_BUFFER2;
   cmd->u.bind_index_buffer2.buffer = buffer;
   cmd->u.bind_index_buffer2.offset = offset;
   cmd->u.bind_index_buffer2.size = size;
   cmd->u.bind_index_buffer2.index_type = indexType;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_bind_vertex_buffers2(struct vk_cmd_queue *queue,
                                 struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkBuffer* )cmd->u.bind_vertex_buffers2.buffers);
   vk_free(queue->alloc, ( VkDeviceSize* )cmd->u.bind_vertex_buffers2.offsets);
   vk_free(queue->alloc, ( VkDeviceSize* )cmd->u.bind_vertex_buffers2.sizes);
   vk_free(queue->alloc, ( VkDeviceSize* )cmd->u.bind_vertex_buffers2.strides);
}

VkResult vk_enqueue_cmd_bind_vertex_buffers2(struct vk_cmd_queue *queue
, uint32_t firstBinding
, uint32_t bindingCount
, const VkBuffer* pBuffers
, const VkDeviceSize* pOffsets
, const VkDeviceSize* pSizes
, const VkDeviceSize* pStrides
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BIND_VERTEX_BUFFERS2], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BIND_VERTEX_BUFFERS2;
   cmd->u.bind_vertex_buffers2.first_binding = firstBinding;
   cmd->u.bind_vertex_buffers2.binding_count = bindingCount;
   if (pBuffers) {
      cmd->u.bind_vertex_buffers2.buffers = vk_zalloc(queue->alloc, sizeof(*cmd->u.bind_vertex_buffers2.buffers) * (bindingCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.bind_vertex_buffers2.buffers == NULL) goto err;
      memcpy((void*)cmd->u.bind_vertex_buffers2.buffers, pBuffers, sizeof(*cmd->u.bind_vertex_buffers2.buffers) * (bindingCount));
   }
   if (pOffsets) {
      cmd->u.bind_vertex_buffers2.offsets = vk_zalloc(queue->alloc, sizeof(*cmd->u.bind_vertex_buffers2.offsets) * (bindingCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.bind_vertex_buffers2.offsets == NULL) goto err;
      memcpy((void*)cmd->u.bind_vertex_buffers2.offsets, pOffsets, sizeof(*cmd->u.bind_vertex_buffers2.offsets) * (bindingCount));
   }
   if (pSizes) {
      cmd->u.bind_vertex_buffers2.sizes = vk_zalloc(queue->alloc, sizeof(*cmd->u.bind_vertex_buffers2.sizes) * (bindingCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.bind_vertex_buffers2.sizes == NULL) goto err;
      memcpy((void*)cmd->u.bind_vertex_buffers2.sizes, pSizes, sizeof(*cmd->u.bind_vertex_buffers2.sizes) * (bindingCount));
   }
   if (pStrides) {
      cmd->u.bind_vertex_buffers2.strides = vk_zalloc(queue->alloc, sizeof(*cmd->u.bind_vertex_buffers2.strides) * (bindingCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.bind_vertex_buffers2.strides == NULL) goto err;
      memcpy((void*)cmd->u.bind_vertex_buffers2.strides, pStrides, sizeof(*cmd->u.bind_vertex_buffers2.strides) * (bindingCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_bind_vertex_buffers2(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_depth_test_enable(struct vk_cmd_queue *queue,
                                  struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_depth_test_enable(struct vk_cmd_queue *queue
, VkBool32 depthTestEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_DEPTH_TEST_ENABLE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_DEPTH_TEST_ENABLE;
   cmd->u.set_depth_test_enable.depth_test_enable = depthTestEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_depth_write_enable(struct vk_cmd_queue *queue,
                                   struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_depth_write_enable(struct vk_cmd_queue *queue
, VkBool32 depthWriteEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_DEPTH_WRITE_ENABLE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_DEPTH_WRITE_ENABLE;
   cmd->u.set_depth_write_enable.depth_write_enable = depthWriteEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_depth_compare_op(struct vk_cmd_queue *queue,
                                 struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_depth_compare_op(struct vk_cmd_queue *queue
, VkCompareOp depthCompareOp
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_DEPTH_COMPARE_OP], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_DEPTH_COMPARE_OP;
   cmd->u.set_depth_compare_op.depth_compare_op = depthCompareOp;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_depth_bounds_test_enable(struct vk_cmd_queue *queue,
                                         struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_depth_bounds_test_enable(struct vk_cmd_queue *queue
, VkBool32 depthBoundsTestEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_DEPTH_BOUNDS_TEST_ENABLE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_DEPTH_BOUNDS_TEST_ENABLE;
   cmd->u.set_depth_bounds_test_enable.depth_bounds_test_enable = depthBoundsTestEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_stencil_test_enable(struct vk_cmd_queue *queue,
                                    struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_stencil_test_enable(struct vk_cmd_queue *queue
, VkBool32 stencilTestEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_STENCIL_TEST_ENABLE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_STENCIL_TEST_ENABLE;
   cmd->u.set_stencil_test_enable.stencil_test_enable = stencilTestEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_stencil_op(struct vk_cmd_queue *queue,
                           struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_stencil_op(struct vk_cmd_queue *queue
, VkStencilFaceFlags faceMask
, VkStencilOp failOp
, VkStencilOp passOp
, VkStencilOp depthFailOp
, VkCompareOp compareOp
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_STENCIL_OP], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_STENCIL_OP;
   cmd->u.set_stencil_op.face_mask = faceMask;
   cmd->u.set_stencil_op.fail_op = failOp;
   cmd->u.set_stencil_op.pass_op = passOp;
   cmd->u.set_stencil_op.depth_fail_op = depthFailOp;
   cmd->u.set_stencil_op.compare_op = compareOp;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_patch_control_points_ext(struct vk_cmd_queue *queue,
                                         struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_patch_control_points_ext(struct vk_cmd_queue *queue
, uint32_t patchControlPoints
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_PATCH_CONTROL_POINTS_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_PATCH_CONTROL_POINTS_EXT;
   cmd->u.set_patch_control_points_ext.patch_control_points = patchControlPoints;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_rasterizer_discard_enable(struct vk_cmd_queue *queue,
                                          struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_rasterizer_discard_enable(struct vk_cmd_queue *queue
, VkBool32 rasterizerDiscardEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_RASTERIZER_DISCARD_ENABLE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_RASTERIZER_DISCARD_ENABLE;
   cmd->u.set_rasterizer_discard_enable.rasterizer_discard_enable = rasterizerDiscardEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_depth_bias_enable(struct vk_cmd_queue *queue,
                                  struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_depth_bias_enable(struct vk_cmd_queue *queue
, VkBool32 depthBiasEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_DEPTH_BIAS_ENABLE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_DEPTH_BIAS_ENABLE;
   cmd->u.set_depth_bias_enable.depth_bias_enable = depthBiasEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_logic_op_ext(struct vk_cmd_queue *queue,
                             struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_logic_op_ext(struct vk_cmd_queue *queue
, VkLogicOp logicOp
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_LOGIC_OP_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_LOGIC_OP_EXT;
   cmd->u.set_logic_op_ext.logic_op = logicOp;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_primitive_restart_enable(struct vk_cmd_queue *queue,
                                         struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_primitive_restart_enable(struct vk_cmd_queue *queue
, VkBool32 primitiveRestartEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_PRIMITIVE_RESTART_ENABLE], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_PRIMITIVE_RESTART_ENABLE;
   cmd->u.set_primitive_restart_enable.primitive_restart_enable = primitiveRestartEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_tessellation_domain_origin_ext(struct vk_cmd_queue *queue,
                                               struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_tessellation_domain_origin_ext(struct vk_cmd_queue *queue
, VkTessellationDomainOrigin domainOrigin
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_TESSELLATION_DOMAIN_ORIGIN_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_TESSELLATION_DOMAIN_ORIGIN_EXT;
   cmd->u.set_tessellation_domain_origin_ext.domain_origin = domainOrigin;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_depth_clamp_enable_ext(struct vk_cmd_queue *queue,
                                       struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_depth_clamp_enable_ext(struct vk_cmd_queue *queue
, VkBool32 depthClampEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_DEPTH_CLAMP_ENABLE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_DEPTH_CLAMP_ENABLE_EXT;
   cmd->u.set_depth_clamp_enable_ext.depth_clamp_enable = depthClampEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_polygon_mode_ext(struct vk_cmd_queue *queue,
                                 struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_polygon_mode_ext(struct vk_cmd_queue *queue
, VkPolygonMode polygonMode
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_POLYGON_MODE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_POLYGON_MODE_EXT;
   cmd->u.set_polygon_mode_ext.polygon_mode = polygonMode;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_rasterization_samples_ext(struct vk_cmd_queue *queue,
                                          struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_rasterization_samples_ext(struct vk_cmd_queue *queue
, VkSampleCountFlagBits  rasterizationSamples
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_RASTERIZATION_SAMPLES_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_RASTERIZATION_SAMPLES_EXT;
   cmd->u.set_rasterization_samples_ext.rasterization_samples = rasterizationSamples;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_sample_mask_ext(struct vk_cmd_queue *queue,
                                struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkSampleMask*    )cmd->u.set_sample_mask_ext.sample_mask);
}

VkResult vk_enqueue_cmd_set_sample_mask_ext(struct vk_cmd_queue *queue
, VkSampleCountFlagBits  samples
, const VkSampleMask*    pSampleMask
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_SAMPLE_MASK_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_SAMPLE_MASK_EXT;
   cmd->u.set_sample_mask_ext.samples = samples;
   if (pSampleMask) {
      cmd->u.set_sample_mask_ext.sample_mask = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_sample_mask_ext.sample_mask) * ((samples + 31) / 32), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_sample_mask_ext.sample_mask == NULL) goto err;
      memcpy((void*)cmd->u.set_sample_mask_ext.sample_mask, pSampleMask, sizeof(*cmd->u.set_sample_mask_ext.sample_mask) * ((samples + 31) / 32));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_sample_mask_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_alpha_to_coverage_enable_ext(struct vk_cmd_queue *queue,
                                             struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_alpha_to_coverage_enable_ext(struct vk_cmd_queue *queue
, VkBool32 alphaToCoverageEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_ALPHA_TO_COVERAGE_ENABLE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_ALPHA_TO_COVERAGE_ENABLE_EXT;
   cmd->u.set_alpha_to_coverage_enable_ext.alpha_to_coverage_enable = alphaToCoverageEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_alpha_to_one_enable_ext(struct vk_cmd_queue *queue,
                                        struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_alpha_to_one_enable_ext(struct vk_cmd_queue *queue
, VkBool32 alphaToOneEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_ALPHA_TO_ONE_ENABLE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_ALPHA_TO_ONE_ENABLE_EXT;
   cmd->u.set_alpha_to_one_enable_ext.alpha_to_one_enable = alphaToOneEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_logic_op_enable_ext(struct vk_cmd_queue *queue,
                                    struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_logic_op_enable_ext(struct vk_cmd_queue *queue
, VkBool32 logicOpEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_LOGIC_OP_ENABLE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_LOGIC_OP_ENABLE_EXT;
   cmd->u.set_logic_op_enable_ext.logic_op_enable = logicOpEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_color_blend_enable_ext(struct vk_cmd_queue *queue,
                                       struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkBool32* )cmd->u.set_color_blend_enable_ext.color_blend_enables);
}

VkResult vk_enqueue_cmd_set_color_blend_enable_ext(struct vk_cmd_queue *queue
, uint32_t firstAttachment
, uint32_t attachmentCount
, const VkBool32* pColorBlendEnables
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_COLOR_BLEND_ENABLE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_COLOR_BLEND_ENABLE_EXT;
   cmd->u.set_color_blend_enable_ext.first_attachment = firstAttachment;
   cmd->u.set_color_blend_enable_ext.attachment_count = attachmentCount;
   if (pColorBlendEnables) {
      cmd->u.set_color_blend_enable_ext.color_blend_enables = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_color_blend_enable_ext.color_blend_enables) * (attachmentCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_color_blend_enable_ext.color_blend_enables == NULL) goto err;
      memcpy((void*)cmd->u.set_color_blend_enable_ext.color_blend_enables, pColorBlendEnables, sizeof(*cmd->u.set_color_blend_enable_ext.color_blend_enables) * (attachmentCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_color_blend_enable_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_color_blend_equation_ext(struct vk_cmd_queue *queue,
                                         struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkColorBlendEquationEXT* )cmd->u.set_color_blend_equation_ext.color_blend_equations);
}

VkResult vk_enqueue_cmd_set_color_blend_equation_ext(struct vk_cmd_queue *queue
, uint32_t firstAttachment
, uint32_t attachmentCount
, const VkColorBlendEquationEXT* pColorBlendEquations
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_COLOR_BLEND_EQUATION_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_COLOR_BLEND_EQUATION_EXT;
   cmd->u.set_color_blend_equation_ext.first_attachment = firstAttachment;
   cmd->u.set_color_blend_equation_ext.attachment_count = attachmentCount;
   if (pColorBlendEquations) {
      cmd->u.set_color_blend_equation_ext.color_blend_equations = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_color_blend_equation_ext.color_blend_equations) * (attachmentCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_color_blend_equation_ext.color_blend_equations == NULL) goto err;
      memcpy((void*)cmd->u.set_color_blend_equation_ext.color_blend_equations, pColorBlendEquations, sizeof(*cmd->u.set_color_blend_equation_ext.color_blend_equations) * (attachmentCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_color_blend_equation_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_color_write_mask_ext(struct vk_cmd_queue *queue,
                                     struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkColorComponentFlags* )cmd->u.set_color_write_mask_ext.color_write_masks);
}

VkResult vk_enqueue_cmd_set_color_write_mask_ext(struct vk_cmd_queue *queue
, uint32_t firstAttachment
, uint32_t attachmentCount
, const VkColorComponentFlags* pColorWriteMasks
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_COLOR_WRITE_MASK_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_COLOR_WRITE_MASK_EXT;
   cmd->u.set_color_write_mask_ext.first_attachment = firstAttachment;
   cmd->u.set_color_write_mask_ext.attachment_count = attachmentCount;
   if (pColorWriteMasks) {
      cmd->u.set_color_write_mask_ext.color_write_masks = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_color_write_mask_ext.color_write_masks) * (attachmentCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_color_write_mask_ext.color_write_masks == NULL) goto err;
      memcpy((void*)cmd->u.set_color_write_mask_ext.color_write_masks, pColorWriteMasks, sizeof(*cmd->u.set_color_write_mask_ext.color_write_masks) * (attachmentCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_color_write_mask_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_rasterization_stream_ext(struct vk_cmd_queue *queue,
                                         struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_rasterization_stream_ext(struct vk_cmd_queue *queue
, uint32_t rasterizationStream
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_RASTERIZATION_STREAM_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_RASTERIZATION_STREAM_EXT;
   cmd->u.set_rasterization_stream_ext.rasterization_stream = rasterizationStream;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_conservative_rasterization_mode_ext(struct vk_cmd_queue *queue,
                                                    struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_conservative_rasterization_mode_ext(struct vk_cmd_queue *queue
, VkConservativeRasterizationModeEXT conservativeRasterizationMode
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_CONSERVATIVE_RASTERIZATION_MODE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_CONSERVATIVE_RASTERIZATION_MODE_EXT;
   cmd->u.set_conservative_rasterization_mode_ext.conservative_rasterization_mode = conservativeRasterizationMode;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_extra_primitive_overestimation_size_ext(struct vk_cmd_queue *queue,
                                                        struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_extra_primitive_overestimation_size_ext(struct vk_cmd_queue *queue
, float extraPrimitiveOverestimationSize
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT;
   cmd->u.set_extra_primitive_overestimation_size_ext.extra_primitive_overestimation_size = extraPrimitiveOverestimationSize;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_depth_clip_enable_ext(struct vk_cmd_queue *queue,
                                      struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_depth_clip_enable_ext(struct vk_cmd_queue *queue
, VkBool32 depthClipEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_DEPTH_CLIP_ENABLE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_DEPTH_CLIP_ENABLE_EXT;
   cmd->u.set_depth_clip_enable_ext.depth_clip_enable = depthClipEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_sample_locations_enable_ext(struct vk_cmd_queue *queue,
                                            struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_sample_locations_enable_ext(struct vk_cmd_queue *queue
, VkBool32 sampleLocationsEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_SAMPLE_LOCATIONS_ENABLE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_SAMPLE_LOCATIONS_ENABLE_EXT;
   cmd->u.set_sample_locations_enable_ext.sample_locations_enable = sampleLocationsEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_color_blend_advanced_ext(struct vk_cmd_queue *queue,
                                         struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkColorBlendAdvancedEXT* )cmd->u.set_color_blend_advanced_ext.color_blend_advanced);
}

VkResult vk_enqueue_cmd_set_color_blend_advanced_ext(struct vk_cmd_queue *queue
, uint32_t firstAttachment
, uint32_t attachmentCount
, const VkColorBlendAdvancedEXT* pColorBlendAdvanced
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_COLOR_BLEND_ADVANCED_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_COLOR_BLEND_ADVANCED_EXT;
   cmd->u.set_color_blend_advanced_ext.first_attachment = firstAttachment;
   cmd->u.set_color_blend_advanced_ext.attachment_count = attachmentCount;
   if (pColorBlendAdvanced) {
      cmd->u.set_color_blend_advanced_ext.color_blend_advanced = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_color_blend_advanced_ext.color_blend_advanced) * (attachmentCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_color_blend_advanced_ext.color_blend_advanced == NULL) goto err;
      memcpy((void*)cmd->u.set_color_blend_advanced_ext.color_blend_advanced, pColorBlendAdvanced, sizeof(*cmd->u.set_color_blend_advanced_ext.color_blend_advanced) * (attachmentCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_color_blend_advanced_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_provoking_vertex_mode_ext(struct vk_cmd_queue *queue,
                                          struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_provoking_vertex_mode_ext(struct vk_cmd_queue *queue
, VkProvokingVertexModeEXT provokingVertexMode
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_PROVOKING_VERTEX_MODE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_PROVOKING_VERTEX_MODE_EXT;
   cmd->u.set_provoking_vertex_mode_ext.provoking_vertex_mode = provokingVertexMode;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_line_rasterization_mode_ext(struct vk_cmd_queue *queue,
                                            struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_line_rasterization_mode_ext(struct vk_cmd_queue *queue
, VkLineRasterizationModeEXT lineRasterizationMode
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_LINE_RASTERIZATION_MODE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_LINE_RASTERIZATION_MODE_EXT;
   cmd->u.set_line_rasterization_mode_ext.line_rasterization_mode = lineRasterizationMode;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_line_stipple_enable_ext(struct vk_cmd_queue *queue,
                                        struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_line_stipple_enable_ext(struct vk_cmd_queue *queue
, VkBool32 stippledLineEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_LINE_STIPPLE_ENABLE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_LINE_STIPPLE_ENABLE_EXT;
   cmd->u.set_line_stipple_enable_ext.stippled_line_enable = stippledLineEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_depth_clip_negative_one_to_one_ext(struct vk_cmd_queue *queue,
                                                   struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_depth_clip_negative_one_to_one_ext(struct vk_cmd_queue *queue
, VkBool32 negativeOneToOne
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT;
   cmd->u.set_depth_clip_negative_one_to_one_ext.negative_one_to_one = negativeOneToOne;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_viewport_wscaling_enable_nv(struct vk_cmd_queue *queue,
                                            struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_viewport_wscaling_enable_nv(struct vk_cmd_queue *queue
, VkBool32 viewportWScalingEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_VIEWPORT_WSCALING_ENABLE_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_VIEWPORT_WSCALING_ENABLE_NV;
   cmd->u.set_viewport_wscaling_enable_nv.viewport_wscaling_enable = viewportWScalingEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_viewport_swizzle_nv(struct vk_cmd_queue *queue,
                                    struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkViewportSwizzleNV* )cmd->u.set_viewport_swizzle_nv.viewport_swizzles);
}

VkResult vk_enqueue_cmd_set_viewport_swizzle_nv(struct vk_cmd_queue *queue
, uint32_t firstViewport
, uint32_t viewportCount
, const VkViewportSwizzleNV* pViewportSwizzles
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_VIEWPORT_SWIZZLE_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_VIEWPORT_SWIZZLE_NV;
   cmd->u.set_viewport_swizzle_nv.first_viewport = firstViewport;
   cmd->u.set_viewport_swizzle_nv.viewport_count = viewportCount;
   if (pViewportSwizzles) {
      cmd->u.set_viewport_swizzle_nv.viewport_swizzles = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_viewport_swizzle_nv.viewport_swizzles) * (viewportCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_viewport_swizzle_nv.viewport_swizzles == NULL) goto err;
      memcpy((void*)cmd->u.set_viewport_swizzle_nv.viewport_swizzles, pViewportSwizzles, sizeof(*cmd->u.set_viewport_swizzle_nv.viewport_swizzles) * (viewportCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_viewport_swizzle_nv(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_coverage_to_color_enable_nv(struct vk_cmd_queue *queue,
                                            struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_coverage_to_color_enable_nv(struct vk_cmd_queue *queue
, VkBool32 coverageToColorEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_COVERAGE_TO_COLOR_ENABLE_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_COVERAGE_TO_COLOR_ENABLE_NV;
   cmd->u.set_coverage_to_color_enable_nv.coverage_to_color_enable = coverageToColorEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_coverage_to_color_location_nv(struct vk_cmd_queue *queue,
                                              struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_coverage_to_color_location_nv(struct vk_cmd_queue *queue
, uint32_t coverageToColorLocation
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_COVERAGE_TO_COLOR_LOCATION_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_COVERAGE_TO_COLOR_LOCATION_NV;
   cmd->u.set_coverage_to_color_location_nv.coverage_to_color_location = coverageToColorLocation;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_coverage_modulation_mode_nv(struct vk_cmd_queue *queue,
                                            struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_coverage_modulation_mode_nv(struct vk_cmd_queue *queue
, VkCoverageModulationModeNV coverageModulationMode
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_COVERAGE_MODULATION_MODE_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_COVERAGE_MODULATION_MODE_NV;
   cmd->u.set_coverage_modulation_mode_nv.coverage_modulation_mode = coverageModulationMode;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_coverage_modulation_table_enable_nv(struct vk_cmd_queue *queue,
                                                    struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_coverage_modulation_table_enable_nv(struct vk_cmd_queue *queue
, VkBool32 coverageModulationTableEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_COVERAGE_MODULATION_TABLE_ENABLE_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_COVERAGE_MODULATION_TABLE_ENABLE_NV;
   cmd->u.set_coverage_modulation_table_enable_nv.coverage_modulation_table_enable = coverageModulationTableEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_coverage_modulation_table_nv(struct vk_cmd_queue *queue,
                                             struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( float* )cmd->u.set_coverage_modulation_table_nv.coverage_modulation_table);
}

VkResult vk_enqueue_cmd_set_coverage_modulation_table_nv(struct vk_cmd_queue *queue
, uint32_t coverageModulationTableCount
, const float* pCoverageModulationTable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_COVERAGE_MODULATION_TABLE_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_COVERAGE_MODULATION_TABLE_NV;
   cmd->u.set_coverage_modulation_table_nv.coverage_modulation_table_count = coverageModulationTableCount;
   if (pCoverageModulationTable) {
      cmd->u.set_coverage_modulation_table_nv.coverage_modulation_table = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_coverage_modulation_table_nv.coverage_modulation_table) * (coverageModulationTableCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_coverage_modulation_table_nv.coverage_modulation_table == NULL) goto err;
      memcpy((void*)cmd->u.set_coverage_modulation_table_nv.coverage_modulation_table, pCoverageModulationTable, sizeof(*cmd->u.set_coverage_modulation_table_nv.coverage_modulation_table) * (coverageModulationTableCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_coverage_modulation_table_nv(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_shading_rate_image_enable_nv(struct vk_cmd_queue *queue,
                                             struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_shading_rate_image_enable_nv(struct vk_cmd_queue *queue
, VkBool32 shadingRateImageEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_SHADING_RATE_IMAGE_ENABLE_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_SHADING_RATE_IMAGE_ENABLE_NV;
   cmd->u.set_shading_rate_image_enable_nv.shading_rate_image_enable = shadingRateImageEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_coverage_reduction_mode_nv(struct vk_cmd_queue *queue,
                                           struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_coverage_reduction_mode_nv(struct vk_cmd_queue *queue
, VkCoverageReductionModeNV coverageReductionMode
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_COVERAGE_REDUCTION_MODE_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_COVERAGE_REDUCTION_MODE_NV;
   cmd->u.set_coverage_reduction_mode_nv.coverage_reduction_mode = coverageReductionMode;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_representative_fragment_test_enable_nv(struct vk_cmd_queue *queue,
                                                       struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_representative_fragment_test_enable_nv(struct vk_cmd_queue *queue
, VkBool32 representativeFragmentTestEnable
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV;
   cmd->u.set_representative_fragment_test_enable_nv.representative_fragment_test_enable = representativeFragmentTestEnable;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_copy_buffer2(struct vk_cmd_queue *queue,
                         struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.copy_buffer2.copy_buffer_info) {
      VkBufferCopy2 *pRegions1 = (void *)(cmd->u.copy_buffer2.copy_buffer_info->pRegions);
      if (cmd->u.copy_buffer2.copy_buffer_info->regionCount) {
      }
      vk_free(queue->alloc, pRegions1);
   }
   vk_free(queue->alloc, (void*)cmd->u.copy_buffer2.copy_buffer_info);

}

VkResult vk_enqueue_cmd_copy_buffer2(struct vk_cmd_queue *queue
, const VkCopyBufferInfo2* pCopyBufferInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_BUFFER2], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_BUFFER2;
   if (pCopyBufferInfo) {
      cmd->u.copy_buffer2.copy_buffer_info = vk_zalloc(queue->alloc, sizeof(VkCopyBufferInfo2), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.copy_buffer2.copy_buffer_info == NULL) goto err;
      VkCopyBufferInfo2 *tmp_dst1 = (void *)cmd->u.copy_buffer2.copy_buffer_info;
      VkCopyBufferInfo2 *tmp_src2 = (void *)pCopyBufferInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkCopyBufferInfo2));
      if (tmp_src2->pRegions) {
         tmp_dst1->pRegions = vk_zalloc(queue->alloc, sizeof(VkBufferCopy2) * tmp_src2->regionCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pRegions == NULL) goto err;
         VkBufferCopy2 *tmp_dst3 = (void *)tmp_dst1->pRegions;
         VkBufferCopy2 *tmp_src4 = (void *)tmp_src2->pRegions;
         memcpy(tmp_dst3, tmp_src4, sizeof(VkBufferCopy2) * tmp_src2->regionCount);
         for (uint32_t i5 = 0; i5 < tmp_src2->regionCount; i5++) {
            VkBufferCopy2 *tmp_dst6 = tmp_dst3 + i5; (void)tmp_dst6;
            VkBufferCopy2 *tmp_src7 = tmp_src4 + i5; (void)tmp_src7;
            }
         } else {
            tmp_dst1->pRegions = NULL;
         }
      } else {
         cmd->u.copy_buffer2.copy_buffer_info = NULL;
      }

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_copy_buffer2(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_copy_image2(struct vk_cmd_queue *queue,
                        struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.copy_image2.copy_image_info) {
      VkImageCopy2 *pRegions1 = (void *)(cmd->u.copy_image2.copy_image_info->pRegions);
      if (cmd->u.copy_image2.copy_image_info->regionCount) {
      }
      vk_free(queue->alloc, pRegions1);
   }
   vk_free(queue->alloc, (void*)cmd->u.copy_image2.copy_image_info);

}

VkResult vk_enqueue_cmd_copy_image2(struct vk_cmd_queue *queue
, const VkCopyImageInfo2* pCopyImageInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_IMAGE2], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_IMAGE2;
   if (pCopyImageInfo) {
      cmd->u.copy_image2.copy_image_info = vk_zalloc(queue->alloc, sizeof(VkCopyImageInfo2), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.copy_image2.copy_image_info == NULL) goto err;
      VkCopyImageInfo2 *tmp_dst1 = (void *)cmd->u.copy_image2.copy_image_info;
      VkCopyImageInfo2 *tmp_src2 = (void *)pCopyImageInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkCopyImageInfo2));
      if (tmp_src2->pRegions) {
         tmp_dst1->pRegions = vk_zalloc(queue->alloc, sizeof(VkImageCopy2) * tmp_src2->regionCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pRegions == NULL) goto err;
         VkImageCopy2 *tmp_dst3 = (void *)tmp_dst1->pRegions;
         VkImageCopy2 *tmp_src4 = (void *)tmp_src2->pRegions;
         memcpy(tmp_dst3, tmp_src4, sizeof(VkImageCopy2) * tmp_src2->regionCount);
         for (uint32_t i5 = 0; i5 < tmp_src2->regionCount; i5++) {
            VkImageCopy2 *tmp_dst6 = tmp_dst3 + i5; (void)tmp_dst6;
            VkImageCopy2 *tmp_src7 = tmp_src4 + i5; (void)tmp_src7;
            }
         } else {
            tmp_dst1->pRegions = NULL;
         }
      } else {
         cmd->u.copy_image2.copy_image_info = NULL;
      }

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_copy_image2(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_blit_image2(struct vk_cmd_queue *queue,
                        struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.blit_image2.blit_image_info) {
      const VkBaseInStructure *pnext1 = cmd->u.blit_image2.blit_image_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
      VkImageBlit2 *pRegions2 = (void *)(cmd->u.blit_image2.blit_image_info->pRegions);
      if (cmd->u.blit_image2.blit_image_info->regionCount) {
         const VkBaseInStructure *pnext3 = pRegions2->pNext;
         if (pnext3) {
            switch ((int32_t)pnext3->sType) {
            case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM: {
               vk_free(queue->alloc, (void*)pnext3);
               break;
            }
            }
         }
      }
      vk_free(queue->alloc, pRegions2);
   }
   vk_free(queue->alloc, (void*)cmd->u.blit_image2.blit_image_info);

}

VkResult vk_enqueue_cmd_blit_image2(struct vk_cmd_queue *queue
, const VkBlitImageInfo2* pBlitImageInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BLIT_IMAGE2], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BLIT_IMAGE2;
   if (pBlitImageInfo) {
      cmd->u.blit_image2.blit_image_info = vk_zalloc(queue->alloc, sizeof(VkBlitImageInfo2), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.blit_image2.blit_image_info == NULL) goto err;
      VkBlitImageInfo2 *tmp_dst1 = (void *)cmd->u.blit_image2.blit_image_info;
      VkBlitImageInfo2 *tmp_src2 = (void *)pBlitImageInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkBlitImageInfo2));
      const VkBaseInStructure *pnext = tmp_dst1->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkBlitImageCubicWeightsInfoQCOM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkBlitImageCubicWeightsInfoQCOM *tmp_dst3 = (void *)tmp_dst1->pNext;
               VkBlitImageCubicWeightsInfoQCOM *tmp_src4 = (void *)pnext;
               memcpy(tmp_dst3, tmp_src4, sizeof(VkBlitImageCubicWeightsInfoQCOM));
            } else {
               tmp_dst1->pNext = NULL;
            }
            break;
         }
      }
      if (tmp_src2->pRegions) {
         tmp_dst1->pRegions = vk_zalloc(queue->alloc, sizeof(VkImageBlit2) * tmp_src2->regionCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pRegions == NULL) goto err;
         VkImageBlit2 *tmp_dst5 = (void *)tmp_dst1->pRegions;
         VkImageBlit2 *tmp_src6 = (void *)tmp_src2->pRegions;
         memcpy(tmp_dst5, tmp_src6, sizeof(VkImageBlit2) * tmp_src2->regionCount);
         for (uint32_t i7 = 0; i7 < tmp_src2->regionCount; i7++) {
            VkImageBlit2 *tmp_dst8 = tmp_dst5 + i7; (void)tmp_dst8;
            VkImageBlit2 *tmp_src9 = tmp_src6 + i7; (void)tmp_src9;
            const VkBaseInStructure *pnext = tmp_dst8->pNext;
            if (pnext) {
               switch ((int32_t)pnext->sType) {
               case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
                  if (pnext) {
                     tmp_dst8->pNext = vk_zalloc(queue->alloc, sizeof(VkCopyCommandTransformInfoQCOM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst8->pNext == NULL) goto err;
                     VkCopyCommandTransformInfoQCOM *tmp_dst10 = (void *)tmp_dst8->pNext;
                     VkCopyCommandTransformInfoQCOM *tmp_src11 = (void *)pnext;
                     memcpy(tmp_dst10, tmp_src11, sizeof(VkCopyCommandTransformInfoQCOM));
                  } else {
                     tmp_dst8->pNext = NULL;
                  }
                  break;
               }
            }
            }
         } else {
            tmp_dst1->pRegions = NULL;
         }
      } else {
         cmd->u.blit_image2.blit_image_info = NULL;
      }

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_blit_image2(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_copy_buffer_to_image2(struct vk_cmd_queue *queue,
                                  struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.copy_buffer_to_image2.copy_buffer_to_image_info) {
      VkBufferImageCopy2 *pRegions1 = (void *)(cmd->u.copy_buffer_to_image2.copy_buffer_to_image_info->pRegions);
      if (cmd->u.copy_buffer_to_image2.copy_buffer_to_image_info->regionCount) {
         const VkBaseInStructure *pnext2 = pRegions1->pNext;
         if (pnext2) {
            switch ((int32_t)pnext2->sType) {
            case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM: {
               vk_free(queue->alloc, (void*)pnext2);
               break;
            }
            }
         }
      }
      vk_free(queue->alloc, pRegions1);
   }
   vk_free(queue->alloc, (void*)cmd->u.copy_buffer_to_image2.copy_buffer_to_image_info);

}

VkResult vk_enqueue_cmd_copy_buffer_to_image2(struct vk_cmd_queue *queue
, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_BUFFER_TO_IMAGE2], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_BUFFER_TO_IMAGE2;
   if (pCopyBufferToImageInfo) {
      cmd->u.copy_buffer_to_image2.copy_buffer_to_image_info = vk_zalloc(queue->alloc, sizeof(VkCopyBufferToImageInfo2), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.copy_buffer_to_image2.copy_buffer_to_image_info == NULL) goto err;
      VkCopyBufferToImageInfo2 *tmp_dst1 = (void *)cmd->u.copy_buffer_to_image2.copy_buffer_to_image_info;
      VkCopyBufferToImageInfo2 *tmp_src2 = (void *)pCopyBufferToImageInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkCopyBufferToImageInfo2));
      if (tmp_src2->pRegions) {
         tmp_dst1->pRegions = vk_zalloc(queue->alloc, sizeof(VkBufferImageCopy2) * tmp_src2->regionCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pRegions == NULL) goto err;
         VkBufferImageCopy2 *tmp_dst3 = (void *)tmp_dst1->pRegions;
         VkBufferImageCopy2 *tmp_src4 = (void *)tmp_src2->pRegions;
         memcpy(tmp_dst3, tmp_src4, sizeof(VkBufferImageCopy2) * tmp_src2->regionCount);
         for (uint32_t i5 = 0; i5 < tmp_src2->regionCount; i5++) {
            VkBufferImageCopy2 *tmp_dst6 = tmp_dst3 + i5; (void)tmp_dst6;
            VkBufferImageCopy2 *tmp_src7 = tmp_src4 + i5; (void)tmp_src7;
            const VkBaseInStructure *pnext = tmp_dst6->pNext;
            if (pnext) {
               switch ((int32_t)pnext->sType) {
               case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
                  if (pnext) {
                     tmp_dst6->pNext = vk_zalloc(queue->alloc, sizeof(VkCopyCommandTransformInfoQCOM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst6->pNext == NULL) goto err;
                     VkCopyCommandTransformInfoQCOM *tmp_dst8 = (void *)tmp_dst6->pNext;
                     VkCopyCommandTransformInfoQCOM *tmp_src9 = (void *)pnext;
                     memcpy(tmp_dst8, tmp_src9, sizeof(VkCopyCommandTransformInfoQCOM));
                  } else {
                     tmp_dst6->pNext = NULL;
                  }
                  break;
               }
            }
            }
         } else {
            tmp_dst1->pRegions = NULL;
         }
      } else {
         cmd->u.copy_buffer_to_image2.copy_buffer_to_image_info = NULL;
      }

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_copy_buffer_to_image2(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_copy_image_to_buffer2(struct vk_cmd_queue *queue,
                                  struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.copy_image_to_buffer2.copy_image_to_buffer_info) {
      VkBufferImageCopy2 *pRegions1 = (void *)(cmd->u.copy_image_to_buffer2.copy_image_to_buffer_info->pRegions);
      if (cmd->u.copy_image_to_buffer2.copy_image_to_buffer_info->regionCount) {
         const VkBaseInStructure *pnext2 = pRegions1->pNext;
         if (pnext2) {
            switch ((int32_t)pnext2->sType) {
            case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM: {
               vk_free(queue->alloc, (void*)pnext2);
               break;
            }
            }
         }
      }
      vk_free(queue->alloc, pRegions1);
   }
   vk_free(queue->alloc, (void*)cmd->u.copy_image_to_buffer2.copy_image_to_buffer_info);

}

VkResult vk_enqueue_cmd_copy_image_to_buffer2(struct vk_cmd_queue *queue
, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_IMAGE_TO_BUFFER2], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_IMAGE_TO_BUFFER2;
   if (pCopyImageToBufferInfo) {
      cmd->u.copy_image_to_buffer2.copy_image_to_buffer_info = vk_zalloc(queue->alloc, sizeof(VkCopyImageToBufferInfo2), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.copy_image_to_buffer2.copy_image_to_buffer_info == NULL) goto err;
      VkCopyImageToBufferInfo2 *tmp_dst1 = (void *)cmd->u.copy_image_to_buffer2.copy_image_to_buffer_info;
      VkCopyImageToBufferInfo2 *tmp_src2 = (void *)pCopyImageToBufferInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkCopyImageToBufferInfo2));
      if (tmp_src2->pRegions) {
         tmp_dst1->pRegions = vk_zalloc(queue->alloc, sizeof(VkBufferImageCopy2) * tmp_src2->regionCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pRegions == NULL) goto err;
         VkBufferImageCopy2 *tmp_dst3 = (void *)tmp_dst1->pRegions;
         VkBufferImageCopy2 *tmp_src4 = (void *)tmp_src2->pRegions;
         memcpy(tmp_dst3, tmp_src4, sizeof(VkBufferImageCopy2) * tmp_src2->regionCount);
         for (uint32_t i5 = 0; i5 < tmp_src2->regionCount; i5++) {
            VkBufferImageCopy2 *tmp_dst6 = tmp_dst3 + i5; (void)tmp_dst6;
            VkBufferImageCopy2 *tmp_src7 = tmp_src4 + i5; (void)tmp_src7;
            const VkBaseInStructure *pnext = tmp_dst6->pNext;
            if (pnext) {
               switch ((int32_t)pnext->sType) {
               case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
                  if (pnext) {
                     tmp_dst6->pNext = vk_zalloc(queue->alloc, sizeof(VkCopyCommandTransformInfoQCOM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst6->pNext == NULL) goto err;
                     VkCopyCommandTransformInfoQCOM *tmp_dst8 = (void *)tmp_dst6->pNext;
                     VkCopyCommandTransformInfoQCOM *tmp_src9 = (void *)pnext;
                     memcpy(tmp_dst8, tmp_src9, sizeof(VkCopyCommandTransformInfoQCOM));
                  } else {
                     tmp_dst6->pNext = NULL;
                  }
                  break;
               }
            }
            }
         } else {
            tmp_dst1->pRegions = NULL;
         }
      } else {
         cmd->u.copy_image_to_buffer2.copy_image_to_buffer_info = NULL;
      }

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_copy_image_to_buffer2(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_resolve_image2(struct vk_cmd_queue *queue,
                           struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.resolve_image2.resolve_image_info) {
      VkImageResolve2 *pRegions1 = (void *)(cmd->u.resolve_image2.resolve_image_info->pRegions);
      if (cmd->u.resolve_image2.resolve_image_info->regionCount) {
      }
      vk_free(queue->alloc, pRegions1);
   }
   vk_free(queue->alloc, (void*)cmd->u.resolve_image2.resolve_image_info);

}

VkResult vk_enqueue_cmd_resolve_image2(struct vk_cmd_queue *queue
, const VkResolveImageInfo2* pResolveImageInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_RESOLVE_IMAGE2], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_RESOLVE_IMAGE2;
   if (pResolveImageInfo) {
      cmd->u.resolve_image2.resolve_image_info = vk_zalloc(queue->alloc, sizeof(VkResolveImageInfo2), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.resolve_image2.resolve_image_info == NULL) goto err;
      VkResolveImageInfo2 *tmp_dst1 = (void *)cmd->u.resolve_image2.resolve_image_info;
      VkResolveImageInfo2 *tmp_src2 = (void *)pResolveImageInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkResolveImageInfo2));
      if (tmp_src2->pRegions) {
         tmp_dst1->pRegions = vk_zalloc(queue->alloc, sizeof(VkImageResolve2) * tmp_src2->regionCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pRegions == NULL) goto err;
         VkImageResolve2 *tmp_dst3 = (void *)tmp_dst1->pRegions;
         VkImageResolve2 *tmp_src4 = (void *)tmp_src2->pRegions;
         memcpy(tmp_dst3, tmp_src4, sizeof(VkImageResolve2) * tmp_src2->regionCount);
         for (uint32_t i5 = 0; i5 < tmp_src2->regionCount; i5++) {
            VkImageResolve2 *tmp_dst6 = tmp_dst3 + i5; (void)tmp_dst6;
            VkImageResolve2 *tmp_src7 = tmp_src4 + i5; (void)tmp_src7;
            }
         } else {
            tmp_dst1->pRegions = NULL;
         }
      } else {
         cmd->u.resolve_image2.resolve_image_info = NULL;
      }

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_resolve_image2(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_fragment_shading_rate_khr(struct vk_cmd_queue *queue,
                                          struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.set_fragment_shading_rate_khr.fragment_size) {
   }
   vk_free(queue->alloc, (void*)cmd->u.set_fragment_shading_rate_khr.fragment_size);

}

VkResult vk_enqueue_cmd_set_fragment_shading_rate_khr(struct vk_cmd_queue *queue
, const VkExtent2D*                           pFragmentSize
, const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_FRAGMENT_SHADING_RATE_KHR], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_FRAGMENT_SHADING_RATE_KHR;
   if (pFragmentSize) {
      cmd->u.set_fragment_shading_rate_khr.fragment_size = vk_zalloc(queue->alloc, sizeof(VkExtent2D), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.set_fragment_shading_rate_khr.fragment_size == NULL) goto err;
      VkExtent2D *tmp_dst1 = (void *)cmd->u.set_fragment_shading_rate_khr.fragment_size;
      VkExtent2D *tmp_src2 = (void *)pFragmentSize;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkExtent2D));
   } else {
      cmd->u.set_fragment_shading_rate_khr.fragment_size = NULL;
   }
   memcpy(cmd->u.set_fragment_shading_rate_khr.combiner_ops, combinerOps, sizeof(*combinerOps) * 2);

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_fragment_shading_rate_khr(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_fragment_shading_rate_enum_nv(struct vk_cmd_queue *queue,
                                              struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_set_fragment_shading_rate_enum_nv(struct vk_cmd_queue *queue
, VkFragmentShadingRateNV                     shadingRate
, const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_FRAGMENT_SHADING_RATE_ENUM_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_FRAGMENT_SHADING_RATE_ENUM_NV;
   cmd->u.set_fragment_shading_rate_enum_nv.shading_rate = shadingRate;
   memcpy(cmd->u.set_fragment_shading_rate_enum_nv.combiner_ops, combinerOps, sizeof(*combinerOps) * 2);

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_set_vertex_input_ext(struct vk_cmd_queue *queue,
                                 struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkVertexInputBindingDescription2EXT* )cmd->u.set_vertex_input_ext.vertex_binding_descriptions);
   vk_free(queue->alloc, ( VkVertexInputAttributeDescription2EXT* )cmd->u.set_vertex_input_ext.vertex_attribute_descriptions);
}

VkResult vk_enqueue_cmd_set_vertex_input_ext(struct vk_cmd_queue *queue
, uint32_t vertexBindingDescriptionCount
, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions
, uint32_t vertexAttributeDescriptionCount
, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_VERTEX_INPUT_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_VERTEX_INPUT_EXT;
   cmd->u.set_vertex_input_ext.vertex_binding_description_count = vertexBindingDescriptionCount;
   if (pVertexBindingDescriptions) {
      cmd->u.set_vertex_input_ext.vertex_binding_descriptions = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_vertex_input_ext.vertex_binding_descriptions) * (vertexBindingDescriptionCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_vertex_input_ext.vertex_binding_descriptions == NULL) goto err;
      memcpy((void*)cmd->u.set_vertex_input_ext.vertex_binding_descriptions, pVertexBindingDescriptions, sizeof(*cmd->u.set_vertex_input_ext.vertex_binding_descriptions) * (vertexBindingDescriptionCount));
   }
   cmd->u.set_vertex_input_ext.vertex_attribute_description_count = vertexAttributeDescriptionCount;
   if (pVertexAttributeDescriptions) {
      cmd->u.set_vertex_input_ext.vertex_attribute_descriptions = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_vertex_input_ext.vertex_attribute_descriptions) * (vertexAttributeDescriptionCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_vertex_input_ext.vertex_attribute_descriptions == NULL) goto err;
      memcpy((void*)cmd->u.set_vertex_input_ext.vertex_attribute_descriptions, pVertexAttributeDescriptions, sizeof(*cmd->u.set_vertex_input_ext.vertex_attribute_descriptions) * (vertexAttributeDescriptionCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_vertex_input_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_color_write_enable_ext(struct vk_cmd_queue *queue,
                                       struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkBool32*   )cmd->u.set_color_write_enable_ext.color_write_enables);
}

VkResult vk_enqueue_cmd_set_color_write_enable_ext(struct vk_cmd_queue *queue
, uint32_t                                attachmentCount
, const VkBool32*   pColorWriteEnables
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_COLOR_WRITE_ENABLE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_COLOR_WRITE_ENABLE_EXT;
   cmd->u.set_color_write_enable_ext.attachment_count = attachmentCount;
   if (pColorWriteEnables) {
      cmd->u.set_color_write_enable_ext.color_write_enables = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_color_write_enable_ext.color_write_enables) * (attachmentCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_color_write_enable_ext.color_write_enables == NULL) goto err;
      memcpy((void*)cmd->u.set_color_write_enable_ext.color_write_enables, pColorWriteEnables, sizeof(*cmd->u.set_color_write_enable_ext.color_write_enables) * (attachmentCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_color_write_enable_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_event2(struct vk_cmd_queue *queue,
                       struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.set_event2.dependency_info) {
      const VkBaseInStructure *pnext1 = cmd->u.set_event2.dependency_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_TENSOR_MEMORY_BARRIER_ARM: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_TENSOR_DEPENDENCY_INFO_ARM: {
            VkTensorMemoryBarrierARM *pTensorMemoryBarriers2 = (void *)(((VkTensorDependencyInfoARM *)pnext1)->pTensorMemoryBarriers);
            if (pTensorMemoryBarriers2) {
            }
            vk_free(queue->alloc, pTensorMemoryBarriers2);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
      VkMemoryBarrier2 *pMemoryBarriers3 = (void *)(cmd->u.set_event2.dependency_info->pMemoryBarriers);
      if (cmd->u.set_event2.dependency_info->memoryBarrierCount) {
      }
      vk_free(queue->alloc, pMemoryBarriers3);
      VkBufferMemoryBarrier2 *pBufferMemoryBarriers4 = (void *)(cmd->u.set_event2.dependency_info->pBufferMemoryBarriers);
      if (cmd->u.set_event2.dependency_info->bufferMemoryBarrierCount) {
         const VkBaseInStructure *pnext5 = pBufferMemoryBarriers4->pNext;
         if (pnext5) {
            switch ((int32_t)pnext5->sType) {
            case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR: {
               vk_free(queue->alloc, (void*)pnext5);
               break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT: {
               vk_free(queue->alloc, (void*)pnext5);
               break;
            }
            }
         }
      }
      vk_free(queue->alloc, pBufferMemoryBarriers4);
      VkImageMemoryBarrier2 *pImageMemoryBarriers6 = (void *)(cmd->u.set_event2.dependency_info->pImageMemoryBarriers);
      if (cmd->u.set_event2.dependency_info->imageMemoryBarrierCount) {
         const VkBaseInStructure *pnext7 = pImageMemoryBarriers6->pNext;
         if (pnext7) {
            switch ((int32_t)pnext7->sType) {
            case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT: {
               VkSampleLocationEXT *pSampleLocations8 = (void *)(((VkSampleLocationsInfoEXT *)pnext7)->pSampleLocations);
               if (((VkSampleLocationsInfoEXT *)pnext7)->sampleLocationsCount) {
               }
               vk_free(queue->alloc, pSampleLocations8);
               vk_free(queue->alloc, (void*)pnext7);
               break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR: {
               vk_free(queue->alloc, (void*)pnext7);
               break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT: {
               vk_free(queue->alloc, (void*)pnext7);
               break;
            }
            }
         }
      }
      vk_free(queue->alloc, pImageMemoryBarriers6);
   }
   vk_free(queue->alloc, (void*)cmd->u.set_event2.dependency_info);

}

VkResult vk_enqueue_cmd_set_event2(struct vk_cmd_queue *queue
, VkEvent                                             event
, const VkDependencyInfo*                             pDependencyInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_EVENT2], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_EVENT2;
   cmd->u.set_event2.event = event;
   if (pDependencyInfo) {
      cmd->u.set_event2.dependency_info = vk_zalloc(queue->alloc, sizeof(VkDependencyInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.set_event2.dependency_info == NULL) goto err;
      VkDependencyInfo *tmp_dst1 = (void *)cmd->u.set_event2.dependency_info;
      VkDependencyInfo *tmp_src2 = (void *)pDependencyInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkDependencyInfo));
      const VkBaseInStructure *pnext = tmp_dst1->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_TENSOR_MEMORY_BARRIER_ARM:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkTensorMemoryBarrierARM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkTensorMemoryBarrierARM *tmp_dst3 = (void *)tmp_dst1->pNext;
               VkTensorMemoryBarrierARM *tmp_src4 = (void *)pnext;
               memcpy(tmp_dst3, tmp_src4, sizeof(VkTensorMemoryBarrierARM));
            } else {
               tmp_dst1->pNext = NULL;
            }
            break;
         case VK_STRUCTURE_TYPE_TENSOR_DEPENDENCY_INFO_ARM:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkTensorDependencyInfoARM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkTensorDependencyInfoARM *tmp_dst5 = (void *)tmp_dst1->pNext;
               VkTensorDependencyInfoARM *tmp_src6 = (void *)pnext;
               memcpy(tmp_dst5, tmp_src6, sizeof(VkTensorDependencyInfoARM));
               if (tmp_src6->pTensorMemoryBarriers) {
                  tmp_dst5->pTensorMemoryBarriers = vk_zalloc(queue->alloc, sizeof(VkTensorMemoryBarrierARM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst5->pTensorMemoryBarriers == NULL) goto err;
                  VkTensorMemoryBarrierARM *tmp_dst7 = (void *)tmp_dst5->pTensorMemoryBarriers;
                  VkTensorMemoryBarrierARM *tmp_src8 = (void *)tmp_src6->pTensorMemoryBarriers;
                  memcpy(tmp_dst7, tmp_src8, sizeof(VkTensorMemoryBarrierARM));
               } else {
                  tmp_dst5->pTensorMemoryBarriers = NULL;
               }
            } else {
               tmp_dst1->pNext = NULL;
            }
            break;
         }
      }
      if (tmp_src2->pMemoryBarriers) {
         tmp_dst1->pMemoryBarriers = vk_zalloc(queue->alloc, sizeof(VkMemoryBarrier2) * tmp_src2->memoryBarrierCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pMemoryBarriers == NULL) goto err;
         VkMemoryBarrier2 *tmp_dst9 = (void *)tmp_dst1->pMemoryBarriers;
         VkMemoryBarrier2 *tmp_src10 = (void *)tmp_src2->pMemoryBarriers;
         memcpy(tmp_dst9, tmp_src10, sizeof(VkMemoryBarrier2) * tmp_src2->memoryBarrierCount);
         for (uint32_t i11 = 0; i11 < tmp_src2->memoryBarrierCount; i11++) {
            VkMemoryBarrier2 *tmp_dst12 = tmp_dst9 + i11; (void)tmp_dst12;
            VkMemoryBarrier2 *tmp_src13 = tmp_src10 + i11; (void)tmp_src13;
            }
         } else {
            tmp_dst1->pMemoryBarriers = NULL;
         }
         if (tmp_src2->pBufferMemoryBarriers) {
            tmp_dst1->pBufferMemoryBarriers = vk_zalloc(queue->alloc, sizeof(VkBufferMemoryBarrier2) * tmp_src2->bufferMemoryBarrierCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
            if (tmp_dst1->pBufferMemoryBarriers == NULL) goto err;
            VkBufferMemoryBarrier2 *tmp_dst14 = (void *)tmp_dst1->pBufferMemoryBarriers;
            VkBufferMemoryBarrier2 *tmp_src15 = (void *)tmp_src2->pBufferMemoryBarriers;
            memcpy(tmp_dst14, tmp_src15, sizeof(VkBufferMemoryBarrier2) * tmp_src2->bufferMemoryBarrierCount);
            for (uint32_t i16 = 0; i16 < tmp_src2->bufferMemoryBarrierCount; i16++) {
               VkBufferMemoryBarrier2 *tmp_dst17 = tmp_dst14 + i16; (void)tmp_dst17;
               VkBufferMemoryBarrier2 *tmp_src18 = tmp_src15 + i16; (void)tmp_src18;
               const VkBaseInStructure *pnext = tmp_dst17->pNext;
               if (pnext) {
                  switch ((int32_t)pnext->sType) {
                  case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR:
                     if (pnext) {
                        tmp_dst17->pNext = vk_zalloc(queue->alloc, sizeof(VkMemoryBarrierAccessFlags3KHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst17->pNext == NULL) goto err;
                        VkMemoryBarrierAccessFlags3KHR *tmp_dst19 = (void *)tmp_dst17->pNext;
                        VkMemoryBarrierAccessFlags3KHR *tmp_src20 = (void *)pnext;
                        memcpy(tmp_dst19, tmp_src20, sizeof(VkMemoryBarrierAccessFlags3KHR));
                     } else {
                        tmp_dst17->pNext = NULL;
                     }
                     break;
                  case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT:
                     if (pnext) {
                        tmp_dst17->pNext = vk_zalloc(queue->alloc, sizeof(VkExternalMemoryAcquireUnmodifiedEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst17->pNext == NULL) goto err;
                        VkExternalMemoryAcquireUnmodifiedEXT *tmp_dst21 = (void *)tmp_dst17->pNext;
                        VkExternalMemoryAcquireUnmodifiedEXT *tmp_src22 = (void *)pnext;
                        memcpy(tmp_dst21, tmp_src22, sizeof(VkExternalMemoryAcquireUnmodifiedEXT));
                     } else {
                        tmp_dst17->pNext = NULL;
                     }
                     break;
                  }
               }
               }
            } else {
               tmp_dst1->pBufferMemoryBarriers = NULL;
            }
            if (tmp_src2->pImageMemoryBarriers) {
               tmp_dst1->pImageMemoryBarriers = vk_zalloc(queue->alloc, sizeof(VkImageMemoryBarrier2) * tmp_src2->imageMemoryBarrierCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pImageMemoryBarriers == NULL) goto err;
               VkImageMemoryBarrier2 *tmp_dst23 = (void *)tmp_dst1->pImageMemoryBarriers;
               VkImageMemoryBarrier2 *tmp_src24 = (void *)tmp_src2->pImageMemoryBarriers;
               memcpy(tmp_dst23, tmp_src24, sizeof(VkImageMemoryBarrier2) * tmp_src2->imageMemoryBarrierCount);
               for (uint32_t i25 = 0; i25 < tmp_src2->imageMemoryBarrierCount; i25++) {
                  VkImageMemoryBarrier2 *tmp_dst26 = tmp_dst23 + i25; (void)tmp_dst26;
                  VkImageMemoryBarrier2 *tmp_src27 = tmp_src24 + i25; (void)tmp_src27;
                  const VkBaseInStructure *pnext = tmp_dst26->pNext;
                  if (pnext) {
                     switch ((int32_t)pnext->sType) {
                     case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
                        if (pnext) {
                           tmp_dst26->pNext = vk_zalloc(queue->alloc, sizeof(VkSampleLocationsInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst26->pNext == NULL) goto err;
                           VkSampleLocationsInfoEXT *tmp_dst28 = (void *)tmp_dst26->pNext;
                           VkSampleLocationsInfoEXT *tmp_src29 = (void *)pnext;
                           memcpy(tmp_dst28, tmp_src29, sizeof(VkSampleLocationsInfoEXT));
                           if (tmp_src29->pSampleLocations) {
                              tmp_dst28->pSampleLocations = vk_zalloc(queue->alloc, sizeof(VkSampleLocationEXT) * tmp_src29->sampleLocationsCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst28->pSampleLocations == NULL) goto err;
                              VkSampleLocationEXT *tmp_dst30 = (void *)tmp_dst28->pSampleLocations;
                              VkSampleLocationEXT *tmp_src31 = (void *)tmp_src29->pSampleLocations;
                              memcpy(tmp_dst30, tmp_src31, sizeof(VkSampleLocationEXT) * tmp_src29->sampleLocationsCount);
                              for (uint32_t i32 = 0; i32 < tmp_src29->sampleLocationsCount; i32++) {
                                 VkSampleLocationEXT *tmp_dst33 = tmp_dst30 + i32; (void)tmp_dst33;
                                 VkSampleLocationEXT *tmp_src34 = tmp_src31 + i32; (void)tmp_src34;
                                 }
                              } else {
                                 tmp_dst28->pSampleLocations = NULL;
                              }
                           } else {
                              tmp_dst26->pNext = NULL;
                           }
                           break;
                        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR:
                           if (pnext) {
                              tmp_dst26->pNext = vk_zalloc(queue->alloc, sizeof(VkMemoryBarrierAccessFlags3KHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst26->pNext == NULL) goto err;
                              VkMemoryBarrierAccessFlags3KHR *tmp_dst35 = (void *)tmp_dst26->pNext;
                              VkMemoryBarrierAccessFlags3KHR *tmp_src36 = (void *)pnext;
                              memcpy(tmp_dst35, tmp_src36, sizeof(VkMemoryBarrierAccessFlags3KHR));
                           } else {
                              tmp_dst26->pNext = NULL;
                           }
                           break;
                        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT:
                           if (pnext) {
                              tmp_dst26->pNext = vk_zalloc(queue->alloc, sizeof(VkExternalMemoryAcquireUnmodifiedEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst26->pNext == NULL) goto err;
                              VkExternalMemoryAcquireUnmodifiedEXT *tmp_dst37 = (void *)tmp_dst26->pNext;
                              VkExternalMemoryAcquireUnmodifiedEXT *tmp_src38 = (void *)pnext;
                              memcpy(tmp_dst37, tmp_src38, sizeof(VkExternalMemoryAcquireUnmodifiedEXT));
                           } else {
                              tmp_dst26->pNext = NULL;
                           }
                           break;
                        }
                     }
                     }
                  } else {
                     tmp_dst1->pImageMemoryBarriers = NULL;
                  }
               } else {
                  cmd->u.set_event2.dependency_info = NULL;
               }

               list_addtail(&cmd->cmd_link, &queue->cmds);
               return VK_SUCCESS;

err:
               if (cmd)
                  vk_free_cmd_set_event2(queue, cmd);
               return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_reset_event2(struct vk_cmd_queue *queue,
                         struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_reset_event2(struct vk_cmd_queue *queue
, VkEvent                                             event
, VkPipelineStageFlags2               stageMask
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_RESET_EVENT2], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_RESET_EVENT2;
   cmd->u.reset_event2.event = event;
   cmd->u.reset_event2.stage_mask = stageMask;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_wait_events2(struct vk_cmd_queue *queue,
                         struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkEvent*                     )cmd->u.wait_events2.events);
   vk_free(queue->alloc, ( VkDependencyInfo*            )cmd->u.wait_events2.dependency_infos);
}

VkResult vk_enqueue_cmd_wait_events2(struct vk_cmd_queue *queue
, uint32_t                                            eventCount
, const VkEvent*                     pEvents
, const VkDependencyInfo*            pDependencyInfos
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_WAIT_EVENTS2], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_WAIT_EVENTS2;
   cmd->u.wait_events2.event_count = eventCount;
   if (pEvents) {
      cmd->u.wait_events2.events = vk_zalloc(queue->alloc, sizeof(*cmd->u.wait_events2.events) * (eventCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.wait_events2.events == NULL) goto err;
      memcpy((void*)cmd->u.wait_events2.events, pEvents, sizeof(*cmd->u.wait_events2.events) * (eventCount));
   }
   if (pDependencyInfos) {
      cmd->u.wait_events2.dependency_infos = vk_zalloc(queue->alloc, sizeof(*cmd->u.wait_events2.dependency_infos) * (eventCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.wait_events2.dependency_infos == NULL) goto err;
      memcpy((void*)cmd->u.wait_events2.dependency_infos, pDependencyInfos, sizeof(*cmd->u.wait_events2.dependency_infos) * (eventCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_wait_events2(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_pipeline_barrier2(struct vk_cmd_queue *queue,
                              struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.pipeline_barrier2.dependency_info) {
      const VkBaseInStructure *pnext1 = cmd->u.pipeline_barrier2.dependency_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_TENSOR_MEMORY_BARRIER_ARM: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_TENSOR_DEPENDENCY_INFO_ARM: {
            VkTensorMemoryBarrierARM *pTensorMemoryBarriers2 = (void *)(((VkTensorDependencyInfoARM *)pnext1)->pTensorMemoryBarriers);
            if (pTensorMemoryBarriers2) {
            }
            vk_free(queue->alloc, pTensorMemoryBarriers2);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
      VkMemoryBarrier2 *pMemoryBarriers3 = (void *)(cmd->u.pipeline_barrier2.dependency_info->pMemoryBarriers);
      if (cmd->u.pipeline_barrier2.dependency_info->memoryBarrierCount) {
      }
      vk_free(queue->alloc, pMemoryBarriers3);
      VkBufferMemoryBarrier2 *pBufferMemoryBarriers4 = (void *)(cmd->u.pipeline_barrier2.dependency_info->pBufferMemoryBarriers);
      if (cmd->u.pipeline_barrier2.dependency_info->bufferMemoryBarrierCount) {
         const VkBaseInStructure *pnext5 = pBufferMemoryBarriers4->pNext;
         if (pnext5) {
            switch ((int32_t)pnext5->sType) {
            case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR: {
               vk_free(queue->alloc, (void*)pnext5);
               break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT: {
               vk_free(queue->alloc, (void*)pnext5);
               break;
            }
            }
         }
      }
      vk_free(queue->alloc, pBufferMemoryBarriers4);
      VkImageMemoryBarrier2 *pImageMemoryBarriers6 = (void *)(cmd->u.pipeline_barrier2.dependency_info->pImageMemoryBarriers);
      if (cmd->u.pipeline_barrier2.dependency_info->imageMemoryBarrierCount) {
         const VkBaseInStructure *pnext7 = pImageMemoryBarriers6->pNext;
         if (pnext7) {
            switch ((int32_t)pnext7->sType) {
            case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT: {
               VkSampleLocationEXT *pSampleLocations8 = (void *)(((VkSampleLocationsInfoEXT *)pnext7)->pSampleLocations);
               if (((VkSampleLocationsInfoEXT *)pnext7)->sampleLocationsCount) {
               }
               vk_free(queue->alloc, pSampleLocations8);
               vk_free(queue->alloc, (void*)pnext7);
               break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR: {
               vk_free(queue->alloc, (void*)pnext7);
               break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT: {
               vk_free(queue->alloc, (void*)pnext7);
               break;
            }
            }
         }
      }
      vk_free(queue->alloc, pImageMemoryBarriers6);
   }
   vk_free(queue->alloc, (void*)cmd->u.pipeline_barrier2.dependency_info);

}

VkResult vk_enqueue_cmd_pipeline_barrier2(struct vk_cmd_queue *queue
, const VkDependencyInfo*                             pDependencyInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_PIPELINE_BARRIER2], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_PIPELINE_BARRIER2;
   if (pDependencyInfo) {
      cmd->u.pipeline_barrier2.dependency_info = vk_zalloc(queue->alloc, sizeof(VkDependencyInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.pipeline_barrier2.dependency_info == NULL) goto err;
      VkDependencyInfo *tmp_dst1 = (void *)cmd->u.pipeline_barrier2.dependency_info;
      VkDependencyInfo *tmp_src2 = (void *)pDependencyInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkDependencyInfo));
      const VkBaseInStructure *pnext = tmp_dst1->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_TENSOR_MEMORY_BARRIER_ARM:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkTensorMemoryBarrierARM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkTensorMemoryBarrierARM *tmp_dst3 = (void *)tmp_dst1->pNext;
               VkTensorMemoryBarrierARM *tmp_src4 = (void *)pnext;
               memcpy(tmp_dst3, tmp_src4, sizeof(VkTensorMemoryBarrierARM));
            } else {
               tmp_dst1->pNext = NULL;
            }
            break;
         case VK_STRUCTURE_TYPE_TENSOR_DEPENDENCY_INFO_ARM:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkTensorDependencyInfoARM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkTensorDependencyInfoARM *tmp_dst5 = (void *)tmp_dst1->pNext;
               VkTensorDependencyInfoARM *tmp_src6 = (void *)pnext;
               memcpy(tmp_dst5, tmp_src6, sizeof(VkTensorDependencyInfoARM));
               if (tmp_src6->pTensorMemoryBarriers) {
                  tmp_dst5->pTensorMemoryBarriers = vk_zalloc(queue->alloc, sizeof(VkTensorMemoryBarrierARM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst5->pTensorMemoryBarriers == NULL) goto err;
                  VkTensorMemoryBarrierARM *tmp_dst7 = (void *)tmp_dst5->pTensorMemoryBarriers;
                  VkTensorMemoryBarrierARM *tmp_src8 = (void *)tmp_src6->pTensorMemoryBarriers;
                  memcpy(tmp_dst7, tmp_src8, sizeof(VkTensorMemoryBarrierARM));
               } else {
                  tmp_dst5->pTensorMemoryBarriers = NULL;
               }
            } else {
               tmp_dst1->pNext = NULL;
            }
            break;
         }
      }
      if (tmp_src2->pMemoryBarriers) {
         tmp_dst1->pMemoryBarriers = vk_zalloc(queue->alloc, sizeof(VkMemoryBarrier2) * tmp_src2->memoryBarrierCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pMemoryBarriers == NULL) goto err;
         VkMemoryBarrier2 *tmp_dst9 = (void *)tmp_dst1->pMemoryBarriers;
         VkMemoryBarrier2 *tmp_src10 = (void *)tmp_src2->pMemoryBarriers;
         memcpy(tmp_dst9, tmp_src10, sizeof(VkMemoryBarrier2) * tmp_src2->memoryBarrierCount);
         for (uint32_t i11 = 0; i11 < tmp_src2->memoryBarrierCount; i11++) {
            VkMemoryBarrier2 *tmp_dst12 = tmp_dst9 + i11; (void)tmp_dst12;
            VkMemoryBarrier2 *tmp_src13 = tmp_src10 + i11; (void)tmp_src13;
            }
         } else {
            tmp_dst1->pMemoryBarriers = NULL;
         }
         if (tmp_src2->pBufferMemoryBarriers) {
            tmp_dst1->pBufferMemoryBarriers = vk_zalloc(queue->alloc, sizeof(VkBufferMemoryBarrier2) * tmp_src2->bufferMemoryBarrierCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
            if (tmp_dst1->pBufferMemoryBarriers == NULL) goto err;
            VkBufferMemoryBarrier2 *tmp_dst14 = (void *)tmp_dst1->pBufferMemoryBarriers;
            VkBufferMemoryBarrier2 *tmp_src15 = (void *)tmp_src2->pBufferMemoryBarriers;
            memcpy(tmp_dst14, tmp_src15, sizeof(VkBufferMemoryBarrier2) * tmp_src2->bufferMemoryBarrierCount);
            for (uint32_t i16 = 0; i16 < tmp_src2->bufferMemoryBarrierCount; i16++) {
               VkBufferMemoryBarrier2 *tmp_dst17 = tmp_dst14 + i16; (void)tmp_dst17;
               VkBufferMemoryBarrier2 *tmp_src18 = tmp_src15 + i16; (void)tmp_src18;
               const VkBaseInStructure *pnext = tmp_dst17->pNext;
               if (pnext) {
                  switch ((int32_t)pnext->sType) {
                  case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR:
                     if (pnext) {
                        tmp_dst17->pNext = vk_zalloc(queue->alloc, sizeof(VkMemoryBarrierAccessFlags3KHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst17->pNext == NULL) goto err;
                        VkMemoryBarrierAccessFlags3KHR *tmp_dst19 = (void *)tmp_dst17->pNext;
                        VkMemoryBarrierAccessFlags3KHR *tmp_src20 = (void *)pnext;
                        memcpy(tmp_dst19, tmp_src20, sizeof(VkMemoryBarrierAccessFlags3KHR));
                     } else {
                        tmp_dst17->pNext = NULL;
                     }
                     break;
                  case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT:
                     if (pnext) {
                        tmp_dst17->pNext = vk_zalloc(queue->alloc, sizeof(VkExternalMemoryAcquireUnmodifiedEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst17->pNext == NULL) goto err;
                        VkExternalMemoryAcquireUnmodifiedEXT *tmp_dst21 = (void *)tmp_dst17->pNext;
                        VkExternalMemoryAcquireUnmodifiedEXT *tmp_src22 = (void *)pnext;
                        memcpy(tmp_dst21, tmp_src22, sizeof(VkExternalMemoryAcquireUnmodifiedEXT));
                     } else {
                        tmp_dst17->pNext = NULL;
                     }
                     break;
                  }
               }
               }
            } else {
               tmp_dst1->pBufferMemoryBarriers = NULL;
            }
            if (tmp_src2->pImageMemoryBarriers) {
               tmp_dst1->pImageMemoryBarriers = vk_zalloc(queue->alloc, sizeof(VkImageMemoryBarrier2) * tmp_src2->imageMemoryBarrierCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pImageMemoryBarriers == NULL) goto err;
               VkImageMemoryBarrier2 *tmp_dst23 = (void *)tmp_dst1->pImageMemoryBarriers;
               VkImageMemoryBarrier2 *tmp_src24 = (void *)tmp_src2->pImageMemoryBarriers;
               memcpy(tmp_dst23, tmp_src24, sizeof(VkImageMemoryBarrier2) * tmp_src2->imageMemoryBarrierCount);
               for (uint32_t i25 = 0; i25 < tmp_src2->imageMemoryBarrierCount; i25++) {
                  VkImageMemoryBarrier2 *tmp_dst26 = tmp_dst23 + i25; (void)tmp_dst26;
                  VkImageMemoryBarrier2 *tmp_src27 = tmp_src24 + i25; (void)tmp_src27;
                  const VkBaseInStructure *pnext = tmp_dst26->pNext;
                  if (pnext) {
                     switch ((int32_t)pnext->sType) {
                     case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
                        if (pnext) {
                           tmp_dst26->pNext = vk_zalloc(queue->alloc, sizeof(VkSampleLocationsInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst26->pNext == NULL) goto err;
                           VkSampleLocationsInfoEXT *tmp_dst28 = (void *)tmp_dst26->pNext;
                           VkSampleLocationsInfoEXT *tmp_src29 = (void *)pnext;
                           memcpy(tmp_dst28, tmp_src29, sizeof(VkSampleLocationsInfoEXT));
                           if (tmp_src29->pSampleLocations) {
                              tmp_dst28->pSampleLocations = vk_zalloc(queue->alloc, sizeof(VkSampleLocationEXT) * tmp_src29->sampleLocationsCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst28->pSampleLocations == NULL) goto err;
                              VkSampleLocationEXT *tmp_dst30 = (void *)tmp_dst28->pSampleLocations;
                              VkSampleLocationEXT *tmp_src31 = (void *)tmp_src29->pSampleLocations;
                              memcpy(tmp_dst30, tmp_src31, sizeof(VkSampleLocationEXT) * tmp_src29->sampleLocationsCount);
                              for (uint32_t i32 = 0; i32 < tmp_src29->sampleLocationsCount; i32++) {
                                 VkSampleLocationEXT *tmp_dst33 = tmp_dst30 + i32; (void)tmp_dst33;
                                 VkSampleLocationEXT *tmp_src34 = tmp_src31 + i32; (void)tmp_src34;
                                 }
                              } else {
                                 tmp_dst28->pSampleLocations = NULL;
                              }
                           } else {
                              tmp_dst26->pNext = NULL;
                           }
                           break;
                        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR:
                           if (pnext) {
                              tmp_dst26->pNext = vk_zalloc(queue->alloc, sizeof(VkMemoryBarrierAccessFlags3KHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst26->pNext == NULL) goto err;
                              VkMemoryBarrierAccessFlags3KHR *tmp_dst35 = (void *)tmp_dst26->pNext;
                              VkMemoryBarrierAccessFlags3KHR *tmp_src36 = (void *)pnext;
                              memcpy(tmp_dst35, tmp_src36, sizeof(VkMemoryBarrierAccessFlags3KHR));
                           } else {
                              tmp_dst26->pNext = NULL;
                           }
                           break;
                        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT:
                           if (pnext) {
                              tmp_dst26->pNext = vk_zalloc(queue->alloc, sizeof(VkExternalMemoryAcquireUnmodifiedEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst26->pNext == NULL) goto err;
                              VkExternalMemoryAcquireUnmodifiedEXT *tmp_dst37 = (void *)tmp_dst26->pNext;
                              VkExternalMemoryAcquireUnmodifiedEXT *tmp_src38 = (void *)pnext;
                              memcpy(tmp_dst37, tmp_src38, sizeof(VkExternalMemoryAcquireUnmodifiedEXT));
                           } else {
                              tmp_dst26->pNext = NULL;
                           }
                           break;
                        }
                     }
                     }
                  } else {
                     tmp_dst1->pImageMemoryBarriers = NULL;
                  }
               } else {
                  cmd->u.pipeline_barrier2.dependency_info = NULL;
               }

               list_addtail(&cmd->cmd_link, &queue->cmds);
               return VK_SUCCESS;

err:
               if (cmd)
                  vk_free_cmd_pipeline_barrier2(queue, cmd);
               return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_write_timestamp2(struct vk_cmd_queue *queue,
                             struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_write_timestamp2(struct vk_cmd_queue *queue
, VkPipelineStageFlags2               stage
, VkQueryPool                                         queryPool
, uint32_t                                            query
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_WRITE_TIMESTAMP2], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_WRITE_TIMESTAMP2;
   cmd->u.write_timestamp2.stage = stage;
   cmd->u.write_timestamp2.query_pool = queryPool;
   cmd->u.write_timestamp2.query = query;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_write_buffer_marker2_amd(struct vk_cmd_queue *queue,
                                     struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_write_buffer_marker2_amd(struct vk_cmd_queue *queue
, VkPipelineStageFlags2               stage
, VkBuffer                                            dstBuffer
, VkDeviceSize                                        dstOffset
, uint32_t                                            marker
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_WRITE_BUFFER_MARKER2_AMD], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_WRITE_BUFFER_MARKER2_AMD;
   cmd->u.write_buffer_marker2_amd.stage = stage;
   cmd->u.write_buffer_marker2_amd.dst_buffer = dstBuffer;
   cmd->u.write_buffer_marker2_amd.dst_offset = dstOffset;
   cmd->u.write_buffer_marker2_amd.marker = marker;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_decode_video_khr(struct vk_cmd_queue *queue,
                             struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.decode_video_khr.decode_info) {
      const VkBaseInStructure *pnext1 = cmd->u.decode_video_khr.decode_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_INLINE_SESSION_PARAMETERS_INFO_KHR: {
            StdVideoH264SequenceParameterSet *pStdSPS2 = (void *)(((VkVideoDecodeH264InlineSessionParametersInfoKHR *)pnext1)->pStdSPS);
            vk_free(queue->alloc, pStdSPS2);
            StdVideoH264PictureParameterSet *pStdPPS3 = (void *)(((VkVideoDecodeH264InlineSessionParametersInfoKHR *)pnext1)->pStdPPS);
            vk_free(queue->alloc, pStdPPS3);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR: {
            StdVideoDecodeH264PictureInfo *pStdPictureInfo4 = (void *)(((VkVideoDecodeH264PictureInfoKHR *)pnext1)->pStdPictureInfo);
            vk_free(queue->alloc, pStdPictureInfo4);
            uint32_t *pSliceOffsets5 = (void *)(((VkVideoDecodeH264PictureInfoKHR *)pnext1)->pSliceOffsets);
            if (((VkVideoDecodeH264PictureInfoKHR *)pnext1)->sliceCount) {
            }
            vk_free(queue->alloc, pSliceOffsets5);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_INLINE_SESSION_PARAMETERS_INFO_KHR: {
            StdVideoH265VideoParameterSet *pStdVPS6 = (void *)(((VkVideoDecodeH265InlineSessionParametersInfoKHR *)pnext1)->pStdVPS);
            vk_free(queue->alloc, pStdVPS6);
            StdVideoH265SequenceParameterSet *pStdSPS7 = (void *)(((VkVideoDecodeH265InlineSessionParametersInfoKHR *)pnext1)->pStdSPS);
            vk_free(queue->alloc, pStdSPS7);
            StdVideoH265PictureParameterSet *pStdPPS8 = (void *)(((VkVideoDecodeH265InlineSessionParametersInfoKHR *)pnext1)->pStdPPS);
            vk_free(queue->alloc, pStdPPS8);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR: {
            StdVideoDecodeH265PictureInfo *pStdPictureInfo9 = (void *)(((VkVideoDecodeH265PictureInfoKHR *)pnext1)->pStdPictureInfo);
            vk_free(queue->alloc, pStdPictureInfo9);
            uint32_t *pSliceSegmentOffsets10 = (void *)(((VkVideoDecodeH265PictureInfoKHR *)pnext1)->pSliceSegmentOffsets);
            if (((VkVideoDecodeH265PictureInfoKHR *)pnext1)->sliceSegmentCount) {
            }
            vk_free(queue->alloc, pSliceSegmentOffsets10);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PICTURE_INFO_KHR: {
            StdVideoDecodeVP9PictureInfo *pStdPictureInfo11 = (void *)(((VkVideoDecodeVP9PictureInfoKHR *)pnext1)->pStdPictureInfo);
            vk_free(queue->alloc, pStdPictureInfo11);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_INLINE_SESSION_PARAMETERS_INFO_KHR: {
            StdVideoAV1SequenceHeader *pStdSequenceHeader12 = (void *)(((VkVideoDecodeAV1InlineSessionParametersInfoKHR *)pnext1)->pStdSequenceHeader);
            vk_free(queue->alloc, pStdSequenceHeader12);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR: {
            StdVideoDecodeAV1PictureInfo *pStdPictureInfo13 = (void *)(((VkVideoDecodeAV1PictureInfoKHR *)pnext1)->pStdPictureInfo);
            vk_free(queue->alloc, pStdPictureInfo13);
            uint32_t *pTileOffsets14 = (void *)(((VkVideoDecodeAV1PictureInfoKHR *)pnext1)->pTileOffsets);
            if (((VkVideoDecodeAV1PictureInfoKHR *)pnext1)->tileCount) {
            }
            vk_free(queue->alloc, pTileOffsets14);
            uint32_t *pTileSizes15 = (void *)(((VkVideoDecodeAV1PictureInfoKHR *)pnext1)->pTileSizes);
            if (((VkVideoDecodeAV1PictureInfoKHR *)pnext1)->tileCount) {
            }
            vk_free(queue->alloc, pTileSizes15);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
      VkVideoReferenceSlotInfoKHR *pSetupReferenceSlot16 = (void *)(cmd->u.decode_video_khr.decode_info->pSetupReferenceSlot);
      if (pSetupReferenceSlot16) {
         const VkBaseInStructure *pnext17 = pSetupReferenceSlot16->pNext;
         if (pnext17) {
            switch ((int32_t)pnext17->sType) {
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR: {
               StdVideoDecodeH264ReferenceInfo *pStdReferenceInfo18 = (void *)(((VkVideoDecodeH264DpbSlotInfoKHR *)pnext17)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo18);
               vk_free(queue->alloc, (void*)pnext17);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR: {
               StdVideoDecodeH265ReferenceInfo *pStdReferenceInfo19 = (void *)(((VkVideoDecodeH265DpbSlotInfoKHR *)pnext17)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo19);
               vk_free(queue->alloc, (void*)pnext17);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR: {
               StdVideoDecodeAV1ReferenceInfo *pStdReferenceInfo20 = (void *)(((VkVideoDecodeAV1DpbSlotInfoKHR *)pnext17)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo20);
               vk_free(queue->alloc, (void*)pnext17);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR: {
               StdVideoEncodeH264ReferenceInfo *pStdReferenceInfo21 = (void *)(((VkVideoEncodeH264DpbSlotInfoKHR *)pnext17)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo21);
               vk_free(queue->alloc, (void*)pnext17);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR: {
               StdVideoEncodeH265ReferenceInfo *pStdReferenceInfo22 = (void *)(((VkVideoEncodeH265DpbSlotInfoKHR *)pnext17)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo22);
               vk_free(queue->alloc, (void*)pnext17);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR: {
               StdVideoEncodeAV1ReferenceInfo *pStdReferenceInfo23 = (void *)(((VkVideoEncodeAV1DpbSlotInfoKHR *)pnext17)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo23);
               vk_free(queue->alloc, (void*)pnext17);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR: {
               vk_free(queue->alloc, (void*)pnext17);
               break;
            }
            }
         }
         VkVideoPictureResourceInfoKHR *pPictureResource24 = (void *)(pSetupReferenceSlot16->pPictureResource);
         if (pPictureResource24) {
         }
         vk_free(queue->alloc, pPictureResource24);
      }
      vk_free(queue->alloc, pSetupReferenceSlot16);
      VkVideoReferenceSlotInfoKHR *pReferenceSlots25 = (void *)(cmd->u.decode_video_khr.decode_info->pReferenceSlots);
      if (cmd->u.decode_video_khr.decode_info->referenceSlotCount) {
         const VkBaseInStructure *pnext26 = pReferenceSlots25->pNext;
         if (pnext26) {
            switch ((int32_t)pnext26->sType) {
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR: {
               StdVideoDecodeH264ReferenceInfo *pStdReferenceInfo27 = (void *)(((VkVideoDecodeH264DpbSlotInfoKHR *)pnext26)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo27);
               vk_free(queue->alloc, (void*)pnext26);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR: {
               StdVideoDecodeH265ReferenceInfo *pStdReferenceInfo28 = (void *)(((VkVideoDecodeH265DpbSlotInfoKHR *)pnext26)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo28);
               vk_free(queue->alloc, (void*)pnext26);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR: {
               StdVideoDecodeAV1ReferenceInfo *pStdReferenceInfo29 = (void *)(((VkVideoDecodeAV1DpbSlotInfoKHR *)pnext26)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo29);
               vk_free(queue->alloc, (void*)pnext26);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR: {
               StdVideoEncodeH264ReferenceInfo *pStdReferenceInfo30 = (void *)(((VkVideoEncodeH264DpbSlotInfoKHR *)pnext26)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo30);
               vk_free(queue->alloc, (void*)pnext26);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR: {
               StdVideoEncodeH265ReferenceInfo *pStdReferenceInfo31 = (void *)(((VkVideoEncodeH265DpbSlotInfoKHR *)pnext26)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo31);
               vk_free(queue->alloc, (void*)pnext26);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR: {
               StdVideoEncodeAV1ReferenceInfo *pStdReferenceInfo32 = (void *)(((VkVideoEncodeAV1DpbSlotInfoKHR *)pnext26)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo32);
               vk_free(queue->alloc, (void*)pnext26);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR: {
               vk_free(queue->alloc, (void*)pnext26);
               break;
            }
            }
         }
         VkVideoPictureResourceInfoKHR *pPictureResource33 = (void *)(pReferenceSlots25->pPictureResource);
         if (pPictureResource33) {
         }
         vk_free(queue->alloc, pPictureResource33);
      }
      vk_free(queue->alloc, pReferenceSlots25);
   }
   vk_free(queue->alloc, (void*)cmd->u.decode_video_khr.decode_info);

}

VkResult vk_enqueue_cmd_decode_video_khr(struct vk_cmd_queue *queue
, const VkVideoDecodeInfoKHR* pDecodeInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DECODE_VIDEO_KHR], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DECODE_VIDEO_KHR;
   if (pDecodeInfo) {
      cmd->u.decode_video_khr.decode_info = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.decode_video_khr.decode_info == NULL) goto err;
      VkVideoDecodeInfoKHR *tmp_dst1 = (void *)cmd->u.decode_video_khr.decode_info;
      VkVideoDecodeInfoKHR *tmp_src2 = (void *)pDecodeInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkVideoDecodeInfoKHR));
      const VkBaseInStructure *pnext = tmp_dst1->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoInlineQueryInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkVideoInlineQueryInfoKHR *tmp_dst3 = (void *)tmp_dst1->pNext;
               VkVideoInlineQueryInfoKHR *tmp_src4 = (void *)pnext;
               memcpy(tmp_dst3, tmp_src4, sizeof(VkVideoInlineQueryInfoKHR));
            } else {
               tmp_dst1->pNext = NULL;
            }
            break;
         case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_INLINE_SESSION_PARAMETERS_INFO_KHR:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeH264InlineSessionParametersInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkVideoDecodeH264InlineSessionParametersInfoKHR *tmp_dst5 = (void *)tmp_dst1->pNext;
               VkVideoDecodeH264InlineSessionParametersInfoKHR *tmp_src6 = (void *)pnext;
               memcpy(tmp_dst5, tmp_src6, sizeof(VkVideoDecodeH264InlineSessionParametersInfoKHR));
               if (tmp_src6->pStdSPS) {
                  tmp_dst5->pStdSPS = vk_zalloc(queue->alloc, sizeof(StdVideoH264SequenceParameterSet), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst5->pStdSPS == NULL) goto err;
                  StdVideoH264SequenceParameterSet *tmp_dst7 = (void *)tmp_dst5->pStdSPS;
                  StdVideoH264SequenceParameterSet *tmp_src8 = (void *)tmp_src6->pStdSPS;
                  memcpy(tmp_dst7, tmp_src8, sizeof(StdVideoH264SequenceParameterSet));
               } else {
                  tmp_dst5->pStdSPS = NULL;
               }
               if (tmp_src6->pStdPPS) {
                  tmp_dst5->pStdPPS = vk_zalloc(queue->alloc, sizeof(StdVideoH264PictureParameterSet), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst5->pStdPPS == NULL) goto err;
                  StdVideoH264PictureParameterSet *tmp_dst9 = (void *)tmp_dst5->pStdPPS;
                  StdVideoH264PictureParameterSet *tmp_src10 = (void *)tmp_src6->pStdPPS;
                  memcpy(tmp_dst9, tmp_src10, sizeof(StdVideoH264PictureParameterSet));
               } else {
                  tmp_dst5->pStdPPS = NULL;
               }
            } else {
               tmp_dst1->pNext = NULL;
            }
            break;
         case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeH264PictureInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkVideoDecodeH264PictureInfoKHR *tmp_dst11 = (void *)tmp_dst1->pNext;
               VkVideoDecodeH264PictureInfoKHR *tmp_src12 = (void *)pnext;
               memcpy(tmp_dst11, tmp_src12, sizeof(VkVideoDecodeH264PictureInfoKHR));
               if (tmp_src12->pStdPictureInfo) {
                  tmp_dst11->pStdPictureInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeH264PictureInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst11->pStdPictureInfo == NULL) goto err;
                  StdVideoDecodeH264PictureInfo *tmp_dst13 = (void *)tmp_dst11->pStdPictureInfo;
                  StdVideoDecodeH264PictureInfo *tmp_src14 = (void *)tmp_src12->pStdPictureInfo;
                  memcpy(tmp_dst13, tmp_src14, sizeof(StdVideoDecodeH264PictureInfo));
               } else {
                  tmp_dst11->pStdPictureInfo = NULL;
               }
               if (tmp_src12->pSliceOffsets) {
                  tmp_dst11->pSliceOffsets = vk_zalloc(queue->alloc, sizeof(uint32_t) * tmp_src12->sliceCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst11->pSliceOffsets == NULL) goto err;
                  uint32_t *tmp_dst15 = (void *)tmp_dst11->pSliceOffsets;
                  uint32_t *tmp_src16 = (void *)tmp_src12->pSliceOffsets;
                  memcpy(tmp_dst15, tmp_src16, sizeof(uint32_t) * tmp_src12->sliceCount);
                  for (uint32_t i17 = 0; i17 < tmp_src12->sliceCount; i17++) {
                     uint32_t *tmp_dst18 = tmp_dst15 + i17; (void)tmp_dst18;
                     uint32_t *tmp_src19 = tmp_src16 + i17; (void)tmp_src19;
                     }
                  } else {
                     tmp_dst11->pSliceOffsets = NULL;
                  }
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_INLINE_SESSION_PARAMETERS_INFO_KHR:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeH265InlineSessionParametersInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkVideoDecodeH265InlineSessionParametersInfoKHR *tmp_dst20 = (void *)tmp_dst1->pNext;
                  VkVideoDecodeH265InlineSessionParametersInfoKHR *tmp_src21 = (void *)pnext;
                  memcpy(tmp_dst20, tmp_src21, sizeof(VkVideoDecodeH265InlineSessionParametersInfoKHR));
                  if (tmp_src21->pStdVPS) {
                     tmp_dst20->pStdVPS = vk_zalloc(queue->alloc, sizeof(StdVideoH265VideoParameterSet), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst20->pStdVPS == NULL) goto err;
                     StdVideoH265VideoParameterSet *tmp_dst22 = (void *)tmp_dst20->pStdVPS;
                     StdVideoH265VideoParameterSet *tmp_src23 = (void *)tmp_src21->pStdVPS;
                     memcpy(tmp_dst22, tmp_src23, sizeof(StdVideoH265VideoParameterSet));
                  } else {
                     tmp_dst20->pStdVPS = NULL;
                  }
                  if (tmp_src21->pStdSPS) {
                     tmp_dst20->pStdSPS = vk_zalloc(queue->alloc, sizeof(StdVideoH265SequenceParameterSet), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst20->pStdSPS == NULL) goto err;
                     StdVideoH265SequenceParameterSet *tmp_dst24 = (void *)tmp_dst20->pStdSPS;
                     StdVideoH265SequenceParameterSet *tmp_src25 = (void *)tmp_src21->pStdSPS;
                     memcpy(tmp_dst24, tmp_src25, sizeof(StdVideoH265SequenceParameterSet));
                  } else {
                     tmp_dst20->pStdSPS = NULL;
                  }
                  if (tmp_src21->pStdPPS) {
                     tmp_dst20->pStdPPS = vk_zalloc(queue->alloc, sizeof(StdVideoH265PictureParameterSet), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst20->pStdPPS == NULL) goto err;
                     StdVideoH265PictureParameterSet *tmp_dst26 = (void *)tmp_dst20->pStdPPS;
                     StdVideoH265PictureParameterSet *tmp_src27 = (void *)tmp_src21->pStdPPS;
                     memcpy(tmp_dst26, tmp_src27, sizeof(StdVideoH265PictureParameterSet));
                  } else {
                     tmp_dst20->pStdPPS = NULL;
                  }
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeH265PictureInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkVideoDecodeH265PictureInfoKHR *tmp_dst28 = (void *)tmp_dst1->pNext;
                  VkVideoDecodeH265PictureInfoKHR *tmp_src29 = (void *)pnext;
                  memcpy(tmp_dst28, tmp_src29, sizeof(VkVideoDecodeH265PictureInfoKHR));
                  if (tmp_src29->pStdPictureInfo) {
                     tmp_dst28->pStdPictureInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeH265PictureInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst28->pStdPictureInfo == NULL) goto err;
                     StdVideoDecodeH265PictureInfo *tmp_dst30 = (void *)tmp_dst28->pStdPictureInfo;
                     StdVideoDecodeH265PictureInfo *tmp_src31 = (void *)tmp_src29->pStdPictureInfo;
                     memcpy(tmp_dst30, tmp_src31, sizeof(StdVideoDecodeH265PictureInfo));
                  } else {
                     tmp_dst28->pStdPictureInfo = NULL;
                  }
                  if (tmp_src29->pSliceSegmentOffsets) {
                     tmp_dst28->pSliceSegmentOffsets = vk_zalloc(queue->alloc, sizeof(uint32_t) * tmp_src29->sliceSegmentCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst28->pSliceSegmentOffsets == NULL) goto err;
                     uint32_t *tmp_dst32 = (void *)tmp_dst28->pSliceSegmentOffsets;
                     uint32_t *tmp_src33 = (void *)tmp_src29->pSliceSegmentOffsets;
                     memcpy(tmp_dst32, tmp_src33, sizeof(uint32_t) * tmp_src29->sliceSegmentCount);
                     for (uint32_t i34 = 0; i34 < tmp_src29->sliceSegmentCount; i34++) {
                        uint32_t *tmp_dst35 = tmp_dst32 + i34; (void)tmp_dst35;
                        uint32_t *tmp_src36 = tmp_src33 + i34; (void)tmp_src36;
                        }
                     } else {
                        tmp_dst28->pSliceSegmentOffsets = NULL;
                     }
                  } else {
                     tmp_dst1->pNext = NULL;
                  }
                  break;
               case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PICTURE_INFO_KHR:
                  if (pnext) {
                     tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeVP9PictureInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst1->pNext == NULL) goto err;
                     VkVideoDecodeVP9PictureInfoKHR *tmp_dst37 = (void *)tmp_dst1->pNext;
                     VkVideoDecodeVP9PictureInfoKHR *tmp_src38 = (void *)pnext;
                     memcpy(tmp_dst37, tmp_src38, sizeof(VkVideoDecodeVP9PictureInfoKHR));
                     if (tmp_src38->pStdPictureInfo) {
                        tmp_dst37->pStdPictureInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeVP9PictureInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst37->pStdPictureInfo == NULL) goto err;
                        StdVideoDecodeVP9PictureInfo *tmp_dst39 = (void *)tmp_dst37->pStdPictureInfo;
                        StdVideoDecodeVP9PictureInfo *tmp_src40 = (void *)tmp_src38->pStdPictureInfo;
                        memcpy(tmp_dst39, tmp_src40, sizeof(StdVideoDecodeVP9PictureInfo));
                     } else {
                        tmp_dst37->pStdPictureInfo = NULL;
                     }
                  } else {
                     tmp_dst1->pNext = NULL;
                  }
                  break;
               case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_INLINE_SESSION_PARAMETERS_INFO_KHR:
                  if (pnext) {
                     tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeAV1InlineSessionParametersInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst1->pNext == NULL) goto err;
                     VkVideoDecodeAV1InlineSessionParametersInfoKHR *tmp_dst41 = (void *)tmp_dst1->pNext;
                     VkVideoDecodeAV1InlineSessionParametersInfoKHR *tmp_src42 = (void *)pnext;
                     memcpy(tmp_dst41, tmp_src42, sizeof(VkVideoDecodeAV1InlineSessionParametersInfoKHR));
                     if (tmp_src42->pStdSequenceHeader) {
                        tmp_dst41->pStdSequenceHeader = vk_zalloc(queue->alloc, sizeof(StdVideoAV1SequenceHeader), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst41->pStdSequenceHeader == NULL) goto err;
                        StdVideoAV1SequenceHeader *tmp_dst43 = (void *)tmp_dst41->pStdSequenceHeader;
                        StdVideoAV1SequenceHeader *tmp_src44 = (void *)tmp_src42->pStdSequenceHeader;
                        memcpy(tmp_dst43, tmp_src44, sizeof(StdVideoAV1SequenceHeader));
                     } else {
                        tmp_dst41->pStdSequenceHeader = NULL;
                     }
                  } else {
                     tmp_dst1->pNext = NULL;
                  }
                  break;
               case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR:
                  if (pnext) {
                     tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeAV1PictureInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst1->pNext == NULL) goto err;
                     VkVideoDecodeAV1PictureInfoKHR *tmp_dst45 = (void *)tmp_dst1->pNext;
                     VkVideoDecodeAV1PictureInfoKHR *tmp_src46 = (void *)pnext;
                     memcpy(tmp_dst45, tmp_src46, sizeof(VkVideoDecodeAV1PictureInfoKHR));
                     if (tmp_src46->pStdPictureInfo) {
                        tmp_dst45->pStdPictureInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeAV1PictureInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst45->pStdPictureInfo == NULL) goto err;
                        StdVideoDecodeAV1PictureInfo *tmp_dst47 = (void *)tmp_dst45->pStdPictureInfo;
                        StdVideoDecodeAV1PictureInfo *tmp_src48 = (void *)tmp_src46->pStdPictureInfo;
                        memcpy(tmp_dst47, tmp_src48, sizeof(StdVideoDecodeAV1PictureInfo));
                     } else {
                        tmp_dst45->pStdPictureInfo = NULL;
                     }
                     if (tmp_src46->pTileOffsets) {
                        tmp_dst45->pTileOffsets = vk_zalloc(queue->alloc, sizeof(uint32_t) * tmp_src46->tileCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst45->pTileOffsets == NULL) goto err;
                        uint32_t *tmp_dst49 = (void *)tmp_dst45->pTileOffsets;
                        uint32_t *tmp_src50 = (void *)tmp_src46->pTileOffsets;
                        memcpy(tmp_dst49, tmp_src50, sizeof(uint32_t) * tmp_src46->tileCount);
                        for (uint32_t i51 = 0; i51 < tmp_src46->tileCount; i51++) {
                           uint32_t *tmp_dst52 = tmp_dst49 + i51; (void)tmp_dst52;
                           uint32_t *tmp_src53 = tmp_src50 + i51; (void)tmp_src53;
                           }
                        } else {
                           tmp_dst45->pTileOffsets = NULL;
                        }
                        if (tmp_src46->pTileSizes) {
                           tmp_dst45->pTileSizes = vk_zalloc(queue->alloc, sizeof(uint32_t) * tmp_src46->tileCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst45->pTileSizes == NULL) goto err;
                           uint32_t *tmp_dst54 = (void *)tmp_dst45->pTileSizes;
                           uint32_t *tmp_src55 = (void *)tmp_src46->pTileSizes;
                           memcpy(tmp_dst54, tmp_src55, sizeof(uint32_t) * tmp_src46->tileCount);
                           for (uint32_t i56 = 0; i56 < tmp_src46->tileCount; i56++) {
                              uint32_t *tmp_dst57 = tmp_dst54 + i56; (void)tmp_dst57;
                              uint32_t *tmp_src58 = tmp_src55 + i56; (void)tmp_src58;
                              }
                           } else {
                              tmp_dst45->pTileSizes = NULL;
                           }
                        } else {
                           tmp_dst1->pNext = NULL;
                        }
                        break;
                     }
                  }
                  if (tmp_src2->pSetupReferenceSlot) {
                     tmp_dst1->pSetupReferenceSlot = vk_zalloc(queue->alloc, sizeof(VkVideoReferenceSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst1->pSetupReferenceSlot == NULL) goto err;
                     VkVideoReferenceSlotInfoKHR *tmp_dst59 = (void *)tmp_dst1->pSetupReferenceSlot;
                     VkVideoReferenceSlotInfoKHR *tmp_src60 = (void *)tmp_src2->pSetupReferenceSlot;
                     memcpy(tmp_dst59, tmp_src60, sizeof(VkVideoReferenceSlotInfoKHR));
                     const VkBaseInStructure *pnext = tmp_dst59->pNext;
                     if (pnext) {
                        switch ((int32_t)pnext->sType) {
                        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
                           if (pnext) {
                              tmp_dst59->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeH264DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst59->pNext == NULL) goto err;
                              VkVideoDecodeH264DpbSlotInfoKHR *tmp_dst61 = (void *)tmp_dst59->pNext;
                              VkVideoDecodeH264DpbSlotInfoKHR *tmp_src62 = (void *)pnext;
                              memcpy(tmp_dst61, tmp_src62, sizeof(VkVideoDecodeH264DpbSlotInfoKHR));
                              if (tmp_src62->pStdReferenceInfo) {
                                 tmp_dst61->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeH264ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst61->pStdReferenceInfo == NULL) goto err;
                                 StdVideoDecodeH264ReferenceInfo *tmp_dst63 = (void *)tmp_dst61->pStdReferenceInfo;
                                 StdVideoDecodeH264ReferenceInfo *tmp_src64 = (void *)tmp_src62->pStdReferenceInfo;
                                 memcpy(tmp_dst63, tmp_src64, sizeof(StdVideoDecodeH264ReferenceInfo));
                              } else {
                                 tmp_dst61->pStdReferenceInfo = NULL;
                              }
                           } else {
                              tmp_dst59->pNext = NULL;
                           }
                           break;
                        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR:
                           if (pnext) {
                              tmp_dst59->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeH265DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst59->pNext == NULL) goto err;
                              VkVideoDecodeH265DpbSlotInfoKHR *tmp_dst65 = (void *)tmp_dst59->pNext;
                              VkVideoDecodeH265DpbSlotInfoKHR *tmp_src66 = (void *)pnext;
                              memcpy(tmp_dst65, tmp_src66, sizeof(VkVideoDecodeH265DpbSlotInfoKHR));
                              if (tmp_src66->pStdReferenceInfo) {
                                 tmp_dst65->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeH265ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst65->pStdReferenceInfo == NULL) goto err;
                                 StdVideoDecodeH265ReferenceInfo *tmp_dst67 = (void *)tmp_dst65->pStdReferenceInfo;
                                 StdVideoDecodeH265ReferenceInfo *tmp_src68 = (void *)tmp_src66->pStdReferenceInfo;
                                 memcpy(tmp_dst67, tmp_src68, sizeof(StdVideoDecodeH265ReferenceInfo));
                              } else {
                                 tmp_dst65->pStdReferenceInfo = NULL;
                              }
                           } else {
                              tmp_dst59->pNext = NULL;
                           }
                           break;
                        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR:
                           if (pnext) {
                              tmp_dst59->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeAV1DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst59->pNext == NULL) goto err;
                              VkVideoDecodeAV1DpbSlotInfoKHR *tmp_dst69 = (void *)tmp_dst59->pNext;
                              VkVideoDecodeAV1DpbSlotInfoKHR *tmp_src70 = (void *)pnext;
                              memcpy(tmp_dst69, tmp_src70, sizeof(VkVideoDecodeAV1DpbSlotInfoKHR));
                              if (tmp_src70->pStdReferenceInfo) {
                                 tmp_dst69->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeAV1ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst69->pStdReferenceInfo == NULL) goto err;
                                 StdVideoDecodeAV1ReferenceInfo *tmp_dst71 = (void *)tmp_dst69->pStdReferenceInfo;
                                 StdVideoDecodeAV1ReferenceInfo *tmp_src72 = (void *)tmp_src70->pStdReferenceInfo;
                                 memcpy(tmp_dst71, tmp_src72, sizeof(StdVideoDecodeAV1ReferenceInfo));
                              } else {
                                 tmp_dst69->pStdReferenceInfo = NULL;
                              }
                           } else {
                              tmp_dst59->pNext = NULL;
                           }
                           break;
                        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR:
                           if (pnext) {
                              tmp_dst59->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH264DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst59->pNext == NULL) goto err;
                              VkVideoEncodeH264DpbSlotInfoKHR *tmp_dst73 = (void *)tmp_dst59->pNext;
                              VkVideoEncodeH264DpbSlotInfoKHR *tmp_src74 = (void *)pnext;
                              memcpy(tmp_dst73, tmp_src74, sizeof(VkVideoEncodeH264DpbSlotInfoKHR));
                              if (tmp_src74->pStdReferenceInfo) {
                                 tmp_dst73->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeH264ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst73->pStdReferenceInfo == NULL) goto err;
                                 StdVideoEncodeH264ReferenceInfo *tmp_dst75 = (void *)tmp_dst73->pStdReferenceInfo;
                                 StdVideoEncodeH264ReferenceInfo *tmp_src76 = (void *)tmp_src74->pStdReferenceInfo;
                                 memcpy(tmp_dst75, tmp_src76, sizeof(StdVideoEncodeH264ReferenceInfo));
                              } else {
                                 tmp_dst73->pStdReferenceInfo = NULL;
                              }
                           } else {
                              tmp_dst59->pNext = NULL;
                           }
                           break;
                        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR:
                           if (pnext) {
                              tmp_dst59->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH265DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst59->pNext == NULL) goto err;
                              VkVideoEncodeH265DpbSlotInfoKHR *tmp_dst77 = (void *)tmp_dst59->pNext;
                              VkVideoEncodeH265DpbSlotInfoKHR *tmp_src78 = (void *)pnext;
                              memcpy(tmp_dst77, tmp_src78, sizeof(VkVideoEncodeH265DpbSlotInfoKHR));
                              if (tmp_src78->pStdReferenceInfo) {
                                 tmp_dst77->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeH265ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst77->pStdReferenceInfo == NULL) goto err;
                                 StdVideoEncodeH265ReferenceInfo *tmp_dst79 = (void *)tmp_dst77->pStdReferenceInfo;
                                 StdVideoEncodeH265ReferenceInfo *tmp_src80 = (void *)tmp_src78->pStdReferenceInfo;
                                 memcpy(tmp_dst79, tmp_src80, sizeof(StdVideoEncodeH265ReferenceInfo));
                              } else {
                                 tmp_dst77->pStdReferenceInfo = NULL;
                              }
                           } else {
                              tmp_dst59->pNext = NULL;
                           }
                           break;
                        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR:
                           if (pnext) {
                              tmp_dst59->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeAV1DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst59->pNext == NULL) goto err;
                              VkVideoEncodeAV1DpbSlotInfoKHR *tmp_dst81 = (void *)tmp_dst59->pNext;
                              VkVideoEncodeAV1DpbSlotInfoKHR *tmp_src82 = (void *)pnext;
                              memcpy(tmp_dst81, tmp_src82, sizeof(VkVideoEncodeAV1DpbSlotInfoKHR));
                              if (tmp_src82->pStdReferenceInfo) {
                                 tmp_dst81->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeAV1ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst81->pStdReferenceInfo == NULL) goto err;
                                 StdVideoEncodeAV1ReferenceInfo *tmp_dst83 = (void *)tmp_dst81->pStdReferenceInfo;
                                 StdVideoEncodeAV1ReferenceInfo *tmp_src84 = (void *)tmp_src82->pStdReferenceInfo;
                                 memcpy(tmp_dst83, tmp_src84, sizeof(StdVideoEncodeAV1ReferenceInfo));
                              } else {
                                 tmp_dst81->pStdReferenceInfo = NULL;
                              }
                           } else {
                              tmp_dst59->pNext = NULL;
                           }
                           break;
                        case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR:
                           if (pnext) {
                              tmp_dst59->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoReferenceIntraRefreshInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst59->pNext == NULL) goto err;
                              VkVideoReferenceIntraRefreshInfoKHR *tmp_dst85 = (void *)tmp_dst59->pNext;
                              VkVideoReferenceIntraRefreshInfoKHR *tmp_src86 = (void *)pnext;
                              memcpy(tmp_dst85, tmp_src86, sizeof(VkVideoReferenceIntraRefreshInfoKHR));
                           } else {
                              tmp_dst59->pNext = NULL;
                           }
                           break;
                        }
                     }
                     if (tmp_src60->pPictureResource) {
                        tmp_dst59->pPictureResource = vk_zalloc(queue->alloc, sizeof(VkVideoPictureResourceInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst59->pPictureResource == NULL) goto err;
                        VkVideoPictureResourceInfoKHR *tmp_dst87 = (void *)tmp_dst59->pPictureResource;
                        VkVideoPictureResourceInfoKHR *tmp_src88 = (void *)tmp_src60->pPictureResource;
                        memcpy(tmp_dst87, tmp_src88, sizeof(VkVideoPictureResourceInfoKHR));
                     } else {
                        tmp_dst59->pPictureResource = NULL;
                     }
                  } else {
                     tmp_dst1->pSetupReferenceSlot = NULL;
                  }
                  if (tmp_src2->pReferenceSlots) {
                     tmp_dst1->pReferenceSlots = vk_zalloc(queue->alloc, sizeof(VkVideoReferenceSlotInfoKHR) * tmp_src2->referenceSlotCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst1->pReferenceSlots == NULL) goto err;
                     VkVideoReferenceSlotInfoKHR *tmp_dst89 = (void *)tmp_dst1->pReferenceSlots;
                     VkVideoReferenceSlotInfoKHR *tmp_src90 = (void *)tmp_src2->pReferenceSlots;
                     memcpy(tmp_dst89, tmp_src90, sizeof(VkVideoReferenceSlotInfoKHR) * tmp_src2->referenceSlotCount);
                     for (uint32_t i91 = 0; i91 < tmp_src2->referenceSlotCount; i91++) {
                        VkVideoReferenceSlotInfoKHR *tmp_dst92 = tmp_dst89 + i91; (void)tmp_dst92;
                        VkVideoReferenceSlotInfoKHR *tmp_src93 = tmp_src90 + i91; (void)tmp_src93;
                        const VkBaseInStructure *pnext = tmp_dst92->pNext;
                        if (pnext) {
                           switch ((int32_t)pnext->sType) {
                           case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
                              if (pnext) {
                                 tmp_dst92->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeH264DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst92->pNext == NULL) goto err;
                                 VkVideoDecodeH264DpbSlotInfoKHR *tmp_dst94 = (void *)tmp_dst92->pNext;
                                 VkVideoDecodeH264DpbSlotInfoKHR *tmp_src95 = (void *)pnext;
                                 memcpy(tmp_dst94, tmp_src95, sizeof(VkVideoDecodeH264DpbSlotInfoKHR));
                                 if (tmp_src95->pStdReferenceInfo) {
                                    tmp_dst94->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeH264ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                    if (tmp_dst94->pStdReferenceInfo == NULL) goto err;
                                    StdVideoDecodeH264ReferenceInfo *tmp_dst96 = (void *)tmp_dst94->pStdReferenceInfo;
                                    StdVideoDecodeH264ReferenceInfo *tmp_src97 = (void *)tmp_src95->pStdReferenceInfo;
                                    memcpy(tmp_dst96, tmp_src97, sizeof(StdVideoDecodeH264ReferenceInfo));
                                 } else {
                                    tmp_dst94->pStdReferenceInfo = NULL;
                                 }
                              } else {
                                 tmp_dst92->pNext = NULL;
                              }
                              break;
                           case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR:
                              if (pnext) {
                                 tmp_dst92->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeH265DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst92->pNext == NULL) goto err;
                                 VkVideoDecodeH265DpbSlotInfoKHR *tmp_dst98 = (void *)tmp_dst92->pNext;
                                 VkVideoDecodeH265DpbSlotInfoKHR *tmp_src99 = (void *)pnext;
                                 memcpy(tmp_dst98, tmp_src99, sizeof(VkVideoDecodeH265DpbSlotInfoKHR));
                                 if (tmp_src99->pStdReferenceInfo) {
                                    tmp_dst98->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeH265ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                    if (tmp_dst98->pStdReferenceInfo == NULL) goto err;
                                    StdVideoDecodeH265ReferenceInfo *tmp_dst100 = (void *)tmp_dst98->pStdReferenceInfo;
                                    StdVideoDecodeH265ReferenceInfo *tmp_src101 = (void *)tmp_src99->pStdReferenceInfo;
                                    memcpy(tmp_dst100, tmp_src101, sizeof(StdVideoDecodeH265ReferenceInfo));
                                 } else {
                                    tmp_dst98->pStdReferenceInfo = NULL;
                                 }
                              } else {
                                 tmp_dst92->pNext = NULL;
                              }
                              break;
                           case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR:
                              if (pnext) {
                                 tmp_dst92->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeAV1DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst92->pNext == NULL) goto err;
                                 VkVideoDecodeAV1DpbSlotInfoKHR *tmp_dst102 = (void *)tmp_dst92->pNext;
                                 VkVideoDecodeAV1DpbSlotInfoKHR *tmp_src103 = (void *)pnext;
                                 memcpy(tmp_dst102, tmp_src103, sizeof(VkVideoDecodeAV1DpbSlotInfoKHR));
                                 if (tmp_src103->pStdReferenceInfo) {
                                    tmp_dst102->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeAV1ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                    if (tmp_dst102->pStdReferenceInfo == NULL) goto err;
                                    StdVideoDecodeAV1ReferenceInfo *tmp_dst104 = (void *)tmp_dst102->pStdReferenceInfo;
                                    StdVideoDecodeAV1ReferenceInfo *tmp_src105 = (void *)tmp_src103->pStdReferenceInfo;
                                    memcpy(tmp_dst104, tmp_src105, sizeof(StdVideoDecodeAV1ReferenceInfo));
                                 } else {
                                    tmp_dst102->pStdReferenceInfo = NULL;
                                 }
                              } else {
                                 tmp_dst92->pNext = NULL;
                              }
                              break;
                           case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR:
                              if (pnext) {
                                 tmp_dst92->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH264DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst92->pNext == NULL) goto err;
                                 VkVideoEncodeH264DpbSlotInfoKHR *tmp_dst106 = (void *)tmp_dst92->pNext;
                                 VkVideoEncodeH264DpbSlotInfoKHR *tmp_src107 = (void *)pnext;
                                 memcpy(tmp_dst106, tmp_src107, sizeof(VkVideoEncodeH264DpbSlotInfoKHR));
                                 if (tmp_src107->pStdReferenceInfo) {
                                    tmp_dst106->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeH264ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                    if (tmp_dst106->pStdReferenceInfo == NULL) goto err;
                                    StdVideoEncodeH264ReferenceInfo *tmp_dst108 = (void *)tmp_dst106->pStdReferenceInfo;
                                    StdVideoEncodeH264ReferenceInfo *tmp_src109 = (void *)tmp_src107->pStdReferenceInfo;
                                    memcpy(tmp_dst108, tmp_src109, sizeof(StdVideoEncodeH264ReferenceInfo));
                                 } else {
                                    tmp_dst106->pStdReferenceInfo = NULL;
                                 }
                              } else {
                                 tmp_dst92->pNext = NULL;
                              }
                              break;
                           case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR:
                              if (pnext) {
                                 tmp_dst92->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH265DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst92->pNext == NULL) goto err;
                                 VkVideoEncodeH265DpbSlotInfoKHR *tmp_dst110 = (void *)tmp_dst92->pNext;
                                 VkVideoEncodeH265DpbSlotInfoKHR *tmp_src111 = (void *)pnext;
                                 memcpy(tmp_dst110, tmp_src111, sizeof(VkVideoEncodeH265DpbSlotInfoKHR));
                                 if (tmp_src111->pStdReferenceInfo) {
                                    tmp_dst110->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeH265ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                    if (tmp_dst110->pStdReferenceInfo == NULL) goto err;
                                    StdVideoEncodeH265ReferenceInfo *tmp_dst112 = (void *)tmp_dst110->pStdReferenceInfo;
                                    StdVideoEncodeH265ReferenceInfo *tmp_src113 = (void *)tmp_src111->pStdReferenceInfo;
                                    memcpy(tmp_dst112, tmp_src113, sizeof(StdVideoEncodeH265ReferenceInfo));
                                 } else {
                                    tmp_dst110->pStdReferenceInfo = NULL;
                                 }
                              } else {
                                 tmp_dst92->pNext = NULL;
                              }
                              break;
                           case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR:
                              if (pnext) {
                                 tmp_dst92->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeAV1DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst92->pNext == NULL) goto err;
                                 VkVideoEncodeAV1DpbSlotInfoKHR *tmp_dst114 = (void *)tmp_dst92->pNext;
                                 VkVideoEncodeAV1DpbSlotInfoKHR *tmp_src115 = (void *)pnext;
                                 memcpy(tmp_dst114, tmp_src115, sizeof(VkVideoEncodeAV1DpbSlotInfoKHR));
                                 if (tmp_src115->pStdReferenceInfo) {
                                    tmp_dst114->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeAV1ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                    if (tmp_dst114->pStdReferenceInfo == NULL) goto err;
                                    StdVideoEncodeAV1ReferenceInfo *tmp_dst116 = (void *)tmp_dst114->pStdReferenceInfo;
                                    StdVideoEncodeAV1ReferenceInfo *tmp_src117 = (void *)tmp_src115->pStdReferenceInfo;
                                    memcpy(tmp_dst116, tmp_src117, sizeof(StdVideoEncodeAV1ReferenceInfo));
                                 } else {
                                    tmp_dst114->pStdReferenceInfo = NULL;
                                 }
                              } else {
                                 tmp_dst92->pNext = NULL;
                              }
                              break;
                           case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR:
                              if (pnext) {
                                 tmp_dst92->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoReferenceIntraRefreshInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst92->pNext == NULL) goto err;
                                 VkVideoReferenceIntraRefreshInfoKHR *tmp_dst118 = (void *)tmp_dst92->pNext;
                                 VkVideoReferenceIntraRefreshInfoKHR *tmp_src119 = (void *)pnext;
                                 memcpy(tmp_dst118, tmp_src119, sizeof(VkVideoReferenceIntraRefreshInfoKHR));
                              } else {
                                 tmp_dst92->pNext = NULL;
                              }
                              break;
                           }
                        }
                        if (tmp_src93->pPictureResource) {
                           tmp_dst92->pPictureResource = vk_zalloc(queue->alloc, sizeof(VkVideoPictureResourceInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst92->pPictureResource == NULL) goto err;
                           VkVideoPictureResourceInfoKHR *tmp_dst120 = (void *)tmp_dst92->pPictureResource;
                           VkVideoPictureResourceInfoKHR *tmp_src121 = (void *)tmp_src93->pPictureResource;
                           memcpy(tmp_dst120, tmp_src121, sizeof(VkVideoPictureResourceInfoKHR));
                        } else {
                           tmp_dst92->pPictureResource = NULL;
                        }
                        }
                     } else {
                        tmp_dst1->pReferenceSlots = NULL;
                     }
                  } else {
                     cmd->u.decode_video_khr.decode_info = NULL;
                  }

                  list_addtail(&cmd->cmd_link, &queue->cmds);
                  return VK_SUCCESS;

err:
                  if (cmd)
                     vk_free_cmd_decode_video_khr(queue, cmd);
                  return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_begin_video_coding_khr(struct vk_cmd_queue *queue,
                                   struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.begin_video_coding_khr.begin_info) {
      const VkBaseInStructure *pnext1 = cmd->u.begin_video_coding_khr.begin_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR: {
            VkVideoEncodeRateControlLayerInfoKHR *pLayers2 = (void *)(((VkVideoEncodeRateControlInfoKHR *)pnext1)->pLayers);
            if (((VkVideoEncodeRateControlInfoKHR *)pnext1)->layerCount) {
               const VkBaseInStructure *pnext3 = pLayers2->pNext;
               if (pnext3) {
                  switch ((int32_t)pnext3->sType) {
                  case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR: {
                     vk_free(queue->alloc, (void*)pnext3);
                     break;
                  }
                  case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR: {
                     vk_free(queue->alloc, (void*)pnext3);
                     break;
                  }
                  case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR: {
                     vk_free(queue->alloc, (void*)pnext3);
                     break;
                  }
                  }
               }
            }
            vk_free(queue->alloc, pLayers2);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_GOP_REMAINING_FRAME_INFO_KHR: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
      VkVideoReferenceSlotInfoKHR *pReferenceSlots4 = (void *)(cmd->u.begin_video_coding_khr.begin_info->pReferenceSlots);
      if (cmd->u.begin_video_coding_khr.begin_info->referenceSlotCount) {
         const VkBaseInStructure *pnext5 = pReferenceSlots4->pNext;
         if (pnext5) {
            switch ((int32_t)pnext5->sType) {
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR: {
               StdVideoDecodeH264ReferenceInfo *pStdReferenceInfo6 = (void *)(((VkVideoDecodeH264DpbSlotInfoKHR *)pnext5)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo6);
               vk_free(queue->alloc, (void*)pnext5);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR: {
               StdVideoDecodeH265ReferenceInfo *pStdReferenceInfo7 = (void *)(((VkVideoDecodeH265DpbSlotInfoKHR *)pnext5)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo7);
               vk_free(queue->alloc, (void*)pnext5);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR: {
               StdVideoDecodeAV1ReferenceInfo *pStdReferenceInfo8 = (void *)(((VkVideoDecodeAV1DpbSlotInfoKHR *)pnext5)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo8);
               vk_free(queue->alloc, (void*)pnext5);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR: {
               StdVideoEncodeH264ReferenceInfo *pStdReferenceInfo9 = (void *)(((VkVideoEncodeH264DpbSlotInfoKHR *)pnext5)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo9);
               vk_free(queue->alloc, (void*)pnext5);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR: {
               StdVideoEncodeH265ReferenceInfo *pStdReferenceInfo10 = (void *)(((VkVideoEncodeH265DpbSlotInfoKHR *)pnext5)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo10);
               vk_free(queue->alloc, (void*)pnext5);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR: {
               StdVideoEncodeAV1ReferenceInfo *pStdReferenceInfo11 = (void *)(((VkVideoEncodeAV1DpbSlotInfoKHR *)pnext5)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo11);
               vk_free(queue->alloc, (void*)pnext5);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR: {
               vk_free(queue->alloc, (void*)pnext5);
               break;
            }
            }
         }
         VkVideoPictureResourceInfoKHR *pPictureResource12 = (void *)(pReferenceSlots4->pPictureResource);
         if (pPictureResource12) {
         }
         vk_free(queue->alloc, pPictureResource12);
      }
      vk_free(queue->alloc, pReferenceSlots4);
   }
   vk_free(queue->alloc, (void*)cmd->u.begin_video_coding_khr.begin_info);

}

VkResult vk_enqueue_cmd_begin_video_coding_khr(struct vk_cmd_queue *queue
, const VkVideoBeginCodingInfoKHR* pBeginInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BEGIN_VIDEO_CODING_KHR], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BEGIN_VIDEO_CODING_KHR;
   if (pBeginInfo) {
      cmd->u.begin_video_coding_khr.begin_info = vk_zalloc(queue->alloc, sizeof(VkVideoBeginCodingInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.begin_video_coding_khr.begin_info == NULL) goto err;
      VkVideoBeginCodingInfoKHR *tmp_dst1 = (void *)cmd->u.begin_video_coding_khr.begin_info;
      VkVideoBeginCodingInfoKHR *tmp_src2 = (void *)pBeginInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkVideoBeginCodingInfoKHR));
      const VkBaseInStructure *pnext = tmp_dst1->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeRateControlInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkVideoEncodeRateControlInfoKHR *tmp_dst3 = (void *)tmp_dst1->pNext;
               VkVideoEncodeRateControlInfoKHR *tmp_src4 = (void *)pnext;
               memcpy(tmp_dst3, tmp_src4, sizeof(VkVideoEncodeRateControlInfoKHR));
               if (tmp_src4->pLayers) {
                  tmp_dst3->pLayers = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeRateControlLayerInfoKHR) * tmp_src4->layerCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst3->pLayers == NULL) goto err;
                  VkVideoEncodeRateControlLayerInfoKHR *tmp_dst5 = (void *)tmp_dst3->pLayers;
                  VkVideoEncodeRateControlLayerInfoKHR *tmp_src6 = (void *)tmp_src4->pLayers;
                  memcpy(tmp_dst5, tmp_src6, sizeof(VkVideoEncodeRateControlLayerInfoKHR) * tmp_src4->layerCount);
                  for (uint32_t i7 = 0; i7 < tmp_src4->layerCount; i7++) {
                     VkVideoEncodeRateControlLayerInfoKHR *tmp_dst8 = tmp_dst5 + i7; (void)tmp_dst8;
                     VkVideoEncodeRateControlLayerInfoKHR *tmp_src9 = tmp_src6 + i7; (void)tmp_src9;
                     const VkBaseInStructure *pnext = tmp_dst8->pNext;
                     if (pnext) {
                        switch ((int32_t)pnext->sType) {
                        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR:
                           if (pnext) {
                              tmp_dst8->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH264RateControlLayerInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst8->pNext == NULL) goto err;
                              VkVideoEncodeH264RateControlLayerInfoKHR *tmp_dst10 = (void *)tmp_dst8->pNext;
                              VkVideoEncodeH264RateControlLayerInfoKHR *tmp_src11 = (void *)pnext;
                              memcpy(tmp_dst10, tmp_src11, sizeof(VkVideoEncodeH264RateControlLayerInfoKHR));
                           } else {
                              tmp_dst8->pNext = NULL;
                           }
                           break;
                        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR:
                           if (pnext) {
                              tmp_dst8->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH265RateControlLayerInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst8->pNext == NULL) goto err;
                              VkVideoEncodeH265RateControlLayerInfoKHR *tmp_dst12 = (void *)tmp_dst8->pNext;
                              VkVideoEncodeH265RateControlLayerInfoKHR *tmp_src13 = (void *)pnext;
                              memcpy(tmp_dst12, tmp_src13, sizeof(VkVideoEncodeH265RateControlLayerInfoKHR));
                           } else {
                              tmp_dst8->pNext = NULL;
                           }
                           break;
                        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR:
                           if (pnext) {
                              tmp_dst8->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeAV1RateControlLayerInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst8->pNext == NULL) goto err;
                              VkVideoEncodeAV1RateControlLayerInfoKHR *tmp_dst14 = (void *)tmp_dst8->pNext;
                              VkVideoEncodeAV1RateControlLayerInfoKHR *tmp_src15 = (void *)pnext;
                              memcpy(tmp_dst14, tmp_src15, sizeof(VkVideoEncodeAV1RateControlLayerInfoKHR));
                           } else {
                              tmp_dst8->pNext = NULL;
                           }
                           break;
                        }
                     }
                     }
                  } else {
                     tmp_dst3->pLayers = NULL;
                  }
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH264RateControlInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkVideoEncodeH264RateControlInfoKHR *tmp_dst16 = (void *)tmp_dst1->pNext;
                  VkVideoEncodeH264RateControlInfoKHR *tmp_src17 = (void *)pnext;
                  memcpy(tmp_dst16, tmp_src17, sizeof(VkVideoEncodeH264RateControlInfoKHR));
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH264GopRemainingFrameInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkVideoEncodeH264GopRemainingFrameInfoKHR *tmp_dst18 = (void *)tmp_dst1->pNext;
                  VkVideoEncodeH264GopRemainingFrameInfoKHR *tmp_src19 = (void *)pnext;
                  memcpy(tmp_dst18, tmp_src19, sizeof(VkVideoEncodeH264GopRemainingFrameInfoKHR));
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH265RateControlInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkVideoEncodeH265RateControlInfoKHR *tmp_dst20 = (void *)tmp_dst1->pNext;
                  VkVideoEncodeH265RateControlInfoKHR *tmp_src21 = (void *)pnext;
                  memcpy(tmp_dst20, tmp_src21, sizeof(VkVideoEncodeH265RateControlInfoKHR));
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH265GopRemainingFrameInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkVideoEncodeH265GopRemainingFrameInfoKHR *tmp_dst22 = (void *)tmp_dst1->pNext;
                  VkVideoEncodeH265GopRemainingFrameInfoKHR *tmp_src23 = (void *)pnext;
                  memcpy(tmp_dst22, tmp_src23, sizeof(VkVideoEncodeH265GopRemainingFrameInfoKHR));
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeAV1RateControlInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkVideoEncodeAV1RateControlInfoKHR *tmp_dst24 = (void *)tmp_dst1->pNext;
                  VkVideoEncodeAV1RateControlInfoKHR *tmp_src25 = (void *)pnext;
                  memcpy(tmp_dst24, tmp_src25, sizeof(VkVideoEncodeAV1RateControlInfoKHR));
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_GOP_REMAINING_FRAME_INFO_KHR:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeAV1GopRemainingFrameInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkVideoEncodeAV1GopRemainingFrameInfoKHR *tmp_dst26 = (void *)tmp_dst1->pNext;
                  VkVideoEncodeAV1GopRemainingFrameInfoKHR *tmp_src27 = (void *)pnext;
                  memcpy(tmp_dst26, tmp_src27, sizeof(VkVideoEncodeAV1GopRemainingFrameInfoKHR));
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            }
         }
         if (tmp_src2->pReferenceSlots) {
            tmp_dst1->pReferenceSlots = vk_zalloc(queue->alloc, sizeof(VkVideoReferenceSlotInfoKHR) * tmp_src2->referenceSlotCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
            if (tmp_dst1->pReferenceSlots == NULL) goto err;
            VkVideoReferenceSlotInfoKHR *tmp_dst28 = (void *)tmp_dst1->pReferenceSlots;
            VkVideoReferenceSlotInfoKHR *tmp_src29 = (void *)tmp_src2->pReferenceSlots;
            memcpy(tmp_dst28, tmp_src29, sizeof(VkVideoReferenceSlotInfoKHR) * tmp_src2->referenceSlotCount);
            for (uint32_t i30 = 0; i30 < tmp_src2->referenceSlotCount; i30++) {
               VkVideoReferenceSlotInfoKHR *tmp_dst31 = tmp_dst28 + i30; (void)tmp_dst31;
               VkVideoReferenceSlotInfoKHR *tmp_src32 = tmp_src29 + i30; (void)tmp_src32;
               const VkBaseInStructure *pnext = tmp_dst31->pNext;
               if (pnext) {
                  switch ((int32_t)pnext->sType) {
                  case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
                     if (pnext) {
                        tmp_dst31->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeH264DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst31->pNext == NULL) goto err;
                        VkVideoDecodeH264DpbSlotInfoKHR *tmp_dst33 = (void *)tmp_dst31->pNext;
                        VkVideoDecodeH264DpbSlotInfoKHR *tmp_src34 = (void *)pnext;
                        memcpy(tmp_dst33, tmp_src34, sizeof(VkVideoDecodeH264DpbSlotInfoKHR));
                        if (tmp_src34->pStdReferenceInfo) {
                           tmp_dst33->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeH264ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst33->pStdReferenceInfo == NULL) goto err;
                           StdVideoDecodeH264ReferenceInfo *tmp_dst35 = (void *)tmp_dst33->pStdReferenceInfo;
                           StdVideoDecodeH264ReferenceInfo *tmp_src36 = (void *)tmp_src34->pStdReferenceInfo;
                           memcpy(tmp_dst35, tmp_src36, sizeof(StdVideoDecodeH264ReferenceInfo));
                        } else {
                           tmp_dst33->pStdReferenceInfo = NULL;
                        }
                     } else {
                        tmp_dst31->pNext = NULL;
                     }
                     break;
                  case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR:
                     if (pnext) {
                        tmp_dst31->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeH265DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst31->pNext == NULL) goto err;
                        VkVideoDecodeH265DpbSlotInfoKHR *tmp_dst37 = (void *)tmp_dst31->pNext;
                        VkVideoDecodeH265DpbSlotInfoKHR *tmp_src38 = (void *)pnext;
                        memcpy(tmp_dst37, tmp_src38, sizeof(VkVideoDecodeH265DpbSlotInfoKHR));
                        if (tmp_src38->pStdReferenceInfo) {
                           tmp_dst37->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeH265ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst37->pStdReferenceInfo == NULL) goto err;
                           StdVideoDecodeH265ReferenceInfo *tmp_dst39 = (void *)tmp_dst37->pStdReferenceInfo;
                           StdVideoDecodeH265ReferenceInfo *tmp_src40 = (void *)tmp_src38->pStdReferenceInfo;
                           memcpy(tmp_dst39, tmp_src40, sizeof(StdVideoDecodeH265ReferenceInfo));
                        } else {
                           tmp_dst37->pStdReferenceInfo = NULL;
                        }
                     } else {
                        tmp_dst31->pNext = NULL;
                     }
                     break;
                  case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR:
                     if (pnext) {
                        tmp_dst31->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeAV1DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst31->pNext == NULL) goto err;
                        VkVideoDecodeAV1DpbSlotInfoKHR *tmp_dst41 = (void *)tmp_dst31->pNext;
                        VkVideoDecodeAV1DpbSlotInfoKHR *tmp_src42 = (void *)pnext;
                        memcpy(tmp_dst41, tmp_src42, sizeof(VkVideoDecodeAV1DpbSlotInfoKHR));
                        if (tmp_src42->pStdReferenceInfo) {
                           tmp_dst41->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeAV1ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst41->pStdReferenceInfo == NULL) goto err;
                           StdVideoDecodeAV1ReferenceInfo *tmp_dst43 = (void *)tmp_dst41->pStdReferenceInfo;
                           StdVideoDecodeAV1ReferenceInfo *tmp_src44 = (void *)tmp_src42->pStdReferenceInfo;
                           memcpy(tmp_dst43, tmp_src44, sizeof(StdVideoDecodeAV1ReferenceInfo));
                        } else {
                           tmp_dst41->pStdReferenceInfo = NULL;
                        }
                     } else {
                        tmp_dst31->pNext = NULL;
                     }
                     break;
                  case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR:
                     if (pnext) {
                        tmp_dst31->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH264DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst31->pNext == NULL) goto err;
                        VkVideoEncodeH264DpbSlotInfoKHR *tmp_dst45 = (void *)tmp_dst31->pNext;
                        VkVideoEncodeH264DpbSlotInfoKHR *tmp_src46 = (void *)pnext;
                        memcpy(tmp_dst45, tmp_src46, sizeof(VkVideoEncodeH264DpbSlotInfoKHR));
                        if (tmp_src46->pStdReferenceInfo) {
                           tmp_dst45->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeH264ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst45->pStdReferenceInfo == NULL) goto err;
                           StdVideoEncodeH264ReferenceInfo *tmp_dst47 = (void *)tmp_dst45->pStdReferenceInfo;
                           StdVideoEncodeH264ReferenceInfo *tmp_src48 = (void *)tmp_src46->pStdReferenceInfo;
                           memcpy(tmp_dst47, tmp_src48, sizeof(StdVideoEncodeH264ReferenceInfo));
                        } else {
                           tmp_dst45->pStdReferenceInfo = NULL;
                        }
                     } else {
                        tmp_dst31->pNext = NULL;
                     }
                     break;
                  case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR:
                     if (pnext) {
                        tmp_dst31->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH265DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst31->pNext == NULL) goto err;
                        VkVideoEncodeH265DpbSlotInfoKHR *tmp_dst49 = (void *)tmp_dst31->pNext;
                        VkVideoEncodeH265DpbSlotInfoKHR *tmp_src50 = (void *)pnext;
                        memcpy(tmp_dst49, tmp_src50, sizeof(VkVideoEncodeH265DpbSlotInfoKHR));
                        if (tmp_src50->pStdReferenceInfo) {
                           tmp_dst49->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeH265ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst49->pStdReferenceInfo == NULL) goto err;
                           StdVideoEncodeH265ReferenceInfo *tmp_dst51 = (void *)tmp_dst49->pStdReferenceInfo;
                           StdVideoEncodeH265ReferenceInfo *tmp_src52 = (void *)tmp_src50->pStdReferenceInfo;
                           memcpy(tmp_dst51, tmp_src52, sizeof(StdVideoEncodeH265ReferenceInfo));
                        } else {
                           tmp_dst49->pStdReferenceInfo = NULL;
                        }
                     } else {
                        tmp_dst31->pNext = NULL;
                     }
                     break;
                  case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR:
                     if (pnext) {
                        tmp_dst31->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeAV1DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst31->pNext == NULL) goto err;
                        VkVideoEncodeAV1DpbSlotInfoKHR *tmp_dst53 = (void *)tmp_dst31->pNext;
                        VkVideoEncodeAV1DpbSlotInfoKHR *tmp_src54 = (void *)pnext;
                        memcpy(tmp_dst53, tmp_src54, sizeof(VkVideoEncodeAV1DpbSlotInfoKHR));
                        if (tmp_src54->pStdReferenceInfo) {
                           tmp_dst53->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeAV1ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst53->pStdReferenceInfo == NULL) goto err;
                           StdVideoEncodeAV1ReferenceInfo *tmp_dst55 = (void *)tmp_dst53->pStdReferenceInfo;
                           StdVideoEncodeAV1ReferenceInfo *tmp_src56 = (void *)tmp_src54->pStdReferenceInfo;
                           memcpy(tmp_dst55, tmp_src56, sizeof(StdVideoEncodeAV1ReferenceInfo));
                        } else {
                           tmp_dst53->pStdReferenceInfo = NULL;
                        }
                     } else {
                        tmp_dst31->pNext = NULL;
                     }
                     break;
                  case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR:
                     if (pnext) {
                        tmp_dst31->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoReferenceIntraRefreshInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst31->pNext == NULL) goto err;
                        VkVideoReferenceIntraRefreshInfoKHR *tmp_dst57 = (void *)tmp_dst31->pNext;
                        VkVideoReferenceIntraRefreshInfoKHR *tmp_src58 = (void *)pnext;
                        memcpy(tmp_dst57, tmp_src58, sizeof(VkVideoReferenceIntraRefreshInfoKHR));
                     } else {
                        tmp_dst31->pNext = NULL;
                     }
                     break;
                  }
               }
               if (tmp_src32->pPictureResource) {
                  tmp_dst31->pPictureResource = vk_zalloc(queue->alloc, sizeof(VkVideoPictureResourceInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst31->pPictureResource == NULL) goto err;
                  VkVideoPictureResourceInfoKHR *tmp_dst59 = (void *)tmp_dst31->pPictureResource;
                  VkVideoPictureResourceInfoKHR *tmp_src60 = (void *)tmp_src32->pPictureResource;
                  memcpy(tmp_dst59, tmp_src60, sizeof(VkVideoPictureResourceInfoKHR));
               } else {
                  tmp_dst31->pPictureResource = NULL;
               }
               }
            } else {
               tmp_dst1->pReferenceSlots = NULL;
            }
         } else {
            cmd->u.begin_video_coding_khr.begin_info = NULL;
         }

         list_addtail(&cmd->cmd_link, &queue->cmds);
         return VK_SUCCESS;

err:
         if (cmd)
            vk_free_cmd_begin_video_coding_khr(queue, cmd);
         return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_control_video_coding_khr(struct vk_cmd_queue *queue,
                                     struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.control_video_coding_khr.coding_control_info) {
      const VkBaseInStructure *pnext1 = cmd->u.control_video_coding_khr.coding_control_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR: {
            VkVideoEncodeRateControlLayerInfoKHR *pLayers2 = (void *)(((VkVideoEncodeRateControlInfoKHR *)pnext1)->pLayers);
            if (((VkVideoEncodeRateControlInfoKHR *)pnext1)->layerCount) {
               const VkBaseInStructure *pnext3 = pLayers2->pNext;
               if (pnext3) {
                  switch ((int32_t)pnext3->sType) {
                  case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR: {
                     vk_free(queue->alloc, (void*)pnext3);
                     break;
                  }
                  case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR: {
                     vk_free(queue->alloc, (void*)pnext3);
                     break;
                  }
                  case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR: {
                     vk_free(queue->alloc, (void*)pnext3);
                     break;
                  }
                  }
               }
            }
            vk_free(queue->alloc, pLayers2);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
   }
   vk_free(queue->alloc, (void*)cmd->u.control_video_coding_khr.coding_control_info);

}

VkResult vk_enqueue_cmd_control_video_coding_khr(struct vk_cmd_queue *queue
, const VkVideoCodingControlInfoKHR* pCodingControlInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_CONTROL_VIDEO_CODING_KHR], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_CONTROL_VIDEO_CODING_KHR;
   if (pCodingControlInfo) {
      cmd->u.control_video_coding_khr.coding_control_info = vk_zalloc(queue->alloc, sizeof(VkVideoCodingControlInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.control_video_coding_khr.coding_control_info == NULL) goto err;
      VkVideoCodingControlInfoKHR *tmp_dst1 = (void *)cmd->u.control_video_coding_khr.coding_control_info;
      VkVideoCodingControlInfoKHR *tmp_src2 = (void *)pCodingControlInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkVideoCodingControlInfoKHR));
      const VkBaseInStructure *pnext = tmp_dst1->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeQualityLevelInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkVideoEncodeQualityLevelInfoKHR *tmp_dst3 = (void *)tmp_dst1->pNext;
               VkVideoEncodeQualityLevelInfoKHR *tmp_src4 = (void *)pnext;
               memcpy(tmp_dst3, tmp_src4, sizeof(VkVideoEncodeQualityLevelInfoKHR));
            } else {
               tmp_dst1->pNext = NULL;
            }
            break;
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeRateControlInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkVideoEncodeRateControlInfoKHR *tmp_dst5 = (void *)tmp_dst1->pNext;
               VkVideoEncodeRateControlInfoKHR *tmp_src6 = (void *)pnext;
               memcpy(tmp_dst5, tmp_src6, sizeof(VkVideoEncodeRateControlInfoKHR));
               if (tmp_src6->pLayers) {
                  tmp_dst5->pLayers = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeRateControlLayerInfoKHR) * tmp_src6->layerCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst5->pLayers == NULL) goto err;
                  VkVideoEncodeRateControlLayerInfoKHR *tmp_dst7 = (void *)tmp_dst5->pLayers;
                  VkVideoEncodeRateControlLayerInfoKHR *tmp_src8 = (void *)tmp_src6->pLayers;
                  memcpy(tmp_dst7, tmp_src8, sizeof(VkVideoEncodeRateControlLayerInfoKHR) * tmp_src6->layerCount);
                  for (uint32_t i9 = 0; i9 < tmp_src6->layerCount; i9++) {
                     VkVideoEncodeRateControlLayerInfoKHR *tmp_dst10 = tmp_dst7 + i9; (void)tmp_dst10;
                     VkVideoEncodeRateControlLayerInfoKHR *tmp_src11 = tmp_src8 + i9; (void)tmp_src11;
                     const VkBaseInStructure *pnext = tmp_dst10->pNext;
                     if (pnext) {
                        switch ((int32_t)pnext->sType) {
                        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR:
                           if (pnext) {
                              tmp_dst10->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH264RateControlLayerInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst10->pNext == NULL) goto err;
                              VkVideoEncodeH264RateControlLayerInfoKHR *tmp_dst12 = (void *)tmp_dst10->pNext;
                              VkVideoEncodeH264RateControlLayerInfoKHR *tmp_src13 = (void *)pnext;
                              memcpy(tmp_dst12, tmp_src13, sizeof(VkVideoEncodeH264RateControlLayerInfoKHR));
                           } else {
                              tmp_dst10->pNext = NULL;
                           }
                           break;
                        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR:
                           if (pnext) {
                              tmp_dst10->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH265RateControlLayerInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst10->pNext == NULL) goto err;
                              VkVideoEncodeH265RateControlLayerInfoKHR *tmp_dst14 = (void *)tmp_dst10->pNext;
                              VkVideoEncodeH265RateControlLayerInfoKHR *tmp_src15 = (void *)pnext;
                              memcpy(tmp_dst14, tmp_src15, sizeof(VkVideoEncodeH265RateControlLayerInfoKHR));
                           } else {
                              tmp_dst10->pNext = NULL;
                           }
                           break;
                        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR:
                           if (pnext) {
                              tmp_dst10->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeAV1RateControlLayerInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst10->pNext == NULL) goto err;
                              VkVideoEncodeAV1RateControlLayerInfoKHR *tmp_dst16 = (void *)tmp_dst10->pNext;
                              VkVideoEncodeAV1RateControlLayerInfoKHR *tmp_src17 = (void *)pnext;
                              memcpy(tmp_dst16, tmp_src17, sizeof(VkVideoEncodeAV1RateControlLayerInfoKHR));
                           } else {
                              tmp_dst10->pNext = NULL;
                           }
                           break;
                        }
                     }
                     }
                  } else {
                     tmp_dst5->pLayers = NULL;
                  }
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH264RateControlInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkVideoEncodeH264RateControlInfoKHR *tmp_dst18 = (void *)tmp_dst1->pNext;
                  VkVideoEncodeH264RateControlInfoKHR *tmp_src19 = (void *)pnext;
                  memcpy(tmp_dst18, tmp_src19, sizeof(VkVideoEncodeH264RateControlInfoKHR));
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH265RateControlInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkVideoEncodeH265RateControlInfoKHR *tmp_dst20 = (void *)tmp_dst1->pNext;
                  VkVideoEncodeH265RateControlInfoKHR *tmp_src21 = (void *)pnext;
                  memcpy(tmp_dst20, tmp_src21, sizeof(VkVideoEncodeH265RateControlInfoKHR));
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeAV1RateControlInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkVideoEncodeAV1RateControlInfoKHR *tmp_dst22 = (void *)tmp_dst1->pNext;
                  VkVideoEncodeAV1RateControlInfoKHR *tmp_src23 = (void *)pnext;
                  memcpy(tmp_dst22, tmp_src23, sizeof(VkVideoEncodeAV1RateControlInfoKHR));
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            }
         }
      } else {
         cmd->u.control_video_coding_khr.coding_control_info = NULL;
      }

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_control_video_coding_khr(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_end_video_coding_khr(struct vk_cmd_queue *queue,
                                 struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.end_video_coding_khr.end_coding_info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.end_video_coding_khr.end_coding_info);

}

VkResult vk_enqueue_cmd_end_video_coding_khr(struct vk_cmd_queue *queue
, const VkVideoEndCodingInfoKHR* pEndCodingInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_END_VIDEO_CODING_KHR], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_END_VIDEO_CODING_KHR;
   if (pEndCodingInfo) {
      cmd->u.end_video_coding_khr.end_coding_info = vk_zalloc(queue->alloc, sizeof(VkVideoEndCodingInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.end_video_coding_khr.end_coding_info == NULL) goto err;
      VkVideoEndCodingInfoKHR *tmp_dst1 = (void *)cmd->u.end_video_coding_khr.end_coding_info;
      VkVideoEndCodingInfoKHR *tmp_src2 = (void *)pEndCodingInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkVideoEndCodingInfoKHR));
   } else {
      cmd->u.end_video_coding_khr.end_coding_info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_end_video_coding_khr(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_encode_video_khr(struct vk_cmd_queue *queue,
                             struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.encode_video_khr.encode_info) {
      const VkBaseInStructure *pnext1 = cmd->u.encode_video_khr.encode_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_INFO_KHR: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR: {
            VkVideoEncodeH264NaluSliceInfoKHR *pNaluSliceEntries2 = (void *)(((VkVideoEncodeH264PictureInfoKHR *)pnext1)->pNaluSliceEntries);
            if (((VkVideoEncodeH264PictureInfoKHR *)pnext1)->naluSliceEntryCount) {
               StdVideoEncodeH264SliceHeader *pStdSliceHeader3 = (void *)(pNaluSliceEntries2->pStdSliceHeader);
               vk_free(queue->alloc, pStdSliceHeader3);
            }
            vk_free(queue->alloc, pNaluSliceEntries2);
            StdVideoEncodeH264PictureInfo *pStdPictureInfo4 = (void *)(((VkVideoEncodeH264PictureInfoKHR *)pnext1)->pStdPictureInfo);
            vk_free(queue->alloc, pStdPictureInfo4);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR: {
            VkVideoEncodeH265NaluSliceSegmentInfoKHR *pNaluSliceSegmentEntries5 = (void *)(((VkVideoEncodeH265PictureInfoKHR *)pnext1)->pNaluSliceSegmentEntries);
            if (((VkVideoEncodeH265PictureInfoKHR *)pnext1)->naluSliceSegmentEntryCount) {
               StdVideoEncodeH265SliceSegmentHeader *pStdSliceSegmentHeader6 = (void *)(pNaluSliceSegmentEntries5->pStdSliceSegmentHeader);
               vk_free(queue->alloc, pStdSliceSegmentHeader6);
            }
            vk_free(queue->alloc, pNaluSliceSegmentEntries5);
            StdVideoEncodeH265PictureInfo *pStdPictureInfo7 = (void *)(((VkVideoEncodeH265PictureInfoKHR *)pnext1)->pStdPictureInfo);
            vk_free(queue->alloc, pStdPictureInfo7);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PICTURE_INFO_KHR: {
            StdVideoEncodeAV1PictureInfo *pStdPictureInfo8 = (void *)(((VkVideoEncodeAV1PictureInfoKHR *)pnext1)->pStdPictureInfo);
            vk_free(queue->alloc, pStdPictureInfo8);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_INFO_KHR: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
      VkVideoReferenceSlotInfoKHR *pSetupReferenceSlot9 = (void *)(cmd->u.encode_video_khr.encode_info->pSetupReferenceSlot);
      if (pSetupReferenceSlot9) {
         const VkBaseInStructure *pnext10 = pSetupReferenceSlot9->pNext;
         if (pnext10) {
            switch ((int32_t)pnext10->sType) {
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR: {
               StdVideoDecodeH264ReferenceInfo *pStdReferenceInfo11 = (void *)(((VkVideoDecodeH264DpbSlotInfoKHR *)pnext10)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo11);
               vk_free(queue->alloc, (void*)pnext10);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR: {
               StdVideoDecodeH265ReferenceInfo *pStdReferenceInfo12 = (void *)(((VkVideoDecodeH265DpbSlotInfoKHR *)pnext10)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo12);
               vk_free(queue->alloc, (void*)pnext10);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR: {
               StdVideoDecodeAV1ReferenceInfo *pStdReferenceInfo13 = (void *)(((VkVideoDecodeAV1DpbSlotInfoKHR *)pnext10)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo13);
               vk_free(queue->alloc, (void*)pnext10);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR: {
               StdVideoEncodeH264ReferenceInfo *pStdReferenceInfo14 = (void *)(((VkVideoEncodeH264DpbSlotInfoKHR *)pnext10)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo14);
               vk_free(queue->alloc, (void*)pnext10);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR: {
               StdVideoEncodeH265ReferenceInfo *pStdReferenceInfo15 = (void *)(((VkVideoEncodeH265DpbSlotInfoKHR *)pnext10)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo15);
               vk_free(queue->alloc, (void*)pnext10);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR: {
               StdVideoEncodeAV1ReferenceInfo *pStdReferenceInfo16 = (void *)(((VkVideoEncodeAV1DpbSlotInfoKHR *)pnext10)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo16);
               vk_free(queue->alloc, (void*)pnext10);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR: {
               vk_free(queue->alloc, (void*)pnext10);
               break;
            }
            }
         }
         VkVideoPictureResourceInfoKHR *pPictureResource17 = (void *)(pSetupReferenceSlot9->pPictureResource);
         if (pPictureResource17) {
         }
         vk_free(queue->alloc, pPictureResource17);
      }
      vk_free(queue->alloc, pSetupReferenceSlot9);
      VkVideoReferenceSlotInfoKHR *pReferenceSlots18 = (void *)(cmd->u.encode_video_khr.encode_info->pReferenceSlots);
      if (cmd->u.encode_video_khr.encode_info->referenceSlotCount) {
         const VkBaseInStructure *pnext19 = pReferenceSlots18->pNext;
         if (pnext19) {
            switch ((int32_t)pnext19->sType) {
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR: {
               StdVideoDecodeH264ReferenceInfo *pStdReferenceInfo20 = (void *)(((VkVideoDecodeH264DpbSlotInfoKHR *)pnext19)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo20);
               vk_free(queue->alloc, (void*)pnext19);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR: {
               StdVideoDecodeH265ReferenceInfo *pStdReferenceInfo21 = (void *)(((VkVideoDecodeH265DpbSlotInfoKHR *)pnext19)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo21);
               vk_free(queue->alloc, (void*)pnext19);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR: {
               StdVideoDecodeAV1ReferenceInfo *pStdReferenceInfo22 = (void *)(((VkVideoDecodeAV1DpbSlotInfoKHR *)pnext19)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo22);
               vk_free(queue->alloc, (void*)pnext19);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR: {
               StdVideoEncodeH264ReferenceInfo *pStdReferenceInfo23 = (void *)(((VkVideoEncodeH264DpbSlotInfoKHR *)pnext19)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo23);
               vk_free(queue->alloc, (void*)pnext19);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR: {
               StdVideoEncodeH265ReferenceInfo *pStdReferenceInfo24 = (void *)(((VkVideoEncodeH265DpbSlotInfoKHR *)pnext19)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo24);
               vk_free(queue->alloc, (void*)pnext19);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR: {
               StdVideoEncodeAV1ReferenceInfo *pStdReferenceInfo25 = (void *)(((VkVideoEncodeAV1DpbSlotInfoKHR *)pnext19)->pStdReferenceInfo);
               vk_free(queue->alloc, pStdReferenceInfo25);
               vk_free(queue->alloc, (void*)pnext19);
               break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR: {
               vk_free(queue->alloc, (void*)pnext19);
               break;
            }
            }
         }
         VkVideoPictureResourceInfoKHR *pPictureResource26 = (void *)(pReferenceSlots18->pPictureResource);
         if (pPictureResource26) {
         }
         vk_free(queue->alloc, pPictureResource26);
      }
      vk_free(queue->alloc, pReferenceSlots18);
   }
   vk_free(queue->alloc, (void*)cmd->u.encode_video_khr.encode_info);

}

VkResult vk_enqueue_cmd_encode_video_khr(struct vk_cmd_queue *queue
, const VkVideoEncodeInfoKHR* pEncodeInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_ENCODE_VIDEO_KHR], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_ENCODE_VIDEO_KHR;
   if (pEncodeInfo) {
      cmd->u.encode_video_khr.encode_info = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.encode_video_khr.encode_info == NULL) goto err;
      VkVideoEncodeInfoKHR *tmp_dst1 = (void *)cmd->u.encode_video_khr.encode_info;
      VkVideoEncodeInfoKHR *tmp_src2 = (void *)pEncodeInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkVideoEncodeInfoKHR));
      const VkBaseInStructure *pnext = tmp_dst1->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoInlineQueryInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkVideoInlineQueryInfoKHR *tmp_dst3 = (void *)tmp_dst1->pNext;
               VkVideoInlineQueryInfoKHR *tmp_src4 = (void *)pnext;
               memcpy(tmp_dst3, tmp_src4, sizeof(VkVideoInlineQueryInfoKHR));
            } else {
               tmp_dst1->pNext = NULL;
            }
            break;
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_INFO_KHR:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeQuantizationMapInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkVideoEncodeQuantizationMapInfoKHR *tmp_dst5 = (void *)tmp_dst1->pNext;
               VkVideoEncodeQuantizationMapInfoKHR *tmp_src6 = (void *)pnext;
               memcpy(tmp_dst5, tmp_src6, sizeof(VkVideoEncodeQuantizationMapInfoKHR));
            } else {
               tmp_dst1->pNext = NULL;
            }
            break;
         case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH264PictureInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkVideoEncodeH264PictureInfoKHR *tmp_dst7 = (void *)tmp_dst1->pNext;
               VkVideoEncodeH264PictureInfoKHR *tmp_src8 = (void *)pnext;
               memcpy(tmp_dst7, tmp_src8, sizeof(VkVideoEncodeH264PictureInfoKHR));
               if (tmp_src8->pNaluSliceEntries) {
                  tmp_dst7->pNaluSliceEntries = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH264NaluSliceInfoKHR) * tmp_src8->naluSliceEntryCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst7->pNaluSliceEntries == NULL) goto err;
                  VkVideoEncodeH264NaluSliceInfoKHR *tmp_dst9 = (void *)tmp_dst7->pNaluSliceEntries;
                  VkVideoEncodeH264NaluSliceInfoKHR *tmp_src10 = (void *)tmp_src8->pNaluSliceEntries;
                  memcpy(tmp_dst9, tmp_src10, sizeof(VkVideoEncodeH264NaluSliceInfoKHR) * tmp_src8->naluSliceEntryCount);
                  for (uint32_t i11 = 0; i11 < tmp_src8->naluSliceEntryCount; i11++) {
                     VkVideoEncodeH264NaluSliceInfoKHR *tmp_dst12 = tmp_dst9 + i11; (void)tmp_dst12;
                     VkVideoEncodeH264NaluSliceInfoKHR *tmp_src13 = tmp_src10 + i11; (void)tmp_src13;
                     if (tmp_src13->pStdSliceHeader) {
                        tmp_dst12->pStdSliceHeader = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeH264SliceHeader), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst12->pStdSliceHeader == NULL) goto err;
                        StdVideoEncodeH264SliceHeader *tmp_dst14 = (void *)tmp_dst12->pStdSliceHeader;
                        StdVideoEncodeH264SliceHeader *tmp_src15 = (void *)tmp_src13->pStdSliceHeader;
                        memcpy(tmp_dst14, tmp_src15, sizeof(StdVideoEncodeH264SliceHeader));
                     } else {
                        tmp_dst12->pStdSliceHeader = NULL;
                     }
                     }
                  } else {
                     tmp_dst7->pNaluSliceEntries = NULL;
                  }
                  if (tmp_src8->pStdPictureInfo) {
                     tmp_dst7->pStdPictureInfo = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeH264PictureInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst7->pStdPictureInfo == NULL) goto err;
                     StdVideoEncodeH264PictureInfo *tmp_dst16 = (void *)tmp_dst7->pStdPictureInfo;
                     StdVideoEncodeH264PictureInfo *tmp_src17 = (void *)tmp_src8->pStdPictureInfo;
                     memcpy(tmp_dst16, tmp_src17, sizeof(StdVideoEncodeH264PictureInfo));
                  } else {
                     tmp_dst7->pStdPictureInfo = NULL;
                  }
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH265PictureInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkVideoEncodeH265PictureInfoKHR *tmp_dst18 = (void *)tmp_dst1->pNext;
                  VkVideoEncodeH265PictureInfoKHR *tmp_src19 = (void *)pnext;
                  memcpy(tmp_dst18, tmp_src19, sizeof(VkVideoEncodeH265PictureInfoKHR));
                  if (tmp_src19->pNaluSliceSegmentEntries) {
                     tmp_dst18->pNaluSliceSegmentEntries = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH265NaluSliceSegmentInfoKHR) * tmp_src19->naluSliceSegmentEntryCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst18->pNaluSliceSegmentEntries == NULL) goto err;
                     VkVideoEncodeH265NaluSliceSegmentInfoKHR *tmp_dst20 = (void *)tmp_dst18->pNaluSliceSegmentEntries;
                     VkVideoEncodeH265NaluSliceSegmentInfoKHR *tmp_src21 = (void *)tmp_src19->pNaluSliceSegmentEntries;
                     memcpy(tmp_dst20, tmp_src21, sizeof(VkVideoEncodeH265NaluSliceSegmentInfoKHR) * tmp_src19->naluSliceSegmentEntryCount);
                     for (uint32_t i22 = 0; i22 < tmp_src19->naluSliceSegmentEntryCount; i22++) {
                        VkVideoEncodeH265NaluSliceSegmentInfoKHR *tmp_dst23 = tmp_dst20 + i22; (void)tmp_dst23;
                        VkVideoEncodeH265NaluSliceSegmentInfoKHR *tmp_src24 = tmp_src21 + i22; (void)tmp_src24;
                        if (tmp_src24->pStdSliceSegmentHeader) {
                           tmp_dst23->pStdSliceSegmentHeader = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeH265SliceSegmentHeader), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst23->pStdSliceSegmentHeader == NULL) goto err;
                           StdVideoEncodeH265SliceSegmentHeader *tmp_dst25 = (void *)tmp_dst23->pStdSliceSegmentHeader;
                           StdVideoEncodeH265SliceSegmentHeader *tmp_src26 = (void *)tmp_src24->pStdSliceSegmentHeader;
                           memcpy(tmp_dst25, tmp_src26, sizeof(StdVideoEncodeH265SliceSegmentHeader));
                        } else {
                           tmp_dst23->pStdSliceSegmentHeader = NULL;
                        }
                        }
                     } else {
                        tmp_dst18->pNaluSliceSegmentEntries = NULL;
                     }
                     if (tmp_src19->pStdPictureInfo) {
                        tmp_dst18->pStdPictureInfo = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeH265PictureInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst18->pStdPictureInfo == NULL) goto err;
                        StdVideoEncodeH265PictureInfo *tmp_dst27 = (void *)tmp_dst18->pStdPictureInfo;
                        StdVideoEncodeH265PictureInfo *tmp_src28 = (void *)tmp_src19->pStdPictureInfo;
                        memcpy(tmp_dst27, tmp_src28, sizeof(StdVideoEncodeH265PictureInfo));
                     } else {
                        tmp_dst18->pStdPictureInfo = NULL;
                     }
                  } else {
                     tmp_dst1->pNext = NULL;
                  }
                  break;
               case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PICTURE_INFO_KHR:
                  if (pnext) {
                     tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeAV1PictureInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst1->pNext == NULL) goto err;
                     VkVideoEncodeAV1PictureInfoKHR *tmp_dst29 = (void *)tmp_dst1->pNext;
                     VkVideoEncodeAV1PictureInfoKHR *tmp_src30 = (void *)pnext;
                     memcpy(tmp_dst29, tmp_src30, sizeof(VkVideoEncodeAV1PictureInfoKHR));
                     if (tmp_src30->pStdPictureInfo) {
                        tmp_dst29->pStdPictureInfo = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeAV1PictureInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst29->pStdPictureInfo == NULL) goto err;
                        StdVideoEncodeAV1PictureInfo *tmp_dst31 = (void *)tmp_dst29->pStdPictureInfo;
                        StdVideoEncodeAV1PictureInfo *tmp_src32 = (void *)tmp_src30->pStdPictureInfo;
                        memcpy(tmp_dst31, tmp_src32, sizeof(StdVideoEncodeAV1PictureInfo));
                     } else {
                        tmp_dst29->pStdPictureInfo = NULL;
                     }
                  } else {
                     tmp_dst1->pNext = NULL;
                  }
                  break;
               case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_INFO_KHR:
                  if (pnext) {
                     tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeIntraRefreshInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst1->pNext == NULL) goto err;
                     VkVideoEncodeIntraRefreshInfoKHR *tmp_dst33 = (void *)tmp_dst1->pNext;
                     VkVideoEncodeIntraRefreshInfoKHR *tmp_src34 = (void *)pnext;
                     memcpy(tmp_dst33, tmp_src34, sizeof(VkVideoEncodeIntraRefreshInfoKHR));
                  } else {
                     tmp_dst1->pNext = NULL;
                  }
                  break;
               }
            }
            if (tmp_src2->pSetupReferenceSlot) {
               tmp_dst1->pSetupReferenceSlot = vk_zalloc(queue->alloc, sizeof(VkVideoReferenceSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pSetupReferenceSlot == NULL) goto err;
               VkVideoReferenceSlotInfoKHR *tmp_dst35 = (void *)tmp_dst1->pSetupReferenceSlot;
               VkVideoReferenceSlotInfoKHR *tmp_src36 = (void *)tmp_src2->pSetupReferenceSlot;
               memcpy(tmp_dst35, tmp_src36, sizeof(VkVideoReferenceSlotInfoKHR));
               const VkBaseInStructure *pnext = tmp_dst35->pNext;
               if (pnext) {
                  switch ((int32_t)pnext->sType) {
                  case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
                     if (pnext) {
                        tmp_dst35->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeH264DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst35->pNext == NULL) goto err;
                        VkVideoDecodeH264DpbSlotInfoKHR *tmp_dst37 = (void *)tmp_dst35->pNext;
                        VkVideoDecodeH264DpbSlotInfoKHR *tmp_src38 = (void *)pnext;
                        memcpy(tmp_dst37, tmp_src38, sizeof(VkVideoDecodeH264DpbSlotInfoKHR));
                        if (tmp_src38->pStdReferenceInfo) {
                           tmp_dst37->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeH264ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst37->pStdReferenceInfo == NULL) goto err;
                           StdVideoDecodeH264ReferenceInfo *tmp_dst39 = (void *)tmp_dst37->pStdReferenceInfo;
                           StdVideoDecodeH264ReferenceInfo *tmp_src40 = (void *)tmp_src38->pStdReferenceInfo;
                           memcpy(tmp_dst39, tmp_src40, sizeof(StdVideoDecodeH264ReferenceInfo));
                        } else {
                           tmp_dst37->pStdReferenceInfo = NULL;
                        }
                     } else {
                        tmp_dst35->pNext = NULL;
                     }
                     break;
                  case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR:
                     if (pnext) {
                        tmp_dst35->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeH265DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst35->pNext == NULL) goto err;
                        VkVideoDecodeH265DpbSlotInfoKHR *tmp_dst41 = (void *)tmp_dst35->pNext;
                        VkVideoDecodeH265DpbSlotInfoKHR *tmp_src42 = (void *)pnext;
                        memcpy(tmp_dst41, tmp_src42, sizeof(VkVideoDecodeH265DpbSlotInfoKHR));
                        if (tmp_src42->pStdReferenceInfo) {
                           tmp_dst41->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeH265ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst41->pStdReferenceInfo == NULL) goto err;
                           StdVideoDecodeH265ReferenceInfo *tmp_dst43 = (void *)tmp_dst41->pStdReferenceInfo;
                           StdVideoDecodeH265ReferenceInfo *tmp_src44 = (void *)tmp_src42->pStdReferenceInfo;
                           memcpy(tmp_dst43, tmp_src44, sizeof(StdVideoDecodeH265ReferenceInfo));
                        } else {
                           tmp_dst41->pStdReferenceInfo = NULL;
                        }
                     } else {
                        tmp_dst35->pNext = NULL;
                     }
                     break;
                  case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR:
                     if (pnext) {
                        tmp_dst35->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeAV1DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst35->pNext == NULL) goto err;
                        VkVideoDecodeAV1DpbSlotInfoKHR *tmp_dst45 = (void *)tmp_dst35->pNext;
                        VkVideoDecodeAV1DpbSlotInfoKHR *tmp_src46 = (void *)pnext;
                        memcpy(tmp_dst45, tmp_src46, sizeof(VkVideoDecodeAV1DpbSlotInfoKHR));
                        if (tmp_src46->pStdReferenceInfo) {
                           tmp_dst45->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeAV1ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst45->pStdReferenceInfo == NULL) goto err;
                           StdVideoDecodeAV1ReferenceInfo *tmp_dst47 = (void *)tmp_dst45->pStdReferenceInfo;
                           StdVideoDecodeAV1ReferenceInfo *tmp_src48 = (void *)tmp_src46->pStdReferenceInfo;
                           memcpy(tmp_dst47, tmp_src48, sizeof(StdVideoDecodeAV1ReferenceInfo));
                        } else {
                           tmp_dst45->pStdReferenceInfo = NULL;
                        }
                     } else {
                        tmp_dst35->pNext = NULL;
                     }
                     break;
                  case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR:
                     if (pnext) {
                        tmp_dst35->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH264DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst35->pNext == NULL) goto err;
                        VkVideoEncodeH264DpbSlotInfoKHR *tmp_dst49 = (void *)tmp_dst35->pNext;
                        VkVideoEncodeH264DpbSlotInfoKHR *tmp_src50 = (void *)pnext;
                        memcpy(tmp_dst49, tmp_src50, sizeof(VkVideoEncodeH264DpbSlotInfoKHR));
                        if (tmp_src50->pStdReferenceInfo) {
                           tmp_dst49->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeH264ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst49->pStdReferenceInfo == NULL) goto err;
                           StdVideoEncodeH264ReferenceInfo *tmp_dst51 = (void *)tmp_dst49->pStdReferenceInfo;
                           StdVideoEncodeH264ReferenceInfo *tmp_src52 = (void *)tmp_src50->pStdReferenceInfo;
                           memcpy(tmp_dst51, tmp_src52, sizeof(StdVideoEncodeH264ReferenceInfo));
                        } else {
                           tmp_dst49->pStdReferenceInfo = NULL;
                        }
                     } else {
                        tmp_dst35->pNext = NULL;
                     }
                     break;
                  case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR:
                     if (pnext) {
                        tmp_dst35->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH265DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst35->pNext == NULL) goto err;
                        VkVideoEncodeH265DpbSlotInfoKHR *tmp_dst53 = (void *)tmp_dst35->pNext;
                        VkVideoEncodeH265DpbSlotInfoKHR *tmp_src54 = (void *)pnext;
                        memcpy(tmp_dst53, tmp_src54, sizeof(VkVideoEncodeH265DpbSlotInfoKHR));
                        if (tmp_src54->pStdReferenceInfo) {
                           tmp_dst53->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeH265ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst53->pStdReferenceInfo == NULL) goto err;
                           StdVideoEncodeH265ReferenceInfo *tmp_dst55 = (void *)tmp_dst53->pStdReferenceInfo;
                           StdVideoEncodeH265ReferenceInfo *tmp_src56 = (void *)tmp_src54->pStdReferenceInfo;
                           memcpy(tmp_dst55, tmp_src56, sizeof(StdVideoEncodeH265ReferenceInfo));
                        } else {
                           tmp_dst53->pStdReferenceInfo = NULL;
                        }
                     } else {
                        tmp_dst35->pNext = NULL;
                     }
                     break;
                  case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR:
                     if (pnext) {
                        tmp_dst35->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeAV1DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst35->pNext == NULL) goto err;
                        VkVideoEncodeAV1DpbSlotInfoKHR *tmp_dst57 = (void *)tmp_dst35->pNext;
                        VkVideoEncodeAV1DpbSlotInfoKHR *tmp_src58 = (void *)pnext;
                        memcpy(tmp_dst57, tmp_src58, sizeof(VkVideoEncodeAV1DpbSlotInfoKHR));
                        if (tmp_src58->pStdReferenceInfo) {
                           tmp_dst57->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeAV1ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst57->pStdReferenceInfo == NULL) goto err;
                           StdVideoEncodeAV1ReferenceInfo *tmp_dst59 = (void *)tmp_dst57->pStdReferenceInfo;
                           StdVideoEncodeAV1ReferenceInfo *tmp_src60 = (void *)tmp_src58->pStdReferenceInfo;
                           memcpy(tmp_dst59, tmp_src60, sizeof(StdVideoEncodeAV1ReferenceInfo));
                        } else {
                           tmp_dst57->pStdReferenceInfo = NULL;
                        }
                     } else {
                        tmp_dst35->pNext = NULL;
                     }
                     break;
                  case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR:
                     if (pnext) {
                        tmp_dst35->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoReferenceIntraRefreshInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst35->pNext == NULL) goto err;
                        VkVideoReferenceIntraRefreshInfoKHR *tmp_dst61 = (void *)tmp_dst35->pNext;
                        VkVideoReferenceIntraRefreshInfoKHR *tmp_src62 = (void *)pnext;
                        memcpy(tmp_dst61, tmp_src62, sizeof(VkVideoReferenceIntraRefreshInfoKHR));
                     } else {
                        tmp_dst35->pNext = NULL;
                     }
                     break;
                  }
               }
               if (tmp_src36->pPictureResource) {
                  tmp_dst35->pPictureResource = vk_zalloc(queue->alloc, sizeof(VkVideoPictureResourceInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst35->pPictureResource == NULL) goto err;
                  VkVideoPictureResourceInfoKHR *tmp_dst63 = (void *)tmp_dst35->pPictureResource;
                  VkVideoPictureResourceInfoKHR *tmp_src64 = (void *)tmp_src36->pPictureResource;
                  memcpy(tmp_dst63, tmp_src64, sizeof(VkVideoPictureResourceInfoKHR));
               } else {
                  tmp_dst35->pPictureResource = NULL;
               }
            } else {
               tmp_dst1->pSetupReferenceSlot = NULL;
            }
            if (tmp_src2->pReferenceSlots) {
               tmp_dst1->pReferenceSlots = vk_zalloc(queue->alloc, sizeof(VkVideoReferenceSlotInfoKHR) * tmp_src2->referenceSlotCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pReferenceSlots == NULL) goto err;
               VkVideoReferenceSlotInfoKHR *tmp_dst65 = (void *)tmp_dst1->pReferenceSlots;
               VkVideoReferenceSlotInfoKHR *tmp_src66 = (void *)tmp_src2->pReferenceSlots;
               memcpy(tmp_dst65, tmp_src66, sizeof(VkVideoReferenceSlotInfoKHR) * tmp_src2->referenceSlotCount);
               for (uint32_t i67 = 0; i67 < tmp_src2->referenceSlotCount; i67++) {
                  VkVideoReferenceSlotInfoKHR *tmp_dst68 = tmp_dst65 + i67; (void)tmp_dst68;
                  VkVideoReferenceSlotInfoKHR *tmp_src69 = tmp_src66 + i67; (void)tmp_src69;
                  const VkBaseInStructure *pnext = tmp_dst68->pNext;
                  if (pnext) {
                     switch ((int32_t)pnext->sType) {
                     case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
                        if (pnext) {
                           tmp_dst68->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeH264DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst68->pNext == NULL) goto err;
                           VkVideoDecodeH264DpbSlotInfoKHR *tmp_dst70 = (void *)tmp_dst68->pNext;
                           VkVideoDecodeH264DpbSlotInfoKHR *tmp_src71 = (void *)pnext;
                           memcpy(tmp_dst70, tmp_src71, sizeof(VkVideoDecodeH264DpbSlotInfoKHR));
                           if (tmp_src71->pStdReferenceInfo) {
                              tmp_dst70->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeH264ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst70->pStdReferenceInfo == NULL) goto err;
                              StdVideoDecodeH264ReferenceInfo *tmp_dst72 = (void *)tmp_dst70->pStdReferenceInfo;
                              StdVideoDecodeH264ReferenceInfo *tmp_src73 = (void *)tmp_src71->pStdReferenceInfo;
                              memcpy(tmp_dst72, tmp_src73, sizeof(StdVideoDecodeH264ReferenceInfo));
                           } else {
                              tmp_dst70->pStdReferenceInfo = NULL;
                           }
                        } else {
                           tmp_dst68->pNext = NULL;
                        }
                        break;
                     case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR:
                        if (pnext) {
                           tmp_dst68->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeH265DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst68->pNext == NULL) goto err;
                           VkVideoDecodeH265DpbSlotInfoKHR *tmp_dst74 = (void *)tmp_dst68->pNext;
                           VkVideoDecodeH265DpbSlotInfoKHR *tmp_src75 = (void *)pnext;
                           memcpy(tmp_dst74, tmp_src75, sizeof(VkVideoDecodeH265DpbSlotInfoKHR));
                           if (tmp_src75->pStdReferenceInfo) {
                              tmp_dst74->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeH265ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst74->pStdReferenceInfo == NULL) goto err;
                              StdVideoDecodeH265ReferenceInfo *tmp_dst76 = (void *)tmp_dst74->pStdReferenceInfo;
                              StdVideoDecodeH265ReferenceInfo *tmp_src77 = (void *)tmp_src75->pStdReferenceInfo;
                              memcpy(tmp_dst76, tmp_src77, sizeof(StdVideoDecodeH265ReferenceInfo));
                           } else {
                              tmp_dst74->pStdReferenceInfo = NULL;
                           }
                        } else {
                           tmp_dst68->pNext = NULL;
                        }
                        break;
                     case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR:
                        if (pnext) {
                           tmp_dst68->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoDecodeAV1DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst68->pNext == NULL) goto err;
                           VkVideoDecodeAV1DpbSlotInfoKHR *tmp_dst78 = (void *)tmp_dst68->pNext;
                           VkVideoDecodeAV1DpbSlotInfoKHR *tmp_src79 = (void *)pnext;
                           memcpy(tmp_dst78, tmp_src79, sizeof(VkVideoDecodeAV1DpbSlotInfoKHR));
                           if (tmp_src79->pStdReferenceInfo) {
                              tmp_dst78->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoDecodeAV1ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst78->pStdReferenceInfo == NULL) goto err;
                              StdVideoDecodeAV1ReferenceInfo *tmp_dst80 = (void *)tmp_dst78->pStdReferenceInfo;
                              StdVideoDecodeAV1ReferenceInfo *tmp_src81 = (void *)tmp_src79->pStdReferenceInfo;
                              memcpy(tmp_dst80, tmp_src81, sizeof(StdVideoDecodeAV1ReferenceInfo));
                           } else {
                              tmp_dst78->pStdReferenceInfo = NULL;
                           }
                        } else {
                           tmp_dst68->pNext = NULL;
                        }
                        break;
                     case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR:
                        if (pnext) {
                           tmp_dst68->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH264DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst68->pNext == NULL) goto err;
                           VkVideoEncodeH264DpbSlotInfoKHR *tmp_dst82 = (void *)tmp_dst68->pNext;
                           VkVideoEncodeH264DpbSlotInfoKHR *tmp_src83 = (void *)pnext;
                           memcpy(tmp_dst82, tmp_src83, sizeof(VkVideoEncodeH264DpbSlotInfoKHR));
                           if (tmp_src83->pStdReferenceInfo) {
                              tmp_dst82->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeH264ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst82->pStdReferenceInfo == NULL) goto err;
                              StdVideoEncodeH264ReferenceInfo *tmp_dst84 = (void *)tmp_dst82->pStdReferenceInfo;
                              StdVideoEncodeH264ReferenceInfo *tmp_src85 = (void *)tmp_src83->pStdReferenceInfo;
                              memcpy(tmp_dst84, tmp_src85, sizeof(StdVideoEncodeH264ReferenceInfo));
                           } else {
                              tmp_dst82->pStdReferenceInfo = NULL;
                           }
                        } else {
                           tmp_dst68->pNext = NULL;
                        }
                        break;
                     case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR:
                        if (pnext) {
                           tmp_dst68->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeH265DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst68->pNext == NULL) goto err;
                           VkVideoEncodeH265DpbSlotInfoKHR *tmp_dst86 = (void *)tmp_dst68->pNext;
                           VkVideoEncodeH265DpbSlotInfoKHR *tmp_src87 = (void *)pnext;
                           memcpy(tmp_dst86, tmp_src87, sizeof(VkVideoEncodeH265DpbSlotInfoKHR));
                           if (tmp_src87->pStdReferenceInfo) {
                              tmp_dst86->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeH265ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst86->pStdReferenceInfo == NULL) goto err;
                              StdVideoEncodeH265ReferenceInfo *tmp_dst88 = (void *)tmp_dst86->pStdReferenceInfo;
                              StdVideoEncodeH265ReferenceInfo *tmp_src89 = (void *)tmp_src87->pStdReferenceInfo;
                              memcpy(tmp_dst88, tmp_src89, sizeof(StdVideoEncodeH265ReferenceInfo));
                           } else {
                              tmp_dst86->pStdReferenceInfo = NULL;
                           }
                        } else {
                           tmp_dst68->pNext = NULL;
                        }
                        break;
                     case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR:
                        if (pnext) {
                           tmp_dst68->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoEncodeAV1DpbSlotInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst68->pNext == NULL) goto err;
                           VkVideoEncodeAV1DpbSlotInfoKHR *tmp_dst90 = (void *)tmp_dst68->pNext;
                           VkVideoEncodeAV1DpbSlotInfoKHR *tmp_src91 = (void *)pnext;
                           memcpy(tmp_dst90, tmp_src91, sizeof(VkVideoEncodeAV1DpbSlotInfoKHR));
                           if (tmp_src91->pStdReferenceInfo) {
                              tmp_dst90->pStdReferenceInfo = vk_zalloc(queue->alloc, sizeof(StdVideoEncodeAV1ReferenceInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                              if (tmp_dst90->pStdReferenceInfo == NULL) goto err;
                              StdVideoEncodeAV1ReferenceInfo *tmp_dst92 = (void *)tmp_dst90->pStdReferenceInfo;
                              StdVideoEncodeAV1ReferenceInfo *tmp_src93 = (void *)tmp_src91->pStdReferenceInfo;
                              memcpy(tmp_dst92, tmp_src93, sizeof(StdVideoEncodeAV1ReferenceInfo));
                           } else {
                              tmp_dst90->pStdReferenceInfo = NULL;
                           }
                        } else {
                           tmp_dst68->pNext = NULL;
                        }
                        break;
                     case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR:
                        if (pnext) {
                           tmp_dst68->pNext = vk_zalloc(queue->alloc, sizeof(VkVideoReferenceIntraRefreshInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst68->pNext == NULL) goto err;
                           VkVideoReferenceIntraRefreshInfoKHR *tmp_dst94 = (void *)tmp_dst68->pNext;
                           VkVideoReferenceIntraRefreshInfoKHR *tmp_src95 = (void *)pnext;
                           memcpy(tmp_dst94, tmp_src95, sizeof(VkVideoReferenceIntraRefreshInfoKHR));
                        } else {
                           tmp_dst68->pNext = NULL;
                        }
                        break;
                     }
                  }
                  if (tmp_src69->pPictureResource) {
                     tmp_dst68->pPictureResource = vk_zalloc(queue->alloc, sizeof(VkVideoPictureResourceInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst68->pPictureResource == NULL) goto err;
                     VkVideoPictureResourceInfoKHR *tmp_dst96 = (void *)tmp_dst68->pPictureResource;
                     VkVideoPictureResourceInfoKHR *tmp_src97 = (void *)tmp_src69->pPictureResource;
                     memcpy(tmp_dst96, tmp_src97, sizeof(VkVideoPictureResourceInfoKHR));
                  } else {
                     tmp_dst68->pPictureResource = NULL;
                  }
                  }
               } else {
                  tmp_dst1->pReferenceSlots = NULL;
               }
            } else {
               cmd->u.encode_video_khr.encode_info = NULL;
            }

            list_addtail(&cmd->cmd_link, &queue->cmds);
            return VK_SUCCESS;

err:
            if (cmd)
               vk_free_cmd_encode_video_khr(queue, cmd);
            return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_decompress_memory_nv(struct vk_cmd_queue *queue,
                                 struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkDecompressMemoryRegionNV* )cmd->u.decompress_memory_nv.decompress_memory_regions);
}

VkResult vk_enqueue_cmd_decompress_memory_nv(struct vk_cmd_queue *queue
, uint32_t decompressRegionCount
, const VkDecompressMemoryRegionNV* pDecompressMemoryRegions
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DECOMPRESS_MEMORY_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DECOMPRESS_MEMORY_NV;
   cmd->u.decompress_memory_nv.decompress_region_count = decompressRegionCount;
   if (pDecompressMemoryRegions) {
      cmd->u.decompress_memory_nv.decompress_memory_regions = vk_zalloc(queue->alloc, sizeof(*cmd->u.decompress_memory_nv.decompress_memory_regions) * (decompressRegionCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.decompress_memory_nv.decompress_memory_regions == NULL) goto err;
      memcpy((void*)cmd->u.decompress_memory_nv.decompress_memory_regions, pDecompressMemoryRegions, sizeof(*cmd->u.decompress_memory_nv.decompress_memory_regions) * (decompressRegionCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_decompress_memory_nv(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_decompress_memory_indirect_count_nv(struct vk_cmd_queue *queue,
                                                struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_decompress_memory_indirect_count_nv(struct vk_cmd_queue *queue
, VkDeviceAddress indirectCommandsAddress
, VkDeviceAddress indirectCommandsCountAddress
, uint32_t stride
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DECOMPRESS_MEMORY_INDIRECT_COUNT_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DECOMPRESS_MEMORY_INDIRECT_COUNT_NV;
   cmd->u.decompress_memory_indirect_count_nv.indirect_commands_address = indirectCommandsAddress;
   cmd->u.decompress_memory_indirect_count_nv.indirect_commands_count_address = indirectCommandsCountAddress;
   cmd->u.decompress_memory_indirect_count_nv.stride = stride;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_build_partitioned_acceleration_structures_nv(struct vk_cmd_queue *queue,
                                                         struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.build_partitioned_acceleration_structures_nv.build_info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.build_partitioned_acceleration_structures_nv.build_info);

}

VkResult vk_enqueue_cmd_build_partitioned_acceleration_structures_nv(struct vk_cmd_queue *queue
, const VkBuildPartitionedAccelerationStructureInfoNV*  pBuildInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BUILD_PARTITIONED_ACCELERATION_STRUCTURES_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BUILD_PARTITIONED_ACCELERATION_STRUCTURES_NV;
   if (pBuildInfo) {
      cmd->u.build_partitioned_acceleration_structures_nv.build_info = vk_zalloc(queue->alloc, sizeof(VkBuildPartitionedAccelerationStructureInfoNV), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.build_partitioned_acceleration_structures_nv.build_info == NULL) goto err;
      VkBuildPartitionedAccelerationStructureInfoNV *tmp_dst1 = (void *)cmd->u.build_partitioned_acceleration_structures_nv.build_info;
      VkBuildPartitionedAccelerationStructureInfoNV *tmp_src2 = (void *)pBuildInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkBuildPartitionedAccelerationStructureInfoNV));
   } else {
      cmd->u.build_partitioned_acceleration_structures_nv.build_info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_build_partitioned_acceleration_structures_nv(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_cu_launch_kernel_nvx(struct vk_cmd_queue *queue,
                                 struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.cu_launch_kernel_nvx.launch_info) {
      void *pParams1 = (void *)(cmd->u.cu_launch_kernel_nvx.launch_info->pParams);
      if (cmd->u.cu_launch_kernel_nvx.launch_info->paramCount) {
      }
      vk_free(queue->alloc, pParams1);
      void *pExtras2 = (void *)(cmd->u.cu_launch_kernel_nvx.launch_info->pExtras);
      if (cmd->u.cu_launch_kernel_nvx.launch_info->extraCount) {
      }
      vk_free(queue->alloc, pExtras2);
   }
   vk_free(queue->alloc, (void*)cmd->u.cu_launch_kernel_nvx.launch_info);

}

VkResult vk_enqueue_cmd_cu_launch_kernel_nvx(struct vk_cmd_queue *queue
, const VkCuLaunchInfoNVX* pLaunchInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_CU_LAUNCH_KERNEL_NVX], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_CU_LAUNCH_KERNEL_NVX;
   if (pLaunchInfo) {
      cmd->u.cu_launch_kernel_nvx.launch_info = vk_zalloc(queue->alloc, sizeof(VkCuLaunchInfoNVX), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.cu_launch_kernel_nvx.launch_info == NULL) goto err;
      VkCuLaunchInfoNVX *tmp_dst1 = (void *)cmd->u.cu_launch_kernel_nvx.launch_info;
      VkCuLaunchInfoNVX *tmp_src2 = (void *)pLaunchInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkCuLaunchInfoNVX));
      if (tmp_src2->pParams) {
         tmp_dst1->pParams = vk_zalloc(queue->alloc, 1 * tmp_src2->paramCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pParams == NULL) goto err;
         void *tmp_dst3 = (void *)tmp_dst1->pParams;
         void *tmp_src4 = (void *)tmp_src2->pParams;
         memcpy(tmp_dst3, tmp_src4, 1 * tmp_src2->paramCount);
      } else {
         tmp_dst1->pParams = NULL;
      }
      if (tmp_src2->pExtras) {
         tmp_dst1->pExtras = vk_zalloc(queue->alloc, 1 * tmp_src2->extraCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pExtras == NULL) goto err;
         void *tmp_dst5 = (void *)tmp_dst1->pExtras;
         void *tmp_src6 = (void *)tmp_src2->pExtras;
         memcpy(tmp_dst5, tmp_src6, 1 * tmp_src2->extraCount);
      } else {
         tmp_dst1->pExtras = NULL;
      }
   } else {
      cmd->u.cu_launch_kernel_nvx.launch_info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_cu_launch_kernel_nvx(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_bind_descriptor_buffers_ext(struct vk_cmd_queue *queue,
                                        struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkDescriptorBufferBindingInfoEXT* )cmd->u.bind_descriptor_buffers_ext.binding_infos);
}

VkResult vk_enqueue_cmd_bind_descriptor_buffers_ext(struct vk_cmd_queue *queue
, uint32_t bufferCount
, const VkDescriptorBufferBindingInfoEXT* pBindingInfos
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BIND_DESCRIPTOR_BUFFERS_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BIND_DESCRIPTOR_BUFFERS_EXT;
   cmd->u.bind_descriptor_buffers_ext.buffer_count = bufferCount;
   if (pBindingInfos) {
      cmd->u.bind_descriptor_buffers_ext.binding_infos = vk_zalloc(queue->alloc, sizeof(*cmd->u.bind_descriptor_buffers_ext.binding_infos) * (bufferCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.bind_descriptor_buffers_ext.binding_infos == NULL) goto err;
      memcpy((void*)cmd->u.bind_descriptor_buffers_ext.binding_infos, pBindingInfos, sizeof(*cmd->u.bind_descriptor_buffers_ext.binding_infos) * (bufferCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_bind_descriptor_buffers_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_descriptor_buffer_offsets_ext(struct vk_cmd_queue *queue,
                                              struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( uint32_t* )cmd->u.set_descriptor_buffer_offsets_ext.buffer_indices);
   vk_free(queue->alloc, ( VkDeviceSize* )cmd->u.set_descriptor_buffer_offsets_ext.offsets);
}

VkResult vk_enqueue_cmd_set_descriptor_buffer_offsets_ext(struct vk_cmd_queue *queue
, VkPipelineBindPoint pipelineBindPoint
, VkPipelineLayout layout
, uint32_t firstSet
, uint32_t setCount
, const uint32_t* pBufferIndices
, const VkDeviceSize* pOffsets
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_DESCRIPTOR_BUFFER_OFFSETS_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_DESCRIPTOR_BUFFER_OFFSETS_EXT;
   cmd->u.set_descriptor_buffer_offsets_ext.pipeline_bind_point = pipelineBindPoint;
   cmd->u.set_descriptor_buffer_offsets_ext.layout = layout;
   cmd->u.set_descriptor_buffer_offsets_ext.first_set = firstSet;
   cmd->u.set_descriptor_buffer_offsets_ext.set_count = setCount;
   if (pBufferIndices) {
      cmd->u.set_descriptor_buffer_offsets_ext.buffer_indices = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_descriptor_buffer_offsets_ext.buffer_indices) * (setCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_descriptor_buffer_offsets_ext.buffer_indices == NULL) goto err;
      memcpy((void*)cmd->u.set_descriptor_buffer_offsets_ext.buffer_indices, pBufferIndices, sizeof(*cmd->u.set_descriptor_buffer_offsets_ext.buffer_indices) * (setCount));
   }
   if (pOffsets) {
      cmd->u.set_descriptor_buffer_offsets_ext.offsets = vk_zalloc(queue->alloc, sizeof(*cmd->u.set_descriptor_buffer_offsets_ext.offsets) * (setCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.set_descriptor_buffer_offsets_ext.offsets == NULL) goto err;
      memcpy((void*)cmd->u.set_descriptor_buffer_offsets_ext.offsets, pOffsets, sizeof(*cmd->u.set_descriptor_buffer_offsets_ext.offsets) * (setCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_descriptor_buffer_offsets_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_bind_descriptor_buffer_embedded_samplers_ext(struct vk_cmd_queue *queue,
                                                         struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_bind_descriptor_buffer_embedded_samplers_ext(struct vk_cmd_queue *queue
, VkPipelineBindPoint pipelineBindPoint
, VkPipelineLayout layout
, uint32_t set
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_EXT;
   cmd->u.bind_descriptor_buffer_embedded_samplers_ext.pipeline_bind_point = pipelineBindPoint;
   cmd->u.bind_descriptor_buffer_embedded_samplers_ext.layout = layout;
   cmd->u.bind_descriptor_buffer_embedded_samplers_ext.set = set;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_begin_rendering(struct vk_cmd_queue *queue,
                            struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.begin_rendering.rendering_info) {
      const VkBaseInStructure *pnext1 = cmd->u.begin_rendering.rendering_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO: {
            VkRect2D *pDeviceRenderAreas2 = (void *)(((VkDeviceGroupRenderPassBeginInfo *)pnext1)->pDeviceRenderAreas);
            if (((VkDeviceGroupRenderPassBeginInfo *)pnext1)->deviceRenderAreaCount) {
            }
            vk_free(queue->alloc, pDeviceRenderAreas2);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM: {
            VkRect2D *pPerViewRenderAreas3 = (void *)(((VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM *)pnext1)->pPerViewRenderAreas);
            if (((VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM *)pnext1)->perViewRenderAreaCount) {
            }
            vk_free(queue->alloc, pPerViewRenderAreas3);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_TILE_MEMORY_SIZE_INFO_QCOM: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM: {
            VkRenderPassStripeInfoARM *pStripeInfos4 = (void *)(((VkRenderPassStripeBeginInfoARM *)pnext1)->pStripeInfos);
            if (((VkRenderPassStripeBeginInfoARM *)pnext1)->stripeInfoCount) {
            }
            vk_free(queue->alloc, pStripeInfos4);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_RENDER_PASS_TILE_SHADING_CREATE_INFO_QCOM: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT: {
            VkSampleLocationEXT *pSampleLocations5 = (void *)(((VkSampleLocationsInfoEXT *)pnext1)->pSampleLocations);
            if (((VkSampleLocationsInfoEXT *)pnext1)->sampleLocationsCount) {
            }
            vk_free(queue->alloc, pSampleLocations5);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
      VkRenderingAttachmentInfo *pColorAttachments6 = (void *)(cmd->u.begin_rendering.rendering_info->pColorAttachments);
      if (cmd->u.begin_rendering.rendering_info->colorAttachmentCount) {
         const VkBaseInStructure *pnext7 = pColorAttachments6->pNext;
         if (pnext7) {
            switch ((int32_t)pnext7->sType) {
            case VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT: {
               vk_free(queue->alloc, (void*)pnext7);
               break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INITIAL_LAYOUT_INFO_MESA: {
               vk_free(queue->alloc, (void*)pnext7);
               break;
            }
            }
         }
      }
      vk_free(queue->alloc, pColorAttachments6);
      VkRenderingAttachmentInfo *pDepthAttachment8 = (void *)(cmd->u.begin_rendering.rendering_info->pDepthAttachment);
      if (pDepthAttachment8) {
         const VkBaseInStructure *pnext9 = pDepthAttachment8->pNext;
         if (pnext9) {
            switch ((int32_t)pnext9->sType) {
            case VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT: {
               vk_free(queue->alloc, (void*)pnext9);
               break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INITIAL_LAYOUT_INFO_MESA: {
               vk_free(queue->alloc, (void*)pnext9);
               break;
            }
            }
         }
      }
      vk_free(queue->alloc, pDepthAttachment8);
      VkRenderingAttachmentInfo *pStencilAttachment10 = (void *)(cmd->u.begin_rendering.rendering_info->pStencilAttachment);
      if (pStencilAttachment10) {
         const VkBaseInStructure *pnext11 = pStencilAttachment10->pNext;
         if (pnext11) {
            switch ((int32_t)pnext11->sType) {
            case VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT: {
               vk_free(queue->alloc, (void*)pnext11);
               break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INITIAL_LAYOUT_INFO_MESA: {
               vk_free(queue->alloc, (void*)pnext11);
               break;
            }
            }
         }
      }
      vk_free(queue->alloc, pStencilAttachment10);
   }
   vk_free(queue->alloc, (void*)cmd->u.begin_rendering.rendering_info);

}

VkResult vk_enqueue_cmd_begin_rendering(struct vk_cmd_queue *queue
, const VkRenderingInfo*                              pRenderingInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BEGIN_RENDERING], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BEGIN_RENDERING;
   if (pRenderingInfo) {
      cmd->u.begin_rendering.rendering_info = vk_zalloc(queue->alloc, sizeof(VkRenderingInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.begin_rendering.rendering_info == NULL) goto err;
      VkRenderingInfo *tmp_dst1 = (void *)cmd->u.begin_rendering.rendering_info;
      VkRenderingInfo *tmp_src2 = (void *)pRenderingInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkRenderingInfo));
      const VkBaseInStructure *pnext = tmp_dst1->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkDeviceGroupRenderPassBeginInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkDeviceGroupRenderPassBeginInfo *tmp_dst3 = (void *)tmp_dst1->pNext;
               VkDeviceGroupRenderPassBeginInfo *tmp_src4 = (void *)pnext;
               memcpy(tmp_dst3, tmp_src4, sizeof(VkDeviceGroupRenderPassBeginInfo));
               if (tmp_src4->pDeviceRenderAreas) {
                  tmp_dst3->pDeviceRenderAreas = vk_zalloc(queue->alloc, sizeof(VkRect2D) * tmp_src4->deviceRenderAreaCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst3->pDeviceRenderAreas == NULL) goto err;
                  VkRect2D *tmp_dst5 = (void *)tmp_dst3->pDeviceRenderAreas;
                  VkRect2D *tmp_src6 = (void *)tmp_src4->pDeviceRenderAreas;
                  memcpy(tmp_dst5, tmp_src6, sizeof(VkRect2D) * tmp_src4->deviceRenderAreaCount);
                  for (uint32_t i7 = 0; i7 < tmp_src4->deviceRenderAreaCount; i7++) {
                     VkRect2D *tmp_dst8 = tmp_dst5 + i7; (void)tmp_dst8;
                     VkRect2D *tmp_src9 = tmp_src6 + i7; (void)tmp_src9;
                     }
                  } else {
                     tmp_dst3->pDeviceRenderAreas = NULL;
                  }
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkMultisampledRenderToSingleSampledInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkMultisampledRenderToSingleSampledInfoEXT *tmp_dst10 = (void *)tmp_dst1->pNext;
                  VkMultisampledRenderToSingleSampledInfoEXT *tmp_src11 = (void *)pnext;
                  memcpy(tmp_dst10, tmp_src11, sizeof(VkMultisampledRenderToSingleSampledInfoEXT));
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkRenderingFragmentShadingRateAttachmentInfoKHR), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkRenderingFragmentShadingRateAttachmentInfoKHR *tmp_dst12 = (void *)tmp_dst1->pNext;
                  VkRenderingFragmentShadingRateAttachmentInfoKHR *tmp_src13 = (void *)pnext;
                  memcpy(tmp_dst12, tmp_src13, sizeof(VkRenderingFragmentShadingRateAttachmentInfoKHR));
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkRenderingFragmentDensityMapAttachmentInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkRenderingFragmentDensityMapAttachmentInfoEXT *tmp_dst14 = (void *)tmp_dst1->pNext;
                  VkRenderingFragmentDensityMapAttachmentInfoEXT *tmp_src15 = (void *)pnext;
                  memcpy(tmp_dst14, tmp_src15, sizeof(VkRenderingFragmentDensityMapAttachmentInfoEXT));
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkMultiviewPerViewAttributesInfoNVX), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkMultiviewPerViewAttributesInfoNVX *tmp_dst16 = (void *)tmp_dst1->pNext;
                  VkMultiviewPerViewAttributesInfoNVX *tmp_src17 = (void *)pnext;
                  memcpy(tmp_dst16, tmp_src17, sizeof(VkMultiviewPerViewAttributesInfoNVX));
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM:
               if (pnext) {
                  tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pNext == NULL) goto err;
                  VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM *tmp_dst18 = (void *)tmp_dst1->pNext;
                  VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM *tmp_src19 = (void *)pnext;
                  memcpy(tmp_dst18, tmp_src19, sizeof(VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM));
                  if (tmp_src19->pPerViewRenderAreas) {
                     tmp_dst18->pPerViewRenderAreas = vk_zalloc(queue->alloc, sizeof(VkRect2D) * tmp_src19->perViewRenderAreaCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst18->pPerViewRenderAreas == NULL) goto err;
                     VkRect2D *tmp_dst20 = (void *)tmp_dst18->pPerViewRenderAreas;
                     VkRect2D *tmp_src21 = (void *)tmp_src19->pPerViewRenderAreas;
                     memcpy(tmp_dst20, tmp_src21, sizeof(VkRect2D) * tmp_src19->perViewRenderAreaCount);
                     for (uint32_t i22 = 0; i22 < tmp_src19->perViewRenderAreaCount; i22++) {
                        VkRect2D *tmp_dst23 = tmp_dst20 + i22; (void)tmp_dst23;
                        VkRect2D *tmp_src24 = tmp_src21 + i22; (void)tmp_src24;
                        }
                     } else {
                        tmp_dst18->pPerViewRenderAreas = NULL;
                     }
                  } else {
                     tmp_dst1->pNext = NULL;
                  }
                  break;
               case VK_STRUCTURE_TYPE_TILE_MEMORY_SIZE_INFO_QCOM:
                  if (pnext) {
                     tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkTileMemorySizeInfoQCOM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst1->pNext == NULL) goto err;
                     VkTileMemorySizeInfoQCOM *tmp_dst25 = (void *)tmp_dst1->pNext;
                     VkTileMemorySizeInfoQCOM *tmp_src26 = (void *)pnext;
                     memcpy(tmp_dst25, tmp_src26, sizeof(VkTileMemorySizeInfoQCOM));
                  } else {
                     tmp_dst1->pNext = NULL;
                  }
                  break;
               case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM:
                  if (pnext) {
                     tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkRenderPassStripeBeginInfoARM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst1->pNext == NULL) goto err;
                     VkRenderPassStripeBeginInfoARM *tmp_dst27 = (void *)tmp_dst1->pNext;
                     VkRenderPassStripeBeginInfoARM *tmp_src28 = (void *)pnext;
                     memcpy(tmp_dst27, tmp_src28, sizeof(VkRenderPassStripeBeginInfoARM));
                     if (tmp_src28->pStripeInfos) {
                        tmp_dst27->pStripeInfos = vk_zalloc(queue->alloc, sizeof(VkRenderPassStripeInfoARM) * tmp_src28->stripeInfoCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst27->pStripeInfos == NULL) goto err;
                        VkRenderPassStripeInfoARM *tmp_dst29 = (void *)tmp_dst27->pStripeInfos;
                        VkRenderPassStripeInfoARM *tmp_src30 = (void *)tmp_src28->pStripeInfos;
                        memcpy(tmp_dst29, tmp_src30, sizeof(VkRenderPassStripeInfoARM) * tmp_src28->stripeInfoCount);
                        for (uint32_t i31 = 0; i31 < tmp_src28->stripeInfoCount; i31++) {
                           VkRenderPassStripeInfoARM *tmp_dst32 = tmp_dst29 + i31; (void)tmp_dst32;
                           VkRenderPassStripeInfoARM *tmp_src33 = tmp_src30 + i31; (void)tmp_src33;
                           }
                        } else {
                           tmp_dst27->pStripeInfos = NULL;
                        }
                     } else {
                        tmp_dst1->pNext = NULL;
                     }
                     break;
                  case VK_STRUCTURE_TYPE_RENDER_PASS_TILE_SHADING_CREATE_INFO_QCOM:
                     if (pnext) {
                        tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkRenderPassTileShadingCreateInfoQCOM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst1->pNext == NULL) goto err;
                        VkRenderPassTileShadingCreateInfoQCOM *tmp_dst34 = (void *)tmp_dst1->pNext;
                        VkRenderPassTileShadingCreateInfoQCOM *tmp_src35 = (void *)pnext;
                        memcpy(tmp_dst34, tmp_src35, sizeof(VkRenderPassTileShadingCreateInfoQCOM));
                     } else {
                        tmp_dst1->pNext = NULL;
                     }
                     break;
                  case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
                     if (pnext) {
                        tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkSampleLocationsInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst1->pNext == NULL) goto err;
                        VkSampleLocationsInfoEXT *tmp_dst36 = (void *)tmp_dst1->pNext;
                        VkSampleLocationsInfoEXT *tmp_src37 = (void *)pnext;
                        memcpy(tmp_dst36, tmp_src37, sizeof(VkSampleLocationsInfoEXT));
                        if (tmp_src37->pSampleLocations) {
                           tmp_dst36->pSampleLocations = vk_zalloc(queue->alloc, sizeof(VkSampleLocationEXT) * tmp_src37->sampleLocationsCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                           if (tmp_dst36->pSampleLocations == NULL) goto err;
                           VkSampleLocationEXT *tmp_dst38 = (void *)tmp_dst36->pSampleLocations;
                           VkSampleLocationEXT *tmp_src39 = (void *)tmp_src37->pSampleLocations;
                           memcpy(tmp_dst38, tmp_src39, sizeof(VkSampleLocationEXT) * tmp_src37->sampleLocationsCount);
                           for (uint32_t i40 = 0; i40 < tmp_src37->sampleLocationsCount; i40++) {
                              VkSampleLocationEXT *tmp_dst41 = tmp_dst38 + i40; (void)tmp_dst41;
                              VkSampleLocationEXT *tmp_src42 = tmp_src39 + i40; (void)tmp_src42;
                              }
                           } else {
                              tmp_dst36->pSampleLocations = NULL;
                           }
                        } else {
                           tmp_dst1->pNext = NULL;
                        }
                        break;
                     }
                  }
                  if (tmp_src2->pColorAttachments) {
                     tmp_dst1->pColorAttachments = vk_zalloc(queue->alloc, sizeof(VkRenderingAttachmentInfo) * tmp_src2->colorAttachmentCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst1->pColorAttachments == NULL) goto err;
                     VkRenderingAttachmentInfo *tmp_dst43 = (void *)tmp_dst1->pColorAttachments;
                     VkRenderingAttachmentInfo *tmp_src44 = (void *)tmp_src2->pColorAttachments;
                     memcpy(tmp_dst43, tmp_src44, sizeof(VkRenderingAttachmentInfo) * tmp_src2->colorAttachmentCount);
                     for (uint32_t i45 = 0; i45 < tmp_src2->colorAttachmentCount; i45++) {
                        VkRenderingAttachmentInfo *tmp_dst46 = tmp_dst43 + i45; (void)tmp_dst46;
                        VkRenderingAttachmentInfo *tmp_src47 = tmp_src44 + i45; (void)tmp_src47;
                        const VkBaseInStructure *pnext = tmp_dst46->pNext;
                        if (pnext) {
                           switch ((int32_t)pnext->sType) {
                           case VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT:
                              if (pnext) {
                                 tmp_dst46->pNext = vk_zalloc(queue->alloc, sizeof(VkAttachmentFeedbackLoopInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst46->pNext == NULL) goto err;
                                 VkAttachmentFeedbackLoopInfoEXT *tmp_dst48 = (void *)tmp_dst46->pNext;
                                 VkAttachmentFeedbackLoopInfoEXT *tmp_src49 = (void *)pnext;
                                 memcpy(tmp_dst48, tmp_src49, sizeof(VkAttachmentFeedbackLoopInfoEXT));
                              } else {
                                 tmp_dst46->pNext = NULL;
                              }
                              break;
                           case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INITIAL_LAYOUT_INFO_MESA:
                              if (pnext) {
                                 tmp_dst46->pNext = vk_zalloc(queue->alloc, sizeof(VkRenderingAttachmentInitialLayoutInfoMESA), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst46->pNext == NULL) goto err;
                                 VkRenderingAttachmentInitialLayoutInfoMESA *tmp_dst50 = (void *)tmp_dst46->pNext;
                                 VkRenderingAttachmentInitialLayoutInfoMESA *tmp_src51 = (void *)pnext;
                                 memcpy(tmp_dst50, tmp_src51, sizeof(VkRenderingAttachmentInitialLayoutInfoMESA));
                              } else {
                                 tmp_dst46->pNext = NULL;
                              }
                              break;
                           }
                        }
                        }
                     } else {
                        tmp_dst1->pColorAttachments = NULL;
                     }
                     if (tmp_src2->pDepthAttachment) {
                        tmp_dst1->pDepthAttachment = vk_zalloc(queue->alloc, sizeof(VkRenderingAttachmentInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst1->pDepthAttachment == NULL) goto err;
                        VkRenderingAttachmentInfo *tmp_dst52 = (void *)tmp_dst1->pDepthAttachment;
                        VkRenderingAttachmentInfo *tmp_src53 = (void *)tmp_src2->pDepthAttachment;
                        memcpy(tmp_dst52, tmp_src53, sizeof(VkRenderingAttachmentInfo));
                        const VkBaseInStructure *pnext = tmp_dst52->pNext;
                        if (pnext) {
                           switch ((int32_t)pnext->sType) {
                           case VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT:
                              if (pnext) {
                                 tmp_dst52->pNext = vk_zalloc(queue->alloc, sizeof(VkAttachmentFeedbackLoopInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst52->pNext == NULL) goto err;
                                 VkAttachmentFeedbackLoopInfoEXT *tmp_dst54 = (void *)tmp_dst52->pNext;
                                 VkAttachmentFeedbackLoopInfoEXT *tmp_src55 = (void *)pnext;
                                 memcpy(tmp_dst54, tmp_src55, sizeof(VkAttachmentFeedbackLoopInfoEXT));
                              } else {
                                 tmp_dst52->pNext = NULL;
                              }
                              break;
                           case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INITIAL_LAYOUT_INFO_MESA:
                              if (pnext) {
                                 tmp_dst52->pNext = vk_zalloc(queue->alloc, sizeof(VkRenderingAttachmentInitialLayoutInfoMESA), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst52->pNext == NULL) goto err;
                                 VkRenderingAttachmentInitialLayoutInfoMESA *tmp_dst56 = (void *)tmp_dst52->pNext;
                                 VkRenderingAttachmentInitialLayoutInfoMESA *tmp_src57 = (void *)pnext;
                                 memcpy(tmp_dst56, tmp_src57, sizeof(VkRenderingAttachmentInitialLayoutInfoMESA));
                              } else {
                                 tmp_dst52->pNext = NULL;
                              }
                              break;
                           }
                        }
                     } else {
                        tmp_dst1->pDepthAttachment = NULL;
                     }
                     if (tmp_src2->pStencilAttachment) {
                        tmp_dst1->pStencilAttachment = vk_zalloc(queue->alloc, sizeof(VkRenderingAttachmentInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                        if (tmp_dst1->pStencilAttachment == NULL) goto err;
                        VkRenderingAttachmentInfo *tmp_dst58 = (void *)tmp_dst1->pStencilAttachment;
                        VkRenderingAttachmentInfo *tmp_src59 = (void *)tmp_src2->pStencilAttachment;
                        memcpy(tmp_dst58, tmp_src59, sizeof(VkRenderingAttachmentInfo));
                        const VkBaseInStructure *pnext = tmp_dst58->pNext;
                        if (pnext) {
                           switch ((int32_t)pnext->sType) {
                           case VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT:
                              if (pnext) {
                                 tmp_dst58->pNext = vk_zalloc(queue->alloc, sizeof(VkAttachmentFeedbackLoopInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst58->pNext == NULL) goto err;
                                 VkAttachmentFeedbackLoopInfoEXT *tmp_dst60 = (void *)tmp_dst58->pNext;
                                 VkAttachmentFeedbackLoopInfoEXT *tmp_src61 = (void *)pnext;
                                 memcpy(tmp_dst60, tmp_src61, sizeof(VkAttachmentFeedbackLoopInfoEXT));
                              } else {
                                 tmp_dst58->pNext = NULL;
                              }
                              break;
                           case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INITIAL_LAYOUT_INFO_MESA:
                              if (pnext) {
                                 tmp_dst58->pNext = vk_zalloc(queue->alloc, sizeof(VkRenderingAttachmentInitialLayoutInfoMESA), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                                 if (tmp_dst58->pNext == NULL) goto err;
                                 VkRenderingAttachmentInitialLayoutInfoMESA *tmp_dst62 = (void *)tmp_dst58->pNext;
                                 VkRenderingAttachmentInitialLayoutInfoMESA *tmp_src63 = (void *)pnext;
                                 memcpy(tmp_dst62, tmp_src63, sizeof(VkRenderingAttachmentInitialLayoutInfoMESA));
                              } else {
                                 tmp_dst58->pNext = NULL;
                              }
                              break;
                           }
                        }
                     } else {
                        tmp_dst1->pStencilAttachment = NULL;
                     }
                  } else {
                     cmd->u.begin_rendering.rendering_info = NULL;
                  }

                  list_addtail(&cmd->cmd_link, &queue->cmds);
                  return VK_SUCCESS;

err:
                  if (cmd)
                     vk_free_cmd_begin_rendering(queue, cmd);
                  return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_end_rendering(struct vk_cmd_queue *queue,
                          struct vk_cmd_queue_entry *cmd)
{
}

VkResult vk_enqueue_cmd_end_rendering(struct vk_cmd_queue *queue
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_END_RENDERING], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_END_RENDERING;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;
}

static void
vk_free_cmd_end_rendering2_ext(struct vk_cmd_queue *queue,
                               struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.end_rendering2_ext.rendering_end_info) {
      const VkBaseInStructure *pnext1 = cmd->u.end_rendering2_ext.rendering_end_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT: {
            VkOffset2D *pFragmentDensityOffsets2 = (void *)(((VkRenderPassFragmentDensityMapOffsetEndInfoEXT *)pnext1)->pFragmentDensityOffsets);
            if (((VkRenderPassFragmentDensityMapOffsetEndInfoEXT *)pnext1)->fragmentDensityOffsetCount) {
            }
            vk_free(queue->alloc, pFragmentDensityOffsets2);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
   }
   vk_free(queue->alloc, (void*)cmd->u.end_rendering2_ext.rendering_end_info);

}

VkResult vk_enqueue_cmd_end_rendering2_ext(struct vk_cmd_queue *queue
, const VkRenderingEndInfoEXT*        pRenderingEndInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_END_RENDERING2_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_END_RENDERING2_EXT;
   if (pRenderingEndInfo) {
      cmd->u.end_rendering2_ext.rendering_end_info = vk_zalloc(queue->alloc, sizeof(VkRenderingEndInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.end_rendering2_ext.rendering_end_info == NULL) goto err;
      VkRenderingEndInfoEXT *tmp_dst1 = (void *)cmd->u.end_rendering2_ext.rendering_end_info;
      VkRenderingEndInfoEXT *tmp_src2 = (void *)pRenderingEndInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkRenderingEndInfoEXT));
      const VkBaseInStructure *pnext = tmp_dst1->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkRenderPassFragmentDensityMapOffsetEndInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkRenderPassFragmentDensityMapOffsetEndInfoEXT *tmp_dst3 = (void *)tmp_dst1->pNext;
               VkRenderPassFragmentDensityMapOffsetEndInfoEXT *tmp_src4 = (void *)pnext;
               memcpy(tmp_dst3, tmp_src4, sizeof(VkRenderPassFragmentDensityMapOffsetEndInfoEXT));
               if (tmp_src4->pFragmentDensityOffsets) {
                  tmp_dst3->pFragmentDensityOffsets = vk_zalloc(queue->alloc, sizeof(VkOffset2D) * tmp_src4->fragmentDensityOffsetCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst3->pFragmentDensityOffsets == NULL) goto err;
                  VkOffset2D *tmp_dst5 = (void *)tmp_dst3->pFragmentDensityOffsets;
                  VkOffset2D *tmp_src6 = (void *)tmp_src4->pFragmentDensityOffsets;
                  memcpy(tmp_dst5, tmp_src6, sizeof(VkOffset2D) * tmp_src4->fragmentDensityOffsetCount);
                  for (uint32_t i7 = 0; i7 < tmp_src4->fragmentDensityOffsetCount; i7++) {
                     VkOffset2D *tmp_dst8 = tmp_dst5 + i7; (void)tmp_dst8;
                     VkOffset2D *tmp_src9 = tmp_src6 + i7; (void)tmp_src9;
                     }
                  } else {
                     tmp_dst3->pFragmentDensityOffsets = NULL;
                  }
               } else {
                  tmp_dst1->pNext = NULL;
               }
               break;
            }
         }
      } else {
         cmd->u.end_rendering2_ext.rendering_end_info = NULL;
      }

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_end_rendering2_ext(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_build_micromaps_ext(struct vk_cmd_queue *queue,
                                struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkMicromapBuildInfoEXT* )cmd->u.build_micromaps_ext.infos);
}

VkResult vk_enqueue_cmd_build_micromaps_ext(struct vk_cmd_queue *queue
, uint32_t infoCount
, const VkMicromapBuildInfoEXT* pInfos
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BUILD_MICROMAPS_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BUILD_MICROMAPS_EXT;
   cmd->u.build_micromaps_ext.info_count = infoCount;
   if (pInfos) {
      cmd->u.build_micromaps_ext.infos = vk_zalloc(queue->alloc, sizeof(*cmd->u.build_micromaps_ext.infos) * (infoCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.build_micromaps_ext.infos == NULL) goto err;
      memcpy((void*)cmd->u.build_micromaps_ext.infos, pInfos, sizeof(*cmd->u.build_micromaps_ext.infos) * (infoCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_build_micromaps_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_copy_micromap_ext(struct vk_cmd_queue *queue,
                              struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.copy_micromap_ext.info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.copy_micromap_ext.info);

}

VkResult vk_enqueue_cmd_copy_micromap_ext(struct vk_cmd_queue *queue
, const VkCopyMicromapInfoEXT* pInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_MICROMAP_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_MICROMAP_EXT;
   if (pInfo) {
      cmd->u.copy_micromap_ext.info = vk_zalloc(queue->alloc, sizeof(VkCopyMicromapInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.copy_micromap_ext.info == NULL) goto err;
      VkCopyMicromapInfoEXT *tmp_dst1 = (void *)cmd->u.copy_micromap_ext.info;
      VkCopyMicromapInfoEXT *tmp_src2 = (void *)pInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkCopyMicromapInfoEXT));
   } else {
      cmd->u.copy_micromap_ext.info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_copy_micromap_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_copy_micromap_to_memory_ext(struct vk_cmd_queue *queue,
                                        struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.copy_micromap_to_memory_ext.info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.copy_micromap_to_memory_ext.info);

}

VkResult vk_enqueue_cmd_copy_micromap_to_memory_ext(struct vk_cmd_queue *queue
, const VkCopyMicromapToMemoryInfoEXT* pInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_MICROMAP_TO_MEMORY_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_MICROMAP_TO_MEMORY_EXT;
   if (pInfo) {
      cmd->u.copy_micromap_to_memory_ext.info = vk_zalloc(queue->alloc, sizeof(VkCopyMicromapToMemoryInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.copy_micromap_to_memory_ext.info == NULL) goto err;
      VkCopyMicromapToMemoryInfoEXT *tmp_dst1 = (void *)cmd->u.copy_micromap_to_memory_ext.info;
      VkCopyMicromapToMemoryInfoEXT *tmp_src2 = (void *)pInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkCopyMicromapToMemoryInfoEXT));
   } else {
      cmd->u.copy_micromap_to_memory_ext.info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_copy_micromap_to_memory_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_copy_memory_to_micromap_ext(struct vk_cmd_queue *queue,
                                        struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.copy_memory_to_micromap_ext.info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.copy_memory_to_micromap_ext.info);

}

VkResult vk_enqueue_cmd_copy_memory_to_micromap_ext(struct vk_cmd_queue *queue
, const VkCopyMemoryToMicromapInfoEXT* pInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_MEMORY_TO_MICROMAP_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_MEMORY_TO_MICROMAP_EXT;
   if (pInfo) {
      cmd->u.copy_memory_to_micromap_ext.info = vk_zalloc(queue->alloc, sizeof(VkCopyMemoryToMicromapInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.copy_memory_to_micromap_ext.info == NULL) goto err;
      VkCopyMemoryToMicromapInfoEXT *tmp_dst1 = (void *)cmd->u.copy_memory_to_micromap_ext.info;
      VkCopyMemoryToMicromapInfoEXT *tmp_src2 = (void *)pInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkCopyMemoryToMicromapInfoEXT));
   } else {
      cmd->u.copy_memory_to_micromap_ext.info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_copy_memory_to_micromap_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_write_micromaps_properties_ext(struct vk_cmd_queue *queue,
                                           struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkMicromapEXT* )cmd->u.write_micromaps_properties_ext.micromaps);
}

VkResult vk_enqueue_cmd_write_micromaps_properties_ext(struct vk_cmd_queue *queue
, uint32_t micromapCount
, const VkMicromapEXT* pMicromaps
, VkQueryType queryType
, VkQueryPool queryPool
, uint32_t firstQuery
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_WRITE_MICROMAPS_PROPERTIES_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_WRITE_MICROMAPS_PROPERTIES_EXT;
   cmd->u.write_micromaps_properties_ext.micromap_count = micromapCount;
   if (pMicromaps) {
      cmd->u.write_micromaps_properties_ext.micromaps = vk_zalloc(queue->alloc, sizeof(*cmd->u.write_micromaps_properties_ext.micromaps) * (micromapCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.write_micromaps_properties_ext.micromaps == NULL) goto err;
      memcpy((void*)cmd->u.write_micromaps_properties_ext.micromaps, pMicromaps, sizeof(*cmd->u.write_micromaps_properties_ext.micromaps) * (micromapCount));
   }
   cmd->u.write_micromaps_properties_ext.query_type = queryType;
   cmd->u.write_micromaps_properties_ext.query_pool = queryPool;
   cmd->u.write_micromaps_properties_ext.first_query = firstQuery;

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_write_micromaps_properties_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_bind_tile_memory_qcom(struct vk_cmd_queue *queue,
                                  struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.bind_tile_memory_qcom.tile_memory_bind_info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.bind_tile_memory_qcom.tile_memory_bind_info);

}

VkResult vk_enqueue_cmd_bind_tile_memory_qcom(struct vk_cmd_queue *queue
, const VkTileMemoryBindInfoQCOM* pTileMemoryBindInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BIND_TILE_MEMORY_QCOM], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BIND_TILE_MEMORY_QCOM;
   if (pTileMemoryBindInfo) {
      cmd->u.bind_tile_memory_qcom.tile_memory_bind_info = vk_zalloc(queue->alloc, sizeof(VkTileMemoryBindInfoQCOM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.bind_tile_memory_qcom.tile_memory_bind_info == NULL) goto err;
      VkTileMemoryBindInfoQCOM *tmp_dst1 = (void *)cmd->u.bind_tile_memory_qcom.tile_memory_bind_info;
      VkTileMemoryBindInfoQCOM *tmp_src2 = (void *)pTileMemoryBindInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkTileMemoryBindInfoQCOM));
   } else {
      cmd->u.bind_tile_memory_qcom.tile_memory_bind_info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_bind_tile_memory_qcom(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_optical_flow_execute_nv(struct vk_cmd_queue *queue,
                                    struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.optical_flow_execute_nv.execute_info) {
      VkRect2D *pRegions1 = (void *)(cmd->u.optical_flow_execute_nv.execute_info->pRegions);
      if (cmd->u.optical_flow_execute_nv.execute_info->regionCount) {
      }
      vk_free(queue->alloc, pRegions1);
   }
   vk_free(queue->alloc, (void*)cmd->u.optical_flow_execute_nv.execute_info);

}

VkResult vk_enqueue_cmd_optical_flow_execute_nv(struct vk_cmd_queue *queue
, VkOpticalFlowSessionNV session
, const VkOpticalFlowExecuteInfoNV* pExecuteInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_OPTICAL_FLOW_EXECUTE_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_OPTICAL_FLOW_EXECUTE_NV;
   cmd->u.optical_flow_execute_nv.session = session;
   if (pExecuteInfo) {
      cmd->u.optical_flow_execute_nv.execute_info = vk_zalloc(queue->alloc, sizeof(VkOpticalFlowExecuteInfoNV), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.optical_flow_execute_nv.execute_info == NULL) goto err;
      VkOpticalFlowExecuteInfoNV *tmp_dst1 = (void *)cmd->u.optical_flow_execute_nv.execute_info;
      VkOpticalFlowExecuteInfoNV *tmp_src2 = (void *)pExecuteInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkOpticalFlowExecuteInfoNV));
      if (tmp_src2->pRegions) {
         tmp_dst1->pRegions = vk_zalloc(queue->alloc, sizeof(VkRect2D) * tmp_src2->regionCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pRegions == NULL) goto err;
         VkRect2D *tmp_dst3 = (void *)tmp_dst1->pRegions;
         VkRect2D *tmp_src4 = (void *)tmp_src2->pRegions;
         memcpy(tmp_dst3, tmp_src4, sizeof(VkRect2D) * tmp_src2->regionCount);
         for (uint32_t i5 = 0; i5 < tmp_src2->regionCount; i5++) {
            VkRect2D *tmp_dst6 = tmp_dst3 + i5; (void)tmp_dst6;
            VkRect2D *tmp_src7 = tmp_src4 + i5; (void)tmp_src7;
            }
         } else {
            tmp_dst1->pRegions = NULL;
         }
      } else {
         cmd->u.optical_flow_execute_nv.execute_info = NULL;
      }

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_optical_flow_execute_nv(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_depth_bias2_ext(struct vk_cmd_queue *queue,
                                struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.set_depth_bias2_ext.depth_bias_info) {
      const VkBaseInStructure *pnext1 = cmd->u.set_depth_bias2_ext.depth_bias_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT: {
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
   }
   vk_free(queue->alloc, (void*)cmd->u.set_depth_bias2_ext.depth_bias_info);

}

VkResult vk_enqueue_cmd_set_depth_bias2_ext(struct vk_cmd_queue *queue
, const VkDepthBiasInfoEXT*         pDepthBiasInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_DEPTH_BIAS2_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_DEPTH_BIAS2_EXT;
   if (pDepthBiasInfo) {
      cmd->u.set_depth_bias2_ext.depth_bias_info = vk_zalloc(queue->alloc, sizeof(VkDepthBiasInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.set_depth_bias2_ext.depth_bias_info == NULL) goto err;
      VkDepthBiasInfoEXT *tmp_dst1 = (void *)cmd->u.set_depth_bias2_ext.depth_bias_info;
      VkDepthBiasInfoEXT *tmp_src2 = (void *)pDepthBiasInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkDepthBiasInfoEXT));
      const VkBaseInStructure *pnext = tmp_dst1->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkDepthBiasRepresentationInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkDepthBiasRepresentationInfoEXT *tmp_dst3 = (void *)tmp_dst1->pNext;
               VkDepthBiasRepresentationInfoEXT *tmp_src4 = (void *)pnext;
               memcpy(tmp_dst3, tmp_src4, sizeof(VkDepthBiasRepresentationInfoEXT));
            } else {
               tmp_dst1->pNext = NULL;
            }
            break;
         }
      }
   } else {
      cmd->u.set_depth_bias2_ext.depth_bias_info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_depth_bias2_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_bind_shaders_ext(struct vk_cmd_queue *queue,
                             struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkShaderStageFlagBits* )cmd->u.bind_shaders_ext.stages);
   vk_free(queue->alloc, ( VkShaderEXT* )cmd->u.bind_shaders_ext.shaders);
}

VkResult vk_enqueue_cmd_bind_shaders_ext(struct vk_cmd_queue *queue
, uint32_t stageCount
, const VkShaderStageFlagBits* pStages
, const VkShaderEXT* pShaders
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BIND_SHADERS_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BIND_SHADERS_EXT;
   cmd->u.bind_shaders_ext.stage_count = stageCount;
   if (pStages) {
      cmd->u.bind_shaders_ext.stages = vk_zalloc(queue->alloc, sizeof(*cmd->u.bind_shaders_ext.stages) * (stageCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.bind_shaders_ext.stages == NULL) goto err;
      memcpy((void*)cmd->u.bind_shaders_ext.stages, pStages, sizeof(*cmd->u.bind_shaders_ext.stages) * (stageCount));
   }
   if (pShaders) {
      cmd->u.bind_shaders_ext.shaders = vk_zalloc(queue->alloc, sizeof(*cmd->u.bind_shaders_ext.shaders) * (stageCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.bind_shaders_ext.shaders == NULL) goto err;
      memcpy((void*)cmd->u.bind_shaders_ext.shaders, pShaders, sizeof(*cmd->u.bind_shaders_ext.shaders) * (stageCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_bind_shaders_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_bind_descriptor_sets2(struct vk_cmd_queue *queue,
                                  struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.bind_descriptor_sets2.bind_descriptor_sets_info) {
      const VkBaseInStructure *pnext1 = cmd->u.bind_descriptor_sets2.bind_descriptor_sets_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO: {
            VkDescriptorSetLayout *pSetLayouts2 = (void *)(((VkPipelineLayoutCreateInfo *)pnext1)->pSetLayouts);
            if (((VkPipelineLayoutCreateInfo *)pnext1)->setLayoutCount) {
            }
            vk_free(queue->alloc, pSetLayouts2);
            VkPushConstantRange *pPushConstantRanges3 = (void *)(((VkPipelineLayoutCreateInfo *)pnext1)->pPushConstantRanges);
            if (((VkPipelineLayoutCreateInfo *)pnext1)->pushConstantRangeCount) {
            }
            vk_free(queue->alloc, pPushConstantRanges3);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
      VkDescriptorSet *pDescriptorSets4 = (void *)(cmd->u.bind_descriptor_sets2.bind_descriptor_sets_info->pDescriptorSets);
      if (cmd->u.bind_descriptor_sets2.bind_descriptor_sets_info->descriptorSetCount) {
      }
      vk_free(queue->alloc, pDescriptorSets4);
      uint32_t *pDynamicOffsets5 = (void *)(cmd->u.bind_descriptor_sets2.bind_descriptor_sets_info->pDynamicOffsets);
      if (cmd->u.bind_descriptor_sets2.bind_descriptor_sets_info->dynamicOffsetCount) {
      }
      vk_free(queue->alloc, pDynamicOffsets5);
   }
   vk_free(queue->alloc, (void*)cmd->u.bind_descriptor_sets2.bind_descriptor_sets_info);

}

VkResult vk_enqueue_cmd_bind_descriptor_sets2(struct vk_cmd_queue *queue
, const VkBindDescriptorSetsInfo*   pBindDescriptorSetsInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BIND_DESCRIPTOR_SETS2], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BIND_DESCRIPTOR_SETS2;
   if (pBindDescriptorSetsInfo) {
      cmd->u.bind_descriptor_sets2.bind_descriptor_sets_info = vk_zalloc(queue->alloc, sizeof(VkBindDescriptorSetsInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.bind_descriptor_sets2.bind_descriptor_sets_info == NULL) goto err;
      VkBindDescriptorSetsInfo *tmp_dst1 = (void *)cmd->u.bind_descriptor_sets2.bind_descriptor_sets_info;
      VkBindDescriptorSetsInfo *tmp_src2 = (void *)pBindDescriptorSetsInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkBindDescriptorSetsInfo));
      const VkBaseInStructure *pnext = tmp_dst1->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkPipelineLayoutCreateInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkPipelineLayoutCreateInfo *tmp_dst3 = (void *)tmp_dst1->pNext;
               VkPipelineLayoutCreateInfo *tmp_src4 = (void *)pnext;
               memcpy(tmp_dst3, tmp_src4, sizeof(VkPipelineLayoutCreateInfo));
               if (tmp_src4->pSetLayouts) {
                  tmp_dst3->pSetLayouts = vk_zalloc(queue->alloc, sizeof(VkDescriptorSetLayout) * tmp_src4->setLayoutCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst3->pSetLayouts == NULL) goto err;
                  VkDescriptorSetLayout *tmp_dst5 = (void *)tmp_dst3->pSetLayouts;
                  VkDescriptorSetLayout *tmp_src6 = (void *)tmp_src4->pSetLayouts;
                  memcpy(tmp_dst5, tmp_src6, sizeof(VkDescriptorSetLayout) * tmp_src4->setLayoutCount);
                  for (uint32_t i7 = 0; i7 < tmp_src4->setLayoutCount; i7++) {
                     VkDescriptorSetLayout *tmp_dst8 = tmp_dst5 + i7; (void)tmp_dst8;
                     VkDescriptorSetLayout *tmp_src9 = tmp_src6 + i7; (void)tmp_src9;
                     }
                  } else {
                     tmp_dst3->pSetLayouts = NULL;
                  }
                  if (tmp_src4->pPushConstantRanges) {
                     tmp_dst3->pPushConstantRanges = vk_zalloc(queue->alloc, sizeof(VkPushConstantRange) * tmp_src4->pushConstantRangeCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst3->pPushConstantRanges == NULL) goto err;
                     VkPushConstantRange *tmp_dst10 = (void *)tmp_dst3->pPushConstantRanges;
                     VkPushConstantRange *tmp_src11 = (void *)tmp_src4->pPushConstantRanges;
                     memcpy(tmp_dst10, tmp_src11, sizeof(VkPushConstantRange) * tmp_src4->pushConstantRangeCount);
                     for (uint32_t i12 = 0; i12 < tmp_src4->pushConstantRangeCount; i12++) {
                        VkPushConstantRange *tmp_dst13 = tmp_dst10 + i12; (void)tmp_dst13;
                        VkPushConstantRange *tmp_src14 = tmp_src11 + i12; (void)tmp_src14;
                        }
                     } else {
                        tmp_dst3->pPushConstantRanges = NULL;
                     }
                  } else {
                     tmp_dst1->pNext = NULL;
                  }
                  break;
               }
            }
            if (tmp_src2->pDescriptorSets) {
               tmp_dst1->pDescriptorSets = vk_zalloc(queue->alloc, sizeof(VkDescriptorSet) * tmp_src2->descriptorSetCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pDescriptorSets == NULL) goto err;
               VkDescriptorSet *tmp_dst15 = (void *)tmp_dst1->pDescriptorSets;
               VkDescriptorSet *tmp_src16 = (void *)tmp_src2->pDescriptorSets;
               memcpy(tmp_dst15, tmp_src16, sizeof(VkDescriptorSet) * tmp_src2->descriptorSetCount);
               for (uint32_t i17 = 0; i17 < tmp_src2->descriptorSetCount; i17++) {
                  VkDescriptorSet *tmp_dst18 = tmp_dst15 + i17; (void)tmp_dst18;
                  VkDescriptorSet *tmp_src19 = tmp_src16 + i17; (void)tmp_src19;
                  }
               } else {
                  tmp_dst1->pDescriptorSets = NULL;
               }
               if (tmp_src2->pDynamicOffsets) {
                  tmp_dst1->pDynamicOffsets = vk_zalloc(queue->alloc, sizeof(uint32_t) * tmp_src2->dynamicOffsetCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pDynamicOffsets == NULL) goto err;
                  uint32_t *tmp_dst20 = (void *)tmp_dst1->pDynamicOffsets;
                  uint32_t *tmp_src21 = (void *)tmp_src2->pDynamicOffsets;
                  memcpy(tmp_dst20, tmp_src21, sizeof(uint32_t) * tmp_src2->dynamicOffsetCount);
                  for (uint32_t i22 = 0; i22 < tmp_src2->dynamicOffsetCount; i22++) {
                     uint32_t *tmp_dst23 = tmp_dst20 + i22; (void)tmp_dst23;
                     uint32_t *tmp_src24 = tmp_src21 + i22; (void)tmp_src24;
                     }
                  } else {
                     tmp_dst1->pDynamicOffsets = NULL;
                  }
               } else {
                  cmd->u.bind_descriptor_sets2.bind_descriptor_sets_info = NULL;
               }

               list_addtail(&cmd->cmd_link, &queue->cmds);
               return VK_SUCCESS;

err:
               if (cmd)
                  vk_free_cmd_bind_descriptor_sets2(queue, cmd);
               return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_push_constants2(struct vk_cmd_queue *queue,
                            struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.push_constants2.push_constants_info) {
      const VkBaseInStructure *pnext1 = cmd->u.push_constants2.push_constants_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO: {
            VkDescriptorSetLayout *pSetLayouts2 = (void *)(((VkPipelineLayoutCreateInfo *)pnext1)->pSetLayouts);
            if (((VkPipelineLayoutCreateInfo *)pnext1)->setLayoutCount) {
            }
            vk_free(queue->alloc, pSetLayouts2);
            VkPushConstantRange *pPushConstantRanges3 = (void *)(((VkPipelineLayoutCreateInfo *)pnext1)->pPushConstantRanges);
            if (((VkPipelineLayoutCreateInfo *)pnext1)->pushConstantRangeCount) {
            }
            vk_free(queue->alloc, pPushConstantRanges3);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
      void *pValues4 = (void *)(cmd->u.push_constants2.push_constants_info->pValues);
      if (cmd->u.push_constants2.push_constants_info->size) {
      }
      vk_free(queue->alloc, pValues4);
   }
   vk_free(queue->alloc, (void*)cmd->u.push_constants2.push_constants_info);

}


static void
vk_free_cmd_push_descriptor_set2(struct vk_cmd_queue *queue,
                                 struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.push_descriptor_set2.push_descriptor_set_info) {
      const VkBaseInStructure *pnext1 = cmd->u.push_descriptor_set2.push_descriptor_set_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO: {
            VkDescriptorSetLayout *pSetLayouts2 = (void *)(((VkPipelineLayoutCreateInfo *)pnext1)->pSetLayouts);
            if (((VkPipelineLayoutCreateInfo *)pnext1)->setLayoutCount) {
            }
            vk_free(queue->alloc, pSetLayouts2);
            VkPushConstantRange *pPushConstantRanges3 = (void *)(((VkPipelineLayoutCreateInfo *)pnext1)->pPushConstantRanges);
            if (((VkPipelineLayoutCreateInfo *)pnext1)->pushConstantRangeCount) {
            }
            vk_free(queue->alloc, pPushConstantRanges3);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
      VkWriteDescriptorSet *pDescriptorWrites4 = (void *)(cmd->u.push_descriptor_set2.push_descriptor_set_info->pDescriptorWrites);
      if (cmd->u.push_descriptor_set2.push_descriptor_set_info->descriptorWriteCount) {
         const VkBaseInStructure *pnext5 = pDescriptorWrites4->pNext;
         if (pnext5) {
            switch ((int32_t)pnext5->sType) {
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK: {
               void *pData6 = (void *)(((VkWriteDescriptorSetInlineUniformBlock *)pnext5)->pData);
               if (((VkWriteDescriptorSetInlineUniformBlock *)pnext5)->dataSize) {
               }
               vk_free(queue->alloc, pData6);
               vk_free(queue->alloc, (void*)pnext5);
               break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR: {
               VkAccelerationStructureKHR *pAccelerationStructures7 = (void *)(((VkWriteDescriptorSetAccelerationStructureKHR *)pnext5)->pAccelerationStructures);
               if (((VkWriteDescriptorSetAccelerationStructureKHR *)pnext5)->accelerationStructureCount) {
               }
               vk_free(queue->alloc, pAccelerationStructures7);
               vk_free(queue->alloc, (void*)pnext5);
               break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV: {
               VkAccelerationStructureNV *pAccelerationStructures8 = (void *)(((VkWriteDescriptorSetAccelerationStructureNV *)pnext5)->pAccelerationStructures);
               if (((VkWriteDescriptorSetAccelerationStructureNV *)pnext5)->accelerationStructureCount) {
               }
               vk_free(queue->alloc, pAccelerationStructures8);
               vk_free(queue->alloc, (void*)pnext5);
               break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_PARTITIONED_ACCELERATION_STRUCTURE_NV: {
               VkDeviceAddress *pAccelerationStructures9 = (void *)(((VkWriteDescriptorSetPartitionedAccelerationStructureNV *)pnext5)->pAccelerationStructures);
               if (((VkWriteDescriptorSetPartitionedAccelerationStructureNV *)pnext5)->accelerationStructureCount) {
               }
               vk_free(queue->alloc, pAccelerationStructures9);
               vk_free(queue->alloc, (void*)pnext5);
               break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_TENSOR_ARM: {
               VkTensorViewARM *pTensorViews10 = (void *)(((VkWriteDescriptorSetTensorARM *)pnext5)->pTensorViews);
               if (((VkWriteDescriptorSetTensorARM *)pnext5)->tensorViewCount) {
               }
               vk_free(queue->alloc, pTensorViews10);
               vk_free(queue->alloc, (void*)pnext5);
               break;
            }
            }
         }
         VkDescriptorImageInfo *pImageInfo11 = (void *)(pDescriptorWrites4->pImageInfo);
         if (pDescriptorWrites4->descriptorCount) {
         }
         vk_free(queue->alloc, pImageInfo11);
         VkDescriptorBufferInfo *pBufferInfo12 = (void *)(pDescriptorWrites4->pBufferInfo);
         if (pDescriptorWrites4->descriptorCount) {
         }
         vk_free(queue->alloc, pBufferInfo12);
         VkBufferView *pTexelBufferView13 = (void *)(pDescriptorWrites4->pTexelBufferView);
         if (pDescriptorWrites4->descriptorCount) {
         }
         vk_free(queue->alloc, pTexelBufferView13);
      }
      vk_free(queue->alloc, pDescriptorWrites4);
   }
   vk_free(queue->alloc, (void*)cmd->u.push_descriptor_set2.push_descriptor_set_info);

}


static void
vk_free_cmd_push_descriptor_set_with_template2(struct vk_cmd_queue *queue,
                                               struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.push_descriptor_set_with_template2.push_descriptor_set_with_template_info) {
      const VkBaseInStructure *pnext1 = cmd->u.push_descriptor_set_with_template2.push_descriptor_set_with_template_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO: {
            VkDescriptorSetLayout *pSetLayouts2 = (void *)(((VkPipelineLayoutCreateInfo *)pnext1)->pSetLayouts);
            if (((VkPipelineLayoutCreateInfo *)pnext1)->setLayoutCount) {
            }
            vk_free(queue->alloc, pSetLayouts2);
            VkPushConstantRange *pPushConstantRanges3 = (void *)(((VkPipelineLayoutCreateInfo *)pnext1)->pPushConstantRanges);
            if (((VkPipelineLayoutCreateInfo *)pnext1)->pushConstantRangeCount) {
            }
            vk_free(queue->alloc, pPushConstantRanges3);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
      void *pData4 = (void *)(cmd->u.push_descriptor_set_with_template2.push_descriptor_set_with_template_info->pData);
      vk_free(queue->alloc, pData4);
   }
   vk_free(queue->alloc, (void*)cmd->u.push_descriptor_set_with_template2.push_descriptor_set_with_template_info);

}


static void
vk_free_cmd_set_descriptor_buffer_offsets2_ext(struct vk_cmd_queue *queue,
                                               struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.set_descriptor_buffer_offsets2_ext.set_descriptor_buffer_offsets_info) {
      const VkBaseInStructure *pnext1 = cmd->u.set_descriptor_buffer_offsets2_ext.set_descriptor_buffer_offsets_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO: {
            VkDescriptorSetLayout *pSetLayouts2 = (void *)(((VkPipelineLayoutCreateInfo *)pnext1)->pSetLayouts);
            if (((VkPipelineLayoutCreateInfo *)pnext1)->setLayoutCount) {
            }
            vk_free(queue->alloc, pSetLayouts2);
            VkPushConstantRange *pPushConstantRanges3 = (void *)(((VkPipelineLayoutCreateInfo *)pnext1)->pPushConstantRanges);
            if (((VkPipelineLayoutCreateInfo *)pnext1)->pushConstantRangeCount) {
            }
            vk_free(queue->alloc, pPushConstantRanges3);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
      uint32_t *pBufferIndices4 = (void *)(cmd->u.set_descriptor_buffer_offsets2_ext.set_descriptor_buffer_offsets_info->pBufferIndices);
      if (cmd->u.set_descriptor_buffer_offsets2_ext.set_descriptor_buffer_offsets_info->setCount) {
      }
      vk_free(queue->alloc, pBufferIndices4);
      VkDeviceSize *pOffsets5 = (void *)(cmd->u.set_descriptor_buffer_offsets2_ext.set_descriptor_buffer_offsets_info->pOffsets);
      if (cmd->u.set_descriptor_buffer_offsets2_ext.set_descriptor_buffer_offsets_info->setCount) {
      }
      vk_free(queue->alloc, pOffsets5);
   }
   vk_free(queue->alloc, (void*)cmd->u.set_descriptor_buffer_offsets2_ext.set_descriptor_buffer_offsets_info);

}

VkResult vk_enqueue_cmd_set_descriptor_buffer_offsets2_ext(struct vk_cmd_queue *queue
, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_DESCRIPTOR_BUFFER_OFFSETS2_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_DESCRIPTOR_BUFFER_OFFSETS2_EXT;
   if (pSetDescriptorBufferOffsetsInfo) {
      cmd->u.set_descriptor_buffer_offsets2_ext.set_descriptor_buffer_offsets_info = vk_zalloc(queue->alloc, sizeof(VkSetDescriptorBufferOffsetsInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.set_descriptor_buffer_offsets2_ext.set_descriptor_buffer_offsets_info == NULL) goto err;
      VkSetDescriptorBufferOffsetsInfoEXT *tmp_dst1 = (void *)cmd->u.set_descriptor_buffer_offsets2_ext.set_descriptor_buffer_offsets_info;
      VkSetDescriptorBufferOffsetsInfoEXT *tmp_src2 = (void *)pSetDescriptorBufferOffsetsInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkSetDescriptorBufferOffsetsInfoEXT));
      const VkBaseInStructure *pnext = tmp_dst1->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkPipelineLayoutCreateInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkPipelineLayoutCreateInfo *tmp_dst3 = (void *)tmp_dst1->pNext;
               VkPipelineLayoutCreateInfo *tmp_src4 = (void *)pnext;
               memcpy(tmp_dst3, tmp_src4, sizeof(VkPipelineLayoutCreateInfo));
               if (tmp_src4->pSetLayouts) {
                  tmp_dst3->pSetLayouts = vk_zalloc(queue->alloc, sizeof(VkDescriptorSetLayout) * tmp_src4->setLayoutCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst3->pSetLayouts == NULL) goto err;
                  VkDescriptorSetLayout *tmp_dst5 = (void *)tmp_dst3->pSetLayouts;
                  VkDescriptorSetLayout *tmp_src6 = (void *)tmp_src4->pSetLayouts;
                  memcpy(tmp_dst5, tmp_src6, sizeof(VkDescriptorSetLayout) * tmp_src4->setLayoutCount);
                  for (uint32_t i7 = 0; i7 < tmp_src4->setLayoutCount; i7++) {
                     VkDescriptorSetLayout *tmp_dst8 = tmp_dst5 + i7; (void)tmp_dst8;
                     VkDescriptorSetLayout *tmp_src9 = tmp_src6 + i7; (void)tmp_src9;
                     }
                  } else {
                     tmp_dst3->pSetLayouts = NULL;
                  }
                  if (tmp_src4->pPushConstantRanges) {
                     tmp_dst3->pPushConstantRanges = vk_zalloc(queue->alloc, sizeof(VkPushConstantRange) * tmp_src4->pushConstantRangeCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst3->pPushConstantRanges == NULL) goto err;
                     VkPushConstantRange *tmp_dst10 = (void *)tmp_dst3->pPushConstantRanges;
                     VkPushConstantRange *tmp_src11 = (void *)tmp_src4->pPushConstantRanges;
                     memcpy(tmp_dst10, tmp_src11, sizeof(VkPushConstantRange) * tmp_src4->pushConstantRangeCount);
                     for (uint32_t i12 = 0; i12 < tmp_src4->pushConstantRangeCount; i12++) {
                        VkPushConstantRange *tmp_dst13 = tmp_dst10 + i12; (void)tmp_dst13;
                        VkPushConstantRange *tmp_src14 = tmp_src11 + i12; (void)tmp_src14;
                        }
                     } else {
                        tmp_dst3->pPushConstantRanges = NULL;
                     }
                  } else {
                     tmp_dst1->pNext = NULL;
                  }
                  break;
               }
            }
            if (tmp_src2->pBufferIndices) {
               tmp_dst1->pBufferIndices = vk_zalloc(queue->alloc, sizeof(uint32_t) * tmp_src2->setCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pBufferIndices == NULL) goto err;
               uint32_t *tmp_dst15 = (void *)tmp_dst1->pBufferIndices;
               uint32_t *tmp_src16 = (void *)tmp_src2->pBufferIndices;
               memcpy(tmp_dst15, tmp_src16, sizeof(uint32_t) * tmp_src2->setCount);
               for (uint32_t i17 = 0; i17 < tmp_src2->setCount; i17++) {
                  uint32_t *tmp_dst18 = tmp_dst15 + i17; (void)tmp_dst18;
                  uint32_t *tmp_src19 = tmp_src16 + i17; (void)tmp_src19;
                  }
               } else {
                  tmp_dst1->pBufferIndices = NULL;
               }
               if (tmp_src2->pOffsets) {
                  tmp_dst1->pOffsets = vk_zalloc(queue->alloc, sizeof(VkDeviceSize) * tmp_src2->setCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst1->pOffsets == NULL) goto err;
                  VkDeviceSize *tmp_dst20 = (void *)tmp_dst1->pOffsets;
                  VkDeviceSize *tmp_src21 = (void *)tmp_src2->pOffsets;
                  memcpy(tmp_dst20, tmp_src21, sizeof(VkDeviceSize) * tmp_src2->setCount);
                  for (uint32_t i22 = 0; i22 < tmp_src2->setCount; i22++) {
                     VkDeviceSize *tmp_dst23 = tmp_dst20 + i22; (void)tmp_dst23;
                     VkDeviceSize *tmp_src24 = tmp_src21 + i22; (void)tmp_src24;
                     }
                  } else {
                     tmp_dst1->pOffsets = NULL;
                  }
               } else {
                  cmd->u.set_descriptor_buffer_offsets2_ext.set_descriptor_buffer_offsets_info = NULL;
               }

               list_addtail(&cmd->cmd_link, &queue->cmds);
               return VK_SUCCESS;

err:
               if (cmd)
                  vk_free_cmd_set_descriptor_buffer_offsets2_ext(queue, cmd);
               return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_bind_descriptor_buffer_embedded_samplers2_ext(struct vk_cmd_queue *queue,
                                                          struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.bind_descriptor_buffer_embedded_samplers2_ext.bind_descriptor_buffer_embedded_samplers_info) {
      const VkBaseInStructure *pnext1 = cmd->u.bind_descriptor_buffer_embedded_samplers2_ext.bind_descriptor_buffer_embedded_samplers_info->pNext;
      if (pnext1) {
         switch ((int32_t)pnext1->sType) {
         case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO: {
            VkDescriptorSetLayout *pSetLayouts2 = (void *)(((VkPipelineLayoutCreateInfo *)pnext1)->pSetLayouts);
            if (((VkPipelineLayoutCreateInfo *)pnext1)->setLayoutCount) {
            }
            vk_free(queue->alloc, pSetLayouts2);
            VkPushConstantRange *pPushConstantRanges3 = (void *)(((VkPipelineLayoutCreateInfo *)pnext1)->pPushConstantRanges);
            if (((VkPipelineLayoutCreateInfo *)pnext1)->pushConstantRangeCount) {
            }
            vk_free(queue->alloc, pPushConstantRanges3);
            vk_free(queue->alloc, (void*)pnext1);
            break;
         }
         }
      }
   }
   vk_free(queue->alloc, (void*)cmd->u.bind_descriptor_buffer_embedded_samplers2_ext.bind_descriptor_buffer_embedded_samplers_info);

}

VkResult vk_enqueue_cmd_bind_descriptor_buffer_embedded_samplers2_ext(struct vk_cmd_queue *queue
, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS2_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS2_EXT;
   if (pBindDescriptorBufferEmbeddedSamplersInfo) {
      cmd->u.bind_descriptor_buffer_embedded_samplers2_ext.bind_descriptor_buffer_embedded_samplers_info = vk_zalloc(queue->alloc, sizeof(VkBindDescriptorBufferEmbeddedSamplersInfoEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.bind_descriptor_buffer_embedded_samplers2_ext.bind_descriptor_buffer_embedded_samplers_info == NULL) goto err;
      VkBindDescriptorBufferEmbeddedSamplersInfoEXT *tmp_dst1 = (void *)cmd->u.bind_descriptor_buffer_embedded_samplers2_ext.bind_descriptor_buffer_embedded_samplers_info;
      VkBindDescriptorBufferEmbeddedSamplersInfoEXT *tmp_src2 = (void *)pBindDescriptorBufferEmbeddedSamplersInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkBindDescriptorBufferEmbeddedSamplersInfoEXT));
      const VkBaseInStructure *pnext = tmp_dst1->pNext;
      if (pnext) {
         switch ((int32_t)pnext->sType) {
         case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
            if (pnext) {
               tmp_dst1->pNext = vk_zalloc(queue->alloc, sizeof(VkPipelineLayoutCreateInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst1->pNext == NULL) goto err;
               VkPipelineLayoutCreateInfo *tmp_dst3 = (void *)tmp_dst1->pNext;
               VkPipelineLayoutCreateInfo *tmp_src4 = (void *)pnext;
               memcpy(tmp_dst3, tmp_src4, sizeof(VkPipelineLayoutCreateInfo));
               if (tmp_src4->pSetLayouts) {
                  tmp_dst3->pSetLayouts = vk_zalloc(queue->alloc, sizeof(VkDescriptorSetLayout) * tmp_src4->setLayoutCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst3->pSetLayouts == NULL) goto err;
                  VkDescriptorSetLayout *tmp_dst5 = (void *)tmp_dst3->pSetLayouts;
                  VkDescriptorSetLayout *tmp_src6 = (void *)tmp_src4->pSetLayouts;
                  memcpy(tmp_dst5, tmp_src6, sizeof(VkDescriptorSetLayout) * tmp_src4->setLayoutCount);
                  for (uint32_t i7 = 0; i7 < tmp_src4->setLayoutCount; i7++) {
                     VkDescriptorSetLayout *tmp_dst8 = tmp_dst5 + i7; (void)tmp_dst8;
                     VkDescriptorSetLayout *tmp_src9 = tmp_src6 + i7; (void)tmp_src9;
                     }
                  } else {
                     tmp_dst3->pSetLayouts = NULL;
                  }
                  if (tmp_src4->pPushConstantRanges) {
                     tmp_dst3->pPushConstantRanges = vk_zalloc(queue->alloc, sizeof(VkPushConstantRange) * tmp_src4->pushConstantRangeCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst3->pPushConstantRanges == NULL) goto err;
                     VkPushConstantRange *tmp_dst10 = (void *)tmp_dst3->pPushConstantRanges;
                     VkPushConstantRange *tmp_src11 = (void *)tmp_src4->pPushConstantRanges;
                     memcpy(tmp_dst10, tmp_src11, sizeof(VkPushConstantRange) * tmp_src4->pushConstantRangeCount);
                     for (uint32_t i12 = 0; i12 < tmp_src4->pushConstantRangeCount; i12++) {
                        VkPushConstantRange *tmp_dst13 = tmp_dst10 + i12; (void)tmp_dst13;
                        VkPushConstantRange *tmp_src14 = tmp_src11 + i12; (void)tmp_src14;
                        }
                     } else {
                        tmp_dst3->pPushConstantRanges = NULL;
                     }
                  } else {
                     tmp_dst1->pNext = NULL;
                  }
                  break;
               }
            }
         } else {
            cmd->u.bind_descriptor_buffer_embedded_samplers2_ext.bind_descriptor_buffer_embedded_samplers_info = NULL;
         }

         list_addtail(&cmd->cmd_link, &queue->cmds);
         return VK_SUCCESS;

err:
         if (cmd)
            vk_free_cmd_bind_descriptor_buffer_embedded_samplers2_ext(queue, cmd);
         return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_rendering_attachment_locations(struct vk_cmd_queue *queue,
                                               struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.set_rendering_attachment_locations.location_info) {
      uint32_t *pColorAttachmentLocations1 = (void *)(cmd->u.set_rendering_attachment_locations.location_info->pColorAttachmentLocations);
      if (cmd->u.set_rendering_attachment_locations.location_info->colorAttachmentCount) {
      }
      vk_free(queue->alloc, pColorAttachmentLocations1);
   }
   vk_free(queue->alloc, (void*)cmd->u.set_rendering_attachment_locations.location_info);

}

VkResult vk_enqueue_cmd_set_rendering_attachment_locations(struct vk_cmd_queue *queue
, const VkRenderingAttachmentLocationInfo* pLocationInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_RENDERING_ATTACHMENT_LOCATIONS], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_RENDERING_ATTACHMENT_LOCATIONS;
   if (pLocationInfo) {
      cmd->u.set_rendering_attachment_locations.location_info = vk_zalloc(queue->alloc, sizeof(VkRenderingAttachmentLocationInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.set_rendering_attachment_locations.location_info == NULL) goto err;
      VkRenderingAttachmentLocationInfo *tmp_dst1 = (void *)cmd->u.set_rendering_attachment_locations.location_info;
      VkRenderingAttachmentLocationInfo *tmp_src2 = (void *)pLocationInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkRenderingAttachmentLocationInfo));
      if (tmp_src2->pColorAttachmentLocations) {
         tmp_dst1->pColorAttachmentLocations = vk_zalloc(queue->alloc, sizeof(uint32_t) * tmp_src2->colorAttachmentCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pColorAttachmentLocations == NULL) goto err;
         uint32_t *tmp_dst3 = (void *)tmp_dst1->pColorAttachmentLocations;
         uint32_t *tmp_src4 = (void *)tmp_src2->pColorAttachmentLocations;
         memcpy(tmp_dst3, tmp_src4, sizeof(uint32_t) * tmp_src2->colorAttachmentCount);
         for (uint32_t i5 = 0; i5 < tmp_src2->colorAttachmentCount; i5++) {
            uint32_t *tmp_dst6 = tmp_dst3 + i5; (void)tmp_dst6;
            uint32_t *tmp_src7 = tmp_src4 + i5; (void)tmp_src7;
            }
         } else {
            tmp_dst1->pColorAttachmentLocations = NULL;
         }
      } else {
         cmd->u.set_rendering_attachment_locations.location_info = NULL;
      }

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_set_rendering_attachment_locations(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_rendering_input_attachment_indices(struct vk_cmd_queue *queue,
                                                   struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.set_rendering_input_attachment_indices.input_attachment_index_info) {
      uint32_t *pColorAttachmentInputIndices1 = (void *)(cmd->u.set_rendering_input_attachment_indices.input_attachment_index_info->pColorAttachmentInputIndices);
      if (cmd->u.set_rendering_input_attachment_indices.input_attachment_index_info->colorAttachmentCount) {
      }
      vk_free(queue->alloc, pColorAttachmentInputIndices1);
      uint32_t *pDepthInputAttachmentIndex2 = (void *)(cmd->u.set_rendering_input_attachment_indices.input_attachment_index_info->pDepthInputAttachmentIndex);
      vk_free(queue->alloc, pDepthInputAttachmentIndex2);
      uint32_t *pStencilInputAttachmentIndex3 = (void *)(cmd->u.set_rendering_input_attachment_indices.input_attachment_index_info->pStencilInputAttachmentIndex);
      vk_free(queue->alloc, pStencilInputAttachmentIndex3);
   }
   vk_free(queue->alloc, (void*)cmd->u.set_rendering_input_attachment_indices.input_attachment_index_info);

}

VkResult vk_enqueue_cmd_set_rendering_input_attachment_indices(struct vk_cmd_queue *queue
, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_RENDERING_INPUT_ATTACHMENT_INDICES], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_RENDERING_INPUT_ATTACHMENT_INDICES;
   if (pInputAttachmentIndexInfo) {
      cmd->u.set_rendering_input_attachment_indices.input_attachment_index_info = vk_zalloc(queue->alloc, sizeof(VkRenderingInputAttachmentIndexInfo), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.set_rendering_input_attachment_indices.input_attachment_index_info == NULL) goto err;
      VkRenderingInputAttachmentIndexInfo *tmp_dst1 = (void *)cmd->u.set_rendering_input_attachment_indices.input_attachment_index_info;
      VkRenderingInputAttachmentIndexInfo *tmp_src2 = (void *)pInputAttachmentIndexInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkRenderingInputAttachmentIndexInfo));
      if (tmp_src2->pColorAttachmentInputIndices) {
         tmp_dst1->pColorAttachmentInputIndices = vk_zalloc(queue->alloc, sizeof(uint32_t) * tmp_src2->colorAttachmentCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pColorAttachmentInputIndices == NULL) goto err;
         uint32_t *tmp_dst3 = (void *)tmp_dst1->pColorAttachmentInputIndices;
         uint32_t *tmp_src4 = (void *)tmp_src2->pColorAttachmentInputIndices;
         memcpy(tmp_dst3, tmp_src4, sizeof(uint32_t) * tmp_src2->colorAttachmentCount);
         for (uint32_t i5 = 0; i5 < tmp_src2->colorAttachmentCount; i5++) {
            uint32_t *tmp_dst6 = tmp_dst3 + i5; (void)tmp_dst6;
            uint32_t *tmp_src7 = tmp_src4 + i5; (void)tmp_src7;
            }
         } else {
            tmp_dst1->pColorAttachmentInputIndices = NULL;
         }
         if (tmp_src2->pDepthInputAttachmentIndex) {
            tmp_dst1->pDepthInputAttachmentIndex = vk_zalloc(queue->alloc, sizeof(uint32_t), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
            if (tmp_dst1->pDepthInputAttachmentIndex == NULL) goto err;
            uint32_t *tmp_dst8 = (void *)tmp_dst1->pDepthInputAttachmentIndex;
            uint32_t *tmp_src9 = (void *)tmp_src2->pDepthInputAttachmentIndex;
            memcpy(tmp_dst8, tmp_src9, sizeof(uint32_t));
         } else {
            tmp_dst1->pDepthInputAttachmentIndex = NULL;
         }
         if (tmp_src2->pStencilInputAttachmentIndex) {
            tmp_dst1->pStencilInputAttachmentIndex = vk_zalloc(queue->alloc, sizeof(uint32_t), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
            if (tmp_dst1->pStencilInputAttachmentIndex == NULL) goto err;
            uint32_t *tmp_dst10 = (void *)tmp_dst1->pStencilInputAttachmentIndex;
            uint32_t *tmp_src11 = (void *)tmp_src2->pStencilInputAttachmentIndex;
            memcpy(tmp_dst10, tmp_src11, sizeof(uint32_t));
         } else {
            tmp_dst1->pStencilInputAttachmentIndex = NULL;
         }
      } else {
         cmd->u.set_rendering_input_attachment_indices.input_attachment_index_info = NULL;
      }

      list_addtail(&cmd->cmd_link, &queue->cmds);
      return VK_SUCCESS;

err:
      if (cmd)
         vk_free_cmd_set_rendering_input_attachment_indices(queue, cmd);
      return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_set_depth_clamp_range_ext(struct vk_cmd_queue *queue,
                                      struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.set_depth_clamp_range_ext.depth_clamp_range) {
   }
   vk_free(queue->alloc, (void*)cmd->u.set_depth_clamp_range_ext.depth_clamp_range);

}

VkResult vk_enqueue_cmd_set_depth_clamp_range_ext(struct vk_cmd_queue *queue
, VkDepthClampModeEXT depthClampMode
, const VkDepthClampRangeEXT* pDepthClampRange
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_SET_DEPTH_CLAMP_RANGE_EXT], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_SET_DEPTH_CLAMP_RANGE_EXT;
   cmd->u.set_depth_clamp_range_ext.depth_clamp_mode = depthClampMode;
   if (pDepthClampRange) {
      cmd->u.set_depth_clamp_range_ext.depth_clamp_range = vk_zalloc(queue->alloc, sizeof(VkDepthClampRangeEXT), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.set_depth_clamp_range_ext.depth_clamp_range == NULL) goto err;
      VkDepthClampRangeEXT *tmp_dst1 = (void *)cmd->u.set_depth_clamp_range_ext.depth_clamp_range;
      VkDepthClampRangeEXT *tmp_src2 = (void *)pDepthClampRange;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkDepthClampRangeEXT));
   } else {
      cmd->u.set_depth_clamp_range_ext.depth_clamp_range = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_set_depth_clamp_range_ext(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_convert_cooperative_vector_matrix_nv(struct vk_cmd_queue *queue,
                                                 struct vk_cmd_queue_entry *cmd)
{
   vk_free(queue->alloc, ( VkConvertCooperativeVectorMatrixInfoNV* )cmd->u.convert_cooperative_vector_matrix_nv.infos);
}

VkResult vk_enqueue_cmd_convert_cooperative_vector_matrix_nv(struct vk_cmd_queue *queue
, uint32_t infoCount
, const VkConvertCooperativeVectorMatrixInfoNV* pInfos
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_CONVERT_COOPERATIVE_VECTOR_MATRIX_NV], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_CONVERT_COOPERATIVE_VECTOR_MATRIX_NV;
   cmd->u.convert_cooperative_vector_matrix_nv.info_count = infoCount;
   if (pInfos) {
      cmd->u.convert_cooperative_vector_matrix_nv.infos = vk_zalloc(queue->alloc, sizeof(*cmd->u.convert_cooperative_vector_matrix_nv.infos) * (infoCount), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (cmd->u.convert_cooperative_vector_matrix_nv.infos == NULL) goto err;
      memcpy((void*)cmd->u.convert_cooperative_vector_matrix_nv.infos, pInfos, sizeof(*cmd->u.convert_cooperative_vector_matrix_nv.infos) * (infoCount));
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_convert_cooperative_vector_matrix_nv(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_dispatch_tile_qcom(struct vk_cmd_queue *queue,
                               struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.dispatch_tile_qcom.dispatch_tile_info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.dispatch_tile_qcom.dispatch_tile_info);

}

VkResult vk_enqueue_cmd_dispatch_tile_qcom(struct vk_cmd_queue *queue
, const VkDispatchTileInfoQCOM* pDispatchTileInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DISPATCH_TILE_QCOM], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DISPATCH_TILE_QCOM;
   if (pDispatchTileInfo) {
      cmd->u.dispatch_tile_qcom.dispatch_tile_info = vk_zalloc(queue->alloc, sizeof(VkDispatchTileInfoQCOM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.dispatch_tile_qcom.dispatch_tile_info == NULL) goto err;
      VkDispatchTileInfoQCOM *tmp_dst1 = (void *)cmd->u.dispatch_tile_qcom.dispatch_tile_info;
      VkDispatchTileInfoQCOM *tmp_src2 = (void *)pDispatchTileInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkDispatchTileInfoQCOM));
   } else {
      cmd->u.dispatch_tile_qcom.dispatch_tile_info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_dispatch_tile_qcom(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_begin_per_tile_execution_qcom(struct vk_cmd_queue *queue,
                                          struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.begin_per_tile_execution_qcom.per_tile_begin_info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.begin_per_tile_execution_qcom.per_tile_begin_info);

}

VkResult vk_enqueue_cmd_begin_per_tile_execution_qcom(struct vk_cmd_queue *queue
, const VkPerTileBeginInfoQCOM* pPerTileBeginInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_BEGIN_PER_TILE_EXECUTION_QCOM], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_BEGIN_PER_TILE_EXECUTION_QCOM;
   if (pPerTileBeginInfo) {
      cmd->u.begin_per_tile_execution_qcom.per_tile_begin_info = vk_zalloc(queue->alloc, sizeof(VkPerTileBeginInfoQCOM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.begin_per_tile_execution_qcom.per_tile_begin_info == NULL) goto err;
      VkPerTileBeginInfoQCOM *tmp_dst1 = (void *)cmd->u.begin_per_tile_execution_qcom.per_tile_begin_info;
      VkPerTileBeginInfoQCOM *tmp_src2 = (void *)pPerTileBeginInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkPerTileBeginInfoQCOM));
   } else {
      cmd->u.begin_per_tile_execution_qcom.per_tile_begin_info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_begin_per_tile_execution_qcom(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_end_per_tile_execution_qcom(struct vk_cmd_queue *queue,
                                        struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.end_per_tile_execution_qcom.per_tile_end_info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.end_per_tile_execution_qcom.per_tile_end_info);

}

VkResult vk_enqueue_cmd_end_per_tile_execution_qcom(struct vk_cmd_queue *queue
, const VkPerTileEndInfoQCOM* pPerTileEndInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_END_PER_TILE_EXECUTION_QCOM], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_END_PER_TILE_EXECUTION_QCOM;
   if (pPerTileEndInfo) {
      cmd->u.end_per_tile_execution_qcom.per_tile_end_info = vk_zalloc(queue->alloc, sizeof(VkPerTileEndInfoQCOM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.end_per_tile_execution_qcom.per_tile_end_info == NULL) goto err;
      VkPerTileEndInfoQCOM *tmp_dst1 = (void *)cmd->u.end_per_tile_execution_qcom.per_tile_end_info;
      VkPerTileEndInfoQCOM *tmp_src2 = (void *)pPerTileEndInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkPerTileEndInfoQCOM));
   } else {
      cmd->u.end_per_tile_execution_qcom.per_tile_end_info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_end_per_tile_execution_qcom(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_copy_tensor_arm(struct vk_cmd_queue *queue,
                            struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.copy_tensor_arm.copy_tensor_info) {
      VkTensorCopyARM *pRegions1 = (void *)(cmd->u.copy_tensor_arm.copy_tensor_info->pRegions);
      if (cmd->u.copy_tensor_arm.copy_tensor_info->regionCount) {
         uint64_t *pSrcOffset2 = (void *)(pRegions1->pSrcOffset);
         if (pRegions1->dimensionCount) {
         }
         vk_free(queue->alloc, pSrcOffset2);
         uint64_t *pDstOffset3 = (void *)(pRegions1->pDstOffset);
         if (pRegions1->dimensionCount) {
         }
         vk_free(queue->alloc, pDstOffset3);
         uint64_t *pExtent4 = (void *)(pRegions1->pExtent);
         if (pRegions1->dimensionCount) {
         }
         vk_free(queue->alloc, pExtent4);
      }
      vk_free(queue->alloc, pRegions1);
   }
   vk_free(queue->alloc, (void*)cmd->u.copy_tensor_arm.copy_tensor_info);

}

VkResult vk_enqueue_cmd_copy_tensor_arm(struct vk_cmd_queue *queue
,  const VkCopyTensorInfoARM* pCopyTensorInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_COPY_TENSOR_ARM], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_COPY_TENSOR_ARM;
   if (pCopyTensorInfo) {
      cmd->u.copy_tensor_arm.copy_tensor_info = vk_zalloc(queue->alloc, sizeof(VkCopyTensorInfoARM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.copy_tensor_arm.copy_tensor_info == NULL) goto err;
      VkCopyTensorInfoARM *tmp_dst1 = (void *)cmd->u.copy_tensor_arm.copy_tensor_info;
      VkCopyTensorInfoARM *tmp_src2 = (void *)pCopyTensorInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkCopyTensorInfoARM));
      if (tmp_src2->pRegions) {
         tmp_dst1->pRegions = vk_zalloc(queue->alloc, sizeof(VkTensorCopyARM) * tmp_src2->regionCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
         if (tmp_dst1->pRegions == NULL) goto err;
         VkTensorCopyARM *tmp_dst3 = (void *)tmp_dst1->pRegions;
         VkTensorCopyARM *tmp_src4 = (void *)tmp_src2->pRegions;
         memcpy(tmp_dst3, tmp_src4, sizeof(VkTensorCopyARM) * tmp_src2->regionCount);
         for (uint32_t i5 = 0; i5 < tmp_src2->regionCount; i5++) {
            VkTensorCopyARM *tmp_dst6 = tmp_dst3 + i5; (void)tmp_dst6;
            VkTensorCopyARM *tmp_src7 = tmp_src4 + i5; (void)tmp_src7;
            if (tmp_src7->pSrcOffset) {
               tmp_dst6->pSrcOffset = vk_zalloc(queue->alloc, sizeof(uint64_t) * tmp_src7->dimensionCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
               if (tmp_dst6->pSrcOffset == NULL) goto err;
               uint64_t *tmp_dst8 = (void *)tmp_dst6->pSrcOffset;
               uint64_t *tmp_src9 = (void *)tmp_src7->pSrcOffset;
               memcpy(tmp_dst8, tmp_src9, sizeof(uint64_t) * tmp_src7->dimensionCount);
               for (uint32_t i10 = 0; i10 < tmp_src7->dimensionCount; i10++) {
                  uint64_t *tmp_dst11 = tmp_dst8 + i10; (void)tmp_dst11;
                  uint64_t *tmp_src12 = tmp_src9 + i10; (void)tmp_src12;
                  }
               } else {
                  tmp_dst6->pSrcOffset = NULL;
               }
               if (tmp_src7->pDstOffset) {
                  tmp_dst6->pDstOffset = vk_zalloc(queue->alloc, sizeof(uint64_t) * tmp_src7->dimensionCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                  if (tmp_dst6->pDstOffset == NULL) goto err;
                  uint64_t *tmp_dst13 = (void *)tmp_dst6->pDstOffset;
                  uint64_t *tmp_src14 = (void *)tmp_src7->pDstOffset;
                  memcpy(tmp_dst13, tmp_src14, sizeof(uint64_t) * tmp_src7->dimensionCount);
                  for (uint32_t i15 = 0; i15 < tmp_src7->dimensionCount; i15++) {
                     uint64_t *tmp_dst16 = tmp_dst13 + i15; (void)tmp_dst16;
                     uint64_t *tmp_src17 = tmp_src14 + i15; (void)tmp_src17;
                     }
                  } else {
                     tmp_dst6->pDstOffset = NULL;
                  }
                  if (tmp_src7->pExtent) {
                     tmp_dst6->pExtent = vk_zalloc(queue->alloc, sizeof(uint64_t) * tmp_src7->dimensionCount, 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
                     if (tmp_dst6->pExtent == NULL) goto err;
                     uint64_t *tmp_dst18 = (void *)tmp_dst6->pExtent;
                     uint64_t *tmp_src19 = (void *)tmp_src7->pExtent;
                     memcpy(tmp_dst18, tmp_src19, sizeof(uint64_t) * tmp_src7->dimensionCount);
                     for (uint32_t i20 = 0; i20 < tmp_src7->dimensionCount; i20++) {
                        uint64_t *tmp_dst21 = tmp_dst18 + i20; (void)tmp_dst21;
                        uint64_t *tmp_src22 = tmp_src19 + i20; (void)tmp_src22;
                        }
                     } else {
                        tmp_dst6->pExtent = NULL;
                     }
                     }
                  } else {
                     tmp_dst1->pRegions = NULL;
                  }
               } else {
                  cmd->u.copy_tensor_arm.copy_tensor_info = NULL;
               }

               list_addtail(&cmd->cmd_link, &queue->cmds);
               return VK_SUCCESS;

err:
               if (cmd)
                  vk_free_cmd_copy_tensor_arm(queue, cmd);
               return VK_ERROR_OUT_OF_HOST_MEMORY;
}

static void
vk_free_cmd_dispatch_data_graph_arm(struct vk_cmd_queue *queue,
                                    struct vk_cmd_queue_entry *cmd)
{
   if (cmd->u.dispatch_data_graph_arm.info) {
   }
   vk_free(queue->alloc, (void*)cmd->u.dispatch_data_graph_arm.info);

}

VkResult vk_enqueue_cmd_dispatch_data_graph_arm(struct vk_cmd_queue *queue
, VkDataGraphPipelineSessionARM session
, const VkDataGraphPipelineDispatchInfoARM* pInfo
)
{
   struct vk_cmd_queue_entry *cmd = vk_zalloc(queue->alloc, vk_cmd_queue_type_sizes[VK_CMD_DISPATCH_DATA_GRAPH_ARM], 8,
                                              VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!cmd) return VK_ERROR_OUT_OF_HOST_MEMORY;

   cmd->type = VK_CMD_DISPATCH_DATA_GRAPH_ARM;
   cmd->u.dispatch_data_graph_arm.session = session;
   if (pInfo) {
      cmd->u.dispatch_data_graph_arm.info = vk_zalloc(queue->alloc, sizeof(VkDataGraphPipelineDispatchInfoARM), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
      if (cmd->u.dispatch_data_graph_arm.info == NULL) goto err;
      VkDataGraphPipelineDispatchInfoARM *tmp_dst1 = (void *)cmd->u.dispatch_data_graph_arm.info;
      VkDataGraphPipelineDispatchInfoARM *tmp_src2 = (void *)pInfo;
      memcpy(tmp_dst1, tmp_src2, sizeof(VkDataGraphPipelineDispatchInfoARM));
   } else {
      cmd->u.dispatch_data_graph_arm.info = NULL;
   }

   list_addtail(&cmd->cmd_link, &queue->cmds);
   return VK_SUCCESS;

err:
   if (cmd)
      vk_free_cmd_dispatch_data_graph_arm(queue, cmd);
   return VK_ERROR_OUT_OF_HOST_MEMORY;
}


void
vk_free_queue(struct vk_cmd_queue *queue)
{
   struct vk_cmd_queue_entry *tmp, *cmd;
   LIST_FOR_EACH_ENTRY_SAFE(cmd, tmp, &queue->cmds, cmd_link) {
      if (cmd->driver_free_cb) {
         cmd->driver_free_cb(queue, cmd);
         vk_free(queue->alloc, cmd);
         continue;
      }
      switch(cmd->type) {
      case VK_CMD_BIND_PIPELINE:
         vk_free_cmd_bind_pipeline(queue, cmd);
         break;
      case VK_CMD_SET_ATTACHMENT_FEEDBACK_LOOP_ENABLE_EXT:
         vk_free_cmd_set_attachment_feedback_loop_enable_ext(queue, cmd);
         break;
      case VK_CMD_SET_VIEWPORT:
         vk_free_cmd_set_viewport(queue, cmd);
         break;
      case VK_CMD_SET_SCISSOR:
         vk_free_cmd_set_scissor(queue, cmd);
         break;
      case VK_CMD_SET_LINE_WIDTH:
         vk_free_cmd_set_line_width(queue, cmd);
         break;
      case VK_CMD_SET_DEPTH_BIAS:
         vk_free_cmd_set_depth_bias(queue, cmd);
         break;
      case VK_CMD_SET_BLEND_CONSTANTS:
         vk_free_cmd_set_blend_constants(queue, cmd);
         break;
      case VK_CMD_SET_DEPTH_BOUNDS:
         vk_free_cmd_set_depth_bounds(queue, cmd);
         break;
      case VK_CMD_SET_STENCIL_COMPARE_MASK:
         vk_free_cmd_set_stencil_compare_mask(queue, cmd);
         break;
      case VK_CMD_SET_STENCIL_WRITE_MASK:
         vk_free_cmd_set_stencil_write_mask(queue, cmd);
         break;
      case VK_CMD_SET_STENCIL_REFERENCE:
         vk_free_cmd_set_stencil_reference(queue, cmd);
         break;
      case VK_CMD_BIND_DESCRIPTOR_SETS:
         vk_free_cmd_bind_descriptor_sets(queue, cmd);
         break;
      case VK_CMD_BIND_INDEX_BUFFER:
         vk_free_cmd_bind_index_buffer(queue, cmd);
         break;
      case VK_CMD_BIND_VERTEX_BUFFERS:
         vk_free_cmd_bind_vertex_buffers(queue, cmd);
         break;
      case VK_CMD_DRAW:
         vk_free_cmd_draw(queue, cmd);
         break;
      case VK_CMD_DRAW_INDEXED:
         vk_free_cmd_draw_indexed(queue, cmd);
         break;
      case VK_CMD_DRAW_MULTI_EXT:
         vk_free_cmd_draw_multi_ext(queue, cmd);
         break;
      case VK_CMD_DRAW_MULTI_INDEXED_EXT:
         vk_free_cmd_draw_multi_indexed_ext(queue, cmd);
         break;
      case VK_CMD_DRAW_INDIRECT:
         vk_free_cmd_draw_indirect(queue, cmd);
         break;
      case VK_CMD_DRAW_INDEXED_INDIRECT:
         vk_free_cmd_draw_indexed_indirect(queue, cmd);
         break;
      case VK_CMD_DISPATCH:
         vk_free_cmd_dispatch(queue, cmd);
         break;
      case VK_CMD_DISPATCH_INDIRECT:
         vk_free_cmd_dispatch_indirect(queue, cmd);
         break;
      case VK_CMD_SUBPASS_SHADING_HUAWEI:
         vk_free_cmd_subpass_shading_huawei(queue, cmd);
         break;
      case VK_CMD_DRAW_CLUSTER_HUAWEI:
         vk_free_cmd_draw_cluster_huawei(queue, cmd);
         break;
      case VK_CMD_DRAW_CLUSTER_INDIRECT_HUAWEI:
         vk_free_cmd_draw_cluster_indirect_huawei(queue, cmd);
         break;
      case VK_CMD_UPDATE_PIPELINE_INDIRECT_BUFFER_NV:
         vk_free_cmd_update_pipeline_indirect_buffer_nv(queue, cmd);
         break;
      case VK_CMD_COPY_BUFFER:
         vk_free_cmd_copy_buffer(queue, cmd);
         break;
      case VK_CMD_COPY_IMAGE:
         vk_free_cmd_copy_image(queue, cmd);
         break;
      case VK_CMD_BLIT_IMAGE:
         vk_free_cmd_blit_image(queue, cmd);
         break;
      case VK_CMD_COPY_BUFFER_TO_IMAGE:
         vk_free_cmd_copy_buffer_to_image(queue, cmd);
         break;
      case VK_CMD_COPY_IMAGE_TO_BUFFER:
         vk_free_cmd_copy_image_to_buffer(queue, cmd);
         break;
      case VK_CMD_COPY_MEMORY_INDIRECT_NV:
         vk_free_cmd_copy_memory_indirect_nv(queue, cmd);
         break;
      case VK_CMD_COPY_MEMORY_INDIRECT_KHR:
         vk_free_cmd_copy_memory_indirect_khr(queue, cmd);
         break;
      case VK_CMD_COPY_MEMORY_TO_IMAGE_INDIRECT_NV:
         vk_free_cmd_copy_memory_to_image_indirect_nv(queue, cmd);
         break;
      case VK_CMD_COPY_MEMORY_TO_IMAGE_INDIRECT_KHR:
         vk_free_cmd_copy_memory_to_image_indirect_khr(queue, cmd);
         break;
      case VK_CMD_UPDATE_BUFFER:
         vk_free_cmd_update_buffer(queue, cmd);
         break;
      case VK_CMD_FILL_BUFFER:
         vk_free_cmd_fill_buffer(queue, cmd);
         break;
      case VK_CMD_CLEAR_COLOR_IMAGE:
         vk_free_cmd_clear_color_image(queue, cmd);
         break;
      case VK_CMD_CLEAR_DEPTH_STENCIL_IMAGE:
         vk_free_cmd_clear_depth_stencil_image(queue, cmd);
         break;
      case VK_CMD_CLEAR_ATTACHMENTS:
         vk_free_cmd_clear_attachments(queue, cmd);
         break;
      case VK_CMD_RESOLVE_IMAGE:
         vk_free_cmd_resolve_image(queue, cmd);
         break;
      case VK_CMD_SET_EVENT:
         vk_free_cmd_set_event(queue, cmd);
         break;
      case VK_CMD_RESET_EVENT:
         vk_free_cmd_reset_event(queue, cmd);
         break;
      case VK_CMD_WAIT_EVENTS:
         vk_free_cmd_wait_events(queue, cmd);
         break;
      case VK_CMD_PIPELINE_BARRIER:
         vk_free_cmd_pipeline_barrier(queue, cmd);
         break;
      case VK_CMD_BEGIN_QUERY:
         vk_free_cmd_begin_query(queue, cmd);
         break;
      case VK_CMD_END_QUERY:
         vk_free_cmd_end_query(queue, cmd);
         break;
      case VK_CMD_BEGIN_CONDITIONAL_RENDERING_EXT:
         vk_free_cmd_begin_conditional_rendering_ext(queue, cmd);
         break;
      case VK_CMD_END_CONDITIONAL_RENDERING_EXT:
         vk_free_cmd_end_conditional_rendering_ext(queue, cmd);
         break;
      case VK_CMD_RESET_QUERY_POOL:
         vk_free_cmd_reset_query_pool(queue, cmd);
         break;
      case VK_CMD_WRITE_TIMESTAMP:
         vk_free_cmd_write_timestamp(queue, cmd);
         break;
      case VK_CMD_COPY_QUERY_POOL_RESULTS:
         vk_free_cmd_copy_query_pool_results(queue, cmd);
         break;
      case VK_CMD_PUSH_CONSTANTS:
         vk_free_cmd_push_constants(queue, cmd);
         break;
      case VK_CMD_BEGIN_RENDER_PASS:
         vk_free_cmd_begin_render_pass(queue, cmd);
         break;
      case VK_CMD_NEXT_SUBPASS:
         vk_free_cmd_next_subpass(queue, cmd);
         break;
      case VK_CMD_END_RENDER_PASS:
         vk_free_cmd_end_render_pass(queue, cmd);
         break;
      case VK_CMD_EXECUTE_COMMANDS:
         vk_free_cmd_execute_commands(queue, cmd);
         break;
      case VK_CMD_DEBUG_MARKER_BEGIN_EXT:
         vk_free_cmd_debug_marker_begin_ext(queue, cmd);
         break;
      case VK_CMD_DEBUG_MARKER_END_EXT:
         vk_free_cmd_debug_marker_end_ext(queue, cmd);
         break;
      case VK_CMD_DEBUG_MARKER_INSERT_EXT:
         vk_free_cmd_debug_marker_insert_ext(queue, cmd);
         break;
      case VK_CMD_EXECUTE_GENERATED_COMMANDS_NV:
         vk_free_cmd_execute_generated_commands_nv(queue, cmd);
         break;
      case VK_CMD_PREPROCESS_GENERATED_COMMANDS_NV:
         vk_free_cmd_preprocess_generated_commands_nv(queue, cmd);
         break;
      case VK_CMD_BIND_PIPELINE_SHADER_GROUP_NV:
         vk_free_cmd_bind_pipeline_shader_group_nv(queue, cmd);
         break;
      case VK_CMD_EXECUTE_GENERATED_COMMANDS_EXT:
         vk_free_cmd_execute_generated_commands_ext(queue, cmd);
         break;
      case VK_CMD_PREPROCESS_GENERATED_COMMANDS_EXT:
         vk_free_cmd_preprocess_generated_commands_ext(queue, cmd);
         break;
      case VK_CMD_PUSH_DESCRIPTOR_SET:
         vk_free_cmd_push_descriptor_set(queue, cmd);
         break;
      case VK_CMD_SET_DEVICE_MASK:
         vk_free_cmd_set_device_mask(queue, cmd);
         break;
      case VK_CMD_DISPATCH_BASE:
         vk_free_cmd_dispatch_base(queue, cmd);
         break;
      case VK_CMD_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE:
         vk_free_cmd_push_descriptor_set_with_template(queue, cmd);
         break;
      case VK_CMD_SET_VIEWPORT_WSCALING_NV:
         vk_free_cmd_set_viewport_wscaling_nv(queue, cmd);
         break;
      case VK_CMD_SET_DISCARD_RECTANGLE_EXT:
         vk_free_cmd_set_discard_rectangle_ext(queue, cmd);
         break;
      case VK_CMD_SET_DISCARD_RECTANGLE_ENABLE_EXT:
         vk_free_cmd_set_discard_rectangle_enable_ext(queue, cmd);
         break;
      case VK_CMD_SET_DISCARD_RECTANGLE_MODE_EXT:
         vk_free_cmd_set_discard_rectangle_mode_ext(queue, cmd);
         break;
      case VK_CMD_SET_SAMPLE_LOCATIONS_EXT:
         vk_free_cmd_set_sample_locations_ext(queue, cmd);
         break;
      case VK_CMD_BEGIN_DEBUG_UTILS_LABEL_EXT:
         vk_free_cmd_begin_debug_utils_label_ext(queue, cmd);
         break;
      case VK_CMD_END_DEBUG_UTILS_LABEL_EXT:
         vk_free_cmd_end_debug_utils_label_ext(queue, cmd);
         break;
      case VK_CMD_INSERT_DEBUG_UTILS_LABEL_EXT:
         vk_free_cmd_insert_debug_utils_label_ext(queue, cmd);
         break;
      case VK_CMD_WRITE_BUFFER_MARKER_AMD:
         vk_free_cmd_write_buffer_marker_amd(queue, cmd);
         break;
      case VK_CMD_BEGIN_RENDER_PASS2:
         vk_free_cmd_begin_render_pass2(queue, cmd);
         break;
      case VK_CMD_NEXT_SUBPASS2:
         vk_free_cmd_next_subpass2(queue, cmd);
         break;
      case VK_CMD_END_RENDER_PASS2:
         vk_free_cmd_end_render_pass2(queue, cmd);
         break;
      case VK_CMD_DRAW_INDIRECT_COUNT:
         vk_free_cmd_draw_indirect_count(queue, cmd);
         break;
      case VK_CMD_DRAW_INDEXED_INDIRECT_COUNT:
         vk_free_cmd_draw_indexed_indirect_count(queue, cmd);
         break;
      case VK_CMD_SET_CHECKPOINT_NV:
         vk_free_cmd_set_checkpoint_nv(queue, cmd);
         break;
      case VK_CMD_BIND_TRANSFORM_FEEDBACK_BUFFERS_EXT:
         vk_free_cmd_bind_transform_feedback_buffers_ext(queue, cmd);
         break;
      case VK_CMD_BEGIN_TRANSFORM_FEEDBACK_EXT:
         vk_free_cmd_begin_transform_feedback_ext(queue, cmd);
         break;
      case VK_CMD_END_TRANSFORM_FEEDBACK_EXT:
         vk_free_cmd_end_transform_feedback_ext(queue, cmd);
         break;
      case VK_CMD_BEGIN_QUERY_INDEXED_EXT:
         vk_free_cmd_begin_query_indexed_ext(queue, cmd);
         break;
      case VK_CMD_END_QUERY_INDEXED_EXT:
         vk_free_cmd_end_query_indexed_ext(queue, cmd);
         break;
      case VK_CMD_DRAW_INDIRECT_BYTE_COUNT_EXT:
         vk_free_cmd_draw_indirect_byte_count_ext(queue, cmd);
         break;
      case VK_CMD_SET_EXCLUSIVE_SCISSOR_NV:
         vk_free_cmd_set_exclusive_scissor_nv(queue, cmd);
         break;
      case VK_CMD_SET_EXCLUSIVE_SCISSOR_ENABLE_NV:
         vk_free_cmd_set_exclusive_scissor_enable_nv(queue, cmd);
         break;
      case VK_CMD_BIND_SHADING_RATE_IMAGE_NV:
         vk_free_cmd_bind_shading_rate_image_nv(queue, cmd);
         break;
      case VK_CMD_SET_VIEWPORT_SHADING_RATE_PALETTE_NV:
         vk_free_cmd_set_viewport_shading_rate_palette_nv(queue, cmd);
         break;
      case VK_CMD_SET_COARSE_SAMPLE_ORDER_NV:
         vk_free_cmd_set_coarse_sample_order_nv(queue, cmd);
         break;
      case VK_CMD_DRAW_MESH_TASKS_NV:
         vk_free_cmd_draw_mesh_tasks_nv(queue, cmd);
         break;
      case VK_CMD_DRAW_MESH_TASKS_INDIRECT_NV:
         vk_free_cmd_draw_mesh_tasks_indirect_nv(queue, cmd);
         break;
      case VK_CMD_DRAW_MESH_TASKS_INDIRECT_COUNT_NV:
         vk_free_cmd_draw_mesh_tasks_indirect_count_nv(queue, cmd);
         break;
      case VK_CMD_DRAW_MESH_TASKS_EXT:
         vk_free_cmd_draw_mesh_tasks_ext(queue, cmd);
         break;
      case VK_CMD_DRAW_MESH_TASKS_INDIRECT_EXT:
         vk_free_cmd_draw_mesh_tasks_indirect_ext(queue, cmd);
         break;
      case VK_CMD_DRAW_MESH_TASKS_INDIRECT_COUNT_EXT:
         vk_free_cmd_draw_mesh_tasks_indirect_count_ext(queue, cmd);
         break;
      case VK_CMD_BIND_INVOCATION_MASK_HUAWEI:
         vk_free_cmd_bind_invocation_mask_huawei(queue, cmd);
         break;
      case VK_CMD_COPY_ACCELERATION_STRUCTURE_NV:
         vk_free_cmd_copy_acceleration_structure_nv(queue, cmd);
         break;
      case VK_CMD_COPY_ACCELERATION_STRUCTURE_KHR:
         vk_free_cmd_copy_acceleration_structure_khr(queue, cmd);
         break;
      case VK_CMD_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_KHR:
         vk_free_cmd_copy_acceleration_structure_to_memory_khr(queue, cmd);
         break;
      case VK_CMD_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_KHR:
         vk_free_cmd_copy_memory_to_acceleration_structure_khr(queue, cmd);
         break;
      case VK_CMD_WRITE_ACCELERATION_STRUCTURES_PROPERTIES_KHR:
         vk_free_cmd_write_acceleration_structures_properties_khr(queue, cmd);
         break;
      case VK_CMD_WRITE_ACCELERATION_STRUCTURES_PROPERTIES_NV:
         vk_free_cmd_write_acceleration_structures_properties_nv(queue, cmd);
         break;
      case VK_CMD_BUILD_ACCELERATION_STRUCTURE_NV:
         vk_free_cmd_build_acceleration_structure_nv(queue, cmd);
         break;
      case VK_CMD_TRACE_RAYS_KHR:
         vk_free_cmd_trace_rays_khr(queue, cmd);
         break;
      case VK_CMD_TRACE_RAYS_NV:
         vk_free_cmd_trace_rays_nv(queue, cmd);
         break;
      case VK_CMD_TRACE_RAYS_INDIRECT_KHR:
         vk_free_cmd_trace_rays_indirect_khr(queue, cmd);
         break;
      case VK_CMD_TRACE_RAYS_INDIRECT2_KHR:
         vk_free_cmd_trace_rays_indirect2_khr(queue, cmd);
         break;
      case VK_CMD_BUILD_CLUSTER_ACCELERATION_STRUCTURE_INDIRECT_NV:
         vk_free_cmd_build_cluster_acceleration_structure_indirect_nv(queue, cmd);
         break;
      case VK_CMD_SET_RAY_TRACING_PIPELINE_STACK_SIZE_KHR:
         vk_free_cmd_set_ray_tracing_pipeline_stack_size_khr(queue, cmd);
         break;
      case VK_CMD_SET_PERFORMANCE_MARKER_INTEL:
         vk_free_cmd_set_performance_marker_intel(queue, cmd);
         break;
      case VK_CMD_SET_PERFORMANCE_STREAM_MARKER_INTEL:
         vk_free_cmd_set_performance_stream_marker_intel(queue, cmd);
         break;
      case VK_CMD_SET_PERFORMANCE_OVERRIDE_INTEL:
         vk_free_cmd_set_performance_override_intel(queue, cmd);
         break;
      case VK_CMD_SET_LINE_STIPPLE:
         vk_free_cmd_set_line_stipple(queue, cmd);
         break;
      case VK_CMD_BUILD_ACCELERATION_STRUCTURES_KHR:
         vk_free_cmd_build_acceleration_structures_khr(queue, cmd);
         break;
      case VK_CMD_BUILD_ACCELERATION_STRUCTURES_INDIRECT_KHR:
         vk_free_cmd_build_acceleration_structures_indirect_khr(queue, cmd);
         break;
      case VK_CMD_SET_CULL_MODE:
         vk_free_cmd_set_cull_mode(queue, cmd);
         break;
      case VK_CMD_SET_FRONT_FACE:
         vk_free_cmd_set_front_face(queue, cmd);
         break;
      case VK_CMD_SET_PRIMITIVE_TOPOLOGY:
         vk_free_cmd_set_primitive_topology(queue, cmd);
         break;
      case VK_CMD_SET_VIEWPORT_WITH_COUNT:
         vk_free_cmd_set_viewport_with_count(queue, cmd);
         break;
      case VK_CMD_SET_SCISSOR_WITH_COUNT:
         vk_free_cmd_set_scissor_with_count(queue, cmd);
         break;
      case VK_CMD_BIND_INDEX_BUFFER2:
         vk_free_cmd_bind_index_buffer2(queue, cmd);
         break;
      case VK_CMD_BIND_VERTEX_BUFFERS2:
         vk_free_cmd_bind_vertex_buffers2(queue, cmd);
         break;
      case VK_CMD_SET_DEPTH_TEST_ENABLE:
         vk_free_cmd_set_depth_test_enable(queue, cmd);
         break;
      case VK_CMD_SET_DEPTH_WRITE_ENABLE:
         vk_free_cmd_set_depth_write_enable(queue, cmd);
         break;
      case VK_CMD_SET_DEPTH_COMPARE_OP:
         vk_free_cmd_set_depth_compare_op(queue, cmd);
         break;
      case VK_CMD_SET_DEPTH_BOUNDS_TEST_ENABLE:
         vk_free_cmd_set_depth_bounds_test_enable(queue, cmd);
         break;
      case VK_CMD_SET_STENCIL_TEST_ENABLE:
         vk_free_cmd_set_stencil_test_enable(queue, cmd);
         break;
      case VK_CMD_SET_STENCIL_OP:
         vk_free_cmd_set_stencil_op(queue, cmd);
         break;
      case VK_CMD_SET_PATCH_CONTROL_POINTS_EXT:
         vk_free_cmd_set_patch_control_points_ext(queue, cmd);
         break;
      case VK_CMD_SET_RASTERIZER_DISCARD_ENABLE:
         vk_free_cmd_set_rasterizer_discard_enable(queue, cmd);
         break;
      case VK_CMD_SET_DEPTH_BIAS_ENABLE:
         vk_free_cmd_set_depth_bias_enable(queue, cmd);
         break;
      case VK_CMD_SET_LOGIC_OP_EXT:
         vk_free_cmd_set_logic_op_ext(queue, cmd);
         break;
      case VK_CMD_SET_PRIMITIVE_RESTART_ENABLE:
         vk_free_cmd_set_primitive_restart_enable(queue, cmd);
         break;
      case VK_CMD_SET_TESSELLATION_DOMAIN_ORIGIN_EXT:
         vk_free_cmd_set_tessellation_domain_origin_ext(queue, cmd);
         break;
      case VK_CMD_SET_DEPTH_CLAMP_ENABLE_EXT:
         vk_free_cmd_set_depth_clamp_enable_ext(queue, cmd);
         break;
      case VK_CMD_SET_POLYGON_MODE_EXT:
         vk_free_cmd_set_polygon_mode_ext(queue, cmd);
         break;
      case VK_CMD_SET_RASTERIZATION_SAMPLES_EXT:
         vk_free_cmd_set_rasterization_samples_ext(queue, cmd);
         break;
      case VK_CMD_SET_SAMPLE_MASK_EXT:
         vk_free_cmd_set_sample_mask_ext(queue, cmd);
         break;
      case VK_CMD_SET_ALPHA_TO_COVERAGE_ENABLE_EXT:
         vk_free_cmd_set_alpha_to_coverage_enable_ext(queue, cmd);
         break;
      case VK_CMD_SET_ALPHA_TO_ONE_ENABLE_EXT:
         vk_free_cmd_set_alpha_to_one_enable_ext(queue, cmd);
         break;
      case VK_CMD_SET_LOGIC_OP_ENABLE_EXT:
         vk_free_cmd_set_logic_op_enable_ext(queue, cmd);
         break;
      case VK_CMD_SET_COLOR_BLEND_ENABLE_EXT:
         vk_free_cmd_set_color_blend_enable_ext(queue, cmd);
         break;
      case VK_CMD_SET_COLOR_BLEND_EQUATION_EXT:
         vk_free_cmd_set_color_blend_equation_ext(queue, cmd);
         break;
      case VK_CMD_SET_COLOR_WRITE_MASK_EXT:
         vk_free_cmd_set_color_write_mask_ext(queue, cmd);
         break;
      case VK_CMD_SET_RASTERIZATION_STREAM_EXT:
         vk_free_cmd_set_rasterization_stream_ext(queue, cmd);
         break;
      case VK_CMD_SET_CONSERVATIVE_RASTERIZATION_MODE_EXT:
         vk_free_cmd_set_conservative_rasterization_mode_ext(queue, cmd);
         break;
      case VK_CMD_SET_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT:
         vk_free_cmd_set_extra_primitive_overestimation_size_ext(queue, cmd);
         break;
      case VK_CMD_SET_DEPTH_CLIP_ENABLE_EXT:
         vk_free_cmd_set_depth_clip_enable_ext(queue, cmd);
         break;
      case VK_CMD_SET_SAMPLE_LOCATIONS_ENABLE_EXT:
         vk_free_cmd_set_sample_locations_enable_ext(queue, cmd);
         break;
      case VK_CMD_SET_COLOR_BLEND_ADVANCED_EXT:
         vk_free_cmd_set_color_blend_advanced_ext(queue, cmd);
         break;
      case VK_CMD_SET_PROVOKING_VERTEX_MODE_EXT:
         vk_free_cmd_set_provoking_vertex_mode_ext(queue, cmd);
         break;
      case VK_CMD_SET_LINE_RASTERIZATION_MODE_EXT:
         vk_free_cmd_set_line_rasterization_mode_ext(queue, cmd);
         break;
      case VK_CMD_SET_LINE_STIPPLE_ENABLE_EXT:
         vk_free_cmd_set_line_stipple_enable_ext(queue, cmd);
         break;
      case VK_CMD_SET_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT:
         vk_free_cmd_set_depth_clip_negative_one_to_one_ext(queue, cmd);
         break;
      case VK_CMD_SET_VIEWPORT_WSCALING_ENABLE_NV:
         vk_free_cmd_set_viewport_wscaling_enable_nv(queue, cmd);
         break;
      case VK_CMD_SET_VIEWPORT_SWIZZLE_NV:
         vk_free_cmd_set_viewport_swizzle_nv(queue, cmd);
         break;
      case VK_CMD_SET_COVERAGE_TO_COLOR_ENABLE_NV:
         vk_free_cmd_set_coverage_to_color_enable_nv(queue, cmd);
         break;
      case VK_CMD_SET_COVERAGE_TO_COLOR_LOCATION_NV:
         vk_free_cmd_set_coverage_to_color_location_nv(queue, cmd);
         break;
      case VK_CMD_SET_COVERAGE_MODULATION_MODE_NV:
         vk_free_cmd_set_coverage_modulation_mode_nv(queue, cmd);
         break;
      case VK_CMD_SET_COVERAGE_MODULATION_TABLE_ENABLE_NV:
         vk_free_cmd_set_coverage_modulation_table_enable_nv(queue, cmd);
         break;
      case VK_CMD_SET_COVERAGE_MODULATION_TABLE_NV:
         vk_free_cmd_set_coverage_modulation_table_nv(queue, cmd);
         break;
      case VK_CMD_SET_SHADING_RATE_IMAGE_ENABLE_NV:
         vk_free_cmd_set_shading_rate_image_enable_nv(queue, cmd);
         break;
      case VK_CMD_SET_COVERAGE_REDUCTION_MODE_NV:
         vk_free_cmd_set_coverage_reduction_mode_nv(queue, cmd);
         break;
      case VK_CMD_SET_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV:
         vk_free_cmd_set_representative_fragment_test_enable_nv(queue, cmd);
         break;
      case VK_CMD_COPY_BUFFER2:
         vk_free_cmd_copy_buffer2(queue, cmd);
         break;
      case VK_CMD_COPY_IMAGE2:
         vk_free_cmd_copy_image2(queue, cmd);
         break;
      case VK_CMD_BLIT_IMAGE2:
         vk_free_cmd_blit_image2(queue, cmd);
         break;
      case VK_CMD_COPY_BUFFER_TO_IMAGE2:
         vk_free_cmd_copy_buffer_to_image2(queue, cmd);
         break;
      case VK_CMD_COPY_IMAGE_TO_BUFFER2:
         vk_free_cmd_copy_image_to_buffer2(queue, cmd);
         break;
      case VK_CMD_RESOLVE_IMAGE2:
         vk_free_cmd_resolve_image2(queue, cmd);
         break;
      case VK_CMD_SET_FRAGMENT_SHADING_RATE_KHR:
         vk_free_cmd_set_fragment_shading_rate_khr(queue, cmd);
         break;
      case VK_CMD_SET_FRAGMENT_SHADING_RATE_ENUM_NV:
         vk_free_cmd_set_fragment_shading_rate_enum_nv(queue, cmd);
         break;
      case VK_CMD_SET_VERTEX_INPUT_EXT:
         vk_free_cmd_set_vertex_input_ext(queue, cmd);
         break;
      case VK_CMD_SET_COLOR_WRITE_ENABLE_EXT:
         vk_free_cmd_set_color_write_enable_ext(queue, cmd);
         break;
      case VK_CMD_SET_EVENT2:
         vk_free_cmd_set_event2(queue, cmd);
         break;
      case VK_CMD_RESET_EVENT2:
         vk_free_cmd_reset_event2(queue, cmd);
         break;
      case VK_CMD_WAIT_EVENTS2:
         vk_free_cmd_wait_events2(queue, cmd);
         break;
      case VK_CMD_PIPELINE_BARRIER2:
         vk_free_cmd_pipeline_barrier2(queue, cmd);
         break;
      case VK_CMD_WRITE_TIMESTAMP2:
         vk_free_cmd_write_timestamp2(queue, cmd);
         break;
      case VK_CMD_WRITE_BUFFER_MARKER2_AMD:
         vk_free_cmd_write_buffer_marker2_amd(queue, cmd);
         break;
      case VK_CMD_DECODE_VIDEO_KHR:
         vk_free_cmd_decode_video_khr(queue, cmd);
         break;
      case VK_CMD_BEGIN_VIDEO_CODING_KHR:
         vk_free_cmd_begin_video_coding_khr(queue, cmd);
         break;
      case VK_CMD_CONTROL_VIDEO_CODING_KHR:
         vk_free_cmd_control_video_coding_khr(queue, cmd);
         break;
      case VK_CMD_END_VIDEO_CODING_KHR:
         vk_free_cmd_end_video_coding_khr(queue, cmd);
         break;
      case VK_CMD_ENCODE_VIDEO_KHR:
         vk_free_cmd_encode_video_khr(queue, cmd);
         break;
      case VK_CMD_DECOMPRESS_MEMORY_NV:
         vk_free_cmd_decompress_memory_nv(queue, cmd);
         break;
      case VK_CMD_DECOMPRESS_MEMORY_INDIRECT_COUNT_NV:
         vk_free_cmd_decompress_memory_indirect_count_nv(queue, cmd);
         break;
      case VK_CMD_BUILD_PARTITIONED_ACCELERATION_STRUCTURES_NV:
         vk_free_cmd_build_partitioned_acceleration_structures_nv(queue, cmd);
         break;
      case VK_CMD_CU_LAUNCH_KERNEL_NVX:
         vk_free_cmd_cu_launch_kernel_nvx(queue, cmd);
         break;
      case VK_CMD_BIND_DESCRIPTOR_BUFFERS_EXT:
         vk_free_cmd_bind_descriptor_buffers_ext(queue, cmd);
         break;
      case VK_CMD_SET_DESCRIPTOR_BUFFER_OFFSETS_EXT:
         vk_free_cmd_set_descriptor_buffer_offsets_ext(queue, cmd);
         break;
      case VK_CMD_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_EXT:
         vk_free_cmd_bind_descriptor_buffer_embedded_samplers_ext(queue, cmd);
         break;
      case VK_CMD_BEGIN_RENDERING:
         vk_free_cmd_begin_rendering(queue, cmd);
         break;
      case VK_CMD_END_RENDERING:
         vk_free_cmd_end_rendering(queue, cmd);
         break;
      case VK_CMD_END_RENDERING2_EXT:
         vk_free_cmd_end_rendering2_ext(queue, cmd);
         break;
      case VK_CMD_BUILD_MICROMAPS_EXT:
         vk_free_cmd_build_micromaps_ext(queue, cmd);
         break;
      case VK_CMD_COPY_MICROMAP_EXT:
         vk_free_cmd_copy_micromap_ext(queue, cmd);
         break;
      case VK_CMD_COPY_MICROMAP_TO_MEMORY_EXT:
         vk_free_cmd_copy_micromap_to_memory_ext(queue, cmd);
         break;
      case VK_CMD_COPY_MEMORY_TO_MICROMAP_EXT:
         vk_free_cmd_copy_memory_to_micromap_ext(queue, cmd);
         break;
      case VK_CMD_WRITE_MICROMAPS_PROPERTIES_EXT:
         vk_free_cmd_write_micromaps_properties_ext(queue, cmd);
         break;
      case VK_CMD_BIND_TILE_MEMORY_QCOM:
         vk_free_cmd_bind_tile_memory_qcom(queue, cmd);
         break;
      case VK_CMD_OPTICAL_FLOW_EXECUTE_NV:
         vk_free_cmd_optical_flow_execute_nv(queue, cmd);
         break;
      case VK_CMD_SET_DEPTH_BIAS2_EXT:
         vk_free_cmd_set_depth_bias2_ext(queue, cmd);
         break;
      case VK_CMD_BIND_SHADERS_EXT:
         vk_free_cmd_bind_shaders_ext(queue, cmd);
         break;
      case VK_CMD_BIND_DESCRIPTOR_SETS2:
         vk_free_cmd_bind_descriptor_sets2(queue, cmd);
         break;
      case VK_CMD_PUSH_CONSTANTS2:
         vk_free_cmd_push_constants2(queue, cmd);
         break;
      case VK_CMD_PUSH_DESCRIPTOR_SET2:
         vk_free_cmd_push_descriptor_set2(queue, cmd);
         break;
      case VK_CMD_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE2:
         vk_free_cmd_push_descriptor_set_with_template2(queue, cmd);
         break;
      case VK_CMD_SET_DESCRIPTOR_BUFFER_OFFSETS2_EXT:
         vk_free_cmd_set_descriptor_buffer_offsets2_ext(queue, cmd);
         break;
      case VK_CMD_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS2_EXT:
         vk_free_cmd_bind_descriptor_buffer_embedded_samplers2_ext(queue, cmd);
         break;
      case VK_CMD_SET_RENDERING_ATTACHMENT_LOCATIONS:
         vk_free_cmd_set_rendering_attachment_locations(queue, cmd);
         break;
      case VK_CMD_SET_RENDERING_INPUT_ATTACHMENT_INDICES:
         vk_free_cmd_set_rendering_input_attachment_indices(queue, cmd);
         break;
      case VK_CMD_SET_DEPTH_CLAMP_RANGE_EXT:
         vk_free_cmd_set_depth_clamp_range_ext(queue, cmd);
         break;
      case VK_CMD_CONVERT_COOPERATIVE_VECTOR_MATRIX_NV:
         vk_free_cmd_convert_cooperative_vector_matrix_nv(queue, cmd);
         break;
      case VK_CMD_DISPATCH_TILE_QCOM:
         vk_free_cmd_dispatch_tile_qcom(queue, cmd);
         break;
      case VK_CMD_BEGIN_PER_TILE_EXECUTION_QCOM:
         vk_free_cmd_begin_per_tile_execution_qcom(queue, cmd);
         break;
      case VK_CMD_END_PER_TILE_EXECUTION_QCOM:
         vk_free_cmd_end_per_tile_execution_qcom(queue, cmd);
         break;
      case VK_CMD_COPY_TENSOR_ARM:
         vk_free_cmd_copy_tensor_arm(queue, cmd);
         break;
      case VK_CMD_DISPATCH_DATA_GRAPH_ARM:
         vk_free_cmd_dispatch_data_graph_arm(queue, cmd);
         break;
      case VK_CMD_TYPE_COUNT:
         break;
      }
      vk_free(queue->alloc, cmd->driver_data);
      vk_free(queue->alloc, cmd);
   }
}

void
vk_cmd_queue_execute(struct vk_cmd_queue *queue,
                     VkCommandBuffer commandBuffer,
                     const struct vk_device_dispatch_table *disp)
{
   list_for_each_entry(struct vk_cmd_queue_entry, cmd, &queue->cmds, cmd_link) {
      switch (cmd->type) {
      case VK_CMD_BIND_PIPELINE:
          disp->CmdBindPipeline(commandBuffer
             , cmd->u.bind_pipeline.pipeline_bind_point             , cmd->u.bind_pipeline.pipeline          );
          break;
      case VK_CMD_SET_ATTACHMENT_FEEDBACK_LOOP_ENABLE_EXT:
          disp->CmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer
             , cmd->u.set_attachment_feedback_loop_enable_ext.aspect_mask          );
          break;
      case VK_CMD_SET_VIEWPORT:
          disp->CmdSetViewport(commandBuffer
             , cmd->u.set_viewport.first_viewport             , cmd->u.set_viewport.viewport_count             , cmd->u.set_viewport.viewports          );
          break;
      case VK_CMD_SET_SCISSOR:
          disp->CmdSetScissor(commandBuffer
             , cmd->u.set_scissor.first_scissor             , cmd->u.set_scissor.scissor_count             , cmd->u.set_scissor.scissors          );
          break;
      case VK_CMD_SET_LINE_WIDTH:
          disp->CmdSetLineWidth(commandBuffer
             , cmd->u.set_line_width.line_width          );
          break;
      case VK_CMD_SET_DEPTH_BIAS:
          disp->CmdSetDepthBias(commandBuffer
             , cmd->u.set_depth_bias.depth_bias_constant_factor             , cmd->u.set_depth_bias.depth_bias_clamp             , cmd->u.set_depth_bias.depth_bias_slope_factor          );
          break;
      case VK_CMD_SET_BLEND_CONSTANTS:
          disp->CmdSetBlendConstants(commandBuffer
             , cmd->u.set_blend_constants.blend_constants          );
          break;
      case VK_CMD_SET_DEPTH_BOUNDS:
          disp->CmdSetDepthBounds(commandBuffer
             , cmd->u.set_depth_bounds.min_depth_bounds             , cmd->u.set_depth_bounds.max_depth_bounds          );
          break;
      case VK_CMD_SET_STENCIL_COMPARE_MASK:
          disp->CmdSetStencilCompareMask(commandBuffer
             , cmd->u.set_stencil_compare_mask.face_mask             , cmd->u.set_stencil_compare_mask.compare_mask          );
          break;
      case VK_CMD_SET_STENCIL_WRITE_MASK:
          disp->CmdSetStencilWriteMask(commandBuffer
             , cmd->u.set_stencil_write_mask.face_mask             , cmd->u.set_stencil_write_mask.write_mask          );
          break;
      case VK_CMD_SET_STENCIL_REFERENCE:
          disp->CmdSetStencilReference(commandBuffer
             , cmd->u.set_stencil_reference.face_mask             , cmd->u.set_stencil_reference.reference          );
          break;
      case VK_CMD_BIND_DESCRIPTOR_SETS:
          disp->CmdBindDescriptorSets(commandBuffer
             , cmd->u.bind_descriptor_sets.pipeline_bind_point             , cmd->u.bind_descriptor_sets.layout             , cmd->u.bind_descriptor_sets.first_set             , cmd->u.bind_descriptor_sets.descriptor_set_count             , cmd->u.bind_descriptor_sets.descriptor_sets             , cmd->u.bind_descriptor_sets.dynamic_offset_count             , cmd->u.bind_descriptor_sets.dynamic_offsets          );
          break;
      case VK_CMD_BIND_INDEX_BUFFER:
          disp->CmdBindIndexBuffer(commandBuffer
             , cmd->u.bind_index_buffer.buffer             , cmd->u.bind_index_buffer.offset             , cmd->u.bind_index_buffer.index_type          );
          break;
      case VK_CMD_BIND_VERTEX_BUFFERS:
          disp->CmdBindVertexBuffers(commandBuffer
             , cmd->u.bind_vertex_buffers.first_binding             , cmd->u.bind_vertex_buffers.binding_count             , cmd->u.bind_vertex_buffers.buffers             , cmd->u.bind_vertex_buffers.offsets          );
          break;
      case VK_CMD_DRAW:
          disp->CmdDraw(commandBuffer
             , cmd->u.draw.vertex_count             , cmd->u.draw.instance_count             , cmd->u.draw.first_vertex             , cmd->u.draw.first_instance          );
          break;
      case VK_CMD_DRAW_INDEXED:
          disp->CmdDrawIndexed(commandBuffer
             , cmd->u.draw_indexed.index_count             , cmd->u.draw_indexed.instance_count             , cmd->u.draw_indexed.first_index             , cmd->u.draw_indexed.vertex_offset             , cmd->u.draw_indexed.first_instance          );
          break;
      case VK_CMD_DRAW_MULTI_EXT:
          disp->CmdDrawMultiEXT(commandBuffer
             , cmd->u.draw_multi_ext.draw_count             , cmd->u.draw_multi_ext.vertex_info             , cmd->u.draw_multi_ext.instance_count             , cmd->u.draw_multi_ext.first_instance             , cmd->u.draw_multi_ext.stride          );
          break;
      case VK_CMD_DRAW_MULTI_INDEXED_EXT:
          disp->CmdDrawMultiIndexedEXT(commandBuffer
             , cmd->u.draw_multi_indexed_ext.draw_count             , cmd->u.draw_multi_indexed_ext.index_info             , cmd->u.draw_multi_indexed_ext.instance_count             , cmd->u.draw_multi_indexed_ext.first_instance             , cmd->u.draw_multi_indexed_ext.stride             , cmd->u.draw_multi_indexed_ext.vertex_offset          );
          break;
      case VK_CMD_DRAW_INDIRECT:
          disp->CmdDrawIndirect(commandBuffer
             , cmd->u.draw_indirect.buffer             , cmd->u.draw_indirect.offset             , cmd->u.draw_indirect.draw_count             , cmd->u.draw_indirect.stride          );
          break;
      case VK_CMD_DRAW_INDEXED_INDIRECT:
          disp->CmdDrawIndexedIndirect(commandBuffer
             , cmd->u.draw_indexed_indirect.buffer             , cmd->u.draw_indexed_indirect.offset             , cmd->u.draw_indexed_indirect.draw_count             , cmd->u.draw_indexed_indirect.stride          );
          break;
      case VK_CMD_DISPATCH:
          disp->CmdDispatch(commandBuffer
             , cmd->u.dispatch.group_count_x             , cmd->u.dispatch.group_count_y             , cmd->u.dispatch.group_count_z          );
          break;
      case VK_CMD_DISPATCH_INDIRECT:
          disp->CmdDispatchIndirect(commandBuffer
             , cmd->u.dispatch_indirect.buffer             , cmd->u.dispatch_indirect.offset          );
          break;
      case VK_CMD_SUBPASS_SHADING_HUAWEI:
          disp->CmdSubpassShadingHUAWEI(commandBuffer
          );
          break;
      case VK_CMD_DRAW_CLUSTER_HUAWEI:
          disp->CmdDrawClusterHUAWEI(commandBuffer
             , cmd->u.draw_cluster_huawei.group_count_x             , cmd->u.draw_cluster_huawei.group_count_y             , cmd->u.draw_cluster_huawei.group_count_z          );
          break;
      case VK_CMD_DRAW_CLUSTER_INDIRECT_HUAWEI:
          disp->CmdDrawClusterIndirectHUAWEI(commandBuffer
             , cmd->u.draw_cluster_indirect_huawei.buffer             , cmd->u.draw_cluster_indirect_huawei.offset          );
          break;
      case VK_CMD_UPDATE_PIPELINE_INDIRECT_BUFFER_NV:
          disp->CmdUpdatePipelineIndirectBufferNV(commandBuffer
             , cmd->u.update_pipeline_indirect_buffer_nv.pipeline_bind_point             , cmd->u.update_pipeline_indirect_buffer_nv.pipeline          );
          break;
      case VK_CMD_COPY_BUFFER:
          disp->CmdCopyBuffer(commandBuffer
             , cmd->u.copy_buffer.src_buffer             , cmd->u.copy_buffer.dst_buffer             , cmd->u.copy_buffer.region_count             , cmd->u.copy_buffer.regions          );
          break;
      case VK_CMD_COPY_IMAGE:
          disp->CmdCopyImage(commandBuffer
             , cmd->u.copy_image.src_image             , cmd->u.copy_image.src_image_layout             , cmd->u.copy_image.dst_image             , cmd->u.copy_image.dst_image_layout             , cmd->u.copy_image.region_count             , cmd->u.copy_image.regions          );
          break;
      case VK_CMD_BLIT_IMAGE:
          disp->CmdBlitImage(commandBuffer
             , cmd->u.blit_image.src_image             , cmd->u.blit_image.src_image_layout             , cmd->u.blit_image.dst_image             , cmd->u.blit_image.dst_image_layout             , cmd->u.blit_image.region_count             , cmd->u.blit_image.regions             , cmd->u.blit_image.filter          );
          break;
      case VK_CMD_COPY_BUFFER_TO_IMAGE:
          disp->CmdCopyBufferToImage(commandBuffer
             , cmd->u.copy_buffer_to_image.src_buffer             , cmd->u.copy_buffer_to_image.dst_image             , cmd->u.copy_buffer_to_image.dst_image_layout             , cmd->u.copy_buffer_to_image.region_count             , cmd->u.copy_buffer_to_image.regions          );
          break;
      case VK_CMD_COPY_IMAGE_TO_BUFFER:
          disp->CmdCopyImageToBuffer(commandBuffer
             , cmd->u.copy_image_to_buffer.src_image             , cmd->u.copy_image_to_buffer.src_image_layout             , cmd->u.copy_image_to_buffer.dst_buffer             , cmd->u.copy_image_to_buffer.region_count             , cmd->u.copy_image_to_buffer.regions          );
          break;
      case VK_CMD_COPY_MEMORY_INDIRECT_NV:
          disp->CmdCopyMemoryIndirectNV(commandBuffer
             , cmd->u.copy_memory_indirect_nv.copy_buffer_address             , cmd->u.copy_memory_indirect_nv.copy_count             , cmd->u.copy_memory_indirect_nv.stride          );
          break;
      case VK_CMD_COPY_MEMORY_INDIRECT_KHR:
          disp->CmdCopyMemoryIndirectKHR(commandBuffer
             , cmd->u.copy_memory_indirect_khr.copy_memory_indirect_info          );
          break;
      case VK_CMD_COPY_MEMORY_TO_IMAGE_INDIRECT_NV:
          disp->CmdCopyMemoryToImageIndirectNV(commandBuffer
             , cmd->u.copy_memory_to_image_indirect_nv.copy_buffer_address             , cmd->u.copy_memory_to_image_indirect_nv.copy_count             , cmd->u.copy_memory_to_image_indirect_nv.stride             , cmd->u.copy_memory_to_image_indirect_nv.dst_image             , cmd->u.copy_memory_to_image_indirect_nv.dst_image_layout             , cmd->u.copy_memory_to_image_indirect_nv.image_subresources          );
          break;
      case VK_CMD_COPY_MEMORY_TO_IMAGE_INDIRECT_KHR:
          disp->CmdCopyMemoryToImageIndirectKHR(commandBuffer
             , cmd->u.copy_memory_to_image_indirect_khr.copy_memory_to_image_indirect_info          );
          break;
      case VK_CMD_UPDATE_BUFFER:
          disp->CmdUpdateBuffer(commandBuffer
             , cmd->u.update_buffer.dst_buffer             , cmd->u.update_buffer.dst_offset             , cmd->u.update_buffer.data_size             , cmd->u.update_buffer.data          );
          break;
      case VK_CMD_FILL_BUFFER:
          disp->CmdFillBuffer(commandBuffer
             , cmd->u.fill_buffer.dst_buffer             , cmd->u.fill_buffer.dst_offset             , cmd->u.fill_buffer.size             , cmd->u.fill_buffer.data          );
          break;
      case VK_CMD_CLEAR_COLOR_IMAGE:
          disp->CmdClearColorImage(commandBuffer
             , cmd->u.clear_color_image.image             , cmd->u.clear_color_image.image_layout             , cmd->u.clear_color_image.color             , cmd->u.clear_color_image.range_count             , cmd->u.clear_color_image.ranges          );
          break;
      case VK_CMD_CLEAR_DEPTH_STENCIL_IMAGE:
          disp->CmdClearDepthStencilImage(commandBuffer
             , cmd->u.clear_depth_stencil_image.image             , cmd->u.clear_depth_stencil_image.image_layout             , cmd->u.clear_depth_stencil_image.depth_stencil             , cmd->u.clear_depth_stencil_image.range_count             , cmd->u.clear_depth_stencil_image.ranges          );
          break;
      case VK_CMD_CLEAR_ATTACHMENTS:
          disp->CmdClearAttachments(commandBuffer
             , cmd->u.clear_attachments.attachment_count             , cmd->u.clear_attachments.attachments             , cmd->u.clear_attachments.rect_count             , cmd->u.clear_attachments.rects          );
          break;
      case VK_CMD_RESOLVE_IMAGE:
          disp->CmdResolveImage(commandBuffer
             , cmd->u.resolve_image.src_image             , cmd->u.resolve_image.src_image_layout             , cmd->u.resolve_image.dst_image             , cmd->u.resolve_image.dst_image_layout             , cmd->u.resolve_image.region_count             , cmd->u.resolve_image.regions          );
          break;
      case VK_CMD_SET_EVENT:
          disp->CmdSetEvent(commandBuffer
             , cmd->u.set_event.event             , cmd->u.set_event.stage_mask          );
          break;
      case VK_CMD_RESET_EVENT:
          disp->CmdResetEvent(commandBuffer
             , cmd->u.reset_event.event             , cmd->u.reset_event.stage_mask          );
          break;
      case VK_CMD_WAIT_EVENTS:
          disp->CmdWaitEvents(commandBuffer
             , cmd->u.wait_events.event_count             , cmd->u.wait_events.events             , cmd->u.wait_events.src_stage_mask             , cmd->u.wait_events.dst_stage_mask             , cmd->u.wait_events.memory_barrier_count             , cmd->u.wait_events.memory_barriers             , cmd->u.wait_events.buffer_memory_barrier_count             , cmd->u.wait_events.buffer_memory_barriers             , cmd->u.wait_events.image_memory_barrier_count             , cmd->u.wait_events.image_memory_barriers          );
          break;
      case VK_CMD_PIPELINE_BARRIER:
          disp->CmdPipelineBarrier(commandBuffer
             , cmd->u.pipeline_barrier.src_stage_mask             , cmd->u.pipeline_barrier.dst_stage_mask             , cmd->u.pipeline_barrier.dependency_flags             , cmd->u.pipeline_barrier.memory_barrier_count             , cmd->u.pipeline_barrier.memory_barriers             , cmd->u.pipeline_barrier.buffer_memory_barrier_count             , cmd->u.pipeline_barrier.buffer_memory_barriers             , cmd->u.pipeline_barrier.image_memory_barrier_count             , cmd->u.pipeline_barrier.image_memory_barriers          );
          break;
      case VK_CMD_BEGIN_QUERY:
          disp->CmdBeginQuery(commandBuffer
             , cmd->u.begin_query.query_pool             , cmd->u.begin_query.query             , cmd->u.begin_query.flags          );
          break;
      case VK_CMD_END_QUERY:
          disp->CmdEndQuery(commandBuffer
             , cmd->u.end_query.query_pool             , cmd->u.end_query.query          );
          break;
      case VK_CMD_BEGIN_CONDITIONAL_RENDERING_EXT:
          disp->CmdBeginConditionalRenderingEXT(commandBuffer
             , cmd->u.begin_conditional_rendering_ext.conditional_rendering_begin          );
          break;
      case VK_CMD_END_CONDITIONAL_RENDERING_EXT:
          disp->CmdEndConditionalRenderingEXT(commandBuffer
          );
          break;
      case VK_CMD_RESET_QUERY_POOL:
          disp->CmdResetQueryPool(commandBuffer
             , cmd->u.reset_query_pool.query_pool             , cmd->u.reset_query_pool.first_query             , cmd->u.reset_query_pool.query_count          );
          break;
      case VK_CMD_WRITE_TIMESTAMP:
          disp->CmdWriteTimestamp(commandBuffer
             , cmd->u.write_timestamp.pipeline_stage             , cmd->u.write_timestamp.query_pool             , cmd->u.write_timestamp.query          );
          break;
      case VK_CMD_COPY_QUERY_POOL_RESULTS:
          disp->CmdCopyQueryPoolResults(commandBuffer
             , cmd->u.copy_query_pool_results.query_pool             , cmd->u.copy_query_pool_results.first_query             , cmd->u.copy_query_pool_results.query_count             , cmd->u.copy_query_pool_results.dst_buffer             , cmd->u.copy_query_pool_results.dst_offset             , cmd->u.copy_query_pool_results.stride             , cmd->u.copy_query_pool_results.flags          );
          break;
      case VK_CMD_PUSH_CONSTANTS:
          disp->CmdPushConstants(commandBuffer
             , cmd->u.push_constants.layout             , cmd->u.push_constants.stage_flags             , cmd->u.push_constants.offset             , cmd->u.push_constants.size             , cmd->u.push_constants.values          );
          break;
      case VK_CMD_BEGIN_RENDER_PASS:
          disp->CmdBeginRenderPass(commandBuffer
             , cmd->u.begin_render_pass.render_pass_begin             , cmd->u.begin_render_pass.contents          );
          break;
      case VK_CMD_NEXT_SUBPASS:
          disp->CmdNextSubpass(commandBuffer
             , cmd->u.next_subpass.contents          );
          break;
      case VK_CMD_END_RENDER_PASS:
          disp->CmdEndRenderPass(commandBuffer
          );
          break;
      case VK_CMD_EXECUTE_COMMANDS:
          disp->CmdExecuteCommands(commandBuffer
             , cmd->u.execute_commands.command_buffer_count             , cmd->u.execute_commands.command_buffers          );
          break;
      case VK_CMD_DEBUG_MARKER_BEGIN_EXT:
          disp->CmdDebugMarkerBeginEXT(commandBuffer
             , cmd->u.debug_marker_begin_ext.marker_info          );
          break;
      case VK_CMD_DEBUG_MARKER_END_EXT:
          disp->CmdDebugMarkerEndEXT(commandBuffer
          );
          break;
      case VK_CMD_DEBUG_MARKER_INSERT_EXT:
          disp->CmdDebugMarkerInsertEXT(commandBuffer
             , cmd->u.debug_marker_insert_ext.marker_info          );
          break;
      case VK_CMD_EXECUTE_GENERATED_COMMANDS_NV:
          disp->CmdExecuteGeneratedCommandsNV(commandBuffer
             , cmd->u.execute_generated_commands_nv.is_preprocessed             , cmd->u.execute_generated_commands_nv.generated_commands_info          );
          break;
      case VK_CMD_PREPROCESS_GENERATED_COMMANDS_NV:
          disp->CmdPreprocessGeneratedCommandsNV(commandBuffer
             , cmd->u.preprocess_generated_commands_nv.generated_commands_info          );
          break;
      case VK_CMD_BIND_PIPELINE_SHADER_GROUP_NV:
          disp->CmdBindPipelineShaderGroupNV(commandBuffer
             , cmd->u.bind_pipeline_shader_group_nv.pipeline_bind_point             , cmd->u.bind_pipeline_shader_group_nv.pipeline             , cmd->u.bind_pipeline_shader_group_nv.group_index          );
          break;
      case VK_CMD_EXECUTE_GENERATED_COMMANDS_EXT:
          disp->CmdExecuteGeneratedCommandsEXT(commandBuffer
             , cmd->u.execute_generated_commands_ext.is_preprocessed             , cmd->u.execute_generated_commands_ext.generated_commands_info          );
          break;
      case VK_CMD_PREPROCESS_GENERATED_COMMANDS_EXT:
          disp->CmdPreprocessGeneratedCommandsEXT(commandBuffer
             , cmd->u.preprocess_generated_commands_ext.generated_commands_info             , cmd->u.preprocess_generated_commands_ext.state_command_buffer          );
          break;
      case VK_CMD_PUSH_DESCRIPTOR_SET:
          disp->CmdPushDescriptorSet(commandBuffer
             , cmd->u.push_descriptor_set.pipeline_bind_point             , cmd->u.push_descriptor_set.layout             , cmd->u.push_descriptor_set.set             , cmd->u.push_descriptor_set.descriptor_write_count             , cmd->u.push_descriptor_set.descriptor_writes          );
          break;
      case VK_CMD_SET_DEVICE_MASK:
          disp->CmdSetDeviceMask(commandBuffer
             , cmd->u.set_device_mask.device_mask          );
          break;
      case VK_CMD_DISPATCH_BASE:
          disp->CmdDispatchBase(commandBuffer
             , cmd->u.dispatch_base.base_group_x             , cmd->u.dispatch_base.base_group_y             , cmd->u.dispatch_base.base_group_z             , cmd->u.dispatch_base.group_count_x             , cmd->u.dispatch_base.group_count_y             , cmd->u.dispatch_base.group_count_z          );
          break;
      case VK_CMD_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE:
          disp->CmdPushDescriptorSetWithTemplate(commandBuffer
             , cmd->u.push_descriptor_set_with_template.descriptor_update_template             , cmd->u.push_descriptor_set_with_template.layout             , cmd->u.push_descriptor_set_with_template.set             , cmd->u.push_descriptor_set_with_template.data          );
          break;
      case VK_CMD_SET_VIEWPORT_WSCALING_NV:
          disp->CmdSetViewportWScalingNV(commandBuffer
             , cmd->u.set_viewport_wscaling_nv.first_viewport             , cmd->u.set_viewport_wscaling_nv.viewport_count             , cmd->u.set_viewport_wscaling_nv.viewport_wscalings          );
          break;
      case VK_CMD_SET_DISCARD_RECTANGLE_EXT:
          disp->CmdSetDiscardRectangleEXT(commandBuffer
             , cmd->u.set_discard_rectangle_ext.first_discard_rectangle             , cmd->u.set_discard_rectangle_ext.discard_rectangle_count             , cmd->u.set_discard_rectangle_ext.discard_rectangles          );
          break;
      case VK_CMD_SET_DISCARD_RECTANGLE_ENABLE_EXT:
          disp->CmdSetDiscardRectangleEnableEXT(commandBuffer
             , cmd->u.set_discard_rectangle_enable_ext.discard_rectangle_enable          );
          break;
      case VK_CMD_SET_DISCARD_RECTANGLE_MODE_EXT:
          disp->CmdSetDiscardRectangleModeEXT(commandBuffer
             , cmd->u.set_discard_rectangle_mode_ext.discard_rectangle_mode          );
          break;
      case VK_CMD_SET_SAMPLE_LOCATIONS_EXT:
          disp->CmdSetSampleLocationsEXT(commandBuffer
             , cmd->u.set_sample_locations_ext.sample_locations_info          );
          break;
      case VK_CMD_BEGIN_DEBUG_UTILS_LABEL_EXT:
          disp->CmdBeginDebugUtilsLabelEXT(commandBuffer
             , cmd->u.begin_debug_utils_label_ext.label_info          );
          break;
      case VK_CMD_END_DEBUG_UTILS_LABEL_EXT:
          disp->CmdEndDebugUtilsLabelEXT(commandBuffer
          );
          break;
      case VK_CMD_INSERT_DEBUG_UTILS_LABEL_EXT:
          disp->CmdInsertDebugUtilsLabelEXT(commandBuffer
             , cmd->u.insert_debug_utils_label_ext.label_info          );
          break;
      case VK_CMD_WRITE_BUFFER_MARKER_AMD:
          disp->CmdWriteBufferMarkerAMD(commandBuffer
             , cmd->u.write_buffer_marker_amd.pipeline_stage             , cmd->u.write_buffer_marker_amd.dst_buffer             , cmd->u.write_buffer_marker_amd.dst_offset             , cmd->u.write_buffer_marker_amd.marker          );
          break;
      case VK_CMD_BEGIN_RENDER_PASS2:
          disp->CmdBeginRenderPass2(commandBuffer
             , cmd->u.begin_render_pass2.render_pass_begin             , cmd->u.begin_render_pass2.subpass_begin_info          );
          break;
      case VK_CMD_NEXT_SUBPASS2:
          disp->CmdNextSubpass2(commandBuffer
             , cmd->u.next_subpass2.subpass_begin_info             , cmd->u.next_subpass2.subpass_end_info          );
          break;
      case VK_CMD_END_RENDER_PASS2:
          disp->CmdEndRenderPass2(commandBuffer
             , cmd->u.end_render_pass2.subpass_end_info          );
          break;
      case VK_CMD_DRAW_INDIRECT_COUNT:
          disp->CmdDrawIndirectCount(commandBuffer
             , cmd->u.draw_indirect_count.buffer             , cmd->u.draw_indirect_count.offset             , cmd->u.draw_indirect_count.count_buffer             , cmd->u.draw_indirect_count.count_buffer_offset             , cmd->u.draw_indirect_count.max_draw_count             , cmd->u.draw_indirect_count.stride          );
          break;
      case VK_CMD_DRAW_INDEXED_INDIRECT_COUNT:
          disp->CmdDrawIndexedIndirectCount(commandBuffer
             , cmd->u.draw_indexed_indirect_count.buffer             , cmd->u.draw_indexed_indirect_count.offset             , cmd->u.draw_indexed_indirect_count.count_buffer             , cmd->u.draw_indexed_indirect_count.count_buffer_offset             , cmd->u.draw_indexed_indirect_count.max_draw_count             , cmd->u.draw_indexed_indirect_count.stride          );
          break;
      case VK_CMD_SET_CHECKPOINT_NV:
          disp->CmdSetCheckpointNV(commandBuffer
             , cmd->u.set_checkpoint_nv.checkpoint_marker          );
          break;
      case VK_CMD_BIND_TRANSFORM_FEEDBACK_BUFFERS_EXT:
          disp->CmdBindTransformFeedbackBuffersEXT(commandBuffer
             , cmd->u.bind_transform_feedback_buffers_ext.first_binding             , cmd->u.bind_transform_feedback_buffers_ext.binding_count             , cmd->u.bind_transform_feedback_buffers_ext.buffers             , cmd->u.bind_transform_feedback_buffers_ext.offsets             , cmd->u.bind_transform_feedback_buffers_ext.sizes          );
          break;
      case VK_CMD_BEGIN_TRANSFORM_FEEDBACK_EXT:
          disp->CmdBeginTransformFeedbackEXT(commandBuffer
             , cmd->u.begin_transform_feedback_ext.first_counter_buffer             , cmd->u.begin_transform_feedback_ext.counter_buffer_count             , cmd->u.begin_transform_feedback_ext.counter_buffers             , cmd->u.begin_transform_feedback_ext.counter_buffer_offsets          );
          break;
      case VK_CMD_END_TRANSFORM_FEEDBACK_EXT:
          disp->CmdEndTransformFeedbackEXT(commandBuffer
             , cmd->u.end_transform_feedback_ext.first_counter_buffer             , cmd->u.end_transform_feedback_ext.counter_buffer_count             , cmd->u.end_transform_feedback_ext.counter_buffers             , cmd->u.end_transform_feedback_ext.counter_buffer_offsets          );
          break;
      case VK_CMD_BEGIN_QUERY_INDEXED_EXT:
          disp->CmdBeginQueryIndexedEXT(commandBuffer
             , cmd->u.begin_query_indexed_ext.query_pool             , cmd->u.begin_query_indexed_ext.query             , cmd->u.begin_query_indexed_ext.flags             , cmd->u.begin_query_indexed_ext.index          );
          break;
      case VK_CMD_END_QUERY_INDEXED_EXT:
          disp->CmdEndQueryIndexedEXT(commandBuffer
             , cmd->u.end_query_indexed_ext.query_pool             , cmd->u.end_query_indexed_ext.query             , cmd->u.end_query_indexed_ext.index          );
          break;
      case VK_CMD_DRAW_INDIRECT_BYTE_COUNT_EXT:
          disp->CmdDrawIndirectByteCountEXT(commandBuffer
             , cmd->u.draw_indirect_byte_count_ext.instance_count             , cmd->u.draw_indirect_byte_count_ext.first_instance             , cmd->u.draw_indirect_byte_count_ext.counter_buffer             , cmd->u.draw_indirect_byte_count_ext.counter_buffer_offset             , cmd->u.draw_indirect_byte_count_ext.counter_offset             , cmd->u.draw_indirect_byte_count_ext.vertex_stride          );
          break;
      case VK_CMD_SET_EXCLUSIVE_SCISSOR_NV:
          disp->CmdSetExclusiveScissorNV(commandBuffer
             , cmd->u.set_exclusive_scissor_nv.first_exclusive_scissor             , cmd->u.set_exclusive_scissor_nv.exclusive_scissor_count             , cmd->u.set_exclusive_scissor_nv.exclusive_scissors          );
          break;
      case VK_CMD_SET_EXCLUSIVE_SCISSOR_ENABLE_NV:
          disp->CmdSetExclusiveScissorEnableNV(commandBuffer
             , cmd->u.set_exclusive_scissor_enable_nv.first_exclusive_scissor             , cmd->u.set_exclusive_scissor_enable_nv.exclusive_scissor_count             , cmd->u.set_exclusive_scissor_enable_nv.exclusive_scissor_enables          );
          break;
      case VK_CMD_BIND_SHADING_RATE_IMAGE_NV:
          disp->CmdBindShadingRateImageNV(commandBuffer
             , cmd->u.bind_shading_rate_image_nv.image_view             , cmd->u.bind_shading_rate_image_nv.image_layout          );
          break;
      case VK_CMD_SET_VIEWPORT_SHADING_RATE_PALETTE_NV:
          disp->CmdSetViewportShadingRatePaletteNV(commandBuffer
             , cmd->u.set_viewport_shading_rate_palette_nv.first_viewport             , cmd->u.set_viewport_shading_rate_palette_nv.viewport_count             , cmd->u.set_viewport_shading_rate_palette_nv.shading_rate_palettes          );
          break;
      case VK_CMD_SET_COARSE_SAMPLE_ORDER_NV:
          disp->CmdSetCoarseSampleOrderNV(commandBuffer
             , cmd->u.set_coarse_sample_order_nv.sample_order_type             , cmd->u.set_coarse_sample_order_nv.custom_sample_order_count             , cmd->u.set_coarse_sample_order_nv.custom_sample_orders          );
          break;
      case VK_CMD_DRAW_MESH_TASKS_NV:
          disp->CmdDrawMeshTasksNV(commandBuffer
             , cmd->u.draw_mesh_tasks_nv.task_count             , cmd->u.draw_mesh_tasks_nv.first_task          );
          break;
      case VK_CMD_DRAW_MESH_TASKS_INDIRECT_NV:
          disp->CmdDrawMeshTasksIndirectNV(commandBuffer
             , cmd->u.draw_mesh_tasks_indirect_nv.buffer             , cmd->u.draw_mesh_tasks_indirect_nv.offset             , cmd->u.draw_mesh_tasks_indirect_nv.draw_count             , cmd->u.draw_mesh_tasks_indirect_nv.stride          );
          break;
      case VK_CMD_DRAW_MESH_TASKS_INDIRECT_COUNT_NV:
          disp->CmdDrawMeshTasksIndirectCountNV(commandBuffer
             , cmd->u.draw_mesh_tasks_indirect_count_nv.buffer             , cmd->u.draw_mesh_tasks_indirect_count_nv.offset             , cmd->u.draw_mesh_tasks_indirect_count_nv.count_buffer             , cmd->u.draw_mesh_tasks_indirect_count_nv.count_buffer_offset             , cmd->u.draw_mesh_tasks_indirect_count_nv.max_draw_count             , cmd->u.draw_mesh_tasks_indirect_count_nv.stride          );
          break;
      case VK_CMD_DRAW_MESH_TASKS_EXT:
          disp->CmdDrawMeshTasksEXT(commandBuffer
             , cmd->u.draw_mesh_tasks_ext.group_count_x             , cmd->u.draw_mesh_tasks_ext.group_count_y             , cmd->u.draw_mesh_tasks_ext.group_count_z          );
          break;
      case VK_CMD_DRAW_MESH_TASKS_INDIRECT_EXT:
          disp->CmdDrawMeshTasksIndirectEXT(commandBuffer
             , cmd->u.draw_mesh_tasks_indirect_ext.buffer             , cmd->u.draw_mesh_tasks_indirect_ext.offset             , cmd->u.draw_mesh_tasks_indirect_ext.draw_count             , cmd->u.draw_mesh_tasks_indirect_ext.stride          );
          break;
      case VK_CMD_DRAW_MESH_TASKS_INDIRECT_COUNT_EXT:
          disp->CmdDrawMeshTasksIndirectCountEXT(commandBuffer
             , cmd->u.draw_mesh_tasks_indirect_count_ext.buffer             , cmd->u.draw_mesh_tasks_indirect_count_ext.offset             , cmd->u.draw_mesh_tasks_indirect_count_ext.count_buffer             , cmd->u.draw_mesh_tasks_indirect_count_ext.count_buffer_offset             , cmd->u.draw_mesh_tasks_indirect_count_ext.max_draw_count             , cmd->u.draw_mesh_tasks_indirect_count_ext.stride          );
          break;
      case VK_CMD_BIND_INVOCATION_MASK_HUAWEI:
          disp->CmdBindInvocationMaskHUAWEI(commandBuffer
             , cmd->u.bind_invocation_mask_huawei.image_view             , cmd->u.bind_invocation_mask_huawei.image_layout          );
          break;
      case VK_CMD_COPY_ACCELERATION_STRUCTURE_NV:
          disp->CmdCopyAccelerationStructureNV(commandBuffer
             , cmd->u.copy_acceleration_structure_nv.dst             , cmd->u.copy_acceleration_structure_nv.src             , cmd->u.copy_acceleration_structure_nv.mode          );
          break;
      case VK_CMD_COPY_ACCELERATION_STRUCTURE_KHR:
          disp->CmdCopyAccelerationStructureKHR(commandBuffer
             , cmd->u.copy_acceleration_structure_khr.info          );
          break;
      case VK_CMD_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_KHR:
          disp->CmdCopyAccelerationStructureToMemoryKHR(commandBuffer
             , cmd->u.copy_acceleration_structure_to_memory_khr.info          );
          break;
      case VK_CMD_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_KHR:
          disp->CmdCopyMemoryToAccelerationStructureKHR(commandBuffer
             , cmd->u.copy_memory_to_acceleration_structure_khr.info          );
          break;
      case VK_CMD_WRITE_ACCELERATION_STRUCTURES_PROPERTIES_KHR:
          disp->CmdWriteAccelerationStructuresPropertiesKHR(commandBuffer
             , cmd->u.write_acceleration_structures_properties_khr.acceleration_structure_count             , cmd->u.write_acceleration_structures_properties_khr.acceleration_structures             , cmd->u.write_acceleration_structures_properties_khr.query_type             , cmd->u.write_acceleration_structures_properties_khr.query_pool             , cmd->u.write_acceleration_structures_properties_khr.first_query          );
          break;
      case VK_CMD_WRITE_ACCELERATION_STRUCTURES_PROPERTIES_NV:
          disp->CmdWriteAccelerationStructuresPropertiesNV(commandBuffer
             , cmd->u.write_acceleration_structures_properties_nv.acceleration_structure_count             , cmd->u.write_acceleration_structures_properties_nv.acceleration_structures             , cmd->u.write_acceleration_structures_properties_nv.query_type             , cmd->u.write_acceleration_structures_properties_nv.query_pool             , cmd->u.write_acceleration_structures_properties_nv.first_query          );
          break;
      case VK_CMD_BUILD_ACCELERATION_STRUCTURE_NV:
          disp->CmdBuildAccelerationStructureNV(commandBuffer
             , cmd->u.build_acceleration_structure_nv.info             , cmd->u.build_acceleration_structure_nv.instance_data             , cmd->u.build_acceleration_structure_nv.instance_offset             , cmd->u.build_acceleration_structure_nv.update             , cmd->u.build_acceleration_structure_nv.dst             , cmd->u.build_acceleration_structure_nv.src             , cmd->u.build_acceleration_structure_nv.scratch             , cmd->u.build_acceleration_structure_nv.scratch_offset          );
          break;
      case VK_CMD_TRACE_RAYS_KHR:
          disp->CmdTraceRaysKHR(commandBuffer
             , cmd->u.trace_rays_khr.raygen_shader_binding_table             , cmd->u.trace_rays_khr.miss_shader_binding_table             , cmd->u.trace_rays_khr.hit_shader_binding_table             , cmd->u.trace_rays_khr.callable_shader_binding_table             , cmd->u.trace_rays_khr.width             , cmd->u.trace_rays_khr.height             , cmd->u.trace_rays_khr.depth          );
          break;
      case VK_CMD_TRACE_RAYS_NV:
          disp->CmdTraceRaysNV(commandBuffer
             , cmd->u.trace_rays_nv.raygen_shader_binding_table_buffer             , cmd->u.trace_rays_nv.raygen_shader_binding_offset             , cmd->u.trace_rays_nv.miss_shader_binding_table_buffer             , cmd->u.trace_rays_nv.miss_shader_binding_offset             , cmd->u.trace_rays_nv.miss_shader_binding_stride             , cmd->u.trace_rays_nv.hit_shader_binding_table_buffer             , cmd->u.trace_rays_nv.hit_shader_binding_offset             , cmd->u.trace_rays_nv.hit_shader_binding_stride             , cmd->u.trace_rays_nv.callable_shader_binding_table_buffer             , cmd->u.trace_rays_nv.callable_shader_binding_offset             , cmd->u.trace_rays_nv.callable_shader_binding_stride             , cmd->u.trace_rays_nv.width             , cmd->u.trace_rays_nv.height             , cmd->u.trace_rays_nv.depth          );
          break;
      case VK_CMD_TRACE_RAYS_INDIRECT_KHR:
          disp->CmdTraceRaysIndirectKHR(commandBuffer
             , cmd->u.trace_rays_indirect_khr.raygen_shader_binding_table             , cmd->u.trace_rays_indirect_khr.miss_shader_binding_table             , cmd->u.trace_rays_indirect_khr.hit_shader_binding_table             , cmd->u.trace_rays_indirect_khr.callable_shader_binding_table             , cmd->u.trace_rays_indirect_khr.indirect_device_address          );
          break;
      case VK_CMD_TRACE_RAYS_INDIRECT2_KHR:
          disp->CmdTraceRaysIndirect2KHR(commandBuffer
             , cmd->u.trace_rays_indirect2_khr.indirect_device_address          );
          break;
      case VK_CMD_BUILD_CLUSTER_ACCELERATION_STRUCTURE_INDIRECT_NV:
          disp->CmdBuildClusterAccelerationStructureIndirectNV(commandBuffer
             , cmd->u.build_cluster_acceleration_structure_indirect_nv.command_infos          );
          break;
      case VK_CMD_SET_RAY_TRACING_PIPELINE_STACK_SIZE_KHR:
          disp->CmdSetRayTracingPipelineStackSizeKHR(commandBuffer
             , cmd->u.set_ray_tracing_pipeline_stack_size_khr.pipeline_stack_size          );
          break;
      case VK_CMD_SET_PERFORMANCE_MARKER_INTEL:
          disp->CmdSetPerformanceMarkerINTEL(commandBuffer
             , cmd->u.set_performance_marker_intel.marker_info          );
          break;
      case VK_CMD_SET_PERFORMANCE_STREAM_MARKER_INTEL:
          disp->CmdSetPerformanceStreamMarkerINTEL(commandBuffer
             , cmd->u.set_performance_stream_marker_intel.marker_info          );
          break;
      case VK_CMD_SET_PERFORMANCE_OVERRIDE_INTEL:
          disp->CmdSetPerformanceOverrideINTEL(commandBuffer
             , cmd->u.set_performance_override_intel.override_info          );
          break;
      case VK_CMD_SET_LINE_STIPPLE:
          disp->CmdSetLineStipple(commandBuffer
             , cmd->u.set_line_stipple.line_stipple_factor             , cmd->u.set_line_stipple.line_stipple_pattern          );
          break;
      case VK_CMD_BUILD_ACCELERATION_STRUCTURES_KHR:
          disp->CmdBuildAccelerationStructuresKHR(commandBuffer
             , cmd->u.build_acceleration_structures_khr.info_count             , cmd->u.build_acceleration_structures_khr.infos             , cmd->u.build_acceleration_structures_khr.pp_build_range_infos          );
          break;
      case VK_CMD_BUILD_ACCELERATION_STRUCTURES_INDIRECT_KHR:
          disp->CmdBuildAccelerationStructuresIndirectKHR(commandBuffer
             , cmd->u.build_acceleration_structures_indirect_khr.info_count             , cmd->u.build_acceleration_structures_indirect_khr.infos             , cmd->u.build_acceleration_structures_indirect_khr.indirect_device_addresses             , cmd->u.build_acceleration_structures_indirect_khr.indirect_strides             , cmd->u.build_acceleration_structures_indirect_khr.pp_max_primitive_counts          );
          break;
      case VK_CMD_SET_CULL_MODE:
          disp->CmdSetCullMode(commandBuffer
             , cmd->u.set_cull_mode.cull_mode          );
          break;
      case VK_CMD_SET_FRONT_FACE:
          disp->CmdSetFrontFace(commandBuffer
             , cmd->u.set_front_face.front_face          );
          break;
      case VK_CMD_SET_PRIMITIVE_TOPOLOGY:
          disp->CmdSetPrimitiveTopology(commandBuffer
             , cmd->u.set_primitive_topology.primitive_topology          );
          break;
      case VK_CMD_SET_VIEWPORT_WITH_COUNT:
          disp->CmdSetViewportWithCount(commandBuffer
             , cmd->u.set_viewport_with_count.viewport_count             , cmd->u.set_viewport_with_count.viewports          );
          break;
      case VK_CMD_SET_SCISSOR_WITH_COUNT:
          disp->CmdSetScissorWithCount(commandBuffer
             , cmd->u.set_scissor_with_count.scissor_count             , cmd->u.set_scissor_with_count.scissors          );
          break;
      case VK_CMD_BIND_INDEX_BUFFER2:
          disp->CmdBindIndexBuffer2(commandBuffer
             , cmd->u.bind_index_buffer2.buffer             , cmd->u.bind_index_buffer2.offset             , cmd->u.bind_index_buffer2.size             , cmd->u.bind_index_buffer2.index_type          );
          break;
      case VK_CMD_BIND_VERTEX_BUFFERS2:
          disp->CmdBindVertexBuffers2(commandBuffer
             , cmd->u.bind_vertex_buffers2.first_binding             , cmd->u.bind_vertex_buffers2.binding_count             , cmd->u.bind_vertex_buffers2.buffers             , cmd->u.bind_vertex_buffers2.offsets             , cmd->u.bind_vertex_buffers2.sizes             , cmd->u.bind_vertex_buffers2.strides          );
          break;
      case VK_CMD_SET_DEPTH_TEST_ENABLE:
          disp->CmdSetDepthTestEnable(commandBuffer
             , cmd->u.set_depth_test_enable.depth_test_enable          );
          break;
      case VK_CMD_SET_DEPTH_WRITE_ENABLE:
          disp->CmdSetDepthWriteEnable(commandBuffer
             , cmd->u.set_depth_write_enable.depth_write_enable          );
          break;
      case VK_CMD_SET_DEPTH_COMPARE_OP:
          disp->CmdSetDepthCompareOp(commandBuffer
             , cmd->u.set_depth_compare_op.depth_compare_op          );
          break;
      case VK_CMD_SET_DEPTH_BOUNDS_TEST_ENABLE:
          disp->CmdSetDepthBoundsTestEnable(commandBuffer
             , cmd->u.set_depth_bounds_test_enable.depth_bounds_test_enable          );
          break;
      case VK_CMD_SET_STENCIL_TEST_ENABLE:
          disp->CmdSetStencilTestEnable(commandBuffer
             , cmd->u.set_stencil_test_enable.stencil_test_enable          );
          break;
      case VK_CMD_SET_STENCIL_OP:
          disp->CmdSetStencilOp(commandBuffer
             , cmd->u.set_stencil_op.face_mask             , cmd->u.set_stencil_op.fail_op             , cmd->u.set_stencil_op.pass_op             , cmd->u.set_stencil_op.depth_fail_op             , cmd->u.set_stencil_op.compare_op          );
          break;
      case VK_CMD_SET_PATCH_CONTROL_POINTS_EXT:
          disp->CmdSetPatchControlPointsEXT(commandBuffer
             , cmd->u.set_patch_control_points_ext.patch_control_points          );
          break;
      case VK_CMD_SET_RASTERIZER_DISCARD_ENABLE:
          disp->CmdSetRasterizerDiscardEnable(commandBuffer
             , cmd->u.set_rasterizer_discard_enable.rasterizer_discard_enable          );
          break;
      case VK_CMD_SET_DEPTH_BIAS_ENABLE:
          disp->CmdSetDepthBiasEnable(commandBuffer
             , cmd->u.set_depth_bias_enable.depth_bias_enable          );
          break;
      case VK_CMD_SET_LOGIC_OP_EXT:
          disp->CmdSetLogicOpEXT(commandBuffer
             , cmd->u.set_logic_op_ext.logic_op          );
          break;
      case VK_CMD_SET_PRIMITIVE_RESTART_ENABLE:
          disp->CmdSetPrimitiveRestartEnable(commandBuffer
             , cmd->u.set_primitive_restart_enable.primitive_restart_enable          );
          break;
      case VK_CMD_SET_TESSELLATION_DOMAIN_ORIGIN_EXT:
          disp->CmdSetTessellationDomainOriginEXT(commandBuffer
             , cmd->u.set_tessellation_domain_origin_ext.domain_origin          );
          break;
      case VK_CMD_SET_DEPTH_CLAMP_ENABLE_EXT:
          disp->CmdSetDepthClampEnableEXT(commandBuffer
             , cmd->u.set_depth_clamp_enable_ext.depth_clamp_enable          );
          break;
      case VK_CMD_SET_POLYGON_MODE_EXT:
          disp->CmdSetPolygonModeEXT(commandBuffer
             , cmd->u.set_polygon_mode_ext.polygon_mode          );
          break;
      case VK_CMD_SET_RASTERIZATION_SAMPLES_EXT:
          disp->CmdSetRasterizationSamplesEXT(commandBuffer
             , cmd->u.set_rasterization_samples_ext.rasterization_samples          );
          break;
      case VK_CMD_SET_SAMPLE_MASK_EXT:
          disp->CmdSetSampleMaskEXT(commandBuffer
             , cmd->u.set_sample_mask_ext.samples             , cmd->u.set_sample_mask_ext.sample_mask          );
          break;
      case VK_CMD_SET_ALPHA_TO_COVERAGE_ENABLE_EXT:
          disp->CmdSetAlphaToCoverageEnableEXT(commandBuffer
             , cmd->u.set_alpha_to_coverage_enable_ext.alpha_to_coverage_enable          );
          break;
      case VK_CMD_SET_ALPHA_TO_ONE_ENABLE_EXT:
          disp->CmdSetAlphaToOneEnableEXT(commandBuffer
             , cmd->u.set_alpha_to_one_enable_ext.alpha_to_one_enable          );
          break;
      case VK_CMD_SET_LOGIC_OP_ENABLE_EXT:
          disp->CmdSetLogicOpEnableEXT(commandBuffer
             , cmd->u.set_logic_op_enable_ext.logic_op_enable          );
          break;
      case VK_CMD_SET_COLOR_BLEND_ENABLE_EXT:
          disp->CmdSetColorBlendEnableEXT(commandBuffer
             , cmd->u.set_color_blend_enable_ext.first_attachment             , cmd->u.set_color_blend_enable_ext.attachment_count             , cmd->u.set_color_blend_enable_ext.color_blend_enables          );
          break;
      case VK_CMD_SET_COLOR_BLEND_EQUATION_EXT:
          disp->CmdSetColorBlendEquationEXT(commandBuffer
             , cmd->u.set_color_blend_equation_ext.first_attachment             , cmd->u.set_color_blend_equation_ext.attachment_count             , cmd->u.set_color_blend_equation_ext.color_blend_equations          );
          break;
      case VK_CMD_SET_COLOR_WRITE_MASK_EXT:
          disp->CmdSetColorWriteMaskEXT(commandBuffer
             , cmd->u.set_color_write_mask_ext.first_attachment             , cmd->u.set_color_write_mask_ext.attachment_count             , cmd->u.set_color_write_mask_ext.color_write_masks          );
          break;
      case VK_CMD_SET_RASTERIZATION_STREAM_EXT:
          disp->CmdSetRasterizationStreamEXT(commandBuffer
             , cmd->u.set_rasterization_stream_ext.rasterization_stream          );
          break;
      case VK_CMD_SET_CONSERVATIVE_RASTERIZATION_MODE_EXT:
          disp->CmdSetConservativeRasterizationModeEXT(commandBuffer
             , cmd->u.set_conservative_rasterization_mode_ext.conservative_rasterization_mode          );
          break;
      case VK_CMD_SET_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT:
          disp->CmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer
             , cmd->u.set_extra_primitive_overestimation_size_ext.extra_primitive_overestimation_size          );
          break;
      case VK_CMD_SET_DEPTH_CLIP_ENABLE_EXT:
          disp->CmdSetDepthClipEnableEXT(commandBuffer
             , cmd->u.set_depth_clip_enable_ext.depth_clip_enable          );
          break;
      case VK_CMD_SET_SAMPLE_LOCATIONS_ENABLE_EXT:
          disp->CmdSetSampleLocationsEnableEXT(commandBuffer
             , cmd->u.set_sample_locations_enable_ext.sample_locations_enable          );
          break;
      case VK_CMD_SET_COLOR_BLEND_ADVANCED_EXT:
          disp->CmdSetColorBlendAdvancedEXT(commandBuffer
             , cmd->u.set_color_blend_advanced_ext.first_attachment             , cmd->u.set_color_blend_advanced_ext.attachment_count             , cmd->u.set_color_blend_advanced_ext.color_blend_advanced          );
          break;
      case VK_CMD_SET_PROVOKING_VERTEX_MODE_EXT:
          disp->CmdSetProvokingVertexModeEXT(commandBuffer
             , cmd->u.set_provoking_vertex_mode_ext.provoking_vertex_mode          );
          break;
      case VK_CMD_SET_LINE_RASTERIZATION_MODE_EXT:
          disp->CmdSetLineRasterizationModeEXT(commandBuffer
             , cmd->u.set_line_rasterization_mode_ext.line_rasterization_mode          );
          break;
      case VK_CMD_SET_LINE_STIPPLE_ENABLE_EXT:
          disp->CmdSetLineStippleEnableEXT(commandBuffer
             , cmd->u.set_line_stipple_enable_ext.stippled_line_enable          );
          break;
      case VK_CMD_SET_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT:
          disp->CmdSetDepthClipNegativeOneToOneEXT(commandBuffer
             , cmd->u.set_depth_clip_negative_one_to_one_ext.negative_one_to_one          );
          break;
      case VK_CMD_SET_VIEWPORT_WSCALING_ENABLE_NV:
          disp->CmdSetViewportWScalingEnableNV(commandBuffer
             , cmd->u.set_viewport_wscaling_enable_nv.viewport_wscaling_enable          );
          break;
      case VK_CMD_SET_VIEWPORT_SWIZZLE_NV:
          disp->CmdSetViewportSwizzleNV(commandBuffer
             , cmd->u.set_viewport_swizzle_nv.first_viewport             , cmd->u.set_viewport_swizzle_nv.viewport_count             , cmd->u.set_viewport_swizzle_nv.viewport_swizzles          );
          break;
      case VK_CMD_SET_COVERAGE_TO_COLOR_ENABLE_NV:
          disp->CmdSetCoverageToColorEnableNV(commandBuffer
             , cmd->u.set_coverage_to_color_enable_nv.coverage_to_color_enable          );
          break;
      case VK_CMD_SET_COVERAGE_TO_COLOR_LOCATION_NV:
          disp->CmdSetCoverageToColorLocationNV(commandBuffer
             , cmd->u.set_coverage_to_color_location_nv.coverage_to_color_location          );
          break;
      case VK_CMD_SET_COVERAGE_MODULATION_MODE_NV:
          disp->CmdSetCoverageModulationModeNV(commandBuffer
             , cmd->u.set_coverage_modulation_mode_nv.coverage_modulation_mode          );
          break;
      case VK_CMD_SET_COVERAGE_MODULATION_TABLE_ENABLE_NV:
          disp->CmdSetCoverageModulationTableEnableNV(commandBuffer
             , cmd->u.set_coverage_modulation_table_enable_nv.coverage_modulation_table_enable          );
          break;
      case VK_CMD_SET_COVERAGE_MODULATION_TABLE_NV:
          disp->CmdSetCoverageModulationTableNV(commandBuffer
             , cmd->u.set_coverage_modulation_table_nv.coverage_modulation_table_count             , cmd->u.set_coverage_modulation_table_nv.coverage_modulation_table          );
          break;
      case VK_CMD_SET_SHADING_RATE_IMAGE_ENABLE_NV:
          disp->CmdSetShadingRateImageEnableNV(commandBuffer
             , cmd->u.set_shading_rate_image_enable_nv.shading_rate_image_enable          );
          break;
      case VK_CMD_SET_COVERAGE_REDUCTION_MODE_NV:
          disp->CmdSetCoverageReductionModeNV(commandBuffer
             , cmd->u.set_coverage_reduction_mode_nv.coverage_reduction_mode          );
          break;
      case VK_CMD_SET_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV:
          disp->CmdSetRepresentativeFragmentTestEnableNV(commandBuffer
             , cmd->u.set_representative_fragment_test_enable_nv.representative_fragment_test_enable          );
          break;
      case VK_CMD_COPY_BUFFER2:
          disp->CmdCopyBuffer2(commandBuffer
             , cmd->u.copy_buffer2.copy_buffer_info          );
          break;
      case VK_CMD_COPY_IMAGE2:
          disp->CmdCopyImage2(commandBuffer
             , cmd->u.copy_image2.copy_image_info          );
          break;
      case VK_CMD_BLIT_IMAGE2:
          disp->CmdBlitImage2(commandBuffer
             , cmd->u.blit_image2.blit_image_info          );
          break;
      case VK_CMD_COPY_BUFFER_TO_IMAGE2:
          disp->CmdCopyBufferToImage2(commandBuffer
             , cmd->u.copy_buffer_to_image2.copy_buffer_to_image_info          );
          break;
      case VK_CMD_COPY_IMAGE_TO_BUFFER2:
          disp->CmdCopyImageToBuffer2(commandBuffer
             , cmd->u.copy_image_to_buffer2.copy_image_to_buffer_info          );
          break;
      case VK_CMD_RESOLVE_IMAGE2:
          disp->CmdResolveImage2(commandBuffer
             , cmd->u.resolve_image2.resolve_image_info          );
          break;
      case VK_CMD_SET_FRAGMENT_SHADING_RATE_KHR:
          disp->CmdSetFragmentShadingRateKHR(commandBuffer
             , cmd->u.set_fragment_shading_rate_khr.fragment_size             , cmd->u.set_fragment_shading_rate_khr.combiner_ops          );
          break;
      case VK_CMD_SET_FRAGMENT_SHADING_RATE_ENUM_NV:
          disp->CmdSetFragmentShadingRateEnumNV(commandBuffer
             , cmd->u.set_fragment_shading_rate_enum_nv.shading_rate             , cmd->u.set_fragment_shading_rate_enum_nv.combiner_ops          );
          break;
      case VK_CMD_SET_VERTEX_INPUT_EXT:
          disp->CmdSetVertexInputEXT(commandBuffer
             , cmd->u.set_vertex_input_ext.vertex_binding_description_count             , cmd->u.set_vertex_input_ext.vertex_binding_descriptions             , cmd->u.set_vertex_input_ext.vertex_attribute_description_count             , cmd->u.set_vertex_input_ext.vertex_attribute_descriptions          );
          break;
      case VK_CMD_SET_COLOR_WRITE_ENABLE_EXT:
          disp->CmdSetColorWriteEnableEXT(commandBuffer
             , cmd->u.set_color_write_enable_ext.attachment_count             , cmd->u.set_color_write_enable_ext.color_write_enables          );
          break;
      case VK_CMD_SET_EVENT2:
          disp->CmdSetEvent2(commandBuffer
             , cmd->u.set_event2.event             , cmd->u.set_event2.dependency_info          );
          break;
      case VK_CMD_RESET_EVENT2:
          disp->CmdResetEvent2(commandBuffer
             , cmd->u.reset_event2.event             , cmd->u.reset_event2.stage_mask          );
          break;
      case VK_CMD_WAIT_EVENTS2:
          disp->CmdWaitEvents2(commandBuffer
             , cmd->u.wait_events2.event_count             , cmd->u.wait_events2.events             , cmd->u.wait_events2.dependency_infos          );
          break;
      case VK_CMD_PIPELINE_BARRIER2:
          disp->CmdPipelineBarrier2(commandBuffer
             , cmd->u.pipeline_barrier2.dependency_info          );
          break;
      case VK_CMD_WRITE_TIMESTAMP2:
          disp->CmdWriteTimestamp2(commandBuffer
             , cmd->u.write_timestamp2.stage             , cmd->u.write_timestamp2.query_pool             , cmd->u.write_timestamp2.query          );
          break;
      case VK_CMD_WRITE_BUFFER_MARKER2_AMD:
          disp->CmdWriteBufferMarker2AMD(commandBuffer
             , cmd->u.write_buffer_marker2_amd.stage             , cmd->u.write_buffer_marker2_amd.dst_buffer             , cmd->u.write_buffer_marker2_amd.dst_offset             , cmd->u.write_buffer_marker2_amd.marker          );
          break;
      case VK_CMD_DECODE_VIDEO_KHR:
          disp->CmdDecodeVideoKHR(commandBuffer
             , cmd->u.decode_video_khr.decode_info          );
          break;
      case VK_CMD_BEGIN_VIDEO_CODING_KHR:
          disp->CmdBeginVideoCodingKHR(commandBuffer
             , cmd->u.begin_video_coding_khr.begin_info          );
          break;
      case VK_CMD_CONTROL_VIDEO_CODING_KHR:
          disp->CmdControlVideoCodingKHR(commandBuffer
             , cmd->u.control_video_coding_khr.coding_control_info          );
          break;
      case VK_CMD_END_VIDEO_CODING_KHR:
          disp->CmdEndVideoCodingKHR(commandBuffer
             , cmd->u.end_video_coding_khr.end_coding_info          );
          break;
      case VK_CMD_ENCODE_VIDEO_KHR:
          disp->CmdEncodeVideoKHR(commandBuffer
             , cmd->u.encode_video_khr.encode_info          );
          break;
      case VK_CMD_DECOMPRESS_MEMORY_NV:
          disp->CmdDecompressMemoryNV(commandBuffer
             , cmd->u.decompress_memory_nv.decompress_region_count             , cmd->u.decompress_memory_nv.decompress_memory_regions          );
          break;
      case VK_CMD_DECOMPRESS_MEMORY_INDIRECT_COUNT_NV:
          disp->CmdDecompressMemoryIndirectCountNV(commandBuffer
             , cmd->u.decompress_memory_indirect_count_nv.indirect_commands_address             , cmd->u.decompress_memory_indirect_count_nv.indirect_commands_count_address             , cmd->u.decompress_memory_indirect_count_nv.stride          );
          break;
      case VK_CMD_BUILD_PARTITIONED_ACCELERATION_STRUCTURES_NV:
          disp->CmdBuildPartitionedAccelerationStructuresNV(commandBuffer
             , cmd->u.build_partitioned_acceleration_structures_nv.build_info          );
          break;
      case VK_CMD_CU_LAUNCH_KERNEL_NVX:
          disp->CmdCuLaunchKernelNVX(commandBuffer
             , cmd->u.cu_launch_kernel_nvx.launch_info          );
          break;
      case VK_CMD_BIND_DESCRIPTOR_BUFFERS_EXT:
          disp->CmdBindDescriptorBuffersEXT(commandBuffer
             , cmd->u.bind_descriptor_buffers_ext.buffer_count             , cmd->u.bind_descriptor_buffers_ext.binding_infos          );
          break;
      case VK_CMD_SET_DESCRIPTOR_BUFFER_OFFSETS_EXT:
          disp->CmdSetDescriptorBufferOffsetsEXT(commandBuffer
             , cmd->u.set_descriptor_buffer_offsets_ext.pipeline_bind_point             , cmd->u.set_descriptor_buffer_offsets_ext.layout             , cmd->u.set_descriptor_buffer_offsets_ext.first_set             , cmd->u.set_descriptor_buffer_offsets_ext.set_count             , cmd->u.set_descriptor_buffer_offsets_ext.buffer_indices             , cmd->u.set_descriptor_buffer_offsets_ext.offsets          );
          break;
      case VK_CMD_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_EXT:
          disp->CmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer
             , cmd->u.bind_descriptor_buffer_embedded_samplers_ext.pipeline_bind_point             , cmd->u.bind_descriptor_buffer_embedded_samplers_ext.layout             , cmd->u.bind_descriptor_buffer_embedded_samplers_ext.set          );
          break;
      case VK_CMD_BEGIN_RENDERING:
          disp->CmdBeginRendering(commandBuffer
             , cmd->u.begin_rendering.rendering_info          );
          break;
      case VK_CMD_END_RENDERING:
          disp->CmdEndRendering(commandBuffer
          );
          break;
      case VK_CMD_END_RENDERING2_EXT:
          disp->CmdEndRendering2EXT(commandBuffer
             , cmd->u.end_rendering2_ext.rendering_end_info          );
          break;
      case VK_CMD_BUILD_MICROMAPS_EXT:
          disp->CmdBuildMicromapsEXT(commandBuffer
             , cmd->u.build_micromaps_ext.info_count             , cmd->u.build_micromaps_ext.infos          );
          break;
      case VK_CMD_COPY_MICROMAP_EXT:
          disp->CmdCopyMicromapEXT(commandBuffer
             , cmd->u.copy_micromap_ext.info          );
          break;
      case VK_CMD_COPY_MICROMAP_TO_MEMORY_EXT:
          disp->CmdCopyMicromapToMemoryEXT(commandBuffer
             , cmd->u.copy_micromap_to_memory_ext.info          );
          break;
      case VK_CMD_COPY_MEMORY_TO_MICROMAP_EXT:
          disp->CmdCopyMemoryToMicromapEXT(commandBuffer
             , cmd->u.copy_memory_to_micromap_ext.info          );
          break;
      case VK_CMD_WRITE_MICROMAPS_PROPERTIES_EXT:
          disp->CmdWriteMicromapsPropertiesEXT(commandBuffer
             , cmd->u.write_micromaps_properties_ext.micromap_count             , cmd->u.write_micromaps_properties_ext.micromaps             , cmd->u.write_micromaps_properties_ext.query_type             , cmd->u.write_micromaps_properties_ext.query_pool             , cmd->u.write_micromaps_properties_ext.first_query          );
          break;
      case VK_CMD_BIND_TILE_MEMORY_QCOM:
          disp->CmdBindTileMemoryQCOM(commandBuffer
             , cmd->u.bind_tile_memory_qcom.tile_memory_bind_info          );
          break;
      case VK_CMD_OPTICAL_FLOW_EXECUTE_NV:
          disp->CmdOpticalFlowExecuteNV(commandBuffer
             , cmd->u.optical_flow_execute_nv.session             , cmd->u.optical_flow_execute_nv.execute_info          );
          break;
      case VK_CMD_SET_DEPTH_BIAS2_EXT:
          disp->CmdSetDepthBias2EXT(commandBuffer
             , cmd->u.set_depth_bias2_ext.depth_bias_info          );
          break;
      case VK_CMD_BIND_SHADERS_EXT:
          disp->CmdBindShadersEXT(commandBuffer
             , cmd->u.bind_shaders_ext.stage_count             , cmd->u.bind_shaders_ext.stages             , cmd->u.bind_shaders_ext.shaders          );
          break;
      case VK_CMD_BIND_DESCRIPTOR_SETS2:
          disp->CmdBindDescriptorSets2(commandBuffer
             , cmd->u.bind_descriptor_sets2.bind_descriptor_sets_info          );
          break;
      case VK_CMD_PUSH_CONSTANTS2:
          disp->CmdPushConstants2(commandBuffer
             , cmd->u.push_constants2.push_constants_info          );
          break;
      case VK_CMD_PUSH_DESCRIPTOR_SET2:
          disp->CmdPushDescriptorSet2(commandBuffer
             , cmd->u.push_descriptor_set2.push_descriptor_set_info          );
          break;
      case VK_CMD_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE2:
          disp->CmdPushDescriptorSetWithTemplate2(commandBuffer
             , cmd->u.push_descriptor_set_with_template2.push_descriptor_set_with_template_info          );
          break;
      case VK_CMD_SET_DESCRIPTOR_BUFFER_OFFSETS2_EXT:
          disp->CmdSetDescriptorBufferOffsets2EXT(commandBuffer
             , cmd->u.set_descriptor_buffer_offsets2_ext.set_descriptor_buffer_offsets_info          );
          break;
      case VK_CMD_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS2_EXT:
          disp->CmdBindDescriptorBufferEmbeddedSamplers2EXT(commandBuffer
             , cmd->u.bind_descriptor_buffer_embedded_samplers2_ext.bind_descriptor_buffer_embedded_samplers_info          );
          break;
      case VK_CMD_SET_RENDERING_ATTACHMENT_LOCATIONS:
          disp->CmdSetRenderingAttachmentLocations(commandBuffer
             , cmd->u.set_rendering_attachment_locations.location_info          );
          break;
      case VK_CMD_SET_RENDERING_INPUT_ATTACHMENT_INDICES:
          disp->CmdSetRenderingInputAttachmentIndices(commandBuffer
             , cmd->u.set_rendering_input_attachment_indices.input_attachment_index_info          );
          break;
      case VK_CMD_SET_DEPTH_CLAMP_RANGE_EXT:
          disp->CmdSetDepthClampRangeEXT(commandBuffer
             , cmd->u.set_depth_clamp_range_ext.depth_clamp_mode             , cmd->u.set_depth_clamp_range_ext.depth_clamp_range          );
          break;
      case VK_CMD_CONVERT_COOPERATIVE_VECTOR_MATRIX_NV:
          disp->CmdConvertCooperativeVectorMatrixNV(commandBuffer
             , cmd->u.convert_cooperative_vector_matrix_nv.info_count             , cmd->u.convert_cooperative_vector_matrix_nv.infos          );
          break;
      case VK_CMD_DISPATCH_TILE_QCOM:
          disp->CmdDispatchTileQCOM(commandBuffer
             , cmd->u.dispatch_tile_qcom.dispatch_tile_info          );
          break;
      case VK_CMD_BEGIN_PER_TILE_EXECUTION_QCOM:
          disp->CmdBeginPerTileExecutionQCOM(commandBuffer
             , cmd->u.begin_per_tile_execution_qcom.per_tile_begin_info          );
          break;
      case VK_CMD_END_PER_TILE_EXECUTION_QCOM:
          disp->CmdEndPerTileExecutionQCOM(commandBuffer
             , cmd->u.end_per_tile_execution_qcom.per_tile_end_info          );
          break;
      case VK_CMD_COPY_TENSOR_ARM:
          disp->CmdCopyTensorARM(commandBuffer
             , cmd->u.copy_tensor_arm.copy_tensor_info          );
          break;
      case VK_CMD_DISPATCH_DATA_GRAPH_ARM:
          disp->CmdDispatchDataGraphARM(commandBuffer
             , cmd->u.dispatch_data_graph_arm.session             , cmd->u.dispatch_data_graph_arm.info          );
          break;
      default: UNREACHABLE("Unsupported command");
      }
   }
}




VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_bind_pipeline(&cmd_buffer->cmd_queue,
                                       pipelineBindPoint, pipeline);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
   } else {
      vk_cmd_enqueue_CmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_attachment_feedback_loop_enable_ext(&cmd_buffer->cmd_queue,
                                       aspectMask);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
   } else {
      vk_cmd_enqueue_CmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_viewport(&cmd_buffer->cmd_queue,
                                       firstViewport, viewportCount, pViewports);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
   } else {
      vk_cmd_enqueue_CmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_scissor(&cmd_buffer->cmd_queue,
                                       firstScissor, scissorCount, pScissors);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
   } else {
      vk_cmd_enqueue_CmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_line_width(&cmd_buffer->cmd_queue,
                                       lineWidth);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetLineWidth(commandBuffer, lineWidth);
   } else {
      vk_cmd_enqueue_CmdSetLineWidth(commandBuffer, lineWidth);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_depth_bias(&cmd_buffer->cmd_queue,
                                       depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
   } else {
      vk_cmd_enqueue_CmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4])
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_blend_constants(&cmd_buffer->cmd_queue,
                                       blendConstants);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4])
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetBlendConstants(commandBuffer, blendConstants);
   } else {
      vk_cmd_enqueue_CmdSetBlendConstants(commandBuffer, blendConstants);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_depth_bounds(&cmd_buffer->cmd_queue,
                                       minDepthBounds, maxDepthBounds);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
   } else {
      vk_cmd_enqueue_CmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_stencil_compare_mask(&cmd_buffer->cmd_queue,
                                       faceMask, compareMask);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
   } else {
      vk_cmd_enqueue_CmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_stencil_write_mask(&cmd_buffer->cmd_queue,
                                       faceMask, writeMask);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
   } else {
      vk_cmd_enqueue_CmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_stencil_reference(&cmd_buffer->cmd_queue,
                                       faceMask, reference);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetStencilReference(commandBuffer, faceMask, reference);
   } else {
      vk_cmd_enqueue_CmdSetStencilReference(commandBuffer, faceMask, reference);
   }
}



/* vk_cmd_enqueue_CmdBindDescriptorSets() is hand-typed in vk_cmd_enqueue.c */

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
   } else {
      vk_cmd_enqueue_CmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_bind_index_buffer(&cmd_buffer->cmd_queue,
                                       buffer, offset, indexType);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
   } else {
      vk_cmd_enqueue_CmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_bind_vertex_buffers(&cmd_buffer->cmd_queue,
                                       firstBinding, bindingCount, pBuffers, pOffsets);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
   } else {
      vk_cmd_enqueue_CmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_draw(&cmd_buffer->cmd_queue,
                                       vertexCount, instanceCount, firstVertex, firstInstance);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
   } else {
      vk_cmd_enqueue_CmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_draw_indexed(&cmd_buffer->cmd_queue,
                                       indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
   } else {
      vk_cmd_enqueue_CmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
   }
}



/* vk_cmd_enqueue_CmdDrawMultiEXT() is hand-typed in vk_cmd_enqueue.c */

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
   } else {
      vk_cmd_enqueue_CmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
   }
}



/* vk_cmd_enqueue_CmdDrawMultiIndexedEXT() is hand-typed in vk_cmd_enqueue.c */

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
   } else {
      vk_cmd_enqueue_CmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_draw_indirect(&cmd_buffer->cmd_queue,
                                       buffer, offset, drawCount, stride);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
   } else {
      vk_cmd_enqueue_CmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_draw_indexed_indirect(&cmd_buffer->cmd_queue,
                                       buffer, offset, drawCount, stride);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
   } else {
      vk_cmd_enqueue_CmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_dispatch(&cmd_buffer->cmd_queue,
                                       groupCountX, groupCountY, groupCountZ);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
   } else {
      vk_cmd_enqueue_CmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_dispatch_indirect(&cmd_buffer->cmd_queue,
                                       buffer, offset);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDispatchIndirect(commandBuffer, buffer, offset);
   } else {
      vk_cmd_enqueue_CmdDispatchIndirect(commandBuffer, buffer, offset);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_subpass_shading_huawei(&cmd_buffer->cmd_queue);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSubpassShadingHUAWEI(commandBuffer);
   } else {
      vk_cmd_enqueue_CmdSubpassShadingHUAWEI(commandBuffer);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_draw_cluster_huawei(&cmd_buffer->cmd_queue,
                                       groupCountX, groupCountY, groupCountZ);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
   } else {
      vk_cmd_enqueue_CmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_draw_cluster_indirect_huawei(&cmd_buffer->cmd_queue,
                                       buffer, offset);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
   } else {
      vk_cmd_enqueue_CmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint           pipelineBindPoint, VkPipeline                    pipeline)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_update_pipeline_indirect_buffer_nv(&cmd_buffer->cmd_queue,
                                       pipelineBindPoint, pipeline);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint           pipelineBindPoint, VkPipeline                    pipeline)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
   } else {
      vk_cmd_enqueue_CmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_buffer(&cmd_buffer->cmd_queue,
                                       srcBuffer, dstBuffer, regionCount, pRegions);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
   } else {
      vk_cmd_enqueue_CmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_image(&cmd_buffer->cmd_queue,
                                       srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
   } else {
      vk_cmd_enqueue_CmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_blit_image(&cmd_buffer->cmd_queue,
                                       srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
   } else {
      vk_cmd_enqueue_CmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_buffer_to_image(&cmd_buffer->cmd_queue,
                                       srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
   } else {
      vk_cmd_enqueue_CmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_image_to_buffer(&cmd_buffer->cmd_queue,
                                       srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
   } else {
      vk_cmd_enqueue_CmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_memory_indirect_nv(&cmd_buffer->cmd_queue,
                                       copyBufferAddress, copyCount, stride);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
   } else {
      vk_cmd_enqueue_CmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyMemoryIndirectKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryIndirectInfoKHR* pCopyMemoryIndirectInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_memory_indirect_khr(&cmd_buffer->cmd_queue,
                                       pCopyMemoryIndirectInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyMemoryIndirectKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryIndirectInfoKHR* pCopyMemoryIndirectInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyMemoryIndirectKHR(commandBuffer, pCopyMemoryIndirectInfo);
   } else {
      vk_cmd_enqueue_CmdCopyMemoryIndirectKHR(commandBuffer, pCopyMemoryIndirectInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride, VkImage dstImage, VkImageLayout dstImageLayout, const VkImageSubresourceLayers* pImageSubresources)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_memory_to_image_indirect_nv(&cmd_buffer->cmd_queue,
                                       copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride, VkImage dstImage, VkImageLayout dstImageLayout, const VkImageSubresourceLayers* pImageSubresources)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
   } else {
      vk_cmd_enqueue_CmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyMemoryToImageIndirectKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToImageIndirectInfoKHR* pCopyMemoryToImageIndirectInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_memory_to_image_indirect_khr(&cmd_buffer->cmd_queue,
                                       pCopyMemoryToImageIndirectInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyMemoryToImageIndirectKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToImageIndirectInfoKHR* pCopyMemoryToImageIndirectInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyMemoryToImageIndirectKHR(commandBuffer, pCopyMemoryToImageIndirectInfo);
   } else {
      vk_cmd_enqueue_CmdCopyMemoryToImageIndirectKHR(commandBuffer, pCopyMemoryToImageIndirectInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_update_buffer(&cmd_buffer->cmd_queue,
                                       dstBuffer, dstOffset, dataSize, pData);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
   } else {
      vk_cmd_enqueue_CmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_fill_buffer(&cmd_buffer->cmd_queue,
                                       dstBuffer, dstOffset, size, data);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
   } else {
      vk_cmd_enqueue_CmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_clear_color_image(&cmd_buffer->cmd_queue,
                                       image, imageLayout, pColor, rangeCount, pRanges);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
   } else {
      vk_cmd_enqueue_CmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_clear_depth_stencil_image(&cmd_buffer->cmd_queue,
                                       image, imageLayout, pDepthStencil, rangeCount, pRanges);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
   } else {
      vk_cmd_enqueue_CmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_clear_attachments(&cmd_buffer->cmd_queue,
                                       attachmentCount, pAttachments, rectCount, pRects);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
   } else {
      vk_cmd_enqueue_CmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_resolve_image(&cmd_buffer->cmd_queue,
                                       srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
   } else {
      vk_cmd_enqueue_CmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_event(&cmd_buffer->cmd_queue,
                                       event, stageMask);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetEvent(commandBuffer, event, stageMask);
   } else {
      vk_cmd_enqueue_CmdSetEvent(commandBuffer, event, stageMask);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_reset_event(&cmd_buffer->cmd_queue,
                                       event, stageMask);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdResetEvent(commandBuffer, event, stageMask);
   } else {
      vk_cmd_enqueue_CmdResetEvent(commandBuffer, event, stageMask);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_wait_events(&cmd_buffer->cmd_queue,
                                       eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
   } else {
      vk_cmd_enqueue_CmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_pipeline_barrier(&cmd_buffer->cmd_queue,
                                       srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
   } else {
      vk_cmd_enqueue_CmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_begin_query(&cmd_buffer->cmd_queue,
                                       queryPool, query, flags);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBeginQuery(commandBuffer, queryPool, query, flags);
   } else {
      vk_cmd_enqueue_CmdBeginQuery(commandBuffer, queryPool, query, flags);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_end_query(&cmd_buffer->cmd_queue,
                                       queryPool, query);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdEndQuery(commandBuffer, queryPool, query);
   } else {
      vk_cmd_enqueue_CmdEndQuery(commandBuffer, queryPool, query);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_begin_conditional_rendering_ext(&cmd_buffer->cmd_queue,
                                       pConditionalRenderingBegin);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
   } else {
      vk_cmd_enqueue_CmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_end_conditional_rendering_ext(&cmd_buffer->cmd_queue);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdEndConditionalRenderingEXT(commandBuffer);
   } else {
      vk_cmd_enqueue_CmdEndConditionalRenderingEXT(commandBuffer);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_reset_query_pool(&cmd_buffer->cmd_queue,
                                       queryPool, firstQuery, queryCount);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
   } else {
      vk_cmd_enqueue_CmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_write_timestamp(&cmd_buffer->cmd_queue,
                                       pipelineStage, queryPool, query);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
   } else {
      vk_cmd_enqueue_CmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_query_pool_results(&cmd_buffer->cmd_queue,
                                       queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
   } else {
      vk_cmd_enqueue_CmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_push_constants(&cmd_buffer->cmd_queue,
                                       layout, stageFlags, offset, size, pValues);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
   } else {
      vk_cmd_enqueue_CmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_begin_render_pass(&cmd_buffer->cmd_queue,
                                       pRenderPassBegin, contents);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
   } else {
      vk_cmd_enqueue_CmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_next_subpass(&cmd_buffer->cmd_queue,
                                       contents);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdNextSubpass(commandBuffer, contents);
   } else {
      vk_cmd_enqueue_CmdNextSubpass(commandBuffer, contents);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdEndRenderPass(VkCommandBuffer commandBuffer)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_end_render_pass(&cmd_buffer->cmd_queue);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdEndRenderPass(VkCommandBuffer commandBuffer)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdEndRenderPass(commandBuffer);
   } else {
      vk_cmd_enqueue_CmdEndRenderPass(commandBuffer);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_execute_commands(&cmd_buffer->cmd_queue,
                                       commandBufferCount, pCommandBuffers);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
   } else {
      vk_cmd_enqueue_CmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_debug_marker_begin_ext(&cmd_buffer->cmd_queue,
                                       pMarkerInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
   } else {
      vk_cmd_enqueue_CmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_debug_marker_end_ext(&cmd_buffer->cmd_queue);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDebugMarkerEndEXT(commandBuffer);
   } else {
      vk_cmd_enqueue_CmdDebugMarkerEndEXT(commandBuffer);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_debug_marker_insert_ext(&cmd_buffer->cmd_queue,
                                       pMarkerInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
   } else {
      vk_cmd_enqueue_CmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_execute_generated_commands_nv(&cmd_buffer->cmd_queue,
                                       isPreprocessed, pGeneratedCommandsInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
   } else {
      vk_cmd_enqueue_CmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_preprocess_generated_commands_nv(&cmd_buffer->cmd_queue,
                                       pGeneratedCommandsInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
   } else {
      vk_cmd_enqueue_CmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_bind_pipeline_shader_group_nv(&cmd_buffer->cmd_queue,
                                       pipelineBindPoint, pipeline, groupIndex);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
   } else {
      vk_cmd_enqueue_CmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_execute_generated_commands_ext(&cmd_buffer->cmd_queue,
                                       isPreprocessed, pGeneratedCommandsInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdExecuteGeneratedCommandsEXT(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
   } else {
      vk_cmd_enqueue_CmdExecuteGeneratedCommandsEXT(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo, VkCommandBuffer stateCommandBuffer)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_preprocess_generated_commands_ext(&cmd_buffer->cmd_queue,
                                       pGeneratedCommandsInfo, stateCommandBuffer);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo, VkCommandBuffer stateCommandBuffer)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdPreprocessGeneratedCommandsEXT(commandBuffer, pGeneratedCommandsInfo, stateCommandBuffer);
   } else {
      vk_cmd_enqueue_CmdPreprocessGeneratedCommandsEXT(commandBuffer, pGeneratedCommandsInfo, stateCommandBuffer);
   }
}



/* vk_cmd_enqueue_CmdPushDescriptorSet() is hand-typed in vk_cmd_enqueue.c */

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdPushDescriptorSet(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdPushDescriptorSet(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
   } else {
      vk_cmd_enqueue_CmdPushDescriptorSet(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_device_mask(&cmd_buffer->cmd_queue,
                                       deviceMask);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetDeviceMask(commandBuffer, deviceMask);
   } else {
      vk_cmd_enqueue_CmdSetDeviceMask(commandBuffer, deviceMask);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_dispatch_base(&cmd_buffer->cmd_queue,
                                       baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
   } else {
      vk_cmd_enqueue_CmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
   }
}



/* vk_cmd_enqueue_CmdPushDescriptorSetWithTemplate() is hand-typed in vk_cmd_enqueue.c */

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdPushDescriptorSetWithTemplate(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdPushDescriptorSetWithTemplate(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
   } else {
      vk_cmd_enqueue_CmdPushDescriptorSetWithTemplate(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_viewport_wscaling_nv(&cmd_buffer->cmd_queue,
                                       firstViewport, viewportCount, pViewportWScalings);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
   } else {
      vk_cmd_enqueue_CmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_discard_rectangle_ext(&cmd_buffer->cmd_queue,
                                       firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
   } else {
      vk_cmd_enqueue_CmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_discard_rectangle_enable_ext(&cmd_buffer->cmd_queue,
                                       discardRectangleEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
   } else {
      vk_cmd_enqueue_CmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_discard_rectangle_mode_ext(&cmd_buffer->cmd_queue,
                                       discardRectangleMode);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
   } else {
      vk_cmd_enqueue_CmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_sample_locations_ext(&cmd_buffer->cmd_queue,
                                       pSampleLocationsInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
   } else {
      vk_cmd_enqueue_CmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_begin_debug_utils_label_ext(&cmd_buffer->cmd_queue,
                                       pLabelInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
   } else {
      vk_cmd_enqueue_CmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_end_debug_utils_label_ext(&cmd_buffer->cmd_queue);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdEndDebugUtilsLabelEXT(commandBuffer);
   } else {
      vk_cmd_enqueue_CmdEndDebugUtilsLabelEXT(commandBuffer);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_insert_debug_utils_label_ext(&cmd_buffer->cmd_queue,
                                       pLabelInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
   } else {
      vk_cmd_enqueue_CmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_write_buffer_marker_amd(&cmd_buffer->cmd_queue,
                                       pipelineStage, dstBuffer, dstOffset, marker);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
   } else {
      vk_cmd_enqueue_CmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo*      pRenderPassBegin, const VkSubpassBeginInfo*      pSubpassBeginInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_begin_render_pass2(&cmd_buffer->cmd_queue,
                                       pRenderPassBegin, pSubpassBeginInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo*      pRenderPassBegin, const VkSubpassBeginInfo*      pSubpassBeginInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
   } else {
      vk_cmd_enqueue_CmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo*      pSubpassBeginInfo, const VkSubpassEndInfo*        pSubpassEndInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_next_subpass2(&cmd_buffer->cmd_queue,
                                       pSubpassBeginInfo, pSubpassEndInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo*      pSubpassBeginInfo, const VkSubpassEndInfo*        pSubpassEndInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
   } else {
      vk_cmd_enqueue_CmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo*        pSubpassEndInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_end_render_pass2(&cmd_buffer->cmd_queue,
                                       pSubpassEndInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo*        pSubpassEndInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
   } else {
      vk_cmd_enqueue_CmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_draw_indirect_count(&cmd_buffer->cmd_queue,
                                       buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
   } else {
      vk_cmd_enqueue_CmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_draw_indexed_indirect_count(&cmd_buffer->cmd_queue,
                                       buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
   } else {
      vk_cmd_enqueue_CmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_checkpoint_nv(&cmd_buffer->cmd_queue,
                                       pCheckpointMarker);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
   } else {
      vk_cmd_enqueue_CmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_bind_transform_feedback_buffers_ext(&cmd_buffer->cmd_queue,
                                       firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
   } else {
      vk_cmd_enqueue_CmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_begin_transform_feedback_ext(&cmd_buffer->cmd_queue,
                                       firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
   } else {
      vk_cmd_enqueue_CmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_end_transform_feedback_ext(&cmd_buffer->cmd_queue,
                                       firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
   } else {
      vk_cmd_enqueue_CmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_begin_query_indexed_ext(&cmd_buffer->cmd_queue,
                                       queryPool, query, flags, index);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
   } else {
      vk_cmd_enqueue_CmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_end_query_indexed_ext(&cmd_buffer->cmd_queue,
                                       queryPool, query, index);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
   } else {
      vk_cmd_enqueue_CmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_draw_indirect_byte_count_ext(&cmd_buffer->cmd_queue,
                                       instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
   } else {
      vk_cmd_enqueue_CmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_exclusive_scissor_nv(&cmd_buffer->cmd_queue,
                                       firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
   } else {
      vk_cmd_enqueue_CmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_exclusive_scissor_enable_nv(&cmd_buffer->cmd_queue,
                                       firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
   } else {
      vk_cmd_enqueue_CmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_bind_shading_rate_image_nv(&cmd_buffer->cmd_queue,
                                       imageView, imageLayout);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
   } else {
      vk_cmd_enqueue_CmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_viewport_shading_rate_palette_nv(&cmd_buffer->cmd_queue,
                                       firstViewport, viewportCount, pShadingRatePalettes);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
   } else {
      vk_cmd_enqueue_CmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_coarse_sample_order_nv(&cmd_buffer->cmd_queue,
                                       sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
   } else {
      vk_cmd_enqueue_CmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_draw_mesh_tasks_nv(&cmd_buffer->cmd_queue,
                                       taskCount, firstTask);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
   } else {
      vk_cmd_enqueue_CmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_draw_mesh_tasks_indirect_nv(&cmd_buffer->cmd_queue,
                                       buffer, offset, drawCount, stride);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
   } else {
      vk_cmd_enqueue_CmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_draw_mesh_tasks_indirect_count_nv(&cmd_buffer->cmd_queue,
                                       buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
   } else {
      vk_cmd_enqueue_CmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_draw_mesh_tasks_ext(&cmd_buffer->cmd_queue,
                                       groupCountX, groupCountY, groupCountZ);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
   } else {
      vk_cmd_enqueue_CmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_draw_mesh_tasks_indirect_ext(&cmd_buffer->cmd_queue,
                                       buffer, offset, drawCount, stride);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
   } else {
      vk_cmd_enqueue_CmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_draw_mesh_tasks_indirect_count_ext(&cmd_buffer->cmd_queue,
                                       buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
   } else {
      vk_cmd_enqueue_CmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_bind_invocation_mask_huawei(&cmd_buffer->cmd_queue,
                                       imageView, imageLayout);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
   } else {
      vk_cmd_enqueue_CmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_acceleration_structure_nv(&cmd_buffer->cmd_queue,
                                       dst, src, mode);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
   } else {
      vk_cmd_enqueue_CmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_acceleration_structure_khr(&cmd_buffer->cmd_queue,
                                       pInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
   } else {
      vk_cmd_enqueue_CmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_acceleration_structure_to_memory_khr(&cmd_buffer->cmd_queue,
                                       pInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
   } else {
      vk_cmd_enqueue_CmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_memory_to_acceleration_structure_khr(&cmd_buffer->cmd_queue,
                                       pInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
   } else {
      vk_cmd_enqueue_CmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_write_acceleration_structures_properties_khr(&cmd_buffer->cmd_queue,
                                       accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
   } else {
      vk_cmd_enqueue_CmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_write_acceleration_structures_properties_nv(&cmd_buffer->cmd_queue,
                                       accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
   } else {
      vk_cmd_enqueue_CmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_build_acceleration_structure_nv(&cmd_buffer->cmd_queue,
                                       pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
   } else {
      vk_cmd_enqueue_CmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdTraceRaysKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_trace_rays_khr(&cmd_buffer->cmd_queue,
                                       pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdTraceRaysKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
   } else {
      vk_cmd_enqueue_CmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_trace_rays_nv(&cmd_buffer->cmd_queue,
                                       raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
   } else {
      vk_cmd_enqueue_CmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_trace_rays_indirect_khr(&cmd_buffer->cmd_queue,
                                       pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
   } else {
      vk_cmd_enqueue_CmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_trace_rays_indirect2_khr(&cmd_buffer->cmd_queue,
                                       indirectDeviceAddress);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
   } else {
      vk_cmd_enqueue_CmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBuildClusterAccelerationStructureIndirectNV(VkCommandBuffer                     commandBuffer, const VkClusterAccelerationStructureCommandsInfoNV*  pCommandInfos)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_build_cluster_acceleration_structure_indirect_nv(&cmd_buffer->cmd_queue,
                                       pCommandInfos);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBuildClusterAccelerationStructureIndirectNV(VkCommandBuffer                     commandBuffer, const VkClusterAccelerationStructureCommandsInfoNV*  pCommandInfos)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBuildClusterAccelerationStructureIndirectNV(commandBuffer, pCommandInfos);
   } else {
      vk_cmd_enqueue_CmdBuildClusterAccelerationStructureIndirectNV(commandBuffer, pCommandInfos);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_ray_tracing_pipeline_stack_size_khr(&cmd_buffer->cmd_queue,
                                       pipelineStackSize);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
   } else {
      vk_cmd_enqueue_CmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
   }
}
/* TODO: Generate vk_cmd_enqueue_CmdSetPerformanceMarkerINTEL() */
/* TODO: Generate vk_cmd_enqueue_CmdSetPerformanceStreamMarkerINTEL() */
/* TODO: Generate vk_cmd_enqueue_CmdSetPerformanceOverrideINTEL() */



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetLineStipple(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_line_stipple(&cmd_buffer->cmd_queue,
                                       lineStippleFactor, lineStipplePattern);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetLineStipple(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetLineStipple(commandBuffer, lineStippleFactor, lineStipplePattern);
   } else {
      vk_cmd_enqueue_CmdSetLineStipple(commandBuffer, lineStippleFactor, lineStipplePattern);
   }
}



/* vk_cmd_enqueue_CmdBuildAccelerationStructuresKHR() is hand-typed in vk_cmd_enqueue.c */

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBuildAccelerationStructuresKHR(VkCommandBuffer                                    commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
   } else {
      vk_cmd_enqueue_CmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer                  commandBuffer, uint32_t                                           infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress*             pIndirectDeviceAddresses, const uint32_t*                    pIndirectStrides, const uint32_t* const*             ppMaxPrimitiveCounts)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_build_acceleration_structures_indirect_khr(&cmd_buffer->cmd_queue,
                                       infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer                  commandBuffer, uint32_t                                           infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress*             pIndirectDeviceAddresses, const uint32_t*                    pIndirectStrides, const uint32_t* const*             ppMaxPrimitiveCounts)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
   } else {
      vk_cmd_enqueue_CmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_cull_mode(&cmd_buffer->cmd_queue,
                                       cullMode);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetCullMode(commandBuffer, cullMode);
   } else {
      vk_cmd_enqueue_CmdSetCullMode(commandBuffer, cullMode);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_front_face(&cmd_buffer->cmd_queue,
                                       frontFace);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetFrontFace(commandBuffer, frontFace);
   } else {
      vk_cmd_enqueue_CmdSetFrontFace(commandBuffer, frontFace);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_primitive_topology(&cmd_buffer->cmd_queue,
                                       primitiveTopology);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
   } else {
      vk_cmd_enqueue_CmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_viewport_with_count(&cmd_buffer->cmd_queue,
                                       viewportCount, pViewports);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
   } else {
      vk_cmd_enqueue_CmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_scissor_with_count(&cmd_buffer->cmd_queue,
                                       scissorCount, pScissors);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
   } else {
      vk_cmd_enqueue_CmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBindIndexBuffer2(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_bind_index_buffer2(&cmd_buffer->cmd_queue,
                                       buffer, offset, size, indexType);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBindIndexBuffer2(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBindIndexBuffer2(commandBuffer, buffer, offset, size, indexType);
   } else {
      vk_cmd_enqueue_CmdBindIndexBuffer2(commandBuffer, buffer, offset, size, indexType);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_bind_vertex_buffers2(&cmd_buffer->cmd_queue,
                                       firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
   } else {
      vk_cmd_enqueue_CmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_depth_test_enable(&cmd_buffer->cmd_queue,
                                       depthTestEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetDepthTestEnable(commandBuffer, depthTestEnable);
   } else {
      vk_cmd_enqueue_CmdSetDepthTestEnable(commandBuffer, depthTestEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_depth_write_enable(&cmd_buffer->cmd_queue,
                                       depthWriteEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
   } else {
      vk_cmd_enqueue_CmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_depth_compare_op(&cmd_buffer->cmd_queue,
                                       depthCompareOp);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetDepthCompareOp(commandBuffer, depthCompareOp);
   } else {
      vk_cmd_enqueue_CmdSetDepthCompareOp(commandBuffer, depthCompareOp);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_depth_bounds_test_enable(&cmd_buffer->cmd_queue,
                                       depthBoundsTestEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
   } else {
      vk_cmd_enqueue_CmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_stencil_test_enable(&cmd_buffer->cmd_queue,
                                       stencilTestEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
   } else {
      vk_cmd_enqueue_CmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_stencil_op(&cmd_buffer->cmd_queue,
                                       faceMask, failOp, passOp, depthFailOp, compareOp);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
   } else {
      vk_cmd_enqueue_CmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_patch_control_points_ext(&cmd_buffer->cmd_queue,
                                       patchControlPoints);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
   } else {
      vk_cmd_enqueue_CmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_rasterizer_discard_enable(&cmd_buffer->cmd_queue,
                                       rasterizerDiscardEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
   } else {
      vk_cmd_enqueue_CmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_depth_bias_enable(&cmd_buffer->cmd_queue,
                                       depthBiasEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
   } else {
      vk_cmd_enqueue_CmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_logic_op_ext(&cmd_buffer->cmd_queue,
                                       logicOp);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetLogicOpEXT(commandBuffer, logicOp);
   } else {
      vk_cmd_enqueue_CmdSetLogicOpEXT(commandBuffer, logicOp);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_primitive_restart_enable(&cmd_buffer->cmd_queue,
                                       primitiveRestartEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
   } else {
      vk_cmd_enqueue_CmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_tessellation_domain_origin_ext(&cmd_buffer->cmd_queue,
                                       domainOrigin);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
   } else {
      vk_cmd_enqueue_CmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_depth_clamp_enable_ext(&cmd_buffer->cmd_queue,
                                       depthClampEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
   } else {
      vk_cmd_enqueue_CmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_polygon_mode_ext(&cmd_buffer->cmd_queue,
                                       polygonMode);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetPolygonModeEXT(commandBuffer, polygonMode);
   } else {
      vk_cmd_enqueue_CmdSetPolygonModeEXT(commandBuffer, polygonMode);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits  rasterizationSamples)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_rasterization_samples_ext(&cmd_buffer->cmd_queue,
                                       rasterizationSamples);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits  rasterizationSamples)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
   } else {
      vk_cmd_enqueue_CmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits  samples, const VkSampleMask*    pSampleMask)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_sample_mask_ext(&cmd_buffer->cmd_queue,
                                       samples, pSampleMask);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits  samples, const VkSampleMask*    pSampleMask)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
   } else {
      vk_cmd_enqueue_CmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_alpha_to_coverage_enable_ext(&cmd_buffer->cmd_queue,
                                       alphaToCoverageEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
   } else {
      vk_cmd_enqueue_CmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_alpha_to_one_enable_ext(&cmd_buffer->cmd_queue,
                                       alphaToOneEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
   } else {
      vk_cmd_enqueue_CmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_logic_op_enable_ext(&cmd_buffer->cmd_queue,
                                       logicOpEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
   } else {
      vk_cmd_enqueue_CmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkBool32* pColorBlendEnables)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_color_blend_enable_ext(&cmd_buffer->cmd_queue,
                                       firstAttachment, attachmentCount, pColorBlendEnables);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkBool32* pColorBlendEnables)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
   } else {
      vk_cmd_enqueue_CmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendEquationEXT* pColorBlendEquations)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_color_blend_equation_ext(&cmd_buffer->cmd_queue,
                                       firstAttachment, attachmentCount, pColorBlendEquations);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendEquationEXT* pColorBlendEquations)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
   } else {
      vk_cmd_enqueue_CmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_color_write_mask_ext(&cmd_buffer->cmd_queue,
                                       firstAttachment, attachmentCount, pColorWriteMasks);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
   } else {
      vk_cmd_enqueue_CmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_rasterization_stream_ext(&cmd_buffer->cmd_queue,
                                       rasterizationStream);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
   } else {
      vk_cmd_enqueue_CmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetConservativeRasterizationModeEXT(VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_conservative_rasterization_mode_ext(&cmd_buffer->cmd_queue,
                                       conservativeRasterizationMode);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetConservativeRasterizationModeEXT(VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
   } else {
      vk_cmd_enqueue_CmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_extra_primitive_overestimation_size_ext(&cmd_buffer->cmd_queue,
                                       extraPrimitiveOverestimationSize);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
   } else {
      vk_cmd_enqueue_CmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_depth_clip_enable_ext(&cmd_buffer->cmd_queue,
                                       depthClipEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
   } else {
      vk_cmd_enqueue_CmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_sample_locations_enable_ext(&cmd_buffer->cmd_queue,
                                       sampleLocationsEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
   } else {
      vk_cmd_enqueue_CmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendAdvancedEXT* pColorBlendAdvanced)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_color_blend_advanced_ext(&cmd_buffer->cmd_queue,
                                       firstAttachment, attachmentCount, pColorBlendAdvanced);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendAdvancedEXT* pColorBlendAdvanced)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
   } else {
      vk_cmd_enqueue_CmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_provoking_vertex_mode_ext(&cmd_buffer->cmd_queue,
                                       provokingVertexMode);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
   } else {
      vk_cmd_enqueue_CmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_line_rasterization_mode_ext(&cmd_buffer->cmd_queue,
                                       lineRasterizationMode);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
   } else {
      vk_cmd_enqueue_CmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_line_stipple_enable_ext(&cmd_buffer->cmd_queue,
                                       stippledLineEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
   } else {
      vk_cmd_enqueue_CmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_depth_clip_negative_one_to_one_ext(&cmd_buffer->cmd_queue,
                                       negativeOneToOne);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
   } else {
      vk_cmd_enqueue_CmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_viewport_wscaling_enable_nv(&cmd_buffer->cmd_queue,
                                       viewportWScalingEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
   } else {
      vk_cmd_enqueue_CmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_viewport_swizzle_nv(&cmd_buffer->cmd_queue,
                                       firstViewport, viewportCount, pViewportSwizzles);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
   } else {
      vk_cmd_enqueue_CmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_coverage_to_color_enable_nv(&cmd_buffer->cmd_queue,
                                       coverageToColorEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
   } else {
      vk_cmd_enqueue_CmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_coverage_to_color_location_nv(&cmd_buffer->cmd_queue,
                                       coverageToColorLocation);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
   } else {
      vk_cmd_enqueue_CmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_coverage_modulation_mode_nv(&cmd_buffer->cmd_queue,
                                       coverageModulationMode);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
   } else {
      vk_cmd_enqueue_CmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_coverage_modulation_table_enable_nv(&cmd_buffer->cmd_queue,
                                       coverageModulationTableEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
   } else {
      vk_cmd_enqueue_CmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_coverage_modulation_table_nv(&cmd_buffer->cmd_queue,
                                       coverageModulationTableCount, pCoverageModulationTable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
   } else {
      vk_cmd_enqueue_CmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_shading_rate_image_enable_nv(&cmd_buffer->cmd_queue,
                                       shadingRateImageEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
   } else {
      vk_cmd_enqueue_CmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_coverage_reduction_mode_nv(&cmd_buffer->cmd_queue,
                                       coverageReductionMode);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
   } else {
      vk_cmd_enqueue_CmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_representative_fragment_test_enable_nv(&cmd_buffer->cmd_queue,
                                       representativeFragmentTestEnable);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
   } else {
      vk_cmd_enqueue_CmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_buffer2(&cmd_buffer->cmd_queue,
                                       pCopyBufferInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
   } else {
      vk_cmd_enqueue_CmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_image2(&cmd_buffer->cmd_queue,
                                       pCopyImageInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyImage2(commandBuffer, pCopyImageInfo);
   } else {
      vk_cmd_enqueue_CmdCopyImage2(commandBuffer, pCopyImageInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_blit_image2(&cmd_buffer->cmd_queue,
                                       pBlitImageInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBlitImage2(commandBuffer, pBlitImageInfo);
   } else {
      vk_cmd_enqueue_CmdBlitImage2(commandBuffer, pBlitImageInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_buffer_to_image2(&cmd_buffer->cmd_queue,
                                       pCopyBufferToImageInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
   } else {
      vk_cmd_enqueue_CmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_image_to_buffer2(&cmd_buffer->cmd_queue,
                                       pCopyImageToBufferInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
   } else {
      vk_cmd_enqueue_CmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_resolve_image2(&cmd_buffer->cmd_queue,
                                       pResolveImageInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdResolveImage2(commandBuffer, pResolveImageInfo);
   } else {
      vk_cmd_enqueue_CmdResolveImage2(commandBuffer, pResolveImageInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetFragmentShadingRateKHR(VkCommandBuffer           commandBuffer, const VkExtent2D*                           pFragmentSize, const VkFragmentShadingRateCombinerOpKHR    combinerOps[2])
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_fragment_shading_rate_khr(&cmd_buffer->cmd_queue,
                                       pFragmentSize, combinerOps);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetFragmentShadingRateKHR(VkCommandBuffer           commandBuffer, const VkExtent2D*                           pFragmentSize, const VkFragmentShadingRateCombinerOpKHR    combinerOps[2])
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
   } else {
      vk_cmd_enqueue_CmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetFragmentShadingRateEnumNV(VkCommandBuffer           commandBuffer, VkFragmentShadingRateNV                     shadingRate, const VkFragmentShadingRateCombinerOpKHR    combinerOps[2])
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_fragment_shading_rate_enum_nv(&cmd_buffer->cmd_queue,
                                       shadingRate, combinerOps);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetFragmentShadingRateEnumNV(VkCommandBuffer           commandBuffer, VkFragmentShadingRateNV                     shadingRate, const VkFragmentShadingRateCombinerOpKHR    combinerOps[2])
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
   } else {
      vk_cmd_enqueue_CmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_vertex_input_ext(&cmd_buffer->cmd_queue,
                                       vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
   } else {
      vk_cmd_enqueue_CmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetColorWriteEnableEXT(VkCommandBuffer       commandBuffer, uint32_t                                attachmentCount, const VkBool32*   pColorWriteEnables)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_color_write_enable_ext(&cmd_buffer->cmd_queue,
                                       attachmentCount, pColorWriteEnables);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetColorWriteEnableEXT(VkCommandBuffer       commandBuffer, uint32_t                                attachmentCount, const VkBool32*   pColorWriteEnables)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
   } else {
      vk_cmd_enqueue_CmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetEvent2(VkCommandBuffer                   commandBuffer, VkEvent                                             event, const VkDependencyInfo*                             pDependencyInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_event2(&cmd_buffer->cmd_queue,
                                       event, pDependencyInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetEvent2(VkCommandBuffer                   commandBuffer, VkEvent                                             event, const VkDependencyInfo*                             pDependencyInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetEvent2(commandBuffer, event, pDependencyInfo);
   } else {
      vk_cmd_enqueue_CmdSetEvent2(commandBuffer, event, pDependencyInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdResetEvent2(VkCommandBuffer                   commandBuffer, VkEvent                                             event, VkPipelineStageFlags2               stageMask)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_reset_event2(&cmd_buffer->cmd_queue,
                                       event, stageMask);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdResetEvent2(VkCommandBuffer                   commandBuffer, VkEvent                                             event, VkPipelineStageFlags2               stageMask)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdResetEvent2(commandBuffer, event, stageMask);
   } else {
      vk_cmd_enqueue_CmdResetEvent2(commandBuffer, event, stageMask);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdWaitEvents2(VkCommandBuffer                   commandBuffer, uint32_t                                            eventCount, const VkEvent*                     pEvents, const VkDependencyInfo*            pDependencyInfos)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_wait_events2(&cmd_buffer->cmd_queue,
                                       eventCount, pEvents, pDependencyInfos);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdWaitEvents2(VkCommandBuffer                   commandBuffer, uint32_t                                            eventCount, const VkEvent*                     pEvents, const VkDependencyInfo*            pDependencyInfos)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
   } else {
      vk_cmd_enqueue_CmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdPipelineBarrier2(VkCommandBuffer                   commandBuffer, const VkDependencyInfo*                             pDependencyInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_pipeline_barrier2(&cmd_buffer->cmd_queue,
                                       pDependencyInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdPipelineBarrier2(VkCommandBuffer                   commandBuffer, const VkDependencyInfo*                             pDependencyInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdPipelineBarrier2(commandBuffer, pDependencyInfo);
   } else {
      vk_cmd_enqueue_CmdPipelineBarrier2(commandBuffer, pDependencyInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdWriteTimestamp2(VkCommandBuffer                   commandBuffer, VkPipelineStageFlags2               stage, VkQueryPool                                         queryPool, uint32_t                                            query)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_write_timestamp2(&cmd_buffer->cmd_queue,
                                       stage, queryPool, query);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdWriteTimestamp2(VkCommandBuffer                   commandBuffer, VkPipelineStageFlags2               stage, VkQueryPool                                         queryPool, uint32_t                                            query)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
   } else {
      vk_cmd_enqueue_CmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdWriteBufferMarker2AMD(VkCommandBuffer                   commandBuffer, VkPipelineStageFlags2               stage, VkBuffer                                            dstBuffer, VkDeviceSize                                        dstOffset, uint32_t                                            marker)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_write_buffer_marker2_amd(&cmd_buffer->cmd_queue,
                                       stage, dstBuffer, dstOffset, marker);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdWriteBufferMarker2AMD(VkCommandBuffer                   commandBuffer, VkPipelineStageFlags2               stage, VkBuffer                                            dstBuffer, VkDeviceSize                                        dstOffset, uint32_t                                            marker)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
   } else {
      vk_cmd_enqueue_CmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_decode_video_khr(&cmd_buffer->cmd_queue,
                                       pDecodeInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
   } else {
      vk_cmd_enqueue_CmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_begin_video_coding_khr(&cmd_buffer->cmd_queue,
                                       pBeginInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
   } else {
      vk_cmd_enqueue_CmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdControlVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_control_video_coding_khr(&cmd_buffer->cmd_queue,
                                       pCodingControlInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdControlVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
   } else {
      vk_cmd_enqueue_CmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_end_video_coding_khr(&cmd_buffer->cmd_queue,
                                       pEndCodingInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
   } else {
      vk_cmd_enqueue_CmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_encode_video_khr(&cmd_buffer->cmd_queue,
                                       pEncodeInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
   } else {
      vk_cmd_enqueue_CmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount, const VkDecompressMemoryRegionNV* pDecompressMemoryRegions)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_decompress_memory_nv(&cmd_buffer->cmd_queue,
                                       decompressRegionCount, pDecompressMemoryRegions);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount, const VkDecompressMemoryRegionNV* pDecompressMemoryRegions)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
   } else {
      vk_cmd_enqueue_CmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress, VkDeviceAddress indirectCommandsCountAddress, uint32_t stride)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_decompress_memory_indirect_count_nv(&cmd_buffer->cmd_queue,
                                       indirectCommandsAddress, indirectCommandsCountAddress, stride);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress, VkDeviceAddress indirectCommandsCountAddress, uint32_t stride)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
   } else {
      vk_cmd_enqueue_CmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBuildPartitionedAccelerationStructuresNV(VkCommandBuffer                     commandBuffer, const VkBuildPartitionedAccelerationStructureInfoNV*  pBuildInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_build_partitioned_acceleration_structures_nv(&cmd_buffer->cmd_queue,
                                       pBuildInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBuildPartitionedAccelerationStructuresNV(VkCommandBuffer                     commandBuffer, const VkBuildPartitionedAccelerationStructureInfoNV*  pBuildInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBuildPartitionedAccelerationStructuresNV(commandBuffer, pBuildInfo);
   } else {
      vk_cmd_enqueue_CmdBuildPartitionedAccelerationStructuresNV(commandBuffer, pBuildInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_cu_launch_kernel_nvx(&cmd_buffer->cmd_queue,
                                       pLaunchInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
   } else {
      vk_cmd_enqueue_CmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount, const VkDescriptorBufferBindingInfoEXT* pBindingInfos)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_bind_descriptor_buffers_ext(&cmd_buffer->cmd_queue,
                                       bufferCount, pBindingInfos);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount, const VkDescriptorBufferBindingInfoEXT* pBindingInfos)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
   } else {
      vk_cmd_enqueue_CmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount, const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_descriptor_buffer_offsets_ext(&cmd_buffer->cmd_queue,
                                       pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount, const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
   } else {
      vk_cmd_enqueue_CmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_bind_descriptor_buffer_embedded_samplers_ext(&cmd_buffer->cmd_queue,
                                       pipelineBindPoint, layout, set);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);
   } else {
      vk_cmd_enqueue_CmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBeginRendering(VkCommandBuffer                   commandBuffer, const VkRenderingInfo*                              pRenderingInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_begin_rendering(&cmd_buffer->cmd_queue,
                                       pRenderingInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBeginRendering(VkCommandBuffer                   commandBuffer, const VkRenderingInfo*                              pRenderingInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBeginRendering(commandBuffer, pRenderingInfo);
   } else {
      vk_cmd_enqueue_CmdBeginRendering(commandBuffer, pRenderingInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdEndRendering(VkCommandBuffer                   commandBuffer)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_end_rendering(&cmd_buffer->cmd_queue);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdEndRendering(VkCommandBuffer                   commandBuffer)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdEndRendering(commandBuffer);
   } else {
      vk_cmd_enqueue_CmdEndRendering(commandBuffer);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdEndRendering2EXT(VkCommandBuffer                   commandBuffer, const VkRenderingEndInfoEXT*        pRenderingEndInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_end_rendering2_ext(&cmd_buffer->cmd_queue,
                                       pRenderingEndInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdEndRendering2EXT(VkCommandBuffer                   commandBuffer, const VkRenderingEndInfoEXT*        pRenderingEndInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdEndRendering2EXT(commandBuffer, pRenderingEndInfo);
   } else {
      vk_cmd_enqueue_CmdEndRendering2EXT(commandBuffer, pRenderingEndInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBuildMicromapsEXT(VkCommandBuffer                                    commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_build_micromaps_ext(&cmd_buffer->cmd_queue,
                                       infoCount, pInfos);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBuildMicromapsEXT(VkCommandBuffer                                    commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
   } else {
      vk_cmd_enqueue_CmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_micromap_ext(&cmd_buffer->cmd_queue,
                                       pInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyMicromapEXT(commandBuffer, pInfo);
   } else {
      vk_cmd_enqueue_CmdCopyMicromapEXT(commandBuffer, pInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_micromap_to_memory_ext(&cmd_buffer->cmd_queue,
                                       pInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
   } else {
      vk_cmd_enqueue_CmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_memory_to_micromap_ext(&cmd_buffer->cmd_queue,
                                       pInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
   } else {
      vk_cmd_enqueue_CmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_write_micromaps_properties_ext(&cmd_buffer->cmd_queue,
                                       micromapCount, pMicromaps, queryType, queryPool, firstQuery);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
   } else {
      vk_cmd_enqueue_CmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBindTileMemoryQCOM(VkCommandBuffer commandBuffer, const VkTileMemoryBindInfoQCOM* pTileMemoryBindInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_bind_tile_memory_qcom(&cmd_buffer->cmd_queue,
                                       pTileMemoryBindInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBindTileMemoryQCOM(VkCommandBuffer commandBuffer, const VkTileMemoryBindInfoQCOM* pTileMemoryBindInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBindTileMemoryQCOM(commandBuffer, pTileMemoryBindInfo);
   } else {
      vk_cmd_enqueue_CmdBindTileMemoryQCOM(commandBuffer, pTileMemoryBindInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV* pExecuteInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_optical_flow_execute_nv(&cmd_buffer->cmd_queue,
                                       session, pExecuteInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV* pExecuteInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
   } else {
      vk_cmd_enqueue_CmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT*         pDepthBiasInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_depth_bias2_ext(&cmd_buffer->cmd_queue,
                                       pDepthBiasInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT*         pDepthBiasInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
   } else {
      vk_cmd_enqueue_CmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_bind_shaders_ext(&cmd_buffer->cmd_queue,
                                       stageCount, pStages, pShaders);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
   } else {
      vk_cmd_enqueue_CmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBindDescriptorSets2(VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfo*   pBindDescriptorSetsInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_bind_descriptor_sets2(&cmd_buffer->cmd_queue,
                                       pBindDescriptorSetsInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBindDescriptorSets2(VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfo*   pBindDescriptorSetsInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBindDescriptorSets2(commandBuffer, pBindDescriptorSetsInfo);
   } else {
      vk_cmd_enqueue_CmdBindDescriptorSets2(commandBuffer, pBindDescriptorSetsInfo);
   }
}



/* vk_cmd_enqueue_CmdPushConstants2() is hand-typed in vk_cmd_enqueue.c */

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdPushConstants2(VkCommandBuffer commandBuffer, const VkPushConstantsInfo*        pPushConstantsInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdPushConstants2(commandBuffer, pPushConstantsInfo);
   } else {
      vk_cmd_enqueue_CmdPushConstants2(commandBuffer, pPushConstantsInfo);
   }
}



/* vk_cmd_enqueue_CmdPushDescriptorSet2() is hand-typed in vk_cmd_enqueue.c */

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdPushDescriptorSet2(VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfo*    pPushDescriptorSetInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdPushDescriptorSet2(commandBuffer, pPushDescriptorSetInfo);
   } else {
      vk_cmd_enqueue_CmdPushDescriptorSet2(commandBuffer, pPushDescriptorSetInfo);
   }
}



/* vk_cmd_enqueue_CmdPushDescriptorSetWithTemplate2() is hand-typed in vk_cmd_enqueue.c */

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdPushDescriptorSetWithTemplate2(VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfo* pPushDescriptorSetWithTemplateInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdPushDescriptorSetWithTemplate2(commandBuffer, pPushDescriptorSetWithTemplateInfo);
   } else {
      vk_cmd_enqueue_CmdPushDescriptorSetWithTemplate2(commandBuffer, pPushDescriptorSetWithTemplateInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetDescriptorBufferOffsets2EXT(VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_descriptor_buffer_offsets2_ext(&cmd_buffer->cmd_queue,
                                       pSetDescriptorBufferOffsetsInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetDescriptorBufferOffsets2EXT(VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);
   } else {
      vk_cmd_enqueue_CmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBindDescriptorBufferEmbeddedSamplers2EXT(VkCommandBuffer commandBuffer, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_bind_descriptor_buffer_embedded_samplers2_ext(&cmd_buffer->cmd_queue,
                                       pBindDescriptorBufferEmbeddedSamplersInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBindDescriptorBufferEmbeddedSamplers2EXT(VkCommandBuffer commandBuffer, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBindDescriptorBufferEmbeddedSamplers2EXT(commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);
   } else {
      vk_cmd_enqueue_CmdBindDescriptorBufferEmbeddedSamplers2EXT(commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetRenderingAttachmentLocations(VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfo* pLocationInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_rendering_attachment_locations(&cmd_buffer->cmd_queue,
                                       pLocationInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetRenderingAttachmentLocations(VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfo* pLocationInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetRenderingAttachmentLocations(commandBuffer, pLocationInfo);
   } else {
      vk_cmd_enqueue_CmdSetRenderingAttachmentLocations(commandBuffer, pLocationInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetRenderingInputAttachmentIndices(VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_rendering_input_attachment_indices(&cmd_buffer->cmd_queue,
                                       pInputAttachmentIndexInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetRenderingInputAttachmentIndices(VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetRenderingInputAttachmentIndices(commandBuffer, pInputAttachmentIndexInfo);
   } else {
      vk_cmd_enqueue_CmdSetRenderingInputAttachmentIndices(commandBuffer, pInputAttachmentIndexInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode, const VkDepthClampRangeEXT* pDepthClampRange)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_set_depth_clamp_range_ext(&cmd_buffer->cmd_queue,
                                       depthClampMode, pDepthClampRange);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode, const VkDepthClampRangeEXT* pDepthClampRange)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdSetDepthClampRangeEXT(commandBuffer, depthClampMode, pDepthClampRange);
   } else {
      vk_cmd_enqueue_CmdSetDepthClampRangeEXT(commandBuffer, depthClampMode, pDepthClampRange);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdConvertCooperativeVectorMatrixNV(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkConvertCooperativeVectorMatrixInfoNV* pInfos)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_convert_cooperative_vector_matrix_nv(&cmd_buffer->cmd_queue,
                                       infoCount, pInfos);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdConvertCooperativeVectorMatrixNV(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkConvertCooperativeVectorMatrixInfoNV* pInfos)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdConvertCooperativeVectorMatrixNV(commandBuffer, infoCount, pInfos);
   } else {
      vk_cmd_enqueue_CmdConvertCooperativeVectorMatrixNV(commandBuffer, infoCount, pInfos);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDispatchTileQCOM(VkCommandBuffer commandBuffer, const VkDispatchTileInfoQCOM* pDispatchTileInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_dispatch_tile_qcom(&cmd_buffer->cmd_queue,
                                       pDispatchTileInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDispatchTileQCOM(VkCommandBuffer commandBuffer, const VkDispatchTileInfoQCOM* pDispatchTileInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDispatchTileQCOM(commandBuffer, pDispatchTileInfo);
   } else {
      vk_cmd_enqueue_CmdDispatchTileQCOM(commandBuffer, pDispatchTileInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdBeginPerTileExecutionQCOM(VkCommandBuffer commandBuffer, const VkPerTileBeginInfoQCOM* pPerTileBeginInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_begin_per_tile_execution_qcom(&cmd_buffer->cmd_queue,
                                       pPerTileBeginInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdBeginPerTileExecutionQCOM(VkCommandBuffer commandBuffer, const VkPerTileBeginInfoQCOM* pPerTileBeginInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdBeginPerTileExecutionQCOM(commandBuffer, pPerTileBeginInfo);
   } else {
      vk_cmd_enqueue_CmdBeginPerTileExecutionQCOM(commandBuffer, pPerTileBeginInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdEndPerTileExecutionQCOM(VkCommandBuffer commandBuffer, const VkPerTileEndInfoQCOM* pPerTileEndInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_end_per_tile_execution_qcom(&cmd_buffer->cmd_queue,
                                       pPerTileEndInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdEndPerTileExecutionQCOM(VkCommandBuffer commandBuffer, const VkPerTileEndInfoQCOM* pPerTileEndInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdEndPerTileExecutionQCOM(commandBuffer, pPerTileEndInfo);
   } else {
      vk_cmd_enqueue_CmdEndPerTileExecutionQCOM(commandBuffer, pPerTileEndInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdCopyTensorARM(VkCommandBuffer commandBuffer,  const VkCopyTensorInfoARM* pCopyTensorInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_copy_tensor_arm(&cmd_buffer->cmd_queue,
                                       pCopyTensorInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdCopyTensorARM(VkCommandBuffer commandBuffer,  const VkCopyTensorInfoARM* pCopyTensorInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdCopyTensorARM(commandBuffer, pCopyTensorInfo);
   } else {
      vk_cmd_enqueue_CmdCopyTensorARM(commandBuffer, pCopyTensorInfo);
   }
}



VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_CmdDispatchDataGraphARM(VkCommandBuffer commandBuffer, VkDataGraphPipelineSessionARM session, const VkDataGraphPipelineDispatchInfoARM* pInfo)
{
   VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (vk_command_buffer_has_error(cmd_buffer))
      return;
   VkResult result = vk_enqueue_cmd_dispatch_data_graph_arm(&cmd_buffer->cmd_queue,
                                       session, pInfo);
   if (unlikely(result != VK_SUCCESS))
      vk_command_buffer_set_error(cmd_buffer, result);
}

VKAPI_ATTR void VKAPI_CALL
vk_cmd_enqueue_unless_primary_CmdDispatchDataGraphARM(VkCommandBuffer commandBuffer, VkDataGraphPipelineSessionARM session, const VkDataGraphPipelineDispatchInfoARM* pInfo)
{
    VK_FROM_HANDLE(vk_command_buffer, cmd_buffer, commandBuffer);

   if (cmd_buffer->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY) {
      const struct vk_device_dispatch_table *disp =
         cmd_buffer->base.device->command_dispatch_table;

      disp->CmdDispatchDataGraphARM(commandBuffer, session, pInfo);
   } else {
      vk_cmd_enqueue_CmdDispatchDataGraphARM(commandBuffer, session, pInfo);
   }
}
