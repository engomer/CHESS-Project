#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <math.h>

using namespace std;
/*** The Class that will include all pieces***/
class Piece{
    private:

    public:
        string name;
       int currow;
       int curcol;
       string colour;
       bool canjump;
        Piece(string,int,int,string);
        bool isMoveLegal(int,int);


};

/** constructer **/
Piece :: Piece(string lab,int row,int col ,string c){
    colour = c;
    if(colour=="black"){name = lab + "-B";}
    else {name = lab+ "-W";}
    currow = row;
    curcol = col;
    canjump = false;
}

/** Controls that is numbers are true **/
bool Piece::isMoveLegal(int drow, int dcol)
{
    if(currow==drow || curcol == dcol){ return true;}
    else{ return false;}
}

/** Pawn class extends Piece Class ***/
class Pawn : public Piece
{

private:
    bool isfirstmove;
public:
    Pawn(int,int,string);
    bool isMoveLegal(int, int);

};

/** Pawns constructor **/
Pawn:: Pawn(int row, int col, string c) : Piece("Pawn  ", row, col, c)
{
    isfirstmove = true;


}

/** Prepared for controlling the move but its not completed **/
bool Pawn :: isMoveLegal(int newRow, int newCol)
{
    if(isfirstmove && curcol == newCol && fabs(newRow - currow) == 2)
    {
        isfirstmove = false;
        return true;
    }
    else if(curcol == newCol && fabs(newRow - currow) == 1)
    {
        isfirstmove = false;
        return true;
    }
    return false;
}

/*** King Class extends Piece Class **/
class King : public Piece
{
    private:
    public:
        King(int, int, string);
        bool isMoveLegal(int, int);
};

/*** not completed constructor **/
King ::King(int row, int col, string c) : Piece("King  ", row, col, c){

}

/*** Knight Class extends Piece Class **/
class Knight : public Piece
{
    private:
    public:
        Knight(int, int, string);
        bool isMoveLegal(int, int);
};

/*** not completed constructor **/
Knight ::Knight(int row, int col, string c) : Piece("Knight", row, col, c){

}

/*** Queen Class extends Piece Class **/
class Queen: public Piece
{
    private:
    public:
        Queen(int, int, string);
        bool isMoveLegal(int,int);
};

/*** not completed constructor **/
Queen ::Queen(int row, int col, string c) : Piece("Queen ", row, col, c){

}

/*** Bishop Class extends Piece Class ***/
class Bishop: public Piece
{
    private:
    public:
        Bishop(int,int, string);
        bool isMoveLegal(int, int);
};

/*** not completed constructor **/
Bishop ::Bishop(int row, int col, string c) : Piece("Bishop", row, col, c){

}

/*** Rook Class extends Piece Class***/
class Rook: public Piece
{
    private:
    public:
        Rook(int,int, string);
        bool isMoveLegal(int, int);
};

/*** not completed constructor **/
Rook ::Rook(int row, int col, string c) : Piece("Rook  ", row, col, c){

}

/** Board class includes chess table, and table operations ***/
class Board
{
    private:

        void clearBoard();
    public:
        Board();
        void setBoard();
        void printBoard();
        void setPiece(string, int, int);
        void setPiece(int,int,int,int);
        string table[8][8];

};

/** Clears board makes all cells "+" ***/
void Board :: clearBoard()
{
    for(int r=0 ; r<8; r++)
    {
        for(int c=0; c<8; c++)
        {
            table[r][c] = " + ";
        }
    }
}
/** sets Pieces names to table **/
void Board :: setPiece(string pieceName, int dRow, int dCol)
{
    table[dRow][dCol] = pieceName;
}

/*** another incomplete set method **/
void Board :: setPiece(int sourceRow, int sourceCol, int destRow, int destCol)
{

}

void Board :: setBoard()
{

}

/*** Prints Chess Table **/
void Board :: printBoard()
{
    int m=8;
    cout<< endl << "-------A-----||------B----||------C----||-----D-----||-----E-----||-----F-----||-----G-----||-----H-------|";
    for(int i=7; i>-1; i--)
    {
        cout<< endl << "-------------||-----------||-----------||-----------||-----------||-----------||-----------||-------------|"<<endl;
        cout<< m;


        for( int j=0 ;j<8; j++)
        {

            if(table[i][j]== "")
            {
                cout<< "|   "<< "     "<< "   |" ;
            }
            else
            {
                cout<< "| "<<table[i][j]<< "  |" ;
            }
        }
        cout << m << "|";
         m--;
    }
    cout<< endl << "-------------||-----------||-----------||-----------||-----------||-----------||-----------||-------------|";
    cout<< endl << "-------A-----||------B----||------C----||-----D-----||-----E-----||-----F-----||-----G-----||-----H-------|"<< endl;
}

