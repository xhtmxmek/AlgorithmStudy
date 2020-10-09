#include <iostream>
#include <vector>
#include <string>

using namespace std;

void threeTimeCount()
{
	int N = 0;
	int time = 0;
	int min = 0;
	int sec = 0;
	int cnt = 0;
	cin >> N;

	for (int i = 0; i < N + 1; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			for (int k = 0; k < 60; k++)
			{
				if ((to_string(i) + to_string(j) + to_string(k)).find('3') != string::npos)
					cnt++;
			}
		}
	}

	cout << cnt;


}

void knightMove()
{
	string knightPos;

	int posX = 1;
	int posY = 1;
	 

	cin >> knightPos;
	posX = knightPos[0] - 'a' + 1;
	posY = knightPos[1] - '0';

	int xMove[] = { 2,2,-2,-2,1,-1,1,-1 };
	int yMove[] = { 1,-1,1,-1,2,2,-2,-2 };


	vector<std::pair<int, int>> pos;

	for (int i = 0; i < 8; i++)
	{
		std::pair<int, int> tmp;
		tmp.first = xMove[i];
		tmp.second = yMove[i];
		pos.push_back(tmp);
	}


	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		int newPosX = posX + pos[i].first;
		int newPosY = posY + pos[i].second;
		if ((newPosX < 1 || newPosX>8) ||
			(newPosY < 1 || newPosY>8))
			continue;
		else
			cnt++;
	}
	cout << cnt << endl;
}

void move()
{


	int N;
	cin >> N;
	int posX = 1;
	int posY = 1;

	string delimn; 
	getline(cin, delimn);
	string plan;

	//cin >> plan;

	std::getline(cin, plan);
	int l = plan.length();
	for (int i = 0; i < plan.length(); i++)
	{

		if (plan[i] == 'L')
		{
			if (posX != 1)
				posX--;
		}
		else if (plan[i] == 'R')
		{
			if (posX != N)
				posX++;
		}
		else if (plan[i] == 'U')
		{
			if (posY != 1)
				posY--;
		}
		else if (plan[i] == 'D')
		{   
				posY++;
		}

	}


	cout << posY << " " << posX << endl;
}  