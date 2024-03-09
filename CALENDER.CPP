#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int FIRST_DAY(int X)
{
	int DAY;

	DAY = (((X - 1) * 365) + ((X - 1) / 4) - ((X - 1) / 100) + ((X - 1) / 400) + 1) % 7;
	return DAY;
}

int main()
{
	int year, day, week;
	int DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string MONTHS[12] = {"JAN", "FEB", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUG", "SEPT", "OCT", "NOV", "DEC"};

	cout << "Enter the Year : ";
	cin >> year;
	if (year % 4 == 0)
	{
		DAYS[1] = 29;
	}

	day = FIRST_DAY(year);
	cout << endl
		 << endl;
	for (int i = 0; i <= 11; i++)
	{
		cout << "\n\n\t\t" << MONTHS[i] << "   " << year;
		cout << "\n\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n    ";

		for (int j = 0; j < day; j++)
		{
			cout << "      ";
		}
		week = day;

		for (int k = 1; k <= DAYS[i]; k++)
		{

			if (week > 6)
			{
				cout << "\n    "
					 << k;
				week = 0;
			}
			else
			{
				cout << k;
			}
			if (k < 10)
			{
				cout << "     ";
			}
			else
			{
				cout << "    ";
			}
			week++;
		}
		if (week == 7)
		{
			week = 0;
		}
		day = week;
	}
	return 0;
}