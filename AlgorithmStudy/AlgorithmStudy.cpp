// AlgorithmStudy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

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

int dReferArr[100];

int dp(int x)
{
    if (x == 1) return 1;
    if (x == 2) return 1;
    if (dReferArr[x] != 0) return dReferArr[x];
    return dReferArr[x] = dp(x - 1) + dp(x - 2);
}

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

    int nodeCnt = 15;

    TreeNode Node[16];

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


    cout << dp(30) << endl;
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
