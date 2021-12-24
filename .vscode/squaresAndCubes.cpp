#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> l;
        int s = 1;
        while (s*s <= n)
        {
            if (s == 1 and s <= n)
            {
                l.push_back(s);
            }
            else if (s * s <= n)
            {
                l.push_back(s * s);
                if (s * s * s <= n)
                {
                    l.push_back(s * s * s);
                }
            }
            else
            {
                break;
            }
            s++;
        }
        cout << l.size() << endl;
    }
}