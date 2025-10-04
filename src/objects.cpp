#include <objects.h>

float lerp(float a, float b, float f) {
    return (a * (1.0 - f)) + (b * f);
}

AnimateRectangle::AnimateRectangle(Vector2 position, Vector2 dimensions, Color color, int size, AnimationFrames frames){
	this->position = position;
	this->dimensions = dimensions;
	this->color = color;

	this->startTime = GetTime();

	this->frames = frames;
	this->size = size;
}

void AnimateRectangle::Animate() {
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

    DrawRectangle(
		lerp(prev->position.x, next->position.x, t),
        lerp(prev->position.y, next->position.y, t),
        dimensions.x*lerp(prev->scale_x, next->scale_x, t),
        dimensions.y*lerp(prev->scale_y, next->scale_y, t),
        color
    );
}



