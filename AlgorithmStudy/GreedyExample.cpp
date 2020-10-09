#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//*------------------�׸��� ����-----------------------*//

#include <string>
#include <algorithm>

//���� 2��
bool desc(int a, int b)
{
	return a > b;
}

int test(vector<int>& arr, int repeatNum, int max)
{
	//arr�� ������������ sort�Ǿ��ٰ� ���� 
	int firstVal = arr[0];
	int secondVal = arr[1];
	int result = 0;
	int firstCnt = 0;

	//���� ū�� repeatNum ��, �״��� ū�� 1�� �ݺ���(repeat + 1)��
	firstCnt = max / (repeatNum + 1) * repeatNum;
	firstCnt += max % (repeatNum + 1);
	result = firstCnt * firstVal;
	//�״������� ū ������ ���� ���ϱ�

	int secondCnt = max - firstCnt;
	result += secondVal * secondCnt;

	return result;
}



//���� 3��
void greedyExample3()
{	
	int** arr;
	int row = 0;
	int column = 0;

	cin >> row;
	cin >> column;

	int minRow = 0;
	int finalMin = 0;


	//��� �����
	vector<vector<int>> mat;

	mat.reserve(row);
	mat.resize(row);

	for (int i = 0; i < row; i++)
	{
		mat[i].reserve(column);
		mat[i].resize(column);
	}

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			cin >> mat[i][j];

	for (int i = 0; i < row; i++)
	{
		minRow = *std::min_element(mat[i].begin(), mat[i].end());
		finalMin = std::max(finalMin, minRow);
	}

	cout << finalMin << endl;
	
}

//���� 4��
void greedyEx4()
{
	int n = 0;
	int k = 0;

	cin >> n;
	cin >> k;

	int cnt = 0;

	while (1)
	{

		//case 1 : 1�� ���� �ʰ�ٷ� ������ �����ϸ� �ٷ� ������
		if (n == 1) break;
		//while(n!=1)

		if (n >= k)
		{
			if (n % k == 0)
			{
				//10000 = 2 * 5000;
				n /= k;
				cnt++;
			}
			else
			{
				//case 2 : 1�� �������� üũ. n�� Ŭ��� ������ �������� ���ڷ� ����µ� 1�� ����� �����ɸ��� ����� ���
				int target = (n / k) * k;
				cnt += n - target;
				n = target;
				//n -= 1;
				//cnt++;
			}
		}
	}

	cout << cnt;
}



//-------------------------��������-------------------------------//

//1�� ���谡 ���->  x--
void guild()
{
	int playerCnt = 0;
	cin >> playerCnt;

	vector<int> fearValue;

	for (int i = 0; i < playerCnt; i++)
	{
		int tmp = 0;
		cin >> tmp;

		fearValue.push_back(tmp);
	}

	sort(fearValue.begin(), fearValue.end());

	int memberCnt = 0;
	int groupCnt = 0;
	for (int i = 0; i < playerCnt; i++)
	{
		memberCnt++;
		if (memberCnt >= fearValue[i])
		{
			groupCnt++;
			memberCnt = 0;
		}		
	}

	cout << groupCnt;
}

//2�� ���ϱ� Ȥ�� ���ϱ�
void multipleAddFunc()
{
	string data;
	cin >> data;
	int result = 0;
	std::string::iterator iter = data.begin();

	int sum = *iter - '0';
	iter++;

	while (iter != data.end())
	{
		//char���� ������ ��ȯ
		int num = *iter - '0';
		if (num == 0 || num == 1||
			sum == 0 || sum == 1)
			sum += num;
		else
			sum *= num;		
		iter++;
	}

	cout << sum << endl;
}


//3�� ���ڿ� ������ -> x--
void flipString()
{
	string s;
	cin >> s;

	int cnt0 = 0;
	int cnt1 = 0;

	if (s[0] == '0')
		cnt1++;
	else
		cnt0++;

	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] != s[i + 1])
		{
			if (s[i + 1] == '0')
				cnt1++;
			else
				cnt0++;
		}
	}

	cout << min(cnt0, cnt1) << endl;

}