/*** Game class includes Move Control, Piece creating **/
class Game
{
    private:
        Board theBoard;
         void createPiece();
        string turn;
        int convert(char);
       // void printBoard();
        Piece * findPiece(int,int);
        bool intersection(int,int,int,int);
        void eatPiece(int,int);
        bool isitMove(int,int,int,int);

    public:
        vector <Piece*> allPieces;
        Game();
        ~Game();
        void takeTurn();
        bool movePiece(int,int,int,int);
        bool isGameOver();
        void getCreatePiece();



};

/*** get method of create piece **/
void Game :: getCreatePiece(void)
{
    return createPiece();
}

/*** constructor ***/
Game :: Game()
{
    createPiece();


    turn = "white";
    cout << "The Game is Starting... \n";

    takeTurn();
}

/*** Creates pieces with using vector and assign them to the board ***/
void Game:: createPiece()
{


        allPieces.push_back(new Pawn(2, 1, "white"));
        allPieces.push_back(new Pawn(7, 1, "black"));
        allPieces.push_back(new Pawn(2, 2, "white"));
        allPieces.push_back(new Pawn(7, 2, "black"));
        allPieces.push_back(new Pawn(2, 3, "white"));
        allPieces.push_back(new Pawn(7, 3, "black"));
        allPieces.push_back(new Pawn(2, 4, "white"));
        allPieces.push_back(new Pawn(7, 4, "black"));
        allPieces.push_back(new Pawn(2, 5, "white"));
        allPieces.push_back(new Pawn(7, 5, "black"));
        allPieces.push_back(new Pawn(2, 6, "white"));
        allPieces.push_back(new Pawn(7, 6, "black"));
        allPieces.push_back(new Pawn(2, 7, "white"));
        allPieces.push_back(new Pawn(7, 7, "black"));
        allPieces.push_back(new Pawn(2, 8, "white"));
        allPieces.push_back(new Pawn(7, 8, "black"));

        allPieces.push_back(new King(1, 5, "white"));
        allPieces.push_back(new King(8, 5, "black"));
        allPieces.push_back(new Queen(1, 4, "white"));
        allPieces.push_back(new Queen(8, 4, "black"));
        allPieces.push_back(new Knight(1, 2, "white"));
        allPieces.push_back(new Knight(8, 2, "black"));
        allPieces.push_back(new Knight(1, 7, "white"));
        allPieces.push_back(new Knight(8, 7, "black"));
        allPieces.push_back(new Rook(1, 1, "white"));
        allPieces.push_back(new Rook(8, 1, "black"));
        allPieces.push_back(new Rook(1, 8, "white"));
        allPieces.push_back(new Rook(8, 8, "black"));
        allPieces.push_back(new Bishop(1, 6, "white"));
        allPieces.push_back(new Bishop(8, 6, "black"));
        allPieces.push_back(new Bishop(1, 3, "white"));
        allPieces.push_back(new Bishop(8, 3, "black"));



    for (int i=0; i<allPieces.size(); i++)
    {
        theBoard.setPiece(allPieces.at(i)->name, allPieces.at(i)->currow-1, allPieces.at(i)->curcol-1);

    }
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            theBoard.table[i][j] = allPieces.at(j)->name;
        }
    }

}

/** Moves piece and controls that user playing right color etc. ***/
bool Game::movePiece(int pRow, int pCol, int deRow,int deCol)
{
    Piece * temp;
    temp = findPiece(pRow, pCol);
    if(temp->currow == -1)
    {
        cout << "The piece does not exist";
        return false;
    }
    else if(turn!= temp->colour)
    {
        cout << "Wrong Colour!";
        return false;
    }
    else if(pRow == deRow && pCol == deCol)
    {
        cout << "The piece is already here...";
        return false;
    }
    else if(findPiece(deRow, deCol)->colour == temp->colour)
    {
        cout<< "in destination target, your piece exist";
        return false;
    }
    else if(intersection(pRow, pCol,deRow, deCol) && !temp->canjump)
    {
        cout << "Your piece can not jump it is not a knight";
        return false;
    }
    else if(!temp->isMoveLegal(deRow, deCol))
    {
        cout << "Move is not legal";
        return false;
    }
    return true;
    //if all conditions are supplied the piece can start to move
    cout << temp->name << "is moving to " << deRow<< " , " << deCol << endl;
    eatPiece(deRow, deCol);
    theBoard.setPiece(temp->currow-1, temp->curcol -1,deRow -1, deCol -1);
    temp->currow = deRow;
    temp->curcol = deCol;
    theBoard.table[deRow][deCol] = temp->name;
}

