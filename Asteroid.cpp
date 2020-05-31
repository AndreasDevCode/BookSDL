#include "Asteroid.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Game.h"
#include "Random.h"
#include "CircleComponent.h"
Asteroid::Asteroid(Game* game)
	:
	Actor(game),
	mCircle(nullptr)
{
	Vector2 randPos = Random::GetVector(Vector2::Zero, Vector2(1024.0f, 768.0f));
	SetPosition(randPos);
	SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));
	//create sprite from png
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTExture(game->GetTexture("Assets/Asteroid.png"));

	// movement
	MoveComponent* mc = new MoveComponent(this);
	mc->SetForwardSpeed(150.0f);
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(40.0f);
	game->AddAsteroids(this);
}
Asteroid::~Asteroid()
{
	GetGame()->RemoveAsteroids(this);
}