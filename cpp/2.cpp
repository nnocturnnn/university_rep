#include <iostream>
#include <string.h>


int main() {
    const int N=7;
    const char*cPointers[N]={"Monday", "Thuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    for (int i = 0; i < N-1; i++)
    {
        for (int j = 0; j < N-1 ; j++ )
        {
            int res = strcmp(cPointers[j+1], cPointers[j]);
            if (res < 0)
            {
                const char*tmp= (cPointers[j + 1]);
                (cPointers[j + 1]) = (cPointers[j]);
                (cPointers[j]) = tmp;
 
            }
        }
    }
    for (int i = 0; i < N; i++)
        std::cout<<cPointers[i]<<std::endl;
    return 0;
}