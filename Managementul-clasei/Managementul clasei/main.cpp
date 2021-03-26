#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Clasa.h"
#include "Button.h"
#include <fstream>
#include <sstream>
#include <cstring>
void initializare_icon(sf::RenderWindow &window);
Button creare_buton(std::string path, float x, float y,float x_dim, float y_dim,bool se_poate_desena);
Button creare_icons(std::string path, float x, float y,float x_dim, float y_dim,bool se_poate_desena);
Button creare_text(std::string path, float x, float y,float x_dim, float y_dim,bool se_poate_desena);
int parcurgere(sf::String S);
void deseneaza_butoane(sf::RenderWindow &window);
void deseneaza_text(sf::RenderWindow &window);
void deseneaza_icons(sf::RenderWindow &window);
void parcurgere_clase();
void deseneaza_clase();
int parcurgere(sf::String S);
std::vector <Button> butoane;
std::vector <Button> text_elements;
std::vector <Clasa> clase;
sf::String nume_s,nr_s,nume_clasa_vizualizare_s,gen_s[2],nume_elev_s,prenume_elev_s,varsta_s;
sf::Text nume_t,nr_t,nume_clasa_vizualizare_t,gen_t[2],nume_elev_t,prenume_elev_t,varsta_t;
sf::Font font;
sf::Texture warning_t,elev_info_t,warning2_t,warning3_t;
sf::RectangleShape warning_shape,elev_info_shape,warning2_shape,warning3_shape;
bool draw_warning3=false;
bool draw_title=true;
bool wait_for_text=false;
bool notPressed=false;
bool draw_warning=false;
bool draw_warning2=false;
bool draw_elev_info=false;
bool button_covered=false;
float frameCount, frameSpeed=500;
sf::Clock clock1;
sf::Color change[2];
short int ind;
int ind_clasa=0,ind_gen=0,ind_elev;
int kk, nr_clase;
std::ifstream F("numar_clase.txt");
std::ofstream O("numar_clase_temp.txt");
std::ofstream fout;
std::vector <Button> icons;
std::ifstream fin("clase_info.txt");
int main()
{
    fout.open("clase_info.txt", std::ofstream::app);
    parcurgere_clase();
    change[0]=sf::Color(192,192,192);
    change[1]=sf::Color::White;
    sf::RenderWindow window(sf::VideoMode(800,800), "Managementul clasei", sf::Style::Close);
    initializare_icon(window);
    font.loadFromFile("FONTURI/Ridgeline201-Regular.otf");
    gen_s[0]="MASCULIN";
    gen_t[0].setString(gen_s[0]);
    gen_t[0].setFont(font);
    gen_t[0].setCharacterSize(20);
    gen_t[0].setPosition(376-gen_t[0].getLocalBounds().width/2+9,465);
    gen_s[1]="FEMININ";
    gen_t[1].setString(gen_s[1]);
    gen_t[1].setFont(font);
    gen_t[1].setCharacterSize(20);
    gen_t[1].setPosition(376-gen_t[1].getLocalBounds().width/2+9,465);
    warning_t.loadFromFile("POZE/warning.png");
    warning2_t.loadFromFile("POZE/warning2.png");
    warning2_shape.setTexture(&warning2_t);
    warning2_shape.setSize(sf::Vector2f(365,38));
    warning2_shape.setPosition(window.getSize().x/2-warning2_shape.getLocalBounds().width/2,100);
    warning3_t.loadFromFile("POZE/warning3.png");
    warning3_shape.setTexture(&warning3_t);
    warning3_shape.setSize(sf::Vector2f(365,38));
    warning3_shape.setPosition(window.getSize().x/2-warning3_shape.getLocalBounds().width/2,100);
    elev_info_t.loadFromFile("POZE/elev_info.png");
    elev_info_shape.setTexture(&elev_info_t);
    elev_info_shape.setSize(sf::Vector2f(506,356));
    elev_info_shape.setPosition(window.getSize().x/2-elev_info_shape.getLocalBounds().width/2,window.getSize().y/2-elev_info_shape.getLocalBounds().height/2);
    warning_shape.setTexture(&warning_t);
    warning_shape.setSize(sf::Vector2f(365,38));
    warning_shape.setPosition(window.getSize().x/2-warning_shape.getLocalBounds().width/2,200);
    nume_clasa_vizualizare_t.setFont(font);
    nume_clasa_vizualizare_t.setCharacterSize(20);
    nume_elev_t.setFont(font);
    nume_elev_t.setCharacterSize(15);
    prenume_elev_t.setFont(font);
    prenume_elev_t.setCharacterSize(15);
    varsta_t.setFont(font);
    varsta_t.setCharacterSize(20);
    nume_t.setFont(font);
    nr_t.setFont(font);
    nume_t.setCharacterSize(20);
    nr_t.setCharacterSize(20);
    nume_t.setPosition(280,205);
    nr_t.setPosition(280,305);
    sf::Texture titlu_t;
    titlu_t.loadFromFile("POZE/titlu.png");
    sf::Sprite titlu_s;
    titlu_s.setTexture(titlu_t);
    titlu_s.setPosition(window.getSize().x/2-titlu_s.getLocalBounds().width/2,100);
    sf::Texture fundal_t,fundal_view_t;
    fundal_t.loadFromFile("POZE/fundal.jpg");
    fundal_view_t.loadFromFile("POZE/clasa3.jpg");
    sf::Sprite fundal_s;
    fundal_s.setTexture(fundal_t);
    Button b=creare_buton("POZE/add_button.png",240,350,235,158,true); /// 0
    sf::Vector2f poz=b.getPosition();
    Button a=creare_buton("POZE/view_button.png",300,400,158,270,true);/// 1
    a.setPosition(poz.x+a.getForma().getLocalBounds().width+5,poz.y+22);
    butoane[butoane.size()-1]=a;
    Button c=creare_buton("POZE/exit_button.png",300,400,237,162,true);/// 2
    c.setPosition(poz.x,poz.y+c.getForma().getLocalBounds().height-5);
    butoane[butoane.size()-1]=c;
    Button d=creare_buton("POZE/add_button_info.png",100,100,100,29,false);/// 3
    Button e=creare_buton("POZE/view_button_info.png",100,100,100,29,false);/// 4
    Button f=creare_buton("POZE/exit_button_info.png",100,100,100,29,false);/// 5
    Button h=creare_buton("POZE/return_button.png",10,10,50,93,false);/// 6
    Button i=creare_buton("POZE/enter_button.png",10,10,259,36,false);/// 7
    i.setPosition(window.getSize().x/2-i.getForma().getGlobalBounds().width/2,200);
    butoane[butoane.size()-1]=i;
    Button j=creare_buton("POZE/enter_button.png",10,30,259,36,false); /// 8
    j.setPosition(window.getSize().x/2-j.getForma().getGlobalBounds().width/2,300);
    butoane[butoane.size()-1]=j;
    Button k=creare_buton("POZE/creeaza_clasa_button.png",300,500,232,73,false); /// 9
    k.setPosition(window.getSize().x/2-k.getForma().getGlobalBounds().width/2,500);
    butoane[butoane.size()-1]=k;
    Button l=creare_text("POZE/nume_text.png",180,210,75,17,false);
    Button m=creare_text("POZE/numar_elevi_text.png",80,310,175,17,false);
    Button n=creare_buton("POZE/return_button_sample2.png",240,33,22,41,false);/// 10
    Button o=creare_buton("POZE/next_button_sample.png",537,33,22,41,false);/// 11
    Button p=creare_buton("POZE/enter_button.png",100,50,259,36,false);/// 12
    p.setPosition(window.getSize().x/2-p.getForma().getGlobalBounds().width/2,35);
    butoane[butoane.size()-1]=p;
    Button q=creare_buton("POZE/save_mark.png",607,526,68,68,false);/// 13
    Button r=creare_buton("POZE/cancel_mark.png",607,210,68,68,false);/// 14
    Button s=creare_buton("POZE/sterge_elev.png",139,560,150,31,false);/// 15!!!
    Button t=creare_buton("POZE/enter_button.png",289,256,209,29,false);/// 16
    Button u=creare_buton("POZE/enter_button.png",338,326,209,29,false);/// 17
    Button v=creare_buton("POZE/enter_button.png",307,396,65,29,false);/// 18
    Button w=creare_buton("POZE/return_button_sample2.png",271,465,17,31,false);/// 19
    Button xx=creare_buton("POZE/next_button_sample.png",481,465,17,31,false);///20
    Button xxx=creare_buton("POZE/cancel_mark.png",700,20,68,68,false);/// 21
    Button y=creare_buton("POZE/sterge_clasa.png",700,20,100,25,false);///22


    Button q1=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q2=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q3=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q4=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q5=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q6=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q7=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q8=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q9=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q10=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q11=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q12=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q13=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q14=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q15=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q16=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q17=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q18=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q19=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q20=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q21=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q22=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q23=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q24=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q25=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q26=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q27=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q28=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q29=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q30=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q31=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q32=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q33=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q34=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q35=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    Button q36=creare_icons("POZE/icon_anonim_cut.png",225,315,47,43,false);
    while(window.isOpen())
    {
        sf::Event evnt;
        while(window.pollEvent(evnt))
        {
            switch(evnt.type)
            {
            case sf::Event::Closed:
                window.close();
            case sf::Event::TextEntered:
                if(wait_for_text && ind==7)///NUMELE CLASEI
                {
                    if(evnt.text.unicode>=65 && evnt.text.unicode<=90 ||(evnt.text.unicode>=48 && evnt.text.unicode<=57)|| evnt.text.unicode==32 &&nume_s.getSize()<16)
                        nume_s+=(char)evnt.text.unicode;
                    else if(evnt.text.unicode>=97 && evnt.text.unicode<=122 &&nume_s.getSize()<16)
                        nume_s+=(char)(evnt.text.unicode-32);
                    else if(evnt.text.unicode==8 && nume_s.getSize()>0)
                        nume_s.erase(nume_s.getSize()-1,nume_s.getSize());
                    nume_t.setString(nume_s);
                }
                else if(wait_for_text && ind==8) /// NUMAR ELEVI
                {
                    if(evnt.text.unicode>=48 && evnt.text.unicode<=57 && nr_s.getSize()<16 && nr_s.getSize()<2)
                    {
                        if(nr_s.getSize()==0)
                            nr_s+=(char)evnt.text.unicode;
                        else if(nr_s.getSize()==1 && nr_s=='3'&&(char)evnt.text.unicode<='6')
                            nr_s+=(char)evnt.text.unicode;
                        else if(nr_s.getSize()==1 && nr_s<'3')
                            nr_s+=(char)evnt.text.unicode;
                    }
                    else if(evnt.text.unicode==8 && nr_s.getSize()>0)
                        nr_s.erase(nr_s.getSize()-1,nr_s.getSize());
                    nr_t.setString(nr_s);
                }
                else if(wait_for_text && ind==16)///NUME
                {
                    if(evnt.text.unicode>=65 && evnt.text.unicode<=90 && nume_elev_s.getSize()<16)
                        nume_elev_s+=(char)evnt.text.unicode;
                    else if(evnt.text.unicode>=97 && evnt.text.unicode<=122  && nume_elev_s.getSize()<16)
                        nume_elev_s+=(char)(evnt.text.unicode-32);
                    else if(evnt.text.unicode==8 && nume_elev_s.getSize()>0)
                        nume_elev_s.erase(nume_elev_s.getSize()-1,nume_elev_s.getSize());
                    nume_elev_t.setString(nume_elev_s);
                }
                else if(wait_for_text && ind==17)///PRENUME
                {
                    if(evnt.text.unicode>=65 && evnt.text.unicode<=90 && prenume_elev_s.getSize()<16)
                        prenume_elev_s+=(char)evnt.text.unicode;
                    else if(evnt.text.unicode>=97 && evnt.text.unicode<=122  && prenume_elev_s.getSize()<16)
                        prenume_elev_s+=(char)(evnt.text.unicode-32);
                    else if(evnt.text.unicode==8 && prenume_elev_s.getSize()>0)
                        prenume_elev_s.erase(prenume_elev_s.getSize()-1,prenume_elev_s.getSize());
                    prenume_elev_t.setString(prenume_elev_s);
                }
                else if(wait_for_text && ind==18)///VARSTA
                {
                    if(evnt.text.unicode>=48 && evnt.text.unicode<=57)
                        varsta_s+=(char)evnt.text.unicode;
                    else if(evnt.text.unicode==8 && varsta_s.getSize()>0)
                        varsta_s.erase(varsta_s.getSize()-1,varsta_s.getSize());
                    varsta_t.setString(varsta_s);

                }
            case sf::Event::MouseButtonPressed:
                if(evnt.mouseButton.button==sf::Mouse::Left && wait_for_text==true)
                    wait_for_text=false;

                break;
            }
        }
        frameCount+=frameSpeed*clock1.restart().asSeconds();
        if(frameCount>500)
        {
            frameCount=0;
            if(draw_warning)
                draw_warning=false;
            if(draw_warning2)
                draw_warning2=false;
            if(draw_warning3)
                draw_warning3=false;
            kk=1-kk;
            butoane[ind].setColor(change[kk]);
        }
        sf::Vector2i Mouse_vec;
        Mouse_vec=sf::Mouse::getPosition(window);
        if(wait_for_text==false)///PARCURGERE ICON-URI
        {
            for(int i=0; i<icons.size(); i++)
                if(icons[i].getForma().getGlobalBounds().contains(Mouse_vec.x,Mouse_vec.y) && icons[i].getDrawn())
                {
                    icons[i].setColor(sf::Color(192,192,192));
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && draw_elev_info==false && !notPressed)
                    {
                        notPressed=true;
                        ind_elev=i;
                        if(ind_elev==clase[ind_clasa].numar_elevi)
                        {
                            clase[ind_clasa].numar_elevi++;
                            icons[ind_elev].setDrawn(false);
                            fout.close();
                            fout.open("clase_info.txt");
                             for(int j=0; j<clase.size(); j++)
                        {
                            fout<<j+1<<'\n';
                            fout<<clase[j].nume_clasa<<'\n'<<clase[j].numar_elevi<<'\n';
                            fout<<'\n';
                            for(int jj=0; jj<=35; jj++)
                            {
                                fout<<clase[j].E[jj].nume<<'\n';
                                fout<<clase[j].E[jj].prenume<<'\n';
                                fout<<clase[j].E[jj].varsta<<'\n';
                                fout<<clase[j].E[jj].gen<<'\n';
                                fout<<clase[j].E[jj].x<<' '<<clase[j].E[jj].y<<'\n';
                                fout<<'\n';
                            }
                        }
                        fout.close();
                        fout.open("clase_info.txt", std::ofstream::app);
                        }
                        else
                        {
                        draw_elev_info=true;
                        nume_elev_s=clase[ind_clasa].E[i].nume;
                        prenume_elev_s=clase[ind_clasa].E[i].prenume;
                        std::stringstream convert;
                        convert<<clase[ind_clasa].E[i].varsta;
                        varsta_s=convert.str();
                        nume_elev_t.setString(nume_elev_s);
                        prenume_elev_t.setString(prenume_elev_s);
                        varsta_t.setString(varsta_s);
                        nume_elev_t.setPosition(300,260);
                        prenume_elev_t.setPosition(342,330);
                        varsta_t.setPosition(310,398);

                        for(int j=13; j<=20; j++)
                            butoane[j].setDrawn(true);
                        }
                    }
                    if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && notPressed)
                        notPressed=false;
                }
                else
                    icons[i].setColor(sf::Color::White);
            for(int i=0; i<butoane.size(); ++i)
            {
                if(butoane[i].getForma().getGlobalBounds().contains(Mouse_vec.x,Mouse_vec.y) &&  butoane[i].getDrawn() &&  button_covered==false) /// daca mouse e pe butoane
                {
                    if(i==21)
                    {
                        butoane[22].setPosition(Mouse_vec.x-50,Mouse_vec.y-20);
                        butoane[22].setDrawn(true);
                    }
                    button_covered=true;
                    if(i!=3 && i!=4 && i!=5)
                        butoane[i].setColor(sf::Color(192,192,192));
                    if(i>=0 && i<=2)
                    {
                        butoane[i+3].setDrawn(true);
                        butoane[i+3].setPosition(Mouse_vec.x,Mouse_vec.y);
                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && i==2)
                        window.close();
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && i==0) /// ADD clasa
                    {
                        for(int j=0; j<3; j++)
                            butoane[j].setDrawn(false);
                        draw_title=false;
                        for(int j=6; j<=9; j++)
                            butoane[j].setDrawn(true);
                        for(int j=0; j<=1; j++)
                            text_elements[j].setDrawn(true);

                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && i==1) /// Vizualizare
                    {
                        if(clase.size()>0)
                        {
                            butoane[21].setDrawn(true);
                            fundal_s.setTexture(fundal_view_t);
                            for(int j=0; j<3; j++)
                                butoane[j].setDrawn(false);
                            draw_title=false;
                            butoane[6].setDrawn(true);
                            for(int j=10; j<=12; j++)
                                butoane[j].setDrawn(true);
                            clase[ind_clasa].setDrawn(true);
                            for(int j=0; j<clase.size(); j++)
                                if(j!=ind_clasa)
                                    clase[j].setDrawn(false);
                            nume_clasa_vizualizare_s=clase[ind_clasa].nume_clasa;
                            nume_clasa_vizualizare_t.setString(nume_clasa_vizualizare_s);
                            notPressed=true;
                            nume_clasa_vizualizare_t.setPosition(window.getSize().x/2-nume_clasa_vizualizare_t.getLocalBounds().width/2,40);
                            for(int j=0; j<=35; j++)
                                icons[j].setDrawn(false);
                        }
                        else
                            draw_warning=true;

                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && i==19 && !notPressed)///Schimba genul elevului la stanga
                    {
                        ind_gen=1-ind_gen;
                        notPressed=true;
                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && i==20 && !notPressed)///Schimba genul elevului la dreapta
                    {
                        ind_gen=1-ind_gen;
                        notPressed=true;
                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && i==10 && !notPressed) /// schimba clasele la vizualizare in stanga
                    {
                        if(ind_clasa==0)
                            ind_clasa=nr_clase-1;
                        else if(ind_clasa>0)
                            ind_clasa--;
                        clase[ind_clasa].setDrawn(true);
                        for(int j=0; j<clase.size(); j++)
                            if(j!=ind_clasa)
                                clase[j].setDrawn(false);
                        nume_clasa_vizualizare_s=clase[ind_clasa].nume_clasa;
                        nume_clasa_vizualizare_t.setString(nume_clasa_vizualizare_s);
                        notPressed=true;
                        nume_clasa_vizualizare_t.setPosition(window.getSize().x/2-nume_clasa_vizualizare_t.getLocalBounds().width/2,40);
                        for(int j=0; j<=35; j++)
                            icons[j].setDrawn(false);
                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && i==11 && !notPressed)/// schimba clasele la vizualizare in dreapta
                    {
                        if(ind_clasa==nr_clase-1)
                            ind_clasa=0;
                        else if(ind_clasa<clase.size()-1)
                            ind_clasa++;
                        clase[ind_clasa].setDrawn(true);
                        for(int j=0; j<clase.size(); j++)
                            if(j!=ind_clasa)
                                clase[j].setDrawn(false);
                        nume_clasa_vizualizare_s=clase[ind_clasa].nume_clasa;
                        nume_clasa_vizualizare_t.setString(nume_clasa_vizualizare_s);
                        nume_clasa_vizualizare_t.setPosition(window.getSize().x/2-nume_clasa_vizualizare_t.getLocalBounds().width/2,40);
                        notPressed=true;
                        for(int j=0; j<=35; j++)
                            icons[j].setDrawn(false);
                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && i==6)  /// buton de return
                    {
                        fundal_s.setTexture(fundal_t);
                        for(int j=0; j<3; j++)
                            butoane[j].setDrawn(true);
                        draw_title=true;
                        for(int j=6; j<=12; j++)
                            butoane[j].setDrawn(false);
                        for(int j=0; j<=35; j++)
                            icons[j].setDrawn(false);
                        for(int j=0; j<=1; j++)
                            text_elements[j].setDrawn(false);
                        if(clase.size()>0)
                            clase[ind_clasa].setDrawn(false);
                        if(draw_elev_info)
                        {
                            draw_elev_info=false;
                            for(int j=13; j<=20; j++)
                                butoane[j].setDrawn(false);
                        }
                        butoane[21].setDrawn(false);

                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && (i==7 || i==8 || i==16 || i==17 || i==18) && wait_for_text==false) /// click pe butoane cu introducere text
                    {
                        wait_for_text=1-wait_for_text;
                        ind=i;
                    }
                    if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && notPressed)///autoclick off - 1 singura apasare
                        notPressed=false;
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && i==13 && nume_elev_s.getSize()>0 && prenume_elev_s.getSize()>0 && varsta_s.getSize()>0 &&!notPressed && ind_elev<clase[ind_clasa].numar_elevi)/// buton save date elev
                    {
                        fout.close();
                        fout.open("clase_info.txt");
                        notPressed=true;
                        clase[ind_clasa].E[ind_elev].nume=nume_elev_s;
                        clase[ind_clasa].E[ind_elev].prenume=prenume_elev_s;
                        clase[ind_clasa].E[ind_elev].gen=gen_s[ind_gen];
                        clase[ind_clasa].E[ind_elev].varsta=parcurgere(varsta_s);
                        for(int j=0; j<clase.size(); j++)
                        {
                            fout<<j+1<<'\n';
                            fout<<clase[j].nume_clasa<<'\n'<<clase[j].numar_elevi<<'\n';
                            fout<<'\n';
                            for(int jj=0; jj<=35; jj++)
                            {
                                fout<<clase[j].E[jj].nume<<'\n';
                                fout<<clase[j].E[jj].prenume<<'\n';
                                fout<<clase[j].E[jj].varsta<<'\n';
                                fout<<clase[j].E[jj].gen<<'\n';
                                fout<<clase[j].E[jj].x<<' '<<clase[j].E[jj].y<<'\n';
                                fout<<'\n';
                            }
                        }
                        draw_elev_info=false;
                        for(int j=13; j<=20; j++)
                            butoane[j].setDrawn(false);
                        fout.close();
                        fout.open("clase_info.txt", std::ofstream::app);
                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && i==21 && notPressed==false && clase.size()>1) /// STERG CLASA
                    {
                        notPressed=true;
                        clase.erase(clase.begin()+ind_clasa);
                        nr_clase=clase.size();
                        if(!O.is_open())
                            O.open("numar_clase_temp.txt");
                        ind_clasa=clase.size()-1;
                        nume_clasa_vizualizare_s=clase[ind_clasa].nume_clasa;
                        nume_clasa_vizualizare_t.setString(nume_clasa_vizualizare_s);
                        nume_clasa_vizualizare_t.setPosition(window.getSize().x/2-nume_clasa_vizualizare_t.getLocalBounds().width/2,40);
                        O<<nr_clase;
                        O.close();
                        remove("numar_clase.txt");
                        rename("numar_clase_temp.txt","numar_clase.txt");
                        fout.close();
                        fout.open("clase_info.txt");
                        for(int j=0; j<clase.size(); j++)
                        {
                            fout<<j+1<<'\n';
                            fout<<clase[j].nume_clasa<<'\n'<<clase[j].numar_elevi<<'\n';
                            fout<<'\n';
                            for(int jj=0; jj<=35; jj++)
                            {
                                fout<<clase[j].E[jj].nume<<'\n';
                                fout<<clase[j].E[jj].prenume<<'\n';
                                fout<<clase[j].E[jj].varsta<<'\n';
                                fout<<clase[j].E[jj].gen<<'\n';
                                fout<<clase[j].E[jj].x<<' '<<clase[j].E[jj].y<<'\n';
                                fout<<'\n';
                            }
                        }
                        fout.close();
                        fout.open("clase_info.txt", std::ofstream::app);
                        remove("numar_clase.txt");
                        rename("numar_clase_temp.txt","numar_clase.txt");


                    }
                   if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && i==21 && notPressed==false && clase.size()==1) /// STERG CLASA - CAZ PARTICULAR
                   {
                        notPressed=true;
                        clase.erase(clase.begin()+ind_clasa);
                        nr_clase=clase.size();
                        if(!O.is_open())
                            O.open("numar_clase_temp.txt");
                        O<<nr_clase;
                        O.close();
                        remove("numar_clase.txt");
                        rename("numar_clase_temp.txt","numar_clase.txt");
                        fout.close();
                        fout.open("clase_info.txt", std::ofstream::app);
                        fundal_s.setTexture(fundal_t);
                        for(int j=0; j<3; j++)
                            butoane[j].setDrawn(true);
                        draw_title=true;
                        for(int j=6; j<=12; j++)
                            butoane[j].setDrawn(false);
                        for(int j=0; j<=35; j++)
                            icons[j].setDrawn(false);
                        for(int j=0; j<=1; j++)
                            text_elements[j].setDrawn(false);
                        if(clase.size()>0)
                            clase[ind_clasa].setDrawn(false);
                        if(draw_elev_info)
                        {
                            draw_elev_info=false;
                            for(int j=13; j<=20; j++)
                                butoane[j].setDrawn(false);
                        }
                        butoane[21].setDrawn(false);
                        fout.close();
                        fout.open("clase_info.txt");
                   }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && i==15) /// Sterge ELEV
                    {
                        draw_elev_info=false;
                        for(int j=13; j<=20; j++)
                            butoane[j].setDrawn(false);
                        clase[ind_clasa].E[ind_elev].nume="-";
                        clase[ind_clasa].E[ind_elev].prenume="-";
                        clase[ind_clasa].E[ind_elev].varsta=0;
                        clase[ind_clasa].E[ind_elev].gen="NEUTRU";
                        fout.close();
                        fout.open("clase_info.txt");
                        notPressed=true;
                        for(int j=0; j<clase.size(); j++)
                        {
                            fout<<j+1<<'\n';
                            fout<<clase[j].nume_clasa<<'\n'<<clase[j].numar_elevi<<'\n';
                            fout<<'\n';
                            for(int jj=0; jj<=35; jj++)
                            {
                                fout<<clase[j].E[jj].nume<<'\n';
                                fout<<clase[j].E[jj].prenume<<'\n';
                                fout<<clase[j].E[jj].varsta<<'\n';
                                fout<<clase[j].E[jj].gen<<'\n';
                                fout<<clase[j].E[jj].x<<' '<<clase[j].E[jj].y<<'\n';
                                fout<<'\n';
                            }
                        }
                        fout.close();
                        fout.open("clase_info.txt", std::ofstream::app);

                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && i==14) /// CANCEL chenar informatii elev
                    {
                        draw_elev_info=false;
                        for(int j=13; j<=20; j++)
                            butoane[j].setDrawn(false);
                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && i==9 && (nume_s.getSize()==0 || nr_s.getSize()==0))
                        draw_warning3=true;
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && i==9 && nume_s.getSize()>0 && nr_s.getSize()>0 && !notPressed) ///CREEAZA CLASA
                    {
                        int ok=0;
                        ok=0;
                        std::string aux;
                        ///cresc numarul de clase
                        for(int j=0; j<clase.size(); ++j)
                        {
                            aux=nume_s;
                            if(aux.compare(clase[j].nume_clasa)==0)
                            {
                                ok=1;
                                draw_warning2=true;
                                break;
                            }
                        }
                        if(ok==0)
                        {
                            for(int j=6; j<=12; j++)
                                butoane[j].setDrawn(false);
                            for(int j=0; j<=1; j++)
                                text_elements[j].setDrawn(false);
                            fundal_s.setTexture(fundal_view_t);
                            for(int j=0; j<3; j++)
                                butoane[j].setDrawn(false);
                            draw_title=false;
                            butoane[6].setDrawn(true);
                            notPressed=true;
                            F.open("numar_clase.txt");
                            if(!O.is_open())
                                O.open("numar_clase_temp.txt");
                            F>>nr_clase;
                            nr_clase++;
                            ind_clasa=nr_clase-1;
                            O<<nr_clase;
                            F.close();
                            O.close();
                            remove("numar_clase.txt");
                            rename("numar_clase_temp.txt","numar_clase.txt");
                            std::string NUME=nume_s;
                            int nr=parcurgere(nr_s);
                            Clasa C(NUME,nr);
                            clase.push_back(C);
                            clase[ind_clasa].setDrawn(true);
                            fout<<nr_clase<<'\n';
                            fout<<NUME<<'\n'<<nr<<'\n';
                            fout<<'\n';
                            for(int j=0; j<=35; j++)
                            {
                                fout<<C.E[j].nume<<'\n';
                                fout<<C.E[j].prenume<<'\n';
                                fout<<C.E[j].varsta<<'\n';
                                fout<<C.E[j].gen<<'\n';
                                fout<<C.E[j].x<<' '<<C.E[j].y<<'\n';
                                fout<<'\n';
                            }


                        }
                    }
                }
                else
                {
                    if(i==21)
                        butoane[22].setDrawn(false);
                    button_covered=false;
                    butoane[i].setColor(sf::Color::White);
                    if(i>=0 && i<=2)
                        butoane[i+3].setDrawn(false);
                }
            }
        }
        window.draw(fundal_s);
        if(draw_title)
            window.draw(titlu_s);
        if(draw_warning)
            window.draw(warning_shape);
        if(draw_warning2)
            window.draw(warning2_shape);
        if(draw_warning3)
            window.draw(warning3_shape);
        deseneaza_clase();
        deseneaza_icons(window);
        if(draw_elev_info)
        {
            window.draw(elev_info_shape);
            window.draw(gen_t[ind_gen]);
        }
        deseneaza_text(window);
        deseneaza_butoane(window);
        if(draw_elev_info)
        {
            window.draw(nume_elev_t);
            window.draw(prenume_elev_t);
            window.draw(varsta_t);
        }
        if(butoane[9].getDrawn())
        {
            window.draw(nume_t);
            window.draw(nr_t);
        }
        if(butoane[10].getDrawn())
            window.draw(nume_clasa_vizualizare_t);
        window.display();
        window.clear();
    }
    return 0;
}
void initializare_icon(sf::RenderWindow &window)
{
    sf::Image icon;
    icon.loadFromFile("POZE/icon.png");
    window.setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());
}
Button creare_buton(std::string path, float x, float y,float x_dim, float y_dim,bool se_poate_desena)
{
    Button b(path,x,y,x_dim,y_dim);
    b.setDrawn(se_poate_desena);
    butoane.push_back(b);
    return b;
}
Button creare_icons(std::string path, float x, float y,float x_dim, float y_dim,bool se_poate_desena)
{
    Button b(path,x,y,x_dim,y_dim);
    b.setDrawn(se_poate_desena);
    icons.push_back(b);
    return b;
}
Button creare_text(std::string path, float x, float y,float x_dim, float y_dim,bool se_poate_desena)
{
    Button b(path,x,y,x_dim,y_dim);
    b.setDrawn(se_poate_desena);
    text_elements.push_back(b);
    return b;
}
void deseneaza_butoane(sf::RenderWindow &window)
{
    for(int i=0; i<butoane.size(); ++i)
        if(butoane[i].getDrawn())
            butoane[i].draw(window);
}
void deseneaza_text(sf::RenderWindow &window)
{
    for(int i=0; i<text_elements.size(); ++i)
        if(text_elements[i].getDrawn())
            text_elements[i].draw(window);
}
void deseneaza_clase()
{
    int i, j;
    for(i=0; i<clase.size(); i++)
        if(clase[i].getDrawn())
        {
            for(j=0; j<clase[i].numar_elevi; j++)
            {
                if(clase[i].E[j].gen=="NEUTRU")
                    icons[j].SetPath("POZE/icon_anonim_cut.png");
                else if(clase[i].E[j].gen=="MASCULIN")
                    icons[j].SetPath("POZE/icon_boy_cut.png");
                else if(clase[i].E[j].gen=="FEMININ")
                    icons[j].SetPath("POZE/icon_girl_cut.png");
                icons[j].setPosition(clase[i].E[j].x,clase[i].E[j].y);
                icons[j].setDrawn(true);
            }
            if(clase[i].numar_elevi<36)
            {
                icons[j].SetPath("POZE/adauga_elev.png");
                icons[j].setPosition(clase[i].E[j].x,clase[i].E[j].y);
                icons[j].setDrawn(true);
            }
        }
}
void parcurgere_clase()
{
    F>>nr_clase;
    F.close();
    int indice;
    std::string nume_clasa;
    int nr_elevi;
    struct elevi
    {
        std::string nume1,prenume1,gen1;
        int varsta1;
        float x1,y1;
    } E1[36];
    for(int i=1; i<=nr_clase; i++)
    {
        fin>>indice;
        fin.get();
        std::getline(fin,nume_clasa);
        fin>>nr_elevi;
        for(int j=0; j<=35; j++)
        {
            fin>>E1[j].nume1>>E1[j].prenume1>>E1[j].varsta1;
            fin>>E1[j].gen1;
            fin>>E1[j].x1>>E1[j].y1;
        }
        Clasa D(nume_clasa,nr_elevi);
        for(int j=0; j<nr_elevi; j++)
        {
            D.E[j].nume=E1[j].nume1;
            D.E[j].prenume=E1[j].prenume1;
            D.E[j].varsta=E1[j].varsta1;
            D.E[j].gen=E1[j].gen1;
            D.E[j].x=E1[j].x1;
            D.E[j].y=E1[j].y1;
        }
        clase.push_back(D);
    }
}
int parcurgere(sf::String S)
{
    int i, lg, val=0;
    lg=S.getSize();
    for(i=0; i<lg; ++i)
        val=val*10+int(S[i]-'0');
    return val;
}
void deseneaza_icons(sf::RenderWindow &window)
{
    for(int i=0; i<icons.size(); ++i)
        if(icons[i].getDrawn())
            icons[i].draw(window);
}

