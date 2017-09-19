///-------------------------------------------------------------------
//*
//*	@作成日		2017/09/19
//*
//*	@名前		Obstacle.h
//*
//*	@著者		加藤 彰馬
//*
//* @役割		障害物クラスのヘッダファイル
//*
///-------------------------------------------------------------------

// ヘッダのインクルード
#include "pch.h"
#include "WICTextureLoader.h"
#include "Obstacle.h"

// 名前空間
using namespace DirectX;
using namespace DirectX::SimpleMath;

////----------------------------------------------------------------------
////! @関数名：Obstacle
////!
////! @役割：障害物クラスのコンストラクタ
////!
////! @引数：なし(void)
////!
////! @戻り値：存在しない
////----------------------------------------------------------------------
Obstacle::Obstacle()
{
}


////----------------------------------------------------------------------
////! @関数名：~Obstacle
////!
////! @役割：障害物クラスのデストラクタ
////!
////! @引数：存在しない
////!
////! @戻り値：存在しない
////----------------------------------------------------------------------
Obstacle::~Obstacle()
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
void Obstacle::Initialize(ID3D11Device * device)
{
	// テクスチャを初期化する
	m_obstacleTexture = nullptr;

	// テクスチャデータを読み込む
	CreateWICTextureFromFile(device, L"Images\\obstacle.png", nullptr, m_obstacleTexture.GetAddressOf());

	// 重力加速度
	m_obstacleA.y = gravity;

	// 初期位置
	m_obstaclePos.x = 500;
	m_obstaclePos.y = 300;

	// 中心点
	m_anchor = Vector2(64, 64);
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
void Obstacle::Update(Mouse* mouse, Mouse::State* mouseState)
{
	// マウスの状態取得
	auto state = mouse->GetState();
	// マウス左クリックされているなら
	if (state.leftButton)
	{
		m_obstaclePos.x = state.x;
		m_obstaclePos.y = state.y; \
	}

	// 速度に加速度を足す
	m_obstacleV.x += m_obstacleA.x;
	m_obstacleV.y += m_obstacleA.y;
	// 位置に速度を足す
	m_obstaclePos.x += m_obstacleV.x;
	m_obstaclePos.y += m_obstacleV.y;
	// 落下速度が早すぎたらちょうどいいとこで加速が止まる
	if (m_obstacleV.y > 50)
	{
		m_obstacleV.y = 50;
	}

	// 地面との雑判定
	if (m_obstaclePos.y > landHeight - 64)
	{
		m_obstaclePos.y = landHeight - 64;
		m_obstacleV.y = 0;
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
void Obstacle::Render(SpriteBatch * m_spriteBatch)
{
	m_spriteBatch->Draw(m_obstacleTexture.Get(), m_obstaclePos, nullptr, Colors::White,
			0.f, m_anchor);
}
