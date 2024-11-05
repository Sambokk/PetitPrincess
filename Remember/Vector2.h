#pragma once

/// <summary>
/// Vector2: x, y
/// TODO: FORCEINLINE / constexpr header�� �Űܼ� ����ȭ �ϱ�
/// 
/// https://docs.unity3d.com/ScriptReference/Vector2.html
/// 2D ���Ϳ� ���� ǥ��
///  2D ��ġ �� ����(��: �޽��� �ؽ�ó ��ǥ �Ǵ� ��Ƽ������ �ؽ�ó ������)�� ǥ���ϱ� ���� �Ϻο��� ���˴ϴ�. 
/// �� �� ��κ��� ��쿡�� Vector3�� ���˴ϴ�.
/// 
/// 240103 �̼���
/// </summary>
struct Vector2
{
	// Constructors
	Vector2() = default;
	Vector2(float inX, float inY) : x(inX), y(inY) {}
	Vector2(int inX, int inY) : x(static_cast<float>(inX)), y(static_cast<float>(inY)) {}

	// Public Methods
	void Normalize();
	Vector2 GetNormalize() const;

	// Static Methods
	float Dot(const Vector2& inVector) const;

	// Operators
	Vector2 operator+(const Vector2& inVector) const;
	Vector2 operator-(const Vector2& inVector) const;
	Vector2 operator*(float InScalar) const;
	Vector2 operator/(float InScalar) const;

	// Properties
	float x = 0.f;
	float y = 0.f;

	// Static Properties
	static const Vector2 Up;
	static const Vector2 Down;
	static const Vector2 Left;
	static const Vector2 Right;

	static const Vector2 One;
	static const Vector2 Zero;

};
