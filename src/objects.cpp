#include <objects.h>
#include <rlgl.h>
#include <raymath.h>
#include <cstring>

unsigned char lerpColor(unsigned char a, unsigned char b, float t) {
    return (unsigned char)((1.0f - t) * a + t * b);
};


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
    float elapsed = startTime;

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

	
	t = cubicBezierEase(t, next->easing.x, next->easing.y, next->easing.z, next->easing.w);
	float posX = lerp(prev->position.x, next->position.x, t);
	float posY = lerp(prev->position.y, next->position.y, t);
	float width  = dimensions.x * lerp(prev->scale_x, next->scale_x, t);
	float height = dimensions.y * lerp(prev->scale_y, next->scale_y, t);
	Color clr {
		(unsigned char)lerp(prev->clr.r, next->clr.r, t),
		(unsigned char)lerp(prev->clr.g, next->clr.g, t),
		(unsigned char)lerp(prev->clr.b, next->clr.b, t),
		(unsigned char)lerp(prev->clr.a, next->clr.a, t)
	};

	rlPushMatrix();
        rlTranslatef(posX, posY, 0.0f);
        rlRotatef(lerp(prev->rotation, next->rotation, t), 0.0f, 0.0f, 1.0f);
		DrawRectangle(-width/2.0f, -height/2.0f, width, height, clr);
    rlPopMatrix();
}


AnimateEllipse::AnimateEllipse(Vector2 position, Vector2 dimensions, Color color, double startTime, AnimationFrames frames, int size){
	this->position = position;
	this->dimensions = dimensions;
	this->color = color;

	this->startTime = startTime + GetTime();

	this->frames = frames;
	this->size = size;
}


void AnimateEllipse::Animate() {
	if(GetTime() < startTime) return;
    float currTime = GetTime();
    float elapsed = startTime;

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

	t = cubicBezierEase(t, next->easing.x, next->easing.y, next->easing.z, next->easing.w);
	int posX = lerp(prev->position.x, next->position.x, t);
	int posY = lerp(prev->position.y, next->position.y, t);
	float width  = dimensions.x * lerp(prev->scale_x, next->scale_x, t);
	float height = dimensions.y * lerp(prev->scale_y, next->scale_y, t);
	Color clr {
		lerpColor(prev->clr.r, next->clr.r, t),
		lerpColor(prev->clr.g, next->clr.g, t),
		lerpColor(prev->clr.b, next->clr.b, t),
		lerpColor(prev->clr.a, next->clr.a, t)
	};

	rlPushMatrix();
        rlTranslatef(posX, posY, 0.0f);
        rlRotatef(lerp(prev->rotation, next->rotation, t), 0.0f, 0.0f, 1.0f);
        DrawEllipse(0, 0, width, height, clr);
    rlPopMatrix();
}
