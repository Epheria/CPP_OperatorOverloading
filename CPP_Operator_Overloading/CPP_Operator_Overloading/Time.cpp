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
	cout << "�� ���� �ð� : " << m_iHour << " : " << m_iMin << endl;
}

void Time::Update()
{
	int iSelect, iHour, iMin, iDays = 1;
	Time SumTime(0, 0);

	while (1)
	{
		system("cls");
		SumTime.ShowTime();
		cout << "=====���� �ð� ���� ���α׷�(" << iDays << "Day)=====" << endl;
		cout << "\t1.�ð� ���" << endl;
		cout << "\t2. ����" << endl;
		cout << "\t�Է� : ";
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
		{
			cout << "�ð� : ";
			cin >> iHour;
			cout << "�� : ";
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