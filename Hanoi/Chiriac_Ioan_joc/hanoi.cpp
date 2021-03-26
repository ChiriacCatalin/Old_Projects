#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>

using namespace std;

struct automat
{
    sf::RectangleShape autom[10];
    int vf;
} S[5];
void Hanoi(int m, int a, int b, int c);
void muta(int a, int c);
void positie();

void wait()
{
    sf::Time time;
    sf::Clock clock;
    time=clock.restart();
    while(time.asSeconds()<1)
        time=clock.getElapsedTime();
}

sf::RenderWindow Window;
sf::Texture faceplayTexture;
sf::Sprite faceplaySprite;

int main()
{
    Window.create(sf::VideoMode(800,600),"Turnurile din 10 A",sf::Style::Close | sf::Style::Titlebar);
    Window.setKeyRepeatEnabled(false);
    int meniu=1,tip=1,piese=0,i,scor[10],cnt2=0,muzica=0;
    sf::Music music[5];
    if(!music[0].openFromFile("Secret.ogg"))
        std::cout<<"Could not load music"<<'\n';
    if(!music[1].openFromFile("Beethoven.ogg"))
        std::cout<<"Could not load music"<<'\n';
    if(!music[2].openFromFile("Mozart.ogg"))
        std::cout<<"Could not load music"<<'\n';
    if(!music[3].openFromFile("Yiruma.ogg"))
        std::cout<<"Could not load music"<<'\n';
    music[muzica].setLoop(true);
    music[muzica].play();
    sf::Font font;
    if(!font.loadFromFile("ALGER.ttf"))
        std::cout<<"Could not load the font"<<'\n';
    sf::String Mod[3],v[10],endgame,muzic;
    muzic="Music";
    endgame="Felicitari ! Ai terminat jocul cu un scor de ";
    sf::Text text[3], vtext[10],tendgame(endgame,font,30),tmuzic(muzic,font,15);
    v[0]="1",  v[1]="2",  v[2]="3",  v[3]="4",  v[4]="5",  v[5]="6",  v[6]="7",  v[7]="8";
    tendgame.setColor(sf::Color::Red);
    tendgame.setPosition(30,55);
    tmuzic.setColor(sf::Color::Red);
    tmuzic.setPosition(730,7);
    for(i=0; i<=7; ++i)
    {
        vtext[i].setString(v[i]);
        vtext[i].setFont(font);
        vtext[i].setColor(sf::Color::Red);
        vtext[i].setCharacterSize(40);
        vtext[i].setPosition(480,210);
    }
    Mod[0]="Turnuri:";
    Mod[1]="Automat";
    Mod[2]="Manual";
    text[1].setString(Mod[1]);
    text[2].setString(Mod[2]);
    text[0].setString(Mod[0]);
    text[1].setFont(font);
    text[2].setFont(font);
    text[0].setFont(font);
    text[1].setCharacterSize(40);
    text[2].setCharacterSize(40);
    text[0].setCharacterSize(40);
    text[1].setColor(sf::Color::Red);
    text[2].setColor(sf::Color::Red);
    text[0].setColor(sf::Color::Red);
    text[1].setPosition(290,320);
    text[2].setPosition(305,320);
    text[0].setPosition(290,210);

    sf::Texture bTexture,playTexture,helpTexture,exitTexture,hTexture,backTexture,playsetTexture,back2Texture;
    sf::Sprite backImage,playbutton,helpbutton,exitbutton,htext,backbutton,playsetImage,back2button;
    sf::Texture back3Texture,back4Texture,back5Texture,back6Texture;
    sf::Sprite back3button,back4button,back5button,back6button;
    if(!bTexture.loadFromFile("7.png"))
        std::cout<<"Could not load BACKGROUND.PNG"<<'\n';
    if(!playTexture.loadFromFile("play2.png"))
        std::cout<<"Could not load play.png"<<'\n';
    if(!helpTexture.loadFromFile("help2.png"))
        std::cout<<"Could not load play.png"<<'\n';
    if(!exitTexture.loadFromFile("exit2.png"))
        std::cout<<"Could not load play.png"<<'\n';
    if(!hTexture.loadFromFile("htext.png"))
        std::cout<<"Could not load htext.png"<<'\n';
    if(!backTexture.loadFromFile("back.png"))
        std::cout<<"Could not load back.png"<<'\n';
    if(!back2Texture.loadFromFile("back.png"))
        std::cout<<"Could not load back.png"<<'\n';
    if(!playsetTexture.loadFromFile("playset.png"))
        std::cout<<"Could not load back.png"<<'\n';
    if(!back3Texture.loadFromFile("back.png"))
        std::cout<<"Could not load back3.png"<<'\n';
    if(!back4Texture.loadFromFile("back.png"))
        std::cout<<"Could not load back4.png"<<'\n';
    if(!back5Texture.loadFromFile("back.png"))
        std::cout<<"Could not load back5.png"<<'\n';
    if(!back6Texture.loadFromFile("back.png"))
        std::cout<<"Could not load back6.png"<<'\n';
    if(!faceplayTexture.loadFromFile("faceplay.png"))
        std::cout<<"Could not load faceplay.png"<<'\n';
    backImage.setTexture(bTexture);
    backImage.setScale(1,1);
    backImage.setColor(sf::Color(255,255,255,255));
    playbutton.setTexture(playTexture);
    playbutton.setPosition(330,220);
    helpbutton.setTexture(helpTexture);
    helpbutton.setPosition(330,290);
    exitbutton.setTexture(exitTexture);
    exitbutton.setPosition(330,360);
    htext.setTexture(hTexture);
    backbutton.setTexture(backTexture);
    playsetImage.setTexture(playsetTexture);
    back2button.setTexture(back2Texture);
    back3button.setTexture(back3Texture);
    back4button.setTexture(back4Texture);
    back5button.setTexture(back5Texture);
    back6button.setTexture(back6Texture);
    faceplaySprite.setTexture(faceplayTexture);
/// date pentru joc / vector de dreptunghiuri
    sf::RectangleShape t1[10];
    sf::RectangleShape t2[10];
    sf::RectangleShape t3[10];
    int red, green, blue; ///setez random colurile pentru piese
    red=rand()%255;
    green=rand()%255;
    blue=rand()%255;
    t1[1].setSize(sf::Vector2f(190,35)); ///setez prima piesa la baza primului turn
    t1[1].setFillColor(sf::Color(red,green,blue));
    t1[1].setPosition(43,474);
    ///pentru mod automat
    S[1].autom[1].setSize(sf::Vector2f(190,35));
    S[1].autom[1].setFillColor(sf::Color(red,green,blue));
    S[1].autom[1].setPosition(43,474);
    for(i=2; i<=8; ++i)
    {
        sf::Vector2f size1;
        sf::Vector2f posit;
        size1=t1[i-1].getSize(); ///setez marimea
        posit=t1[i-1].getPosition();///si positia
        t1[i].setSize(sf::Vector2f(size1.x-20,35)); /// in functie de piesa de la baza
        red=rand()%255;
        green=rand()%255;
        blue=rand()%255;
        t1[i].setFillColor(sf::Color(red,green,blue));
        t1[i].setPosition(posit.x+10,posit.y-35);
        S[1].autom[i].setSize(sf::Vector2f(size1.x-20,35));
        S[1].autom[i].setFillColor(sf::Color(red,green,blue));
        S[1].autom[i].setPosition(posit.x+10,posit.y-35);
    }
///
    int vf1=1, vf2=0, vf3=0,da,nu=0,mutari=0,minim=1,ok=0;;
    while(Window.isOpen())
    {
        sf::Event Event;
        while(Window.pollEvent(Event))
        {
            switch(Event.type)
            {
            case sf::Event::Closed:
                Window.close();
                break;
            case sf::Event::MouseButtonReleased:
            {
                if(Event.mouseButton.button==sf::Mouse::Right) ///cand apas click 2
                    std::cout<<"X:"<<Event.mouseButton.x<<"Y:"<<Event.mouseButton.y<<'\n'; ///afisez coordonatele la care este cursorul
                else if(Event.mouseButton.button==sf::Mouse::Left)
                {
                    if(Event.mouseButton.x>=330 && Event.mouseButton.x<=480 && Event.mouseButton.y>=220 && Event.mouseButton.y<=273 && meniu==1) ///aps butonul play
                        meniu=2;
                    else if(Event.mouseButton.x>=330 && Event.mouseButton.x<=480 && Event.mouseButton.y>=290 && Event.mouseButton.y<=343 && meniu==1) ///aps butonul help
                        meniu=3;
                    else if(Event.mouseButton.x>=330 && Event.mouseButton.x<=480 && Event.mouseButton.y>=360 && Event.mouseButton.y<=413 && meniu==1) ///aps butonul exit
                        Window.close();
                    if(meniu==2) ///setarile pentru joc
                    {
                        if(Event.mouseButton.x>=544 && Event.mouseButton.x<=581 && Event.mouseButton.y>=326 && Event.mouseButton.y<=361)///modul automat/manual
                            tip=3-tip;
                        if(Event.mouseButton.x>=544 && Event.mouseButton.x<=581 && Event.mouseButton.y>=216 && Event.mouseButton.y<=250)///numarul de piese
                            piese++, vf1++;
                        if(piese==8) piese=0;
                        if(vf1==9) vf1=1;
                    }
                    else if(Event.mouseButton.x>=782 && Event.mouseButton.x<=795 && Event.mouseButton.y>=10 && Event.mouseButton.y<=23 && meniu==4)
                        music[muzica].stop(), muzica=(muzica+1)%5, music[muzica].play(), music[muzica].setLoop(true);
                }
            }
            break;
            case sf::Event::MouseMoved: ///miscarea butoanelor de play/help/exit din meniu
            {
                if(Event.mouseMove.x>=330 && Event.mouseMove.x<=480 && Event.mouseMove.y>=220 && Event.mouseMove.y<=273)
                    playbutton.setPosition(335,210), Window.draw(playbutton);
                else if(Event.mouseMove.x>=330 && Event.mouseMove.x<=480 && Event.mouseMove.y>=290 && Event.mouseMove.y<=343)
                    helpbutton.setPosition(335,280), Window.draw(helpbutton);
                else if(Event.mouseMove.x>=330 && Event.mouseMove.x<=480 && Event.mouseMove.y>=360 && Event.mouseMove.y<=413)
                    exitbutton.setPosition(335,350), Window.draw(exitbutton);
                else
                    playbutton.setPosition(330,220), helpbutton.setPosition(330,290), exitbutton.setPosition(330,360);
            }
            break;
            }
        }
        if(meniu==1) ///imaginea meniului
        {
            Window.clear();
            Window.draw(backImage);
            Window.draw(helpbutton);
            Window.draw(exitbutton);
            Window.draw(playbutton);
            Window.display();
        }
        if(meniu==2) ///setarile pentru joc
        {
            Window.clear();
            Window.draw(playsetImage);
            back2button.setScale(0.2f,0.2f);
            back2button.setRotation(180); /// butonul de "Continue" - dute la joc
            back2button.setPosition(800,599);
            Window.draw(back2button);

            backbutton.setScale(0.2f,0.2f);///butonul de "Back"- mergi inapoi la meniu
            backbutton.setPosition(0,547);
            Window.draw(backbutton);

///
            Window.draw(vtext[piese]);
            Window.draw(text[tip]);
            Window.draw(text[0]);
            back3button.setScale(0.2f,0.2f); ///butonul de switch automat/manual
            back3button.setRotation(180);
            back3button.setPosition(590,370);
            back4button.setScale(0.2f,0.2f);
            back4button.setRotation(180);
            back4button.setPosition(590,260); ///butonul pentru modific numarul de piese
            Window.draw(back3button);
            Window.draw(back4button);

///
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i mousePosition=sf::Mouse::getPosition(Window);
                if(mousePosition.x>=1 && mousePosition.x<=46 && mousePosition.y>=555 && mousePosition.y<=596) ///daca apas butonul de back pt meniu
                    meniu=1;
                if(mousePosition.x>=755 && mousePosition.x<=793 && mousePosition.y>=553 && mousePosition.y<=591)///daca apas butonul "continue" pentru joc
                {
                    if(tip==2)
                        meniu=4;
                    else if(tip==1)
                        meniu=5;
                }
            }
            Window.display();
        }
        if(meniu==4 || meniu==5) ///jocul propriu-zis
        {
            Window.clear();
            Window.draw(faceplaySprite);
            if(meniu==5 && ok==0)
            {
                S[1].vf=vf1;
                Window.clear();
                Window.draw(faceplaySprite);
                Window.draw(faceplaySprite);
                for(i=1; i<=S[1].vf; ++i) ///desenez rectangle-urile de pe primul turn
                    Window.draw(S[1].autom[i]);
                for(i=1; i<=S[2].vf; ++i)///desenez rectangle-urile de pe al doilea turn
                    Window.draw(S[2].autom[i]);
                for(i=1; i<=S[3].vf; ++i)///desenez rectangle-urile de pe al treilea turn
                    Window.draw(S[3].autom[i]);
                Window.display();
                wait();

                Hanoi(vf1,1,2,3);
                ok=1;
            }
            if(meniu==5)
            {
                for(i=1; i<=S[1].vf; ++i) ///desenez rectangle-urile de pe primul turn
                    Window.draw(S[1].autom[i]);
                for(i=1; i<=S[2].vf; ++i)///desenez rectangle-urile de pe al doilea turn
                    Window.draw(S[2].autom[i]);
                for(i=1; i<=S[3].vf; ++i)///desenez rectangle-urile de pe al treilea turn
                    Window.draw(S[3].autom[i]);
            }
            if(meniu==4)
            {
                Window.draw(tmuzic);
                back5button.setScale(0.08f,0.08f);
                back5button.setRotation(180);
                back5button.setPosition(800,27);
                Window.draw(back5button);
                sf::Vector2f size1,size2,size3; ///positiile  pieselor din varful turnurilor
                sf::Vector2f posit,posit2,posit3;
                size1=t1[vf1].getSize();
                posit=t1[vf1].getPosition();

                size2=t2[vf2].getSize();
                posit2=t2[vf2].getPosition();

                size3=t3[vf3].getSize();
                posit3=t3[vf3].getPosition(); ///pana aici iau pozitiile varfurilor
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))  ///miscarea pe turnuri
                {
                    sf::Vector2i mousePosition=sf::Mouse::getPosition(Window);
                    if(mousePosition.x>=posit.x && mousePosition.x<=posit.x+size1.x && mousePosition.y>=posit.y && mousePosition.y<=posit.y+size1.y)/// iau o piesa de pe turnul1
                        da=1;
                    if(mousePosition.x>=posit2.x && mousePosition.x<=posit2.x+size2.x && mousePosition.y>=posit2.y && mousePosition.y<=posit2.y+size2.y)/// de pe turnul2
                        da=2;
                    if(mousePosition.x>=posit3.x && mousePosition.x<=posit3.x+size3.x && mousePosition.y>=posit3.y && mousePosition.y<=posit3.y+size3.y)/// de pe turnul3
                        da=3;
                }
                if(da==1)/// de pe turnul1 pe turnul2 sau turnul3
                {
                    sf::Vector2i mousePosition=sf::Mouse::getPosition(Window);
                    t1[vf1].setPosition(mousePosition.x,mousePosition.y);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        if(mousePosition.x<=400-size1.x/3 && mousePosition.x+size1.x>=410 && mousePosition.y>=150 && mousePosition.y<=480 && (vf2==0 || size2.x>size1.x) && da==1)
                            vf1--, vf2++, da=0, t2[vf2]=t1[vf1+1], t2[vf2].setPosition(393-size1.x/2,510-vf2*35), mutari++;///verific daca piesa poate fi pusa pe turnul 2
                        else if(mousePosition.x<=667-size1.x/3 && mousePosition.x+size1.x>=677 && mousePosition.y>=150 && mousePosition.y<=480 && (vf3==0 || size3.x>size1.x) && da==1)
                            vf1--, vf3++, da=0, t3[vf3]=t1[vf1+1], t3[vf3].setPosition(665-size1.x/2,510-vf3*35), mutari++;///verific daca piesa poate fi pusa pe turnul 3
                        else if(mousePosition.x<=139-size1.x/3 && mousePosition.x+size1.x>=150 && mousePosition.y>=150 && mousePosition.y<=480)
                            da=0, nu=0, t1[vf1].setPosition(138-size1.x/2,510-vf1*35);///verific daca piesa poate fi pusa pe turnul 1
                    }
                }
                else if(da==2)/// de pe turnul2 pe turnul1 sau turnul3
                {
                    sf::Vector2i mousePosition=sf::Mouse::getPosition(Window);
                    t2[vf2].setPosition(mousePosition.x,mousePosition.y);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        if(mousePosition.x<=667-size2.x/3 && mousePosition.x+size2.x>=677 && mousePosition.y>=150 && mousePosition.y<=480 && (vf3==0 || size3.x>size2.x) && da==2)
                            vf2--, vf3++, da=0, t3[vf3]=t2[vf2+1], t3[vf3].setPosition(665-size2.x/2,510-vf3*35), mutari++;///verific daca piesa poate fi pusa pe turnul 3
                        else if(mousePosition.x<=139-size2.x/3 && mousePosition.x+size2.x>=150 && mousePosition.y>=150 && mousePosition.y<=480 && (vf1==0 || size1.x>size2.x) && da==2)
                            vf2--, vf1++, da=0, t1[vf1]=t2[vf2+1], t1[vf1].setPosition(138-size2.x/2,510-vf1*35), mutari++;///verific daca piesa poate fi pusa pe turnul 1
                        else if(mousePosition.x<=400-size2.x/3 && mousePosition.x+size2.x>=410 && mousePosition.y>=150 && mousePosition.y<=480)
                            da=0, nu=0, t2[vf2].setPosition(393-size2.x/2,510-vf2*35);///verific daca piesa poate fi pusa pe turnul 2
                    }
                }
                else if(da==3)/// de pe turnul3 pe turnul1 sau turnul2
                {
                    sf::Vector2i mousePosition=sf::Mouse::getPosition(Window);
                    t3[vf3].setPosition(mousePosition.x,mousePosition.y);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        if(mousePosition.x<=139-size3.x/3 && mousePosition.x+size3.x>=150 && mousePosition.y>=150 && mousePosition.y<=480 && (vf1==0 || size1.x>size3.x) && da==3)
                            vf3--, vf1++, da=0, t1[vf1]=t3[vf3+1], t1[vf1].setPosition(138-size3.x/2,510-vf1*35), mutari++;///verific daca piesa poate fi pusa pe turnul 1
                        else if(mousePosition.x<=400-size3.x/3 && mousePosition.x+size3.x>=410 && mousePosition.y>=150 && mousePosition.y<=480 && (vf2==0 || size2.x>size3.x) && da==3)
                            vf3--, vf2++, da=0, t2[vf2]=t3[vf3+1], t2[vf2].setPosition(393-size3.x/2,510-vf2*35), mutari++;///verific daca piesa poate fi pusa pe turnul 2
                        else if(mousePosition.x<=667-size3.x/3 && mousePosition.x+size3.x>=677 && mousePosition.y>=150 && mousePosition.y<=480)
                            da=0, nu=0, t3[vf3].setPosition(665-size3.x/2,510-vf3*35);///verific daca piesa poate fi pusa pe turnul 3
                    }
                }

                for(i=1; i<=vf1; ++i) ///desenez rectangle-urile de pe primul turn
                    Window.draw(t1[i]);
                for(i=1; i<=vf2; ++i)///desenez rectangle-urile de pe al doilea turn
                    Window.draw(t2[i]);
                for(i=1; i<=vf3; ++i)///desenez rectangle-urile de pe al treilea turn
                    Window.draw(t3[i]);
                if((vf2==piese+1 || vf3==piese+1) && ok==0) ///daca am terminat calculez scorul
                {
                    ok=1;
                    for(i=0; i<=piese; ++i)
                        minim*=2;
                    minim--;
                    minim=minim*100/mutari;
                    if(minim==0)
                        scor[++cnt2]=0;
                    else
                        while(minim)
                            scor[++cnt2]=minim%10, minim/=10;
                    for(i=cnt2; i>=1; --i)
                        endgame+=(char)(scor[i]+'0');
                    endgame+='%';
                    tendgame.setString(endgame);
                }
            }
            if(ok==1) ///afisez scorul
            {
                if(meniu==4)
                    Window.draw(tendgame);
                Window.draw(backbutton); ///butonul de Back-mergi inapoi la meniu
                backbutton.setScale(0.2f,0.2f);///dupa terminarea jocului creez butonul de back
                backbutton.setPosition(0,547);
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) ///apas butonul de Back-mergi inapoi la meniu
                {
                    sf::Vector2i mousePosition=sf::Mouse::getPosition(Window);
                    if(mousePosition.x>=1 && mousePosition.x<=46 && mousePosition.y>=555 && mousePosition.y<=596) ///resetez toate datele
                    {
                        if(meniu==4)
                            endgame.erase(endgame.getSize()-1,endgame.getSize());
                        for(i=cnt2; i>0; --i)
                            endgame.erase(endgame.getSize()-1,endgame.getSize());
                        meniu=1, vf1=piese+1, vf2=0, vf3=0, ok=0, minim=1, mutari=0, cnt2=0;

                        S[1].vf=0, S[2].vf=0, S[3].vf=0;
                        red=rand()%255;
                        green=rand()%255;
                        blue=rand()%255;
                        t1[1].setSize(sf::Vector2f(190,35));
                        t1[1].setFillColor(sf::Color(red,green,blue));
                        t1[1].setPosition(43,474);
                        t3[1].setSize(sf::Vector2f(0,0));
                        t2[1].setSize(sf::Vector2f(0,0));
                        t3[1].setFillColor(sf::Color(0,0,0));
                        t2[1].setFillColor(sf::Color(0,0,0));
                        S[1].autom[1].setSize(sf::Vector2f(190,35));
                        S[1].autom[1].setFillColor(sf::Color(red,green,blue));
                        S[1].autom[1].setPosition(43,474);
                        for(i=2; i<=8; ++i)
                        {
                            sf::Vector2f size1;
                            sf::Vector2f posit;
                            size1=t1[i-1].getSize();
                            posit=t1[i-1].getPosition();
                            t1[i].setSize(sf::Vector2f(size1.x-20,35));
                            t2[i].setSize(sf::Vector2f(0,0));
                            t3[i].setSize(sf::Vector2f(0,0));
                            red=rand()%255;
                            green=rand()%255;
                            blue=rand()%255;
                            t1[i].setFillColor(sf::Color(red,green,blue));
                            t2[i].setFillColor(sf::Color(0,0,0));
                            t3[i].setFillColor(sf::Color(0,0,0));
                            t1[i].setPosition(posit.x+10,posit.y-35);
                            S[1].autom[i].setSize(sf::Vector2f(size1.x-20,35));
                            S[1].autom[i].setFillColor(sf::Color(red,green,blue));
                            S[1].autom[i].setPosition(posit.x+10,posit.y-35);
                            S[2].autom[i].setSize(sf::Vector2f(0,0));
                            S[2].autom[i].setFillColor(sf::Color(0,0,0));
                            S[3].autom[i].setSize(sf::Vector2f(0,0));
                            S[3].autom[i].setFillColor(sf::Color(0,0,0));
                        }
                    }
                }
            }

            Window.display();
        }
