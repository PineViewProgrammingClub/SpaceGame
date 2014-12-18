#ifndef SPRITE_H
#define SPRITE_H

class Sprite {
private:
	float width,height;

public:
	float x,y;
	Sprite(float x, float y, float width, float height);
	draw();
}

#endif