#ifndef CLASA_H
#define CLASA_H
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include "Button.h"

class Clasa
{
    public:
        Clasa(std::string Nume, int Nr_elevi);
        Clasa(const Clasa&ceva);
        Clasa& operator=(const Clasa& other)
        {
            nume_clasa=other.nume_clasa;
            numar_elevi=other.numar_elevi;
            for(int j=0;j<36;j++)
                E[j]=other.E[j];
            return *this;
        }
        bool getDrawn();
        void setDrawn(bool value);
        std::string nume_clasa;
        std::ifstream fin;
        int numar_elevi;
        struct elev
        {
            std::string nume,prenume,gen;
             int varsta;
            float x,y;
        }E[36];
        private:
            bool isDrawn=false;
};
#endif // CLASA_H;
