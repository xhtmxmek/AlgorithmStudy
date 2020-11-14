#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.


bool compare(string s1, string s2)
{
    //case1. 174, 32일떈 32가 더 큰걸로 치부한다.
    if (s1.length() > s2.length())
        return s1.length() < s2.length();
    return true;
}
class Solution {
public:
    vector<string> solution(vector<string> sequence) {

        vector<string> result;
        result.reserve(sequence.size());
        result.resize(sequence.size());

        //sequnce로 들어온 문자열을 숫자로 바꾼뒤, 해당 숫자 기준으로 문자열을 정렬한다.
        vector<pair<int, string>> tempArr;
        for (int i = 0; i < sequence.size(); i++)
        {            
            int temp = stoi(sequence[i]);
            tempArr.push_back({ temp,sequence[i] });
        }
        
        sort(tempArr.begin(), tempArr.end());

        for (int i = 0; i < sequence.size(); i++)
        {
            result[i] = tempArr[i].second;
        }

        return result;
    }
};

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution2 {
public:
    int solution(vector<int> statements) {

        //문장의 참여부 갯수
        int trueCnt = 0;

        //statement내에서 같은 숫자를 세는 개수
        int sameCnt = 0;

        //참이란걸 증명한 숫자는 다시 카운트하기 않기 위한 체크용 플래그가 필요하다

        vector<bool> check;
        check.reserve(52);
        check.resize(52,false);


        for (int i = 0; i < statements.size(); i++)
        {
            //아직 참이 증명되지 않은 문장만 검사한다.
            if (check[statements[i]] == false)
            {
                for (int j = 0; j < statements.size(); j++)
                {
                    if (j != i) //자기자신을 제외하고 같은녀석이 자기자신의 값과 같은녀석이 값 -1개만큼 있어야한다.ex)1개의 문장이 참 -> 같은녀석 x 2개의 문장이참 -> 같은녀석 1개
                    {
                        if (statements[i] == statements[j])
                            sameCnt++;
                    }
                }
                if (sameCnt == statements[i] - 1)
                {
                    trueCnt++;
                    check[statements[i]] = true;  //문장이 참일경우 플래그도 업데이트 시켜주기
                }
                    
                sameCnt = 0;
            }

        }



        
        int result = 0;

        //답이 하나라면 참인 문장 수를 반환
        result = trueCnt;

        //두개이상이라면 참인 문장중 가장 큰 번호를 찾는다.
        if (trueCnt > 1)
        {
            for (int i = 0; i < check.size(); i++)
            {
                if (check[i] == true)
                    result = i;
            }
        }

        //모순일 경우를 위한 예외처리가 필요하다. 0으로만 statement가 이루어져있을경우를 검사한다.
        int notZeroflag = false;
        for (int i = 0; i < statements.size(); i++)
        {
            if (statements[i] != 0)
                notZeroflag = true;
        }
        if(!notZeroflag)
            result = -1;

        return result;
    }
};


int cnt0 = 0;
int cnt1 = 0;
int fibo(int n)
{
    if (n == 0)
    {
        cnt0++;
        return 0;
    }    

    if (n == 1)
    {
        cnt1++;
        return 1;
    }
    return fibo(n - 1) + fibo(n - 2);                                   
}

class Solution3 {
public:
    vector<int> solution(int n) {

        vector<int> result;
        result.reserve(2);
        result.resize(2);

        fibo(n);
        result[0] = cnt0;
        result[1] = cnt1;
        return result;
    }
};

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution4 {
public:
    int solution(int x1, int y1, int x2, int y2, int d) {

        int result = 0;

        ////타원의 방정식

        //int a = d / 2;
        //int b = a*a - 
        ////점을 구하는 공식
        //for(int i = x1+1 ; i < x2; i++)
        //    for (int j = y1 + 1; j < y2; j++)
        //    {
        //        int tx = i;
        //        int ty = j;

        //        int dist = sqrt((tx - x1) * (ty - y1)) + sqrt((tx - x2) * (ty - y2));
        //        if (dist != d)
        //            result++;
        //    }

        return result;
    }
};


int main()
{
    Solution2 s;

    int cnt = 0;
    cin >> cnt;

    vector<int> states;
    for (int i = 0; i < cnt; i++)
    {
        int tmp = 0;
        cin >> tmp;
        states.push_back(tmp);
    }

    int out = s.solution(states);
    cout << out << endl;

}
