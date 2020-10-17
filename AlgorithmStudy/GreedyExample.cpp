#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

//*------------------그리디 예제-----------------------*//

#include <string>
#include <algorithm>
#include <sstream>
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

int muzzi_algorithm(vector<int> food_times, int k)
{
	//음식이 먹는데 소요된 시간
	int summary = 0;
	for (int i = 0; i < food_times.size(); i++)
	{
		summary += food_times[i];
	}

	if (summary <= k) return -1;


	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

	for (int i = 0; i < food_times.size(); i++)
	{
		pq.push({ food_times[i],i + 1 });
	}

	summary = 0;
	int preTime = 0;
	int length = food_times.size();

	while (summary + (pq.top().first - preTime) * length <= k)
	{
		int now = pq.top().first;
		pq.pop();
		summary += (now - preTime) * length;
		length -= 1;
		preTime = now;
	}

	vector<pair<int, int>> result;
	while (!pq.empty())
	{
		int time = pq.top().first;
		int num = pq.top().second;
		pq.pop();
		result.push_back({ time,num });
		
	}

	sort(result.begin(), result.end(), sortCompare);

	return result[(k - summary) % length].second;

}

//그리디----백준

bool coinCompare(int lhs, int rhs)
{
	return lhs > rhs;
}
void coin_caculate()
{
	int coinKinds = 0;
	int TargetCost = 0;

	cin >> coinKinds;
	cin >> TargetCost;

	vector<int> coins;
	for (int i = 0; i < coinKinds; i++)
	{
		int tmp = 0;
		cin >> tmp;
		coins.push_back(tmp);
	}

	sort(coins.begin(), coins.end(),coinCompare);

	int remain = TargetCost;


	int coinIdx = 0;
	int coinCnt = 0;

	while (remain != 0)
	{
		if (coins[coinIdx] <= remain)
		{
			remain -= coins[coinIdx];
			coinCnt++;
		}		
		else
			coinIdx++;
	}
	
	cout << coinCnt;
}

//ATM문제 11399번


void atmTimeCaculate()
{
	int manCnt = 0;
	vector<int> atmUseTime;
	vector<int> timeCost;	
	cin >> manCnt;

	for (int i = 0; i < manCnt; i++)
	{
		int tmp = 0;
		cin >> tmp;
		atmUseTime.push_back(tmp);
	}

	std::sort(atmUseTime.begin(), atmUseTime.end());

	
	int time = 0;
	for (int i = 0; i < manCnt; i++)
	{
		time += atmUseTime[i];
		timeCost.push_back(time);
	}

	int result = 0;
	for (int i = 0; i < manCnt; i++)
		result += timeCost[i];

	cout << result;
	//3 1 4 3 2
	

}

//1541번 문제

bool isDelim(char c)
{
	string delims(";,:. \n\t");
	for (int i = 0; i < delims.size(); ++i)
	{
		if (delims[i] == c)
			return true;
	}

	return false;
}

//x--
void bracket()
{

	string s;
	cin >> s;

	int result = 0;


	vector<string> strArr;

	string temp;
	bool minus = false;
	for (int i = 0; i <= s.size(); i++)
	{
		if (s[i] == '+' || s[i] == '-' || s[i] == '\0')
		{

			if (minus)
				result -= stoi(temp);
			else
				result += stoi(temp);

			if (s[i] == '-')
				minus = true;

			temp.clear();

			continue;
		}

		temp.push_back(s[i]);	//55
	}
	
	cout << result;
}

//1931번 문제 //x--

bool endTimeSort(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second < p2.second;
}

void conferenceRoom()
{
	int conferenceCnt = 0;
	cin >> conferenceCnt;

	vector<pair<int, int>> times;	
	for (int i = 0; i < conferenceCnt; i++)
	{
		int startTime = 0;
		int endTime = 0;

		cin >> startTime >> endTime;		

		times.push_back({ startTime,endTime });
	}

	sort(times.begin(), times.end());
	sort(times.begin(), times.end(), endTimeSort);


	int result = 1;

	int min = times[0].second;

	for (int i = 0; i < conferenceCnt; i++)
	{
		if (times[i].first >= min)
		{
			result++;
			min = times[i].second;
		}
	}

	cout << result;
}

//백준 5585번 -> 나머지 금액 문제
void coinCount()
{
	int price = 0;
	cin >> price;
	int cnt = 0;
	int coins[] = { 500,100,50, 5, 10,1 };

	int remain = 1000 - price;

	for (int i = 0; i < 6; i++)
	{
		if (remain == 0)
			break;
		cnt += (remain / coins[i]);
		remain = remain % coins[i];
	}

	cout << cnt;
}


//16208번 문제 x--
void stickCost()
{
	int cnt;

	cin >> cnt;

	priority_queue<int, vector<int> ,greater<int>> pq;

	for (int i = 0; i < cnt; i++)
	{
		int temp = 0;
		cin >> temp;
		pq.push(temp);
	}

	long result = 0;

	while (pq.size() > 1)
	{

		long x = pq.top();
		pq.pop();
		long y = pq.top();
		pq.pop();

		result += x * y;

		pq.push(x + y);

	}

	cout << result;
}


//10162번
void MicroWave()
{
	int time = 0;
	cin >> time;
	int button[] = { 300, 60, 10 };

	int remain = time;
	int buttonPushCnt[] = { 0,0,0 };

	for (int i = 0; i < 3; i++)
	{
		buttonPushCnt[i] += remain / button[i];
		remain = remain % button[i];
	}

	if (remain > 0)
		cout << -1;
	else
		cout << buttonPushCnt[0]<<" " << buttonPushCnt[1]<<" " << buttonPushCnt[2] << endl;
}

//1138번 x---
void LineUp()
{
	int cnt = 0;
	cin >> cnt;
	vector<int> data;
	for (int i = 0; i < cnt; i++)
	{
		int tmp = 0;
		cin >> tmp;
		data.push_back(tmp);
	}

	vector<int> result;
	

	result.reserve(4);
	result.resize(4,0);

	for (int i = 0; i < cnt; i++)
	{
		int left = data[i];

		for (int j = 0; j < cnt; j++)
		{
			if (left == 0 && result[j] == 0)
			{
				result[j] = i + 1;
				break;
			}

			else if (result[j] == 0)
				left--;
		}
	}
	
	for (int i = 0; i < 4; i++)
		cout<< result[i] << " ";
}

//2217번
void rope()
{
	int n = 0;
	cin >> n;

	vector<int> weights;	
	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		cin >> tmp;
		weights.push_back(tmp);
	}

	sort(weights.begin(), weights.end());
	int cnt = n;
	int max = weights[0] * cnt;

	for (int i = 1; i < n; i++)
	{
		int tmp = weights[i] * (cnt - i);
		if (tmp > max)
			max = tmp;
	}

	cout << max;

}

