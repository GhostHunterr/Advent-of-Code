#include <bits/stdc++.h>

using namespace std;

int calculateHouses(ifstream &inputFile)
{
    int count = 0;
    string line;
    unordered_map<string, int> location;
    getline(inputFile, line);
    int x = 0;
    int y = 0;

    for (char move : line)
    {
        // Update the coordinates.
        if (move == '^')
        {
            x += 1;
        }
        else if (move == 'v')
        {
            x -= 1;
        }
        else if (move == '>')
        {
            y += 1;
        }
        else if (move == '<')
        {
            y -= 1;
        }

        // Update or create a key,value pair in location map
        location[to_string(x) + ',' + to_string(y)]++;
    }

    for (const auto &pair : location)
    {
        if (pair.second >= 1)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    string fileName = "input.txt";
    ifstream inputFile(fileName);

    if (!inputFile.is_open())
    {
        cerr << "Couldn't Open File!" << endl;
    }

    cout << calculateHouses(inputFile) << endl;

    return 0;
}