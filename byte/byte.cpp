#include <iostream>
using namespace std;


template<std::size_t N>
void reverse(std::bitset<N> &b) {
    for(std::size_t i = 0; i < N/2; ++i) {
        bool t = b[i];
        b[i] = b[N-i-1];
        b[N-i-1] = t;
    }
}

int main() {
    int a = 110;
    int b = -78;
    int c = 32;
    double d = -60.34375;
    std::string binary_a = std::bitset<8>(a).to_string();
    std::string binary_b = std::bitset<8>(b).to_string();
    std::string binary_c = std::bitset<8>(c).to_string();
    std::string binary_d_4 = std::bitset<32>(d).to_string();
    std::string binary_d_8 = std::bitset<64>(d).to_string();
    std::string binary_d_10 = std::bitset<80>(d).to_string();
    // std::cout<<binary_a<<"\n";
    // reverse(binary_a.begin(), binary_a.end()); 
    // std::cout<<binary_a<<"\n";
}

