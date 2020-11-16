#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first == p2.first)
    {
        return p1.second < p2.second;
    }
    else
        p1.first < p2.first;
}

vector<int> solution(vector<int> nums, int target) {
    vector<int> answer;

    //거꾸로 중복되는걸 막기위한 체크용 벡터
    vector<pair<int,int>> check;


    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i+1; j < nums.size(); j++)
        {
            
          int tmp = nums[i] + nums[j];
          if (tmp == target)
          {
              check.push_back({ i, j });
          }                     
        }
    }


    
    if (!check.empty())
    {   
        //사전 순 정렬하기
        sort(check.begin(), check.end());
        answer.push_back(check[0].first);
        answer.push_back(check[0].second);
    }

    return answer;
}

//int main()
//{
//
//
//    vector<int> nums;
//    int numCnt;
//    cin >> numCnt;
//    for (int i = 0; i < numCnt; i++)
//    {
//        int tmp = 0;
//        cin >> tmp;
//        nums.push_back(tmp);
//    }
//
//    int target = 0;
//    cin >> target;
//
//    vector<int> result = solution(nums, target);
//
//    for (int i = 0; i < result.size(); i++)
//        cout << result[i]<<endl;
//
//	return 0;
//}