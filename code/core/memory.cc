#include "memory.h"

int memory::read(int EA)
{
    if (m.find(EA) == m.end())
    {
        return 0;
    }
    return m[EA];
}

void memory::write(int EA, int data)
{
    m[EA] = data;
}
