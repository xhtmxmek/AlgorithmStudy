#include <iostream>
#include <vector>
#include <string>
#include "implement.h"
#include <algorithm>
#include <queue>
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


void gameSimulate()
{
	int n;
	int m;
	int dir;

	cin >> n;
	cin >> m;

	int charPosX = 0;
	int charPosY = 0;
	cin >> charPosX;
	cin >> charPosY;

	cin >> dir;


	int dirX[] = { 0,1,0,-1 };	//��,��,��,��
	int dirY[] = { -1,0,1,0 };
	vector<vector<pair<int, bool>>> mapInfo = vector<vector<pair<int, bool>>>(n, vector<pair<int, bool>>(m, { 0,false }));

	for(int i = 0 ; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int tmp = 0;
			cin >> tmp;
			mapInfo[i][j].first = tmp;
			mapInfo[i][j].second = false;
		}




	mapInfo[charPosY][charPosX].second = true;

	int result = 0;
	bool endFlag = false;
	while (!endFlag)
	{
		//1. ���� ���� �������� ���ʹ��⿡ ������ ���� ĭ�� �ִ��� Ȯ���Ѵ�. �̰������� ������ �������� ȸ���Ѵ�.
		dir -= 1;
		if (dir < 0)
			dir = 3;
		//2. ����ĭ�� ����ĭ���� �Ȱ���ĭ���� Ȯ��.
		int nx = charPosX + dirX[dir];
		int ny = charPosY + dirY[dir];


		int failFlag = 0;

		int result = 0;
		bool IsSea = ((nx<0 || nx >= m || ny<0 || ny>=n) || mapInfo[ny][nx].first == 1) ? true : false;
		//for (int i = 0; i < 4; i++)
		
			//�������ϴ� ��� 1. �ٴ��ϰ��
			if (IsSea || mapInfo[ny][nx].second == true)
			{
				failFlag++;
				if (failFlag == 4)
				{
					int tempX = charPosX - dirX[dir];
					int tempY = charPosY - dirY[dir];
					if ((tempX < 0 || tempX >= m || tempY < 0 || tempY >= n) || mapInfo[tempY][tempX].first == 1)
					{
						endFlag = true;
						cout << result;

					}
						
					else
					{
						charPosX = tempX;
						charPosY = tempY;
						result++;
						failFlag = 0;
					}
				}
			}
												
			//�Ȱ��� ĭ�̰� �����ϰ�� �ش�������� ����.
			else if (mapInfo[ny][nx].second == false && mapInfo[ny][nx].first == 0)
			{				
				mapInfo[ny][nx].second == true;
				charPosX = nx;
				charPosY = ny;				
				result++;
				failFlag = 0;
			}			
		


	}
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


	vector<vector<pair<int, bool>>> mapData;	//�ι�° bool�� ������ �湮���θ� üũ��
	
	

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


	mapData[charPosY][charPosX].second = true;	//������ġ�� �湮�Ѱɷ� ��
	while (!stopFlag)
	{


		//��ƾ 1. �������� ȸ�� �� �̵���Ű��


		if (charDir == 0) //ĳ������ ������ �����̸�
			charDir = 3;
		else
			charDir -= 1;

		int newCharPosX = charPosX + xMove[charDir];
		int newCharPosY = charPosY + yMove[charDir];


		if ((newCharPosX <0 || newCharPosX > mapWidth) ||		//�ٴ��� ���(1. ��� �ε��� 2. ���� 1�ϋ�)
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
		//2�ܰ�. ���ʿ� �Ȱ��� ĭ�� ������ ȸ���� ��Ű�� 1�ܰ��
		else if (mapData[newCharPosY][newCharPosX].second == true)
		{
			blockCount += 1;
		}
		//3�ܰ�. �׹��� �̸̹�� ���ų� �ٴ��� ĭ�̸� ���� ������ü ��ĭ �ڷΰ��� 1�ܰ�� ���ƤӰ�. �ٴ��ϰ�쿡�� ������ ���߱�
		
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

			//�ٴٰ� �ƴϸ� �ڷΕ��ϱ�(�湮���ο� �������)
			else
			{
				charPosX = backPosX;
				charPosY = backPosY;
			}
		}
				
	}

	cout << visitCount <<endl;

}

void luckyStraight()
{
	string score;

	cin >> score;


	int halfSize = score.length() / 2;
	string leftScoreStr = score.substr(0, halfSize);

	string rightScoreStr = score.substr(halfSize, halfSize);

	int leftScore = 0;

	for (int i = 0; i < leftScoreStr.length(); i++)
		leftScore += (leftScoreStr[i] - '0');

	int rightScore = 0;

	for (int i = 0; i < rightScoreStr.length(); i++)
		rightScore += (rightScoreStr[i] - '0');

	if (leftScore == rightScore)
		cout << "LUCKY"<<endl;
	else
		cout << "READY"<<endl;
}


