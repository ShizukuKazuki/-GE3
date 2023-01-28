#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include <vector>
#include <chrono>

class DirectXCommon
{
	public: //�����o�֐�
		//������
		void Initialize(WinApp* winApp);
		//�`��O����
		void PreDraw();
		//�`��㏈��
		void PostDraw();
		//Getter
		ID3D12Device* GetDevice() const { return device.Get(); }
		//�R�}���h���X�g
		ID3D12GraphicsCommandList* GetCommondList()const { return commandList.Get();}
private:
	//�f�o�C�X������
	void InitializeDevice();
	//�R�}���h�֘A������
	void InitializeCommand();
	//�X���b�v�`�F�[��������
	void InitializeSwapchain();
	//�����_�[�^�[�Q�b�g�r���[������
	void InitializeRenderTargetView();
	//�[�x�o�b�t�@
	void InitializeDepthBuffer();
	//�t�F���X������
	void  InitializeFence();
	//FPS�Œ�X�V
	void InitializeFixFPS();
	//FPS�Œ�X�V
	void UpdateFixFPS();
private:
	WinApp* winApp = nullptr;
	//�f�o�C�X�֘A
	Microsoft::WRL::ComPtr<ID3D12Device> device;
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;
	//�R�}���h�֘A
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;
	//�X���b�v�`�F�[��
	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};
	//�����_�[�^�[�Q�b�g�r���[
	ComPtr<ID3D12DescriptorHeap> rtvHeap;  
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;
	//�[�x�o�b�t�@
	Microsoft::WRL::ComPtr<ID3D12Resource> depthBuff;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;
	//�t�F���X
	Microsoft::WRL::ComPtr<ID3D12Fence> fence;
	UINT64 fenceVal = 0;
	//�L�^����(FPS�Œ�p)
	std::chrono::steady_clock::time_point reference_;
};

