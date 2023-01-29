#pragma once
#include <Windows.h>
class WinApp
{
public:
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
public: //定数
	//ウィンドウ横幅
	static const int  window_width = 1280;
	//ウィンドウ縦幅
	static const int window_height = 720;
public: //メンバ関数
	//初期化
	void Initialize();
	//メッセージの処理
	bool ProcessMessage();
	//更新
	void Updata();
	//終了
	void Finalize();
	//getter
	HWND GetHwnd() const { return hwnd;}
	HINSTANCE GetHlnstance() const { return w.hInstance; }

private: //メンバ変数
	//ウィンドハンドル
	HWND hwnd = nullptr;
	// ウィンドウクラスの設定
	WNDCLASSEX w{};
};

