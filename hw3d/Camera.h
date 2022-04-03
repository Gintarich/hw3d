#pragma once
#include "Graphics.h"
#include "Window.h"

class Camera
{
public: 
	DirectX::XMMATRIX GetMatrix() const noexcept;
	void MoveCamera(float x, float y) noexcept;
	void ZoomCamera(float z) noexcept;
	void Reset() noexcept;
private:
	float xcoord = 0.0f;
	float ycoord = 0.0f;
	float r = 20.0f;
	float theta = 0.0f;
	float phi = 0.0f;
	float pitch = 0.0f;
	float yaw = 0.0f;
	float roll = 0.0f;
};
