#include "Vector2.h"
#include "Renderer.h"
#include "Input.h"
#include "Particle.h"
#include "Random.h"
#include "ETime.h"
#include "MathUtils.h"
#include <SDL.h>
#include <stdlib.h>
#include <iostream>
#include <vector>





int main(int argc, char* argv[])
{
	Renderer renderer;
	Input input;
	float offset = 0;
	
	renderer.Initialize();
	renderer.CreateWindow("Game Engine", 800, 800);

	input.Initialize();
	Time time;

	std::vector<Particle> particles;

	/*for (int i = 0; i < 10000; i++)
	{
		particles.push_back(Particle{ {rand() % 800, rand() % 800}, { randomf(60, 120), 0.0f}, randomf(1.0, 5.0)});
	}*/

	//main
	bool quit = false;
	while (!quit)
	{
		//input
		//update
		//draw
		time.Tick();
		std::cout << time.GetTime() << std::endl;
		//Input
		input.Update();

		if (input.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;
		}

		//UPDATE
		Vector2 mousePosition = input.GetMousePosition();

		if (input.GetMouseButtonDown(0))
		{
			for(int i = 0; i < 100; i++)
				particles.push_back(Particle{ mousePosition, randomOnUnitCircle() * randomf(25, 175), randomf(1.0, 5.0)});
		}

		for (Particle& particle : particles)
		{
			particle.Update(time.GetDeltaTime());
			if (particle.position.x > 800)
			{
				particle.position.x = 0;
			}
			if (particle.position.x < 0)
			{
				particle.position.x = 800;
			}
		}
		
		
		//DRAW
		// clear screen
		renderer.SetColor(0, 0, 0, 0);
		//renderer.BeginFrame();

		renderer.SetColor(255, 255, 255, 0);

		float radius = 200.0f;
		offset += (90 * time.GetDeltaTime());
		for (float angle = 0; angle < 360; angle += 360 / 30)
		{
			float x = Math::Cos(Math::DegToRad(angle + offset)) * Math::Sin((offset + angle) * 0.045f) * radius;
			float y = Math::Sin(Math::DegToRad(angle + offset)) * Math::Sin((offset + angle) * 0.045f) * radius;

			renderer.SetColor(random(255), random(255), random(255), 0);
			renderer.DrawRect(x, y, 4.0f, 4.0f);
		}

			//// draw line
		renderer.SetColor(255, 255, 255, 0);
		for (Particle particle : particles)
		{
			particle.Draw(renderer);
		}


		// show screen
		renderer.EndFrame();
	}

	return 0;
}