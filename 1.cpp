#include <iostream>

using namespace std;

int n, m, c5, c4;

void func(int step = 0, int sum = 0, int cnt5 = 0, int cnt4 = 0)
{
    if (step + 4 > n)
    {
        if (sum > m)
        {
            m = sum;
            c5 = cnt5;
            c4 = cnt4;
        }
        return;
    }
    int tmp = step + 5;
    func(tmp, sum + (n - tmp) * 15, cnt5 + 1, cnt4);
    tmp = step + 4;
    func(tmp, sum + (n - tmp) * 10, cnt5, cnt4 + 1);
}

int main()
{
    int s = 0;
    cin>>n;
    int t = (n - 2) / 20;
    n = (n - 2) % 20 + 2;
    s = t * (2 * n + t * 20 - 5) * 2 * 15;
    func();
    c5 += 4 * t;
    cout<<"5: "<<c5<<" 4: "<<c4<<" max "<<m + s<<endl;
    return 0;
}
