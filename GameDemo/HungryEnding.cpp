#include "GameDemo_pch.h"
#include "HungryEnding.h"

//engine
#include "IGraphics.h"

//manager
#include "InputManager.h"
#include "EventManager.h"
#include "SceneManager.h"
#include "CameraManager.h"
#include "SoundManager.h"

//entity
#include "Entity.h"

#include "UIBlack.h"
#include "UITestScript.h"

//component
#include "MainUI.h"
#include "UIRenderer.h"
#include "MeshFilter.h"
#include "GraphicsTransfer.h"
HungryEnding::HungryEnding(std::wstring sceneName)
{

}

void HungryEnding::Start()
{
	auto background = std::make_shared<Entity>("Background");
	Scene::AddEntity(background);
	background->AddComponent<MainUI>();
	background->AddComponent<MeshFilter>();
	background->GetComponent<MeshFilter>()->SetModelKey(GraphicsTransfer::ModelKey::UI_GameOver);
	background->AddComponent<UIRenderer>();

	SoundManager::GetInstance()->StopAllSounds();
	SoundManager::GetInstance()->PlayBGM("GameOver.mp3");

	/// fadeIN/OUT   ------------ ���� ���� �ڿ�
	auto BlackUI = std::make_shared<UIBlack>();
	Scene::AddEntity(BlackUI);
	BlackUI->GetComponent<Transform>()->SetWorldPosition({ 0,0,0 });
	BlackUI->GetComponent<Transform>()->SetWorldScale({ 1,1,1 });
	BlackUI->AddComponent<UITestScript>(UIType::FADE);

	Scene::Start();
}

void HungryEnding::Update(double dt)
{
	int score = EventManager::GetInstance()->m_score;
	std::wstring paddedScore = padWithZeros(score);

	m_graphics.lock()->DrawChar(L"BŰ�� ���� Ÿ��Ʋ�� ���ư���", Vector2(335.f, 95.f), 24, Vector4(211.f/255.f, 202.f/255.f, 189.f/255.f, 1.f), Vector2(1000, 500));
	m_graphics.lock()->DrawChar(paddedScore, Vector2(1452.f, 925.f), 80, Vector4(0.f, 0.f, 0.f, 1.f), Vector2(800, 500));

	if (InputManager::GetInstance()->IsKeyDown('B'))
	{
		EventManager::GetInstance()->SceneChange(m_sceneManager.lock()->GetScene("Title"));
	}

	Scene::Update(dt);
}

std::wstring HungryEnding::padWithZeros(int number)
{
	// õ�� ������ 0�� ä������ �ڸ����� ���
	int numDigits = 8; // 1õ���� �ڸ����� 8�Դϴ�.

	// �Էµ� ���ڸ� wstring���� ��ȯ
	std::wstring numberString = std::to_wstring(number);

	// �ʿ��Ѹ�ŭ�� 0�� �տ� �߰�
	int zerosToAdd = numDigits - numberString.length();
	std::wstring paddedString;
	for (int i = 0; i < zerosToAdd; ++i) {
		paddedString += L'0';
	}

	// 0�� �տ� �߰��� �ڿ� �Էµ� ���ڸ� �߰�
	paddedString += numberString;

	return paddedString;
}
