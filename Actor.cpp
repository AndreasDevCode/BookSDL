#include "Actor.h"
#include "Game.h"
#include "Component.h"
Actor::Actor(Game* game)
	:
	mState(EActive),
	mPosition(Vector2::Zero),
	mScale(0.0f),
	mRotation(0.0f),
	mGame(game)
{
	mGame->AddActor(this);
}
Actor::~Actor()
{
	mGame->RemoveActor(this);
	while (!mComponents.empty())
	{
		delete mComponents.back();
	}
}
void Actor::Update(float dt)
{
	if (mState == EActive)
	{
		UpdateComponents(dt);
		UpdateActor(dt);
	}
}
void Actor::UpdateComponents(float dt)
{
	for (auto c : mComponents)
	{
		c->Update(dt);
	}
}
void Actor::UpdateActor(float dt)// virtual
{
}
void Actor::ProcessInput(const uint8_t* keyState)
{
	if (mState == EActive)
	{
		for (auto c : mComponents)
		{
			c->ProcessInput(keyState);//virtual
		}
		ActorInput(keyState);// virtual
	}
}
void Actor::ActorInput(const uint8_t* keyState)
{


}
void Actor::AddComponent(Component* component)
{
	int myOrder = component->GetUpdateOrder();
	auto iter = mComponents.begin();
	for (; iter != mComponents.end(); ++iter)
	{
		if (myOrder < (*iter)->GetUpdateOrder())
		{
			break;
		}
	}
	mComponents.insert(iter,component);
}

void Actor::RemoveComponent(Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		mComponents.erase(iter);
	}
}
