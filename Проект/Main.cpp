#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;


void Show_arr(int arr[3][3], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << arr[j][i] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
bool WhoWin(int arr[3][3], int SIZE, int value)
{
	for (int i = 0; i < SIZE; i++)
	{
		int cnt = 0;
		int cnt2 = 0;
		for (int j = 0; j < SIZE; j++)
		{
			if (arr[j][i] == value)
				cnt++;
			if (arr[i][j] == value)
				cnt2++;
		}
		if (cnt == 3 || cnt2 == 3 || ((arr[0][0] == value && arr[1][1] == value && arr[2][2] == value) || (arr[0][2] == value && arr[1][1] == value && arr[2][0] == value)))
		{
			return true;
			break;
		}
	}
	return false;
}
bool is_Draw(int arr[3][3], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arr[i][j] == 0)
				return false;
		}
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	const int SIZE = 3;
		//  x  y 
	int arr[SIZE][SIZE]{};
	int x = 0, y = 0;
	bool flag = true;
	
	Show_arr(arr, SIZE);

	while (flag)
	{
		cout << "Âàø õîä!\nÂâåäèòå êîîðäèíàòû x y: ";
		cin >> x >> y;
		cout << "\n";
		
		int temp = arr[x][y];
		bool draw = true;
		int counter = 0;


		//Ïðîâåðêà íà çàïîëíåííóþ êëåòêó
		while (temp != 0)
		{
			cout << "Êëåòêà çàíÿòà!\nÏîâòîðèòå ïîïûòêó";
			cout << "\nÂâåäèòå êîîðäèíàòû x y: ";
			cin >> x >> y;
			temp = arr[x][y];
			cout << "\n";
		}

		arr[x][y] = 1;

		Show_arr(arr, SIZE);

		if (is_Draw(arr, SIZE))
		{
			cout << "Íè÷üÿ!\n\n";
			break;
		}

		if (WhoWin(arr, SIZE, 1)) //Ôóíêöèÿ ïðîâåðêè ïîáåäû èãðîêà. Ïàðàìåòð 1 - ýòî êðåñòèê, ò.å. õîä èãðîêà
		{
			cout << "Âû ïîáåäèëè!\n";
			break;
		}

		cout << "Õîä êîìïüþòåðà\n\n";

		do
		{
			x = rand() % 3;
			y = rand() % 3;
		} while (arr[x][y] != 0);

		for (long int i = 0; i < 500000000; ) { i++; }

		arr[x][y] = 2;

		Show_arr(arr, SIZE);

		if (WhoWin(arr, SIZE, 2)) //Ôóíêöèÿ ïðîâåðêè ïîáåäû êîìïüþòåðà. Ïàðàìåòð 2 - ýòî íîëèê, ò.å. õîä êîìïüþòåðà
		{
			cout << "Âû ïðîèãðàëè\n";
			break;
		}

		if (is_Draw(arr, SIZE))
		{
			cout << "Íè÷üÿ!\n\n";
			break;
		}

		
	}



	return 0;
}
