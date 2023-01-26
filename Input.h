#pragma once
#include <windows.h>
#include<wrl.h>

#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
#include <dinput.h>

class Input
{
	public:
	template <class T>  using ComPtr = Microsoft::WRL::ComPtr<T>;
	//������
	void Initialize(HINSTANCE hInsstance, HWND hwnd);
	//�X�V
	void Update();
	//�S�L�[�̏��
	BYTE key[256] = {};
	//�O��̑S�L�[�̏��
	BYTE keyPre[256] = {};

	bool PushKey(BYTE keyNumber);
	bool TriggerKey(BYTE keyNumber);

	private:
		ComPtr<IDirectInputDevice8> keyboard;
		ComPtr<IDirectInput8> directInput;

		
	
};

