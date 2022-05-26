#include "Coin.h"

Coin::Coin()
{
    m_image.Load("Assets/Images/Treasure.png");
    m_image.SetSpriteDimension(80, 80);
    m_image.SetImageDimension(6, 1, 3072, 512);

    

    m_image.IsAnimated(true);
    m_image.SetAnimationSpeed(1.0f);
    m_image.IsLooping(true);

    m_collider.SetDimension(m_image.GetSpriteDimension().x, m_image.GetSpriteDimension().y);
}

Coin::~Coin()
{
    m_image.Unload();
}

const BoxCollider& Coin::GetCollider() const
{
    return m_collider;
}

void Coin::Update()
{
    m_collider.SetPosition(m_position.x, m_position.y);
    m_collider.Update();
}

void Coin::Render()
{
    m_image.Render(m_position.x, m_position.y, m_angle);
}