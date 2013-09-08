#include <stdio.h>
#include <stdlib.h>

/******************************************************************
** File : lingo.c
** Auteur : Franc Sander van Schaick
** Datum : 08-09-2013
** Compiler : GNU GCC
** Description :
** spel lingo voor CXX01
** Modifications :
** inlezen file toegevoegd.
******************************************************************/

char carrIngevoegdWoord[6];
char carrGekozenWoord[6];
char carrTussenWoord[18];
char cKeuze;
int iCount1, iCount2, iCount3;


int main()
{
    FILE *input;
    if ((input = fopen("C:\\Users\\Sander\\Documents\\lingowoorden.txt", "r")) == NULL)       //invoer ophalen
    {
        printf("Geen invoer bestand");                              //wanneer er geen input is, deze waarschuwing geven
        return 0;
    }
    else
    {
        printf("Welkom bij Lingo!\nHet eerste woord is:\n");
        fgets (carrGekozenWoord, 6, input);
       // for(iCount=0; iCount<6; iCount++)
       // {
       //     printf("%c", carrGekozenWoord[iCount]);
       // }
        for(iCount1 = 0; iCount1<5; iCount1++)
        {
            if(iCount1 == 0){printf("%c", carrGekozenWoord[iCount1]);}
            else{printf(".");}
        }
        printf("\n");

        for(iCount2 = 0; iCount2<5; iCount2++)
        {
            scanf("%c", &carrIngevoegdWoord[iCount2]);
        }


        for(iCount1 = 0; iCount1<6; iCount1++)
        {
            if(carrGekozenWoord[iCount1]==carrIngevoegdWoord[iCount1])
        }

    }





    return 0;
}


