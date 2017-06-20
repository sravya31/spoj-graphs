#include<bits/stdc++.h>

using namespace std;

int main(){
int t;
cin>>t;
while(t--){
  int x,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;
  cin>>x;
  int i;
  char exp[41];
  cin>>exp;
  for(i=0;i<strlen(exp);i++){
     if(exp[i]=='T' && exp[i+1]=='T' && exp[i+2]=='T')
        a++;
     else
     if(exp[i]=='T' && exp[i+1]=='T' && exp[i+2]=='H')
        b++;
     else
     if(exp[i]=='T' && exp[i+1]=='H' && exp[i+2]=='T')
        c++;
     else
     if(exp[i]=='T' && exp[i+1]=='H' && exp[i+2]=='H')
        d++;
     else
     if(exp[i]=='H' && exp[i+1]=='T' && exp[i+2]=='T')
        e++;
     else
     if(exp[i]=='H' && exp[i+1]=='T' && exp[i+2]=='H')
        f++;
     else
     if(exp[i]=='H' && exp[i+1]=='H' && exp[i+2]=='T')
        g++;
     else
     if(exp[i]=='H' && exp[i+1]=='H' && exp[i+2]=='H')
        h++;
    }
cout<<x<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<" "<<endl;
}
return 0;
}
   
     

