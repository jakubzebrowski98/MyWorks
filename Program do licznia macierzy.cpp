#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
  int **A,**B,**C,m,n,p,i,j,k,s;

	cout << "podaj wymiary 1 macierzy \n\n";
  cout << "podaj ilosc kolumn\n";
  while (!(cin >> m) || m == 0)
  {
  		cin.clear();
		cin.sync();
  	cout << "podaj liczbe!!\n";
  }
  		cin.clear();
		cin.sync();
  cout << "podaj ilosc wierszy\n";
    while (!(cin >> n) || n == 0)
  {
  		cin.clear();
		cin.sync();
  	cout << "podaj liczbe!!\n";
  }
  		cin.clear();
		cin.sync();
  	cout << "podaj wymiary 2 macierzy \n\n";
  	
  cout << "podaj ilosc kolumn\n";
    while (!(cin >> p) || p == 0)
  {
  		cin.clear();
		cin.sync();
  	cout << "podaj liczbe!!\n";
  }
  		cin.clear();
		cin.sync();
  
  cout << "ilosc wierszy 2 maciezy jest zalezna od\nilosci wierszy pierwszej i wynosci "<<n<<endl<<endl;
  
  
  A = new int * [m];
  B = new int * [n];
  C = new int * [m];

  for(i = 0; i < m; i++)
  {
    A[i] = new int[n];
    C[i] = new int[p];
  }

  for(i = 0; i < n; i++) B[i] = new int[p];

cout << "podaj wyrazy 1 macierzy \n";
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j ++)
	{
		cout << "kolumna "<<i+1<<" wiersz "<<j+1<<"\n";
	 	  while (!(cin >> A[i][j]))
  		{
  			cin.clear();
			cin.sync();
  			cout << "podaj liczbe!!\n";
	  	}
	}
		cin.clear();
		cin.sync();
cout << "podaj wyrazy 2 macierzy\n";
  for(i = 0; i < n; i++)
    for(j = 0; j < p; j++)
    {
	cout << "kolumna "<<i+1<<" wiersz "<<j+1<<"\n"; 
		 	  while (!(cin >> B[i][j]))
  		{
  			cin.clear();
			cin.sync();
  			cout << "podaj liczbe!!\n";
	  	}
	
	}
  cout << endl;

  for(i = 0; i < m; i++)
    for(j = 0; j < p; j++)
    {
      s = 0;
      for(k = 0; k < n; k++) s += A[i][k] * B[k][j];
      C[i][j] = s;
    }

  cout <<  "Wynik \n";

  for(i = 0; i < m; i++)
  {
    for(j = 0; j < p; j++) cout << setw(6) << C[i][j];
    cout << endl;
  }
  return 0;
} 