void stringSort()
{
	string data;
	cin >> data;

	vector<char> strData;

	int numValue = 0;
	for (int i = 0; i < data.length(); i++)
	{
		char c1 = data[i];
		if (c1 < '0' || c1 > '9')
			strData.push_back(c1);
		else if (c1 >= '0' && c1 <= '9')
			numValue += (data[i] - '0');
	}
	sort(strData.begin(), strData.end());

	for (int i = 0; i < strData.size(); i++)
		cout << strData[i];
	cout << numValue<<endl;
}

//���ڿ� ���๮�� x--

void stringZipSolution()
{

	string s;

	cin >> s;
	int unit = 1;

	//������ 1�� ���


	int sameCount = 1;

	string str;

	int result = 0;

	result = s.length();
	for (int j = 1; j <= s.length() / 2; j++)
	{
		sameCount = 1;
		str.clear();
		unit = j;
		string compareStr = s.substr(0, unit);
		for (int i = unit; i < s.length(); i = i + unit)	
		{

			if (s.substr(i, unit) == compareStr)
			{
				sameCount++;
			}
			else
			{
				if (sameCount > 1)
					str += to_string(sameCount);
				str += compareStr;
				sameCount = 1;
				compareStr = s.substr(i, unit);
			}

		}

		if (sameCount > 1)
			str += to_string(sameCount);
		str += compareStr;

		result = std::min(result, (int)str.length());
	}

	cout << result;
}


//����� Ű ����	x--

vector<vector<int> > rotateClockWiseMatrixBy90Degree(vector<vector<int> > a) {
	int n = a.size(); // �� ���� ���
	int m = a[0].size(); // �� ���� ���
	vector<vector<int> > result(n, vector<int>(m)); // ��� ����Ʈ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result[j][n - i - 1] = a[i][j];
		}
	}
	return result;
}

// �ڹ����� �߰� �κ��� ��� 1���� Ȯ��
bool check(vector<vector<int> > newLock) {
	int lockLength = newLock.size() / 3;
	for (int i = lockLength; i < lockLength * 2; i++) {
		for (int j = lockLength; j < lockLength * 2; j++) {
			if (newLock[i][j] != 1) {
				return false;
			}
		}
	}
	return true;
}

bool solution(vector<vector<int> > key, vector<vector<int> > lock) {
	int n = lock.size();
	int m = key.size();
	// �ڹ����� ũ�⸦ ������ 3��� ��ȯ
	vector<vector<int> > newLock(n * 3, vector<int>(n * 3));
	// ���ο� �ڹ����� �߾� �κп� ������ �ڹ��� �ֱ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			newLock[i + n][j + n] = lock[i][j];
		}
	}

	// 4���� ���⿡ ���ؼ� Ȯ��
	for (int rotation = 0; rotation < 4; rotation++) {
		key = rotateClockWiseMatrixBy90Degree(key); // ���� ȸ��
		for (int x = 0; x < n * 2; x++) {
			for (int y = 0; y < n * 2; y++) {
				// �ڹ��迡 ���踦 ���� �ֱ�
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < m; j++) {
						newLock[x + i][y + j] += key[i][j];
					}
				}
				// ���ο� �ڹ��迡 ���谡 ��Ȯ�� ��� �´��� �˻�
				if (check(newLock)) return true;
				// �ڹ��迡�� ���踦 �ٽ� ����
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < m; j++) {
						newLock[x + i][y + j] -= key[i][j];
					}
				}
			}
		}
	}
	return false;
}


bool newCheck(vector<vector<int>> newLock)
{
	int length = newLock.size() / 3;
	for(int i = length; i < newLock.size() * 2; i++)
		for (int j = length; j < newLock.size() * 2; j++)
		{
			if (newLock[i][j] != 1)
				return false;
		}

	return true;
}

