#include <fstream>
#include <iostream>
#include <string>
#include "cpu.h"
#include "memory.h"

using namespace std;

uint32_t instruction_buffer[100000];
int size = 0;

void load_instructions(string filename)
{
    string line;
    ifstream file(filename);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << " ";
            uint32_t decimal_value = stoi(line, nullptr, 2);
            printf("%X\n", decimal_value);
            instruction_buffer[size++] = decimal_value;
        }
        file.close();
        for (int j = 0; j < size; j++)
            printf("%X\n", instruction_buffer[j]);
    }
    else
        cout << "Unable to open file";
}

int main()
{
    cpu cpu1;
    memory mem;
    load_instructions("test.txt");
    for (int j = 0; j < size; j++)
    {
        printf("%X\n", instruction_buffer[j]);
        cpu1.instruction_decode(instruction_buffer[j]);
    }
    return 0;
}