//4�� ����� ���� �ݾ� -> x--
void coinSelection()
{

	int coinCnt = 0;

	cin >> coinCnt;

	vector<int> coins;
	for (int i = 0; i < coinCnt; i++)
	{
		int tmp = 0;
		cin >> tmp;
		coins.push_back(tmp);
	}

	int target = 1;
	for (int i = 0; i < coinCnt; i++)
	{
		if (coins[i] > target)
			break;
		target += coins[i];
	}

	cout << target;
}




//5�� ������ ����		��--

//����� �� ������.?
void greedy5_balling()
{
	int N = 0;
	int M = 0;
	
	int WeightedBallsCnt[10];

	cin >> N;
	cin >> M;

	vector<int> weights;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		weights.push_back(tmp);
	}

	for (int i = 0; i < N; i++)	
		WeightedBallsCnt[weights[i]] += 1;	

	int result = 0;

	for (int i = 0; i <	M; i++)
	{
		N -= WeightedBallsCnt[i];
		result += WeightedBallsCnt[i] * N;
	}

	cout << result << endl;	
}


//6�� ������ �Թ� ���̺� https://programmers.co.kr/learn/courses/30/lessons/42891#
int solution(vector<int> food_times, long long k) {
	int answer = 0;

	int sec = 0;

	int foodIdx = 0;
	int lastFoodIdx = food_times.size() - 1;	

	while (sec != k)
	{
		if (food_times[foodIdx] != 0)
		{
			food_times[foodIdx] -= 1;
			sec++;
		}
		

		if (foodIdx == lastFoodIdx)
		{
			foodIdx = 0;
		}
		else
			foodIdx++;

		
	}


	answer = foodIdx;

	return answer;
} 

//���ο� �ַ�� -> �Դµ� ���� �ð��� ���� �ɸ��� ���ĺ��� ��� �ϰ� �� ���Ŀ��� ���������� �����Ͽ� ������ �ذ��ϱ�

struct compare
{
	bool operator()(pair<int, int> p1, pair<int, int> p2)
	{
		return p1.first < p2.first;
	}
};

bool sortCompare(pair<int,int> p1, pair<int,int> p2)
{
	return p1.second < p2.second;
}
int muzzi_solution(vector<int> food_times, long long k)
{
	int answer = 0;
	
	// ��ü ������ �Դ� �ð����� k�� ũ�ų� ���ٸ� -1
	long long summary = 0;
	for (int i = 0; i < food_times.size(); i++) {
		summary += food_times[i];
	}
	if (summary <= k) return -1;

	//�ð��� ���� ���ĺ��� ���� ���� �켱���� ť�� �̿�
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

	for (int i = 0; i < food_times.size(); i++)
	{
		pq.push({ -food_times[i],i + 1 });
	}

	summary = 0;	//�Ա����� ����� �ð�
	long long previous = 0; //������ �� ���� ���� �ð�
	long long length = food_times.size(); // ���� ������ ����

	// summary + (������ ���� �ð� - ���� ���� �ð�) * ���� ���� ������ k ��
	while (summary + ((-pq.top().first - previous) * length) <= k) {
		int now = -pq.top().first;
		pq.pop();
		summary += (now - previous) * length;
		length -= 1; // �� ���� ���� ����
		previous = now; // ���� ���� �ð� �缳��
	}

	// ���� ���� �߿��� �� ��° �������� Ȯ���Ͽ� ���
	vector<pair<int, int> > result;
	while (!pq.empty()) {
		int food_time = -pq.top().first;
		int num = pq.top().second;
		pq.pop();
		result.push_back({ food_time, num });
	}
	sort(result.begin(), result.end(), sortCompare); // ������ ��ȣ �������� ����
	return result[(k - summary) % length].second;



}




