#pragma once

#include "Square.h"
#include <vector>
#include <random>
#include "FrameTimer.h"
#include "Vec2.h"
#include "Colors.h"

class Env
{
private:
	std::mt19937 rng;
	std::vector<Square> boxes;
	FrameTimer ft;
	float delta;
	std::vector<Color> colors = { Colors::Red, Colors::Gray, Colors::Blue, Colors::White };
public:
	/*
		spawn boxes in
		check for collisions
		signal boxes to redraw
	*/

	struct

	Env();
	void spawnBoxes(const int num_boxes);
	void SpawnBox();
	void Update();
	void checkCollisions();
	void checkWallCollisions();
	void checkBoxCollisions();
	void Draw( Graphics& gfx );
	void Start();
};

