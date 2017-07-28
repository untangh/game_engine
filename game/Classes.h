#pragma once
#include "define_variable.h"
#include<GL/glut.h>

class character {
public:
	//0→左上　から時計回り
	double position[4][2];
	double width;
	double height;
	double color[3];
	double speed;
	bool right_flag;
	bool up_flag;
	bool left_flag;
	bool down_flag;

	character();
	character(double x, double y, double w, double h, double color[3]);
	void move(double x, double y);
	void set(double delta_x, double delta_y);
	void draw();
};

//変数宣言用
character::character() {
	right_flag = false;
	left_flag = false;
	up_flag = false;
	down_flag = false;
	speed = 5;
};

//本命のコンストラクタ
character::character(double x, double y, double w, double h, double temp_color[3]) {
	width = w;
	height = h;
	for (int i = 0; i < 3; ++i) color[i] = temp_color[i];
	set(x, y);
}

void character::set(double x, double y) {
	position[0][0] = x;
	position[0][1] = y;
	position[1][0] = x + width;
	position[1][1] = y;
	position[2][0] = x + width;
	position[2][1] = y + height;
	position[3][0] = x;
	position[3][1] = y + height;
}

void character::move(double delta_x, double delta_y) {
	double next_x = position[0][0] + delta_x;
	double next_y = position[0][1] + delta_y;
	if (0 <= next_x && next_x + width <= WINDOW_WIDTH && 0 <= next_y && next_y + height <= WINDOW_HEIGHT) set(position[0][0] + delta_x, position[0][1] + delta_y);
}

void character::draw() {
	glColor3dv(color);
	glBegin(GL_LINES);
	for (int i = 0; i < 4; ++i) {
		glVertex2dv(position[i]);
		glVertex2dv(position[(i + 1) % 4]);
	}
	glEnd();
	glFlush();
}

class enemy {
public:
	double position[4][2];
	double color[3] = { 1,0,0 };
	double width;
	double height;
	double speed;
	bool up_flag;
	bool down_flag;
	enemy();
	enemy(double x, double y, double w, double h);
	void move();
	void set(double x, double y);
	void draw();
};

enemy::enemy() {
	up_flag = true;
	down_flag = false;
	speed = 3;
}

enemy::enemy(double x, double y, double w, double h) {
	width = w;
	height = h;
	set(x, y);
}

void enemy::set(double x, double y) {
	position[0][0] = x;
	position[0][1] = y;
	position[1][0] = x + width;
	position[1][1] = y;
	position[2][0] = x + width;
	position[2][1] = y + height;
	position[3][0] = x;
	position[3][1] = y + height;
}

void enemy::move() {
	if (0 >= position[0][1]) {
		down_flag = true;
		up_flag = false;
	}
	if (WINDOW_HEIGHT <= position[0][1]+height) {
		down_flag = false;
		up_flag = true;
	}
	if (down_flag) set(position[0][0], position[0][1] + speed);
	if (up_flag) set(position[0][0], position[0][1] - speed);
}

void enemy::draw() {
	glBegin(GL_LINES);
	for (int i = 0; i < 4; ++i) {
		glVertex2dv(position[i]);
		glVertex2dv(position[(i + 1) % 4]);
	}
	glEnd();
	glFlush();
}