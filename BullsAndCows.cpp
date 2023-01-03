class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int secretfreq[10];
        int guessfreq[10];
        for (int i = 0; i < 10; i++)
        {
            secretfreq[i] = 0;
            guessfreq[i] = 0;
        }
        for (int i = 0; i < secret.size(); i++)
        {
            secretfreq[secret[i] - '0']++;
            guessfreq[guess[i] - '0']++;
        }
        int bull = 0;
        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                bull++;
                secretfreq[secret[i] - '0']--;
                guessfreq[secret[i] - '0']--;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            cout << secretfreq[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << guessfreq[i] << " ";
        }
        int cow = 0;
        for (int i = 0; i < 10; i++)
        {
            if (secretfreq[i] != 0 && guessfreq[i] != 0)
            {
                cout << min(secretfreq[i], guessfreq[i]);
                cow += min(secretfreq[i], guessfreq[i]);
            }
        }
        string s = to_string(bull) + 'A' + to_string(cow) + 'B' return s;
    }
};