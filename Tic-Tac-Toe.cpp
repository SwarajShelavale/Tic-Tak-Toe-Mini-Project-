/**************************************************************************
     TIC-TAC-TOE GAME USING C++ & GRAPHICS  COPYRIGHTS: @SWARAJ SHELAVALE
***************************************************************************/
#include <iostream>
#include <string.h>
#include <conio.h>
#include <graphics.h>
#include <unistd.h>
#include<dos.h>
#include "Color.cpp"
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
int check_winner();
void board();
void clearsquare();
string name1,name2,reply;
int count1=0,count2=0;
void loading();

int main()
{
	int player = 1,i,choice;
	char mark;
	New_start:
	system("cls");
	SetConsoleTextAttribute(hConsole, 10);
	cout <<"\n\n\t* * * * * * * * * * * * * *\n";
	cout <<	   "\t*                         *\n";
	cout <<    "\t* Welcome To TIC-TAC-TOE  *\n";
	cout <<    "\t*                         *\n";
	cout <<"    \t* * * * * * * * * * * * * *\n\n\n"<<RESET;

	SetConsoleTextAttribute(hConsole, 4);
	cout<<"\t# RULES FOR TIC-TAC-TOE\n\n"<<RESET;

	SetConsoleTextAttribute(hConsole, 14);
	cout<<"\t1. The game is played on a grid that's 3 squares by 3 squares. \n";
	sleep(1);
	cout<<"\t2. Player 1 is X, & Player 2 is O.\n\t   Players take turns putting their marks in empty squares\n";
	sleep(1);
	cout<<"\t3. The first player to get 3 of their marks in a \n\t   row (up, down, across, or diagonally) is the Winner.\n";
	sleep(1);
	cout<<"\t4. When all 9 squares are full, the game is over.\n\t   If no player has 3 marks in a row, the game ends in a Draw.\n\n"<<RESET;
	sleep(1);
	cout<<RED<<"\n\t#Let's Begin\n\n"<<RESET;SetConsoleTextAttribute(hConsole, 14);

	cout<<"\t$ Enter Player 1 Name: "<<RESET;SetConsoleTextAttribute(hConsole,10);
	cin>>name1;

	cout<<RESET;SetConsoleTextAttribute(hConsole, 14);
	cout<<"\t$ Enter Player 2 Name: "<<RESET;SetConsoleTextAttribute(hConsole, 10);
	cin>>name2;
	cout<<RESET;
	start:
	loading();
	do
	{
		board();
		player=(player%2)?1:2;
		if(player==1)
		{
			sleep(0.5);
			cout <<"\t"<<GREEN<<player<<"."<<name1<<",";
			SetConsoleTextAttribute(hConsole, 11);
			cout<<" Enter a number:  "<<RESET;
		
		}
		else
		{
			sleep(0.5);
			cout <<"\t"<<GREEN<<player<<"."<<name2;
			SetConsoleTextAttribute(hConsole, 11);
			cout<<", Enter a number:  "<<RESET;
		}
			
		cout <<RED;
		cin >> choice;
		cout<<RESET;
		mark=(player == 1) ? 'X' : 'O';
		if (choice == 1 && square[1] == '1')
			square[1] = mark;
		else if (choice == 2 && square[2] == '2')
			square[2] = mark;
		else if (choice == 3 && square[3] == '3')
			square[3] = mark;
		else if (choice == 4 && square[4] == '4')
			square[4] = mark;
		else if (choice == 5 && square[5] == '5')
			square[5] = mark;
		else if (choice == 6 && square[6] == '6')
			square[6] = mark;
		else if (choice == 7 && square[7] == '7')
			square[7] = mark;
		else if (choice == 8 && square[8] == '8')
			square[8] = mark;
		else if (choice == 9 && square[9] == '9')
			square[9] = mark;
		else
		{
			cout<<RED<<"\tAlert: Invalid move ";
			player--;
			getch();
		}
		i=check_winner();
		player++;
	}while(i==-1);
	board();
	sleep(1);
	if(i==1)
	{
		--player;
		if(player==1)
		{
			count1++;
			cout<<BOLDYELLOW<<"\t==>\a Congratulations "<<GREEN<<name1<<" you are Winner!\n\n";
			cout<<RESET;
			
		}
		else
		{
			count2++;
			cout<<BOLDYELLOW<<"\t==>\a Congratulations "<<GREEN<<name2<<" you are Winner!\n\n";
			cout<<RESET;
			
		}
	}
		
	else
		cout<<BOLDYELLOW<<"\t==>\a Game draw\n\n";
	
	cout<<BOLDYELLOW<<"\t==>\aTOTAL SCORE-CARD: "<<RESET;

	cout<<GREEN<<name1<<": "<<RED<<count1<<RESET<<GREEN;
	SetConsoleTextAttribute(hConsole, 11);
	cout<<" <--> "<<RESET<<GREEN<<name2<<": "<<RED<<count2<<RESET<<"\n\n";
	sleep(1);
	cout<<"\tQ. "<<name1<<" & "<<name2<<" do you want to play again?(y/n)\n\t==>";
	cin>>reply;
	clearsquare();
	if(reply[0]=='Y' || reply[0]=='y')
	{
		system("cls");
		goto start;
	}
	else
	{
		cout<<"\tQ. Do you want to Start New Game or Exit the Game?(y/n)\n\t==>";
		cin>>reply;
		count1=0;
		count2=0;
		clearsquare();
		if(reply[0]=='Y' || reply[0]=='y')
			goto New_start;
		else
		{
			cout<<GREEN<<"\n\n\tTHANKS FOR PLAYING......HAVE A GOOD DAY!!\n\n"<<RESET;
			return 0;		
		}
	}
	getch();
	
	return 0;
}


