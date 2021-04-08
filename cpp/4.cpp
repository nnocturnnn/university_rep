
#include <iostream>
 
class fragarray
{
private:
    int m_array[100];
 
public:
    int& operator[] (const int index);
};
 
int& fragarray::operator[] (const int index)
{
    return m_array[index];
}