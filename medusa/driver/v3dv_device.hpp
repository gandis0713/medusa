#pragma once

namespace medusa
{

class v3dv_device
{
public:
    v3dv_device();
    ~v3dv_device();

    // Delete copy constructor and assignment operator
    v3dv_device(const v3dv_device&) = delete;
    v3dv_device& operator=(const v3dv_device&) = delete;
};

} // namespace medusa