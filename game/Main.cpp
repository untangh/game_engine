
#include<iostream>
#include "class.h"
#include "fps_temp.h"

character main_char;
enemy enem;

fpsTemp *fps = new fpsTemp(60);

//描画用
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	if (main_char.isUpMove) main_char.move(0, -main_char.speed);
	if (main_char.isRightMove) main_char.move(main_char.speed, 0);
	if (main_char.isDownMove) main_char.move(0, main_char.speed);
	if (main_char.isLeftMove) main_char.move(-main_char.speed, 0);
	main_char.draw();
	enem.move();
	enem.draw();
	glutSwapBuffers();
}


//無理矢理元に戻すことでリサイズを拒否
void resize(int w, int h) {
	glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}

//暇な時はコマ送りで描画を更新(アニメーション)
void idle() {
	fps->GetFPS();
	if (fps->draw)
		glutPostRedisplay();
}

void init() {
	glClearColor(1, 1, 1, 1.0);
	double color[3] = { 0, 1, 0 };
	new(&main_char)character(100, 100, 50, 50, color);
	new(&enem)enemy(500, 100, 50, 50);
	glOrtho(-0.5, (GLdouble)WINDOW_WIDTH - 0.5, (GLdouble)WINDOW_HEIGHT - 0.5, -0.5, -1.0, 1.0);
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}

void mouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			std::cout << x << " " << y << std::endl;
		}
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN) {
			std::cout << enem.position[0][0] << " " << enem.position[0][1] << std::endl;
		}
		break;
	case GLUT_RIGHT_BUTTON:
		//std::cout << "right";
		break;
	default:
		break;
	}
}

//ドラッグ時の処理
void motion(int x, int y)
{
}

void keyboard(unsigned char key, int x, int y) {
	//std::cout << "key=" << key << " x=" << x << " y=" << y << std::endl;
	if (key == 'd') main_char.isRightMove = true;
	if (key == 'a') main_char.isLeftMove = true;
	if (key == 'w') main_char.isUpMove = true;
	if (key == 's') main_char.isDownMove = true;
	//glutIdleFunc(idle);
}

void keyboard_up(unsigned char key, int x, int y) {
	if (key == 'w') main_char.isUpMove = false;
	if (key == 'd') main_char.isRightMove = false;
	if (key == 's') main_char.isDownMove = false;
	if (key == 'a') main_char.isLeftMove = false;
	//glutIdleFunc(0);
}

int main(int argc, char *argv[]) {
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboard_up);
	init();
	glutMainLoop();
	return 0;
}