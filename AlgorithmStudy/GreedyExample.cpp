#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//*------------------그리디 예제-----------------------*//

#include <string>
#include <algorithm>

//예제 2번
bool desc(int a, int b)
{
	return a > b;
}

int test(vector<int>& arr, int repeatNum, int max)
{
	//arr은 내림차순으로 sort되었다고 가정 
	int firstVal = arr[0];
	int secondVal = arr[1];
	int result = 0;
	int firstCnt = 0;

	//가장 큰수 repeatNum 개, 그다음 큰수 1번 반복됨(repeat + 1)꼴
	firstCnt = max / (repeatNum + 1) * repeatNum;
	firstCnt += max % (repeatNum + 1);
	result = firstCnt * firstVal;
	//그다음으로 큰 숫자의 갯수 구하기

	int secondCnt = max - firstCnt;
	result += secondVal * secondCnt;

	return result;
}



//예제 3번
void greedyExample3()
{	
	int** arr;
	int row = 0;
	int column = 0;

	cin >> row;
	cin >> column;

	int minRow = 0;
	int finalMin = 0;


	//행렬 만들기
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

//예제 4번
void greedyEx4()
{
	int n = 0;
	int k = 0;

	cin >> n;
	cin >> k;

	int cnt = 0;

	while (1)
	{

		//case 1 : 1로 뺴지 않고바로 나눠도 가능하면 바로 나누기
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
				//case 2 : 1로 뺀다음에 체크. n을 클경우 나누어 떨어지는 숫자로 만드는데 1씩 뺄경우 오래걸리니 배수로 계산
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



//-------------------------실전문제-------------------------------//

//1번 모험가 길드->  x--
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

//2번 곱하기 혹은 더하기
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
		//char형을 정수로 변환
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


//3번 문자열 뒤집기 -> x--
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

//4번 만들수 없는 금액 -> x--
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




//5번 볼링공 고르기		ㅁ--

//경우의 수 따지기.?
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


//6번 무지의 먹방 라이브 https://programmers.co.kr/learn/courses/30/lessons/42891#
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

//새로운 솔루션 -> 먹는데 가장 시간이 적게 걸리는 음식부터 계산 하고 그 이후에는 순차적으로 접근하여 문제를 해결하기

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
	
	// 전체 음식을 먹는 시간보다 k가 크거나 같다면 -1
	long long summary = 0;
	for (int i = 0; i < food_times.size(); i++) {
		summary += food_times[i];
	}
	if (summary <= k) return -1;

	//시간이 작은 음식부터 빼기 위해 우선순위 큐를 이용
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

	for (int i = 0; i < food_times.size(); i++)
	{
		pq.push({ -food_times[i],i + 1 });
	}

	summary = 0;	//먹기위해 사용한 시간
	long long previous = 0; //직전에 다 먹은 음식 시간
	long long length = food_times.size(); // 남은 음식의 개수

	// summary + (현재의 음식 시간 - 이전 음식 시간) * 현재 음식 개수와 k 비교
	while (summary + ((-pq.top().first - previous) * length) <= k) {
		int now = -pq.top().first;
		pq.pop();
		summary += (now - previous) * length;
		length -= 1; // 다 먹은 음식 제외
		previous = now; // 이전 음식 시간 재설정
	}

	// 남은 음식 중에서 몇 번째 음식인지 확인하여 출력
	vector<pair<int, int> > result;
	while (!pq.empty()) {
		int food_time = -pq.top().first;
		int num = pq.top().second;
		pq.pop();
		result.push_back({ food_time, num });
	}
	sort(result.begin(), result.end(), sortCompare); // 음식의 번호 기준으로 정렬
	return result[(k - summary) % length].second;



}




