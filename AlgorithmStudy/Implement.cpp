#include <iostream>
#include <vector>
#include <string>
#include "implement.h"

using namespace std;


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


enum class mapInfo
{
	land,
	sea,
};

void characterMove()
{
	int mapWidth = 0;
	int mapHeight = 0;

	int direction = 0;
	int charDir;

	int charPosX = 0;
	int charPosY = 0;

	cin >> mapWidth >> mapHeight;
	cin >> charPosX >> charPosY;
	cin >> charDir;


	vector<vector<pair<int, bool>>> mapData;	//두번째 bool형 변수는 방문여부를 체크함
	
	

	int visitCount = 1;

	mapData.reserve(mapHeight);
	mapData.resize(mapHeight);

	for (int i = 0; i < mapHeight; i++)
	{	
		mapData[i].reserve(mapWidth);
		mapData[i].resize(mapWidth);
		for (int j = 0; j < mapWidth; j++)
		{			
			cin >> mapData[i][j].first;
			mapData[i][j].second = false;
		}
	}

	int xMove[] = { 0,1,0,-1 };
	int yMove[] = { -1,0,1,0 };

	int blockCount = 0;

	bool stopFlag = false;


	mapData[charPosY][charPosX].second = true;	//시작위치는 방문한걸로 함
	while (!stopFlag)
	{


		//루틴 1. 왼쪽으로 회전 후 이동시키기


		if (charDir == 0) //캐릭터의 방향이 북쪽이면
			charDir = 3;
		else
			charDir -= 1;

		int newCharPosX = charPosX + xMove[charDir];
		int newCharPosY = charPosY + yMove[charDir];


		if ((newCharPosX <0 || newCharPosX > mapWidth) ||		//바다일 경우(1. 벗어난 인덱스 2. 값이 1일떄)
			(newCharPosY < 0 || newCharPosY > mapHeight) ||
			mapData[newCharPosY][newCharPosX].first == (int)mapInfo::sea)
			blockCount += 1;
		
			


		else if (mapData[newCharPosY][newCharPosX].second == false)
		{
			mapData[newCharPosY][newCharPosX].second = true;
			charPosX = newCharPosX;
			charPosY = newCharPosY;
			visitCount++;
			blockCount = 0;
		}
		//2단계. 왼쪽에 안가본 칸이 없으면 회전만 시키고 1단계로
		else if (mapData[newCharPosY][newCharPosX].second == true)
		{
			blockCount += 1;
		}
		//3단계. 네방향 이미모두 갔거나 바다인 칸이면 방향 유지한체 한칸 뒤로가고 1단계로 돌아ㅣ감. 바다일경우에는 움직임 멈추기
		
		if (blockCount == 4)
		{
			blockCount = 0;
			int backPosX = charPosX - xMove[charDir];
			int backPosY = charPosY -= yMove[charDir];

			
			if (backPosX < 0 || backPosX > mapWidth ||
				backPosY <0 || backPosY > mapHeight)
				stopFlag = true;
			else if (mapData[backPosY][backPosX].first == (int)mapInfo::sea)
				stopFlag = true;

			//바다가 아니면 뒤로뺵하기(방문여부와 관계없이)
			else
			{
				charPosX = backPosX;
				charPosY = backPosY;
			}
		}
				
	}

	cout << visitCount <<endl;

}
