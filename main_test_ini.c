/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_ini.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:10:43 by vronchin          #+#    #+#             */
/*   Updated: 2020/02/14 14:10:45 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
    //printf("%*d", width(largeur), num);
    //equivalent a:

    printf("\n***PRECISION***\n");//Precision: precise le nb de char a generer
    printf("\n- precision 0, valeur 0: ");
    printf( "%.0d", 0 );
    printf("\n- precision 1, valeur 8: ");
    printf( "%.1d", 8 );
    printf("\n- precision de 3 sur '123456', valeur 0: ");
    printf( "%.3d", 132456 );
    
    printf("\n");

    printf("\nL'ARGUMENT WIDTH\n");//indique le minimum de char. specificateur de largeur = (*). ne tronque pas car juste indicatif.
    printf("\n| 0*d |  width = 5 | valeur = '123456789': ");
    printf("%0*d", 5, 123456789);
    //width = 5 donc on check si la valeur a moins de 5 places.
    //Si la valeur est plus large ou egale a 5 alors rien ne se passe.
    //si la valeur est plus courte strictement que 5 alors on complete par (width - largeur valeur)0. i.e de chiffres non significatifs
    printf("\n| 0*d |  width = 5 | valeur = '123': ");
    printf("%0*d", 5, 123);
    //en fait width nous donne le minimum de taille que l'on veut pour notre valeur.

    // meme resultat sans le 0. Donc fait apparaitre (wwidth - largeur valeur) espaces
    printf("\n| *d |  width = 5 | valeur = '123': ");
    printf("%*d", 5, 123);

    printf("\n| 0*d |  width = 5 | valeur = '123456789': ");
    printf("%0*d", 5, 123456789);//minimum largeur de 5 donc on remplit toutle reste sans souci

    //avec un char*
    printf("\n| *s |  width = 7 | valeur = 'Maman tout se passe bien.': ");
    printf("%*s", 5, "Maman tout se passe bien.");
    //le 0 dewidth ne marche pas avec des char

    //avec un char* mais 
    printf("\n| *s |  width = 10 | valeur = 'Maman': ");
    printf("%*s", 10, "Maman");//pas possible avec 0
    printf("\n| *c |  width = 10 | valeur = 'M': ");
    printf("%*c", 10, 'M');//on met 9 espaces avant, marche pas

    printf("\n");
    printf("\nTEST width < precision:");
    printf("|");
    printf("%*.10d", 5, 1234);//Avec width il faut faire 5 au minimum. 1er test: comparer width et taille_valeur. 
    // 2e test: Si on a width et precision alors il faut les comparer direct pour voir qui ajouter.dans tous les cas on va generer exactement $precision places
    //ici width < precision donc pas besoin de gerer le width.
    printf("|");

    printf("\nTEST 0.2 *.*:");
    printf("|");
    printf("%.*d", 5, 1234);//qu'il soit avant ou apres * est un width wuiprend sa valeur dans l arguement precedent la valeur 
    printf("|");

    printf("\nTEST 2 precision < width:");
    printf("|");
    printf("%*.4d", 5, 1234);//si jamais precision < width alors width prend le dessus et on ajoute espace a gauche du width.
    printf("|");
    

    printf("\nTEST 3:le 0 est ignored si on a la precision .ET le width:");
    printf("|");
    printf("%0*.4d", 5, 1234);// Si 0 est spécifié pour un format entier (i, u, x, X, o, d)
    // et qu’une spécification de précision est également présente (par exemple, %04.d), le 0 est ignoré
    printf("|");

    printf("\nTEST 4:\n- si on a que la precision, 0 marche");
    printf("|");
    printf("%0.5d", 1234);//
    printf("|");
    printf("\n- sans le zero: ");// marche pareil
    printf("|");
    printf("%.5d", 1234);//
    printf("|");

    // le - surpasse le 0

    printf("\nTEST 5: le - : ");
    printf("|");
    printf("%-.5d", 1234);//
    printf("|");

    printf("\n");

////////////////////////////////////////      La taille initiale    ///////////////////////////////////////////////////////////////////////////////////

    printf("\n");   
    printf("\n///////////////////////////////   TESTs la taille initiale /////////////////////// ");

    printf("\n# taille de 2 pour une valeur_size de 4=");
    printf("|");
    printf("%2d", 1234);
    printf("|");

    printf("\n");

    printf("\n# taille de 5 pour une valeur_size de 4=");
    printf("|");
    printf("%5d", 1234);
    printf("|");


    printf("\n");
    printf("\n");

    /*  COMMENTAIRES  
    la taille ajoute seulement des espaces, a gauche ou a droite en fonction du -
    */

///////////////////////////////////////      LE    -   ET le  .    ////////////////////////////////////////////////////////////////////////////////////
    printf("\n///////////////////////////       TESTs 6: le - et le . //////////////////////////// ");

    printf("\n# le - seul =");
    printf("|");
    printf("%15d", 1234);
    printf("|");

    printf("\n");

    printf("\n# le - seul =");
    printf("|");
    printf("%-15d", 1234);
    printf("|");

    printf("\n");

    printf("\n# sans -, taille 15, precision 9 =");
    printf("|");
    printf("%15.9d", 1234);
    printf("|");

    printf("\n");

    printf("\n# avec -, taille 15, precision 9 =");
    printf("|");
    printf("%-15.*d", 9, 1234);
    printf("|");

    /* COMMENTAIRES     * width ne tronque pas mais ajoute des 0.
    1. le chiffre apres - nous donne la taille globale. 
    A. Si on a rien dautre on complete de (taille- taille_valeur) espaces a droite (car on aligne a gauche)
    B. si on  a un precision apres (la precision est toujours apres) alors on doit equilibrer entre les 0 fournis par la precision a gauche de 
    la valeur et les espaces a droite. i.e affiche (width - taille_valeur) zeros, la valeur et enfin (taille du -)
    3.
    
    le - doit nous permettre de remplir a l invere les derniers espaces.
    le chiffre du debut peut etre au tout debut ou apres le - et nous donne la longueur du resultat final 
    
    */
    
   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("\n");

    printf("\n# avec -, taille 15, precision 9 =");
    printf("|");
    printf(%d);
    printf("|");




    return 0;
}

/* QUESTION
- comment gerer les 0 et - qui font erreur avec gcc
- 

*/