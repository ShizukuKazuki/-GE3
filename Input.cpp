#include "Input.h"
#include<cassert>
#include  <wrl.h>
using  namespace Microsoft :: WRL;

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
void Input::Initialize(WinApp* winApp)
{
    HRESULT result;
    //�؂�Ă���WinApp�̃C���X�^���X���L�^
    this->winApp = winApp;
    //DirectInput�̏�����
    //ComPtr<IDirectInput8> directInput;
    result = DirectInput8Create(
        this->winApp->GetHlnstance(), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
    assert(SUCCEEDED(result));
   // �L�[�{�[�h�f�o�C�X�̐���
    //ComPtr<IDirectInputDevice8> keyboard;
    result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
    // ���̓f�[�^�`���̃Z�b�g
    result = keyboard->SetDataFormat(&c_dfDIKeyboard); // �W���`��
    assert(SUCCEEDED(result));
    // �r�����䃌�x���̃Z�b�g
    result = keyboard->SetCooperativeLevel(
        this->winApp->GetHwnd(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
    assert(SUCCEEDED(result));
}


void Input :: Update()
{
    HRESULT result;
    memcpy(keyPre, key, sizeof(key));

    // �L�[�{�[�h���̎擾�J�n
    //keyboard->Acquire();
    result = keyboard->Acquire();
    // �S�L�[�̓��͏�Ԃ��擾����
    //BYTE key[256] = {};
   //keyboard->GetDeviceState(sizeof(key), key);
    result =  keyboard->GetDeviceState(sizeof(key), key);
}

bool Input::PushKey(BYTE keyNumber)
{
    //�w��L�[�������Ă���true��Ԃ�
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