/*** finds the piece when its needed **/
Piece * Game::findPiece(int row, int col)
{
    Piece temp= Piece("no piece" , -1, -1, "no colour");
    bool found = false;
    Piece * currentPiece;

    for(int i=0; i<allPieces.size(); i++)
    {
        currentPiece= allPieces.at(i);
        if(currentPiece->currow == row && currentPiece->curcol == col)
        {
            return currentPiece;
        }
    }
    if(!found)
    {
        return &temp;
    }
}

/** controls the destination cell is empty or ready to be captured ***/
bool Game ::intersection(int srcRow, int srcCol, int dRow, int dCol)
{
    int tempr = srcRow;
    int tempc = srcCol;

    while(tempr!= dRow || tempc != dCol)
    {
        if(tempr < dRow) { tempr++;}
        else if(tempr> dRow) {tempr --;}

        if(tempc < dCol) {tempc++;}
        else if(tempc> dCol) {tempc--;}

        if(findPiece(tempr, tempc) ->currow != -1)
        {
            //cout << "piece found in your path " << tempr<< " , " << tempc;
            return true;
        }
        return false;
    }
}

int Game::convert(char l)
{
    return -1;
}

/** changes turns and asks user for moves **/
void Game ::takeTurn()
{
    if(turn == "white") { turn="black";}
    else {turn = "white";}
    char src1, src2, dest1, dest2;
    int srow, scol, drow, dcol;
    bool moveSuccess = false;


    while(!moveSuccess)
    {

        string answ;
        cout << turn << " , enter the piece that you want to move > " ;
        getline(cin, answ);
        if(answ.substr(0,4)=="EXIT")
            break;
       // if(answ.substr(0,3)=="NEW")
       //     clearBoard();
        if(answ.substr(0, 1) >= "A" && answ.substr(0, 1) <= "H" && answ.substr(1, 1) >= "1"
           && answ.substr(1, 1) <= "8" && answ.substr(2, 1) >= "A" && answ.substr(2, 1) <= "H"
           && answ.substr(3, 1) >= "1" && answ.substr(3, 1) <= "8")
        {
            int a,b,c,d;

            scol=answ[0]-'A';
            srow=answ[1]-'1';
            dcol=answ[2]-'A';
            drow=answ[3]-'1';

    }


}
if(isitMove(srow,scol,drow,dcol))
        {
            moveSuccess = true;
            movePiece(srow, scol, drow, dcol);
            theBoard.table[drow][dcol] = theBoard.table[srow][scol];
            theBoard.table[srow][scol] = "\0";

        }

}

/*** controls the capture ***/
void Game ::eatPiece(int r, int c)
{
    Piece * curP;
    int target= -1;

    for(int i=0; i<allPieces.size(); i++)
    {
        curP = allPieces.at(i);

        if(curP->currow == r && curP->curcol == c)
        {
            target = i;
            cout<< "You eated " <<curP->name<< endl;
        }

    }
    if(target!= -1)
    {
        allPieces.erase(allPieces.begin()+ target);
    }
}

/** controls check-mate ***/
bool Game::isGameOver()
{
    bool wKing = false;
    bool bKing = false;
    Piece * curp;

    for(int i=0; i<allPieces.size(); i++)
    {
        curp = allPieces.at(i);
        if(curp->name == "K-W") { wKing = true;}
        else if(curp->name == "K-B") {bKing= true;}
    }
    if(!wKing)
    {
        cout << "Black Wins!";
        return false;
    }
    else if(!bKing)
    {
        cout << "White Wins!";
        return false;
    }
    else {return false;}
}

/** destructor ***/
Game ::~Game()
{
    for(int i=0; i<allPieces.size(); i++)
    {
        delete allPieces.at(i);
    }
}

/** includes special algorithms which are pieces moves **/
bool Game :: isitMove(int srow, int scol, int drow, int dcol)
{
    Piece *currentP = findPiece(srow, scol);


        if(currentP->name == "PAWN" && currentP->colour == "white")
        {
            if(theBoard.table[drow][dcol]== "\0")
            {
                if(srow==1||srow+1==drow)
                    {
                        if(theBoard.table[srow+1][scol]== "\0")
                        {
                            theBoard.table[drow][dcol] = theBoard.table[srow][scol];
                            theBoard.table[srow][scol] = "\0";
                            return true;
                        }
                    }
            }
        }
}

/*** constructor */
Board :: Board()
{

    printBoard();
    //clearBoard();
}



int main()
{
    Game theGame;
    Board theBoard;





    while(!theGame.isGameOver())
    {
        theGame.takeTurn();
    }

    return 0;
}
