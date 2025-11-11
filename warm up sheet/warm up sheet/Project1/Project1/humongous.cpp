#include<iostream>
using namespace std;

long long sumAllNumbers(long long start, long long end)
{

	return (end * (end + 1) / 2) - (start * (start - 1) / 2);
}

long long sumAllEvenNumbers(long long  start, long long  end)
{
	return (end / 2 * ((end / 2) + 1)) - ((start - 1) / 2 * (((start - 1) / 2) + 1));
}

long long sumAllOdds(long long  start, long long  end)
{

	return sumAllNumbers(start, end) - sumAllEvenNumbers(start, end);

}

void showAllSums(long long  start, long long  end)
{


	if (start > end)
	{
		swap(start, end);
	}

	cout << sumAllNumbers(start, end);

	cout << endl << sumAllEvenNumbers(start, end);

	cout << endl << sumAllOdds(start, end);

}

int main()
{
	long long  start, end;
	cin >> start >> end;

	showAllSums(start, end);
}
