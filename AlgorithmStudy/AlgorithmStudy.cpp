// AlgorithmStudy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include "GreedyExample.h"
#include "implement.h"

using namespace std;


int number = 7;

struct node
{
	bool visited;
	vector<node*> child;
	int key;
};


void bfs(node& start)
{
	queue<node> q;

	start.visited = true;
	q.push(start);

	while (!q.empty())
	{
		node x = q.front();
		q.pop();
		cout << x.key << endl;

		for (int i = 0; i < x.child.size(); i++)
		{
			if (!x.child[i]->visited)
			{
				x.child[i]->visited = true;
				q.push(*x.child[i]);
			}

		}

	}
}

void dfs(node& start)
{
	if (start.visited)
		return;
	start.visited = true;
	cout << start.key << endl;
	for (int i = 0; i < start.child.size(); i++)
	{
		dfs(*start.child[i]);
	}
}


//부모 노드를 찾는 함수
int getParent(int parent[], int x)
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

//부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a < b) parent[b] = a;
	else
		parent[a] = b;
}

bool checkSameParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return true;
	else
		return false;
}

struct Edge
{
public:
	int Node[2];
	int Length;

public:
	Edge(int nodeA, int nodeB, int length)
	{
		Node[0] = nodeA;
		Node[1] = nodeB;
		Length = length;
	}

	const bool operator <(const Edge& src)
	{
		return this->Length < src.Length;
	}
};

typedef struct TreeNode* TreePointer;

typedef struct TreeNode
{
	int data;
	TreePointer lChild, rChild;
};

//전위 순회
void preOrder(TreePointer ptr)
{
	if (ptr)
	{
		cout << ptr->data << endl;
		preOrder(ptr->lChild);
		preOrder(ptr->rChild);
	}
}

//중위순회
void inOrder(TreePointer ptr)
{
	if (ptr)
	{
		inOrder(ptr->lChild);
		cout << ptr->data << endl;
		inOrder(ptr->rChild);
	}
}

//후위순회
void postOrder(TreePointer ptr)
{
	if (ptr)
	{
		postOrder(ptr->lChild);
		postOrder(ptr->rChild);
		cout << ptr->data << endl;
	}
}

int dReferArr[100001]; //문제에 따라 원소 갯수가 바뀜

int dp(int x)
{
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (dReferArr[x] != 0) return dReferArr[x];
	return dReferArr[x] = dp(x - 1) + dp(x - 2);
}

int dpTiling(int x)
{
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (dReferArr[x] != 0) return dReferArr[x];
	return dReferArr[x] = dpTiling(x - 1) + dpTiling(x - 2) % 10007;
}

int dpTiling2(int x)
{
	if (x == 0) return 1;
	if (x == 1) return 0;
	if (x == 2) return 3;

	if (dReferArr[x] != 0) return dReferArr[x];
	int result = 3 * dpTiling2(x - 2);
	for (int i = 3; i <= x; i++)
	{
		if (i % 2 == 0)
			result += 2 * dpTiling2(x - i);

	}

	return dReferArr[x] = result;
}

int dpTiling3(int x)
{
	if (x == 0) return 1;
	if (x == 1) return 2;
	if (x == 2) return 7;
	if (dReferArr[x] != 0) return dReferArr[x];
	int result = 3 * dpTiling3(x - 2) + 2 * dpTiling3(x - 1);
	for (int i = 3; i <= x; i++)
		result += (2 * dpTiling3(x - i)) % 100000007;

	return dReferArr[x] = result % 100000007;
}

void greedy2_Multy_Add()
{
	int result = 0;
	int sum = 0;

	string s;
	cin >> s;

	sum = s[0] - '0';
	for (int i = 1; i < s.length(); i++)
	{
		int lhs = sum;
		int rhs = s[i] - '0';
		if ((lhs == 0 || lhs == 1) ||
			(rhs == 0 || rhs == 1))
			sum = (lhs + rhs);
		else
			sum = (lhs * rhs);
	}

	cout << sum << endl;

	return;
}


