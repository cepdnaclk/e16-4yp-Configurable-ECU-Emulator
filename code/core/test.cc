#include <iostream>

using namespace std;

int main()
{

    uint32_t c = (0x00003000 & 0x0000F000) >> 12;
    cout << c << endl;
    return 0;
}