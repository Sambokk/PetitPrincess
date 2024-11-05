#include "GameDemo_pch.h"
#include "STAGE1.h"

#include <random>

//���� �������� ����
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> ranInt(0, 1);


///Entity
#include "Entity.h"

///Prefab
#include "PlayerPrefab.h"
#include "PlayerPrefab.h"
#include "GuardPrefab.h"
#include "Grid.h"
#include "RedBox.h"
#include "TextureBox.h"
#include "UI.h"
#include "UIGauge.h"
#include "UIhungry.h"
#include "UIMiniMapIcon.h"
#include "UISkill.h"
#include "UIBlack.h"


///Compoenent
#include "DirectionalLight.h"
#include "SunLight.h"
#include "TimerUI.h"
#include "TextRender.h"
#include "MeshFilter.h"
#include "UIRenderer.h"
#include "SphereCollider.h"
#include "PlaneCollider.h"
#include "MeshRenderer.h"
#include "ShopKeeperFSM.h"
#include "CapsuleCollider.h"
#include "BoxCollider.h"
#include "PointLight.h"
#include "UIMinimapCurPos.h"
#include "MerchantUI.h"
#include "PlayerMoveScript.h"
#include "PlayerFSM.h"
#include "PetitCamera.h"
#include "MiniGameManager.h"

///Script
#include "GameManager.h"
#include "TechniquesScript.h"
#include "InterKeyScript.h"
#include "ShopKeeperDoubtScript.h"
#include "FoodTableScript.h"
#include "ScoreUI.h"
#include "HideAutomaticScript.h"
#include "HideInteractionScript.h"
#include "UITestScript.h"
#include "PopUpUI.h"
#include "ShopKeeperCallingScript.h"
#include "UIDataSyncScript.h"
#include "UIMinimap.h"
#include "TorchLight.h"
#include "HideInterKeyScript.h"
#include "ChaseRangeScript.h"
#include "GuardUI.h"

///Manager
#include "ResourceManager.h"
#include "MinigameDefine.h"
#include "CameraManager.h"
#include "SoundManager.h"
#include "InputManager.h"
#include "CameraModule.h"
#include "MiniGameManager.h"

STAGE1::STAGE1(std::wstring sceneName)
	: Scene(sceneName)
{
	m_shopData =
	{
		{Vector3(7.5f, 0.f, 5.5f), EntityDirection::RIGHT},			//1
		{Vector3(34.5f, 0.f, 9.5f), EntityDirection::RIGHT},		//2
		{Vector3(17.5f, 0.f, 20.5f), EntityDirection::RIGHT},		//3
		{Vector3(40.0f, 0.f, 30.5f), EntityDirection::DOWN},		//4
		{Vector3(19.5f, 0.f, 41.5f), EntityDirection::RIGHT},		//5
		{Vector3(60.0f, 0.f, 27.5f), EntityDirection::DOWN},		//6
		{Vector3(6.5f, 0.f, 56.5f), EntityDirection::DOWN},			//7
		{Vector3(75.5f, 0.f, 14.5f), EntityDirection::DOWN},		//8
		{Vector3(26.5f, 0.f, 71.5f), EntityDirection::DOWN},		//9
		{Vector3(42.5f, 0.f, 58.5f), EntityDirection::RIGHT},		//10

		{Vector3(60.5f, 0.f, 47.5f), EntityDirection::RIGHT},		//11
		{Vector3(79.5f, 0.f, 35.5f), EntityDirection::DOWN},		//12
		{Vector3(97.5f, 0.f, 28.5f), EntityDirection::LEFT},		//13
		{Vector3(112.5f, 0.f, 19.5f), EntityDirection::LEFT},		//14
		{Vector3(121.5f, 0.f, 4.5f), EntityDirection::RIGHT},		//15
		{Vector3(133.5f, 0.f, 18.5f), EntityDirection::LEFT},		//16
		{Vector3(144.5f, 0.f, 5.5f), EntityDirection::LEFT},		//17
		{Vector3(125.5f, 0.f, 32.5f), EntityDirection::LEFT},		//18
		{Vector3(136.5f, 0.f, 44.5f), EntityDirection::LEFT},		//19
		{Vector3(98.5f, 0.f, 48.5f), EntityDirection::LEFT},		//20

		{Vector3(114.5f, 0.f, 55.5f), EntityDirection::LEFT},		//21
		{Vector3(128.5f, 0.f, 65.5f), EntityDirection::RIGHT},		//22
		{Vector3(143.5f, 0.f, 75.5f), EntityDirection::LEFT},		//23
		{Vector3(130.5f, 0.f, 84.5f), EntityDirection::RIGHT},		//24
		{Vector3(110.5f, 0.f, 94.5f), EntityDirection::LEFT},		//25
		{Vector3(128.5f, 0.f, 102.5f), EntityDirection::DOWN},		//26
		{Vector3(143.5f, 0.f, 102.5f), EntityDirection::DOWN},		//27
		{Vector3(123.5f, 0.f, 118.5f), EntityDirection::LEFT},		//28
		{Vector3(139.5f, 0.f, 130.5f), EntityDirection::LEFT},		//29
		{Vector3(142.5f, 0.f, 143.5f), EntityDirection::LEFT},		//30

		{Vector3(121.5f, 0.f, 141.5f), EntityDirection::DOWN},		//31
		{Vector3(104.5f, 0.f, 122.5f), EntityDirection::RIGHT},		//32
		{Vector3(99.5f, 0.f, 138.5f), EntityDirection::LEFT},		//33
		{Vector3(75.5f, 0.f, 139.5f), EntityDirection::DOWN},		//34
		{Vector3(82.5f, 0.f, 123.5f), EntityDirection::DOWN},		//35
		{Vector3(49.5f, 0.f, 138.5f), EntityDirection::RIGHT},		//36
		{Vector3(55.5f, 0.f, 121.5f), EntityDirection::LEFT},		//37
		{Vector3(29.5f, 0.f, 131.5f), EntityDirection::LEFT},		//38
		{Vector3(8.5f, 0.f, 140.5f), EntityDirection::RIGHT},		//39
		{Vector3(12.5f, 0.f, 119.5f), EntityDirection::DOWN},		//40

		{Vector3(20.5f, 0.f, 100.5f), EntityDirection::DOWN},		//41
		{Vector3(33.5f, 0.f, 113.5f), EntityDirection::LEFT},		//42
		{Vector3(38.5f, 0.f, 88.5f), EntityDirection::RIGHT},		//43
		{Vector3(52.5f, 0.f, 101.5f), EntityDirection::DOWN},		//44
		{Vector3(56.5f, 0.f, 78.5f), EntityDirection::RIGHT},		//45
		{Vector3(68.5f, 0.f, 61.5f), EntityDirection::DOWN},		//46
		{Vector3(90.5f, 0.f, 63.5f), EntityDirection::LEFT},		//47
		{Vector3(112.5f, 0.f, 74.5f), EntityDirection::DOWN},		//48
		{Vector3(96.5f, 0.f, 79.5f), EntityDirection::LEFT},		//49
		{Vector3(96.5f, 0.f, 108.5f), EntityDirection::LEFT},		//50

		{Vector3(71.5f, 0.f, 110.5f), EntityDirection::RIGHT},		//51
		{Vector3(75.5f, 0.f, 93.5f), EntityDirection::DOWN},		//52
		{Vector3(15.5f, 0.f, 84.5f), EntityDirection::LEFT},		//53
	};

	m_guardData =
	{
		{Vector3(25.5f, 0.f, 30.5f), EntityDirection::DOWN},		//1
		{Vector3(43.5f, 0.f, 18.5f), EntityDirection::LEFT},		//2
		{Vector3(16.5f, 0.f, 52.5f), EntityDirection::UP},			//3
		{Vector3(10.5f, 0.f, 67.5f), EntityDirection::UP},			//4
		{Vector3(47.5f, 0.f, 81.5f), EntityDirection::LEFT},		//5

		{Vector3(5.5f, 0.f, 93.5f), EntityDirection::RIGHT},		//6
		{Vector3(41.5f, 0.f, 97.5f), EntityDirection::LEFT},		//7
		{Vector3(24.5f, 0.f, 111.5f), EntityDirection::LEFT},		//8
		{Vector3(8.5f, 0.f, 131.5f), EntityDirection::RIGHT},		//9
		{Vector3(34.5f, 0.f, 145.5f), EntityDirection::RIGHT},		//10

		{Vector3(46.5f, 0.f, 124.5f), EntityDirection::LEFT},		//11
		{Vector3(48.5f, 0.f, 38.5f), EntityDirection::RIGHT},		//12
		{Vector3(91.5f, 0.f, 29.5f), EntityDirection::LEFT},		//13
		{Vector3(113.5f, 0.f, 10.5f), EntityDirection::LEFT},		//14
		{Vector3(114.5f, 0.f, 35.5f), EntityDirection::UP},			//15

		{Vector3(122.5f, 0.f, 25.5f), EntityDirection::DOWN},		//16
		{Vector3(61.5f, 0.f, 54.5f), EntityDirection::LEFT},		//17
		{Vector3(53.5f, 0.f, 131.5f), EntityDirection::RIGHT},		//18
		{Vector3(64.5f, 0.f, 111.5f), EntityDirection::LEFT},		//19
		{Vector3(69.5f, 0.f, 147.5f), EntityDirection::LEFT},		//20

		{Vector3(82.5f, 0.f, 115.5f), EntityDirection::RIGHT},		//21
		{Vector3(78.5f, 0.f, 85.5f), EntityDirection::LEFT},		//22
		{Vector3(70.5f, 0.f, 68.5f), EntityDirection::RIGHT},		//23
		{Vector3(88.5f, 0.f, 137.5f), EntityDirection::UP},			//24
		{Vector3(99.5f, 0.f, 101.5f), EntityDirection::LEFT},		//25

		{Vector3(100.5f, 0.f, 64.5f), EntityDirection::RIGHT},		//26
		{Vector3(93.5f, 0.f, 53.5f), EntityDirection::LEFT},		//27
		{Vector3(103.5f, 0.f, 132.5f), EntityDirection::LEFT},		//28
		{Vector3(114.5f, 0.f, 148.5f), EntityDirection::RIGHT},		//29
		{Vector3(132.5f, 0.f, 131.5f), EntityDirection::LEFT},		//30

		{Vector3(122.5f, 0.f, 77.5f), EntityDirection::RIGHT},		//21
		{Vector3(124.5f, 0.f, 53.5f), EntityDirection::UP},			//22
		{Vector3(139.5f, 0.f, 112.5f), EntityDirection::LEFT},		//23
		{Vector3(137.5f, 0.f, 94.5f), EntityDirection::LEFT},		//24
	};
}

