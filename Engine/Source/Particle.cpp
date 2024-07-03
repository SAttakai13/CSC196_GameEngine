#include "Particle.h"

void Particle::Update()
{
	position = position + velocity;
}

void Particle::Draw(Renderer& renderer)
{
	renderer.DrawPoint(position.x, position.y);
}
