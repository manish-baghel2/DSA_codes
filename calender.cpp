#include<bits/stdc++.h>
using namespace std;

class user
{
    public:

        vector<pair<string, pair<int, int> > > events;
        string name;
        public:
        user()
        {
        }

        string aduser(string s, vector<user> namelist)
        {
            for(auto i:namelist)
            {
                if(s == i.name)
                {
                    return "failed";
                }
            }
            name = s;
            return "success";
        }

        string event(string  date, int start, int dur)
        {
            for(auto j:events)
            {
                if(date == j.first)
                {
                    if(start <= j.second.second and start>= j.second.first)
                    {
                        return "failed";
                    }
                }
            }
            
            int end = start + dur -1;
            if(end >= 1439)
            {
                return "failed";
            }
            events.push_back(make_pair(date, make_pair(start, end)));
            return "success";
        }

        void list_of_events(string day, vector<user> namelist)
        {
            for(auto j:events)
            {
                if(day == j.first)
                {
                    cout<<j.second.first<<"-"<<j.second.second;
                    for(auto i:namelist)
                    {
                        for(auto t:i.events)
                        {
                            if(t.first == day)
                            {
                                if(t.second.first == j.second.first and t.second.second == j.second.second)
                                {
                                    cout<<i.name;
                                }
                            }
                        }
                    }
                }
            }
            cout<<endl;
            // for(auto i:namelist)
            // {
            //     for(auto t:i.events)
            //     {
            //         if(t.first == day)
            //         {
            //             if(t.second)
            //         }
            //     }
            // }
        }

        
};

int main()
{

}