#pragma once
#include <cstdint>
#include "Math.h"
#include <vector>

class Actor
{
public:
	enum State{EActive, EPaused, EDead};
	Actor(class Game* game);
	virtual ~Actor();

	void Update(float dt);
	void UpdateComponents(float dt);
	virtual void UpdateActor(float dt);
	void ProcessInput(const uint8_t* keyState);
	virtual void ActorInput(const uint8_t* keyState);


	// getters setters
	const Vector2& GetPosition() const { return mPosition; }
	void SetPosition(const Vector2& pos) { mPosition = pos; }
	float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale; }
	float GetRotation() const { return mRotation; }
	void SetRotation(float rotation) { mRotation = rotation; }

	Vector2 GetForward() const {
		return Vector2(Math::Cos(mRotation),
						-Math::Sin(mRotation));
	}
	State GetState() const { return mState; }
	void SetState(State state) { mState = state; }
	class Game* GetGame() { return mGame; }
	// add remove components
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);
private:
	class Game* mGame;
	State mState;
	Vector2 mPosition;
	float mRotation;
	float mScale;
	std::vector<class Component*> mComponents;

};