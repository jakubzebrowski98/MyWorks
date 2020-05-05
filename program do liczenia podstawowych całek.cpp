#include<iostream>
#include<cstdlib>
using namespace std;

int horner(long long int wsp[],long long int st, long long int x)
{
	if(st==0)
		return wsp[0];
	
	return x*horner(wsp,st-1,x)+wsp[st];
}

int main()
{
	long long int *wspolczynniki;
	long long int stopien, argument;
	
	cout<<"Podaj stopien wielomianu jako dodatnia l.calkowita: ";
	while (!(cin>>stopien) || stopien < 0)
		{
		cin.clear();
		cin.sync();
		cout << "\nPodaj liczbe dodatnia !!: ";
		}
	
	wspolczynniki = new long long int [stopien+1];
	
	for(int i=0;i<=stopien;i++)
	{
		cout<<"Podaj wspolczynnik przy "<<stopien-i<<" potedze : ";
		while (!(cin>>wspolczynniki[i]))
		{
		cin.clear();
		cin.sync();
		cout << "\nPodaj liczbe!!: ";
		}
	}
	
	cout<<"Podaj argument: ";
	while (!(cin>>argument))
		{
		cin.clear();
		cin.sync();
		cout << "\nPodaj liczbe!!: ";
		}
	
	cout<<"F0 = "<<horner(wspolczynniki,stopien,argument)<<endl;
	
	system("pause");
	return 0;
}

