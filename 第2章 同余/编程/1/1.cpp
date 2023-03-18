#include <iostream>
using namespace std;

long long square_multiply(long long base, long long exponent, long long modulus) {
    long long result = 1;  // ��������������ʼ��Ϊ1
    while (exponent > 0) { // ��ָ������0ʱ
        if (exponent % 2 == 1) { // ���ָ��������
            result = (result * base) % modulus; // ��������ϵ�������ģ��ȡ��
        }
        base = (base * base) % modulus; // ������ƽ������ģ��ȡ��
        exponent = exponent / 2; // ��ָ������2
    }
    return result; // ���ؽ��
}

int main() {
    cout << "Calculate a^n(mod m)" << endl;
    cout << "Please input:" << endl;
    long long base = 2, exponent = 10, modulus = 1000000007;
    cout << "a=";
    cin >> base;
    cout <<  "n=";
    cin >> exponent;
    cout <<  "m=";
    cin >> modulus;
    // ���������ָ����ģ���������������ָ������������
    long long result = square_multiply(base, exponent, modulus); // ����ƽ��-���㷨
    cout << base << "^" << exponent << "(mod" << modulus << ")=" << result;// ������
    system("pause");
    return 0;
}