bool newLockSolution(vector<vector<int>> lock, vector<vector<int>> key)
{
	int n = lock.size();
	int m = key.size();

	//3�� Ű�� ���ο� �ڹ��� �����
	vector<vector<int>> newLock = vector<vector<int>>(n * 3, vector<int>(n * 3, 0));

	//��� �κ� 0���� ä���
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			newLock[i + n][j + n] = lock[i][j];
		}


	//ȸ�����Ѱ��� ��ĭ�� �ű�� ���纸��
	for (int i = 0; i < 4; i++)
	{
		key = rotateClockWiseMatrixBy90Degree(key);

		//���� �Ⱦƺ���
		for(int x = 0 ; x < n*2; x++)
			for (int y = 0; y < n * 2; y++)
			{
				for(int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
					{
						newLock[x + i][y + j] += key[i][j];
					}

				//Ű �žƺ��� üũ
				if (newCheck(newLock))
					return true;

				//���� �ٽ� ����
				
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
					{
						newLock[x + i][y + j] -= key[i][j];
					}
			}		
	}

	return false;
}





void snake()
{
	int mapWidth;
	int mapHeight;

	cin >> mapWidth;

	mapHeight = mapWidth;

	int appleCnt = 0;

	cin >> appleCnt;

	vector<vector<int>> mapInfo;		//0�� �ƹ��͵� ����. 1�� ����� �����Ѵٴ°�. 2�� ���� ���� ��ġ�Ѵٴ� ��

	mapInfo.reserve(mapHeight);
	mapInfo.resize(mapHeight);

	for (int i = 0; i < mapHeight; i++)
	{
		mapInfo[i].reserve(mapWidth);
		mapInfo[i].resize(mapWidth,0);
	}
		
	for (int i = 0; i < appleCnt; i++)
	{
		int tmpX = 0;
		int tmpY = 0;
		cin >> tmpY >> tmpX;

		mapInfo[tmpY-1][tmpX-1] = 1;
	}

	int dirChangeCnt = 0;

	cin >> dirChangeCnt;

	vector<pair<int, char>> dirInfo;


	for (int i = 0; i < dirChangeCnt; i++)
	{
		int sec = 0;
		cin >> sec;
		char dir;
		cin >> dir;
		dirInfo.push_back({ sec, dir });
	}

	int sec = 0;

	int sHPosX = 0;	//�Ӹ��� ��ġ
	int sHPosY = 0;

	int snakeDirX[] = { 0,1,0,-1 };	//��,��,��,��
	int snakeDirY[] = { -1,0,1,0 };

	//���ʿ��� �������� ����

	int dir = 1;
	mapInfo[sHPosY][sHPosX] = 2;

	queue<pair<int, int>> snakePos;	//posY,posX
	snakePos.push({ sHPosY,sHPosX});



	int idx = 0;

	while (true)
	{

		int nX = sHPosX + snakeDirX[dir];
		int nY = sHPosY + snakeDirY[dir];

		sec++;
		//���� �ε����ų� �ڱ� �ڽŰ� ��������
		if ((nX < 0 || nX > mapWidth - 1) ||
			(nY < 0 || nY > mapHeight - 1) ||
			mapInfo[nY][nX] == 2)
		{
			break;
		}


			if (mapInfo[nY][nX] == 1)		//����� ������� ������ �״�� �α�
			{
				mapInfo[nY][nX] = 2;
				snakePos.push({ nY, nX });
			}
			else
			{
				mapInfo[nY][nX] = 2;
				snakePos.push({ nY,nX });
				int tailPosX = snakePos.front().second;
				int tailPosY = snakePos.front().first;
				snakePos.pop();
				mapInfo[tailPosY][tailPosX] = 0;

			}
		

		sHPosX = nX;
		sHPosY = nY;

		if (idx < dirChangeCnt && sec == dirInfo[idx].first) { // ȸ���� �ð��� ��� ȸ��			
			if (dirInfo[idx].second == 'D')
				dir++;
			else if (dirInfo[idx].second == 'L')
				dir--;
			if (dir < 0)
				dir = 3;
			else if (dir > 3)
				dir = 0;
			
			idx += 1;
		}


		

	}

	cout << sec;
}


bool possible(vector<vector<int>> answer)
{
	for (int i = 0; i < answer.size(); i++)
	{
		int x = answer[i][0];
		int y = answer[i][1];
		int stuff = answer[i][2];

		//����ϰ��
		if (stuff == 0)
		{
			bool check = false;
			if (y == 0)
				check = true;

			for (int j = 0; j < answer.size(); j++)
			{
				//����� ���ϰ��
				if (x == answer[j][0] && y - 1 == answer[j][1] && answer[j][2] == 0)
					check = true;
				//���� ���� ���
				if (x - 1 == answer[j][0] && y == answer[j][1] && answer[j][2] == 1)
					check = true;
				if (x == answer[j][0] && y == answer[j][1] && answer[j][2] == 1)
					check = true;
			}

			if (!check)
				return false;
		}
		
		//���� ���
		if (stuff == 1)
		{
			bool check = false;
			bool left = false;
			bool right = false;
			for (int j = 0; j < answer.size(); j++)
			{
				//���� ���κ��� ����� ���� ���
				if (x == answer[j][0] && y - 1 == answer[j][1] && answer[j][2] == 0)
					check = true;
				if (x + 1 == answer[j][0] && y - 1 == answer[j][1] && answer[j][2] == 0)
					check = true;
				//���ʳ��� ���� ���
				if (x - 1 == answer[j][0] && y == answer[j][1] && answer[j][2] == 1)
					left = true;
				if (x + 1 == answer[j][0] && y == answer[j][1] && answer[j][2] == 1)
					right = true;

			}

			if (left && right) check = true;
			if (!check)
				return false;
		}

	}
	return true;
}

