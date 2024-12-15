#include<iostream>
#include<string>
#include<vector>
using namespace std;


vector<string> split(string s)
{
    vector<string>result;
    int pos = 0;
    while (pos + 1 < s.size())
    {
        int n = 0;
        while (s[pos+n]!=' '&&pos+n<s.size())
        {
            n++;
        }
        result.push_back(s.substr(pos,n));
        pos += n;
        while (s[pos] ==' '&&pos<s.size())
        {
            pos++;
        }
    }
    
    return result;
}
int main()
{
    string in;
    getline(cin,in);
    vector<string>v;
    v = split(in);
    for(int i = 0;i<v.size();i++)
        cout<<v[i]<<endl;
    return 0;
}