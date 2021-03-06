#include <stdbool.h>
#include <string.h>

#include "liste_char.c"

/* *******************************************************************************************
 *  Q.2
 *  Fonction qui teste qu'un caractere est un signe de parenthesage ouvrant
 * ********************************************************************************************/
bool estOuvrant (char c) {
    return ((c == '(') || (c == '[') || (c == '{')) ;
}

void test_estOuvrant_param (char c) {
    printf("Le caractère %c ", c);
    if (estOuvrant(c)) { printf("est "); } else { printf("n'est pas "); }
    printf("un caractère ouvrant\n");

}

void test_estOuvrant () {
    test_estOuvrant_param('(') ;
    test_estOuvrant_param(')') ;
    test_estOuvrant_param('{') ;
    test_estOuvrant_param('}') ;
    test_estOuvrant_param('[') ;
    test_estOuvrant_param(']') ;
    test_estOuvrant_param('g') ;
    test_estOuvrant_param('3') ;
}

/* *******************************************************************************************
 *  Q.3 - caractère fermant
 *  Fonction qui teste qu'un caractere est un signe de parenthesage FERMANT
 * ********************************************************************************************/
bool estFermant (char c) {
    return ((c == ')') || (c == ']') || (c == '}')) ;
}

void test_estFermant_param (char c) {
    printf("Le caractère %c ", c);
    if (estFermant(c)) { printf("est "); } else { printf("n'est pas "); }
    printf("un caractère fermant\n");

}

void test_estFermant () {
    test_estFermant_param('(') ;
    test_estFermant_param(')') ;
    test_estFermant_param('{') ;
    test_estFermant_param('}') ;
    test_estFermant_param('[') ;
    test_estFermant_param(']') ;
    test_estFermant_param('g') ;
    test_estFermant_param('3') ;
}


/* *******************************************************************************************
 *  Q.4 - Fonction qui teste que deux caractères sont l'un ouvrant l'autre fermant et qu'ils se correspondent
 * ********************************************************************************************/
bool sontOuvrantFermantCorrespondant (char c1, char c2) {
    return (((c1 == '(') && (c2 == ')')) || ((c1 == '[') && (c2 == ']')) || ((c1 == '{') && (c2 == '}')) ) ;
}

void teste_sontOuvrantsFermantsCorrespondants_param (char c1, char c2) {
    printf("Les caractères %c %c ", c1, c2);
    if (sontOuvrantFermantCorrespondant(c1, c2)) { printf("sont "); } else { printf("ne sont pas "); }
    printf("des caractères ouvrant et fermant correspondants\n");
}


void test_sontOuvrantsFermantsCorrespondants () {
    teste_sontOuvrantsFermantsCorrespondants_param ('(', ')') ;
    teste_sontOuvrantsFermantsCorrespondants_param (')', '(') ;
    teste_sontOuvrantsFermantsCorrespondants_param ('{', '}') ;
    teste_sontOuvrantsFermantsCorrespondants_param ('[', ']') ;
    teste_sontOuvrantsFermantsCorrespondants_param ('(', '}') ;
    teste_sontOuvrantsFermantsCorrespondants_param ('{', ']') ;
    teste_sontOuvrantsFermantsCorrespondants_param ('[', ')') ;
    teste_sontOuvrantsFermantsCorrespondants_param ('}', '{') ;
}

/* *******************************************************************************************
 *  Q.5 - Teste qu'une chaine de caractère est bien parenthésée
 * ********************************************************************************************/

