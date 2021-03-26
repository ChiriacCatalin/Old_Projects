#include <bits/stdc++.h>
#include <graphics.h>
#include <winbgim.h>
#include <windows.h>
#include <mmsystem.h>
using namespace std;

int mat[20][20],ct1,ct2,turn=1,Check[20][20],COPIE[20][20],done=0,mini,SINGLEplayer;
int PlayButtonCoord[]= {185,505,40,90};
int PlayButtonCoord1[]= {285,417,300,350};
int HelpButtonCoord[]= {285,417,400,450};
int ExitButtonCoord[]= {285,417,500,550};


int EasyDiff[]= {250,450,200,250};
int MediumDiff[]= {250,450,300,350};
int HardDiff[]= {250,450,400,450};

int SinglePlayerType[]= {200,500,200,250};
int MultiplayerType[] = {200,500,400,450};

int dif1=7, dif2=9, dif3=11, dif, multi=0, single=1;
int raza=25, margin=100,marginSup=150,GrosimeDrum=5;
struct coord
{
    int x1,x2,y1,y2; ///coord de verificare (butoane accesibile)
    int xx1,xx2,yy1,yy2; ///coordonare de trasare (pt a efectua desenul) - trasat drumurile
    int i1,i2,j1,j2; ///pozitiile din matrice
} CRed[500],CBlue[500];
struct CoadaLee
{
    int lin,col,val;
} Lee[1000],X;

void menu();
void difficulties();
void BackButton();
int main();
void circlefill();
void behindTheScenes();
void drawtable();
int checkForWin(int value, int iFinal, int jFinal);
void makeCopy();
void PlayAgain();
void SinglePlayer();
void GAME();
void CheckForLength(int value, int iFinal, int jFinal);
void ClearMatrix();
void GameType();
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    initwindow(700,700);
    menu();
    // SINGLEplayer;
    //PlayAgain();
    getch();
    closegraph();
    return 0;
}

