#include <iostream>
using namespace std;

long long square_multiply(long long base, long long exponent, long long modulus) {
    long long result = 1;  // 定义结果变量并初始化为1
    while (exponent > 0) { // 当指数大于0时
        if (exponent % 2 == 1) { // 如果指数是奇数
            result = (result * base) % modulus; // 将结果乘上底数并对模数取余
        }
        base = (base * base) % modulus; // 将底数平方并对模数取余
        exponent = exponent / 2; // 将指数除以2
    }
    return result; // 返回结果
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
    // 定义底数、指数和模数，并假设底数和指数都是正整数
    long long result = square_multiply(base, exponent, modulus); // 调用平方-乘算法
    cout << base << "^" << exponent << "(mod" << modulus << ")=" << result;// 输出结果
    system("pause");
    return 0;
}
