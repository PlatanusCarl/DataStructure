#include<fstream>
#include<iostream>
#include<ostream>
#include<istream>
#include<iomanip>
#include<vector>

using namespace std;

const char* adrs1= "C:\\Users\\Platanus\\Desktop\\qu.geojson";
class pt
{
	public:
	double x;
	double y;
	pt *next;
};

class mian
{
	public:
	pt *head;
	mian *next;
};

class manymian
{
	public:
	mian* head;
	manymian *next;
};
int main()
{
	manymian *DMhead=nullptr;
	char buffer[100];
	char buffer2[10];
	ifstream read(adrs1, ios::in);
	if (read.bad())
	{
		cout << "Error";
		exit(1);
	}

	while (!read.eof())
	{
		read >> buffer;
		if (strcmp(buffer, "[") == 0)
		{
			read >> buffer;
			if (strcmp(buffer, "[") == 0)
			{
				read >> buffer;
				if (strcmp(buffer, "[") == 0)
				{
					read >> buffer;
					if (strcmp(buffer, "[") == 0)
					{
						DMhead = new manymian;
						read >> DMhead->head->head->x;
						read >> buffer2;
						DMhead->head->head->y;
						pt *p;
						p = DMhead->head->head;
						p = p->next;

					}
				}
			}
		}
	}
	return 0;
}