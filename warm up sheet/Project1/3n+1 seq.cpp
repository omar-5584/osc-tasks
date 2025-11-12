#include<iostream>
using namespace std;

int  recursive_nums(int n, int& cnt)
{


    if (n == 1)
    {
        return ++cnt;
    }
    else if (n & 1)
    {
        cnt++;
        recursive_nums(3 * n + 1, cnt);
    }
    else
    {
        cnt++;
        recursive_nums(n / 2, cnt);
    }

}
int main()
{
    int cnt = 0;
    int n;
    cin >> n;
    cout << recursive_nums(n, cnt);






}