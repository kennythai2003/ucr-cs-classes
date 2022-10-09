#include <bits/stdc++.h>
using namespace std;

bool hit(long long a, long long b, long long c, long long d, long long range){
    long double val;
    bool safe;
    val = sqrt(pow(a-c, 2.0) + pow(b-d, 2.0));
  //  cout << "val:" << val << endl;
    if (val <= range)
    {
        safe = false;
    }
    else{
        safe = true;
    }
    return safe;
}
int main()
{
    long long willowpositionx;
    long long willowpositiony;
    cin >> willowpositionx;
    cin.ignore();
    cin >> willowpositiony;
    cin.ignore();

    long long attackrange;
    cin >> attackrange;
    cin.ignore();

    long long inputs;
    cin >> inputs;
    cin.ignore();

    long long c1;
    long long c2;
    vector<string>w;
    for (int i = 0; i < inputs; ++i)
    {
        cin >> c1;
        cin.ignore();
        cin >> c2;
        cin.ignore();

        if (hit(willowpositionx, willowpositiony, c1, c2, attackrange))
        {
            w.push_back("yes");
        }
        else{
            w.push_back("no");
        }
    }

    for (int i = 0; i < w.size(); ++i)
    {
        cout << w.at(i) << endl;
    }
    return 0;
}