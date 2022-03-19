#include "Graphics.h"

//compiler sets linker settings for us
#pragma comment(lib,"d3d11.lib")

Graphics::Graphics(HWND hWnd)
{
	//Description structure
	DXGI_SWAP_CHAIN_DESC sd = { };
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 0;
	sd.BufferDesc.RefreshRate.Denominator= 0;
	sd.BufferDesc.Scaling= DXGI_MODE_SCALING_UNSPECIFIED;
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.SampleDesc.Count= 1;
	sd.SampleDesc.Quality = 0;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.BufferCount = 1;
	sd.OutputWindow = hWnd;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	sd.Flags - 0;

	//Have to create Device and swap chain
	D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		nullptr,
		0,
		D3D11_SDK_VERSION,
		&sd,
		&m_pSwap,
		&m_pDevice,
		nullptr,
		&m_pContext
	);
}

Graphics::~Graphics()
{
	if( m_pContext != nullptr )
	{
		m_pContext->Release();
	}
	if( m_pSwap != nullptr )
	{
		m_pSwap->Release();
	}
	if( m_pDevice != nullptr )
	{
		m_pDevice->Release();
	}
}
