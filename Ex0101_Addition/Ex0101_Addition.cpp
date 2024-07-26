#include <string>
#include <vector>
#include <iostream>

using namespace std;

string Add(string str1, string str2)
{
	// TODO:
	string newStr1 = str1;
	string newStr2 = str2;
	string result;
	int additiveMaximum = str1.size() >= str2.size() ? str1.size() : str2.size();

	for (int i = 0; i < additiveMaximum - str1.size(); ++i)
	{
		newStr1 = "0" + newStr1;
	}

	for (int i = 0; i < additiveMaximum - str2.size(); ++i)
	{
		newStr2 = "0" + newStr2;
	}

	for (int i = 0; i < additiveMaximum; ++i)
	{
		result += "0";
	}

	bool addNum = false;

	for (int i = additiveMaximum - 1; i >= 0; i--)
	{
		int x = (newStr1[i] - '0') + (newStr2[i] - '0');

		if (addNum)
		{
			x += 1;
			addNum = false;
		}

		if (x < 10)
		{
			result[i] = x + '0';
		}
		else
		{
			result[i] = (x - 10) + '0';
			addNum = true;
		}

		cout << newStr1[i] << " " << newStr2[i] << " ";

		for (int j = 0; j < result.size(); ++j)
		{
			cout << result[j];
		}

		cout << endl;
	}

	if (addNum)
	{
		result = "1" + result;
	}

	return result;
}

int main()
{
	vector<vector<string>> tests = {
		{"12", "34", to_string(12 + 34)}
		, {"123", "45", to_string(123 + 45)}
		, {"54544", "44545", to_string(54544 + 44545)}
		, {"5555", "55", to_string(5555 + 55)}
		, {"5555", "5555", to_string(5555 + 5555)}
		, {"9823471235421415454545454545454544", "1714546546546545454544548544544545", "11538017781967960909090003089999089"}
	};

	for (const auto& t : tests)
	{
		const string str1 = t[0];     // "12"
		const string str2 = t[1];     // "34"
		const string expected = t[2]; // "46"

		cout << str1 << " + " << str2 << " = " << expected << endl;

		const string result = Add(str1, str2);

		cout << result << " " << expected << " ";

		if (result == expected)
			cout << "OK" << endl;
		else {
			cout << "Not OK" << endl;
			exit(-1);
		}
		cout << endl << endl;
	}

	cout << "Congratulations. All OK!" << endl;

	return 0;
}
