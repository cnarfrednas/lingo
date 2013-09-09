#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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
char carrWoord[6];
char carrWoord2[6];
char carrHeleGoedeLetters[6];
char carrSymbol[6];
char carrGoedeLetters[6]= {' ', ' ', ' ', ' ', ' ', '\0'};
char carrAanwezigeLetters[6]= {' ', ' ', ' ', ' ', ' ', '\0'};

char cKeuze;
int iCount1, iCount2, iCount3;

void ControleerInvoer(void);
int a, b ,c, k, l, p;
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
        printf("Welkom bij Lingo!\n#: goede letter\n@: aanwezige letter\n\nHet eerste woord is:\n");
        fgets (carrGekozenWoord, 6, input);
        //for(iCount=0; iCount<6; iCount++)
        // {
        //     printf("%c", carrGekozenWoord[iCount]);
        // }
        for(iCount1 = 0; iCount1<5; iCount1++)
        {
            if(iCount1 == 0)
            {
                printf("%c", carrGekozenWoord[iCount1]);
            }
            else
            {
                printf(".");
            }
            carrWoord2[iCount1]=carrGekozenWoord[iCount1];
        }
        // strcpy(carrGekozenWoord,carrWoord);
        printf("\n");
        scanf("%s", &carrIngevoegdWoord);
        ControleerInvoer();
        printf("\n");
        scanf("%s", &carrIngevoegdWoord);
        ControleerInvoer();
        printf("\n");
        scanf("%s", &carrIngevoegdWoord);
        ControleerInvoer();


    }

    return 0;
}

void Initialisatie(void)
{

}

void ControleerInvoer(void)
{
    for(a=0; a<5; a++)
    {
        if(carrWoord2[a]==carrIngevoegdWoord[a])
        {
            carrGoedeLetters[a]=carrWoord2[a];
            carrWoord[a] = '.';
            carrWoord2[a]='.';
        }
        else
        {
            carrWoord[a]=carrIngevoegdWoord[a];
            carrGoedeLetters[a]='.';

        }
    }
    printf("\n%s   :Rest invoer",&carrWoord);
    printf("\n%s   :Rest opl",&carrWoord2);
    printf("\n%s   :Goede letters",&carrGoedeLetters);

    printf("\n\n");
    for(b=0; b<5; b++)
    {
        for(c=0; c<5; c++)
        {
            //printf("\n  %i:%i : %c:%c",b,c,carrWoord[b], carrWoord2[c]);
            if(carrWoord[b]==carrWoord2[c] && carrWoord[b] != '.')
            {
                carrAanwezigeLetters[b]=carrWoord[b];
                carrWoord[b]='.';
                carrWoord2[c]='.';
                break;
            }
            else
            {
                carrAanwezigeLetters[b] = '.';
            }
        }
    }

    for(k=0; k<5; k++)
    {
        carrHeleGoedeLetters[k]=carrGoedeLetters[k];
    }

    if((carrIngevoegdWoord[0]==carrGekozenWoord[0])&&(carrIngevoegdWoord[1]==carrGekozenWoord[1])&&(carrIngevoegdWoord[2]==carrGekozenWoord[2])&&(carrIngevoegdWoord[3]==carrGekozenWoord[3])&&(carrIngevoegdWoord[4]==carrGekozenWoord[4]))
    {
        printf("gefeliciteerd, het woord is goed!");
    }
    else
    {
        printf("\n\n%s   :Rest invoer",&carrWoord);
        printf("\n%s   :Rest opl",&carrWoord2);
        //printf("\n%s   :Goede letters",&carrGoedeLetters);
        printf("\n%s   :Aanwezige letters",&carrAanwezigeLetters);
        printf("\n%s   :Nieuwe kans",&carrHeleGoedeLetters);
    }



}
