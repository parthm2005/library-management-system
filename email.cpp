#include<bits/stdc++.h>
using namespace std;
bool isChar(char c)
{
    return ((c>='A' && c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')||c=='@'||c=='.');
}
bool isValid(string email)
{
    if(email[0]=='@') return 0;
    if(!isChar(email[0])) return 0;
    int At=-1,Dot=-1;
    for(int i=0;i<email.length();i++)
    {
        if(!isChar(email[i])) return 0;
        if(email[i]=='@'&& At==-1) At=i;
        else if(email[i]=='@' && At!=-1) return 0;
        else if(email[i]=='.' && Dot!=i-1) Dot=i;
        else if(email[i]=='.' && Dot==i-1) return 0;
    }
    if(At==-1 || Dot==-1) return 0;
    if(At>Dot||At+1==Dot) return 0;
    if(Dot>=email.length()-1) return 0;
    return 1;
}
int main()
{   
    string email;
    cin>>email;
    int x=isValid(email);
    cout<<x<<endl;

    main();
    return 0;
}