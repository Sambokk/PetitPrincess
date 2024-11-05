#pragma once

#include "Vector3.h"

/// <summary>
/// Quaternion i = j = k = sqrt(-1) 3���� �࿡ ���� ȸ���� ǥ��
/// float X Y Z W
/// 
/// TODO: Angle / Euler / FromToRotation / LookRotation ���� �ʿ�
/// 
/// https://en.wikipedia.org/wiki/Quaternion
/// https://docs.unity3d.com/ScriptReference/Quaternion.html
/// ���ʹϾ��� ȸ���� ǥ���ϴ� �� ���˴ϴ�.
/// ũ�Ⱑ �۰� ���� ���� ������ ���� ������ ���� ������ �� �ֽ��ϴ�. 
/// ���Ҽ��� ������� �ϹǷ� ���������� �����ϱⰡ ���� �ʽ��ϴ�. 
/// ���� ���ʹϾ� ���� ���(x,y,z,w)�� �׼����ϰų� �����ϴ� ���� ���� ������, 
/// ��κ� ���� ȸ��(��: ��ȯ����)�� �����ͼ� ���ο� ȸ��(��: �� ȸ�� ������ �ε巯�� ����)�� �����ϴ� �� ����մϴ�. 
/// 99%�� ��� ����ϴ� ���ʹϾ� �Լ�
/// Quaternion.LookRotation, Quaternion.Angle, Quaternion.Euler, Quaternion.Slerp, Quaternion.FromToRotation �� Quaternion.identity�Դϴ�
/// 
/// 240103 �̼���
/// </summary>
struct Quaternion
{
	// Constructors
	Quaternion() = default;
	Quaternion(float inX, float inY, float inZ, float inW) : x(inX), y(inY), z(inZ), w(inW) {}

	Quaternion(const struct Rotator& inRotator);
	Quaternion(const struct Matrix3x3& inMatrix);

	// Public Methods
	Quaternion Inverse() const { return Quaternion(-x, -y, -z, w); }
	Rotator ToRotator() const;
	Vector3 ToVector3() const;

	// Static Methods
	static float Angle(const Quaternion& inQuaternion1, const Quaternion& inQuaternion2);
	static Quaternion Euler(float x, float y, float z);
	static Quaternion FromToRotation(const Vector3& fromDirectionVector, const Vector3& toDirectionVector);
	static Quaternion LookRotation(const Vector3& forwardVector, const Vector3& upVector = Vector3::Up);
	static Quaternion Slerp(const Quaternion& startQuaternion, const Quaternion& endQuaternion, float alpha);

	// Operators
	Quaternion operator-() const;
	Vector3 operator*(const Vector3& inVector) const;

	// Static Properties
	static const Quaternion Identity;

	// Properties
	float x = 0.f;
	float y = 0.f;
	float z = 0.f;
	float w = 1.f;
};
