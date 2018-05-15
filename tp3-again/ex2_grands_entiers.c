#include <math.h>

#include "liste_entiers.c"

#define BASE 10

/* **************************************************************************************
 * Q2. Affiche grand entier
 * ***************************************************************************************/

void afficher_grand_entier (liste L) {
    if (est_vide(L))
        return ;

    liste M = renverser (L) ;
    while ( prem(M) == 0) {
        M = reste (M) ;
    }

    while (! est_vide(M)) {
        printf ("%d", prem (M));
        M = reste (M) ;
    }
}

void test_afficher_grand_entier_param (liste L) {
    printf ("Afficher_grand_entier ( ") ;
    afficher_liste(L) ;
    printf (" ) = ") ;

    afficher_grand_entier(L) ;
    printf ("\n") ;
}

void test_afficher_grand_enier () {

    liste L ;
    L = cons (5, cons (7, cons (6, cons (7, cons (0, cons (0, l_vide ())))))) ;
    test_afficher_grand_entier_param (L) ;
}

/* **************************************************************************************
 * Q3. Successeur grand entier
 * ***************************************************************************************/

liste succ_FA (liste L, unsigned int retenue) {

    /* si la liste est vide : il faut dans tous les cas retourner une liste vide à un moment */
    if (est_vide(L)) {
        if (retenue == 0) {
            return l_vide() ;
        } else {
            return cons (retenue, l_vide()) ;
        }
    }

    /* si la retenue fait dépasser la base */
    if ((prem (L) + retenue) == BASE) {
        return cons (0, succ_FA(reste(L), 1)) ;
    }

    return cons (prem(L) + retenue, succ_FA(reste(L), 0)) ;
}

liste successeur_grand_entier (liste L) {
    return succ_FA(L, 1) ;
}

void test_successeur_grand_entier_param (liste L) {
    printf ("Successeur grand entier ( ") ;
    afficher_liste(L) ;
    printf (" ) = ") ;
    afficher_grand_entier( successeur_grand_entier(L)) ;
    printf ("\n") ;
}

void test_successeur_grand_entier () {
    liste L ;

    L = cons (7, cons (7, l_vide ())) ;
    test_successeur_grand_entier_param (L) ;

    L = cons (5, cons (7, cons (6, cons (7, cons (0, cons (0, l_vide ())))))) ;
    test_successeur_grand_entier_param (L) ;
}

/* **************************************************************************************
 * Q4. Grand entier correspondant à un entier naturel
 * ***************************************************************************************/

liste entier_nat_vers_grand_entier (unsigned int entier_nat) {
    /* on utilise mod pour récuperer l'élement a mettre dans la liste
     * on utiise la division entiere pour recupere la suite du nombre à traiter*/


    if (entier_nat == 0)
        return l_vide() ;

    return cons (entier_nat % BASE, entier_nat_vers_grand_entier (entier_nat / BASE)) ;
}


void test_entier_nat_vers_grand_entier_param (unsigned int entier_nat) {
    printf ("Entier_nat_vers_grand_entier ( %d ) = ", entier_nat) ;
    afficher_liste(entier_nat_vers_grand_entier(entier_nat)) ;
    printf ("\n") ;
}

void test_entier_nat_vers_grand_entier () {
    unsigned int i = 173456712 ;
    test_entier_nat_vers_grand_entier_param(i) ;
}


/* **************************************************************************************
 * Q5. Entier naturel correspondant à un grand entier
 * ***************************************************************************************/
unsigned long  gd_ent_ent_nat_FA (liste L, unsigned int puissance) {
    if (est_vide(L))
        return 0 ;

    return (prem (L) * pow(BASE, puissance) + gd_ent_ent_nat_FA (reste (L), puissance + 1)) ;
}



unsigned long grand_entier_vers_entier_nat (liste L) {
    return gd_ent_ent_nat_FA (L, 0) ;
}

void test_grand_entier_vers_entier_nat_param (liste L) {
    printf ("Grand_entier_vers_entier_nat ( ");
    afficher_liste(L) ;
    printf (" ) = %lu", grand_entier_vers_entier_nat(L)) ;
    printf ("\n") ;
}


void test_grand_entier_vers_entier_nat () {
    liste L = cons (5, cons (7, cons (6, cons (7, cons (0, cons (0, l_vide ())))))) ;
    test_grand_entier_vers_entier_nat_param (L) ;
}


/* **************************************************************************************
 * Q6. Somme de grands entiers
 * ***************************************************************************************/

liste somme_grands_entiers (liste L, liste M, unsigned int retenue) {

    /* deux listes vides : fin de la recursivité */
    if (est_vide(L) && est_vide(M)) {
        return (retenue != 0) ? cons (retenue, l_vide()) : l_vide() ;

    }


    /* ici au moins une des deux listes n'est pas vide*/

    unsigned int temp = retenue ;
    liste N, O ;

    if (!est_vide(L)) {
        temp += prem (L) ;
        N = reste (L) ;
    } else {
        N = l_vide() ;
    }

    if (!est_vide (M)) {
        temp += prem (M) ;
        O = reste (M) ;
    } else {
        O = l_vide() ;
    }

    return cons (temp % BASE, somme_grands_entiers (N, O, temp / BASE)) ;
}


void test_somme_grands_entiers_param (liste L, liste M) {
    printf ("test_somme_grands_entiers ( ") ;
    afficher_liste(L) ;
    printf (" + ") ;
    afficher_liste(M) ;
    printf (" ) = ") ;
    afficher_liste(somme_grands_entiers(L, M, 0)) ;
    printf (" = ") ;
    afficher_grand_entier(somme_grands_entiers(L, M, 0)) ;
    printf ("\n") ;
}

