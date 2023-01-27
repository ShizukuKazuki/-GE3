#pragma once
#include <windows.h>
#include<wrl.h>

#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
#include <dinput.h>
#include "WinApp.h"

class Input
{
	public:
	template <class T>  using ComPtr = Microsoft::WRL::ComPtr<T>;
	//������
	void Initialize(WinApp* winApp);

	//�X�V
	void Update();
	
	bool PushKey(BYTE keyNumber);
	bool TriggerKey(BYTE keyNumber);

	private:

		WinApp* winApp = nullptr;

		ComPtr<IDirectInputDevice8> keyboard;
		ComPtr<IDirectInput8> directInput;

		//�S�L�[�̏��
		BYTE key[256] = {};
		//�O��̑S�L�[�̏��
		BYTE keyPre[256] = {};
};

