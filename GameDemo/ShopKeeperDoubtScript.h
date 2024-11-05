#pragma once
#include <Script.h>

class ShopKeeperDoubtScript : public Script
{
	// Reflection
	GENERATE_CLASS_TYPE_INFO(ShopKeeperDoubtScript)

	// Serialize
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShopKeeperDoubtScript, m_name, m_UID)
	void Serialize(nlohmann::json& json) override { to_json(json, *this); }
	void Deserialize(const nlohmann::json& json) override { if (!json.is_null()) from_json(json, *this); }

public:
	ShopKeeperDoubtScript();
	~ShopKeeperDoubtScript();

	virtual void Update(double dt) override;
	virtual void Render(double dt) override;
	virtual void Finalize() override;

	//�浹������ ���� ������ �ϰڴ�
	virtual void OnCollisionEnter(const Collision& collision);
	virtual void OnCollisionStay(const Collision& collision);
	virtual void OnCollisionExit(const Collision& collision) {};
	virtual void OnTriggerEnter(Collider* collider);
	virtual void OnTriggerStay(Collider* collider);
	virtual void OnTriggerExit(Collider* collider) {};

	virtual std::shared_ptr<Component> Clone() const override;

private:
	bool m_SenseOnSound = false;
	bool m_SenseLookingSound = false;
};