void test_somme_grands_entiers () {
    liste L = cons (9, l_vide()) ;
    test_somme_grands_entiers_param(L, L) ;

    L = cons (5, cons (7, cons (6, cons (7, cons (0, cons (0, l_vide ())))))) ;
    liste M = cons (9, l_vide()) ;
    test_somme_grands_entiers_param(L, M) ;

}


/* **************************************************************************************
 * Q7. Différence de grands eniers
 * WARNING : on calcule la différence (grand_enier_1 - grand_entier_2) uniquement pour grand_enier_1 >= grand_entier_2
 * ***************************************************************************************/

liste difference_grands_entiers (liste L, liste M, unsigned int retenue) {
    unsigned int temp = retenue ;
    liste N ;


    if (est_vide(L))
        return cons (retenue, l_vide()) ;

    if (!est_vide (M)) {
        temp += prem (M) ;
        N = reste (M) ;
    } else {
        N = l_vide() ;
    }

    if (prem (L) >= temp) {
        return cons (prem (L) - temp, difference_grands_entiers(reste (L), N, 0)) ;
    } else {
        return cons ((prem (L) + BASE) - temp, difference_grands_entiers(reste (L), N, 1)) ;
    }

}

void test_difference_grands_entiers_param (liste L, liste M) {
    printf ("difference_grands_entiers ( ") ;
    afficher_liste (L) ;
    printf (" - ") ;
    afficher_liste (M) ;
    printf (" ) = ") ;
    afficher_liste (difference_grands_entiers (L, M, 0)) ;
    printf ("  = ") ;
    afficher_grand_entier (difference_grands_entiers (L, M, 0)) ;
    printf ("\n") ;
}


void test_difference_grands_entiers () {
    liste L = cons (4, cons (1, cons (1, l_vide ()))) ;
    liste M = cons (5, cons (5, l_vide())) ;
    test_difference_grands_entiers_param (L, M) ;

}

/* **************************************************************************************
 * Q8. Multiplication de grands entiers
 * ***************************************************************************************/
liste prod (liste L, unsigned int y, unsigned int retenue) {

    if (est_vide(L) && (retenue == 0)) {
        return l_vide() ;
    }

    if (est_vide(L) && (retenue != 0)) {
        //printf ("retenue %d\n", retenue) ;
        return cons (retenue, l_vide()) ;
    }


    unsigned int temp = prem (L) * y + retenue ;

    return cons (temp % BASE, prod (reste (L), y, temp / BASE)) ;
}


liste produit_grands_entiers (liste L, liste P) {

    liste S = l_vide() ;
    liste M = P ;
    unsigned  int cpt = 0 ;

    while (!est_vide(M)) {
        liste N ;

        N = prod (L, prem (M), 0) ;
       /* printf ("\nN = ") ;
        afficher_liste(N) ;
        printf ("\n") ;*/
        int i ;

        for (i = 0 ; i < cpt ; i += 1) {
            N = cons (0, N) ;
        }

        cpt += 1 ;
        S = somme_grands_entiers(S, N, 0) ;
        M = reste (M) ;
    }

    return S ;
}

void test_produit_grands_entiers_param (liste L, liste P) {
    printf ("produit_grands_entiers ( ") ;
    afficher_liste (L) ;
    printf (" * ") ;
    afficher_liste (P) ;
    printf (" ) = ") ;
    afficher_liste(produit_grands_entiers(L, P)) ;
    printf (" = ") ;
    afficher_grand_entier(produit_grands_entiers(L, P)) ;
    printf ("\n") ;
}

void test_produit_grands_entiers () {
    liste L = cons (9, cons (9, l_vide ())) ;
    test_produit_grands_entiers_param (L, L) ;

    liste M = cons (2, l_vide ()) ;
    test_produit_grands_entiers_param (L, M) ;

    test_produit_grands_entiers_param (M, L) ;
}

/* **************************************************************************************
 * Q9. Factorielle
 * ***************************************************************************************/

liste factorielle_GE (liste L) {

    if (grand_entier_vers_entier_nat(L) == 1)
        return cons (1, l_vide()) ;

    return produit_grands_entiers(L, factorielle_GE(difference_grands_entiers(L, cons (1, l_vide()), 0))) ;
}

void test_factorielle_GE_param (liste L) {
    printf ("factorielle_ge ( ") ;
    afficher_liste(L) ;
    printf (" ) = ") ;
    afficher_liste(factorielle_GE(L)) ;
    printf (" = ") ;
    afficher_grand_entier(factorielle_GE(L)) ;
    printf ("\n") ;
}

void test_factorielle_GE () {
    test_factorielle_GE_param(cons(7, l_vide())) ;
}




int main () {

    printf ("\n") ;

    printf ("Base : %d\n\n", BASE) ;

    test_afficher_grand_enier() ;

    printf ("\n") ;

    test_successeur_grand_entier () ;

    printf ("\n") ;

    test_entier_nat_vers_grand_entier () ;

    printf ("\n") ;

    test_grand_entier_vers_entier_nat () ;

    printf ("\n") ;

    test_somme_grands_entiers () ;

    printf ("\n") ;

    test_difference_grands_entiers () ;

    printf ("\n") ;

    test_produit_grands_entiers () ;

    printf ("\n") ;

    test_factorielle_GE () ;

    return 0 ;
}