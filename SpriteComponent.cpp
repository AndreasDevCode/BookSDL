#include "SpriteComponent.h"
#include "Actor.h"
#include "Game.h"
SpriteComponent::SpriteComponent(Actor* actor, int drawOrder)
	:
	Component(actor),
	mTexture(nullptr),
	mDrawOrder(drawOrder),
	mTexHeight(0),
	mTexWidth(0)
{
	mOwner->GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
	mOwner->GetGame()->RemoveSprite(this);
}

void SpriteComponent::Draw(SDL_Renderer* renderer)
{
	if (mTexture)
	{
		SDL_Rect r;
		// scale things to owners scale
		r.w = static_cast<int>(mTexWidth * mOwner->GetScale());
		r.h = static_cast<int>(mTexHeight * mOwner->GetScale());
		// center te rectangle around owner position
		r.x = static_cast<int>(mOwner->GetPosition().x - r.w / 2);
		r.y = static_cast<int>(mOwner->GetPosition().y - r.h / 2);
	
		SDL_RenderCopyEx(renderer,
			mTexture, nullptr, &r,
			-Math::ToDegrees(mOwner->GetRotation()), // radians to degrees
			nullptr, SDL_FLIP_NONE);
	
	}
}

void SpriteComponent::SetTexture(SDL_Texture* texture)
{
	mTexture = texture;
	// setting width and height
	SDL_QueryTexture(texture, nullptr, nullptr, &mTexWidth, &mTexHeight);

}
