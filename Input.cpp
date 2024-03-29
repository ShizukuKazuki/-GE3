#include "Input.h"
#include<cassert>
#include  <wrl.h>
using  namespace Microsoft :: WRL;

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
void Input::Initialize(WinApp* winApp)
{０４−０５
    HRESULT result;
    //借りてきたWinAppのインスタンスを記録
    this->winApp = winApp;
    //DirectInputの初期化
    //ComPtr<IDirectInput8> directInput;
    result = DirectInput8Create(
        this->winApp->GetHlnstance(), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
    assert(SUCCEEDED(result));
   // キーボードデバイスの生成
    //ComPtr<IDirectInputDevice8> keyboard;
    result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
    // 入力データ形式のセット
    result = keyboard->SetDataFormat(&c_dfDIKeyboard); // 標準形式
    assert(SUCCEEDED(result));
    // 排他制御レベルのセット
    result = keyboard->SetCooperativeLevel(
        this->winApp->GetHwnd(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
    assert(SUCCEEDED(result));
}


void Input :: Update()
{
    HRESULT result;
    memcpy(keyPre, key, sizeof(key));

    // キーボード情報の取得開始
    //keyboard->Acquire();
    result = keyboard->Acquire();
    // 全キーの入力状態を取得する
    //BYTE key[256] = {};
   //keyboard->GetDeviceState(sizeof(key), key);
    result =  keyboard->GetDeviceState(sizeof(key), key);
}

bool Input::PushKey(BYTE keyNumber)
{
    //指定キーを押してたらtrueを返す
    if (key[keyNumber])
    {
        return true;
    }
    return false;
}
bool Input::TriggerKey(BYTE keyNomder)
{
    if (key[keyNomder] && !keyPre[keyNomder])
    {
        return true;
    }

    return false; 
}