/// sfrasitul codului pt joc

        if(meniu==3) ///helpul
        {
            Window.clear();
            Window.draw(htext);
            Window.draw(backbutton); ///butonul de Back-mergi inapoi la meniu
            backbutton.setScale(0.2f,0.2f);
            backbutton.setPosition(0,547);
            Window.display();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) ///apas butonul de Back-mergi inapoi la meniu
            {
                sf::Vector2i mousePosition=sf::Mouse::getPosition(Window);
                if(mousePosition.x>=1 && mousePosition.x<=46 && mousePosition.y>=555 && mousePosition.y<=596)
                    meniu=1;
            }
        }
    }

    return 0;
}

void muta(int a, int c)
{

    int i;
    sf::Vector2f size1[4];
    size1[a]=S[a].autom[S[a].vf].getSize();

    S[a].vf--;
    S[c].vf++;
    S[c].autom[S[c].vf]=S[a].autom[S[a].vf+1];
    if(c==3)
        S[c].autom[S[c].vf].setPosition(665-size1[a].x/2,510-S[c].vf*35);
    else if(c==2)
        S[c].autom[S[c].vf].setPosition(393-size1[a].x/2,510-S[c].vf*35);
    else if(c==1)
        S[c].autom[S[c].vf].setPosition(138-size1[a].x/2,510-S[c].vf*35);
    Window.clear();
    Window.draw(faceplaySprite);
    for(i=1; i<=S[1].vf; ++i) ///desenez rectangle-urile de pe primul turn
        Window.draw(S[1].autom[i]);
    for(i=1; i<=S[2].vf; ++i)///desenez rectangle-urile de pe al doilea turn
        Window.draw(S[2].autom[i]);
    for(i=1; i<=S[3].vf; ++i)///desenez rectangle-urile de pe al treilea turn
        Window.draw(S[3].autom[i]);
    Window.display();
    wait();


}
void Hanoi(int m, int a, int b, int c)
{
    if(m==1)
        muta(a,c);
    else
    {
        Hanoi(m-1, a,c,b);
        muta(a,c);
        Hanoi(m-1,b,a,c);
    }
}
