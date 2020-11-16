#include <iostream>
#include <string>
#include <vector>

using namespace std;

string compute(int& sum, int rhs, char op)
{
	if (op == '+')
		sum += rhs;
	else if (op == '-')
		sum -= rhs;
	else if (op == '*')
		sum *= rhs;
	else if (op == '/')
	{
		if (rhs == 0)
			return string("Impossible");
		sum /= rhs;
	}

	return string();
}


string solution2(string input)
{
	int sum = 0;
	sum = input[0] - '0';

	int opIdx = 0;
	vector<int> numArr;
	vector<char> opArr;
	vector<char> fopArr;
	for (int i = 1; i < input.length(); i++)
	{
		if (i % 2 == 1)
		{
			opArr.push_back(input[i]);
		}
		else if (opArr[opIdx] == '*')
		{
			int currNum = input[i] - '0';
			int num = input[i - 1] - '0';
			num *= currNum;
			numArr.push_back(num);
			opIdx++;
		}
		else if (opArr[opIdx] == '/')
		{
			int currNum = input[i] - '0';
			if (currNum == 0)
				return string("Impossible");
			int num = input[i - 1] - '0';
			num /= currNum;
			
			numArr.push_back(num);
			opIdx++;
		}
		else if (opArr[opIdx] == '+' || opArr[opIdx] == '-')
		{
			fopArr.push_back(opArr[opIdx]);
			opIdx++;
		}
	}

		int result = numArr[0];
		int fopIdx = 0;
		for (int i = 1; i < numArr.size(); i++)
		{
			int curr = numArr[i];
			if (fopArr[fopIdx] == '+')
				result += curr;
			if (fopArr[fopIdx] == '-')
				result -= curr;
			fopIdx++;
		}

	return to_string(result);
	
}

int main()
{
	cout << solution2("8/2-4*5") << endl;
	return 0;

	//8245/*-
}