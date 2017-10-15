#pragma once
#include "define_variable.h"
#include<GL/glut.h>

class character {
public:
	//0������@���玞�v���
	double position[4][2];
	double width;
	double height;
	double color[3];
	double speed;
	bool isRightMove;
	bool isUpMove;
	bool isLeftMove;
	bool isDownMove;

	//�ϐ��錾
	character();

	//x,y:����̍��W w:���̑傫�� h:�c�̑傫��
	character(double x, double y, double w, double h, double color[3]);

	//deltaX,deltaY:�ړ��ʂ��w�肵�č�����ړ����Ă���S�̂�set
	void move(double deltaX, double deltaY);

	//x,y:����̍��W
	//����̍��W�����Ƃɂ���set
	void set(double x, double y);

	//�`��
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

