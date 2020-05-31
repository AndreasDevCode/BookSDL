#include "CircleComponent.h"
#include "Actor.h"
CircleComponent::CircleComponent(Actor* actor)
	:
	Component(actor),
	mRadius(0.0f)
{

}
const Vector2& CircleComponent::GetCenter() const
{
	return mOwner->GetPosition();
}
float CircleComponent::GetRadius() const
{
	return mRadius;
}
bool Intersect(const CircleComponent& a, const CircleComponent& b)
{
	Vector2 diff = a.GetCenter() - b.GetCenter();
	float distSq = diff.LengthSq();
	float radiiSq = a.GetRadius() + b.GetRadius();
	radiiSq *= radiiSq;
	return distSq <= radiiSq;


}
