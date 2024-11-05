#pragma once

#include <array>

#include "Vector3.h"
#include "Plane.h"
#include "Sphere.h"
#include "Box.h"

/// <summary>
/// Frustum�� BoundSphere / BoundBox / Vector3 point Check�� ��ȯ�Ǵ� �����
/// 
/// 240106 �̼���
/// </summary>
enum class BoundCheckResult : unsigned int
{
	Outside = 0,
	Intersect,
	Inside
};

/// <summary>
/// Perspective camera���� ���Ǵ� Frustum
/// Plane 6���� �����Ǿ� ������, ������ Plane�� Normal�� D���� ������ �ִ�.
/// 
/// 240106 �̼���
/// </summary>
struct Frustum
{
	// Constructors
	Frustum() = default;

	// Public Methods
	BoundCheckResult CheckBound(const Vector3& inPoint) const;
	BoundCheckResult CheckBound(const Sphere& inSphere) const;
	BoundCheckResult CheckBound(const Box& inBox) const;

	// Properties
	std::array<Plane, 6> planes; // Y+, Y-, X+, X-, Z+, Z- ������ ����
};