void STAGE1::Start()
{
	m_cameraManager.lock()->GetMainCamera()->SetPosition(Vector3(0, 21, -28));
	m_cameraManager.lock()->GetMainCamera()->AddLookRadian(Vector2(0, -1.123f));

	/// ���� ����
	Scene::SetSimulating(true);
	Scene::SetPrevSimulating(true);

	/// floor
	auto floor = std::make_shared<Entity>("SampleFloor");
	auto floorRenderer = floor->AddComponent<MeshRenderer>("FloorRenderer");
	auto floorMesh = floor->AddComponent<MeshFilter>("FloorMesh");
	floor->AddComponent<PlaneCollider>();
	floor->GetComponent<Transform>()->SetLocalScale(Vector3(10.0f, 1.f, 10.f));
	Scene::AddEntity(floor);
	floorMesh->SetModelKey(GraphicsTransfer::ModelKey::Floor);
	floorMesh->m_pbrSet.useBaseColorMap = false;
	floorMesh->m_pbrSet.SetBaseColor({ 201, 148, 130, 255 });

	floorMesh->m_cullingOff = true; // �ٴ��� �ø����� �ʴ´�.

	/*///Grid
	auto gridEntity1 = std::make_shared<Grid>();
	Scene::AddEntity(gridEntity1);*/


	///GameManager
	m_gameManager = std::make_shared<Entity>("GameManager");
	Scene::AddEntity(m_gameManager);
	auto manager = m_gameManager->AddComponent<GameManager>();

	// ���� �޴����� �ڽ����� �߰� -> �ð�
	auto timemgr = std::make_shared<Entity>("TimeUI");
	Scene::AddEntity(timemgr);
	timemgr->GetComponent<Transform>()->SetParent(m_gameManager->GetComponent<Transform>());
	timemgr->AddComponent<SunLight>();
	auto light = timemgr->AddComponent<DirectionalLight>();
	light->SetIntensity(0.14);
	light->SetAmbient255(Vector4(255, 255, 255, 247));
	timemgr->AddComponent<TimerUI>();
	timemgr->AddComponent<TextRender>();
	timemgr->AddComponent<MeshFilter>();
	timemgr->GetComponent<MeshFilter>()->SetModelKey(GraphicsTransfer::ModelKey::UI_Timer);
	timemgr->AddComponent<UIRenderer>();

	m_gameManager->AddComponent<SphereCollider>();
	m_gameManager->GetComponent<SphereCollider>()->SetRadius(3.f);
	m_gameManager->GetComponent<SphereCollider>()->SetDisableGravity(true);
	m_gameManager->GetComponent<SphereCollider>()->SetIsTrigger(true);
	m_gameManager->GetComponent<Transform>()->SetWorldPosition(Vector3(75, 0, -1));

	///Player
	//�÷��̾�
	auto PlayerEntity = std::make_shared<Entity>("Player");
	Scene::AddEntity(PlayerEntity);
	auto playerRenderer = PlayerEntity->AddComponent<MeshRenderer>("Player");
	auto playerMesh = PlayerEntity->AddComponent<MeshFilter>("PlayerMesh");
	PlayerEntity->GetComponent<MeshFilter>()->SetModelKey(GraphicsTransfer::ModelKey::Player);
	auto transform = PlayerEntity->GetComponent<Transform>();
	transform->AddPosition(Vector3(70.f, 0.0f, 5.f));   m_cameraManager.lock()->GetMainCamera()->SetPosition(Vector3(74, 30, -10));
	PlayerEntity->AddComponent<PlayerMoveScript>();
	PlayerEntity->AddComponent<PlayerFSM>();
	PlayerEntity->AddComponent<RayCaster>();
	PlayerEntity->GetComponent<RayCaster>()->SetUnitDirectionOffset(Vector3(0, 0, 1));
	PlayerEntity->GetComponent<RayCaster>()->SetStartPosOffset(Vector3(0, 0, 0.5f));
	PlayerEntity->GetComponent<RayCaster>()->SetDistance(5);
	PlayerEntity->AddComponent<CapsuleCollider>();
	auto collider = PlayerEntity->GetComponent<CapsuleCollider>();
	PlayerEntity->SetLayerCollision(LayerCollision::Player);  ///----------------------------------------------------------- ���̾� ����
	PlayerEntity->AddComponent<PointLight>()->SetPosOffset(Vector3(0,2.5,-0.6));
	PlayerEntity->AddComponent<TorchLight>();


	collider->FreezeRotation(true, true, true);
	collider->SetOffset(Vector3(0.f, 1.00f, 0.f));
	collider->SetSize(0.5f, 0.5f);
	collider->SetMaterial(0.5, 0.5, 0.f);

	PlayerEntity->AddComponent<PetitCamera>();
	PlayerEntity->GetComponent<PetitCamera>()->SetTarget(PlayerEntity);

	manager->SetPlayer(PlayerEntity);

	/// �÷��̾��� �ڽ����� ScoreUI �߰�
	auto scoreUI = std::make_shared<Entity>("ScoreUI");
	Scene::AddEntity(scoreUI);
	scoreUI->GetComponent<Transform>()->SetParent(PlayerEntity->GetComponent<Transform>());
	scoreUI->AddComponent<ScoreUI>();
	scoreUI->AddComponent<UIRenderer>();
	scoreUI->AddComponent<MeshFilter>();
	scoreUI->GetComponent<MeshFilter>()->SetModelKey(GraphicsTransfer::ModelKey::UI_Score);


	/// �÷��̾� ������ ���� ��������
	auto aimingUI = std::make_shared<UIGauge>();
	Scene::AddEntity(aimingUI);
	aimingUI->SetName("AimmingUI");
	aimingUI->GetComponent<Transform>()->SetWorldPosition({ 0,0,0 });
	aimingUI->GetComponent<Transform>()->SetLocalScale({ 0.05,0.05,0.05 });
	aimingUI->AddComponent<UITestScript>(UIType::Jiwon);
	//aimingUI->GetComponent<UITestScript>()->SetDuration(0.0f);
	aimingUI->SetRender(true);
	aimingUI->GetComponent<UITestScript>()->SetPlayerPointer(PlayerEntity); /// �÷��̾� ������ ����



	//-----------------

	CreateDeco(DecoType::Flag, 74, 1);
	CreateDeco(DecoType::Lamp, 79.2, 10.1);
	CreateDeco(DecoType::Lamp, 100.8, 18.9);
	CreateDeco(DecoType::Lamp, 82.8, 31.8);
	CreateDeco(DecoType::Lamp, 101.4, 37.6);
	CreateDeco(DecoType::Lamp, 120.1, 42.9);
	CreateDeco(DecoType::Lamp, 129.3, 32.8);
	CreateDeco(DecoType::Lamp, 130.6, 56.8);
	CreateDeco(DecoType::Lamp, 134.7, 78.8);
	CreateDeco(DecoType::Lamp, 122.5, 104.8);
	CreateDeco(DecoType::Lamp, 128.5, 116.8);
	CreateDeco(DecoType::Lamp, 99.1, 120.4);
	CreateDeco(DecoType::Lamp, 77.9, 118.2);
	CreateDeco(DecoType::Lamp, 57.3, 132.2);
	CreateDeco(DecoType::Lamp, 24.5, 123.8);
	CreateDeco(DecoType::Lamp, 12.1, 134.87);
	CreateDeco(DecoType::Lamp, 15.3, 95.97);
	CreateDeco(DecoType::Lamp, 32.4, 90.44);
	CreateDeco(DecoType::Lamp, 21.6, 66.46);
	CreateDeco(DecoType::Lamp, 20.4, 51.55);
	CreateDeco(DecoType::Lamp, 37.0, 54.86);
	CreateDeco(DecoType::Lamp, 55.7, 23.06);
	CreateDeco(DecoType::Lamp, 12.36, 8.5);
	CreateDeco(DecoType::Lamp, 44.7, 70.5);
	CreateDeco(DecoType::Lamp, 48.9, 97.0);
	CreateDeco(DecoType::Lamp, 92.7, 143.5);
	CreateDeco(DecoType::Lamp, 134.3, 137.6);
	CreateDeco(DecoType::Lamp, 10.0, 24.37);
	CreateDeco(DecoType::Lamp, 59.5, 64.6);
	CreateDeco(DecoType::Lamp, 84.5, 99.9);
	CreateDeco(DecoType::Lamp, 119.5, 69.5);
	CreateDeco(DecoType::Lamp, 94.5, 57.10);
	CreateDeco(DecoType::Lamp, 100.5, 69.8);

	CreateDeco(DecoType::Candle1, 57.7, 11.96, 0, 0.5);
	CreateDeco(DecoType::Candle1, 57.7, 11.96, 0, 0.7);
	CreateDeco(DecoType::Candle1, 42.03, 26.28, 0, 0.5);
	CreateDeco(DecoType::Candle1, 38.5, 11.15, 0, 0.5);
	CreateDeco(DecoType::Candle1, 20.60, 16.56, 0, 0.6);
	CreateDeco(DecoType::Candle1, 18.08, 14.65, 0, 0.3);
	CreateDeco(DecoType::Candle2, 27.44, 33.53, 0, 0.8);
	CreateDeco(DecoType::Candle2, 35.76, 109.82, 0, 1.0);
	CreateDeco(DecoType::Candle1, 40.24, 126.7, 0, 1.0);
	CreateDeco(DecoType::Candle2, 72.34, 136.57, 0, 0.4);
	CreateDeco(DecoType::Candle2, 117.5, 135.71, 0, 0.6);
	CreateDeco(DecoType::Candle1, 127.67, 127.03, 0, 1.0);
	CreateDeco(DecoType::Candle2, 139.17, 97.83, 0, 1.0);
	CreateDeco(DecoType::Candle2, 32.13, 5.3, 0, 0.5);
	CreateDeco(DecoType::Candle2, 9.86, 51.64, 0, 0.6);
	CreateDeco(DecoType::Candle1, 12.76, 79.8, 0, 1.0);
	CreateDeco(DecoType::Candle1, 51.1, 80.1, 0, 0.7);
	CreateDeco(DecoType::Candle1, 70.97, 89.07, 0, 0.5);
	CreateDeco(DecoType::Candle1, 67.97, 105.59, 0, 0.5);
	CreateDeco(DecoType::Candle1, 52.97, 115.34, 0, 0.6);
	CreateDeco(DecoType::Candle1, 55.35, 133.34, 0, 0.25);
	CreateDeco(DecoType::Candle1, 71.18, 137.34, 0, 0.2);
	CreateDeco(DecoType::Candle1, 85.09, 127.58, 0, 0.2);
	CreateDeco(DecoType::Candle1, 103.21, 139.58, 0, 0.3);
	CreateDeco(DecoType::Candle1, 76.65, 71.58, 0, 0.2);
	CreateDeco(DecoType::Candle1, 78.21, 73.02, 0, 0.3);
	CreateDeco(DecoType::Candle2, 71.02, 70.44, 0, 0.4);
	CreateDeco(DecoType::Candle2, 69.73, 75.30, 0, 0.2);
	CreateDeco(DecoType::Candle2, 76.9, 76.76, 0, 0.2);
	CreateDeco(DecoType::Candle2, 106.9, 102.76, 0, 0.5);
	CreateDeco(DecoType::Candle2, 118.64, 87.4, 0, 0.65);
	CreateDeco(DecoType::Candle2, 134.07, 87.13, 0, 0.65);
	CreateDeco(DecoType::Candle2, 117.07, 16.27, 0, 0.5);
	CreateDeco(DecoType::Candle2, 129.86, 15.14, 0, 0.6);
	CreateDeco(DecoType::Candle2, 123.86, 6.8, 0, 0.4);
	CreateDeco(DecoType::Candle2, 93.86, 75.8, 0, 0.6);
	CreateDeco(DecoType::Candle2, 94.7, 86.6, 0, 0.6);

	CreateDeco(DecoType::Candy, 61.573, 24.624, -28.058);
	CreateDeco(DecoType::Table, 54.662, 24.659, 0.712);
	CreateDeco(DecoType::Grass, 91.762, 26.117, -67.458);
	CreateDeco(DecoType::Grass, 90.415, 24.921, -45.353);
	CreateDeco(DecoType::Grass, 97.377, 23.567, -80.755);
	CreateDeco(DecoType::Table, 124.353, 7.662, -180);
	CreateDeco(DecoType::Flag, 122.101, 1.160, 22.402);
	CreateDeco(DecoType::Candy, 118.294, 2.098, -45.443);
	CreateDeco(DecoType::Grass, 124.293, -1.652, 31.663);
	CreateDeco(DecoType::Grass, 128.726, 0.249, 95.166);
	CreateDeco(DecoType::Grass, 116.838, 15.953, -120.971);
	CreateDeco(DecoType::Grass, 116.838, 12.384, -178.763);
	CreateDeco(DecoType::Grass, 115.428, 10.220, -89.013);
	CreateDeco(DecoType::Candy, 133.210, 15.108, 17.924);
	CreateDeco(DecoType::Grass, 131.366, 15.541, -28.364);
	CreateDeco(DecoType::Grass, 129.306, 14.456, -2.813);
	CreateDeco(DecoType::Tree1, 126.487, 34.737, -35.137, 1.5);
	CreateDeco(DecoType::Tree1, 129.956, 22.271, 74.022, 1.5);
	CreateDeco(DecoType::Tree1, 132.016, 24.006, 174.331);
	CreateDeco(DecoType::Tree1, 132.016, 11.544, 123.923);
	CreateDeco(DecoType::Grass, 130.822, 10.676, -91.141);
	CreateDeco(DecoType::Grass, 133.641, 6.992, -0.088);
	CreateDeco(DecoType::Grass, 137.002, 3.632, -5.787);
	CreateDeco(DecoType::Tree1, 140.688, 7.864, 179.912);
	CreateDeco(DecoType::Grass, 139.388, 7.430, -132.013);
	CreateDeco(DecoType::Grass, 141.449, 0, 922, 96.165);
	CreateDeco(DecoType::Grass, 137.004, 27.157, 130.748);
	CreateDeco(DecoType::Grass, 141.018, 28.680, 63.416);
	CreateDeco(DecoType::Grass, 133.539, 40.164, 3.161);
	CreateDeco(DecoType::Tree1, 133.430, 50.038, -129.182, 1.5);
	CreateDeco(DecoType::Tree1, 135.492, 52.852, 126.178, 1.2);
	CreateDeco(DecoType::Tree1, 123.029, 62.393, -82.896, 1.2);
	CreateDeco(DecoType::Tree1, 80.421, 15.997, 53.766, 1.2);
	CreateDeco(DecoType::Grass, 73.486, 6.888, 148.800, 1.2);
	CreateDeco(DecoType::Grass, 74.674, 7.646, 17.051);
	CreateDeco(DecoType::Tree1, 69.683, 6.240, 56.031, 1.5);
	CreateDeco(DecoType::Tree1, 81.285, 17.627, 70.313, 1.5);
	CreateDeco(DecoType::Tree1, 87.788, 41.256, 87.055, 1.5);
	CreateDeco(DecoType::Tree1, 84.311, 8.193, -23.080, 1.5);
	CreateDeco(DecoType::Tree1, 124.8, 143.0);
	CreateDeco(DecoType::Tree2, 124.2, 138.6);
	CreateDeco(DecoType::Tree1, 136.0, 125.3);
	CreateDeco(DecoType::Tree2, 140.1, 121.4);
	CreateDeco(DecoType::Tree1, 137.3, 119.5);

	CreateDeco(DecoType::Tree2, 140.3, 116.4);
	CreateDeco(DecoType::Tree1, 111.5, 110.6);
	CreateDeco(DecoType::Tree2, 120.7, 121.6);
	CreateDeco(DecoType::Tree1, 116.3, 129.4);
	CreateDeco(DecoType::Tree2, 116.9, 145.6);

	CreateDeco(DecoType::Tree1, 104.8, 148.5);
	CreateDeco(DecoType::Tree2, 102.7, 146.3);
	CreateDeco(DecoType::Tree1, 101.2, 142.5);
	CreateDeco(DecoType::Tree2, 101.2, 123.8);
	CreateDeco(DecoType::Tree1, 102.5, 119.0);

	CreateDeco(DecoType::Tree2, 72.6, 137.4);
	CreateDeco(DecoType::Tree1, 53.0, 140.6);
	CreateDeco(DecoType::Tree2, 54.7, 145.0);
	CreateDeco(DecoType::Tree1, 50.4, 143.9);
	CreateDeco(DecoType::Tree2, 74.1, 113.3);

	CreateDeco(DecoType::Tree1, 94.3, 110.2);
	CreateDeco(DecoType::Tree2, 112.3, 91.2);
	CreateDeco(DecoType::Tree1, 110.0, 91.2);
	CreateDeco(DecoType::Tree2, 134.3, 87.7);
	CreateDeco(DecoType::Tree1, 147.3, 85.3);

	CreateDeco(DecoType::Tree2, 140.4, 71.4);
	CreateDeco(DecoType::Tree1, 128.7, 81.7);
	CreateDeco(DecoType::Tree2, 127.9, 84.9);
	CreateDeco(DecoType::Tree1, 115.2, 72.8);
	CreateDeco(DecoType::Tree2, 114.9, 78.1);

	CreateDeco(DecoType::Tree1, 97.7, 76.3);
	CreateDeco(DecoType::Tree2, 99.5, 79.0);
	CreateDeco(DecoType::Tree1, 92.9, 81.2);
	CreateDeco(DecoType::Tree2, 79.5, 92.8);
	CreateDeco(DecoType::Tree1, 79.4, 119.8);
	CreateDeco(DecoType::Tree1, 86.154, 10.894, 24.625, 1.2);
	CreateDeco(DecoType::Grass, 87.236, 4.066, -5.448, 1.2);
	CreateDeco(DecoType::Grass, 88.646, 2.014, 114.404);
	CreateDeco(DecoType::Grass, 96.992, 12.854, 47.052);
	CreateDeco(DecoType::Tree1, 103.286, 31.935, 40.135, 1.5);
	CreateDeco(DecoType::Grass, 103.503, 23.916, 89.293, 1.5);
	CreateDeco(DecoType::Grass, 105.237, 22.183, 102.278, 1.3);
	CreateDeco(DecoType::Grass, 112.933, 28.038, 47.641, 1.5);
	CreateDeco(DecoType::Tree1, 128.876, 55.353, 46.112, 1.5);
	CreateDeco(DecoType::Tree1, 141.011, 39.095, 40.477, 1.5);
	CreateDeco(DecoType::Tree1, 87.560, 11.559, 11.234, 1.5);
	CreateDeco(DecoType::Grass, 89.407, 9.180, 110.586, 1.2);
	CreateDeco(DecoType::Grass, 91.357, 7.238, 90.942, 1.2);
	CreateDeco(DecoType::Tree1, 80.079, -0.779, 90.595, 1.5);
	CreateDeco(DecoType::Tree1, 82.571, -3.166, 123.215, 1.5);
	CreateDeco(DecoType::Grass, 85.173, 1.705, 82.624, 1.2);
	CreateDeco(DecoType::Table, 86.6, 117.8, -48.0);
	CreateDeco(DecoType::Table, 114.0, 109.1, -48.0);
	CreateDeco(DecoType::Table, 124.4, 100.8, -80.0);
	CreateDeco(DecoType::Table, 145.2, 87.3, -9.0);
	CreateDeco(DecoType::Table, 98.2, 82.5, 20.0);
	CreateDeco(DecoType::Table, 79.9, 88.3, -19.0);
	CreateDeco(DecoType::Candy, 107.2, 123.5, -19.0);
	CreateDeco(DecoType::Tree1, 98.935, -1.212, 64.274, 1.5);
	CreateDeco(DecoType::Tree1, 108.690, 5.943, -119.907, 1.5);
	CreateDeco(DecoType::Tree1, 106.739, -1.389, 163.583, 1.5);
	CreateDeco(DecoType::Candy, 63, 23.9);
	CreateDeco(DecoType::Candle2, 11, 16);
	CreateDeco(DecoType::Table, 19, 51);
	CreateDeco(DecoType::Table, 38, 127);
	CreateDeco(DecoType::Tree1, 10, 75);
	CreateDeco(DecoType::Tree1, 10, 75);
	CreateDeco(DecoType::Tree1, 8, 101);
	CreateDeco(DecoType::Tree2, 4, 119);
	CreateDeco(DecoType::Tree2, 16, 131);
	CreateDeco(DecoType::Tree2, 21, 141);
	CreateDeco(DecoType::Tree2, 38, 138);
	CreateDeco(DecoType::Tree2, 53, 32);
	CreateDeco(DecoType::Table, 75, 50);
	CreateDeco(DecoType::Table, 75, 50);
	CreateDeco(DecoType::Table, 29, 91);
	CreateDeco(DecoType::Table, 5, 111);
	CreateDeco(DecoType::Table, 12, 91);
	CreateDeco(DecoType::Candy, 60, 13);
	CreateDeco(DecoType::Tree2, 43, 4);
	CreateDeco(DecoType::Tree2, 30, 15);
	CreateDeco(DecoType::Tree2, 30, 23);
	CreateDeco(DecoType::Tree2, 17, 27);
	CreateDeco(DecoType::Tree2, 7, 26);
	CreateDeco(DecoType::Tree2, 3, 32);
	CreateDeco(DecoType::Tree2, 6, 38);
	CreateDeco(DecoType::Tree2, 0.2, 44);
	CreateDeco(DecoType::Tree2, 3, 43);
	CreateDeco(DecoType::Tree2, 5, 40);
	CreateDeco(DecoType::Tree2, 4, 44);
	CreateDeco(DecoType::Tree2, 4, 44);
	CreateDeco(DecoType::Tree2, 1, 40);
	CreateDeco(DecoType::Tree2, 0, 37);
	CreateDeco(DecoType::Tree2, 1.6, 35);
	CreateDeco(DecoType::Tree2, 3.7, 33);
	CreateDeco(DecoType::Tree2, 6, 34);
	CreateDeco(DecoType::Tree2, 5, 31);
	CreateDeco(DecoType::Tree2, 1, 29);
	CreateDeco(DecoType::Tree2, 0.4, 28);
	CreateDeco(DecoType::Tree2, 2.8, 26);
	CreateDeco(DecoType::Tree2, 4, 25);
	CreateDeco(DecoType::Tree2, 0.7, 25);
	CreateDeco(DecoType::Tree2, -0.4, 22);
	CreateDeco(DecoType::Tree2, 1.2, 20);
	CreateDeco(DecoType::Tree2, 3, 19);
	CreateDeco(DecoType::Tree2, 4, 21);
	CreateDeco(DecoType::Tree2, 5, 19);
	CreateDeco(DecoType::Tree2, 4, 17);
	CreateDeco(DecoType::Tree2, 6, 19);
	CreateDeco(DecoType::Tree2, 7, 17);
	CreateDeco(DecoType::Tree2, 0.1, 15);
	CreateDeco(DecoType::Tree2, 1.9, 16);
	CreateDeco(DecoType::Tree2, 0.9, 8);
	CreateDeco(DecoType::Tree2, -0.4, 4.1);
	CreateDeco(DecoType::Tree2, 0.7, -1.6);
	CreateDeco(DecoType::Tree2, 0.7, -3.8);
	CreateDeco(DecoType::Tree2, 3.8, -4);
	CreateDeco(DecoType::Tree2, 6, -3.4);
	CreateDeco(DecoType::Tree2, 9, -3.4);
	CreateDeco(DecoType::Tree2, 0.9, 12.7);
	CreateDeco(DecoType::Tree2, 3.2, 12.7);
	CreateDeco(DecoType::Tree2, 5, 13);
	CreateDeco(DecoType::Tree2, 6.5, 11);
	CreateDeco(DecoType::Tree2, 2.6, 10);
	CreateDeco(DecoType::Tree2, -0.6, 6.4);
	CreateDeco(DecoType::Tree2, -0.6, 6.4);
	CreateDeco(DecoType::Tree2, -1.2, 1.5);
	CreateDeco(DecoType::Tree2, 2.1, 3.6);
	CreateDeco(DecoType::Tree2, 3.4, 10.6);
	CreateDeco(DecoType::Tree2, 7, 10);
	CreateDeco(DecoType::Tree2, 5, 13.2);
	CreateDeco(DecoType::Tree2, 7, 10);
	CreateDeco(DecoType::Tree2, 3, -2);
	CreateDeco(DecoType::Tree2, 3, -2);
	CreateDeco(DecoType::Tree2, 0.5, 45);
	CreateDeco(DecoType::Tree2, 2, 47);
	CreateDeco(DecoType::Tree2, 0.5, 48);
	CreateDeco(DecoType::Tree2, 0.5, 48);
	CreateDeco(DecoType::Tree2, 0.1, 50);
	CreateDeco(DecoType::Tree2, -0.9, 53);
	CreateDeco(DecoType::Tree2, 0.3, 50);
	CreateDeco(DecoType::Tree2, 0.3, 53);
	CreateDeco(DecoType::Tree2, 0.0, 57);
	CreateDeco(DecoType::Tree2, 1.2, 58);
	CreateDeco(DecoType::Tree2, -0.5, 61);
	CreateDeco(DecoType::Tree2, 2.0, 61);
	CreateDeco(DecoType::Tree2, -0.8, 64.3);
	CreateDeco(DecoType::Tree2, 2, 62);
	CreateDeco(DecoType::Tree2, 1.3, 64);
	CreateDeco(DecoType::Tree2, -0.3, 66);
	CreateDeco(DecoType::Tree2, 1.5, 68);
	CreateDeco(DecoType::Tree2, -0.3, 70);
	CreateDeco(DecoType::Tree2, -0.6, 73);
	CreateDeco(DecoType::Tree2, 1.6, 74);
	CreateDeco(DecoType::Tree2, 1.6, 76);
	CreateDeco(DecoType::Tree2, 0, 79);
	CreateDeco(DecoType::Tree2, 0.3, 81);
	CreateDeco(DecoType::Tree2, 1.4, 82);
	CreateDeco(DecoType::Tree2, 1.4, 82);
	CreateDeco(DecoType::Tree2, 1.4, 84);
	CreateDeco(DecoType::Tree2, 1.8, 84);
	CreateDeco(DecoType::Tree2, -0.5, 86);
	CreateDeco(DecoType::Tree2, 3.6, 82);
	CreateDeco(DecoType::Tree2, 5.1, 80);
	CreateDeco(DecoType::Tree2, 2.8, 78);
	CreateDeco(DecoType::Tree2, 2.8, 75);
	CreateDeco(DecoType::Tree2, 0.04, 87);
	CreateDeco(DecoType::Tree2, 0.04, 90);
	CreateDeco(DecoType::Tree2, -1.1, 92);
	CreateDeco(DecoType::Tree2, -0.3, 95);
	CreateDeco(DecoType::Tree2, -0.1, 97);
	CreateDeco(DecoType::Tree2, 0.1, 99);
	CreateDeco(DecoType::Tree2, 0.4, 100);
	CreateDeco(DecoType::Tree2, 0.4, 100);
	CreateDeco(DecoType::Tree2, 0.4, 102);
	CreateDeco(DecoType::Tree2, -0.5, 111);
	CreateDeco(DecoType::Tree2, -0.5, 111);
	CreateDeco(DecoType::Tree2, -0.5, 113);
	CreateDeco(DecoType::Tree2, -0.5, 115);
	CreateDeco(DecoType::Tree2, -0.5, 117);
	CreateDeco(DecoType::Tree2, -0.5, 118);
	CreateDeco(DecoType::Tree2, -0.5, 120);
	CreateDeco(DecoType::Tree2, -0.5, 123);
	CreateDeco(DecoType::Tree2, -0.5, 125);
	CreateDeco(DecoType::Tree2, -0.5, 127);
	CreateDeco(DecoType::Tree2, -0.5, 129);
	CreateDeco(DecoType::Tree2, -0.5, 131);
	CreateDeco(DecoType::Tree2, -0.5, 133);
	CreateDeco(DecoType::Tree2, -0.5, 135);
	CreateDeco(DecoType::Tree2, -0.5, 137);
	CreateDeco(DecoType::Tree2, -0.5, 139);
	CreateDeco(DecoType::Tree2, -0.5, 141);
	CreateDeco(DecoType::Tree2, -0.5, 143);
	CreateDeco(DecoType::Tree2, -0.5, 145);
	CreateDeco(DecoType::Tree2, -0.3, 108);
	CreateDeco(DecoType::Tree2, 0.1, 106);
	CreateDeco(DecoType::Tree2, 2.2, 104);
	CreateDeco(DecoType::Tree2, 2.2, 103);
	CreateDeco(DecoType::Tree2, 2.2, 102);
	CreateDeco(DecoType::Tree2, 4, 102);
	CreateDeco(DecoType::Tree2, 3, 100);
	CreateDeco(DecoType::Tree2, 3, 97);
	CreateDeco(DecoType::Tree2, 3.3, 95);
	CreateDeco(DecoType::Tree2, 3.1, 93);
	CreateDeco(DecoType::Tree2, 2.1, 91);
	CreateDeco(DecoType::Tree2, 1.8, 87);
	CreateDeco(DecoType::Tree2, 1.1, 115);
	CreateDeco(DecoType::Tree2, 2.1, 118);
	CreateDeco(DecoType::Tree2, 2.3, 122);
	CreateDeco(DecoType::Tree2, 4, 125);
	CreateDeco(DecoType::Tree2, 2.6, 126);
	CreateDeco(DecoType::Tree2, 2.0, 127);
	CreateDeco(DecoType::Tree2, 3.4, 125);
	CreateDeco(DecoType::Tree2, 2.4, 128);
	CreateDeco(DecoType::Tree2, 1.6, 130);
	CreateDeco(DecoType::Tree2, 1.8, 130);
	CreateDeco(DecoType::Tree2, 3.4, 128);
	CreateDeco(DecoType::Tree2, 4.4, 126);
	CreateDeco(DecoType::Tree2, 1.3, 132);
	CreateDeco(DecoType::Tree2, -2.3, 132);
	CreateDeco(DecoType::Tree2, -1.7, 136);
	CreateDeco(DecoType::Tree2, -3.9, 139);
	CreateDeco(DecoType::Tree2, 2.2, 137);
	CreateDeco(DecoType::Tree2, 2.2, 137);
	CreateDeco(DecoType::Tree2, 2.4, 139);
	CreateDeco(DecoType::Tree2, 3.4, 135);
	CreateDeco(DecoType::Tree2, -2.6, 140);
	CreateDeco(DecoType::Tree2, 5, 123);
	CreateDeco(DecoType::Tree2, -4, 143);
	CreateDeco(DecoType::Tree2, 1.7, 108);
	CreateDeco(DecoType::Tree2, 3.9, 165);
	CreateDeco(DecoType::Tree2, 2.6, 37.3);
	//----------------


	/// �̴ϸ� ������
	auto miniMapIcon = std::make_shared<UIMiniMapIcon>();
	miniMapIcon->GetComponent<Transform>()->SetWorldPosition({ -830,-430,0 });
	miniMapIcon->GetComponent<Transform>()->SetWorldScale({ 1,1,1 });
	miniMapIcon->AddComponent<UITestScript>(UIType::STATIC);
	Scene::AddEntity(miniMapIcon);

	// ���� �湮 ����Ʈ
	auto eatSpotList = std::make_shared<Entity>("EatSpotList");
	eatSpotList->AddComponent<UIRenderer>();
	Scene::AddEntity(eatSpotList);
	eatSpotList->AddComponent<MeshFilter>()->SetModelKey(ModelKey::UI_EatSpot);

	/// UI Hungry
	auto HungryUI = std::make_shared<UIHungry>();
	Scene::AddEntity(HungryUI);
	HungryUI->GetComponent<Transform>()->SetWorldPosition({ 830,-400,0 });
	HungryUI->GetComponent<Transform>()->SetWorldScale({ 1,1,1 });
	HungryUI->AddComponent<UITestScript>(UIType::HUNGRY);
	HungryUI->AddComponent<TextRender>();
	auto hungryPointer = PlayerEntity->GetComponent<PlayerMoveScript>()->GetHungerPointer();
	HungryUI->GetComponent<UITestScript>()->SetHungry(hungryPointer);

	/// UI ��ų 
	auto SkillUI = std::make_shared<UISkill>();
	Scene::AddEntity(SkillUI);
	SkillUI->GetComponent<Transform>()->SetWorldPosition({ 850,-50,0 });
	SkillUI->GetComponent<Transform>()->SetWorldScale({ 1,1,1 });
	SkillUI->AddComponent<TextRender>();
	SkillUI->AddComponent<UITestScript>(UIType::SKILL);
	SkillUI->GetComponent<UITestScript>()->SetPlayerPointer(PlayerEntity);


	///���� �����
	int(*grid)[151] = m_resourceManager.lock()->GetMapInfo();
	int(*direction)[151] = m_resourceManager.lock()->GetDirData();
	int(*minigame)[151] = m_resourceManager.lock()->GetGameData();

	/// �÷��̾ �������� ���� ��
	{
		// �Ʒ�
		auto bottomWall = std::make_shared<Entity>("bottomWall");
		Scene::AddEntity(bottomWall);
		bottomWall->GetComponent<Transform>()->SetLocalPosition(Vector3(80, 1, -5));
		auto bwc = bottomWall->AddComponent<BoxCollider>();
		bwc->SetSize(Vector3(200, 2, 1));
		bwc->SetBodyType(BodyType::Static);

		// ��
		auto topWall = std::make_shared<Entity>("topWall");
		Scene::AddEntity(topWall);
		topWall->GetComponent<Transform>()->SetLocalPosition(Vector3(75, 1, 150));
		auto twc = topWall->AddComponent<BoxCollider>();
		twc->SetSize(Vector3(200, 2, 1));
		twc->SetBodyType(BodyType::Static);

		// ��
		auto leftWall = std::make_shared<Entity>("leftWall");
		Scene::AddEntity(leftWall);
		leftWall->GetComponent<Transform>()->SetLocalPosition(Vector3(-1, 1, 80));
		auto lwc = leftWall->AddComponent<BoxCollider>();
		lwc->SetSize(Vector3(1, 2, 200));
		lwc->SetBodyType(BodyType::Static);

		// ��
		auto rightWall = std::make_shared<Entity>("rightWall");
		Scene::AddEntity(rightWall);
		rightWall->GetComponent<Transform>()->SetLocalPosition(Vector3(150, 1, 80));
		auto rwc = rightWall->AddComponent<BoxCollider>();
		rwc->SetSize(Vector3(1, 2, 200));
		rwc->SetBodyType(BodyType::Static);
	}

	//Wall
	for (int i = 0; i < 150; i++)
	{
		for (int j = 0; j < 150; j++)
		{
			CreateMap(grid[i][j], j, i, direction[i][j], minigame[i][j]);
		}
	}
	// UI ���������� ������ ���������� �� �ڷ� ���ϴ�
	for (int i = 0; i < 150; i++)
	{
		for (int j = 0; j < 150; j++)
		{
			CreateStoreMap(grid[i][j], j, i, direction[i][j], minigame[i][j]);
		}
	}

	/// ����
	SoundManager::GetInstance()->StopAllBGM();
	SoundManager::GetInstance()->ResumeBGM("InGame_Default.wav");
	SoundManager::GetInstance()->PlayBGM("InGame_Default.wav");

	/// �̴ϸ�(��Ű)
	std::shared_ptr<Entity> minimap = std::make_shared<UIMinimap>();
	minimap->SetName("Minimap");
	minimap->GetComponent<Transform>()->SetWorldPosition({ 0,0,0 });
	minimap->AddComponent<UITestScript>(UIType::MINIMAP);
	Scene::AddEntity(minimap);
	minimap->SetRender(false);

	// �̴ϸ� X��ư
	auto minimapClose = std::make_shared<UIMinimapCurPos>();
	minimapClose->SetName("MinimapCloseButton");
	minimapClose->GetComponent<Transform>()->SetWorldPosition({ 488,190,0 });
	minimapClose->AddComponent<UITestScript>(UIType::MINIMAPCURPOS);
	Scene::AddEntity(minimapClose);
	minimapClose->SetRender(false);




	// ESC ������ �� �� �˾� UI ---------------------- ���� �ڿ� �߰��ؾ� �մϴ�
	auto popUp = std::make_shared<Entity>("PopUpUI");
	Scene::AddEntity(popUp);
	popUp->AddComponent<PopUpUI>();
	popUp->AddComponent<UIRenderer>();
	popUp->AddComponent<MeshFilter>();
	popUp->GetComponent<MeshFilter>()->SetModelKey(GraphicsTransfer::ModelKey::UI_IngamePopUp);


	/// fadeIN/OUT   ------------ ���� ���� �ڿ�
	auto BlackUI = std::make_shared<UIBlack>();
	Scene::AddEntity(BlackUI);
	BlackUI->GetComponent<Transform>()->SetWorldPosition({ 0,0,0 });
	BlackUI->GetComponent<Transform>()->SetWorldScale({ 1,1,1 });
	BlackUI->AddComponent<UITestScript>(UIType::FADE);

	Scene::Start();

	if (m_tableScripts.size() == m_shopkeeperFSMs.size())
	{
		for (int i = 0; i < m_tableScripts.size(); ++i)
		{
			m_tableScripts[i]->SetPointerSense(m_shopkeeperFSMs[i]->GetPointerSense());
		}
	}
	else
		assert(!"�� ���� ����� �ٸ��ٴ°� �߸��ƴ�.");
}

