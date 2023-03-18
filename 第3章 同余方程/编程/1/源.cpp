#include<iostream>  
using namespace std;
int kr = 2, kq = 1;
void ojld(int a, int b, int res[], int q[], int s[], int t[]) {
    s[0] = 1; s[1] = 0; t[0] = 0; t[1] = 1;
    a = abs(a), b = abs(b);
    int max = a > b ? a : b;
    int min = a > b ? b : a;
    while (min != 0) {
        int qx = max / min;
        int r = max % min;
        if (r != 0) {
            q[kq] = qx;//存储商  
            res[kr] = r;
            s[kr] = s[kr - 2] - q[kr - 1] * s[kr - 1];//迭代计算s和t直至算到sn和tn  
            t[kr] = t[kr - 2] - q[kr - 1] * t[kr - 1];
            kr++;
            kq++;
            max = min;
            min = r;
        }
        else {
            min = r;
        }
    }
}
int main() {
    int n; cin >> n;
    int m1 = 1;
    int* b = new int[n];
    int* m = new int[n];
    int* M = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "b_" << i << "=";
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cout << "m_" << i << "=";
        cin >> m[i];
        m1 *= m[i];
    }
    for (int i = 0; i < n; i++) {
        M[i] = m1 / m[i];
    }

    int* res = new int[99999];
    int* q = new int[99999];
    int* s = new int[99999];
    int* t = new int[99999];
    int x = 0;
    for (int i = 0; i < n; i++) {
        ojld(M[i], m[i], res, q, s, t);
        int a1 = M[i] > m[i] ? M[i] : m[i];
        int b1 = M[i] < m[i] ? M[i] : m[i];
        if (s[kr - 1] < 0)s[kr - 1] += b1;
        if (t[kr - 1] < 0)t[kr - 1] += a1;
        if (M[i] > m[i])x += M[i] * s[kr - 1] * b[i];
        else x += M[i] * t[kr - 1] * b[i];
        kr = 2, kq = 1;
    }
    cout << "x≡" << x % m1 << "(mod " << m1 << ")";
    delete b, m, M, res, q, s, t;
    system("pause");
    return 0;
}
