#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include<time.h>
#include<iomanip>
#include<windows.h>
//#include<unistd.h>

class Clock
{
public:
	//构造函数
	Clock()
	{
		time_t t = time(NULL);
		struct tm ti1 = *localtime(&t);
		//struct tm * gmtime(const time_t *timer);
		struct tm ti2 = *localtime(&t);
		year = ti2.tm_year+1900;
		month = ti1.tm_mon + 1;
		day2 = ti1.tm_mday;
		day1 = ti1.tm_wday;
		hor = ti1.tm_hour;
		min = ti1.tm_min;
		sec = ti1.tm_sec;
    }


	void run()
	{
		while (1)
		{
			//显示函数
			show();
			//数据更新函数
			review();
		}
	}

	

private:
	void show()
	{
		system("cls");//清屏函数
		cout << "星期" << setw(1) << day1 << "   ";
		cout << setw(4) << year << "-";
		cout << setw(2) << month << "-";
		cout << setw(2) << day2 << "   ";
		cout << setw(2) << hor << ":";
		cout << setw(2) << min << ":";
		cout << setw(2) << sec << " ";
		/*time_t lt;
		lt = time(NULL);
		printf(ctime(&lt));*/
	}
	void review()
	{
		Sleep(1000);
		if (++sec == 60)
		{
			sec = 0;
			min += 1;
			if (min == 60)
			{
				min = 0;
				hor += 1;
				if (hor == 24)
				{
					hor = 0;
					day1 += 1;
					day2 += 1;

					if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
					{
						if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
						{
							if (day2 == 31||day1 == 7)
							{
								day1 = 1;
								day2 = 1;
								month += 1;
								if (month == 12)
								{
									month = 1;
									year += 1;
								}
							}
						}
						else if (month == 2)
						{
							if (day2 == 29 || day1 == 7)
							{
								day1 = 1;
								day2 = 1;
								month += 1;
								if (month == 12)
								{
									month = 1;
									year += 1;
								}
							}
						}
						else//不是上面两种情况
						{
							if (day2 == 30 || day1 == 7)
							{
								day1 = 1;
								day2 = 1;
								month += 1;
								if (month == 12)
								{
									month = 1;
									year += 1;
								}
							}
						}
					}
					else//不是闰年
					{
						if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
						{
							if (day2 == 31 || day1 == 7)
							{
								day1 = 1;
								day2 = 1;
								month += 1;
								if (month == 12)
								{
									month = 1;
									year += 1;
								}
							}
						}
						else if (month == 2)
						{
							if (day2 == 28 || day1 == 7)
							{
								day1 = 1;
								day2 = 1;
								month += 1;
								if (month == 12)
								{
									month = 1;
									year += 1;
								}
							}
						}
						else//不是上面两种情况
						{
							if (day2 == 30 || day1 == 7)
							{
								day1 = 1;
								day2 = 1;
								month += 1;
								if (month == 12) 
								{
									month = 1;
									year += 1;
								}
							}
						}
					}
				}
			}
		}
	}

private:
	int year;
	int month;
	int day1;//表示显示星期
	int day2;//表示显示月
	int hor;//时
	int min;//分
	int sec;//秒
};
int main()
{
	Clock c;
	c.run();
	system("pause");
	return 0;
}
