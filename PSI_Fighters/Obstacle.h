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

// 多重インクルードの防止
#pragma once

// ヘッダのインクルード
#include "Obstacle.h"
#include <SpriteBatch.h>
#include <SimpleMath.h>
#include <Keyboard.h>
#include <Mouse.h>

//////////////////////////
//* オブスタクルクラス *//
//////////////////////////

class Obstacle
{
public:
	Obstacle();
	~Obstacle();

	// 初期化関数
	void Initialize(ID3D11Device* device);
	// 更新関数
	void Update(DirectX::Mouse* mouse, DirectX::Mouse::State* mouseState);
	// 描画関数
	void Render(DirectX::SpriteBatch* spriteBatch);

private:
	// 障害物テクスチャ
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_obstacleTexture;
	// 速度
	DirectX::SimpleMath::Vector2 m_obstacleV;
	// 加速度
	DirectX::SimpleMath::Vector2 m_obstacleA;
	// 座標
	DirectX::SimpleMath::Vector2 m_obstaclePos;
	//元画像のｘ座標
	int grp_x;
	//元画像のｙ座標
	int grp_y;
	//元画像の幅
	int grp_w;
	//元画像の高さ
	int grp_h;

	// 画像の中心点
	DirectX::SimpleMath::Vector2 m_anchor;

	// 仮の地面
	int landHeight = 500;

	// 重力
	float gravity = 0.5f;
};

