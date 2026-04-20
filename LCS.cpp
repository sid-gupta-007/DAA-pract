#include <iostream>
#include <cstring>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    char X[100], Y[100];
    int dp[100][100];

    cout << "Enter first string: ";
    cin >> X;

    cout << "Enter second string: ";
    cin >> Y;

    int m = strlen(X);
    int n = strlen(Y);

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << "Length of LCS = " << dp[m][n] << endl;

    char lcs[100];
    int index = dp[m][n];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    cout << "LCS = " << lcs << endl;
    return 0;
}