/*********************************************
	FUNCTION TO RETURN GAME STATUS
	1 FOR GAME IS OVER WITH RESULT
	-1 FOR GAME IS IN PROGRESS
	O GAME IS OVER AND NO RESULT
**********************************************/

int check_winner()
{
	if (square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
}





void board()
{
	system("cls");
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n\n\t* * * * * * * *\n";
	cout <<     "\t*             *\n";
	cout <<     "\t* TIC-TAC-TOE *\n";
	cout <<     "\t*             *\n";
	cout <<     "\t* * * * * * * *\n\n"<<RESET;
	cout <<BOLDYELLOW<<"\t(X) "<<RESET;
	SetConsoleTextAttribute(hConsole, 11);
	cout<<name1<<" <=> "<<name2<<RESET;
	cout<<BOLDYELLOW<<" (O)" << "\n" << "\n"<<RESET;
	cout << "\n";
	cout <<"\t"<< " _________________" << "\n";
	cout <<"\t"<< "|     |     |     |" << "\n";
	cout <<"\t"<< "|  " <<RED<<square[1] <<RESET<< "  |  " <<RED<<square[2] <<RESET<< "  |  " <<RED<<square[3] <<RESET<< "  |\n";
	cout <<"\t"<< "|_____|_____|_____|" << "\n";
	cout <<"\t"<< "|     |     |     |" << "\n";
	cout <<"\t"<< "|  " <<RED<<square[4] <<RESET<< "  |  " <<RED<<square[5] <<RESET<< "  |  " <<RED<<square[6] <<RESET<< "  |\n";
	cout <<"\t"<< "|_____|_____|_____|" << "\n";
	cout <<"\t"<< "|     |     |     |" << "\n";
	cout <<"\t"<< "|  " <<RED<<square[7] <<RESET<< "  |  " <<RED<<square[8] <<RESET<< "  |  " <<RED<<square[9] <<RESET<< "  |\n";
	cout <<"\t"<< "|_____|_____|_____|"<< "\n\n\n"<<RESET;;

}

void clearsquare()
{
	int i=1,j=49;
	for(i=1;i<10;i++,j++)
	{
		square[i]=j;
	}
}

void loading()
{
	
    cout<<"\n\n";
    cout<<GREEN<<"\tPlease Wait....\n";
    cout<<"\tLoading ";
    cout<<". ";
    Sleep(1000);
    cout<<". ";
    Sleep(1000);
    cout<<". ";
    Sleep(1000);
    cout<<". ";
    Sleep(1000);
    cout<<". ";
    Sleep(1000);
    cout<<". ";
    Sleep(1000);
    cout<<". ";
    Sleep(1000);
   	cout<<RESET;
    system("cls");
    
}
