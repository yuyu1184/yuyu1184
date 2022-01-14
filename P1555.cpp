#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int turn2(string str)
{
    int ans = 0;
    for (auto u : str)
        ans = (ans << 1) + u - '0';
    return ans;
}

int turn3(string str)
{
    int ans = 0;
    for (auto u : str)
        ans = (ans << 1) + ans + u - '0';
    return ans;
}

int main()
{
    string s, t;
    cin >> s >> t;
    int lens = s.length(), lent = t.length();
    for (int i = 0; i < lens; i ++)
    {
        string backup = s;
        for (int j = 0; j <= 1; j ++)
        {
            s[i] = j + '0';
            for (int k = 0; k < lent; k ++)
            {
                string backup_2 = t;
                for (int l = 0; l <= 2; l ++)
                {
                    t[k] = l + '0';
                    int turn_s = turn2(s);
                    int turn_t = turn3(t);
                    if (turn_s == turn_t)
                    {
                        cout << turn_s << endl;
                        return 0;
                    }
                    t = backup_2;
                }
            }
            s = backup;
        }
    }
    return 0;
}