void STAGE1::Update(double dt)
{
	Scene::Update(dt);

	// ���� ġƮŰ
	if (InputManager::GetInstance()->IsKeyDown('7'))
	{
		MiniGameManager::GetInstance()->CheatAllClear();
	}

	// �ð� ġƮŰ
	if (InputManager::GetInstance()->IsKeyDown('9'))
	{
		m_gameManager->GetComponent<GameManager>()->CheatFullTime();
	}
	
}



void STAGE1::CreateWall(int x, int y)
{
	auto wall = std::make_shared<PinkBox>();
	wall->SetName("wall");
	wall->GetComponent<Transform>()->SetLocalPosition(Vector3(x, 0.5, y));
	AddEntity(wall);
	// 	wall->SetLayerCollision(LayerCollision::Wall);  ///----------------------------------------------------------- ���̾� ����
	// 	wall->AddComponent<BoxCollider>()->SetSize(Vector3(1, 2, 1));
	// 	wall->GetComponent<BoxCollider>()->SetBodyType(BodyType::Static);
}

void STAGE1::CreateAutoBush(int x, int y)
{
	auto m_hideAutomaticObject = std::make_shared<Entity>("Grass");
	m_hideAutomaticObject->SetName("HideAutomaticObject");
	Scene::AddEntity(m_hideAutomaticObject);
	m_hideAutomaticObject->AddComponent<MeshRenderer>();
	m_hideAutomaticObject->AddComponent<MeshFilter>()->SetModelKey(GraphicsTransfer::ModelKey::Bush);
	m_hideAutomaticObject->GetComponent<Transform>()->SetLocalPosition(Vector3(x, 0.0f, y));
	m_hideAutomaticObject->AddComponent<SphereCollider>();
	m_hideAutomaticObject->GetComponent<SphereCollider>()->SetRadius(1.5f);
	m_hideAutomaticObject->GetComponent<SphereCollider>()->SetDisableGravity(true);
	m_hideAutomaticObject->GetComponent<SphereCollider>()->SetIsTrigger(true);
	m_hideAutomaticObject->AddComponent<HideAutomaticScript>();

	m_hideAutomaticObject->SetLayerCollision(LayerCollision::Interactable);  ///----------------------------------------------------------- ���̾� ����
}

