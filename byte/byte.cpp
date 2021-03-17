#include <iostream>
#include <unistd.h>
#include <cmath>
using namespace std;


int main() {
    int a = 110;
    int b = -78;
    int c = 32;
    double d = -60.34375;
    int res_int;
    std::string binary_a = std::bitset<8>(a).to_string();
    cout << "A = " << a << " Byte A = " << binary_a << endl;
    std::string binary_b = std::bitset<8>(b).to_string();
    cout << "B = " << b << " Byte B = " << binary_b << endl;
    std::string binary_c = std::bitset<8>(c).to_string();
    cout << "C = " << c << " Byte C = " << binary_c << endl;
    std::string binary_d_4 = std::bitset<32>(d).to_string();
    cout << "D = " << d << " 4 Byte D = " << binary_d_4 << endl;
    std::string binary_d_8 = std::bitset<64>(d).to_string();
    cout << "D = " << d << " 8 Byte D = " << binary_d_8 << endl;
    std::string binary_d_10 = std::bitset<80>(d).to_string();
    cout << "D = " << d << " 10 Byte D = " << binary_d_10 << endl;
    reverse(binary_b.begin(), binary_b.end());
    std::bitset<8> b3(binary_b);
    std::bitset<8> b4(binary_c);
    std :: bitset <8> sum (b3.to_ulong () + b4.to_ulong());
    res_int = (int)(sum.to_ulong()) * -1;res_int--;
    cout << "Byte B - Byte C = Byte " << sum << " And Int " << res_int << endl;
    double f_1 = 0.10101 * pow(2,-1);
    double f_2 = 0.10101 * pow(2, 11);
    double rez = (d + f_1) * f_2;
    cout <<  "(D + 0.10101 * 2(-1)) * 0.10101 * 2(11)) = " << rez << endl;

}

