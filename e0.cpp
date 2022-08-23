#include <bits/stdc++.h>
using namespace std;
int cn,sum;
char ch;
string name,s,str,ss;
vector<string> a;
vector<string>::iterator it;
int main()
{
    system("cd");
    system("clear");
    cout<<"文件名：";
    getline(cin,name);
    fstream f(name.c_str());
    if(!f.good())
    {
        while(true)
        {
            system("clear");
            cout<<"文件不存在！是否需要创建？[Y/N]"<<endl;
            cin>>ch;
            if(ch=='y'||ch=='Y')
            {
                s="touch "+name;
                system(s.c_str());
                break;
            }
            else if(ch=='n'||ch=='N')
            {
                exit(0);
            }
            else
            {
                cout<<"输入有误！请重试！"<<endl;
                sleep(1);
            }
        }
    }
    freopen(name.c_str(),"r",stdin);
    while(getline(cin,str))
    {
        cn++;
        a.push_back(str);
    }
    freopen("/dev/tty","r",stdin);
    cin.clear();
    while(true)
    {
        system("clear");
        for(int i=0;i<a.size();i++)
        {
            cout<<setw(4)<<i+1<<" "<<a[i]<<endl;
        }
        sum=0;
        it=a.begin();
        getline(cin,str);
        for(int i=2;i<str.length();i++)
        {
            sum=sum*10+str[i]-'0';
        }
        for(int i=1;i<sum;i++)
        {
            it++;
        }
        if(str=="s")
        {
            freopen(name.c_str(),"w",stdout);
            for(int i=0;i<a.size();i++)
            {
                cout<<a[i]<<endl;
            }
            freopen("/dev/tty","w",stdout);
        }
        else if(str=="sq"||str=="q")
        {
            freopen(name.c_str(),"w",stdout);
            for(int i=0;i<a.size();i++)
            {
                cout<<a[i]<<endl;
            }
            freopen("/dev/tty","w",stdout);
            exit(0);
        }
        else if(str[0]=='i')
        {
            int x=a.size();
            getline(cin,ss);
            if(sum-x>=2)
            {
                for(int i=1;i<=sum-x-1;i++)
                {
                    a.insert(a.end(),"");
                }
                a.insert(a.end(),ss);
            }
            else
            {
                a.insert(it,ss);
            }
        }
        else if(str[0]=='d')
        {
            if(sum>=1&&sum<=a.size())
            {
                a.erase(it);
            }
            else
            {
                cout<<"输入有误！"<<endl;
                cin.get();
            }
        }
        else if(str[0]=='c')
        {
            if(sum>=1&&sum<=a.size())
            {
                getline(cin,a[sum-1]);
            }
            else
            {
                cout<<"输入有误！"<<endl;
                cin.get();
            }
        }
        else
        {
            cout<<"输入有误！"<<endl;
            cin.get();
        }
    }
    return 0;
}