void STAGE1::CreateInterBush(int x, int y)
{
	/// ���� ������Ʈ (����)
	auto m_hideInteractionObject = std::make_shared<Entity>("InterBush");
	m_hideInteractionObject->SetName("HideInteractionObject");
	Scene::AddEntity(m_hideInteractionObject);
	m_hideInteractionObject->GetComponent<Transform>()->SetLocalPosition(Vector3(x, 0.0f, y));
	m_hideInteractionObject->AddComponent<SphereCollider>();
	m_hideInteractionObject->GetComponent<SphereCollider>()->SetRadius(1.5f);
	m_hideInteractionObject->GetComponent<SphereCollider>()->SetDisableGravity(true);
	m_hideInteractionObject->GetComponent<SphereCollider>()->SetIsTrigger(true);
	m_hideInteractionObject->AddComponent<BoxCollider>()->SetOffset({ 0,1,0 });				/// �ڽ� �ݶ��̴�
	m_hideInteractionObject->GetComponent<BoxCollider>()->SetBodyType(BodyType::Static);	/// �ڽ� �ݶ��̴� 
	m_hideInteractionObject->AddComponent<HideInteractionScript>();
	m_hideInteractionObject->AddComponent<MeshRenderer>();
	m_hideInteractionObject->AddComponent<MeshFilter>()->SetModelKey(GraphicsTransfer::ModelKey::Barrel);
	m_hideInteractionObject->SetLayerCollision(LayerCollision::Interactable);  ///----------------------------------------------------------- ���̾� ����

	/// ���� ���� ǥ�ÿ� UI - ��� ������Ʈ�� ���� �ٽ� ����
	auto m_hideInterKey = std::make_shared<Entity>("CanHideInterKey");
	m_hideInterKey->AddComponent<UIRenderer>("CanHideInterKeyRenderer");
	m_hideInterKey->AddComponent<MeshFilter>("CanHideInterKeyMesh");
	m_hideInterKey->AddComponent<HideInterKeyScript>();
	m_hideInterKey->GetComponent<HideInterKeyScript>()->m_hideInteractionScript = m_hideInteractionObject->GetComponent<HideInteractionScript>();
	Scene::AddEntity(m_hideInterKey);
	m_hideInterKey->SetRender(false);
	m_hideInterKey->GetComponent<MeshFilter>()->SetModelKey(GraphicsTransfer::ModelKey::UI_IngameInterKey);
	m_hideInteractionObject->GetComponent<Transform>()->SetChild(m_hideInterKey->GetComponent<Transform>());
	m_hideInterKey->GetComponent<Transform>()->SetLocalPosition(Vector3(0.f, 2.2f, 0.f));
}

