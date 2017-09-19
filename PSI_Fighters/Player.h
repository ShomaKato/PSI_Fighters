///-------------------------------------------------------------------
//*
//*	@作成日		2017/08/06
//*
//*	@名前		Player.h
//*
//*	@著者		加藤 彰馬
//*
//* @役割		プレイヤクラスのヘッダファイル
//*
///-------------------------------------------------------------------

// 多重インクルードの防止
#pragma once

// ヘッダのインクルード
#include <SpriteBatch.h>
#include <SimpleMath.h>
#include <Keyboard.h>
#include <Mouse.h>


//////////////////////
//* プレイヤクラス *//
//////////////////////

class Player
{
public:
	Player();
	~Player();

	// 初期化関数
	void Initialize(ID3D11Device* device);
	// 更新関数
	void Update(DirectX::Keyboard* keyboard, DirectX::Keyboard::KeyboardStateTracker* keyboardTracker);
	// 描画関数
	void Render(DirectX::SpriteBatch* spriteBatch);

private:

	// プレイヤテクスチャ
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_playerTexture;
	// 速度
	DirectX::SimpleMath::Vector2 m_playerV;
	// 加速度
	DirectX::SimpleMath::Vector2 m_playerA;
	// 座標
	DirectX::SimpleMath::Vector2 m_playerPos;

	// 仮の地面
	int landHeight = 500;

	// 重力
	float gravity = 0.5f;

};

