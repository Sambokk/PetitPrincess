#pragma once
/// <summary>
/// Degree �� yaw, pitch, roll�� ȸ���� ��Ÿ���� ����ü
/// yaw : y�� ���� ȸ�� / pitch : x�� ���� ȸ�� / roll : z�� ���� ȸ��
/// z -> x -> y ���� == roll -> pitch -> yaw ����
/// https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FRotator/
/// https://docs.unity3d.com/ScriptReference/Quaternion.Euler.html
/// 
/// 240104 �̼���
/// </summary>
struct Rotator
{
	// Constructors
	Rotator() = default;
	Rotator(float inYaw, float inPitch, float inRoll) : yaw(inYaw), pitch(inPitch), roll(inRoll) {}

	// Public Methods
	void Clamp();
	float GetClampedAngleValue(float inAngle);
	struct Vector3 ToVector3() const;

	static const Rotator Identity;

	// Properties
	float yaw = 0.f;
	float roll = 0.f;
	float pitch = 0.f;
};