void ClearMatrix()
{
    for(int i=1; i<=11; ++i)
        for(int j=1; j<=11; ++j)
            mat[i][j]=0;
}
void circlefill(int x, int y, int r)
{
    int i;
    for(i=1; i<=r; ++i)
        circle(x,y,i);
}
void behindTheScenes()
{
    int i,j;
    ClearMatrix();
    ct1=ct2=0;
    for(i=1; i<=dif; ++i) /// stabilesc valorile matricei // Lee-ul se va face la salturi de pasi in loc de 1
        for(j=1; j<=dif; ++j)
        {
            if(i%2==1 && j%2==0) ///stabilesc coordonatele de verificare la Click pentru culoarea albastra
            {
                mat[i][j]=-1; ///valoarea specifica culorii alabastre
                if(j<(dif-1)) ///liniile orizontale
                {
                    CBlue[++ct1].x1=margin+2*raza+(j-1)*3*raza, CBlue[ct1].x2=margin+(j+1)*3*raza, CBlue[ct1].y1=marginSup+(i-1)*3*raza, CBlue[ct1].y2=marginSup+2*raza+(i-1)*3*raza;
                    CBlue[ct1].xx1=margin+raza+(j-1)*3*raza, CBlue[ct1].xx2=margin+raza+(j+1)*3*raza, CBlue[ct1].yy1=marginSup+raza+(i-1)*3*raza, CBlue[ct1].yy2=marginSup+raza+(i-1)*3*raza;
                    CBlue[ct1].i1=i, CBlue[ct1].i2=i, CBlue[ct1].j1=j, CBlue[ct1].j2=j+2;
                }
                if(i<dif)/// liniile verticale
                {
                    CBlue[++ct1].x1=margin+(j-1)*3*raza, CBlue[ct1].x2=margin+2*raza+(j-1)*3*raza, CBlue[ct1].y1=marginSup+2*raza+(i-1)*3*raza, CBlue[ct1].y2=marginSup+(i+1)*3*raza;
                    CBlue[ct1].xx1=margin+raza+(j-1)*3*raza, CBlue[ct1].xx2=margin+raza+(j-1)*3*raza, CBlue[ct1].yy1=marginSup+raza+(i-1)*3*raza, CBlue[ct1].yy2=marginSup+raza+(i+1)*3*raza;
                    CBlue[ct1].i1=i, CBlue[ct1].i2=i+2, CBlue[ct1].j1=j, CBlue[ct1].j2=j;
                }
            }
            else if(i%2==0 && j%2==1)///stabilesc coordonatele de verificare la Click pentru culoarea rosie
            {
                mat[i][j]=-2; ///valoarea specifica culorii rosi
                if(j<dif) ///pe orizontala
                {
                    CRed[++ct2].x1=margin+2*raza+(j-1)*3*raza, CRed[ct2].x2=margin+(j+1)*3*raza, CRed[ct2].y1=marginSup+(i-1)*3*raza, CRed[ct2].y2=marginSup+2*raza+(i-1)*3*raza;
                    CRed[ct2].xx1=margin+raza+(j-1)*3*raza, CRed[ct2].xx2=margin+raza+(j+1)*3*raza, CRed[ct2].yy1=marginSup+raza+(i-1)*3*raza, CRed[ct2].yy2=marginSup+raza+(i-1)*3*raza;
                    CRed[ct2].i1=i, CRed[ct2].i2=i, CRed[ct2].j1=j, CRed[ct2].j2=j+2;
                }
                if(i<(dif-1)) ///pe verticala
                {
                    CRed[++ct2].x1=margin+(j-1)*3*raza, CRed[ct2].x2=margin+2*raza+(j-1)*3*raza, CRed[ct2].y1=marginSup+2*raza+(i-1)*3*raza, CRed[ct2].y2=marginSup+(i+1)*3*raza;
                    CRed[ct2].xx1=margin+raza+(j-1)*3*raza, CRed[ct2].xx2=margin+raza+(j-1)*3*raza, CRed[ct2].yy1=marginSup+raza+(i-1)*3*raza, CRed[ct2].yy2=marginSup+raza+(i+1)*3*raza;
                    CRed[ct2].i1=i, CRed[ct2].i2=i+2, CRed[ct2].j1=j, CRed[ct2].j2=j;
                }
            }
        }
    for(i=1; i<=dif; ++i) /// fac o copie a matricei pentru a nu mai apela toata functia daca vreau sa joc dinou
        for(j=1; j<=dif; ++j)
            COPIE[i][j]=mat[i][j];

}
void drawtable()
{
    int i,j;
    BackButton();
    for(i=1; i<=dif; ++i) ///desenez tabla
        for(j=1; j<=dif; ++j)
            if(mat[i][j])
            {
                if(mat[i][j]==-2)
                    setcolor(COLOR(0,70,255)); ///Blue
                else
                    setcolor(COLOR(255,0,0)); ///Red
                circle(margin+raza+(i-1)*3*raza,marginSup+raza+(j-1)*3*raza, raza);
                circlefill(margin+raza+(i-1)*3*raza,marginSup+raza+(j-1)*3*raza,raza);
            }

}
void GAME()
{
    int i,j,r=25,x,y;

    setcolor(COLOR(0,70,255));
    settextstyle(8,0,7);
    outtextxy(180, 40, "Turn:BLUE");
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            int i_value=0,j_value=0;
            getmouseclick(WM_LBUTTONDOWN,x,y);
            if(turn==1) /// daca joaca player BLUE
            {
                setcolor(COLOR(0,70,255));
                for(i=1; i<=ct1; ++i)
                    if(CBlue[i].x1<=x && CBlue[i].x2>=x && CBlue[i].y1<=y && CBlue[i].y2>=y) /// verific daca playerul a apasat pe una din poz accesibile
                    {
                        i_value=0;
                        j_value=0;
                        if(CBlue[i].i1<CBlue[i].i2) ///caut pozitia dintre cele 2 puncte
                            i_value=1;
                        if(CBlue[i].j1<CBlue[i].j2)
                            j_value=1;
                        if(mat[CBlue[i].i2-i_value][CBlue[i].j2-j_value]==0) ///ma uit daca a fost trasat un drum intre cele 2 puncte
                        {
                            ///verificand daca spatiul dintre ele este liber sau nu
                            mat[CBlue[i].i2-i_value][CBlue[i].j2-j_value]=-1;
                            makeCopy(); /// fac copia matricei si incep verificare de terminare a jocul
                            for(int index=1; index<=dif/2; ++index)
                                Lee[index].lin=1, Lee[index].col=2*index, Check[1][2*index]=1;
                            turn=2; ///schimba tura pentru playerul rosu
                            for(j=-GrosimeDrum; j<=GrosimeDrum; ++j) ///trasez drumul intre cele 2 puncte
                                line(CBlue[i].xx1+j,CBlue[i].yy1+j,CBlue[i].xx2+j,CBlue[i].yy2+j);
                            if(SINGLEplayer==0) ///daca nu joaca cu calculatorul
                            {
                                setcolor(COLOR(0,0,0));
                                outtextxy(180, 40, "Turn:BLUE");
                                setcolor(COLOR(255,0,0));
                                outtextxy(180, 40, "Turn:RED");
                            }
                            PlaySound(TEXT("MoveSound.wav"),NULL,SND_ASYNC);
                            if(checkForWin(-1,dif,-1)) /// functia ce apeleaza verificare daca playerul a castigat sau nu
                            {
                                done=1;
                                setcolor(COLOR(0,0,0));
                                outtextxy(180, 40, "Turn:RED");
                                setcolor(COLOR(0,70,255));
                                outtextxy(180, 40, "Blue Wins");/// afisez textul de GameOver (CAstigatorul)
                                delay(2000);
                                setcolor(COLOR(0,0,0));
                                outtextxy(180, 40, "Blue Wins");/// sterg textul de GameOver (CAstigatorul)
                                PlayAgain();
                            }
                        }
                    }
            }
            if(SINGLEplayer==0 && turn==2)/// daca joaca player RED
            {
                for(i=1; i<=ct2; ++i)
                    if(CRed[i].x1<=x && CRed[i].x2>=x && CRed[i].y1<=y && CRed[i].y2>=y)/// verific daca playerul a apasat pe una din poz accesibile
                    {
                        i_value=0;
                        j_value=0;
                        if(CRed[i].i1<CRed[i].i2) ///caut pozitia dintre cele 2 puncte
                            i_value=1;
                        if(CRed[i].j1<CRed[i].j2)
                            j_value=1;
                        if(mat[CRed[i].i2-i_value][CRed[i].j2-j_value]==0)///ma uit daca a fost trasat un drum intre cele 2 puncte
                        {
                            ///verificand daca spatiul dintre ele este liber sau nu
                            mat[CRed[i].i2-i_value][CRed[i].j2-j_value]=-2;
                            makeCopy(); /// fac copia matricei si incep verificare de terminare a jocul
                            for(int index=1; index<=dif/2; ++index)
                                Lee[index].col=1, Lee[index].lin=2*index, Check[2*index][1]=1;
                            turn=1;///schimba tura pentru playerul albastru
                            for(j=-GrosimeDrum; j<=GrosimeDrum; ++j)  ///trasez drumul intre cele 2 puncte
                                line(CRed[i].xx1+j,CRed[i].yy1+j,CRed[i].xx2+j,CRed[i].yy2+j);

                            setcolor(COLOR(0,0,0));
                            outtextxy(180, 40, "Turn:RED");
                            setcolor(COLOR(0,70,255));
                            outtextxy(180, 40, "Turn:BLUE");
                            PlaySound(TEXT("MoveSound.wav"),NULL,SND_ASYNC);
                            if(checkForWin(-2,-1,dif)) /// functia ce apeleaza verificare daca playerul a castigat sau nu
                            {
                                done=1;
                                setcolor(COLOR(0,0,0));
                                outtextxy(180, 40, "Turn:BLUE");
                                setcolor((COLOR(255,0,0)));
                                outtextxy(180, 40, "Red Wins"); /// afisez textul de GameOver (CAstigatorul)
                                delay(2000);
                                setcolor((COLOR(0,0,0)));
                                outtextxy(180, 40, "Red Wins"); /// sterg textul de GameOver (CAstigatorul)
                                PlayAgain();
                            }

                        }
                    }
            }
            else if(turn==2 && SINGLEplayer==1)
                SinglePlayer();
            else if(x>=30 && x<=60 && y>=20 && y<=40)
            {
                done=0;
                turn=1;
                clearviewport();
                menu();
            }
            cout<<x<<' '<<y<<'\n';
            // if(x>500)
            //   done=1;
        }
    }
    while(!done);

}

