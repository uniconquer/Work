#pragma once

namespace DX
{
	static const UINT c_frameCount = 3;		// 3중 버퍼링을 사용합니다.

	// 모든 DirectX 장치 리소스를 제어합니다.
	class DeviceResources
	{
	public:
		DeviceResources();
		void SetWindow(Windows::UI::Core::CoreWindow^ window);
		void SetLogicalSize(Windows::Foundation::Size logicalSize);
		void SetCurrentOrientation(Windows::Graphics::Display::DisplayOrientations currentOrientation);
		void SetDpi(float dpi);
		void ValidateDevice();
		void Present();
		void WaitForGpu();

		// 장치 접근자입니다.
		Windows::Foundation::Size	GetOutputSize() const				{ return m_outputSize; }
		Windows::Foundation::Size	GetLogicalSize() const				{ return m_logicalSize; }
		bool						IsDeviceRemoved() const				{ return m_deviceRemoved; }

		// D3D 접근자입니다.
		ID3D12Device*				GetD3DDevice() const				{ return m_d3dDevice.Get(); }
		IDXGISwapChain3*			GetSwapChain() const				{ return m_swapChain.Get(); }
		ID3D12Resource*				GetRenderTarget() const				{ return m_renderTargets[m_currentFrame].Get(); }
		ID3D12CommandQueue*			GetCommandQueue() const				{ return m_commandQueue.Get(); }
		ID3D12CommandAllocator*		GetCommandAllocator() const			{ return m_commandAllocators[m_currentFrame].Get(); }
		D3D12_VIEWPORT				GetScreenViewport() const			{ return m_screenViewport; }
		DirectX::XMFLOAT4X4			GetOrientationTransform3D() const	{ return m_orientationTransform3D; }
		UINT						GetCurrentFrameIndex() const		{ return m_currentFrame; }

		CD3DX12_CPU_DESCRIPTOR_HANDLE GetRenderTargetView() const
		{
			return CD3DX12_CPU_DESCRIPTOR_HANDLE(m_rtvHeap->GetCPUDescriptorHandleForHeapStart(), m_currentFrame, m_rtvDescriptorSize);
		}

	private:
		void CreateDeviceIndependentResources();
		void CreateDeviceResources();
		void CreateWindowSizeDependentResources();
		void MoveToNextFrame();
		DXGI_MODE_ROTATION ComputeDisplayRotation();

		UINT											m_currentFrame;

		// Direct3D 개체입니다.
		Microsoft::WRL::ComPtr<ID3D12Device>			m_d3dDevice;
		Microsoft::WRL::ComPtr<IDXGIFactory4>			m_dxgiFactory;
		Microsoft::WRL::ComPtr<IDXGISwapChain3>			m_swapChain;
		Microsoft::WRL::ComPtr<ID3D12Resource>			m_renderTargets[c_frameCount];
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>	m_rtvHeap;
		UINT											m_rtvDescriptorSize;
		Microsoft::WRL::ComPtr<ID3D12CommandQueue>		m_commandQueue;
		Microsoft::WRL::ComPtr<ID3D12CommandAllocator>	m_commandAllocators[c_frameCount];
		D3D12_VIEWPORT									m_screenViewport;
		bool											m_deviceRemoved;

		// CPU/GPU 동기화.
		Microsoft::WRL::ComPtr<ID3D12Fence>				m_fence;
		UINT64											m_fenceValues[c_frameCount];
		HANDLE											m_fenceEvent;

		// 창에 대한 캐시된 참조입니다.
		Platform::Agile<Windows::UI::Core::CoreWindow>	m_window;

		// 캐시된 장치 속성입니다.
		Windows::Foundation::Size						m_d3dRenderTargetSize;
		Windows::Foundation::Size						m_outputSize;
		Windows::Foundation::Size						m_logicalSize;
		Windows::Graphics::Display::DisplayOrientations	m_nativeOrientation;
		Windows::Graphics::Display::DisplayOrientations	m_currentOrientation;
		float											m_dpi;

		// 표시 방향에 사용되는 변환입니다.
		DirectX::XMFLOAT4X4 m_orientationTransform3D;
	};
}
