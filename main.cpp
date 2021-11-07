#include <iostream>
#include <Windows.h>
#include <vector>
#include <random>

// Casino

using namespace std;

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int randNum(int min, int max) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(min, max);
	return dis(gen);
}

int main() {
	int count = 0;


	vector<char> slotList;
	slotList.emplace_back('a');
	slotList.emplace_back('7');
	slotList.emplace_back('b');
	slotList.emplace_back('X');
	slotList.emplace_back('c');
	slotList.emplace_back('Q');

	char myList[3];

	while (true)
	{
		if (GetAsyncKeyState(VK_SPACE)) {
			count++;
			cout << count << "¹øÂ° ·ê·¿ : ";
			for (int i = 0; i < 3; i++)
			{
				myList[i] = slotList[randNum(0, slotList.size() - 1)];
				cout << myList[i] << " ";
			}
			cout << endl;
			if (myList[0] == myList[1] && myList[1] == myList[2]) {
				cout << "Congratulations!" << endl;
				if (myList[0] == '7') cout << "Jackpot!" << endl;
			}
		}
		Sleep(50);
	}
}