
#include "stdafx.h"

using namespace std;

struct A
{
	int a;
	int b;
	bool c;
	char r[48];

	A() = default;
	A(bool v) : a(5), b(v ? 1 : 0), c(v) {}
};

char* p[2'500'00];


void random_test()
{
	srand(53545);
	int k = 0;

	while (true)
	{

		if (rand() % 5 > 1)
		{
			if (rand() % 4 == 0)
				p[k] = new char[rand() % 1000 + 1];
			else
			{
				p[k] = new char[rand() % 10 + 1];
			}

			if (p[k] != 0)
			{
				++k;
			}
			else
			{
				break;
			}
		}
		else if (k != 0)
		{
			int x = rand() % (k / 2) + k / 2;
			delete[] p[x];

			for (int j = x + 1; j < k; ++j)
			{
				p[j - 1] = p[j];
			}
			--k;
		}

		memoryUsage();
		cout << "max available space:" << maxAvailable() << " bytes          \n";
		cout << "matrix fragmentation:" << metricFragmentation(0) << "            ";

		COORD coord;
		coord.X = 0;
		coord.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

}

void vector_test()
{
	//set<int> st;
	vector<int> vec1;
	for (int i = 1; i <= 10000; ++i)
	{
		if (i % 1000 == 0)
		{
			Sleep(10);
		}
		//st.insert(i);
		vec1.push_back(i);

		memoryUsage();
		cout << "max available space:" << maxAvailable() << " bytes          \n";
		cout << "matrix fragmentation:" << metricFragmentation(0) << "            ";

		COORD coord;
		coord.X = 0;
		coord.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
}

void long_long_test()
{
	char *a = new char[10000]; a[0] = 'x'; Sleep(1000);
	char *b = new char[10000]; b[0] = 'x'; Sleep(1000);
	char *c = new char[10000]; c[0] = 'x'; Sleep(1000);
	char *d = new char[10000]; d[0] = 'x'; Sleep(1000);
	char *e = new char[10000]; e[0] = 'x'; Sleep(1000);
	char *f = new char[10000]; f[0] = 'x'; Sleep(1000);
	int *g = new int[10000]; g[0] = 7; Sleep(1000);
	int *h = new int[12345]; h[0] = 8; Sleep(1000);

	delete a; Sleep(1000);
	delete b; Sleep(1000);
	delete c; Sleep(1000);
	delete d; Sleep(1000);
	delete e; Sleep(1000);
	delete f; Sleep(1000);
	delete g; Sleep(1000);
	delete h; Sleep(1000);
	long long *x = new long long[61000];
	x[0] = 10;
	Sleep(1000); delete x;

	long long *l1 = new long long[10];
	l1[0] = 1;
	Sleep(1000); delete l1;

	long long *l2 = new long long[200];
	l2[0] = 2;
	Sleep(1000); delete l2;

	long long *l3 = new long long[30];
	l3[0] = 4;
	delete l3; Sleep(1000);

	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void fragmentation_test()
{
	for (int i = 0; i < 1'000'00; ++i)
	p[i] = new char[1];

	for (int i = 0; i < 1'000'00; i += 2)
	{
		delete[] p[i];
		printf("matrix fragmentation:%f\n            ",metricFragmentation(0));

		COORD coord;
		coord.X = 0;
		coord.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
}

int main()
{

	memoryVisualise();

	//random_test();
	//long_long_test();
	//vector_test();
	fragmentation_test();

	memoryUsage();
	//cout << "Max memory block available: " << maxAvailable() << " Bytes \n";
	system("pause");

  return 0;
}