bool estBienParenthesee_FA (liste C, liste P) { // C pour Chaine, P pour Pile
    /* si chaine vide ET pile vide => VRAI */
    if ((est_vide(C)) && (est_vide(P)))
        return true ;

    /* si chaine vide MAIS pile pas vide => FAUX */
    if ((est_vide((C))) && (!est_vide(P)))
        return false ;

    /* ICI : chaine pas vide */
    /* on regarde le premier caractere de la chaine  */

    /* si premier caractere n'est pas un signe de parenthesage */
    if ((!estOuvrant(prem(C))) && (!estFermant(prem(C)))) {
        /* on passe au caractere suivant */
        return estBienParenthesee_FA (reste(C), P) ;
    }

    /* si premier caractere est un signe de parenthesage */
    /* si parenthesage ouvrant */
    else if ((estOuvrant(prem(C)))) {
        /* on ajoute le charactere a la pile et on continue avec le reste de la chaine */
        return estBienParenthesee_FA (reste(C), cons(prem(C), P)) ;
    }
    /* si parenthesage fermant */
    else { //if ((estFermant(prem(C)))) {

        /* si la pile est vide => FAUX*/
        if (est_vide(P))
            return false ;

        /* si le premier caractere de la pile est ouvrant et que cela correspond => on passe à la suite */
        if (sontOuvrantFermantCorrespondant(prem(P), prem(C))) {
            return estBienParenthesee_FA(reste(C), reste(P)) ;
        }
        /* sinon => FAUX*/
        else {
            return false ;
        }
    }

}

bool estBienParenthesee (char * str) {

    liste L ;
    int i ;

    L = l_vide() ;

    /* convert string -> list */
    for (i = 0 ; i < strlen(str) ; i += 1) {
        L = cons (str[i], L) ;
    }

    L = renverser(L) ;

    //afficher_liste(L) ;

    return estBienParenthesee_FA (L, l_vide()) ;
}



void test_chaineParenthesee_param (char * str) {
    printf("La chaine de caractère \"%s\" ", str);
    if (estBienParenthesee(str)) { printf("est "); } else { printf("n'est pas "); }
    printf("bien parenthésée\n");
}

void test_chaineParenthesee () {
    char * str = "" ;
    test_chaineParenthesee_param(str) ;

    str = "({[]})" ;
    test_chaineParenthesee_param(str) ;

    str = "({[]})(" ;
    test_chaineParenthesee_param(str) ;

    str = "({[]})}" ;
    test_chaineParenthesee_param(str) ;

    char * str1 = "a+(b- [c * d * e / (f + g)])" ;
    test_chaineParenthesee_param(str1) ;

    char * str2 = "a+(b- [c * d * e / (f + g)" ;
    test_chaineParenthesee_param(str2) ;
}

/* *******************************************************************************************
 *  Q.6 - Teste le parenthesage et retourne 1, -1 ou -2 selon le type de chaine (bien, pas bien type a, pas bien type b)
 * ********************************************************************************************/

bool pileContientSeulementParenthesageOuvrant (liste P) { /* la liste passee en premiere instance n est pas vide */

	if (est_vide (P)) {
		return true ;
	} else if (estOuvrant (prem (P))) {
		return pileContientSeulementParenthesageOuvrant (reste (P)) ;
	} else {
		return false ;
	}
}


