#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <fstream>
using namespace std;
static int wysokosc=11;
static int szerokosc=31;
int punkty=0,wynik;
int x = 14,y = 10;
int vsY=0;
int vsX1=4,vsX2=9,vsX3=14,vsX4=19;
bool vs1=true,vs2=true,vs3=true,vs4=true;
int vsshotY=1;
bool vsshot=false;
int strzalx = x+1,strzaly = y-1;
bool strzal = false;
int life=3;
static bool Koniec = false;
int los=0;
int vsshotX[3];
string nick;
void baner()
{
cout<<endl<<endl<<"         :::::::: :::::::: ::::::::::: :::::::::   ::::::::"<<endl; 
cout<<"            :+: :+:       :+:    :+:  :+:    :+: :+:    :+:"<<endl;
cout<<"          +:+  +:+       +:+    +:+  +:+    +:+ +:+    +:+"<<endl;
cout<<"        +#+   +#++:++#  +#++:++#+   +#++:++#:  +#+    +:+"<<endl;  
cout<<"      +#+    +#+       +#+    +#+  +#+    +#+ +#+    :+:"<<endl;
cout<<"    #+#     #+#       #+#    #+#  #+#    #+# #+#    #+#"<<endl;     
cout<<"  ####### ########## ##########  ###    ###  ########       "<<endl;
HANDLE hOut;
hOut=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
cout<<"                                 E N T E R T E I M E N T ";
}
void menu()
{
HANDLE hOut;
hOut=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_INTENSITY);	
cout<<"   _______ _                  _____                      "<<endl;
cout<<"  |__   __| |                / ____|                     "<<endl;
cout<<"     | |  | |__   ___       | (___  _ __   __ _  ___ ___ "<<endl;
cout<<"     | |  | '_ \\ / _ \\       \\___ \\| '_ \\ / _` |\/ __/ _ \\"<<endl;
cout<<"     | |  | | | |  __/       ____) | |_) | (_| | (_|  __/"<<endl;
cout<<"     |_|  |_| |_|\\___|  /\\  |_____/| .__/ \\__,_|\\___\\___|"<<endl;                                  
cout<<"                       /  \\   _   _|_|          _    "<<endl;
cout<<"                      / /\\ \\ | |_| |_ __ _  ___| | __"<<endl;
cout<<"                     / /__\\ \\| __| __/ _` |/ __| |/ /"<<endl;
cout<<"                    /  ____  \\ |_| || (_| | (__|   < "<<endl;
cout<<"                   /_/      \\_\\__|\\__\\__,_|\\___|_|\\_\\"<<endl<<endl<<endl<<endl<<endl;
SetConsoleTextAttribute(hOut,14|FOREGROUND_INTENSITY);
cout << " "<<(char)254<<" Nowa gra"<<endl;
cout << " "<<(char)254<<" Tworcy"<<endl;
cout << " "<<(char)254<<" Najlepsze wyniki"<<endl;
cout << " "<<(char)254<<" Sterowanie"<<endl;
cout << " "<<(char)254<<" Quit game";
}
void czyszczenie()
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

void start()
{
	HANDLE hOut;
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	cout <<endl<< "   Podaj swoj nick : ";
	SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	cin >> nick;
	SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	char start;
	cout<< endl<<" "<<(char)201;
	for (int i = 0; i<szerokosc; i++)
	{
		cout << (char)205;
	}
	cout << (char)187<<endl;
	cout << endl<<endl<<endl<<endl<< "        PASS ENTER TO START"<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<" "<<(char)200;
	for (int i = 0; i<szerokosc; i++)
	{
		cout << (char)205;
	}
	cout << (char)188<<endl;
	start = getch();
	system ( "cls" );
}

