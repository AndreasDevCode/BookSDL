#include "Laser.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Game.h"
#include "CircleComponent.h"
#include "Asteroid.h"
Laser::Laser(Game* game)
	:
	Actor(game),
	mDeathTimer(1.0f)
{
	// create sprite for laser
	SpriteComponent* sp = new SpriteComponent(this);
	sp->SetTexture(game->GetTexture("Assets/Laser.png"));

	// Make a movecomponent
	MoveComponent* mc = new MoveComponent(this);
	mc->SetForwardSpeed(800.0f);
	//create circlecomponent
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(11.0f);

}

void Laser::UpdateActor(float dt)
{
	mDeathTimer -= dt;
	// if run out of time -> laser is dead
	if (mDeathTimer <= 0)
	{
		SetState(EDead);
	}
	else
	{
		for (auto ast : GetGame()->GetAsteroids())
		{
			/*
			if (Intersect(*mCircle, *(ast->GetCircle())))
			{
				// The first asteroid we intersect with,
				// set ourselves and the asteroid to dead
				SetState(EDead);
				ast->SetState(EDead);
				break;
			}
			*/
		}
	}
}
