//
// Game.h
//

#pragma once

#include "StepTimer.h"
#include "SpriteBatch.h"
#include "SimpleMath.h"
#include <Keyboard.h>
#include <Mouse.h>


// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();
    void Present();

    void CreateDevice();
    void CreateResources();

    void OnDeviceLost();

    // Device resources.
    HWND                                            m_window;
    int                                             m_outputWidth;
    int                                             m_outputHeight;

    D3D_FEATURE_LEVEL                               m_featureLevel;
    Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

    Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;
    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;

    // Rendering loop timer.
    DX::StepTimer                                   m_timer;







	//* �X�v���C�g�o�b�`�Ɖ����̍��W
	std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
	DirectX::SimpleMath::Vector2 m_origin;

	//* ���̒n��
	int landHeight = 500;

	//* �d��
	float gravity = 0.5f;


	/* ===== �����ƂŃv���C���N���X�Ɉړ�������́� ===== */

	// �v���C���e�N�X�`��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_playerTexture;
	// ���x
	DirectX::SimpleMath::Vector2 m_playerV;
	// �����x
	DirectX::SimpleMath::Vector2 m_playerA;
	// ���W
	DirectX::SimpleMath::Vector2 m_playerPos;
	// �L�[�{�[�h
	std::unique_ptr<DirectX::Keyboard> m_keyboard;
	//// �}�E�X
	//std::unique_ptr<Mouse> m_mouse;

	/* ===== �����ƂŃv���C���N���X�Ɉړ�������́� ===== */



	/* ===== �����ƂŃI�u�X�^�N���N���X�Ɉړ�������́� ===== */

	// ��Q���e�N�X�`��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_obstacleTexture;
	// ���x
	DirectX::SimpleMath::Vector2 m_obstacleV;
	// �����x
	DirectX::SimpleMath::Vector2 m_obstacleA;
	// ���W
	DirectX::SimpleMath::Vector2 m_obstaclePos;

	/* ===== �����ƂŃI�u�X�^�N���N���X�Ɉړ�������́�===== */


};