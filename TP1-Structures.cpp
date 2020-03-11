// TP1-Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//

#include <iostream>
#include <string>
using namespace std;

int Calcul_Diviseur(int numerateur, int denominateur);
string Afficher_Simplifier(int numerateur, int denominateur);

int main()
{
    int numerateur, denominatur;
    cout << "Entrez numerateur: ";
    cin >> numerateur;
    cout << "Entrez denominateur: ";
    cin >> denominatur;

    cout << Afficher_Simplifier(numerateur, denominatur);
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

    return (to_string(aff_num) + " / " + to_string(aff_den));
}
