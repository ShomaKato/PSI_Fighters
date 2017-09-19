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

// �w�b�_�̃C���N���[�h
#include "pch.h"
#include "WICTextureLoader.h"
#include "Obstacle.h"

// ���O���
using namespace DirectX;
using namespace DirectX::SimpleMath;

////----------------------------------------------------------------------
////! @�֐����FObstacle
////!
////! @�����F��Q���N���X�̃R���X�g���N�^
////!
////! @�����F�Ȃ�(void)
////!
////! @�߂�l�F���݂��Ȃ�
////----------------------------------------------------------------------
Obstacle::Obstacle()
{
}


////----------------------------------------------------------------------
////! @�֐����F~Obstacle
////!
////! @�����F��Q���N���X�̃f�X�g���N�^
////!
////! @�����F���݂��Ȃ�
////!
////! @�߂�l�F���݂��Ȃ�
////----------------------------------------------------------------------
Obstacle::~Obstacle()
{
}


////----------------------------------------------------------------------
////! @�֐����FInitialize
////!
////! @�����F�v���C���̏���������
////!
////! @�����F�Ȃ�(void)
////!
////! @�߂�l�F�Ȃ�(void)
////----------------------------------------------------------------------
void Obstacle::Initialize(ID3D11Device * device)
{
	// �e�N�X�`��������������
	m_obstacleTexture = nullptr;

	// �e�N�X�`���f�[�^��ǂݍ���
	CreateWICTextureFromFile(device, L"Images\\obstacle.png", nullptr, m_obstacleTexture.GetAddressOf());

	// �d�͉����x
	m_obstacleA.y = gravity;

	// �����ʒu
	m_obstaclePos.x = 500;
	m_obstaclePos.y = 300;

	// ���S�_
	m_anchor = Vector2(64, 64);
}


////----------------------------------------------------------------------
////! @�֐����FUpdate
////!
////! @�����F�v���C���̍X�V����
////!
////! @�����F�Ȃ�(void)
////!
////! @�߂�l�F�Ȃ�(void)
////----------------------------------------------------------------------
void Obstacle::Update(Mouse* mouse, Mouse::State* mouseState)
{
	// �}�E�X�̏�Ԏ擾
	auto state = mouse->GetState();
	// �}�E�X���N���b�N����Ă���Ȃ�
	if (state.leftButton)
	{
		m_obstaclePos.x = state.x;
		m_obstaclePos.y = state.y; \
	}

	// ���x�ɉ����x�𑫂�
	m_obstacleV.x += m_obstacleA.x;
	m_obstacleV.y += m_obstacleA.y;
	// �ʒu�ɑ��x�𑫂�
	m_obstaclePos.x += m_obstacleV.x;
	m_obstaclePos.y += m_obstacleV.y;
	// �������x�����������炿�傤�ǂ����Ƃ��ŉ������~�܂�
	if (m_obstacleV.y > 50)
	{
		m_obstacleV.y = 50;
	}

	// �n�ʂƂ̎G����
	if (m_obstaclePos.y > landHeight - 64)
	{
		m_obstaclePos.y = landHeight - 64;
		m_obstacleV.y = 0;
	}
}


////----------------------------------------------------------------------
////! @�֐����FRender
////!
////! @�����F�v���C���̕`�揈��
////!
////! @�����F�Ȃ�(void)
////!
////! @�߂�l�F�Ȃ�(void)
////----------------------------------------------------------------------
void Obstacle::Render(SpriteBatch * m_spriteBatch)
{
	m_spriteBatch->Draw(m_obstacleTexture.Get(), m_obstaclePos, nullptr, Colors::White,
			0.f, m_anchor);
}