void makeCopy()
{
    int i,j;
    for(i=1; i<=dif; ++i)
        for(j=1; j<=dif; ++j)
            Check[i][j]=mat[i][j];
}

int checkForWin(int value, int iFinal, int jFinal)
{
    int dc[]= {0,1,0,-1}; /// daca iFinal=-1 inseamna ca nu conteaza ce valoare are pe linie (deci e playerul rosu)
    int dl[]= {-1,0,1,0}; /// daca jFinal=-1 inseamna ca nu conteaza ce valoare are pe coloana (deci e playerul albastru)
    int newLine,newCol,k,ic=1,sc=dif/2; ///verificarea se face prin coada LEE
    mini=9999;
    while(ic<=sc)
    {
        X=Lee[ic++];
        for(k=0; k<4; ++k)
        {
            newLine=X.lin+dl[k];
            newCol=X.col+dc[k];
            if(Check[newLine][newCol]==value || (Check[newLine][newCol]>0 &&Check[newLine][newCol]>X.val+1))
            {
                Lee[++sc].lin=newLine;
                Lee[sc].col=newCol;
                Check[newLine][newCol]=X.val+1;
                if(newLine>=iFinal && newCol>=jFinal && Check[newLine][newCol]<mini)
                    mini=Check[newLine][newCol];
            }
        }
    }
    if(mini!=9999)
        return 1;
    return 0;
}
void menu()
{
    int x,y,i,j;
    int r=25;
    done=0;
    turn=1;
    setcolor(COLOR(0,70,255));
    circle(325,200, r);
    circlefill(325,200,r);
    setcolor(COLOR(255,0,0));
    circle(375,200, r);
    circlefill(375,200,r);
    setcolor(WHITE);
    settextstyle(10,0,6);
    outtextxy(290, 300, "Play");
    line(PlayButtonCoord1[0],PlayButtonCoord1[2],PlayButtonCoord1[1],PlayButtonCoord1[2]);
    line(PlayButtonCoord1[1],PlayButtonCoord1[2],PlayButtonCoord1[1],PlayButtonCoord1[3]);
    line(PlayButtonCoord1[1],PlayButtonCoord1[3],PlayButtonCoord1[0],PlayButtonCoord1[3]);
    line(PlayButtonCoord1[0],PlayButtonCoord1[3],PlayButtonCoord1[0],PlayButtonCoord1[2]);

    outtextxy(290, 400, "Help");
    line(HelpButtonCoord[0],HelpButtonCoord[2],HelpButtonCoord[1],HelpButtonCoord[2]);
    line(HelpButtonCoord[1],HelpButtonCoord[2],HelpButtonCoord[1],HelpButtonCoord[3]);
    line(HelpButtonCoord[1],HelpButtonCoord[3],HelpButtonCoord[0],HelpButtonCoord[3]);
    line(HelpButtonCoord[0],HelpButtonCoord[3],HelpButtonCoord[0],HelpButtonCoord[2]);

    outtextxy(290, 500, "Exit");
    line(ExitButtonCoord[0],ExitButtonCoord[2],ExitButtonCoord[1],ExitButtonCoord[2]);
    line(ExitButtonCoord[1],ExitButtonCoord[2],ExitButtonCoord[1],ExitButtonCoord[3]);
    line(ExitButtonCoord[1],ExitButtonCoord[3],ExitButtonCoord[0],ExitButtonCoord[3]);
    line(ExitButtonCoord[0],ExitButtonCoord[3],ExitButtonCoord[0],ExitButtonCoord[2]);
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN,x,y);
            if(x>=PlayButtonCoord1[0] && x<=PlayButtonCoord1[1] && y>=PlayButtonCoord1[2] && y<=PlayButtonCoord1[3])
                GameType();

            if(x>=HelpButtonCoord[0] && x<=HelpButtonCoord[1] && y>=HelpButtonCoord[2] && y<=HelpButtonCoord[3])
            {
                clearviewport();
                setcolor(10);
                settextstyle(10,0,6);
                outtextxy(200, 10, "Bridg-It");

                setcolor(WHITE);
                settextstyle(10,0,2);
                outtextxy(50, 100, "Bridg-It is a simple connection board game that was ");
                outtextxy(30, 120, "created around 1960 by a man named David Gale.");
                outtextxy(30, 140, "It is a two-player game and the board consists of two");
                outtextxy(30, 160, "rectangular arrays of dots, one array for each player.");
                outtextxy(30, 180, "The players move by alternately connecting two dots");
                outtextxy(30, 200, "within their array to form a line or bridge.");
                setcolor(10);
                circle(12,260, 7);
                settextstyle(10,0,4);
                outtextxy(30, 245, "Rules");
                settextstyle(10,0,2);
                circle(30,310,4);
                outtextxy(40, 300, "Players take turns connecting two adjacent dots of");
                outtextxy(30, 320, "their own color with a bridge.");
                circle(30,400,4);
                outtextxy(40, 390, "Adjacent dots are considered to be dots directly above,");
                outtextxy(30, 410, "below, to the right, or to the left of another dot with");
                outtextxy(30, 430, "the same color.");
                circle(30,510,4);
                outtextxy(40, 500, "A newly formed bridge cannot cross a bridge already");
                outtextxy(30, 520, "played and whoever connects their opposite");
                outtextxy(30, 540, "edges of the board first wins.");

                setcolor(WHITE);
                line(20,650,30, 640);
                line(20,650,30, 660);
                line(20,650,60, 650);

                do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN,x,y);
            if(x>=20 && x<=60 && y>=640 && y<=660)
            {
                clearviewport();
                menu();

            }

        }
    }
    while(1);

            }

            if(x>=ExitButtonCoord[0] && x<=ExitButtonCoord[1] && y>=ExitButtonCoord[2] && y<=ExitButtonCoord[3])
               {
                  exit(0);

               }
            cout<<x<<' '<<y<<'\n';
        }

    }
    while(1);
}
void BackButton()
{
    int x, y;
    setcolor(WHITE);
    line(30,30,40,20);
    line(30,30,40,40);
    line(30,30,60,30);

}
void GameType()
{
    int x, y;
    clearviewport();
    setcolor(WHITE);
    settextstyle(10,0,5);
    outtextxy(200, 205, "Singleplayer");
    line(SinglePlayerType[0],SinglePlayerType[2],SinglePlayerType[1],SinglePlayerType[2]);
    line(SinglePlayerType[1],SinglePlayerType[2],SinglePlayerType[1],SinglePlayerType[3]);
    line(SinglePlayerType[1],SinglePlayerType[3],SinglePlayerType[0],SinglePlayerType[3]);
    line(SinglePlayerType[0],SinglePlayerType[3],SinglePlayerType[0],SinglePlayerType[2]);

    setcolor(WHITE);
    settextstyle(10,0,5);
    outtextxy(213, 405, "Multiplayer");
    line(MultiplayerType[0],MultiplayerType[2],MultiplayerType[1],MultiplayerType[2]);
    line(MultiplayerType[1],MultiplayerType[2],MultiplayerType[1],MultiplayerType[3]);
    line(MultiplayerType[1],MultiplayerType[3],MultiplayerType[0],MultiplayerType[3]);
    line(MultiplayerType[0],MultiplayerType[3],MultiplayerType[0],MultiplayerType[2]);

    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN,x,y);
            if(x>=SinglePlayerType[0] && x<=SinglePlayerType[1] && y>=SinglePlayerType[2] && y<=SinglePlayerType[3])
            {
                clearviewport();
                SINGLEplayer=single;
                difficulties();

            }
            cout<<x<<' '<<y<<'\n';

            if(x>=MultiplayerType[0] && x<=MultiplayerType[1] && y>=MultiplayerType[2] && y<=MultiplayerType[3])
            {
                clearviewport();
                SINGLEplayer=multi;
                difficulties();
            }

        }
    }
    while(1);

}


