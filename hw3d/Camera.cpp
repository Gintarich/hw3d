#include "Camera.h"

namespace dx = DirectX;

DirectX::XMMATRIX Camera::GetMatrix() const noexcept
{
    const auto pos = dx::XMVector3Transform(
        dx::XMVectorSet(xcoord, ycoord, -r, 0.0f),
        dx::XMMatrixRotationRollPitchYaw(phi, theta, 0.0f)
    );
#if 0
    return dx::XMMatrixLookAtLH(
        pos, dx::XMVectorZero(),
        dx::XMVectorSet(0.0f,1.0f,0.0f,0.0f)
    );
#endif 
    
#if 1
    return dx::XMMatrixSet(
        1.0f , 0.0f , 0.0f , 0.0f,
        0.0f , 1.0f , 0.0f , 0.0f,
        0.0f , 0.0f , 1.0f , 0.0f,
        xcoord , ycoord , r , 1.0f
    );
#endif
}

void Camera::MoveCamera(float x, float y) noexcept
{
    xcoord -= x/10;
    ycoord += y/10;
}

void Camera::Reset() noexcept
{
    xcoord = 0.0f;
    ycoord = 0.0f;
    r = 20.0f;
    theta = 0.0f;
    phi = 0.0f;
    pitch = 0.0f;
    yaw = 0.0f;
    roll = 0.0f;
}
