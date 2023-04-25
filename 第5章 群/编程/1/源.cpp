#include <iostream>
#include <bitset>

using namespace std;

// 定义IP置换矩阵
int IP[64] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17,  9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};

// 分组函数
void groupData(string data, bitset<64>& left, bitset<64>& right) {
    bitset<64> bitData(data);

    // 将数据按照IP矩阵进行置换
    for (int i = 0; i < 64; i++) {
        if (IP[i] <= 32) {
            left.set(31 - IP[i], bitData[63 - i]);
        }
        else {
            right.set(31 - (IP[i] - 32), bitData[63 - i]);
        }
    }
}

int main() {
    // 待分组的明文数据
    string data = "507239AA7EA3B82E";

    // 定义分组后的左半部分和右半部分
    bitset<64> left, right;

    // 进行分组操作
    groupData(data, left, right);

    // 打印分组后的结果
    cout << "Left: " << left.to_string() << endl;
    cout << "Right: " << right.to_string() << endl;

    return 0;
}
