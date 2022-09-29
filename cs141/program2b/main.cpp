#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int department;
    cin >> department;

    int majority = department / 2 + 1;
    vector<int>faculty;
    int f;
    int sum = 0;
    for (int i = 0; i < department; ++i)
    {
        cin >> f;
        faculty.push_back(f);
    }
    sort(faculty.begin(), faculty.end());
    for (int i = 0; i < majority; ++i)
    {
        sum += (faculty.at(i) / 2 + 1);
    }
    printf("%d\n", sum);
}