void nowa_plansza()
{			
	HANDLE hOut;
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_INTENSITY);

	cout<<(char)201;
	for (int p = 0;p<szerokosc;p++)
		cout << (char)205;
	cout << (char)187<<endl;
	
	for (int i =0;i<wysokosc;i++)
	{
		for(int j=0;j<szerokosc;j++)
		{
			
			SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			if (j==0)
			{
				cout << (char)186;
			}
			SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_INTENSITY);
			if (j==x && i==y)
			{
				cout <<(char)47<<(char)206<<(char)92;
			}
			SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
			if (vs1==true && i==vsY && j == vsX1 )
			{
				cout<<(char)60<<(char)194<<(char)62;
			}
			else if(vs1==false && i==vsY && j == vsX1)
			{
				cout<<"   ";
			}
			else if (vs2==true && i==vsY && j == vsX2 )
			{
				cout<<(char)60<<(char)194<<(char)62;
			}
			else if(vs2==false && i==vsY && j == vsX2)
			{
				cout<<"   ";
			}
			else if (vs3==true && i==vsY && j == vsX3 )
			{
				cout<<(char)60<<(char)194<<(char)62;
			}
			else if(vs3==false && i==vsY && j == vsX3)
			{
				cout<<"   ";
			}
			else if (vs4==true && i==vsY && j == vsX4 )
			{
				cout<<(char)60<<(char)194<<(char)62;
			}
			else if(vs4==false && i==vsY && j == vsX4)
			{
				cout<<"   ";
			}
			else if (strzal==true && i == strzaly && j == strzalx)
			{
				cout << "!";
			}
			else if(vs1==true && vsshot==true && i==vsshotY && j==vsshotX[los]) 
			{
				cout << ".";
			}
			else if(vs2==true && vsshot==true && i==vsshotY && j==vsshotX[los])
			{
				cout << ".";
			}
			else if(vs3==true && vsshot==true && i==vsshotY  && j==vsshotX[los])
			{
				cout << ".";
			}
			else if(vs4==true && vsshot==true && i==vsshotY  && j==vsshotX[los])
			{
				cout << ".";
			}
			else
			{
				bool print = true;
				if (print)
				{
					cout << " ";
				}
				
			}
			
			SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
			if(i == vsY&&j==22)
			{
				cout << (char)186;
			}
			if(i == y&&j==27)
			{
				cout << (char)186;
			}
 			SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            if (j == szerokosc - 1 && i!=vsY && i!=y)
                cout << (char)186;
		}cout<<endl;
	}
	cout << (char)200;
	for (int k = 0;k<szerokosc;k++)
		cout << (char)205;
	cout << (char)188;
}

void sterowanie()
{
	if (kbhit())
	{
		switch (getch())
			{
				case 'a':
					case 'A':
					x--;
					break;
				case 'd':
					case 'D':
					x++;			
					break;
				case 'w':
					case 'W':
						y--;
					break;
				case 's':
					case 'S':
						y++;
					break;
				case 'k':
					case 'K':
				{	
					strzal= true;
					break;}	 	
			}
	}
}

