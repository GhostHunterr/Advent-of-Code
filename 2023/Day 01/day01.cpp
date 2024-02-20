#include <iostream>
#include <fstream>
#include <string>

using namespace std;

long readFile(ifstream &inp)
{
    string line;
    long count = 0;
    while (getline(inp, line))
    {
        string f_digit = "";
        string l_digit = "";
        for (int i = 0; i < line.length(); i++)
        {
            if (isdigit(line[i]))
            {
                f_digit += line[i];
                break;
            }
        }
        for(int j = line.length()-1; j>=0; j--)
        {
            if(isdigit(line[j]))
            {
                l_digit += line[j];
                break;
            }
        }
        f_digit += l_digit;
        count += stoi(f_digit);
    }
    return count;
}

int main()
{
    string fileName = "input.txt";
    ifstream inp(fileName);
    if (!inp.is_open())
    {
        cerr << "Couldn't Open File." << endl;
    }
    cout << readFile(inp) << endl;
    inp.close();

    return 0;
}