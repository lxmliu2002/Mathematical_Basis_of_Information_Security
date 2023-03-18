#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int num;
    int sum = 1;
    bool flag;
    cin >> num;
    cout << num << "=";
    int t = num;
    for (int i = 2; i < num; i++)
    {
        flag = true;

        for (int m = 2; m < sqrtf(i); m++)
        {
            if (i % m == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            while (t % i == 0)
            {
                sum = sum * i;
                if (sum < num)
                {
                    cout << i << "*";
                }
                else if (sum == num)
                    cout << i << endl;
                t = t / i;
            }
        }
    }
    system("pause");
    return 0;
}
