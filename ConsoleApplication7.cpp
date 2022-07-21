#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool comp(const pair<int, int>& p1, const pair<int, int>& p2)
{
	if (p1.second == p2.second)
	{
		return p1.first < p2.first;
	}
	return p1.second > p2.second;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	int a = 0;
	cin >> a;
	int b = 0;
	double average = 0.0;
	int max2 = 0;
	int mode = 0;
	vector<int> v;
	vector<int> count;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		v.push_back(b);
	}
	sort(v.begin(), v.end());

	//산술평균 출력(소수점 이하 첫째 자리에서 반올림)
	for (auto iter = v.begin(); iter != v.end(); iter++)
	{
		average += *iter;
	}
	average = average / v.size();
	if (round(average) == -0)
	{
		cout << '0' << '\n';
	}
	else cout << round(average) << '\n';

	//중앙값 출력
	int middle = v.size();
	middle = middle / 2;
	cout << v.at(middle) << '\n';

	//최빈값
	vector<pair<int, int>> st;
	vector<int>::size_type i;

	for (int i = 0; i < v.size(); i++)
	{
		if (st.empty())
		{
			st.push_back(pair<int, int>(v[i], 1));
			continue;
		}
		if (st.back().first == v[i])
		{
			pair<int, int> tmp = st.back();
			tmp.second++;
			st.push_back(tmp);
		}
		else
		{
			st.push_back(pair<int, int>(v[i], 1));
		}
	}

	sort(st.begin(), st.end(), comp);

	if (st[0].second == st[1].second)
	{
		cout << st[1].first << endl;
	}
	else {
		cout << st[0].first << endl;
	}


	//

	//범위
	int max = *max_element(v.begin(), v.end());
	int min = *min_element(v.begin(), v.end());
	cout << max - min << '\n';


	return 0;

}