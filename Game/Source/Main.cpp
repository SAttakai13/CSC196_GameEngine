#include "../../Engine/Source/Vector2.h"
#include "../../Engine/Source/Renderer.h"
#include "../../Engine/Source/Input.h"
#include "../../Engine/Source/Particle.h"
#include "../../Engine/Source/Random.h"
#include "../../Engine/Source/ETime.h"
#include <SDL.h>
#include <stdlib.h>
#include <iostream>
#include <vector>





int main(int argc, char* argv[])
{
	Renderer renderer;
	Input input;
	
	renderer.Initialize();
	renderer.CreateWindow("Game Engine", 800, 800);

	input.Initialize();
	Time time;

	std::vector<Particle> particles;

	for (int i = 0; i < 10000; i++)
	{
		particles.push_back(Particle{ {rand() % 800, rand() % 800}, { randomf(60, 120), 0.0f} });
	}

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
			particles.push_back(Particle{ mousePosition, { randomf(-100, 100), randomf(-100, 100)} });
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
		renderer.BeginFrame();

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