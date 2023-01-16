#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

// Tokenize the string
void tokenize(string const &str, const char delim, vector<string> &out)
{
    string s;

    stringstream ss(str);

    while (std::getline(ss, s, delim))
    {
        out.push_back(s);
    }
}

// Extend the string with zeros
string zeroExtend(string str, int n)
{
    string s = "";
    for (int i = 0; i < n; i++)
    {
        s += "0";
    }
    return s + str;
}

// Convert the integer to binary
string toBinary(int n)
{
    string r;
    while (n != 0)
    {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r;
}

// Extract the number from the string
string extractNumber(string str)
{
    regex re("[^0-9]+");
    return regex_replace(str, re, "");
}

int main()
{

    string instruction = "";
    const char delim = ' ';
    vector<string> out;

    string op1 = "";
    string op2 = "";
    string operand1 = "";
    string operand2 = "";
    string operand3 = "";
    string n1, n2, n3;

    // Read from the text file
    ifstream MyReadFile("instruction.txt");

    // Create and open a text file
    ofstream MyFile("instruction_output.txt");

    while (getline(MyReadFile, instruction))
    {
        // Read the instruction from the input
        // cout << "Enter the instruction: ";
        // getline(cin, instruction, '\n');

        // Tokenize the instruction
        tokenize(instruction, delim, out);

        if (!out[0].compare("abs")) // ABS
        {
            op1 = "00001011"; // Bit[7:0]
            op2 = "00011100"; // Bit[27:20]

            n1 = extractNumber(out[1]);
            n2 = extractNumber(out[2]);

            operand1 = toBinary(stoi(n1));
            operand2 = toBinary(stoi(n2));

            operand1 = zeroExtend(operand1, 4 - operand1.length());
            operand2 = zeroExtend(operand2, 4 - operand2.length());

            // Write to the file
            MyFile << operand1 << op2 << "00"
                   << "00" << operand2 << "0000" << op2 << endl;
        }
        else if (!out[0].compare("add")) // ADD
        {
            switch (out.size())
            {
            case 3:
                if (out[2][0] == '#')
                {
                    op1 = "11000010"; // Bit[7:0]
                }
                else
                {
                    op1 = "01000010"; // Bit[7:0]
                }

                n1 = extractNumber(out[1]); // d[a]
                n2 = extractNumber(out[2]); // const, d[b]

                operand1 = toBinary(stoi(n1));
                operand2 = toBinary(stoi(n2));

                operand1 = zeroExtend(operand1, 4 - operand1.length());
                operand2 = zeroExtend(operand2, 4 - operand2.length());

                MyFile << operand2 << operand1 << op1 << endl;

                break;
            case 4:

                n1 = extractNumber(out[1]); // d[a]
                n2 = extractNumber(out[2]); // const, d[b]
                n3 = extractNumber(out[3]);

                int m1 = stoi(n1);
                int m2 = stoi(n2);
                int m3 = stoi(n3);

                operand1 = toBinary(m1);
                operand2 = toBinary(m2);
                operand3 = toBinary(m3);

                operand1 = zeroExtend(operand1, 4 - operand1.length());
                operand2 = zeroExtend(operand2, 4 - operand2.length());

                if (out[3][0] == '#')
                {
                    if (m1 == 15)
                    {
                        op1 = "10011010"; // Bit[7:0]
                        operand3 = zeroExtend(operand3, 4 - operand3.length());

                        MyFile << operand3 << operand1 << op1 << endl;
                    }
                    else if (m2 == 15)
                    {
                        op1 = "10010010"; // Bit[7:0]
                        operand3 = zeroExtend(operand3, 4 - operand3.length());

                        MyFile << operand3 << operand1 << op1 << endl;
                    }
                    else
                    {
                        op1 = "10001011"; // Bit[7:0]
                        operand3 = zeroExtend(operand3, 9 - operand3.length());

                        MyFile << operand1 << "00000000" << operand3 << operand2 << op1 << endl;
                    }
                }
                else
                {
                    if (m1 == 15)
                    {
                        op1 = "11000010"; // Bit[7:0]
                        operand3 = zeroExtend(operand3, 4 - operand3.length());

                        MyFile << operand3 << operand2 << op1 << endl;
                    }
                    else if (m2 == 15)
                    {
                        op1 = "11000011"; // Bit[7:0]
                        operand3 = zeroExtend(operand3, 4 - operand3.length());

                        MyFile << operand3 << operand2 << op1 << endl;
                    }
                    else
                    {
                        op1 = "00001011"; // Bit[7:0]
                        operand3 = zeroExtend(operand3, 4 - operand3.length());

                        MyFile << operand1 << "00000000"
                               << "00"
                               << "00" << operand3 << operand2 << op1 << endl;
                    }
                }
                break;
            }
        }
        else if (!out[0].compare("j"))
        {
            op1 = "00011101"; // Bit[7:0]

            n1 = extractNumber(out[1]);
            operand1 = toBinary(stoi(n1));
            operand1 = zeroExtend(operand1, 24 - operand1.length());

            n1 = operand1.substr(8, 16);
            n2 = operand1.substr(0, 8);

            MyFile << n1 << n2 << op1 << endl;
        }
        else if (!out[0].compare("jge"))
        {
            n1 = extractNumber(out[1]); // d[a]
            n2 = extractNumber(out[2]); // const, d[b]
            n3 = extractNumber(out[3]);

            operand1 = toBinary(stoi(n1));
            operand2 = toBinary(stoi(n2));
            operand3 = toBinary(stoi(n3));

            operand1 = zeroExtend(operand1, 4 - operand1.length());
            operand2 = zeroExtend(operand2, 4 - operand2.length());
            operand3 = zeroExtend(operand3, 15 - operand3.length());

            if (out[2][0] == '#')
            {
                op1 = "11111111"; // Bit[7:0]
            }
            else
            {
                op1 = "01111111"; // Bit[7:0]
            }

            MyFile << "0" << operand3 << operand2 << operand1 << op1 << endl;
        }
        else if (!out[0].compare("mov"))
        {
            n1 = extractNumber(out[1]);
            n2 = extractNumber(out[2]);

            operand1 = toBinary(stoi(n1));
            operand2 = toBinary(stoi(n2));

            if (out[2][0] == '#')
            {
                op1 = "00111011"; // Bit[7:0]

                operand1 = zeroExtend(operand1, 4 - operand1.length());
                operand2 = zeroExtend(operand2, 16 - operand2.length());

                MyFile << operand1 << operand2 << "0000" << op1 << endl;
            }
            else
            {
                op1 = "00001011"; // Bit[7:0]

                operand1 = zeroExtend(operand1, 4 - operand1.length());
                operand2 = zeroExtend(operand2, 4 - operand2.length());

                MyFile << operand1 << "00011111"
                       << "0000" << operand2 << "0000" << op1 << endl;
            }
        }
        else if (!out[0].compare("mul"))
        {
            op1 = "01110011"; // Bit[7:0]

            n1 = extractNumber(out[1]);
            n2 = extractNumber(out[2]);
            n3 = extractNumber(out[3]);

            operand1 = toBinary(stoi(n1));
            operand2 = toBinary(stoi(n2));
            operand3 = toBinary(stoi(n3));

            operand1 = zeroExtend(operand1, 4 - operand1.length());
            operand2 = zeroExtend(operand2, 4 - operand2.length());
            operand3 = zeroExtend(operand3, 4 - operand3.length());

            MyFile << operand1 << "000000001010" << operand3 << operand2 << op1 << endl;
        }
        else if (!out[0].compare("sub"))
        {
            op1 = "00001011"; // Bit[7:0]

            n1 = extractNumber(out[1]);
            n2 = extractNumber(out[2]);
            n3 = extractNumber(out[3]);

            operand1 = toBinary(stoi(n1));
            operand2 = toBinary(stoi(n2));
            operand3 = toBinary(stoi(n3));

            operand1 = zeroExtend(operand1, 4 - operand1.length());
            operand2 = zeroExtend(operand2, 4 - operand2.length());
            operand3 = zeroExtend(operand3, 4 - operand3.length());

            MyFile << operand1 << "00001000"
                   << "00"
                   << "00" << operand3 << operand2 << op1 << endl;
        }
        else if (!out[0].compare("nop"))
        {
            op1 = "00001101"; // Bit[7:0]

            MyFile << zeroExtend(op1, 32 - op1.length()) << endl;
        }
        else
        {
            MyFile << "Instruction is not in the list...\n";
        }

        // Clear the vector
        out.clear();
    }

    MyFile.close();
    return 0;
}