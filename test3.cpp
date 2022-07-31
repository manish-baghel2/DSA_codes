#include<bits/stdc++.h>
using namespace std;

int main()
{
		map<string, string> mp;
        int j='A';
        for(char i = 1;i<=26;i++)
        {
            
            mp[to_string(i)]=j;j++;
        }
		cout<<mp["25"];
		// int n = 7;
		// char a = 7;
		// string j = to_string(a);
		// string k = "07";
		// if(j == k)
		// {
		// 	cout<<"ok";
		// }
		// else{
		// 	cout<<"not ok";
		// }
}