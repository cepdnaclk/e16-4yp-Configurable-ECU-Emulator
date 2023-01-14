#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <map>

class memory
{
private:
    std::map<int, int> m;

public:
    int read(int EA);
    void write(int EA, int data);
};

#endif