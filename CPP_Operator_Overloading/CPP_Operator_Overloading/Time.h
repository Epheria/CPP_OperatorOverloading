#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
	int m_iHour;
	int m_iMin;
public:
	void Update();
	void ShowTime();
	void operator + (Time time);

	Time();
	Time(int Hour, int Min);
	~Time();
};