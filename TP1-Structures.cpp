// TP1-Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//

#include <iostream>
#include <string>
using namespace std;

int Calcul_Diviseur(int numerateur, int denominateur);
string Afficher_Simplifier(int numerateur, int denominateur);
void Afficher_Final(int tabNum[], int tabDeNum[], int taille);
void saisie(int tabNum[], int tabDeNum[], int taille);
int verification(); 

int main()
{
    int taille{};
    cout << "Entrez le nombre de fraction : "; 
    taille = verification();

    int* tabNum{ new int [taille] {} };
    int* tabDeNum{ new int [taille] {} };
    saisie(tabNum, tabDeNum, taille);
    Afficher_Final(tabNum, tabDeNum, taille);
    delete[] tabNum, tabDeNum; 
}


int Calcul_Diviseur(int numerateur, int denominateur) {
    int minimum = numerateur;
    int div_ret = 1;

    if (denominateur < minimum)
        minimum = denominateur;

    for (int diviseur = 1; diviseur <= minimum; diviseur++) {
        if (numerateur % diviseur == 0 && denominateur % diviseur == 0)
            div_ret = diviseur;
    }

    return div_ret;
}

// Retourne string avec le numerateur et le denominateur simplifié
string Afficher_Simplifier(int numerateur, int denominateur) {
    int aff_num = numerateur / Calcul_Diviseur(numerateur, denominateur);
    int aff_den = denominateur / Calcul_Diviseur(numerateur, denominateur);

    return (to_string(aff_num) + "/" + to_string(aff_den));
}

void Afficher_Final(int tabNum[], int tabDeNum[], int taille) {
    for (int i = 0; i < taille; i++)
    {
        cout << tabNum[i] << "/" << tabDeNum[i] << " >>> " << Afficher_Simplifier(tabNum[i], tabDeNum[i]) << endl;  

    }
}

void saisie(int tabNum[], int tabDeNum[], int taille) {
    for (int i = 0; i < taille; i++)
    {
        cout << "entrez un numerateur : ";
        tabNum[i] = verification();
        cout << "entrez un denumerateur : ";
        tabDeNum[i] = verification();

    }
    
}

int verification() {
    int n;

    do {
        cin >> n;
        if (n <= 0)
            cout << "erreur reesayer : "; 
    } while (n <= 0);
    return n; 
}