void STAGE1::CreatePotion(int x, int y)
{
	///SkillObject
	auto techniquesObject = std::make_shared<Entity>("Potion");
	techniquesObject->SetName("TechniquesObject");
	Scene::AddEntity(techniquesObject);
	techniquesObject->GetComponent<Transform>()->SetLocalPosition(Vector3(x, 0., y));
	techniquesObject->AddComponent<SphereCollider>();
	techniquesObject->GetComponent<SphereCollider>()->SetRadius(1.5f);
	techniquesObject->GetComponent<SphereCollider>()->SetDisableGravity(true);
	techniquesObject->GetComponent<SphereCollider>()->SetIsTrigger(true);
	techniquesObject->AddComponent<BoxCollider>()->SetOffset({ 0,1,0 });				/// �ڽ� �ݶ��̴�
	techniquesObject->AddComponent<BoxCollider>()->SetSize({ 1,2,1 });				/// �ڽ� �ݶ��̴�
	techniquesObject->GetComponent<BoxCollider>()->SetBodyType(BodyType::Static);		/// �ڽ� �ݶ��̴�
	techniquesObject->AddComponent<TechniquesScript>();
	techniquesObject->AddComponent<MeshRenderer>();
	techniquesObject->AddComponent<MeshFilter>()->SetModelKey(GraphicsTransfer::ModelKey::Box1);
	techniquesObject->SetLayerCollision(LayerCollision::Interactable);  ///----------------------------------------------------------- ���̾� ����

	/// ���ͷ�Ƽ�� Ű (��� ������Ʈ)
	auto techniquesInterKey = std::make_shared<Entity>("InteractiveKey (Techniques Object)");
	auto techniquesIterKeyRenderer = techniquesInterKey->AddComponent<UIRenderer>("InteractiveKeyRenderer");
	auto techniquesInterKeyMesh = techniquesInterKey->AddComponent<MeshFilter>("InteractiveKeyMesh");
	auto techniquesInterKeyScript = techniquesInterKey->AddComponent<InterKeyScript>();
	techniquesInterKeyScript->m_techniquesScript = techniquesObject->GetComponent<TechniquesScript>();
	Scene::AddEntity(techniquesInterKey);
	techniquesInterKeyMesh->SetModelKey(GraphicsTransfer::ModelKey::QTE_InteractiveKey);
	techniquesObject->GetComponent<Transform>()->SetChild(techniquesInterKey->GetComponent<Transform>()); // ��� ������Ʈ�� �ڽ����� ����
	auto techniquesInterKeyTransform = techniquesInterKey->GetComponent<Transform>();
	techniquesInterKeyTransform->SetLocalPosition(Vector3(0.f, 2.2f, 0.f));
	techniquesInterKeyTransform->SetLocalScale(Vector3(0.01f, 0.01f, 0.01f));
}

