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




//int main()
//{
//
//return 0;
//}




// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
