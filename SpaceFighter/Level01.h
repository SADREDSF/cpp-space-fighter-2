#pragma once

#include "Level.h"
#include "Texture.h"
#include "SpriteBatch.h"

using namespace KatanaEngine;

/** @brief The first level of the game. */
class Level01 :	public Level
{

public:
	
	/** @brief Instantiate a level object. */
	Level01();
	virtual ~Level01();
	void LoadContent(ResourceManager& resourceManager) override;
	void Update(const GameTime& gameTime) override;
	void Draw(SpriteBatch& spriteBatch) override;

	/** @brief Load the content for the level, including game objects and resources.
		@param resourceManager A reference to the game's resource manager,
		used for loading and managing game assets (resources). */
	//virtual void LoadContent(ResourceManager& resourceManager);

private:
	Texture* m_pBackgroundTexture = nullptr;
	float m_backgroundScrollY = 0.0f;
	float m_backgroundScrollSpeed = 50.0f;
};

