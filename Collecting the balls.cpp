# C_N_Backrracking
#include<bits/stdc++.h>
using namespace std;

bool help(long long k, long long n)
{
	long long sum = 0;
	long long curr = n;
	while (curr > 0)
	{
		sum = sum + min(curr, k);
		curr = curr - k;
		curr = curr - (curr / 10);


	}

	if (sum * 2 >= n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

long long findans(long long s, long long e, long long n)
{
	static long long ans = LONG_MAX;
	if (s <= e)
	{





		long long mid = (s + e) / 2;

		bool ispossible = help(mid, n);

		if (ispossible)
		{
			//cout << mid << endl;
			if (mid < ans) ans = mid;
			findans(s, mid - 1, n);
		}
		else
		{
			//cout << "not true" << endl;
			findans(mid + 1 , e, n);
		}
		//cout << ans;
	}
	return ans;
}


int main()
{



	long long n;
	cin >> n;
	cout << findans(1, n, n);

}
