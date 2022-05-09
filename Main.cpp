#include <iostream>

using namespace std;
#define MAX 52
#define M10
int MAX10(int Number)
{
	return (Number > 10) ? 10 : Number;
}

int main()
{
	int Deck[MAX] = { 0, };

	srand(static_cast<unsigned int>(time(NULL)));

	for (int i = 0; i < MAX; i++)
	{
		Deck[i] = (i % 13) + 1;
	}
	for (int i = 0; i < MAX * 2; i++)
	{
		int First = rand() % MAX;
		int Second = rand() % MAX;

		int Temp = Deck[First];
		Deck[First] = Deck[Second];
		Deck[Second] = Temp;
	}

	int Player[3] = { 0, };
	int AI[3] = { 0, };

	for (int i = 0; i < 3; i++)
	{
		Player[i] = Deck[i] * 2;
		AI[i] = (Deck[i] * 2) + 1;
	}
	int PlayerSum = 0;
	int AISum = 0;
	for (int i = 0; i < 3; i++)
	{
		PlayerSum += (Player[i] > 10) ? 10 : Player[i]; // i가 10보다 크면 10 아니면 i
		AISum += MAX10(AI[i]); // 함수 선언해서 사용
	}
	cout << Player[0] << '\t' << AI[0] << '\n';
	cout << Player[1] << '\t' << AI[1] << '\n';
	cout << Player[2] << '\t' << AI[2] << '\n';
	cout << PlayerSum << '\t' << AISum << '\n';
	if (AISum > 21)
	{
		cout << "PlayerWin";
	}

	else if (PlayerSum == 21)
	{
		cout << "PlayerWin";
	}

	else if (PlayerSum > AISum)
	{
		cout << "PlayerWin";
	}
	else if (PlayerSum == AISum)
	{
		cout << "PlayerWin";
	}
	else if (PlayerSum > 21)
	{
		cout << "AIWIn";
	}
	else if (AISum == 21)
	{
		cout << "AIWin";
	}
	else if (PlayerSum < AISum)
	{
		cout << "AIWin";
	}
	else
	{
		cout << "AIWin";
	}
	return 0;
}


