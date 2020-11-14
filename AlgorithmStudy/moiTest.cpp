#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//�ٽ� �ҽ��ڵ��� ������ �ּ����� �ۼ��ϸ� �򰡿� ū ������ �˴ϴ�.


bool compare(string s1, string s2)
{
    //case1. 174, 32�ϋ� 32�� �� ū�ɷ� ġ���Ѵ�.
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

        //sequnce�� ���� ���ڿ��� ���ڷ� �ٲ۵�, �ش� ���� �������� ���ڿ��� �����Ѵ�.
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

//�ٽ� �ҽ��ڵ��� ������ �ּ����� �ۼ��ϸ� �򰡿� ū ������ �˴ϴ�.
class Solution2 {
public:
    int solution(vector<int> statements) {

        //������ ������ ����
        int trueCnt = 0;

        //statement������ ���� ���ڸ� ���� ����
        int sameCnt = 0;

        //���̶��� ������ ���ڴ� �ٽ� ī��Ʈ�ϱ� �ʱ� ���� üũ�� �÷��װ� �ʿ��ϴ�

        vector<bool> check;
        check.reserve(52);
        check.resize(52,false);


        for (int i = 0; i < statements.size(); i++)
        {
            //���� ���� ������� ���� ���常 �˻��Ѵ�.
            if (check[statements[i]] == false)
            {
                for (int j = 0; j < statements.size(); j++)
                {
                    if (j != i) //�ڱ��ڽ��� �����ϰ� �����༮�� �ڱ��ڽ��� ���� �����༮�� �� -1����ŭ �־���Ѵ�.ex)1���� ������ �� -> �����༮ x 2���� �������� -> �����༮ 1��
                    {
                        if (statements[i] == statements[j])
                            sameCnt++;
                    }
                }
                if (sameCnt == statements[i] - 1)
                {
                    trueCnt++;
                    check[statements[i]] = true;  //������ ���ϰ�� �÷��׵� ������Ʈ �����ֱ�
                }
                    
                sameCnt = 0;
            }

        }



        
        int result = 0;

        //���� �ϳ���� ���� ���� ���� ��ȯ
        result = trueCnt;

        //�ΰ��̻��̶�� ���� ������ ���� ū ��ȣ�� ã�´�.
        if (trueCnt > 1)
        {
            for (int i = 0; i < check.size(); i++)
            {
                if (check[i] == true)
                    result = i;
            }
        }

        //����� ��츦 ���� ����ó���� �ʿ��ϴ�. 0���θ� statement�� �̷����������츦 �˻��Ѵ�.
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

//�ٽ� �ҽ��ڵ��� ������ �ּ����� �ۼ��ϸ� �򰡿� ū ������ �˴ϴ�.
class Solution4 {
public:
    int solution(int x1, int y1, int x2, int y2, int d) {

        int result = 0;

        ////Ÿ���� ������

        //int a = d / 2;
        //int b = a*a - 
        ////���� ���ϴ� ����
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