void STAGE1::CreateGuard(int x, int y)
{
	///Guard
	//for (auto i : m_guardData)

	//���
	auto GuardEntity = std::make_shared<GuardPrefab>();
	Scene::AddEntity(GuardEntity);	

	// UI
	auto ui = std::make_shared<Entity>("GuardUI");
	Scene::AddEntity(ui);
	ui->AddComponent<UIRenderer>();
	ui->AddComponent<MeshFilter>()->SetModelKey(GraphicsTransfer::ModelKey::UI_GuardFSM);
	ui->AddComponent<GuardUI>();
	GuardEntity->GetComponent<Transform>()->SetChild(ui->GetComponent<Transform>());
	//ui->GetComponent<Transform>()->SetParent(GuardEntity->GetComponent<Transform>());

	//���� ���� �ݰ� - �÷��̾ ���⿡ ������ ���� �߰�
	auto chaseRange = std::make_shared<Entity>("ChaseRange");
	AddEntity(chaseRange);
	chaseRange->AddComponent<SphereCollider>();
	chaseRange->GetComponent<SphereCollider>()->SetRadius(8);
	chaseRange->GetComponent<SphereCollider>()->SetIsTrigger(true);
	chaseRange->GetComponent<SphereCollider>()->SetDisableGravity(true);
	chaseRange->GetComponent<SphereCollider>()->SetBodyType(BodyType::Static);
	chaseRange->AddComponent<ChaseRangeScript>();
	chaseRange->SetLayerCollision(LayerCollision::OnlyPlayer);
	//GuardEntity->GetComponent<Transform>()->SetChild(chaseRange->GetComponent<Transform>());
	chaseRange->GetComponent<Transform>()->SetParent(GuardEntity->GetComponent<Transform>());
	chaseRange->GetComponent<Transform>()->SetLocalPosition(Vector3(0, 0, 0));

	GuardEntity->SetPos(Vector3(x, 0, y));
	GuardEntity->SetPatrolPath(GuardEntity->GetComponent<Transform>()->GetWorldPosition() + Vector3(0, 0, 0));
	GuardEntity->SetLayerCollision(LayerCollision::Guard);  ///----------------------------------------------------------- ���̾� ����
	//float position = 0.f;	// <- ���� ����
	//if (i.m_direction == EntityDirection::DOWN)
	//{
	//	position = 0.f;
	//}
	//else if (i.m_direction == EntityDirection::RIGHT)
	//{
	//	position = -90.f;
	//}
	//else if (i.m_direction == EntityDirection::LEFT)
	//{
	//	position = 90.f;
	//}
	//else if (i.m_direction == EntityDirection::UP)
	//{
	//	position = 180.f;
	//}

	//GuardEntity->GetComponent<Transform>()->SetLocalRotation(Vector3(0.f, position, 0.f));

}

void STAGE1::CreatePlayer(int x, int y)
{

}

void STAGE1::CreateStreetLight(int x, int y)
{
	auto store = std::make_shared<Entity>("Lamp");
	auto storeRenderer = store->AddComponent<MeshRenderer>();
	auto storeMesh = store->AddComponent<MeshFilter>();
	auto storeTransform = store->GetComponent<Transform>();
	Scene::AddEntity(store);
	storeMesh->SetModelKey(GraphicsTransfer::ModelKey::Lamp);
	store->AddComponent<PointLight>();
	store->AddComponent<TorchLight>();
	store->AddComponent<BoxCollider>();

	storeTransform->SetLocalPosition(Vector3(x, 0.f, y));
}

void STAGE1::CreateTree(int x, int y)
{
	auto store = std::make_shared<Entity>("Tree");
	auto storeRenderer = store->AddComponent<MeshRenderer>();
	auto storeMesh = store->AddComponent<MeshFilter>();
	auto storeTransform = store->GetComponent<Transform>();
	Scene::AddEntity(store);
	storeMesh->SetModelKey(GraphicsTransfer::ModelKey::Tree1);

	store->AddComponent<BoxCollider>();
	storeTransform->SetWorldPosition(Vector3(x, 0.f, y));
}

void STAGE1::CreateStore(int x, int y, int dir, int type)
{
	///Shop
	/// ���� ����
	auto store = std::make_shared<Entity>("SampleStore");
	auto storeRenderer = store->AddComponent<MeshRenderer>("StoreRenderer");
	auto storeMesh = store->AddComponent<MeshFilter>("SampleStore");
	auto storeTransform = store->GetComponent<Transform>();
	//storeTransform->AddPosition(Vector3(x, 0.f, y));
	Scene::AddEntity(store);
	//storeMesh->SetModelKey(GraphicsTransfer::ModelKey::BagleStore);
	store->AddComponent<BoxCollider>()->SetSize({ 7.f,7.5f,5.8f });
	store->GetComponent<BoxCollider>()->SetOffset({ -0.7,3.8,0.2 });
	store->GetComponent<BoxCollider>()->SetBodyType(BodyType::Static);
	store->SetLayerCollision(LayerCollision::Store);  ///----------------------------------------------------------- ���̾� ����
	//store->AddComponent<BoxCollider>()->SetBodyType(BodyType::Static);


	/// ���� 
	auto merchant = std::make_shared<Entity>("SampleMerchant");
	Scene::AddEntity(merchant);
	merchant->AddComponent<ShopKeeperFSM>();
	merchant->AddComponent<ShopKeeperDoubtScript>();
	auto merchantRenderer = merchant->AddComponent<MeshRenderer>("MerchantRenderer");
	auto merchantMesh = merchant->AddComponent<MeshFilter>("PlayerMesh");
	merchantMesh->SetModelKey(GraphicsTransfer::ModelKey::Merchant);
	store->GetComponent<Transform>()->SetChild(merchant->GetComponent<Transform>()); // ���� ������ �ڽ����� ����
	merchant->GetComponent<Transform>()->AddPosition(Vector3(-0.1f, 0.f, -3.4f));
	merchant->GetComponent<Transform>()->SetLocalRotation(Vector3(0.f, 180.f, 0.f));
	/*merchant->AddComponent<CapsuleCollider>()->FreezeRotation(true, true, true);  /// ĸ�� �ݶ��̴�
	merchant->GetComponent<CapsuleCollider>()->SetOffset({ 0.f, 1.f, 0.f });	  /// ĸ�� �ݶ��̴�
	merchant->GetComponent<CapsuleCollider>()->SetSize({ 0.5,0.5,0.5 });			  /// ĸ�� �ݶ��̴�
	merchant->GetComponent<CapsuleCollider>()->SetBodyType(BodyType::Static);	  /// ĸ�� �ݶ��̴�*/
	merchant->GetComponent<ShopKeeperFSM>()->Start();
	merchant->SetLayerCollision(LayerCollision::Merchant); ///----------------------------------------------------------- ���̾� ����
	/*merchant->GetComponent<CapsuleCollider>()->SetOffset();*/

	/// ������ UI
	auto merchantUI = std::make_shared<Entity>("MerchantUI");
	Scene::AddEntity(merchantUI);
	merchant->GetComponent<Transform>()->SetChild(merchantUI->GetComponent<Transform>());
	merchantUI->AddComponent<MeshFilter>()->SetModelKey(GraphicsTransfer::ModelKey::UI_Merchant);
	merchantUI->AddComponent<UIRenderer>();
	merchantUI->AddComponent<MerchantUI>();

	///������ ȣ�����
	auto callingRange = std::make_shared<Entity>("callingRange");
	Scene::AddEntity(callingRange);
	callingRange->AddComponent<Transform>();
	callingRange->AddComponent<MeshRenderer>();
	callingRange->AddComponent<SphereCollider>();
	callingRange->GetComponent<SphereCollider>()->SetRadius(30.f);
	callingRange->GetComponent<SphereCollider>()->SetDisableGravity(true);
	callingRange->GetComponent<SphereCollider>()->SetIsTrigger(true);
	callingRange->AddComponent<ShopKeeperCallingScript>();
	callingRange->SetLayerCollision(LayerCollision::CallingRange); ///----------------------------------------------------------- ���̾� ����

	///ȣ����� ���� ��ƼƼ�� ���̱�
	merchant->GetComponent<Transform>()->SetChild(callingRange->GetComponent<Transform>());
	callingRange->GetComponent<Transform>()->SetLocalPosition(Vector3(0, 0, 0));

	int m_range = 10;
	float offset = -0.5f;
	///������ ��ġ ����
//���� ray
	merchant->AddComponent<RayCaster>();
	merchant->GetComponent<RayCaster>(0)->SetUnitDirectionOffset(Vector3(0, 0, 1));
	merchant->GetComponent<RayCaster>(0)->SetStartPosOffset(Vector3(0, 1, offset));
	merchant->GetComponent<RayCaster>(0)->SetDistance(m_range);

	//���� 15��
	merchant->AddComponent<RayCaster>();
	merchant->GetComponent<RayCaster>(1)->SetUnitDirectionOffset(Vector3(-0.26, 0, 1));
	merchant->GetComponent<RayCaster>(1)->SetStartPosOffset(Vector3(0, 1, offset));
	merchant->GetComponent<RayCaster>(1)->SetDistance(m_range);

	//������ 15��
	merchant->AddComponent<RayCaster>();
	merchant->GetComponent<RayCaster>(2)->SetUnitDirectionOffset(Vector3(0.26, 0, 1));
	merchant->GetComponent<RayCaster>(2)->SetStartPosOffset(Vector3(0, 1, offset));
	merchant->GetComponent<RayCaster>(2)->SetDistance(m_range);

	//���� 7.5��
	merchant->AddComponent<RayCaster>();
	merchant->GetComponent<RayCaster>(3)->SetUnitDirectionOffset(Vector3(-0.13, 0, 1));
	merchant->GetComponent<RayCaster>(3)->SetStartPosOffset(Vector3(0, 1, offset));
	merchant->GetComponent<RayCaster>(3)->SetDistance(m_range);

	//������ 7.5��
	merchant->AddComponent<RayCaster>();
	merchant->GetComponent<RayCaster>(4)->SetUnitDirectionOffset(Vector3(0.13, 0, 1));
	merchant->GetComponent<RayCaster>(4)->SetStartPosOffset(Vector3(0, 1, offset));
	merchant->GetComponent<RayCaster>(4)->SetDistance(m_range);


	/// Ǫ�� ���̺�
	auto table = std::make_shared<Entity>("SampleTable");
	auto tableRenderer = table->AddComponent<MeshRenderer>("TableRenderer");
	auto tableMesh = table->AddComponent<MeshFilter>("SampleTable");
	table->AddComponent<SphereCollider>();
	table->GetComponent<SphereCollider>()->SetRadius(1.1f);
	table->GetComponent<SphereCollider>()->SetDisableGravity(true);
	table->GetComponent<SphereCollider>()->SetIsTrigger(true);
	table->GetComponent<SphereCollider>()->SetOffset(Vector3(0,0,-0.3f));
	auto tableScript = table->AddComponent<FoodTableScript>(FoodType::Bagle);
	Scene::AddEntity(table);
	tableMesh->SetModelKey(GraphicsTransfer::ModelKey::FoodTable);
	store->GetComponent<Transform>()->SetChild(table->GetComponent<Transform>()); // ���� ������ �ڽ����� ����
	table->AddComponent<BoxCollider>()->SetSize({ 2.9f,1.f,1.3f });				/// �ڽ� �ݶ��̴�
	table->AddComponent<BoxCollider>()->SetOffset({ 0.f, 1.f, 0.f });			/// �ڽ� �ݶ��̴�
	table->GetComponent<BoxCollider>()->SetBodyType(BodyType::Static);			/// �ڽ� �ݶ��̴�
	table->GetComponent<Transform>()->AddPosition(Vector3(-0.1f, 0.f, -4.9f));
	table->SetLayerCollision(LayerCollision::Interactable); ///----------------------------------------------------------- ���̾� ����

	/// Ǫ��
	auto food = std::make_shared<Entity>("SampleFood");
	auto foodRenderer = food->AddComponent<MeshRenderer>("FoodRenderer");
	auto foodMesh = food->AddComponent<MeshFilter>("SampleFood");
	auto foodTransform = food->GetComponent<Transform>();
	Scene::AddEntity(food);
	foodMesh->SetModelKey(GraphicsTransfer::ModelKey::SampleFood);
	table->GetComponent<Transform>()->SetChild(food->GetComponent<Transform>()); // ���� ���̺��� �ڽ����� ����
	foodTransform->SetLocalPosition(Vector3(0.f, 0.9f, 0.f));
	foodTransform->SetLocalRotation(Vector3(0.f, -5.f, 0.f));

	/// ���ͷ�Ƽ�� Ű (���� ���̺�)
	auto foodTableInterKey = std::make_shared<Entity>("InteractiveKey (Food Table)");
	auto foodTableIterKeyRenderer = foodTableInterKey->AddComponent<UIRenderer>("InteractiveKeyRenderer");
	auto foodTableInterKeyMesh = foodTableInterKey->AddComponent<MeshFilter>("InteractiveKeyMesh");
	auto foodTableInterKeyScript = foodTableInterKey->AddComponent<InterKeyScript>();
	foodTableInterKeyScript->m_foodTableScript = table->GetComponent<FoodTableScript>();
	Scene::AddEntity(foodTableInterKey);
	foodTableInterKeyMesh->SetModelKey(GraphicsTransfer::ModelKey::QTE_InteractiveKey);
	table->GetComponent<Transform>()->SetChild(foodTableInterKey->GetComponent<Transform>()); // ���� ���̺��� �ڽ����� ����
	auto foodTableInterKeyTransform = foodTableInterKey->GetComponent<Transform>();
	foodTableInterKeyTransform->SetLocalPosition(Vector3(0.f, 2.2f, 0.f));
	foodTableInterKeyTransform->SetLocalScale(Vector3(0.01f, 0.01f, 0.01f));

	store->GetComponent<Transform>()->SetWorldPosition(Vector3(x, 0, y));
	tableScript->SetPointerSense(merchant->GetComponent<ShopKeeperFSM>()->GetPointerSense());


	int a = ranInt(gen);
	food->GetComponent<MeshFilter>()->SetModelKey(ModelKey::SampleFood);

	switch (type)
	{
	case 1: // ��
		storeMesh->SetModelKey(GraphicsTransfer::ModelKey::BagleStore);

		if (a == 0) table->GetComponent<FoodTableScript>()->SetFoodType(FoodType::Bagle);
		if (a == 1) table->GetComponent<FoodTableScript>()->SetFoodType(FoodType::BaguettePoint);
		break;

	case 2: // ����Ʈ
		storeMesh->SetModelKey(GraphicsTransfer::ModelKey::CupCakeStore);

		if (a == 0) table->GetComponent<FoodTableScript>()->SetFoodType(FoodType::Bagle);
		if (a == 1) table->GetComponent<FoodTableScript>()->SetFoodType(FoodType::Bagle);
		break;

	case 3:  // ����
		storeMesh->SetModelKey(GraphicsTransfer::ModelKey::AppleStore);

		if (a == 1) table->GetComponent<FoodTableScript>()->SetFoodType(FoodType::WaterMelon);
		if (a == 0) table->GetComponent<FoodTableScript>()->SetFoodType(FoodType::Banana);
		break;

	case 4:  // �ػ깰
		storeMesh->SetModelKey(GraphicsTransfer::ModelKey::FishStore);

		if (a == 1) table->GetComponent<FoodTableScript>()->SetFoodType(FoodType::Fish);
		if (a == 0) table->GetComponent<FoodTableScript>()->SetFoodType(FoodType::Fish);
		break;

	case 5:  // ���
		storeMesh->SetModelKey(GraphicsTransfer::ModelKey::SausageStore);

		if (a == 0) table->GetComponent<FoodTableScript>()->SetFoodType(FoodType::Sausage);
		if (a == 1) table->GetComponent<FoodTableScript>()->SetFoodType(FoodType::Sausage);
		break;
	}

	//store->GetComponent<Transform>()->SetLocalRotation(Vector3(0.f, position, 0.f));

	/// ��ŸƮ �Լ��� �Ҹ��� �� ���� �����ϱ� ����
	m_tableScripts.push_back(tableScript);
	m_shopkeeperFSMs.push_back(merchant->GetComponent<ShopKeeperFSM>());
}