void greedy3_string()
{
	string s;
	cin >> s;

	
	bool changeFlag = false;
	for (int i = 1; i < s.length(); i++)
	{
		int pre = s[i - 1] - '0';
		int current = s[i] - '0';
		int next = s[i + 1] - '0';
		
		if (current != pre) changeFlag = true;

		if (changeFlag&&current == next)
		{
			switch (current)
			{
			case 1: 
				s[i] = '0';
			case 0:
				s[i] = '1';
			}
		}
		else
		{
			switch (current)
			{
			case 1:
				s[i] = '0';
			case 0:
				s[i] = '1';
			}

		//	changeflag = false;
			
		}
		
		//한번에 뒤집어야 하는 반복수 조건. 
		//1.curr가 pre 숫자와 다르고(flag Check)바로 next가 자신과 같다.
		//or 2. curr가 pre와 같은데 flag가 체크되어있다. 이경우 해당하는 수는 뒤집어 준다.
		//3. 둘다 해당하지 않을 경우에 flag를 false로 해준다.
		//4. 둘다 해당하지 않을경우 .else로 빼서 모든 수를 그냥 뒤집어 준다.
		//if(lhs==rhs)

	}
}


//void greedy4_balling()




int main()
{
	//dfs, bfs test code
	/*
	//vector<node> tree;
	//tree.reserve(7);
	//tree.resize(7);

	//tree[0].key = 1;
	//tree[0].visited = false;
	//tree[0].child.push_back(&tree[1]);
	//tree[0].child.push_back(&tree[2]);

	//tree[1].key = 2;
	//tree[1].visited = false;
	//tree[1].child.push_back(&tree[2]);
	//tree[1].child.push_back(&tree[3]);
	//tree[1].child.push_back(&tree[4]);

	//tree[2].key = 3;
	//tree[2].visited = false;
	//tree[2].child.push_back(&tree[1]);
	//tree[2].child.push_back(&tree[5]);
	//tree[2].child.push_back(&tree[6]);

	//tree[3].key = 4;
	//tree[3].visited = false;
	//tree[3].child.push_back(&tree[1]);

	//tree[4].key = 5;
	//tree[4].visited = false;
	//tree[4].child.push_back(&tree[1]);

	//tree[5].key = 6;
	//tree[5].visited = false;
	//tree[5].child.push_back(&tree[2]);

	//tree[6].key = 7;
	//tree[6].visited = false;
	//tree[6].child.push_back(&tree[2]);

	//dfs(tree[0]);
	*/

	//int parentArr[11];
	//for (int i = 1; i <= 10; i++)
	//    parentArr[i] = i;

	//unionParent(parentArr, 1, 2);
	//unionParent(parentArr, 2, 3);
	//unionParent(parentArr, 3, 4);
	//unionParent(parentArr, 5, 6);
	//unionParent(parentArr, 6, 7);
	//unionParent(parentArr, 7, 8);

	//vector<Edge> v;

	////node 1
	//v.push_back(Edge(1, 7, 12));
	//v.push_back(Edge(1, 4, 28));
	//v.push_back(Edge(1, 2, 67));
	//v.push_back(Edge(1, 5, 17));

	////node 2    
	//v.push_back(Edge(2, 4, 24));
	//v.push_back(Edge(2, 5, 62));

	////node 3
	//v.push_back(Edge(3, 5, 20));
	//v.push_back(Edge(3, 6, 37));

	////node 4
	//v.push_back(Edge(4, 7, 13));

	////node 5
	//v.push_back(Edge(5, 6, 45));
	//v.push_back(Edge(5, 7, 73));

	//
	////간선의 비용으로 오름차순 정렬
	//std::sort(v.begin(), v.end());

	////각 정점이 포함된 그래프가 어디인지 저장
	//int set[7];
	//for (int i = 0; i < 7; i++)
	//    set[i] = i;

	////거리의 합을 0으로 초기화
	//int sum = 0;
	//for (int i = 0; i < v.size(); i++)
	//{
	//    //동일한 부모를 가르키지 않는 경우, 사이클이 발생하지 않을 경우에만 선택
	//    if (!checkSameParent(set, v[i].Node[0] - 1, v[i].Node[1] - 1)) {
	//        sum += v[i].Length;
	//        unionParent(set, v[i].Node[0] - 1, v[i].Node[1] - 1);
	//    }

	//}

	//cout << sum << endl;

	//int nodeCnt = 15;

	//TreeNode Node[16];

	//for (int i = 1; i <= nodeCnt; i++)
	//{
	//    Node[i].data = i;
	//    Node[i].lChild = nullptr;
	//    Node[i].rChild = nullptr;
	//}

	//for (int i = 1; i <= nodeCnt; i++)
	//{
	//    if (i % 2 == 0)
	//        Node[i / 2].lChild = &Node[i];
	//    else
	//        Node[i / 2].rChild = &Node[i];
	//}

	//preOrder(&Node[1]);


	//cout << dp(30) << endl;

//int value = 0;
//cin >> value;
//cout<<dpTiling3(value);


/*
//그리디 실전 1번 나의 풀이
	int n;
	vector<int> arr;

	cin >> n;
	arr.reserve(n);
	arr.resize(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];


	int selectableMem = n;

	std::sort(arr.begin(), arr.end());

	int numParty = 0;
	int preIdx = n - 1;
	int checkHorror = 0;
	while (preIdx >= 0)
	{
		checkHorror = arr[preIdx];
		if (checkHorror > selectableMem)    //남은 멤버수보다 공포도가 큰 녀석은 그냥 버리고 가야함
		{
			preIdx -= 1;
			selectableMem -= 1;
			continue;
		}
		else
		{
			preIdx = selectableMem - (checkHorror + 1); // 5 - 3-1
			selectableMem = selectableMem - checkHorror; //5 - 3 = 2
			numParty++;
		}



	}
	cout << numParty << endl;
*/

	//greedy5_balling();

//vector<int> foodTime;
//
//int k = 0;
//
//for (int i = 0; i < 3; i++)
//{
//	int tmp = 0;
//	cin >> tmp;
//	foodTime.push_back(tmp);
//}
//
//cin >> k;
//
//cout << solution(foodTime, k);


//vector<int> v;
//
//v.push_back(8);
//v.push_back(6);
//v.push_back(4);
//
//cout<< muzzi_solution(v, 15);

//MicroWave();

//stringSort();

//stringZipSolution();

//snake();

vector<vector<int>> test;

vector<int> temp;
temp.push_back(1);
temp.push_back(0);
temp.push_back(0);
temp.push_back(1);

test.push_back(temp);


vector<int> temp2;
temp2.push_back(1);
temp2.push_back(1);
temp2.push_back(1);
temp2.push_back(1);

test.push_back(temp2);

vector<int> temp3;
temp3.push_back(2);
temp3.push_back(1);
temp3.push_back(0);
temp3.push_back(1);

test.push_back(temp3);

vector<int> temp4;
temp4.push_back(2);
temp4.push_back(2);
temp4.push_back(1);
temp4.push_back(1);

test.push_back(temp4);

vector<int> temp5;
temp5.push_back(5);
temp5.push_back(0);
temp5.push_back(0);
temp5.push_back(1);

test.push_back(temp5);

vector<int> temp6;
temp6.push_back(5);
temp6.push_back(1);
temp6.push_back(0);
temp6.push_back(1);

test.push_back(temp6);

vector<int> temp7;
temp7.push_back(4);
temp7.push_back(2);
temp7.push_back(1);
temp7.push_back(1);

test.push_back(temp7);

vector<int> temp8;
temp8.push_back(3);
temp8.push_back(2);
temp8.push_back(1);
temp8.push_back(1);

test.push_back(temp8);




vector<vector<int>> sol = buildsolution(5,test);

for (int i = 0; i < 5; i++)
{

}

return 0;
}




// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