vector<vector<int>> buildsolution(int n, vector<vector<int>> build_frame) 

{				
	vector<vector<int>> answer;

	for (int i = 0; i < build_frame.size(); i++)
	{
		int x = build_frame[i][0];
		int y = build_frame[i][1];
		bool stuff = build_frame[i][2];

		bool eraseCheck = build_frame[i][3];

		int eraseIdx = 0;
		if (eraseCheck == 0)	//����
		{
			for (int j = 0; j < build_frame.size(); j++)
			{
				if (x == answer[j][0] && y == answer[j][1] && stuff == answer[j][2])
					eraseIdx = j;
			}

			vector<int> erased = answer[eraseIdx];
			answer.erase(answer.begin() + eraseIdx);
			if (!possible(answer))
				answer.push_back(erased);
		}
		else
		{
			vector<int> temp;
			temp.push_back(x);
			temp.push_back(y);
			temp.push_back(stuff);
			answer.push_back(temp);
			if (!possible(answer))
				answer.pop_back();
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}


//����? ���չ���?

int getSum(vector<pair<int, int>>& candidates, vector<pair<int,int>>& house)

{
	int result = 0;

	for (int i = 0; i < house.size(); i++)
	{
		int hx = house[i].first;
		int hy = house[i].second;

		int minimum = 1e9;
		for (int j = 0; j < candidates.size(); j++)
		{
			int cx = candidates[j].first;
			int cy = candidates[j].second;

			minimum = min(minimum, abs(cx - hx) + abs(cy - hy));
		}

		result += minimum;
	}

	return result;
}
void Chicken()
{
	int n;
	int m;

	vector<pair<int, int>> houses;
	vector<pair<int, int>> chickens;
	cin >> n;
	cin >> m;

	vector<vector<int>> mapInfo = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int tmp = 0;
			cin >> tmp;
			mapInfo[i][j] = tmp;

			//�Ϲ����ϰ��
			if (tmp == 0)
				houses.push_back({ i,j });
			else if (tmp == 1)
				chickens.push_back({ i,j });
		}

	//ġŲ�� �߿��� m���� ġŲ���� �̴´�
	vector<bool> binary(chickens.size());
	fill(binary.end() - m, binary.end(), true);

	int result = 1e9;

	do {
		vector < pair<int, int>> now;
		for (int i = 0; i < chickens.size(); i++)
		{
			if (binary[i])
			{
				int cx = chickens[i].first;
				int cy = chickens[i].second;
				now.push_back({ cx,cy });
			}
		}

		result = min(result, getSum(now,houses));

	} while (next_permutation(binary.begin(), binary.end()));
	
}

int restorantSolution(int n, vector<int> weak, vector<int> dist) {
	// ���̸� 2��� �÷��� '����'�� ���� ���·� ����
	int length = weak.size();
	for (int i = 0; i < length; i++) {
		weak.push_back(weak[i] + n);
	}
	// ������ ģ�� ���� �ּڰ��� ã�ƾ� �ϹǷ� len(dist) + 1�� �ʱ�ȭ
	int answer = dist.size() + 1;
	// 0���� length - 1������ ��ġ�� ���� ���������� ����
	for (int start = 0; start < length; start++) {
		// ģ���� �����ϴ� ��� ��� ������ ���Ͽ� Ȯ��
		do {
			int cnt = 1; // ������ ģ���� ��
			// �ش� ģ���� ������ �� �ִ� ������ ��ġ
			int position = weak[start] + dist[cnt - 1];
			// ���������� ��� ����� ������ Ȯ��
			for (int index = start; index < start + length; index++) {
				// ������ �� �ִ� ��ġ�� ����� ���
				if (position < weak[index]) {
					cnt += 1; // ���ο� ģ���� ����
					if (cnt > dist.size()) { // �� ������ �Ұ����ϴٸ� ����
						break;
					}
					position = weak[index] + dist[cnt - 1];
				}
			}
			answer = min(answer, cnt); // �ּڰ� ���
		} while (next_permutation(dist.begin(), dist.end()));
	}
	if (answer > dist.size()) {
		return -1;
	}
	return answer;
}

int resSol(int n, vector<int> weak, vector<int> dist)
{
	int length = weak.size();
	for (int i = 0; i < length; i++)
		weak.push_back(weak[i] + n);

	int answer = dist.size() + 1;

	for (int start = 0; start < length; start++)
	{
		do {
			int cnt = 1;
			//ģ���� �����Ҽ� �ִ� ������ ������
			int position = start + dist[cnt - 1];

			//���������� ������� Ȯ��
			for (int index = start; index < start + length; index++)
			{
				if (position < weak[index])
				{
					cnt++;
					if (cnt > dist.size())
						break;

					position = weak[index] + dist[cnt - 1];
				}
				

			}
			answer = min(answer, cnt);

		} while (next_permutation(dist.begin(), dist.end()));
		
	}
	if (answer > dist.size()) {
		return -1;
	}
	return answer;
}

void luckyStraightNew()
{
	string score;
	cin >> score;


	//���� ������ ��
	int leftSum = 0;
	for (int i = 0; i < score.length() / 2; i++)
	{
		int num = score[i] - '0';		
		leftSum += num;
	}

	//������ ������ ��
	int rightSum = 0;
	for (int i = score.length() / 2; i < score.length(); i++)
	{
		int num = score[i] - '0';
		rightSum += num;
	}

	if (leftSum == rightSum)
		cout << "LUCKY";
	else
		cout << "READY";
	
}

void stringSortNew()
{
	string s;
	cin >> s;

	string result;
	int sum = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] < '0' || s[i]>'9')
			result.push_back(s[i]);
		else
			sum += s[i] - '0';
	}

	sort(result.begin(), result.end());

	result = result + to_string(sum);

	cout << result;
}



