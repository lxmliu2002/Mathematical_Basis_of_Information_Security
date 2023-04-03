#include <bits/stdc++.h>  
using namespace std;
int m;
void binary(vector<int>& a, int T)
{
    int q = T;
    int r;
    while (q != 0)
    {
        r = q % 2;
        a.push_back(r);
        q = q / 2;
    }
}
int pfc(int a, int n, int x)
{
    vector<int> b;
    binary(b, n);
    int c = 1;
    for (int i = b.size() - 1; i >= 0; i--)
    {
        c = c * c % x;
        if (b[i])
        {
            c = c * a % x;
        }
    }
    return c;
}
bool sushu(int n)
{
    if (n == 1)
        return false;
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
}
void fj(int n, vector<int>& res)
{
    int l = 0;
    for (int i = 2; i <= n; i++)
    {
        if (sushu(i))
        {
            if (n % i == 0)
            {
                l++;
                res[i]++;
                int t = n / i;
                m = t;
                fj(t, res);
                break;
            }
        }
    }
    if (!l)
        res[m]++;
}
int oula(int n)
{
    vector<int> vec(10000, 0);
    fj(n, vec);
    int fai = n;
    for (int i = 2; i < vec.size(); i++)
    {
        if (vec[i] != 0)
            fai *= (1 - 1 / double(i));
    }
    return fai;
}
int main()
{
    cout << "Please inputn(n>0): ";
    int n;
    cin >> n;
    int fai = oula(n);
    int g = 0;
    vector<int> exp;
    vector<int> res(10000);
    fj(fai, res);
    for (int i = 2; i < res.size(); i++)
    {
        if (res[i] != 0)
            exp.push_back(fai / i);
    }
    for (int i = 2; i < n; i++)
    {
        bool flag = 1;
        for (int j = 0; j < exp.size(); j++)
        {
            int t = pfc(i, exp[j], n);
            if (t == 1)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            g = i;
            break;
        }
    }
    cout << "The min primitive root of " << n << ": g=" << g << endl;
    cout << "The ind_table of " << n << " based on g=" << g << " is:" << endl;
    cout << setw(6) << " ";
    for (int i = 0; i < 10; i++)
        cout << setw(6) << i;
    cout << endl;
    int row = n / 10;
    int** table = new int* [row + 1];
    for (int i = 0; i < row + 1; i++)
    {
        table[i] = new int[11];
        table[i][0] = i;
        for (int j = 1; j < 11; j++)
            table[i][j] = -1;
    }
    for (int i = 0; i <= fai - 1; i++)
    {
        int t = pfc(g, i, n);
        int row_num = t / 10;
        int col_num = t % 10;
        table[row_num][col_num + 1] = i;
    }
    for (int i = 0; i < row + 1; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (table[i][j] != -1)
                cout << setw(6) << table[i][j];
            else
                cout << setw(6) << "-";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
