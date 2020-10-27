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

bool newCheck(vector< vector<int>> src)
{
	int lockLength = src.size() / 3;

	for(int i  = lockLength ; i < lockLength * 2; i++)
		for (int j = lockLength; j < lockLength * 2; j++)
		{
			if (src[i][j] != 1)
				return false;
		}

	return true;
}


void LockNKey()
{
	//�־��� ����
	vector<vector<int>> lock;

	vector<vector<int>> key;


	bool result = false;
	int lockSize = 0;
	int keySize = 0;

	cin >> lockSize;
	cin >> keySize;


	vector<vector<int>> newLock(lockSize * 3,  vector<int>(lockSize * 3));

	//����� ���� ���� �ֱ�
	for (int i = 0; i < lockSize; i++)
	{
		for (int j = 0; j < lockSize; j++)
		{
			newLock[i + lockSize][j + lockSize] = lock[i][j];
		}
	}

	

	for (int rotation = 0; rotation < 4; rotation++)
	{
		key = rotateClockWiseMatrixBy90Degree(key);

		for (int i = 0; i < lockSize * 2; i++)
		{
			for (int j = 0; j < lockSize * 2; j++)
			{
				//�ڹ��迡 ��������
				for (int y = 0; y < keySize; y++)
				{
					for (int x = 0; x < lockSize; x++)
					{
						newLock[i + y][j + x] += key[y][x];
					}
				}

				if (newCheck(newLock))
				{
					result = true;
					cout << "��� ����";
					return;
				}

				//�ڹ��迡�� �ٽ� ����
				for (int y = 0; y < keySize; y++)
				{
					for (int x = 0; x < lockSize; x++)
					{
						newLock[i + y][j + x] -= key[y][x];
					}
				}
					
			}
		}
	}


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


struct PointData
{
	bool none;
	bool columnBot;
	bool columnTop;
	bool paperLeft;
	bool paperRight;
};

vector<vector<int>> buildsolution(int n, vector<vector<int>> build_frame) {				//gg
	vector<vector<int>> answer;

	vector<vector<PointData>> mapInfo(n+1, vector<PointData>(n+1));

	for (int i = 0; i < n+1; i++)
		for (int j = 0; j < n+1; j++)
		{
			mapInfo[i][j].none = true;
			mapInfo[i][j].columnBot= false;
			mapInfo[i][j].columnTop = false;
			mapInfo[i][j].paperLeft = false;
			mapInfo[i][j].paperRight = false;

		}
			//0: �ƹ��͵� ���� 1: ��չص� 2: ������� 3: ���� ���� 4:���� ������

	for (int i = 0; i < build_frame.size(); i++)
	{
		int px = build_frame[i][0];
		int py = build_frame[i][1];

		//1)����� ���
		if (build_frame[i][2] == 0)
		{
			if (build_frame[i][3] == 1)	//��ġ�� ���?
			{				
				if (mapInfo[px][py].none == false ||
					(mapInfo[px][py].none == true && py == 0))	//��ġ�Ϸ��� ��ġ�� �ٴ��̰ų� ��������̰ų� ���� �� ���̵� �� �ϳ��϶�
				{
					//mapInfo[px][py + 1].column = 1;
					mapInfo[px][py].columnBot = true;
					mapInfo[px][py].none = false;

					mapInfo[px][py+1].columnTop = true;
					mapInfo[px][py + 1].none = false;
				}
				//����� ��쿣 ��ġ x
			}
			else
			{
				//����� �����ϴ� ��� --> ���� ���� ������ ���� ����
				if (!mapInfo[px][py + 1].paperLeft&&
					!mapInfo[px][py + 1].paperRight)
				{
					mapInfo[px][py].columnBot = false;
					mapInfo[px][py+1].columnTop = false;
				}
			}
		}
		else
		{
			//2) ���ϰ��
			if (build_frame[i][3] == 1)	//��ġ�� ���?
			{
				if ((mapInfo[px][py-1].columnBot == true || mapInfo[px+1][py - 1].columnBot == true)||
					(mapInfo[px][py].paperRight && mapInfo[px + 1][py].paperLeft))	//��ġ�Ϸ��� ��ġ�� ��������̰ų� �� ���̵忡 ���� ������
				{					
					mapInfo[px][py].paperLeft = true;
					mapInfo[px][py].none = false;
					mapInfo[px+1][py].paperRight = true;
					mapInfo[px + 1][py].none = false;
					
				}
				//����� ��쿣 ��ġ x
			}
			else
			{
				//���� �����ϴ� ��� -> ���� ���� ������ �Ǵ� �翷�� �ƹ��͵� ������ ���� ����
				
				if ((py + 1 < n+1 && mapInfo[px][py + 1].none) ||
					(mapInfo[px][py].paperRight == false &&
					(px + 1 < n+1 && mapInfo[px + 1][py].paperLeft==false)))
				{
					mapInfo[px][py].paperLeft = false;									
					mapInfo[px + 1][py].paperRight = false;

				}				
			}

		}

		if (!mapInfo[px][py].columnBot &&
			!mapInfo[px][py].columnTop &&
			!mapInfo[px][py].paperLeft &&
			!mapInfo[px][py].paperRight)
			mapInfo[px][py].none = true;
	}

	for(int i = 0 ; i < n+1; i++)
		for (int j = 0; j < n+1; j++)
		{
			if (!mapInfo[i][j].none)
			{
				vector<int> temp;
				temp.push_back(i);
				temp.push_back(j);
				int column = (mapInfo[i][j].columnBot) ? 0 : 1;
				temp.push_back(column);				
				answer.push_back(temp);
			}
		}

	return answer;
}


void Chicken()
{
	int n;
	int m;
	cin >> n;
	cin >> m;

	vector<vector<int>> mapInfo(n, vector<int>(n));

	vector<pair<int, int>> chickenStores;
	for(int i = 0 ; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int tmp = 0;
			cin >> tmp;
			if (tmp == 2)
				chickenStores.push_back({ n,n });
			mapInfo[i][j] = tmp;
		}


	//ġŲ �Ÿ� ���ϱ�

	int execeptIdx = 0;
	int minDist = (n-1)*2;
	int cityChickDist = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (mapInfo[i][j] == 1)
			{
				for (int k = 0; k < chickenStores.size(); k++)
				{
					if (k != execeptIdx)
					{
						int dist = abs(i - chickenStores[k].first) + abs(j - chickenStores[k].second);
						minDist = min(minDist, dist);
					}
				}
			}
		}



}


