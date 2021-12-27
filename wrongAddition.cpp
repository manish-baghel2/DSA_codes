#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a, s;
        int b=0;
        cin>>a;
        cin>>s;
        int n=0;
        while(a>0)
        {
            int x = 0, y = 0;
            x = a%10;
            y = s%10;
            a = (a-a%10)/10;
            s = (s-s%10)/10;
            if(x > y)
            {
                y = (s%10)*10+y;
                s = (s-s%10)/10;
                b += (y-x)*pow(10, n);
            }else
            {
                b += (y-x)*pow(10,n);
            }
            n++;
        }
        cout<<b<<endl;
    }  
}