void dzialanie()
{
	if (vs1==false&&vs2==false&&vs3==false&&vs4==false)
	{
		punkty+=10;
		vs1=true;vs2=true;vs3=true;vs4=true;
	}
	if (x==28) x = 1;	else if (x==0) x = 27; //hit wall
	if (y>=wysokosc-1) y=wysokosc-1; else if (y<=wysokosc-3) y=wysokosc -3;

	if (strzal==true && strzaly >= vsY-1) //fireline
	{
		strzaly --;
	}
	if(strzaly == vsY && strzalx >= 4 && strzalx <= 6 && strzal==true && vs1==true) punkty += 10; //points
	if(strzaly == vsY && strzalx >= 11 && strzalx <= 13 && strzal==true && vs2==true) punkty += 10;
	if(strzaly == vsY && strzalx >= 18 && strzalx <= 20 && strzal==true && vs3==true) punkty += 10; 
	if(strzaly == vsY && strzalx >= 25 && strzalx <= 27 && strzal==true && vs4==true) punkty += 10;
	
	if(strzaly == vsY && strzalx >= 4 && strzalx <= 6 && strzal==true) vs1=false; //likwidowanie przeciwnikow
	if(strzaly == vsY && strzalx >= 11 && strzalx <= 13 && strzal==true) vs2=false; //likwidowanie przeciwnikow
	if(strzaly == vsY && strzalx >= 18 && strzalx <= 20 && strzal==true) vs3=false; //likwidowanie przeciwnikow
	if(strzaly == vsY && strzalx >= 25 && strzalx <= 27 && strzal==true) vs4=false; //likwidowanie przeciwnikow

	if(strzaly == vsY) //odnowa strzalu
	{
		strzal=false;
	}

	if (strzal==false)
	{
		strzaly=y;strzalx=x+1;
	}
	if(vsshotY==1&&vs1==true)vsshot=true;
	if(vsshotY==1&&vs2==true)vsshot=true;	
	if(vsshotY==1&&vs3==true)vsshot=true;	
	if(vsshotY==1&&vs4==true)vsshot=true;	
	if(vsshot==true && vsshotY<=y) vsshotY++; //vs fire
	if(vsshot==true && vsshotY==y && vsshotX[los]>=x && vsshotX[los]<=x+2)
	{
	life--;
	Sleep(1000);}
	if(vsshot==true && vsshotY==y) vsshot=false;
	if(vsshot==false) vsshotY=1;
	
	if (life == 0) Koniec=true;
	if (vsshot==false) los++;
	if (los > 3) los=0;
	if (los==0 && vs1==false && vsshot==false) los=1;
	if (los==1 && vs2==false && vsshot==false) los=2;
	if (los==2 && vs3==false && vsshot==false) los=3;
	if (los==3 && vs4==false && vs1==true && vsshot==false) los=4;
	
	if (Koniec==true) //lose result
	{
		wynik = punkty;
		ofstream plik;
		plik.open("Best.txt", ios::out|ios::app);
		plik<<nick<<"  "<<wynik<<"p"<<endl<<endl;
		plik.close();
		system ("cls");
		cout <<endl<<endl<< "YOU ARE LOOSER";
		Sleep (3000);
		system ("cls");
	}
}


int main(int argc, char** argv) 
{
	
	vsshotX[0]=5;
	vsshotX[1]=12;
	vsshotX[2]=19;
	vsshotX[3]=26;
	int wybor;
	HANDLE hOut;
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	baner();
	Sleep (3000);
	system ( "cls" );
	cout<<flush;
	
while(wybor!='5')
{
	life = 3;
	menu();
	wybor=getch();
	system ( "cls" );
	switch (wybor)
	{
		
		case '2':
		{
			system ( "cls" );
			cout <<endl<< " Glowny Deweloper    "<<endl<<"    Jakub "<<(char)189<<"ebrowski";
			cout <<endl<<endl<<" Wszystko "<<endl<<"    Jakub "<<(char)189<<"ebrowski   :P";
			getch();
			system ( "cls" );
			break;
		}
		case '1':
		{	
			system ( "cls" );	
			start();
			while (Koniec!=true)
			{
				czyszczenie();
				SetConsoleTextAttribute( hOut, 14);
				cout << " PUNKTY : "<<punkty<< endl;
				nowa_plansza();
				sterowanie();
				dzialanie();
				SetConsoleTextAttribute( hOut, 14);
				cout<<endl<< " ZYCIA:                        "<<life;
			}
		
			system ("cls");
			break;
		}
		case '4':
		{
			system ("cls");
			cout <<endl<<endl<< "   Gora     |   W";
			cout <<endl<<endl<< "   Dol      |   S";
			cout <<endl<<endl<< "   Prawo    |   D";
			cout <<endl<<endl<< "   Lewo     |   A";
			cout <<endl<<endl<< "   Strzal   |   K";
			getch();
			system ("cls");
			break;
		}
		case '3':
			{
				cout << " NICK   WYNIK" <<endl;
				string score;
				ifstream plik;
				plik.open("Best.txt", ios::in);
				do
				{
					getline (plik,score);
					cout<< "  "<<score<<endl;
				}while ( getline(plik,score));
				plik.close();
				getch();
				system ( "cls" );
			}
		case '5':
			break;
	}
}
	return 0;
}
