while (sec--)
    {
        string newS;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '+')
            {
                int res = (s[i - 1] - '0') + (s[i + 1] - '0');
                s[i] = res + '0';
                s[i - 1] = 'x';
                s[i + 1] = 'x';
                for (auto j : s)
                {
                    if (j == 'x')
                        continue;
                    // cout << j;
                    newS.push_back(j);
                }
                // cout << endl;
                cout << newS << endl;
                s = newS;
                break;
            }
            else if (s[i] == '-')
            {
                int res = (s[i - 1] - '0') - (s[i + 1] - '0');
                s[i] = res + '0';
                s[i - 1] = 'x';
                s[i + 1] = 'x';
                for (auto j : s)
                {
                    if (j == 'x')
                        continue;
                    // cout << j;
                    newS.push_back(j);
                }
                // cout << endl;
                cout << newS << endl;
                s = newS;
                break;
            }
        }
    }