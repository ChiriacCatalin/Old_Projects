#include "Clasa.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Button.h"

Clasa::Clasa(std::string Nume, int Nr_elevi)
{
    nume_clasa=Nume;
    numar_elevi=Nr_elevi;
    fin.open("coordonate_elevi.txt");
    for(int i=0;i<=35;i++)
    {
    E[i].gen="NEUTRU";
    E[i].nume="-";
    E[i].prenume="-";
    E[i].varsta=0;
    fin>>E[i].x>>E[i].y;
    }
}
Clasa::Clasa(const Clasa&ceva)
{
   nume_clasa=ceva.nume_clasa;
   numar_elevi=ceva.numar_elevi;
   for(int j=0;j<36;j++)
                E[j]=ceva.E[j];
}
bool Clasa::getDrawn()
{
    return isDrawn;
}
void Clasa::setDrawn(bool value)
{
    isDrawn=value;
}
/*Clasa& Clasa::operator=(const Clasa& other)
{

}
*/