int estBienParentheseeValeur_FA (liste C, liste P) { // C pour Chaine, P pour Pile
	/* si chaine vide ET pile vide => VRAI */

	
	if ((est_vide(C)) && (est_vide(P))) {
		return 1 ;
	}

    /* si chaine vide MAIS pile pas vide => FAUX */
    if ((est_vide((C))) && (!est_vide(P))) {

	    
        if (pileContientSeulementParenthesageOuvrant (P)) { /* il manque des parenthesages fermant : type a */
		return -1;
	}
	else { /* il manque autre chose que des parenthesages fermant : type b */
		return -2 ;
	}
    }

    /* ICI : chaine pas vide, pile peut etre vide ou pas vide*/
    /* on regarde le premier caractere de la chaine  */

    /* si premier caractere n'est pas un signe de parenthesage */
    if ((!estOuvrant(prem(C))) && (!estFermant(prem(C)))) {

	/* on passe au caractere suivant */
        return estBienParentheseeValeur_FA (reste(C), P) ;
    }

    /* si premier caractere est un signe de parenthesage */
    /* si parenthesage ouvrant */
    else if ((estOuvrant(prem(C)))) {
        /* on ajoute le charactere a la pile et on continue avec le reste de la chaine */
        return estBienParentheseeValeur_FA (reste(C), cons(prem(C), P)) ;
    }
    /* si parenthesage fermant */
    else { //if ((estFermant(prem(C)))) {

        /* si la pile est vide => FAUX*/
        if (est_vide(P))
            return -2 ;

        /* si le premier caractere de la pile est ouvrant et que cela correspond => on passe à la suite */
        if (sontOuvrantFermantCorrespondant(prem(P), prem(C))) {
            return estBienParentheseeValeur_FA(reste(C), reste(P)) ;
        }
        /* sinon => FAUX*/
        else {
            return -2 ;
        }
    }
}


	
int estBienParentheseeValeur (char * str) {

    liste L ;
    int i ;

    L = l_vide() ;

    /* convert string -> list */
    for (i = 0 ; i < strlen(str) ; i += 1) {
        L = cons (str[i], L) ;
    }

    L = renverser(L) ;

    //afficher_liste(L) ;

    return estBienParentheseeValeur_FA (L, l_vide()) ;
}

void test_chaineParentheseeValeur_param (char * str) {
    printf("La chaine de caractère \"%s\" ", str);
    if (estBienParentheseeValeur(str) == 1) { printf("est bien parenthésée\n"); } 
    else if (estBienParentheseeValeur(str) == -1){ printf("n'est pas bien parenthésée - type a (il manque des parenthésages fermants)\n"); }
    else { printf("n'est pas bien parenthésée - type b\n"); }

}

void test_chaineParentheseeValeur () {
    char * str = "" ;
    test_chaineParentheseeValeur_param(str) ;

    str = "({[]})" ;
    test_chaineParentheseeValeur_param(str) ;

    str = "({[]})(" ;
    test_chaineParentheseeValeur_param(str) ;

    str = "({[]})}" ;
    test_chaineParentheseeValeur_param(str) ;

    char * str1 = "a+(b- [c * d * e / (f + g)])" ;
    test_chaineParentheseeValeur_param(str1) ;

    char * str2 = "a+(b- [c * d * e / (f + g)" ;
    test_chaineParentheseeValeur_param(str2) ;
}

/* *******************************************************************************************
 *  Q.7 - Associe à une chaine pas bien parenthésée type-a une chaine bien parenthésée
 * ********************************************************************************************/

/*liste retablitParenthesage (char * str) {
}*/


void test_retablitParenthesage_param (char * str) {
	printf("A la chaine mal parenthésée type a \"%s\", retablitParenthesage() associe", str);

}


void test_retablitParenthesage () {

    char * str = "a+(b- [c * d * e / (f + g)" ;
    test_retablitParenthesage_param(str) ;
}
/* *******************************************************************************************
 *  Main
 * ********************************************************************************************/
int main () {


    liste L ;

    L = cons ('l', cons ('9', l_vide())) ;
    /* teste liste_char */
    afficher_liste(L) ;
    printf("\n") ;


    /* teste le parenthesage ouvrant */
    test_estOuvrant () ;
    printf("\n") ;

    /* teste le parenthesage fermant */
	test_estFermant () ;
    printf("\n") ;

    /* teste deux caracteres ouvrant/fermant/correspondant */
    test_sontOuvrantsFermantsCorrespondants () ;
    printf ("\n") ;

    /* teste chaine de caracteres */
    test_chaineParenthesee () ;
    printf ("\n") ;

    /* teste chaine de caracteres avec valeur pour type a et b */
    test_chaineParentheseeValeur () ;
    printf ("\n") ;
    
    /* teste le retablissement du parenthesage */
    test_retablitParenthesage () ;
    printf ("\n") ;
    
    return (0) ;
}