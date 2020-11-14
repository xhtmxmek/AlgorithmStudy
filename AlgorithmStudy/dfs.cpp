#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[9];
vector<int> graph[9];


void dfs(int x)
{
	visited[x] = true;
	cout << x << ' ';
	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		if (!visited[y]) dfs(y);
	}
}


void bfs(int x)
{
	queue<int> q;
	q.push(x);

	visited[x] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << ' ';
		
		for (int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			if (!visited[y])
			{
				q.push(y);
				visited[y] = true;
			}
		}
		

	}

}


void bfsTest(int x, int y, int w, int h, vector<vector<int>>& graph)
{

	queue<pair<int,int>> q;

	q.push({ 0,0 });


	int result = 0;

	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };
	while (!q.empty())
	{
		int qx = q.front().first;
		int qy = q.front().second;
		q.pop();


		//for (int i = 0; i < 4; i++)
		//{
		//	int nx = qx + dx[i];
		//	int ny = qy + dy[i];

		//	if (nx < 0 || nx >= w || ny < 0 || ny >= h)
		//		continue;
		//	if (graph[ny][nx] == 0)
		//		continue;
		//	if (graph[ny][nx] == 1)
		//	{
		//		graph[ny][nx] = graph[qy][qx] + 1;
		//		q.push(ny, nx);
		//	}
		//}

		cout << graph[h - 1][w - 1];



	}
}



bool drinkDfs(int x, int y, int w, int h, vector<vector<int>>& graph)
{	
		
	if (y <= -1 || y >= h || x <= -1 || x >= w)
		return false;

	int val = graph[y][x];

	
	if (val == 0)
	{		
		graph[y][x] = 1;
		drinkDfs(x - 1, y, w,h,graph);
		drinkDfs(x + 1, y, w, h, graph);
		drinkDfs(x, y-1, w, h, graph);
		drinkDfs(x, y+1, w, h, graph);
		return true;		
	}

	return false;
}

/*
Ž���Ұ�� �ش� ���� graph�� �ش� ���� 0�ϰ�쿡�� Ž��
0���� Ž���Ϸ��µ� visited�� false�� �Ǿ� �ֱ� ������ Ž�� ����
Ž�� ������ ī��Ʈ �ø���
�״����� 1���� Ž���Ϸ��� �ص� visited[1] = true�̱� ������ Ž���Ұ�

*/
//0���� Ž���Ϸ�
//Ž���� �Ϸ� �Ǹ� ī��Ʈ �ϳ� �ø���

void drink()
{
	int result = 0;

	int n;
	int m;

	cin >> n;
	cin >> m;

	//data set
	vector< vector<int>> graphHole = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++)
		{
			int val = tmp[j] - '0';
			graphHole[i][j] = val;
		}
	}


	//dfs
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(drinkDfs(j,i, m,n,graphHole))
				result++;
		}
	}

	cout << result;

}


void MazeSolution()
{	
	//data setting
	int n;
	int m;

	cin >> n;
	cin >> m;

	vector<vector<int>> mapInfo;
	mapInfo.reserve(n);
	mapInfo.resize(n);

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			mapInfo[i].push_back(s[j] - '0');
		}
	}

	//bfs
	int result = 0;

	int dx[] = { -1,1,0,0 };	//��,��,��,��
	int dy[] = { 0,0,1,-1 };
	queue<pair<int, int>> q;
	q.push({ 0,0 });


	while (!q.empty())
	{
		int qx = q.front().first;
		int qy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = qx + dx[i];
			int ny = qy + dy[i];
			if (nx < 0 || ny < 0 ||nx >=m || ny >= n)
				continue;
			if (mapInfo[ny][nx] == 0)
				continue;
			if (mapInfo[ny][nx] == 1)
			{
				mapInfo[ny][nx] = mapInfo[qy][qx] + 1;
				q.push({ nx,ny });
			}
		}
	}
	result = mapInfo[n - 1][m - 1];

	cout << result << endl;
}


void shortCity()
{
	int n;
	int m;
	int k;
	int x;
	vector<vector<int>> mapInfo;
		

	cin >> n;
	cin >> m;
	cin >> k;
	cin >> x;

	mapInfo.reserve(n+1);
	mapInfo.resize(n+1);

	for (int i = 0; i < m; i++)
	{
		int first = 0;
		int second = 0;

		cin >> first;
		cin >> second;

		mapInfo[first].push_back(second);
	}

	vector<bool> cityVisit;
	cityVisit.reserve(n+1);
	cityVisit.resize(n+1);

	cityVisit[x] = true;

	queue<int> q;
	q.push(x);

	int dist = 0;
	vector<int> distArr;
	distArr.reserve(n+1);
	distArr.resize(n+1, 0);

	while (!q.empty())
	{
		int val = q.front();
		q.pop();
		//�湮�ߴ����!

		for (int i = 0; i < mapInfo[val].size(); i++)
		{
			int adjacentIdx = mapInfo[val][i];
			if (!cityVisit[adjacentIdx])
			{
				cityVisit[adjacentIdx] = true;
				q.push(adjacentIdx);
				dist++;
				distArr[adjacentIdx] = distArr[val] + 1;
			}
		}
	}

	int resultCnt = 0;
	for (int i = 0; i < n+1; i++)
	{
		if (distArr[i] == k)
		{
			cout << i << endl;
			resultCnt++;
		}
	}

	if (resultCnt == 0)
		cout << -1;
	
}

