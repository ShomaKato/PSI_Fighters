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


//////////////////////
//* プレイヤクラス *//
//////////////////////

class Player
{
public:
	Player();
	~Player();

	// 初期化関数
	void Init();
	// 更新関数
	void Update();
	// 描画関数
	void Render();

private:
	// テクスチャ
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;

	// スプライトバッチ
	std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;

	// 位置座標
	DirectX::SimpleMath::Vector2 m_pos;

};

