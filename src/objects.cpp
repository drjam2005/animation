#include <objects.h>

float lerp(float a, float b, float f) {
    return (a * (1.0 - f)) + (b * f);
}

float cubicBezierEase(float t, float x1, float y1, float x2, float y2) {
    float u = 1.0f - t;
    float tt = t * t;
    float uu = u * u;

    return (3 * uu * t * y1) + (3 * u * tt * y2) + (tt * t);
}

AnimateRectangle::AnimateRectangle(Vector2 position, Vector2 dimensions, Color color, double startTime, AnimationFrames frames, int size){
	this->position = position;
	this->dimensions = dimensions;
	this->color = color;

	this->startTime = startTime + GetTime();

	this->frames = frames;
	this->size = size;
}

void AnimateRectangle::Animate() {
	if(GetTime() < startTime) return;
    float currTime = GetTime();
    float elapsed = 0.0f;

    Keyframe* prev = &frames.keyframes[0];
    Keyframe* next = nullptr;

    for (int i = 1; i < size; i++) {
        elapsed += frames.keyframes[i-1].duration;
        if (currTime < elapsed) {
            next = &frames.keyframes[i];
            break;
        }
        prev = &frames.keyframes[i];
    }

    if (!next) {
        next = prev;
    }

    float frameStartTime = elapsed - prev->duration;
    float t = (currTime - frameStartTime) / prev->duration;
    if (t < 0.0f) t = 0.0f;
    if (t > 1.0f) t = 1.0f;


	t = cubicBezierEase(t, 0.62, 0, 0.233, 1.01);
    //DrawRectangle(
	//	lerp(prev->position.x, next->position.x, t),
    //    lerp(prev->position.y, next->position.y, t),
    //    dimensions.x*lerp(prev->scale_x, next->scale_x, t),
    //    dimensions.y*lerp(prev->scale_y, next->scale_y, t),
    //    color
    //);
	float posX = lerp(prev->position.x, next->position.x, t);
	float posY = lerp(prev->position.y, next->position.y, t);
	float width  = dimensions.x * lerp(prev->scale_x, next->scale_x, t);
	float height = dimensions.y * lerp(prev->scale_y, next->scale_y, t);

	DrawRectanglePro(
		Rectangle{ posX, posY, width, height },
		Vector2{ width/2, height/2 }, // <-- rotate around center
		lerp(prev->rotation, next->rotation, t),
		color
	);

			
			
}



