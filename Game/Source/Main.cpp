#include "../../Engine/Source/Vector2.h"
#include "../../Engine/Source/Renderer.h"
#include <SDL.h>
#include <stdlib.h>
#include <iostream>
#include <vector>




int main(int argc, char* argv[])
{
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Game Engine", 800, 600);

	

	Vector2 v1{ 400,300 };
	Vector2 v2{ 500,700 };
	std::vector<Vector2> points;
	for (int i = 0; i < 100; i++)
	{
		points.push_back(Vector2{ rand() % 800, rand() % 600 });
	}

	//main
	while (true)
	{
		//input
		//update
		//draw

		//UPDATE
		Vector2 speed{ 0.1f, -0.1f };
		for (Vector2& point : points)
		{
			/*point.x += 0.1f;
			point.x -= 0.1f;*/
			//point = point + speed;
			point = point + 0.002f;
		}
		//DRAW
		// clear screen
		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();

			//// draw line
		renderer.SetColor(255, 255, 255, 0);
		renderer.DrawLine(0, 0, rand() % 800, rand() % 600);
		renderer.DrawLine(0, 0, rand() % 800, rand() % 600);
		renderer.DrawLine(0, 0, rand() % 800, rand() % 600);
		renderer.DrawLine(0, 0, rand() % 800, rand() % 600);
		renderer.DrawLine(v1.x, v1.y, v2.x, v2.y);
		for (int i = 0; i < points.size() - 1; i++)
		{
			renderer.DrawLine(points[i].x, points[i].y, points[i+1].x, points[i+1].y);
		}

		for (int i = 0; i < 1000; i++)
				
			renderer.DrawLine( 0, 0, rand()%800, rand()%600);
			renderer.DrawPoint(400, 300);
			renderer.SetColor(255, 255, 255, 0);
			renderer.SetColor(rand() % 255, rand() % 255, rand() % 255, 0);



			//// show screen
		renderer.EndFrame();
	}

	return 0;
}