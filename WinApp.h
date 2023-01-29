#pragma once
#include <Windows.h>
class WinApp
{
public:
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
public: //�萔
	//�E�B���h�E����
	static const int  window_width = 1280;
	//�E�B���h�E�c��
	static const int window_height = 720;
public: //�����o�֐�
	//������
	void Initialize();
	//���b�Z�[�W�̏���
	bool ProcessMessage();
	//�X�V
	void Updata();
	//�I��
	void Finalize();
	//getter
	HWND GetHwnd() const { return hwnd;}
	HINSTANCE GetHlnstance() const { return w.hInstance; }

private: //�����o�ϐ�
	//�E�B���h�n���h��
	HWND hwnd = nullptr;
	// �E�B���h�E�N���X�̐ݒ�
	WNDCLASSEX w{};
};

