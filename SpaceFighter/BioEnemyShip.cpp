
#include "BioEnemyShip.h"
#include "Level.h"


BioEnemyShip::BioEnemyShip()
{
	SetSpeed(150);
	SetMaxHitPoints(1);
	SetCollisionRadius(20);
}


void BioEnemyShip::Update(const GameTime& gameTime)
{
	if (IsActive())
	{
		float x = cos(gameTime.GetTotalTime() * Math::PI + GetIndex()); // changed to cos
		x *= GetSpeed() * gameTime.GetElapsedTime() * 3.1f; // Speed changed, Bio Enemy ship moves more erratic now
		TranslatePosition(x, GetSpeed() * gameTime.GetElapsedTime());

		if (!IsOnScreen()) Deactivate();
	}

	EnemyShip::Update(gameTime);
}


void BioEnemyShip::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
	}
}
