#pragma once

#include "SDL.h"
#include <unordered_map>
#include <vector>
#include <string>
class Game
{

public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	//Adding and removing methods for different enteties in the game
	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);
	
	SDL_Texture* GetTexture(const std::string& fileName);

	// Specific for asteroids
	void AddAsteroids(class Asteroid* ast);
	void RemoveAsteroids(class Asteroid* ast);
	std::vector<class Asteroid*> GetAsteroids() { return mAsteroids; }
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnloadData();

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	
	Uint32 mTicksCount;
	bool mIsRunning;
	bool mUpdatingActors;

	// containers for stuff
	std::unordered_map<std::string, SDL_Texture*> mTextures;
	std::vector<class Actor*>			mActors;
	std::vector<class Actor*>			mPendingActors;
	std::vector<class SpriteComponent*> mSprites;
	std::vector<class Asteroid*>		mAsteroids;
	
	class Ship* mShip;


};