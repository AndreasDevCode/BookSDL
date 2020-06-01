#pragma once
#include "Component.h"
#include <string>
#include <unordered_map>
class AIComponent : public Component
{
public:
	AIComponent(class Actor* actor);
	void Update(float dt) override;
	void ChangeState(const std::string& name);
	void RegisterState(class AIState* state);


private:
	std::unordered_map<std::string, class AIState*> mStates;
	class AIState* mCurrentState;
};