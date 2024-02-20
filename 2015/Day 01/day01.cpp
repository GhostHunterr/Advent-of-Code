#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int readFile(ifstream &inputFile)
{
    string line;
    int count = 0;
    while (getline(inputFile, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if(line[i] == '(')
            {
                count++;
            }
            else if(line[i] == ')')
            {
                count --;
            }

            if(count == -1)
            {
                return i+1;
            }
        }
    }
    return -1;
}

int main()
{
    string fileName = "input.txt";
    ifstream inputFile(fileName);

    if (!inputFile.is_open())
    {
        cerr << "Couldn't Open File." << endl;
    }

    cout << readFile(inputFile) << endl;

    inputFile.close();
    return 0;
}