void difficulties()
{
    int x,y;
    done=0;
    turn=1;
    clearviewport();
    setcolor(WHITE);
    settextstyle(10,0,6);
    outtextxy(287, 200, "Easy");
    line(EasyDiff[0],EasyDiff[2],EasyDiff[1],EasyDiff[2]);
    line(EasyDiff[1],EasyDiff[2],EasyDiff[1],EasyDiff[3]);
    line(EasyDiff[1],EasyDiff[3],EasyDiff[0],EasyDiff[3]);
    line(EasyDiff[0],EasyDiff[3],EasyDiff[0],EasyDiff[2]);

    outtextxy(260, 300, "Medium");
    line(MediumDiff[0],MediumDiff[2],MediumDiff[1],MediumDiff[2]);
    line(MediumDiff[1],MediumDiff[2],MediumDiff[1],MediumDiff[3]);
    line(MediumDiff[1],MediumDiff[3],MediumDiff[0],MediumDiff[3]);
    line(MediumDiff[0],MediumDiff[3],MediumDiff[0],MediumDiff[2]);

    outtextxy(287, 400, "Hard");
    line(HardDiff[0],HardDiff[2],HardDiff[1],HardDiff[2]);
    line(HardDiff[1],HardDiff[2],HardDiff[1],HardDiff[3]);
    line(HardDiff[1],HardDiff[3],HardDiff[0],HardDiff[3]);
    line(HardDiff[0],HardDiff[3],HardDiff[0],HardDiff[2]);
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN,x,y);
            if(x>=EasyDiff[0] && x<=EasyDiff[1] && y>=EasyDiff[2] && y<=EasyDiff[3])
            {
                clearviewport();
                dif=dif1;
                raza=25;
                GrosimeDrum=5;
                behindTheScenes();
                drawtable();
                // SINGLEplayer=1;
                GAME();

            }
            cout<<x<<' '<<y<<'\n';

            if(x>=MediumDiff[0] && x<=MediumDiff[1] && y>=MediumDiff[2] && y<=MediumDiff[3])
            {
                clearviewport();
                dif=dif2;
                raza=20;
                GrosimeDrum=4;

                behindTheScenes();
                drawtable();
                // SINGLEplayer=1;
                GAME();
            }

            if(x>=HardDiff[0] && x<=HardDiff[1] && y>=HardDiff[2] && y<=HardDiff[3])
            {
                clearviewport();
                dif=dif3;
                raza=16;
                GrosimeDrum=3;

                behindTheScenes();
                drawtable();
                //SINGLEplayer=1;
                GAME();
            }

        }
    }
    while(1);

}
void PlayAgain()
{
    int x,y,i,j;
    setcolor(WHITE);
    settextstyle(10,0,6);
    outtextxy(190, 40, "Play Again");
    line(PlayButtonCoord[0],PlayButtonCoord[2],PlayButtonCoord[1],PlayButtonCoord[2]);
    line(PlayButtonCoord[1],PlayButtonCoord[2],PlayButtonCoord[1],PlayButtonCoord[3]);
    line(PlayButtonCoord[1],PlayButtonCoord[3],PlayButtonCoord[0],PlayButtonCoord[3]);
    line(PlayButtonCoord[0],PlayButtonCoord[3],PlayButtonCoord[0],PlayButtonCoord[2]);

    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN,x,y);
            if(x>=PlayButtonCoord[0] && x<=PlayButtonCoord[1] && y>=PlayButtonCoord[2] && y<=PlayButtonCoord[3])
            {
                clearviewport();
                done=0;
                turn=1;
                for(i=1; i<=dif; ++i) /// fac o copie a matricei pentru a nu mai apela toata functia daca vreau sa joc dinou
                    for(j=1; j<=dif; ++j)
                        mat[i][j]=COPIE[i][j];
                drawtable();
                GAME();
            }
            else  if(x>=30 && x<=60 && y>=20 && y<=40)
            {

                clearviewport();
                menu();
            }
            cout<<x<<' '<<y<<'\n';
        }
    }
    while(1);
}
void CheckForLength(int value, int iFinal, int jFinal)
{
    int dc[]= {0,1,0,-1}; /// daca iFinal=-1 inseamna ca nu conteaza ce valoare are pe linie (deci e playerul rosu)
    int dl[]= {-1,0,1,0}; /// daca jFinal=-1 inseamna ca nu conteaza ce valoare are pe coloana (deci e playerul albastru)
    int newLine,newCol,k,ic=1,sc=dif/2; ///verificarea se face prin coada LEE
    mini=9999;
    while(ic<=sc)
    {
        X=Lee[ic++];
        for(k=0; k<4; ++k)
        {
            newLine=X.lin+dl[k];
            newCol=X.col+dc[k];
            if((newLine>=1 && newLine<=dif && newCol>=1 && newCol<=dif) && (Check[newLine][newCol]==value || Check[newLine][newCol]==0 || Check[newLine][newCol]>X.val+1)||(mat[newLine][newCol]==value && Check[newLine][newCol]>X.val))
            {
                Lee[++sc].lin=newLine;
                Lee[sc].col=newCol;

                if(mat[newLine][newCol]!=value)/// daca nu exista drum (este 0 in mat) se mareste lungimea drumului
                    Check[newLine][newCol]=X.val+1, Lee[sc].val=X.val+1;
                else /// daca exista deja drum consider ca lungimea drumului care trebuie completat nu mai creste
                    Check[newLine][newCol]=X.val, Lee[sc].val=X.val;
                if(newLine>=iFinal && newCol>=jFinal && Check[newLine][newCol]<mini)
                    mini=Check[newLine][newCol];
            }
        }
    }
}
void SinglePlayer()
{
///Note
///fac un bkt pentru a pune pe rand in fiecare spatiu liber un drum
/// fac pentru fiecare astfel de miscare un CheckForWin pentru a vedea cand se lungeste cel mai tare drumul playerului care incepe(Albastru)
/// daca am situatii in care lungimea drumului ramane constanta sau situatii multiple cu aceasi lungime
/// aleg ca muture drumul care imi scurteaza cel mai mult distanta calculatorului ( fac CheckForWin si pentru calculator - Rosu )
    int i,min1,min2,i_value,j_value,i_value2,j_value2,indice,j,x;
    int InitialPlayerLength,InitialComputerLength=99;

    for(i=1; i<=ct2; ++i)
    {
        i_value=0;
        j_value=0;
        if(CRed[i].i1<CRed[i].i2) ///caut pozitia dintre cele 2 puncte
            i_value=1;
        if(CRed[i].j1<CRed[i].j2)
            j_value=1;
        if(mat[CRed[i].i2-i_value][CRed[i].j2-j_value]==0)  ///ma uit daca a fost trasat un drum intre cele 2 puncte
        {
            ///verificand daca spatiul dintre ele este liber sau nu
            mat[CRed[i].i2-i_value][CRed[i].j2-j_value]=-2; /// setez drumul

            makeCopy();  ///verific lungimea calculatorului
            for(int index=1; index<=dif/2; ++index)
                Lee[index].col=1, Lee[index].lin=2*index, Check[2*index][1]=1, Lee[index].val=1;
            CheckForLength(-2,-1,dif);
            min1=mini; ///valoarea trebuie sa fie cat mai mica

            makeCopy(); /// verific lungimea playerlui
            for(int index=1; index<=dif/2; ++index)
                Lee[index].lin=1, Lee[index].col=2*index, Check[1][2*index]=1, Lee[index].val=1;
            CheckForLength(-1,dif,-1);
            min2=mini; ///valoarea trebuie sa fie cat mai mare

            srand((unsigned)time(0));
            x=rand()%2;
            if(min2>InitialPlayerLength)
                InitialPlayerLength=min2, InitialComputerLength=min1, indice=i, i_value2=i_value, j_value2=j_value;
            else if(min2==InitialPlayerLength && min1<InitialComputerLength)
                InitialPlayerLength=min2, InitialComputerLength=min1, indice=i, i_value2=i_value, j_value2=j_value;
            else if(min2==InitialPlayerLength && min1==InitialComputerLength && x==1)
                InitialPlayerLength=min2, InitialComputerLength=min1, indice=i, i_value2=i_value, j_value2=j_value;

            mat[CRed[i].i2-i_value][CRed[i].j2-j_value]=0; ///sterg drumul
        }
    }
    mat[CRed[indice].i2-i_value2][CRed[indice].j2-j_value2]=-2;
    setcolor(COLOR(255,0,0));
    for(j=-5; j<=5; ++j)  ///trasez drumul intre cele 2 puncte
        line(CRed[indice].xx1+j,CRed[indice].yy1+j,CRed[indice].xx2+j,CRed[indice].yy2+j);
    turn=1;

    makeCopy(); /// fac copia matricei si incep verificare de terminare a jocul
    for(int index=1; index<=dif/2; ++index)
        Lee[index].col=1, Lee[index].lin=2*index, Check[2*index][1]=1, Lee[index].val=1;
    if(checkForWin(-2,-1,dif)) /// functia ce apeleaza verificare daca playerul a castigat sau nu
    {
        done=1;
        setcolor(COLOR(0,0,0));
        outtextxy(180, 40, "Turn:BLUE");
        setcolor((COLOR(255,0,0)));
        outtextxy(180, 40, "Red Wins"); /// afisez textul de GameOver (CAstigatorul)
        delay(2000);
        setcolor((COLOR(0,0,0)));
        outtextxy(180, 40, "Red Wins"); /// sterg textul de GameOver (CAstigatorul)
        PlayAgain();
    }

}
