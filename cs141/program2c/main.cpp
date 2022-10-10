#include <bits/stdc++.h>
using namespace std;
int gcf (int, int);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int money;
    int candlePrice;
    vector<int> candle{ 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> price;
    vector<int> usableC;
    vector<int> usableP;
 
    cin >> money;
    cin.ignore();
 
    for (int i = 0; i < 9; i++)
    {
        cin >> candlePrice;
        cin.ignore();
 
        price.push_back(candlePrice);
    }
 
    //insertion sort
    int key1, key2, j;
    for (int i = 1; i < price.size(); i++)
    {
        key1 = price.at(i);
        key2 = candle.at(i);
        j = i - 1;
 
        while (j >= 0 && price.at(j) > key1)
        {
            price.at(j + 1) = price.at(j);
            candle.at(j + 1) = candle.at(j);
 
            j = j - 1;
        }
 
        price.at(j + 1) = key1;
        candle.at(j + 1) = key2;
    }
 
    // for (int i = 0; i < 9; i++)
    // {
    //     cout << "candle: " << candle.at(i) << " price: " << price.at(i) << endl;
    // }
 
    for (int i = 0; i < candle.size(); ++i)
    {
        for (int j = i + 1; j < candle.size() - 1; ++j)
        {
            cout << "comparing candle " << i << ": " << price.at(i) << " vs candle " <<j << ": " << price.at(j) << endl;
            if(gcf(price.at(i), price.at(j)) == price.at(i) && gcf(price.at(i), price.at(j)) == price.at(j))
            {
               if (candle.at(i) < candle.at(j))
               {
                   usableC.push_back(candle.at(j));
                   usableP.push_back(price.at(j));
               }
               else
               {
                   usableC.push_back(candle.at(i));
                   usableP.push_back(price.at(i));                  
               }
            }
            else if (gcf(price.at(i), price.at(j)) == price.at(i))
            {
                   usableC.push_back(candle.at(i));
                   usableP.push_back(price.at(i));            
            }
            else if (gcf(price.at(i), price.at(j)) == price.at(j))
            {
                   usableC.push_back(candle.at(j));
                   usableP.push_back(price.at(j));  
            }
 
        }
    }
    for (int i = 0; i < 9; i++)
    {
        cout << "usable candle: " << usableC.at(i) << " price: " << usableP.at(i) << endl;
    }    
    return 0;
}
int gcf (int a, int b)
{
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
 
    return a;
}

