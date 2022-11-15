#include <iostream>

using namespace std;

int main()
{

    uint32_t c = (0x00003000 & 0x0000F000) >> 12;
    if (1)
    {
        int k = 10;
        cout << k;
    }
    else
    {
        int k = 20;
        cout << k;
    }
    cout << c << endl;
    return 0;
}