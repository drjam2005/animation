#include <iostream>
#include <raylib.h>
#include <objects.h>
#include <thread>

int main(int argc, char **argv) {
	Keyframe recKeyFrames[] = {
		{
			1.0f,
			1.0f,
			2.0f,
			{100, 100},
		}, {
			1.0f,
			2.0f,
			2.0f,
			{100, 250},
		}, {
			1.0f,
			3.0f,
			2.0f,
			{150, 100},
		}
	};
	AnimateRectangle rec({100, 100}, {20, 40}, WHITE, 3, {recKeyFrames});

	InitWindow(600, 600, "test");
	SetTargetFPS(60);
	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(BLACK);
		
		rec.Animate();

		EndDrawing();
	}
    return 0;
}
