

#include "Level01.h"
#include "BioEnemyShip.h"
#include "Game.h"

Level01::Level01()
{
	m_backgroundScrollY = 0.0f;
	m_backgroundScrollSpeed = 200.0f;
}

Level01::~Level01(){}


void Level01::LoadContent(ResourceManager& resourceManager)
{
	// Setup enemy ships
	Texture *pTexture = resourceManager.Load<Texture>("Textures\\BioEnemyShip.png");

	const int COUNT = 21;

	double xPositions[COUNT] =
	{
		0.25, 0.2, 0.3,
		0.75, 0.8, 0.7,
		0.3, 0.25, 0.35, 0.2, 0.4,
		0.7, 0.75, 0.65, 0.8, 0.6,
		0.5, 0.4, 0.6, 0.45, 0.55
	};
	
	double delays[COUNT] =
	{
		0.0, 0.25, 0.25,
		3.0, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.5, 0.3, 0.3, 0.3, 0.3
	};

	float delay = 3.0; // start delay
	Vector2 position;

	for (int i = 0; i < COUNT; i++)
	{
		delay += delays[i];
		position.Set(xPositions[i] * Game::GetScreenWidth(), -pTexture->GetCenter().Y);

		BioEnemyShip *pEnemy = new BioEnemyShip();
		pEnemy->SetTexture(pTexture);
		pEnemy->SetCurrentLevel(this);
		pEnemy->Initialize(position, (float)delay);
		AddGameObject(pEnemy);
	}

	// Setup background
	m_pBackgroundTexture = resourceManager.Load<Texture>("Textures\\waterPixelated.jpg");

	
	//COMMENT OUT FOR SCROLLING SHADER [BUGGED]
	SetBackground(resourceManager.Load<Texture>("Textures\\waterPixelated.jpg"));

	

	Level::LoadContent(resourceManager);
	m_backgroundScrollY = 0.0f;
}

void Level01::Update(const GameTime& gameTime)
{
	float bgHeight = m_pBackgroundTexture->GetSize().Y;

	m_backgroundScrollY += m_backgroundScrollSpeed * gameTime.GetElapsedTime();
	if (m_backgroundScrollY >= -bgHeight)
	{
		m_backgroundScrollY -= bgHeight;
	}

	Level::Update(gameTime);
}


void Level01::Draw(KatanaEngine::SpriteBatch& spriteBatch)
{
	float bgHeight = m_pBackgroundTexture->GetSize().Y;

	// Draw first background at scrolled position
	spriteBatch.Draw(m_pBackgroundTexture, Vector2(0, m_backgroundScrollY));

	// Draw second background just *below* it
	spriteBatch.Draw(m_pBackgroundTexture, Vector2(0, m_backgroundScrollY + bgHeight));

	Level::Draw(spriteBatch);
}


