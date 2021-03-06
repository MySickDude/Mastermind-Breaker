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
    int  longueurTableau = 100, essais[longueurTableau][nombreCases], score[longueurTableau][2], combinaisonCourante[nombreCases], scoreTemp[2] = {0}, nombreEssais = 0;
    bool essaisMarque [nombreCases], combinaisonCouranteMarque [nombreCases], combinaisonTrouvee;
    
    genererCombinaison(combinaisonCourante, nombreCases, nombreCouleurs);
    
    for (int i = 0; i < longueurTableau; i++) {
        score[i][0] = 0;
        score[i][1] = 0;
    }
    
    do {
        nombreEssais++;
        
        for (int i = 0; i < nombreCases; i++) {
            essais[nombreEssais][i] = combinaisonCourante[i];
        }
        
        afficherCombinaison(combinaisonCourante, nombreCases);
        
        cout << "Combien y a-t-il de noirs ?";
        cin >> score[nombreEssais][0];
        
        cout << "Combien y a-t-il de blancs ?";
        cin >> score[nombreEssais][1];
        
        
        do {
            combinaisonTrouvee = true;
            genererCombinaison(combinaisonCourante, nombreCases, nombreCouleurs);
            
            for (int k = 0; k <= nombreEssais; k++) {
                fill(scoreTemp, scoreTemp + 2, 0);
                
                for (int i = 0; i < nombreCases; i++) { //Remise à zéro des marques sur les combinaisons
                    essaisMarque[i] = false;
                    combinaisonCouranteMarque[i] = false;
                }
                
                for (int i = 0; i < nombreCases; i++) { // Calcul du nombre de "noir" (bonne couleur au bon endroit)
                    if (combinaisonCourante [i] == essais[k] [i]) {
                        scoreTemp [0] += 1; // score[0] représente les noirs
                        essaisMarque[i] = true;
                        combinaisonCouranteMarque[i] = true;
                    }
                }
                
                for (int i = 0; i < nombreCases; i++) { // Calcul du nombre de "blanc" (bonne couleur pas au même endroit)
                    if (not essaisMarque[i]) {
                        for (int j = 0; j < nombreCases; j++) {
                            if (combinaisonCourante[j] == essais[k][i] && not combinaisonCouranteMarque[j]) {
                                scoreTemp[1] += 1; // représente les blancs
                                essaisMarque[i] = true;
                                combinaisonCouranteMarque[j] = true;
                                break;
                            }
                        }
                        
                        
                    }
                    
                    
                    
                }
                
                if(scoreTemp[0] != score[k][0] && scoreTemp[1] != score[k][1]){
                    break;
                }
            }
            
            
        } while(not combinaisonTrouvee);
        
        
        
        
        
    } while(score[nombreEssais][0] != 4);
    
    
    
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