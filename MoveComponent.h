#pragma once
#include "Component.h"
class MoveComponent : public Component
{
public:
	MoveComponent(class Actor* actor, int updateOrder = 10);
	void Update(float dt) override;
	float GetAngularSpeed() const { return mAngularSpeed; }
	float GetForwardSpeed() const { return mForwardSpeed; }
	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }

private:
	float mAngularSpeed;
	float mForwardSpeed;
};