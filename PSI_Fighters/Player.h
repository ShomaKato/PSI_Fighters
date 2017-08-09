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


//////////////////////
//* �v���C���N���X *//
//////////////////////

class Player
{
public:
	Player();
	~Player();

	// �������֐�
	void Init();
	// �X�V�֐�
	void Update();
	// �`��֐�
	void Render();

private:
	// �e�N�X�`��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;

	// �X�v���C�g�o�b�`
	std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;

	// �ʒu���W
	DirectX::SimpleMath::Vector2 m_pos;

};

