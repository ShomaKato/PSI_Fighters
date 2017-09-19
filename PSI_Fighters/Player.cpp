///-------------------------------------------------------------------
//*
//*	@作成日		2017/08/06
//*
//*	@名前		Player.cpp
//*
//* @役割		プレイヤクラスのソースファイル
//*
//*	@著者		加藤 彰馬
//*
///-------------------------------------------------------------------

// ヘッダのインクルード
#include "pch.h"
#include "WICTextureLoader.h"
#include "Player.h"

// 名前空間
using namespace DirectX;
using namespace DirectX::SimpleMath;


////----------------------------------------------------------------------
////! @関数名：Player
////!
////! @役割：プレイヤクラスのコンストラクタ
////!
////! @引数：なし(void)
////!
////! @戻り値：存在しない
////----------------------------------------------------------------------
Player::Player()
{
}


////----------------------------------------------------------------------
////! @関数名：~Player
////!
////! @役割：プレイヤクラスのデストラクタ
////!
////! @引数：存在しない
////!
////! @戻り値：存在しない
////----------------------------------------------------------------------
Player::~Player()
{
}


////----------------------------------------------------------------------
////! @関数名：Initialize
////!
////! @役割：プレイヤの初期化処理
////!
////! @引数：なし(void)
////!
////! @戻り値：なし(void)
////----------------------------------------------------------------------
void Player::Initialize(ID3D11Device* device)
{
	// テクスチャを初期化する
	m_playerTexture = nullptr;

	// テクスチャデータを読み込む
	CreateWICTextureFromFile(device, L"Images\\player.png", nullptr, m_playerTexture.GetAddressOf());

	// 重力加速度
	m_playerA.y = gravity;

	// 初期位置
	m_playerPos.x = 100;
	m_playerPos.y = 100;
}


////----------------------------------------------------------------------
////! @関数名：Update
////!
////! @役割：プレイヤの更新処理
////!
////! @引数：なし(void)
////!
////! @戻り値：なし(void)
////----------------------------------------------------------------------
void Player::Update(DirectX::Keyboard* keyboard, DirectX::Keyboard::KeyboardStateTracker* keyboardTracker)
{
	// キーボードの状態取得
	auto kb = keyboard->GetState();
	keyboardTracker->Update(kb);


	// 速度に加速度を足す
	m_playerV.x += m_playerA.x;
	m_playerV.y += m_playerA.y;
	// 位置に速度を足す
	m_playerPos.x += m_playerV.x;
	m_playerPos.y += m_playerV.y;
	// 落下速度が早すぎたらちょうどいいとこで加速が止まる
	if (m_playerV.y > 50)
	{
		m_playerV.y = 50;
	}

	// 地面との雑判定
	if (m_playerPos.y > landHeight)
	{
		m_playerPos.y = landHeight;
		m_playerV.y = 0;
	}

	// Aキーで左へ
	if (kb.A)
	{
		m_playerPos.x = m_playerPos.x - 3.5f;
	}
	// Dキーで右へ
	if (kb.D)
	{
		m_playerPos.x = m_playerPos.x + 3.5f;
	}
	// Wキーでジャンプ
	if (keyboardTracker->IsKeyPressed(Keyboard::Keys::W))
	{
		m_playerV.y = m_playerV.x - 14.5f;
	}


}


////----------------------------------------------------------------------
////! @関数名：Render
////!
////! @役割：プレイヤの描画処理
////!
////! @引数：なし(void)
////!
////! @戻り値：なし(void)
////----------------------------------------------------------------------
void Player::Render(SpriteBatch* m_spriteBatch)
{
	m_spriteBatch->Draw(m_playerTexture.Get(), m_playerPos);
}
