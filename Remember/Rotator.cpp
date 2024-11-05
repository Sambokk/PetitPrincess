#include "pch.h"
#include "Rotator.h"
#include "MathUtill.h"
#include "Vector3.h"

#include <cmath>

const Rotator Rotator::Identity(0.f, 0.f, 0.f);

void Rotator::Clamp()
{
	yaw = GetClampedAngleValue(yaw);
	roll = GetClampedAngleValue(roll);
	pitch = GetClampedAngleValue(pitch);
}

float Rotator::GetClampedAngleValue(float inAngle)
{
	float angle = Math::FModuler(inAngle, 360.f);
	if (angle < 0.f)
	{
		angle += 360.f;
	}
	return angle;
}

/// <summary>
/// x��, y��, z�� ȸ������ Vector3�� ��ȯ
/// </summary>
/// <returns></returns>
Vector3 Rotator::ToVector3() const
{
	return Vector3(pitch, yaw, roll);
}
