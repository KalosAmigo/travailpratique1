// TP1-Structures.cpp
//
//

#include <iostream>
#include <string>
using namespace std;

int Saisie_Valeurs();
void Insertion_Valeurs(int tab_numerateur[], int tab_denumerateur[], int taille);
int Calcul_Diviseur(int numerateur, int denominateur);
string Afficher_Simplifier(int numerateur, int denominateur);
void Afficher_Final(int tab_numerateur[], int tab_denumerateur[], int taille);

int main()
{
    int taille{};

    cout << "Entrez le nombre de fractions a calculer (nombre positif): ";
    taille = Saisie_Valeurs();

    int* tab_numerateur{ new int[taille] {} };
    int* tab_denumerateur{ new int[taille] {} };

    cout << taille << " fractions seront traitees." << endl;

    Insertion_Valeurs(tab_numerateur, tab_denumerateur, taille);

    Afficher_Final(tab_numerateur, tab_denumerateur, taille);

    delete[] tab_numerateur, tab_denumerateur;
    return 0;
}


// Calcul_Diviseur
// 
// Reçoit un numerateur et un denominateur. 
//
// Retourne PGCD des deux valeurs passé en paramètre
// 
// minimum -> valeur plus petite entre le numerateur et le denominateur
// diviseur_retour -> valeur du PGCD et la variable retourné

int Calcul_Diviseur(int numerateur, int denominateur) {
    int minimum = numerateur;
    int diviseur_retour = 1;

    if (denominateur < minimum)
        minimum = denominateur;

    for (int diviseur = 1; diviseur <= minimum; diviseur++) {
        if (numerateur % diviseur == 0 && denominateur % diviseur == 0)
            diviseur_retour = diviseur;
    }

    return diviseur_retour;
}

// Afficher_Simplifier
//
// Reçoit un numerateur et un denominateur. 
//
// Retourne string avec le numerateur et le denominateur simplifié concatené.
//
// aff_num -> Numerateur simplifié
// aff_den -> denominateur simplifié

string Afficher_Simplifier(int numerateur, int denominateur) {

    int aff_num = numerateur / Calcul_Diviseur(numerateur, denominateur);
    int aff_den = denominateur / Calcul_Diviseur(numerateur, denominateur);

    return (to_string(aff_num) + "/" + to_string(aff_den));
}


// Afficher_Final
//
// Reçoit le tableau de numerateurs, le tableau de denominateurs et la taille de ces tableaux
//

void Afficher_Final(int tab_numerateur[], int tab_denumerateur[], int taille) {
    for (int i = 0; i < taille; i++) {
        cout << tab_numerateur[i] << "/" << tab_denumerateur[i] << " >>> " << Afficher_Simplifier(tab_numerateur[i], tab_denumerateur[i]) << endl;
    }
}

// Saisie_Valeurs
//
// Lit l'entrée de l'utilisateur, vérifie si elle est positive.
// Elle la retourne si valide.
//

int Saisie_Valeurs() {
    int nombre;
    do {
        cin >> nombre;
        if (nombre <= 0)
            cout << "ERREUR -> Valeur egale ou plus petite que 0. \n" << "Reessayez: ";
    } while (nombre <= 0);

    return nombre;
}

// Insertion_Valeurs
// 
// Insertion des données des tableaux. Se repète d'après la taille communiqué.
// Appelle la fonction Saisie_Valeurs
//

void Insertion_Valeurs(int tab_numerateur[], int tab_denumerateur[], int taille) {

    for (int i = 0; i < taille; i++) {
        cout << "Entrez le numerateur #" << (i + 1) << " (nombre positif): ";
        tab_numerateur[i] = Saisie_Valeurs();

        cout << "Entrez le denominateur #" << (i + 1) << " (nombre positif): ";
        tab_denumerateur[i] = Saisie_Valeurs();
    }
}







