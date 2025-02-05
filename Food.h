//
// Created by Emanuel Rojas on 2/4/25.
//


#ifndef FOOD_H
#define FOOD_H
#include "raylib.h"



class Food {
    private:
    Color color;
    Vector2 position;
	int height;
	int width;
	Texture2D texture;

    public:

	Food(Color c) {
 		Image image = LoadImage("../resources/images/food.png");
		texture = LoadTextureFromImage(image);
		this->color = c;
		position = generateRandomPosition();
   		this->height = 25;
  		this->width = 25;
	}

    ~Food() {
		UnloadTexture(texture);
	}

    Color getColor() {
        return this->color;
    }
    Vector2 getPosition() {
        return this->position;
    }

    void Draw() {
        DrawTexture(texture, position.x * 30, position.y * 30, WHITE);
    }

	void eaten() {
		this->position = generateRandomPosition();
	}

	Vector2 generateRandomPosition() {
		float x = GetRandomValue(0, 24);
		float y = GetRandomValue(0, 24);
		return Vector2{ x, y };
	}

};



#endif //FOOD_H
