#pragma once
/// <summary>
/// Degree 값 yaw, pitch, roll로 회전을 나타내는 구조체
/// yaw : y축 기준 회전 / pitch : x축 기준 회전 / roll : z축 기준 회전
/// z -> x -> y 순서 == roll -> pitch -> yaw 순서
/// https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FRotator/
/// https://docs.unity3d.com/ScriptReference/Quaternion.Euler.html
/// 
/// 240104 이서영
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

