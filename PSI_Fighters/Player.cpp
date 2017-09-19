///-------------------------------------------------------------------
//*
//*	@�쐬��		2017/08/06
//*
//*	@���O		Player.cpp
//*
//* @����		�v���C���N���X�̃\�[�X�t�@�C��
//*
//*	@����		���� ���n
//*
///-------------------------------------------------------------------

// �w�b�_�̃C���N���[�h
#include "pch.h"
#include "WICTextureLoader.h"
#include "Player.h"

// ���O���
using namespace DirectX;
using namespace DirectX::SimpleMath;


////----------------------------------------------------------------------
////! @�֐����FPlayer
////!
////! @�����F�v���C���N���X�̃R���X�g���N�^
////!
////! @�����F�Ȃ�(void)
////!
////! @�߂�l�F���݂��Ȃ�
////----------------------------------------------------------------------
Player::Player()
{
}


////----------------------------------------------------------------------
////! @�֐����F~Player
////!
////! @�����F�v���C���N���X�̃f�X�g���N�^
////!
////! @�����F���݂��Ȃ�
////!
////! @�߂�l�F���݂��Ȃ�
////----------------------------------------------------------------------
Player::~Player()
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
void Player::Initialize(ID3D11Device* device)
{
	// �e�N�X�`��������������
	m_playerTexture = nullptr;

	// �e�N�X�`���f�[�^��ǂݍ���
	CreateWICTextureFromFile(device, L"Images\\player.png", nullptr, m_playerTexture.GetAddressOf());

	// �d�͉����x
	m_playerA.y = gravity;

	// �����ʒu
	m_playerPos.x = 100;
	m_playerPos.y = 100;
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
void Player::Update(DirectX::Keyboard* keyboard, DirectX::Keyboard::KeyboardStateTracker* keyboardTracker)
{
	// �L�[�{�[�h�̏�Ԏ擾
	auto kb = keyboard->GetState();
	keyboardTracker->Update(kb);


	// ���x�ɉ����x�𑫂�
	m_playerV.x += m_playerA.x;
	m_playerV.y += m_playerA.y;
	// �ʒu�ɑ��x�𑫂�
	m_playerPos.x += m_playerV.x;
	m_playerPos.y += m_playerV.y;
	// �������x�����������炿�傤�ǂ����Ƃ��ŉ������~�܂�
	if (m_playerV.y > 50)
	{
		m_playerV.y = 50;
	}

	// �n�ʂƂ̎G����
	if (m_playerPos.y > landHeight)
	{
		m_playerPos.y = landHeight;
		m_playerV.y = 0;
	}

	// A�L�[�ō���
	if (kb.A)
	{
		m_playerPos.x = m_playerPos.x - 3.5f;
	}
	// D�L�[�ŉE��
	if (kb.D)
	{
		m_playerPos.x = m_playerPos.x + 3.5f;
	}
	// W�L�[�ŃW�����v
	if (keyboardTracker->IsKeyPressed(Keyboard::Keys::W))
	{
		m_playerV.y = m_playerV.x - 14.5f;
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
void Player::Render(SpriteBatch* m_spriteBatch)
{
	m_spriteBatch->Draw(m_playerTexture.Get(), m_playerPos);
}
