#pragma once

#include<Windows.h>
#include<mmsystem.h>
typedef unsigned UL;

using namespace std;

#define CPUMax 30000
#define CPUMin 10000

class fpsTemp{
public:
	int LoopCount, Frame, sleep, Skip, FrameSkip, Fps, CurrentFps;
	bool draw;
	//現在のタイム、前回のタイム
	UL Time, Oldtime;
	float FrameTime, FrameTimeO;

	fpsTemp(int);
	void SetFPS(int);
	void GetFPS();
private:
	char buf[255];
};

fpsTemp::fpsTemp(int fps) {
	draw = false;
	LoopCount = 0;
	Frame = 0;
	sleep = 15;
	Skip = 0;
	Fps = fps;
	FrameSkip = 0;
	CurrentFps = 0;
	FrameTime = 1000.0 / fps - 0.000001f; //1フレームの時間
	FrameTimeO = 1000.0 / fps + 0.000001f;
	Oldtime = 0; //なんやこれ
}

void fpsTemp::SetFPS(int fps) {
	Fps = fps;
	FrameTime = 1000.0 / fps - 0.000001f; //1フレームの時間
	FrameTimeO = 1000.0 / fps + 0.000001f; Fps = fps;
}

void fpsTemp::GetFPS() {
	draw = false;
	LoopCount++;
	Time = timeGetTime();
	if (Time - Oldtime > Frame*FrameTime) {
		Frame++;
		if (Time - Oldtime < Frame*FrameTimeO) {
			draw = true;
			Sleep(sleep);
		}
		else {
			if (sleep > 1) sleep--;
			Skip++;
		}
	}if (Time - Oldtime > 1000 - FrameTime) {
		if (LoopCount > CPUMax) if (sleep < 15) sleep++;
		if (LoopCount < CPUMin) if (sleep > 1) sleep--;
		FrameSkip = Skip;
		Skip = 0;
		LoopCount = 0;
		Frame = 0;
		Oldtime = Time;
	}
}