#include "AIComponent.h"
#include "AIState.h"
#include "SDL.h"
void AIComponent::Update(float dt)
{
	// hvid current state ikke er nullpointer så kalles update
	// fra klassen til staten
	if (mCurrentState)
	{
		mCurrentState->Update(dt);
	}
}

void AIComponent::ChangeState(const std::string& name)
{
	if (mCurrentState)
	{
		mCurrentState->OnExit();
	}
	auto iter = mStates.find(name);
	if (iter != mStates.end())
	{
		mCurrentState = iter->second;
		mCurrentState->OnEnter();
	}
	else
	{
		SDL_Log("Could not find AIState: %s", name.c_str());
		mCurrentState = nullptr;
	}

}
void AIComponent::RegisterState(AIState*  state)
{
	mStates.emplace(state->GetName(), state);
}
