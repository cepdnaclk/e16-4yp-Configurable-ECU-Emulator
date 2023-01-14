#include <iostream>
#include "cpu.h"
#include "memory.h"

using namespace std;

int main()
{
    cpu cpu1;
    memory mem;
    cout << &cpu1 << endl;
    cpu1.execute(0x0B, 0x11C0000B);
    cout << "just started" << endl;
    return 0;
}