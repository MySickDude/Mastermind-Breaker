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
void afficherCombinaison(int combinaisonCourante[], int nombreCases);
int demanderNombre (string caption);
void calculScore(int combinaisonMystere[], int combinaisonUtilisateur[], int nombreCases, int score [], int nombreEssais);


int main(int argc, const char * argv[])
{
    srandomdev();
    
    const int nombreCases = demanderNombre("Combien de cases souhaitez-vous ?"), nombreCouleurs = demanderNombre("Combien de couleurs souhaitez-vous ?");
    int  longueurTableau = 100, essais[longueurTableau][nombreCases], score[longueurTableau][2], combinaisonCourante[nombreCases], scoreTemp[2] = {0};
    bool essaisMarque [nombreCases], combinaisonCouranteMarque [nombreCases];
    
    
    for (int nombreEssais = 0; score[nombreEssais][0] != 4; nombreEssais++) {
        
        for (int i = 0; i < nombreCases; i++) {
            essais[nombreEssais][i] = combinaisonCourante[i];
        }
        
        genererCombinaison(combinaisonCourante, nombreCases, nombreCouleurs);
        
        afficherCombinaison(combinaisonCourante, nombreCases);
        
        cout << "Combien y a-t-il de noirs ?";
        cin >> score[nombreEssais][0];
        
        cout << "Combien y a-t-il de blancs ?";
        cin >> score[nombreEssais][1];
        
        
        while (scoreTemp[0] != score[nombreEssais][0] && scoreTemp[1] != score[nombreEssais][1]) {
            fill(scoreTemp, scoreTemp + 2, 0);
            
            genererCombinaison(combinaisonCourante, nombreCases, nombreCouleurs);
            
            for (int i = 0; i < nombreCases; i++) { //Remise à zéro des marques sur les combinaisons
                essaisMarque[i] = false;
                combinaisonCouranteMarque[i] = false;
            }
            
            for (int i = 0; i < nombreCases; i++) { // Calcul du nombre de "noir" (bonne couleur au bon endroit)
                if (combinaisonCourante [i] == essais[nombreEssais] [i]) {
                    scoreTemp [0] += 1; // score[0] représente les noirs
                    essaisMarque[i] = true;
                    combinaisonCouranteMarque[i] = true;
                }
            }
            
            for (int i = 0; i < nombreCases; i++) { // Calcul du nombre de "blanc" (bonne couleur pas au même endroit)
                if (not essaisMarque[i]) {
                    for (int j = 0; j < nombreCases; j++) {
                        if (combinaisonCourante[j] == essais[nombreEssais][i] && not combinaisonCouranteMarque[j]) {
                            scoreTemp[1] += 1; // représente les blancs
                            essaisMarque[i] = true;
                            combinaisonCouranteMarque[j] = true;
                            break;
                        }
                    }
                }
                
            }
            
            
            
        }
        
    }
    
    
    
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

int demanderNombre (string caption)
{
    int nombre;
    cout << caption;
    cin >> nombre;
    return nombre;
}

/*
 
 void calculScore(int combinaisonMystere [][], int combinaisonUtilisateur [][], int nombreCases, int score[], int nombreEssais) // Changer pour utiliser tableau bi-dimensionel ! (changer nom variable + envoyer nombreEssais)
 {
 bool combinaisonMystereMarque [nombreCases], combinaisonUtilisateurMarque [nombreCases];
 
 
 fill(score, score + 2, 0); // Remet à zéro les scores
 
 for (int i = 0; i < nombreCases; i++) { //Remise à zéro des marques sur les combinaisons
 combinaisonMystereMarque[i] = false;
 combinaisonUtilisateurMarque[i] = false;
 }
 
 for (int i = 0; i < nombreCases; i++) { // Calcul du nombre de "noir" (bonne couleur au bon endroit)
 if (combinaisonUtilisateur [i] == combinaisonMystere [i]) {
 score [0] += 1; // score[0] représente les noirs
 combinaisonMystereMarque[i] = true;
 combinaisonUtilisateurMarque[i] = true;
 }
 }
 
 for (int i = 0; i < nombreCases; i++) { // Calcul du nombre de "blanc" (bonne couleur pas au même endroit)
 if (not combinaisonMystereMarque[i]) {
 for (int j = 0; j < nombreCases; j++) {
 if (combinaisonUtilisateur[j] == combinaisonMystere[i] && not combinaisonUtilisateurMarque[j]) {
 score[1] += 1; // représente les blancs
 combinaisonMystereMarque[i] = true;
 combinaisonUtilisateurMarque[j] = true;
 break;
 }
 }
 }
 
 }
 
 
 }
 */