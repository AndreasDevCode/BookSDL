#pragma once

class AIState
{
public:
	AIState(class AIComponent* owner)
		:
		mOwner(owner)
	{}

	virtual void Update(float dt) = 0;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;
	virtual const char* GetName() const = 0;
protected:
	class AIComponent* mOwner;
};

class AIPatrol :public AIState
{
	AIPatrol(class AIComponent* owner);
	void Update(float dt) override;
	void OnEnter() override;
	void OnExit() override;
	const char* GetName() const override
	{
		return "Patrol";
	}

};
class AIDeath :public AIState
{
	AIDeath(class AIComponent* owner);
	void Update(float dt) override;
	void OnEnter() override;
	void OnExit() override;
	const char* GetName() const override
	{
		return "Death";
	}

};
class AIAttack :public AIState
{
	AIAttack(class AIComponent* owner);
	void Update(float dt) override;
	void OnEnter() override;
	void OnExit() override;
	const char* GetName() const override
	{
		return "Attack";
	}

};