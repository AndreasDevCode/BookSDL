#include "MoveComponent.h"
#include "Actor.h"
MoveComponent::MoveComponent(Actor* actor, int updateOrder)
	:
	Component(actor, updateOrder),
	mAngularSpeed(0.0f),
	mForwardSpeed(0.0f)
{

}

void MoveComponent::Update(float dt)
{
	if (!Math::NearZero(mAngularSpeed))
	{
		float rot = mOwner->GetRotation();
		rot += mAngularSpeed * dt;
		mOwner->SetRotation(rot);

	}
	if (!Math::NearZero(mForwardSpeed))
	{
		Vector2 pos = mOwner->GetPosition();
		pos += mOwner->GetForward() * mForwardSpeed * dt;
		// wrapping if ouside screen
		if (pos.x < 0.0f) { pos.x = 1022.0f; }
		else if (pos.x > 1024.0f) { pos.x = 2.0f; }

		if (pos.y < 0.0f) { pos.y = 766.0f; }
		else if (pos.y > 768.0f) { pos.y = 2.0f; }
		mOwner->SetPosition(pos);
	}
}