void STAGE1::CreateRestaurant(int x, int y, int dir, int type)
{
	///Shop
	/// ���� ����
	auto store = std::make_shared<Entity>("SampleStore");
	auto storeRenderer = store->AddComponent<MeshRenderer>("StoreRenderer");
	auto storeMesh = store->AddComponent<MeshFilter>("SampleStore");
	auto storeTransform = store->GetComponent<Transform>();
	//storeTransform->AddPosition(Vector3(x, 0.f, y));
	Scene::AddEntity(store);
	//storeMesh->SetModelKey(GraphicsTransfer::ModelKey::BagleStore);
	store->AddComponent<BoxCollider>()->SetSize({ 7.f,7.5f,5.8f });
	store->GetComponent<BoxCollider>()->SetOffset({ -0.7,3.8,0.2 });
	store->GetComponent<BoxCollider>()->SetBodyType(BodyType::Static);
	store->SetLayerCollision(LayerCollision::Store); ///----------------------------------------------------------- ���̾� ����
	//store->AddComponent<BoxCollider>()->SetBodyType(BodyType::Static);

	/// ���� 
	auto merchant = std::make_shared<Entity>("SampleMerchant");
	Scene::AddEntity(merchant);
	merchant->AddComponent<ShopKeeperFSM>();
	merchant->AddComponent<ShopKeeperDoubtScript>();
	auto merchantRenderer = merchant->AddComponent<MeshRenderer>("MerchantRenderer");
	auto merchantMesh = merchant->AddComponent<MeshFilter>("PlayerMesh");
	merchantMesh->SetModelKey(GraphicsTransfer::ModelKey::Merchant);
	store->GetComponent<Transform>()->SetChild(merchant->GetComponent<Transform>()); // ���� ������ �ڽ����� ����
	merchant->GetComponent<Transform>()->AddPosition(Vector3(-0.1f, 0.f, -3.4f));
	merchant->GetComponent<Transform>()->SetLocalRotation(Vector3(0.f, 180.f, 0.f));
	/*merchant->AddComponent<CapsuleCollider>()->FreezeRotation(true, true, true);		 /// ĸ�� �ݶ��̴�
	merchant->GetComponent<CapsuleCollider>()->SetOffset({ 0.f, 1.f, 0.f });			 /// ĸ�� �ݶ��̴�
	merchant->GetComponent<CapsuleCollider>()->SetBodyType(BodyType::Static);		 /// ĸ�� �ݶ��̴�*/
	merchant->GetComponent<ShopKeeperFSM>()->Start();
	merchant->SetLayerCollision(LayerCollision::Merchant); ///----------------------------------------------------------- ���̾� ����
	/*merchant->GetComponent<CapsuleCollider>()->SetOffset();*/

	/// ������ UI
	auto merchantUI = std::make_shared<Entity>("MerchantUI");
	Scene::AddEntity(merchantUI);
	merchant->GetComponent<Transform>()->SetChild(merchantUI->GetComponent<Transform>());
	merchantUI->AddComponent<MeshFilter>()->SetModelKey(GraphicsTransfer::ModelKey::UI_Merchant);
	merchantUI->AddComponent<UIRenderer>();
	merchantUI->AddComponent<MerchantUI>();

	///������ ȣ�����
	auto callingRange = std::make_shared<Entity>("callingRange");
	Scene::AddEntity(callingRange);
	callingRange->AddComponent<Transform>();
	callingRange->AddComponent<MeshRenderer>();
	callingRange->AddComponent<SphereCollider>();
	callingRange->GetComponent<SphereCollider>()->SetRadius(20.f);
	callingRange->GetComponent<SphereCollider>()->SetDisableGravity(true);
	callingRange->GetComponent<SphereCollider>()->SetIsTrigger(true);
	callingRange->AddComponent<ShopKeeperCallingScript>();
	callingRange->SetLayerCollision(LayerCollision::CallingRange); ///----------------------------------------------------------- ���̾� ����

	///ȣ����� ���� ��ƼƼ�� ���̱�
	merchant->GetComponent<Transform>()->SetChild(callingRange->GetComponent<Transform>());
	callingRange->GetComponent<Transform>()->SetLocalPosition(Vector3(0, 0, 0));

	int m_range = 10;
	float offset = -0.5f;
	///������ ��ġ ����
//���� ray
	merchant->AddComponent<RayCaster>();
	merchant->GetComponent<RayCaster>(0)->SetUnitDirectionOffset(Vector3(0, 0, 1));
	merchant->GetComponent<RayCaster>(0)->SetStartPosOffset(Vector3(0, 1, offset));
	merchant->GetComponent<RayCaster>(0)->SetDistance(m_range);

	//���� 15��
	merchant->AddComponent<RayCaster>();
	merchant->GetComponent<RayCaster>(1)->SetUnitDirectionOffset(Vector3(-0.26, 0, 1));
	merchant->GetComponent<RayCaster>(1)->SetStartPosOffset(Vector3(0, 1, offset));
	merchant->GetComponent<RayCaster>(1)->SetDistance(m_range);

	//������ 15��
	merchant->AddComponent<RayCaster>();
	merchant->GetComponent<RayCaster>(2)->SetUnitDirectionOffset(Vector3(0.26, 0, 1));
	merchant->GetComponent<RayCaster>(2)->SetStartPosOffset(Vector3(0, 1, offset));
	merchant->GetComponent<RayCaster>(2)->SetDistance(m_range);

	//���� 7.5��
	merchant->AddComponent<RayCaster>();
	merchant->GetComponent<RayCaster>(3)->SetUnitDirectionOffset(Vector3(-0.13, 0, 1));
	merchant->GetComponent<RayCaster>(3)->SetStartPosOffset(Vector3(0, 1, offset));
	merchant->GetComponent<RayCaster>(3)->SetDistance(m_range);

	//������ 7.5��
	merchant->AddComponent<RayCaster>();
	merchant->GetComponent<RayCaster>(4)->SetUnitDirectionOffset(Vector3(0.13, 0, 1));
	merchant->GetComponent<RayCaster>(4)->SetStartPosOffset(Vector3(0, 1, offset));
	merchant->GetComponent<RayCaster>(4)->SetDistance(m_range);

	/// Ǫ�� ���̺�
	/// Ǫ�� ���̺�
	auto table = std::make_shared<Entity>("SampleTable");
	auto tableRenderer = table->AddComponent<MeshRenderer>("TableRenderer");
	auto tableMesh = table->AddComponent<MeshFilter>("SampleTable");
	table->AddComponent<SphereCollider>();
	table->GetComponent<SphereCollider>()->SetRadius(1.1f);
	table->GetComponent<SphereCollider>()->SetDisableGravity(true);
	table->GetComponent<SphereCollider>()->SetIsTrigger(true);
	table->GetComponent<SphereCollider>()->SetOffset(Vector3(0, 0, -0.3f));
	auto tableScript = table->AddComponent<FoodTableScript>(FoodType::Bagle);
	Scene::AddEntity(table);
	tableMesh->SetModelKey(GraphicsTransfer::ModelKey::FoodTable);
	store->GetComponent<Transform>()->SetChild(table->GetComponent<Transform>()); // ���� ������ �ڽ����� ����
	table->AddComponent<BoxCollider>()->SetSize({ 2.9f,1.f,1.3f });				/// �ڽ� �ݶ��̴�
	table->AddComponent<BoxCollider>()->SetOffset({ 0.f, 1.f, 0.f });			/// �ڽ� �ݶ��̴�
	table->GetComponent<BoxCollider>()->SetBodyType(BodyType::Static);			/// �ڽ� �ݶ��̴�
	table->SetLayerCollision(LayerCollision::Interactable); ///----------------------------------------------------------- ���̾� ����

	/// Ǫ��
	auto food = std::make_shared<Entity>("SampleFood");
	auto foodRenderer = food->AddComponent<MeshRenderer>("FoodRenderer");
	auto foodMesh = food->AddComponent<MeshFilter>("SampleFood");
	auto foodTransform = food->GetComponent<Transform>();
	foodTransform->SetLocalPosition(Vector3(0.f, 0.9f, 0.f));
	foodTransform->SetLocalRotation(Vector3(0.f, -5.f, 0.f));

	Scene::AddEntity(food);
	foodMesh->SetModelKey(GraphicsTransfer::ModelKey::SampleFood);
	table->GetComponent<Transform>()->SetChild(food->GetComponent<Transform>()); // ���� ���̺��� �ڽ����� ����

	/// ���ͷ�Ƽ�� Ű (���� ���̺�)
	auto foodTableInterKey = std::make_shared<Entity>("InteractiveKey (Food Table)");
	auto foodTableIterKeyRenderer = foodTableInterKey->AddComponent<UIRenderer>("InteractiveKeyRenderer");
	auto foodTableInterKeyMesh = foodTableInterKey->AddComponent<MeshFilter>("InteractiveKeyMesh");
	auto foodTableInterKeyScript = foodTableInterKey->AddComponent<InterKeyScript>();
	foodTableInterKeyScript->m_foodTableScript = table->GetComponent<FoodTableScript>();
	Scene::AddEntity(foodTableInterKey);
	foodTableInterKeyMesh->SetModelKey(GraphicsTransfer::ModelKey::QTE_InteractiveKey);
	table->GetComponent<Transform>()->SetChild(foodTableInterKey->GetComponent<Transform>()); // ���� ���̺��� �ڽ����� ����
	auto foodTableInterKeyTransform = foodTableInterKey->GetComponent<Transform>();
	foodTableInterKeyTransform->SetLocalPosition(Vector3(0.f, 2.2f, 0.f));
	foodTableInterKeyTransform->SetLocalScale(Vector3(0.01f, 0.01f, 0.01f));

	store->GetComponent<Transform>()->SetWorldPosition(Vector3(x, 0, y));
	tableScript->SetPointerSense(merchant->GetComponent<ShopKeeperFSM>()->GetPointerSense());
	tableScript->SetDelicious(true);

	food->GetComponent<MeshFilter>()->SetModelKey(ModelKey::SampleFood);
	switch (type)
	{
	case 2: // ��
		storeMesh->SetModelKey(GraphicsTransfer::ModelKey::BagleStore);
		table->GetComponent<FoodTableScript>()->SetFoodType(FoodType::BaguetteWheel);
		break;

	case 1: // ����Ʈ
		storeMesh->SetModelKey(GraphicsTransfer::ModelKey::CupCakeStore);
		table->GetComponent<FoodTableScript>()->SetFoodType(FoodType::CupCake);
		break;

	case 3:  // ����
		storeMesh->SetModelKey(GraphicsTransfer::ModelKey::AppleStore);
		table->GetComponent<FoodTableScript>()->SetFoodType(FoodType::Apple);
		break;

	case 4:  // �ػ깰
		storeMesh->SetModelKey(GraphicsTransfer::ModelKey::FishStore);
		table->GetComponent<FoodTableScript>()->SetFoodType(FoodType::Crab);
		break;

	case 5:  // ���
		storeMesh->SetModelKey(GraphicsTransfer::ModelKey::SausageStore);
		table->GetComponent<FoodTableScript>()->SetFoodType(FoodType::Ham);
		break;
	}

	switch (dir)
	{
	case 0:  //����
		break;

	case 1: // ������

		storeTransform->SetLocalRotation(Vector3(0, -90, 0));
		break;

	case 2: //����

		storeTransform->SetLocalRotation(Vector3(0, 90, 0));
		break;
	}

	table->GetComponent<Transform>()->AddPosition(Vector3(-0.1f, 0.f, -4.9f));

	/// ��ŸƮ �Լ��� �Ҹ��� �� ���� �����ϱ� ����
	m_tableScripts.push_back(tableScript);
	m_shopkeeperFSMs.push_back(merchant->GetComponent<ShopKeeperFSM>());
}

