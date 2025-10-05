#include <raylib.h>
#include <objects.h>
#include <raymath.h>
#include <rlgl.h>

int main(int argc, char **argv) {
	Keyframe recKeyFrames[] = {
		{
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
			.clr= RED,
			.position = {100, 100},
		}, {
			.duration = 1.0f,
			.scale_x  = 2.0f,
			.scale_y  = 2.0f,
			.rotation = 180.0f,
			.position = {100, 250},
		}, {
			.duration = 2.0f,
			.scale_x  = 3.0f,
			.scale_y  = 2.0f,
			.rotation = 360.0f,
			.easing = {0.701, -0.328, 0.258, 1.285},
			.clr= RED,
			.position = {500, 100},
		}, {
			.duration = 2.2f,
			.scale_x  = 3.0f,
			.scale_y  = 2.0f,
			.rotation = 360.0f,
			.easing = {0.46, -0.137, 0, 1},
			.position = {100, 100},
		}
	};
	AnimateRectangle rec({100, 100}, {40, 20}, WHITE, 1.0f, {recKeyFrames}, sizeof(recKeyFrames)/sizeof(recKeyFrames[0]));
	AnimateEllipse ell({200, 300}, {40, 20}, WHITE, 2.0f, {recKeyFrames}, sizeof(recKeyFrames)/sizeof(recKeyFrames[0]));

	InitWindow(600, 600, "test");
	SetTargetFPS(144);
	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(BLACK);

		DrawFPS(20,20);
		rec.Animate();
		ell.Animate();

		EndDrawing();
	}
    return 0;
}
