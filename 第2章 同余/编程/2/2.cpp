#include <iostream>
using namespace std;

// ��չ��ŷ������㷨����Ԫ
// a: ������Ԫ������m: ģ����x: ��Ԫ
// ����ֵ: �Ƿ������Ԫ
bool extGcd(int a, int m, int& x)
{
    int x1, y1, x0, y0, y;
    x0 = 1;
    y0 = 0;
    x1 = 0;
    y1 = 1;
    int m0 = m;
    int r = a % m;
    int q = (a - r) / m;
    while (r)
    {
        x = x0 - q * x1;
        y = y0 - q * y1;
        x0 = x1;
        y0 = y1;
        x1 = x;
        y1 = y;
        a = m;
        m = r;
        r = a % m;
        q = (a - r) / m;
    }
    if (m != 1) // a��m�����ʣ���������Ԫ
    {
        return false;
    }
    x = x1;
    if (x < 0) // ��x������[0, m)��Χ��
    {
        x += m0;
    }
    return true;
}
int gcd(int x, int y)
{
    int z = y;
    while (x % y != 0)
    {
        z = x % y;
        x = y;
        y = z;
    }
    return z;
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int n, m;
    cout << "a=";
    cin >> n;
    cout << "b=";
    cin >> m;
    cout << "gcd(a,b)=" << gcd(n, m) << endl;
    cout << "lcm(a,b)=" << lcm(n, m) << endl;
    int x;
    if (extGcd(n, m, x))
    {
        cout << "a^(-1)=" << x << " (mod " << m << ")" << endl;
    }
    else
    {
        cout << "��������Ԫ" << endl;
    }
    if (extGcd(m, n, x))
    {
        cout << "b^(-1)=" << x << " (mod " << n << ")" << endl;
    }
    else
    {
        cout << "��������Ԫ" << endl;
    }
    system("pause");
    return 0;
}
