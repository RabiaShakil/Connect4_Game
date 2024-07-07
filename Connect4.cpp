
#include<iostream>
#include<string>

using namespace std;


struct connect4{

    connect4(string Names[]){
        re_init(Names);
    }
    connect4(){
        string N[2] = {"P1", "P2"};
        re_init(N);
    }
    void re_init(string Names[]){
        for(int i = 0; i< 7; i++){
            ColumnMoves[i] = 6;
            for(int j = 0; j< 6; j++)
                 Data[j][i] = 32; 
        }
        GameOver = 0;
        PlayerNames[0] = Names[0];
        PlayerNames[1] = Names[1];
        PlayerChar[0] = 'o';
        PlayerChar[1] = 'x';
        PlayerWinningChar[0] = 'O';
        PlayerWinningChar[1] = 'X';
    }
      
	
 

    int MakeMove(int Column)
	{
        WhosTurn();
        int i=0,j=0;
        Column--;
        j=ColumnMoves[Column]-1;
        int Rows=j;
        int Col=Column;
        Data[Rows][Col]=PlayerChar[TurningPlayer];
        ColumnMoves[Column]--;
        bool b=CheckIfGameOver(Rows,Col);
        if(b==true)
        {
        	GameOver=true;
        	isGameOver();
		}  
		 
    }

    int ShowGame(){
    cout<<" 1   2   3   4   5   6   7\n";
	for(int a = 0; a<= 5; a++)
	{
		for(int b =0; b <= 6; b++) cout<<char(218)<<char(196)<<char(191)<<" ";
		cout<<'\n';
		for(int b =0; b <= 6; b++) cout<<char(179)<<Data[a][b]<<char(179)<<" ";
		cout<<'\n';
		for(int b =0; b <= 6; b++) cout<<char(192)<<char(196)<<char(217)<<" ";
		cout<<'\n';
	}
}


    bool isGameOver(){
      return GameOver;
    }

    int WhosTurn(){
        int mod;
        TurningPlayer++;
        mod = TurningPlayer % 2; 
        if (mod == 0)
            TurningPlayer = 2;    
        else
            TurningPlayer = 1;
        return TurningPlayer;
    }

    string getPlayerName(int id){
        if(id< 0 || id > 1 )
            return "";
        return PlayerNames[id];
    }
private:
    bool CheckIfGameOver(int a, int b){
    int vertical = 1;
	int horizontal = 1;
	int diagonal1 = 1;
	int diagonal2 = 1;
	char player = Data[a][b];
	int x;
	int y;
	for(x = a +1;Data[x][b] == player && x<= 5;x++,vertical++);
	for(x = a -1;Data[x][b] == player && x >= 0;x--,vertical++);
	if(vertical >= 4)return true;

	for(y = b -1;Data[a][y] == player && y>= 0;y--,horizontal++);
	for(y = b +1;Data[a][y] == player && y<= 6;y++,horizontal++);
	if(horizontal >= 4) return true;
	
	for(x = a -1, y= b -1;Data[x][y] == player && x>=0 && y >=0; diagonal1 ++, x --, y --);
	for(x = a +1, y= b+1;Data[x][y] == player && x<=5 && y <=6;diagonal1 ++, x ++, y++);
	if(diagonal1 >= 4) return true;

	for(x= a -1, y= b +1;Data[x][y] == player && x>=0 && y <= 6; diagonal2 ++, x--, y ++);
	for(x= a +1, y= b -1;Data[x][y] == player && x<=5 && y >=0; diagonal2 ++, x++, y--);
	if(diagonal2 >= 4) return true;
	return false;

    }
    string PlayerNames[2]; // To Hold Name of Players Who are playing
    int TurningPlayer; // To save the players ID who is making a move; 0: First Player, 1: Second Player
    char PlayerChar[2]; // Characters to be shown for move
    char PlayerWinningChar[2]; // Character to be shown if player wins.
    int  ColumnMoves[7]; // An array to keep record of first empty cell in a column
    char Data[6][7]; // Array to hold game data.
    bool GameOver; // If true it means the game is over.
};


int main(){
    cout<<" Welcome to Connect 4 Game "<<endl;
    connect4 connect;
    string player[3];
    cout<<endl;
    for(int i=1;i<=2;i++)
    {
    	cout<<"Enter Player"<<i<<"'s name :"<<"  ";
    	cin>>player[i];
    	cout<<endl;
	}
	connect.ShowGame();
    string N[2] = {"P1", "P2"};
    int column,counter=1;
    int j=0;
    while (connect.isGameOver()!=true){
    for(int i=1;i<=2 && connect.isGameOver()!=true;i++) 
    {
	 cout<<"Player"<<i<<"'s Turn:"<<"  ";
	 j=i;
     cin>>column;
     cout<<endl;
     connect.MakeMove(column);
     connect.ShowGame();
     counter++;   
	}
}
	cout<<"Player "<<j<<" Won";
    return 0;
}


