#include "pch.h"
#include "Vector3.h"
#include <cassert>

#include "MathUtill.h"

const Vector3 Vector3::Up = Vector3(0.f, 1.f, 0.f);
const Vector3 Vector3::Down = Vector3(0.f, -1.f, 0.f);
const Vector3 Vector3::Right = Vector3(1.f, 0.f, 0.f);
const Vector3 Vector3::Left = Vector3(-1.f, 0.f, 0.f);

const Vector3 Vector3::Zero = Vector3(0.f, 0.f, 0.f);
const Vector3 Vector3::One = Vector3(1.f, 1.f, 1.f);

const Vector3 Vector3::Forward = Vector3(0.f, 0.f, 1.f);
const Vector3 Vector3::Back = Vector3(0.f, 0.f, -1.f);

const Vector3 Vector3::UnitX(1.f, 0.f, 0.f);
const Vector3 Vector3::UnitY(0.f, 1.f, 0.f);
const Vector3 Vector3::UnitZ(0.f, 0.f, 1.f);

void Vector3::Normalize()
{
	*this = GetNormalize();
}

Vector3 Vector3::GetNormalize() const
{
	float squareSum = x * x + y * y + z * z;
	if (squareSum == 1.f)
	{
		return *this;
	}
	else if (squareSum == 0.f)
	{
		return Vector3::Zero;
	}

	float invLength = Math::InvSqrt(squareSum);
	return Vector3(x * invLength, y * invLength, z * invLength);
}

float Vector3::SizeSquared() const
{
	return x * x + y * y + z * z;
}

float Vector3::Dot(const Vector3& inVector) const
{
	return x * inVector.x + y * inVector.y + z * inVector.z;
}

Vector3 Vector3::Cross(const Vector3& inVector) const
{
	return Vector3(
		y * inVector.z - z * inVector.y,
		z * inVector.x - x * inVector.z,
		x * inVector.y - y * inVector.x);
}

Vector3 Vector3::operator+(const Vector3& inVector) const
{
	return Vector3(x + inVector.x, y + inVector.y, z + inVector.z);
}

Vector3 Vector3::operator-(const Vector3& inVector) const
{
	return Vector3(x - inVector.x, y - inVector.y, z - inVector.z);
}

Vector3 Vector3::operator-() const
{
	return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator*(float InScalar) const
{
	return Vector3(x * InScalar, y * InScalar, z * InScalar);
}

Vector3 Vector3::operator*(const Vector3& inVector) const
{
	return Vector3(x * inVector.x, y * inVector.y, z * inVector.z);
}

Vector3 Vector3::operator/(float InScalar) const
{
	return Vector3(x / InScalar, y / InScalar, z / InScalar);
}

Vector3& Vector3::operator+=(const Vector3& inVector)
{
	x += inVector.x;
	y += inVector.y;
	z += inVector.z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& inVector)
{
	x -= inVector.x;
	y -= inVector.y;
	z -= inVector.z;
	return *this;
}

Vector3& Vector3::operator*=(float InScalar)
{
	x *= InScalar;
	y *= InScalar;
	z *= InScalar;
	return *this;
}

Vector3& Vector3::operator/=(float InScalar)
{
	x /= InScalar;
	y /= InScalar;
	z /= InScalar;
	return *this;
}

float Vector3::operator[](unsigned char inIndex) const
{
	if (inIndex == 0)
	{
		return x;
	}
	else if (inIndex == 1)
	{
		return y;
	}
	else if (inIndex == 2)
	{
		return z;
	}
	else
	{
		assert(false && "Vector3 inIndex != 0, 1, 2");
		return 0.f;
	}
}

float& Vector3::operator[](unsigned char inIndex)
{
	if (inIndex == 0)
	{
		return x;
	}
	else if (inIndex == 1)
	{
		return y;
	}
	else if (inIndex == 2)
	{
		return z;
	}
	else
	{
		assert(false && "Vector3 inIndex != 0, 1, 2");
		return x;
	}
}
