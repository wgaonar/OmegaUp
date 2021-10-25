// 1460_K_Ceros
// https://omegaup.com/arena/problem/cuentas/
// Wilmer Gaona Romero
// 10.08.2021

#include <bits/stdc++.h>
using namespace std;

int main() {

int n,c;
cin>>c>>n;

int *cuentas = new int[n];
bool flag=false;
for(int i=0;i<n;i++)
{
    cin>>cuentas[i];
}

int izq=0,der=0,cont0=0,t=n,tt=0;
if(cuentas[0]==0)
{
    cont0=1;
}

while(izq<n)
{
    if(cont0==c)
    {
        if(flag==true)
        {
            tt=abs((n+der)-izq)+1;
        }
        else
        {
            tt=abs(der-izq)+1;
        }
        if(tt<t)
        {
            t=tt;
        }
        izq++;
        cont0--;
        //cout<<"primero"<<endl;
        /*if(cuentas[izq]==0)
        {
            cont0++;
        }*/
    }
    else if(cont0<c&&cuentas[izq]==1)
    {
        izq++;
        /*if(cuentas[izq]==0) 
        {
            cont0++;
        }*/
        //cout<<"segundo"<<endl;
    }
    else if(cont0<c&&cuentas[izq]==0)
    {
        der++;
        if(der==n)
        {
            der=0;
            flag=true;
        }
        if(cuentas[der]==0)
        {
            cont0++;
        }
        //cout<<"tercero"<<endl;
    }
    /*if(der==n)
        {
            der=0;
            flag=true;
            cout<<endl<<flag<<endl;
        }*/
    //cout<<"izq: "<<izq<<endl<<"der: "<<der<<endl<<"cont0: "<<cont0<<endl<<"t: "<<tt<<endl<<endl;
    
}

cout<<t-c; 

	return 0;
}