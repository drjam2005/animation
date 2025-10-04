#pragma once
#include <raylib.h>

struct Keyframe {
	float duration = 0.0f;
	float scale_x = 1.0f;
	float scale_y = 1.0f;
	Vector2 position;
};

struct AnimationFrames {
	Keyframe* keyframes;
};

class AnimateRectangle {
	private:
		Vector2 position, dimensions;
		Color color;
		AnimationFrames frames;
		int size;
		double startTime;
	public:
		AnimateRectangle(Vector2 position, Vector2 dimensions, Color color, int size, AnimationFrames frames);
		void Animate();
};


