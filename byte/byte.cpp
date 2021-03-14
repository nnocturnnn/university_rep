#include <iostream>
using namespace std;


int main() {
    int a = 110;
    int b = -78;
    char a_rr[sizeof(int)];
    char b_rr[sizeof(int)];
    std::memcpy(a_rr,&a,sizeof(int));
    std::memcpy(b_rr,&b,sizeof(int));
    std::reverse(b_rr, b_rr + sizeof(int));
    cout << *(reinterpret_cast<int16_t*>(a_rr));
    cout << *(reinterpret_cast<int16_t*>(b_rr));
    
}