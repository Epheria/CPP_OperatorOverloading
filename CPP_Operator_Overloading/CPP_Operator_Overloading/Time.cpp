#include "Time.h"

Time::Time()
{
}

Time::Time(int Hour, int Min)
{
	m_iHour = Hour;
	m_iMin = Min;
}

void Time::operator +(Time time)
{
	while (time.m_iMin >= 60)
	{
		time.m_iMin -= 60;
		time.m_iHour++;
	}

	this->m_iHour = this->m_iHour + time.m_iHour;
	this->m_iMin = this->m_iMin + time.m_iMin;

	while (this->m_iMin >= 60)
	{
		this->m_iMin -= 60;
		this->m_iHour++;
	}
}

void Time::ShowTime()
{
	cout << "총 공부 시간 : " << m_iHour << " : " << m_iMin << endl;
}

void Time::Update()
{
	int iSelect, iHour, iMin, iDays = 1;
	Time SumTime(0, 0);

	while (1)
	{
		system("cls");
		SumTime.ShowTime();
		cout << "=====공부 시간 관리 프로그램(" << iDays << "Day)=====" << endl;
		cout << "\t1.시간 등록" << endl;
		cout << "\t2. 종료" << endl;
		cout << "\t입력 : ";
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
		{
			cout << "시간 : ";
			cin >> iHour;
			cout << "분 : ";
			cin >> iMin;
			Time PlusTime(iHour, iMin);
			SumTime + PlusTime;
			iDays++;
			break;
		}
		case 2:
			return;
		}
	}
}

Time::~Time()
{
}