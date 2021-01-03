#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include<iomanip>

using namespace std;

int main()
{
    int pointsN, minN;
    cin >> pointsN >> minN;
    vector<double> distances;
    for(int i=0; i<pointsN; i++)
    {
        double xCord, yCord, zCord;
        cin >> xCord >> yCord >> zCord;
        double squarD = xCord*xCord + yCord*yCord + zCord*zCord;
        double distC = squarD / sqrt(squarD);
        distances.push_back(distC);
    } 
    sort(distances.begin(), distances.end());
    cout <<fixed << setprecision(8) <<  distances.at(minN-1) << endl;

}