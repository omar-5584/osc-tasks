#include<iostream>
using namespace std;

int main()
{
	long long num;
	long long sqtnum;
	cin >> num;
	sqtnum = sqrt(num);
	(sqtnum * sqtnum == num) ? cout << "YES" : cout << "NO";


}