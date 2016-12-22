#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<vector<double> > values;
    vector<double> valueline;
    ifstream fin("threshold_station_time.csv");
    string item;
    for (string line; getline(fin, line); )
    {
        stringstream in(line, ios::in);

        while (getline(in, item, ','))
        {
            valueline.push_back(atof(item.c_str()));
        }

        values.push_back(valueline);
        valueline.clear();
    }
    for(int row=0 ; row<values.size() ; row++){
        for(int col=0 ; col<values[row].size() ; col++)
            cout << values[row][col] << "  ";
        cout << endl;
    }
}