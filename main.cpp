#include"Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
#pragma region 基盤システム初期化
    //WinApp
    WinApp* winApp = nullptr;
    winApp = new WinApp();
    winApp->Initialize();
   
    //DxCommon
    DirectXCommon* dxCommon = nullptr;
    dxCommon = new DirectXCommon;
    dxCommon->Initialize(winApp);

    //Input
    Input* input = nullptr;
    input = new  Input();
    input->Initialize(winApp);

#pragma endregion

#pragma region 最初のシーン初期化

#pragma endregion 
    // ゲームループ
    while (true)
    {
 
        //Windowsのメッセージ処理
        if (winApp->ProcessMessage()==true)
        {
            //ゲームループを抜ける
            break;
        }
       input->Update();

        //描画前処理
        dxCommon->PreDraw();
        //描画後処理
        dxCommon->PostDraw();
    }
    //入力解放
    delete input;
    input = nullptr;
    delete dxCommon;
    dxCommon = nullptr;
    winApp->Finalize();
    delete winApp;
    winApp = nullptr;
    return 0;
}