int virusX[] = { -1,0,1,0 };	//��,��,��,��
int virusY[] = { 0,1,0,-1 };

int arr[8][8]; // �ʱ� �� �迭
int temp[8][8]; // ���� ��ġ�� ���� �� �迭

int result = 0;


void virus(int x, int y, int n, int m)
{

	for (int i = 0; i < 4; i++)
	{
		int nx = x + virusX[i];
		int ny = y + virusY[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (temp[nx][ny] == 0)
			{
				temp[nx][ny] = 2;
				virus(nx, ny, n, m);
			}
		}							
	}
	return ;

}

// ���� �ʿ��� ���� ������ ũ�� ����ϴ� �޼���
int getScore(int n, int m) {
	int score = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) {
				score += 1;
			}
		}
	}
	return score;
}

void virusDfs(int count,int n, int m)
{
	// ��Ÿ���� 3�� ��ġ�� ���
	if (count == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = arr[i][j];
			}
		}
		// �� ���̷����� ��ġ���� ���� ����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j] == 2) {
					virus(i, j,n,m);
				}
			}
		}
		// ���� ������ �ִ밪 ���
		result = max(result, getScore(n,m));
		return;
	}
	// �� ������ ��Ÿ���� ��ġ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				count += 1;
				virusDfs(count,n,m);
				arr[i][j] = 0;
				count -= 1;
			}
		}
	}
}



void virusLab()
{
	int n;
	int m;

	cin >> n;
	cin >> m;


	for(int i = 0 ; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int val;
			cin >> val;
			arr[i][j] = val;
		}

	virusDfs(0, n, m);

	cout << result;

}

bool diseaseDfs(vector<vector<int>>& mapInfo, int x, int y, int width, int height, int time,int level,int virusNum)
{
	if (x < 0 || x >= width || y < 0 || y >= height)
		return false;


	level++;
	if (mapInfo[y][x] == 0 && level <= time)
	{		
		mapInfo[y][x] = virusNum;
		diseaseDfs(mapInfo, x - 1, y, width, height,time,level, virusNum);
		diseaseDfs(mapInfo, x + 1, y, width, height, time, level, virusNum);
		diseaseDfs(mapInfo, x, y - 1, width, height, time, level, virusNum);
		diseaseDfs(mapInfo, x, y + 1, width, height, time, level, virusNum);

		return true;
	}
	return false;
}

void disease()
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<vector<int>> mapInfo = vector<vector<int>>(n, vector<int>(n));

	for(int i = 0 ; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int tmp = 0;
			cin >> tmp;
			mapInfo[i][j] = tmp;
		}


	int s;
	cin >> s;

	vector<vector<pair<int,int>>> virusNumPos;	
	virusNumPos.reserve(k+1);
	virusNumPos.resize(k + 1);

	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int val = mapInfo[i][j];
			if (val != 0)
			{
				virusNumPos[val].push_back({i,j});
			}
		}

	sort(virusNumPos.begin(), virusNumPos.end());
	
	for (int sec = 1; sec <= s; sec++)
	{
		for (int i = 1; i < k+1; i++)
		{	
			for (int j = 0; j < virusNumPos[i].size(); j++)
			{
				int vNum = i;
				int posX = virusNumPos[i][j].first;
				int posY = virusNumPos[i][j].second;
				diseaseDfs(mapInfo, posX, posY, n, n, sec, 0, vNum);
			}

			
		}
		
	}

	int x;	
	int y;
	cin >> x;
	cin >> y;

	cout << mapInfo[y-1][x-1]<<endl;
}

//�����������ڿ��� ������ �Լ�
bool checkBalanced(const string& s)
{
	int openBranketCnt = 0;
	int closeBranketCnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			openBranketCnt++;
		else if (s[i] == ')')
			closeBranketCnt++;
	}
	if (openBranketCnt == closeBranketCnt)
		return true;
	else
		return false;
}

string branketSolution(string p) {
	string answer = "";

	if (p.empty())
		return "";



		
	return answer;
}

int main()
{ 
	string s = "(()())()";
	string s2 = ")(";
	//branketSolution(s2);
	virusLab();
	return 0;
}