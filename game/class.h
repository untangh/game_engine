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
	bool isRightMove;
	bool isUpMove;
	bool isLeftMove;
	bool isDownMove;

	//変数宣言
	character();

	//x,y:左上の座標 w:横の大きさ h:縦の大きさ
	character(double x, double y, double w, double h, double color[3]);

	//deltaX,deltaY:移動量を指定して左上を移動してから全体をset
	void move(double deltaX, double deltaY);

	//x,y:左上の座標
	//左上の座標をもとにしてset
	void set(double x, double y);

	//描画
	void draw();
};



class enemy {
public:
	double position[4][2];
	double color[3];
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

