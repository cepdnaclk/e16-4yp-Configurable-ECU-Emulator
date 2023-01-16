#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> mem;
    mem[0] = 0x00003000;
    mem[1] = 0x0000F000;
    mem[2] = mem[0] & mem[1];
    mem[3] = mem[2] >> 12;
    for (const auto &m : mem)
    {
        cout << m.first << " " << m.second << endl;
    }
    if (mem.find(4) == mem.end())
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "found" << endl;
    }
}