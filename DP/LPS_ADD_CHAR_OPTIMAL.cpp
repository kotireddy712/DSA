#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'longestPalindromicSubsequence' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */
int longestPalindromicSubsequence(string s, int k) 
{
    int l=s.length();
    if(k==0)
    {
        return 26*(l+1);
    }
    vector<vector<int>> dp(l+1,vector<int>(l+1,0));
    for(int i=l-1;i>=0;i--)
    {
        dp[i][i]=1;
        for(int j=i+1;j<l;j++)
        {
            int temp= max(dp[i+1][j],dp[i][j-1]);
            if(s[i]==s[j])
            {
                temp = max(2+dp[i+1][j-1],temp);
            }
            dp[i][j]=temp;
        }
    }
    vector<vector<int>> pref(l+1,vector<int>(l+1,0));
    string r=s;
    reverse(r.begin(),r.end());
    for(int i=1;i<=l;i++)
    {
        for(int j=1;j<=l;j++)
        {
            int maxL = max(pref[i][j-1],pref[i-1][j]);
            if(s[i-1]==r[j-1])
            {
                maxL = max(maxL,1+pref[i-1][j-1]);
            }
            pref[i][j]=maxL;
        }
    }
    int count=0,oldLPS=dp[0][l-1];
    vector<int> temp(l+1);
    for(int i=0;i<=l;i++)
    {
        temp[i]=1+2*pref[i][l-i];
    }
    vector<vector<int>> pos(26);
    for(int i=0;i<l;i++)
    {
        pos[s[i]-'a'].push_back(i);
    }
    for(int i=0;i<=l;i++)
    {
        for( char c='a';c<='z';c++ )
        {
            int currMax = temp[i];
            for( int j: pos[c-'a'] )
            {
                if( i <= j )
                {
                    currMax = max( currMax,2 + 2 * pref[i][l-j-1]+ dp[i][j-1] );
                }
                else
                {
                     currMax = max( currMax,2 + 2 * pref[j][l-i]+ dp[j+1][i-1] );
                }
            }
            if( currMax >= oldLPS+k ) 
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        string s;
        getline(cin, s);

        int result = longestPalindromicSubsequence(s, k);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}