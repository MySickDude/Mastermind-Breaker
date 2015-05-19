//
//  main.cpp
//  MasterMind Breaker
//
//  Created by Sacha Kozma on 19.05.15.
//  Copyright (c) 2015 Sacha KOZMA. All rights reserved.
//

#include <iostream>

using namespace std;

void genererCombinaison (int combinaisonCourante[], int nombreCases, int nombreCouleurs);
void afficherCombinaison(int combinaisonCourante[], int nombreCases)
;


int main(int argc, const char * argv[])
{
    srandomdev();

    
    int nombreCases, longueurTableau, essais[longueurTableau][nombreCases], score[longueurTableau][2], nombreEssais = 0, combinaisonCourante[nombreCases], nombreCouleurs ;
    
    
    genererCombinaison(combinaisonCourante, nombreCases, nombreCouleurs);
    
    afficherCombinaison(combinaisonCourante, nombreCases);
    
    cout << "Combien y a-t-il de noirs ?";
    cin >> score[nombreEssais][0];
    
    cout << "Combien y a-t-il de blancs ?";
    cin >> score[nombreEssais][1];
    
    return 0;
}

void genererCombinaison (int combinaisonCourante[], int nombreCases, int nombreCouleurs)
{
    for (int i = 0; i < nombreCases; i++) {
        combinaisonCourante[i] = random() % nombreCouleurs + 1;
    }
}

void afficherCombinaison(int combinaisonCourante[], int nombreCases)
{
    for (int i = 0; i < nombreCases; i++) {
        cout << " | " << combinaisonCourante[i] << " | ";
    }
    
    cout << endl << endl;
}