void snakeNew()
{
	int n = 0;
	int appleCnt = 0;

	cin >> n;
	cin >> appleCnt;

	vector<vector<int>> mapInfo = vector<vector<int>>(n, vector<int>(n, 0));
	
	queue<pair<int, int>> snakePos;

	snakePos.push({ 0, 0 });

	mapInfo[0][0] = 2;
	int snakedirX[] = { 1,0,-1,0 };			//��,��,��,�� ������
	int snakedirY[] = { 0,1,0,-1 };

	int snakeDir = 0;

	for (int i = 0; i < appleCnt; i++)
	{
		int tmpX = 0;
		int tmpY = 0;
		cin >> tmpY;
		cin >> tmpX;
		mapInfo[tmpY-1][tmpX-1] = 1;
	}

	int sec = 0;

	int dirChangeCnt = 0;
	cin >> dirChangeCnt;
	vector<pair<int, char>> dirInfo;
	for (int i = 0; i < dirChangeCnt; i++)
	{
		int time = 0;
		char direction;

		cin >> time;
		cin >> direction;

		dirInfo.push_back({ time,direction });
	}

	int dirIdx = 0;
	while (true)
	{
		sec++;

		int nx = snakePos.back().first + snakedirX[snakeDir];
		int ny = snakePos.back().second + snakedirY[snakeDir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			break;

		if (mapInfo[ny][nx] == 2)
			break;

		snakePos.push({ nx,ny });	//�Ӹ� ��ġ ����
	
		//0. �ƹ��͵� ���� 1. ��� 2. ���� ����

		//�����κ��� �ʻ��µ� ǥ���ϱ�.
		int tX = snakePos.front().first;
		int tY = snakePos.front().second;
		if (mapInfo[ny][nx] == 1)
		{
			mapInfo[ny][nx] = 2;	//���� ���°��� �ʿ� ǥ�⸦ �صд�.

		}
			
		else if(mapInfo[ny][nx] == 0)
		{
			mapInfo[ny][nx] = 2;	//���� ���°��� �ʿ� ǥ�⸦ �صд�
			mapInfo[tY][tX] = 0;
			snakePos.pop();			//���� �ڸ���
		}
		
		if (dirIdx < dirChangeCnt && sec == dirInfo[dirIdx].first)
		{
			if (dirInfo[dirIdx].second == 'L')
				snakeDir -= 1;				
			else
				snakeDir += 1;
				
			if (snakeDir < 0)
				snakeDir = 3;
			else if (snakeDir > 3)
				snakeDir = 0;

			dirIdx++;			
		}
		
	}

	cout << sec;
}


//int main()
//{
//	snakeNew();
//	return 0;
//}