#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include "cpu.h"
#include "memory.h"

using namespace std;

uint32_t instruction_buffer[100000];

void load_instructions(string filename, int &size)
{
    string line;
    ifstream file(filename);
    if (file.is_open())
    {
        cout << "DEBUG: started to read the file" << endl;
        while (getline(file, line))
        {
            // cout << line << " ";
            uint32_t decimal_value = stoi(line, nullptr, 2);
            // printf("%X\n", decimal_value);
            instruction_buffer[size++] = decimal_value;
        }
        cout << "DEBUG: finished the reading file" << endl;
        file.close();
        // for (int j = 0; j < size; j++)
        //     printf("%X\n", instruction_buffer[j]);
    }
    else
        cout << "Unable to open file";
}

int main()
{
    cpu cpu1;
    memory mem;
    int size = 0;
    clock_t instruction_load_start_time = clock();
    load_instructions("../test/test.txt", size);
    clock_t instruction_load_end_time = clock();

    clock_t instruction_execution_start_time = clock();
    for (int j = 0; j < size; j++)
    {
        // printf("%X\n", instruction_buffer[j]);
        cpu1.instruction_decode(instruction_buffer[j]);
    }
    clock_t instruction_execution_end_time = clock();

    double instruction_load_elapsed_time = (instruction_load_end_time - instruction_load_start_time) / CLOCKS_PER_SEC;
    double instruction_execution_elapsed_time = (instruction_execution_end_time - instruction_execution_start_time) / CLOCKS_PER_SEC;
    cout << "--------------------------------------------------------" << endl;
    cout << "Instructions loaded: " << size << endl;
    cout << "Instructions load time: " << instruction_load_elapsed_time << " seconds" << endl;
    cout << "Instructions execution time: " << instruction_execution_elapsed_time << " seconds" << endl;

    return 0;
}
