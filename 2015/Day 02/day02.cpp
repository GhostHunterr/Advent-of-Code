#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

// Part-1
//  long readFile(ifstream &inputFile)
//  {
//      int count = 1;
//      string line;
//      long totalArea = 0;
//      while (getline(inputFile, line))
//      {
//          std::istringstream data(line);
//          std::string token;
//          int l, w, h;

//         getline(data, token, 'x');
//         l = stoi(token);
//         getline(data, token, 'x');
//         w = stoi(token);
//         getline(data, token, '\n');
//         h = stoi(token);

//         totalArea += (2 * (l * w + w * h + h * l) + min({l*w,w*h,h*l}));

//     }
//     return totalArea;
// }

//Part-2
long readFile(ifstream &inputFile)
{
    int count = 1;
    string line;
    long ribbon = 0;
    while (getline(inputFile, line))
    {
        std::istringstream data(line);
        std::string token;
        int l, w, h;

        getline(data, token, 'x');
        l = stoi(token);
        getline(data, token, 'x');
        w = stoi(token);
        getline(data, token, '\n');
        h = stoi(token);

        ribbon +=  l * w * h + min({2*(l+h), 2*(h+w), 2*(l+w)});
    }
    return ribbon;
}

int main()
{
    string fileName = "input.txt";
    ifstream inputFile(fileName);

    if (!inputFile.is_open())
    {
        cerr << "Couldn't Open File!" << endl;
    }

    cout << readFile(inputFile) << endl;

    return 0;
}