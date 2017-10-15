#include "class.h"

//変数宣言用
character::character() {
	isRightMove = false;
	isLeftMove = false;
	isUpMove = false;
	isDownMove = false;
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


enemy::enemy() {
	this->color[0] = 1;
	this->color[1] = 0;
	this->color[2] = 0;
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
	if (WINDOW_HEIGHT <= position[0][1] + height) {
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