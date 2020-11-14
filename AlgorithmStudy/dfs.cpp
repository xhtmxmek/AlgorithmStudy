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
탐색할경우 해당 값이 graph의 해당 값이 0일경우에만 탐색
0부터 탐색하려는데 visited가 false로 되어 있기 때문에 탐색 시작
탐색 끝나면 카운트 올리기
그다음꺼 1부터 탐색하려고 해도 visited[1] = true이기 때문에 탐색불가

*/
//0부터 탐색하려
//탐색이 완료 되면 카운트 하나 올리기

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

	int dx[] = { -1,1,0,0 };	//좌,우,상,하
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
		//방문했다출력!

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

int virusX[] = { -1,0,1,0 };	//북,동,남,서
int virusY[] = { 0,1,0,-1 };

int arr[8][8]; // 초기 맵 배열
int temp[8][8]; // 벽을 설치한 뒤의 맵 배열

int result = 0;


void virus(int x, int y, int n, int m)
{

	for (int i = 0; i < 4; i++)
	{
		int nx = x + virusX[i];
		int ny = y + virusY[i];
		if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
			if (temp[ny][nx] == 0)
			{
				temp[ny][nx] = 2;
				virus(nx, ny, n, m);
			}
		}							
	}
	return ;

}

// 현재 맵에서 안전 영역의 크기 계산하는 메서드
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


void backTrackDfs(int cnt, int n, int m)
{
	if (cnt == 3)
	{
		for(int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				temp[i][j] = arr[i][j];
			}

		for(int i = 0 ; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (temp[i][j] == 2)
					virus(j, i, n, m);
			}

		result = max(result, getScore(n,m));
		return;

	}

	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
			{
				cnt++;
				arr[i][j] = 1;
				backTrackDfs(cnt, n, m);
				arr[i][j] = 0;
				cnt--;
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

	backTrackDfs(0, n, m);

	cout << result;

}

class Virus
{
public:
	int index;
	int second;
	int posX;
	int posY;
	Virus(int idx, int sec, int x, int y)
		:index(idx),second(sec),posX(x),posY(y)
	{

	}

	bool operator<(const Virus& src)
	{
		return this->index < src.index;
	}
};

void disease()
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<vector<int>> mapInfo = vector<vector<int>>(n, vector<int>(n));

	vector<Virus> vArr;

	for(int i = 0 ; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int tmp = 0;
			cin >> tmp;
			mapInfo[i][j] = tmp;
			if (tmp != 0) //바이러스일 경우
				vArr.push_back(Virus(tmp, 0, j, i));
		}


	int s;
	cin >> s;
	int x;	
	int y;
	cin >> x;
	cin >> y;

	//bfs를 수행(그전에 정렬하여 넣어주기)

	sort(vArr.begin(), vArr.end());

	queue<Virus> q;
	
	for(int i = 0; i < vArr.size(); i++)
		q.push(vArr[i]);

	while (!q.empty())
	{
		Virus currVirus = q.front();
		q.pop();

		if (currVirus.second == s)
			break;

		for (int i = 0; i < 4; i++)
		{
			int nx = currVirus.posX + virusX[i];
			int ny = currVirus.posY + virusY[i];

			if (nx >= 0 && nx < n && ny>=0 && ny < n)
			{
				if (mapInfo[ny][nx] == 0)
				{
					mapInfo[ny][nx] = currVirus.index;
					q.push(Virus(currVirus.index, currVirus.second + 1, nx, ny));
				}
			}
		}
	}

	cout << mapInfo[y-1][x-1]<<endl;
}

//균형잡힌문자열을 나누는 함수
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
	disease();
	return 0;
}