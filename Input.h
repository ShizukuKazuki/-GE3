#pragma once
#include <windows.h>
#include<wrl.h>

#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
#include <dinput.h>
#include "WinApp.h"

class Input
{
	public:
	template <class T>  using ComPtr = Microsoft::WRL::ComPtr<T>;
	//初期化
	void Initialize(WinApp* winApp);

	//更新
	void Update();
	
	bool PushKey(BYTE keyNumber);
	bool TriggerKey(BYTE keyNumber);

	private:

		WinApp* winApp = nullptr;

		ComPtr<IDirectInputDevice8> keyboard;
		ComPtr<IDirectInput8> directInput;

		//全キーの状態
		BYTE key[256] = {};
		//前回の全キーの状態
		BYTE keyPre[256] = {};
};