void STAGE1::CreateFountain(int x, int y)
{
	auto fountain = std::make_shared<Entity>("Fountain");
	Scene::AddEntity(fountain);
	fountain->AddComponent<MeshRenderer>();
	auto mesh = fountain->AddComponent<MeshFilter>();
	mesh->SetModelKey(GraphicsTransfer::ModelKey::Fountain);
	fountain->AddComponent<BoxCollider>()->SetSize({ 4,3,4 });
	fountain->GetComponent<BoxCollider>()->SetOffset({ 0.f,1.f,0.f });
	fountain->GetComponent<BoxCollider>()->SetBodyType(BodyType::Static);
	fountain->GetComponent<Transform>()->SetWorldPosition(Vector3(x, 0.f, y));
}

void STAGE1::CreateMap(int info, int x, int y, int direction, int minigame)
{
	Info id = static_cast<Info>(info);


	switch (id)
	{
			break;

	case STAGE1::Info::Wall:
		//CreateWall(x, y);
		break;
	case STAGE1::Info::AutoBush: // �ڵ��ν� (�ܵ�)
		CreateAutoBush(x, y);
		break;
	case STAGE1::Info::InterBush: // �����ν� (��)
		CreateInterBush(x, y);
		break;
	case STAGE1::Info::Potion: // ������ (�ڽ�)
		CreatePotion(x, y);
		break;
	//case STAGE1::Info::store: // ����					/// UI ���������� CreateStoreMap �Լ��� ���λ�
	//	CreateStore(x, y, direction, minigame);
	//	break;
	//case STAGE1::Info::Restaurant: // ����
	//	CreateRestaurant(x, y, direction, minigame);
	//	break;
	case STAGE1::Info::Plaza: // �м���
		CreateFountain(x, y);
		break;
	case STAGE1::Info::Guard: // ���
		CreateGuard(x, y);
		break;
	case STAGE1::Info::Player: // �÷��̾�
		break;
	case STAGE1::Info::Streetlight: // ���ε�
		//CreateStreetLight(x, y);
		break;
	case STAGE1::Info::Tree: // ����
		//CreateTree(x, y);
		break;
	case STAGE1::Info::End:
		break;
	default:
		break;
	}
}

void STAGE1::CreateStoreMap(int info, int x, int y, int direction, int minigame)
{
	Info id = static_cast<Info>(info);


	switch (id)
	{
		break;

	case STAGE1::Info::store: // ����
		CreateStore(x, y, direction, minigame);
		break;
	case STAGE1::Info::Restaurant: // ����
		CreateRestaurant(x, y, direction, minigame);
		break;
	default:
		break;
	}
}

void STAGE1::CreateDeco(DecoType type, float x, float y, float yRotation /*= 0.f*/, float scale)
{
	auto deco = std::make_shared<Entity>("DecoObject");
	Scene::AddEntity(deco);
	deco->AddComponent<MeshRenderer>();
	auto mesh = deco->AddComponent<MeshFilter>();
	deco->GetComponent<Transform>()->SetWorldPosition(Vector3(x, 0.f, y));
	deco->GetComponent<Transform>()->SetWorldRotation(Vector3(0, yRotation, 0));
	deco->GetComponent<Transform>()->SetWorldScale(Vector3(scale, scale, scale));
	deco->SetLayerCollision(LayerCollision::OnlyPlayer);

	switch (type)
	{
	case STAGE1::DecoType::Grass:
		mesh->SetModelKey(GraphicsTransfer::ModelKey::Grass);
		deco->SetName("grass");
		break;

	case STAGE1::DecoType::Flag:
		mesh->SetModelKey(GraphicsTransfer::ModelKey::Flag);
		deco->AddComponent<PointLight>()->SetPosOffset(Vector3(0.7,2.8,-2.4));
		deco->AddComponent<TorchLight>();
		deco->SetName("flag");
		break;

	case STAGE1::DecoType::Tree1:
		mesh->SetModelKey(GraphicsTransfer::ModelKey::Tree1);
		deco->AddComponent<CapsuleCollider>()->SetSize(0.3 * scale, 1.9 * scale);
		deco->GetComponent<CapsuleCollider>()->SetBodyType(BodyType::Static);
		deco->SetName("tree1");
		break;

	case STAGE1::DecoType::Tree2:
		mesh->SetModelKey(GraphicsTransfer::ModelKey::Tree2);
		deco->AddComponent<CapsuleCollider>()->SetSize(0.3 * scale, 1.9 * scale);
		deco->GetComponent<CapsuleCollider>()->SetBodyType(BodyType::Static);
		deco->SetName("tree2");
		break;

	case STAGE1::DecoType::Table:
		mesh->SetModelKey(GraphicsTransfer::ModelKey::Table);
		deco->AddComponent<BoxCollider>()->SetSize(Vector3(5*scale, 4*scale, 1.3*scale));
		deco->GetComponent<BoxCollider>()->SetBodyType(BodyType::Static);
		deco->SetName("table");
		break;

	case STAGE1::DecoType::Candy:
		mesh->SetModelKey(GraphicsTransfer::ModelKey::Candy);
		deco->AddComponent<CapsuleCollider>()->SetSize(0.3 * scale, 1.9 * scale);
		deco->GetComponent<CapsuleCollider>()->SetBodyType(BodyType::Static);
		deco->SetName("candy");
		break;



	case STAGE1::DecoType::Candle1:
		deco->SetName("candle1");
		mesh->SetModelKey(GraphicsTransfer::ModelKey::Candle1);
		deco->AddComponent<PointLight>()->SetPosOffset(Vector3(0, 3.6 * scale, -0.9 * scale));
		deco->AddComponent<TorchLight>()->SetMinMaxRatio(scale);
		deco->AddComponent<CapsuleCollider>()->SetSize(0.3 * scale, 1.9 * scale);
		deco->GetComponent<CapsuleCollider>()->SetBodyType(BodyType::Static);
		break;

	case STAGE1::DecoType::Candle2:
		deco->SetName("candle2");
		mesh->SetModelKey(GraphicsTransfer::ModelKey::Candle2);
		deco->AddComponent<PointLight>()->SetPosOffset(Vector3(0, 3.6 * scale, -0.9 * scale));
		deco->AddComponent<TorchLight>()->SetMinMaxRatio(scale);
		deco->AddComponent<CapsuleCollider>()->SetSize(0.5 * scale, 1.0 * scale);
		deco->GetComponent<CapsuleCollider>()->SetBodyType(BodyType::Static);
		break;

	case STAGE1::DecoType::Lamp:
		deco->SetName("lamp");
		mesh->SetModelKey(GraphicsTransfer::ModelKey::Lamp);
		deco->AddComponent<PointLight>()->SetPosOffset(Vector3(0, 4.0 * scale, -0.45 * scale));
		deco->AddComponent<TorchLight>()->SetMinMaxRatio(scale);
		deco->AddComponent<CapsuleCollider>()->SetSize(0.3 * scale,1.9 * scale);
		deco->GetComponent<CapsuleCollider>()->SetBodyType(BodyType::Static);
		break;
	}
}
