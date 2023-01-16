#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    uint32_t instruction_buffer[100000];
    ifstream file("test.txt");
    if (file.is_open())
    {
        int size = 0;
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
    return 0;
}
