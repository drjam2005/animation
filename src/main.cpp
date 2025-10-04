#include <raylib.h>
#include <objects.h>

int main(int argc, char **argv) {
	Keyframe recKeyFrames[] = {
		{
			.duration = 3.0f,
			.scale_x  = 1.0f,
			.scale_y  = 1.0f,
			.rotation = 0.0f,
			.position = {100, 100},
		}, {
			.duration = 0.25,
			.scale_x  = 1.0f,
			.scale_y  = 1.0f,
			.rotation = 50.0f,
			.position = {100, 100},
		}, {
			.duration = 1.0f,
			.scale_x  = 1.0f,
			.scale_y  = 2.0f,
			.rotation = 200.0f,
			.position = {100, 100},
		}, {
			.duration = 1.0f,
			.scale_x  = 2.0f,
			.scale_y  = 2.0f,
			.rotation = 360.0f,
			.position = {100, 250},
		}, {
			.duration = 2.4f,
			.scale_x  = 3.0f,
			.scale_y  = 2.0f,
			.rotation = 1080.0f,
			.position = {500, 100},
		}
	};
	AnimateRectangle rec({100, 100}, {40, 20}, WHITE, 1.0f, {recKeyFrames}, sizeof(recKeyFrames)/sizeof(recKeyFrames[0]));

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
