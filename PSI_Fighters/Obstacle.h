///-------------------------------------------------------------------
//*
//*	@�쐬��		2017/09/19
//*
//*	@���O		Obstacle.h
//*
//*	@����		���� ���n
//*
//* @����		��Q���N���X�̃w�b�_�t�@�C��
//*
///-------------------------------------------------------------------

// ���d�C���N���[�h�̖h�~
#pragma once

// �w�b�_�̃C���N���[�h
#include "Obstacle.h"
#include <SpriteBatch.h>
#include <SimpleMath.h>
#include <Keyboard.h>
#include <Mouse.h>

//////////////////////////
//* �I�u�X�^�N���N���X *//
//////////////////////////

class Obstacle
{
public:
	Obstacle();
	~Obstacle();

	// �������֐�
	void Initialize(ID3D11Device* device);
	// �X�V�֐�
	void Update(DirectX::Mouse* mouse, DirectX::Mouse::State* mouseState);
	// �`��֐�
	void Render(DirectX::SpriteBatch* spriteBatch);

private:
	// ��Q���e�N�X�`��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_obstacleTexture;
	// ���x
	DirectX::SimpleMath::Vector2 m_obstacleV;
	// �����x
	DirectX::SimpleMath::Vector2 m_obstacleA;
	// ���W
	DirectX::SimpleMath::Vector2 m_obstaclePos;
	//���摜�̂����W
	int grp_x;
	//���摜�̂����W
	int grp_y;
	//���摜�̕�
	int grp_w;
	//���摜�̍���
	int grp_h;

	// �摜�̒��S�_
	DirectX::SimpleMath::Vector2 m_anchor;

	// ���̒n��
	int landHeight = 500;

	// �d��
	float gravity = 0.5f;
};

