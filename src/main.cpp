#include <iostream>
#include <raylib.h>

int main(int argc, char **argv) {
	InitWindow(600, 600, "test");
	SetTargetFPS(60);
	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(BLACK);

		EndDrawing();
	}
    return 0;
}
