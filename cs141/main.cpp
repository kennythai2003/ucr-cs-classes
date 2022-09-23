#include <bits/stdc++.h>
using namespace std;
 
void bubbleSort(vector<string>);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    long long int firstYears = 0;
    cin >> firstYears;
    cin.ignore();
 
    string name;
    string house;
 
    vector<string> gryffindors;
    vector<string> hufflepuff;
    vector<string> ravenclaw;
    vector<string> slytherin;
 
    for (int i = 0; i < firstYears; ++i)
    {
        cin >> name;
        cin.ignore();
 
        cin >> house;
        cin.ignore();
 
        if (house == "Gryffindor")
        {
            gryffindors.push_back(name);
        }
        else if (house == "Hufflepuff")
        {
            hufflepuff.push_back(name);
        }
        else if (house == "Ravenclaw")
        {
            ravenclaw.push_back(name);
        }
        else
        {
            slytherin.push_back(name);
        }
 
    }
 
    bubbleSort(gryffindors);
    bubbleSort(hufflepuff);
    bubbleSort(ravenclaw);
    bubbleSort(slytherin);
 
    printf("Gryffindor\n");
    for (int i = 0; i < gryffindors.size(); ++i)
    {
        printf("%s\n", gryffindors.at(i).c_str());
    }
   
    printf("Hufflepuff\n");
    for (int i = 0; i < hufflepuff.size(); ++i)
    {
        printf("%s\n", hufflepuff.at(i).c_str());
    }
   
    printf("Ravenclaw\n");
    for (int i = 0; i < ravenclaw.size(); ++i)
    {
        printf("%s\n", ravenclaw.at(i).c_str());
    }
   
    printf("Slytherin\n");
     for (int i = 0; i < slytherin.size(); ++i)
    {
        printf("%s\n", slytherin.at(i).c_str());
    }
 
    return 0;
}
 
void bubbleSort(vector<string> x)
{
    for (int i = 0; i < x.size(); ++i)
    {
        for (int j = 0; j < x.size() - i - 1; ++j)
        {
            if (x.at(j) > x.at(j + 1))
            {
                string temp = x.at(j);
                x.at(j) = x.at(j + 1);
                x.at(j + 1) = temp;
            }
        }
    }
}
