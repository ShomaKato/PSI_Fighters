///-------------------------------------------------------------------
//*
//*	@�쐬��		2017/08/06
//*
//*	@���O		Player.h
//*
//*	@����		���� ���n
//*
//* @����		�v���C���N���X�̃w�b�_�t�@�C��
//*
///-------------------------------------------------------------------

// ���d�C���N���[�h�̖h�~
#pragma once

// �w�b�_�̃C���N���[�h
#include <SpriteBatch.h>
#include <SimpleMath.h>
#include <Keyboard.h>
#include <Mouse.h>


//////////////////////
//* �v���C���N���X *//
//////////////////////

class Player
{
public:
	Player();
	~Player();

	// �������֐�
	void Initialize(ID3D11Device* device);
	// �X�V�֐�
	void Update(DirectX::Keyboard* keyboard, DirectX::Keyboard::KeyboardStateTracker* keyboardTracker);
	// �`��֐�
	void Render(DirectX::SpriteBatch* spriteBatch);

private:

	// �v���C���e�N�X�`��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_playerTexture;
	// ���x
	DirectX::SimpleMath::Vector2 m_playerV;
	// �����x
	DirectX::SimpleMath::Vector2 m_playerA;
	// ���W
	DirectX::SimpleMath::Vector2 m_playerPos;

	// ���̒n��
	int landHeight = 500;

	// �d��
	float gravity = 0.5f;

};

