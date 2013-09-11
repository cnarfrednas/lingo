#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

/******************************************************************
** File : lingo.c
** Auteur : Franc Sander van Schaick
** Datum : 10-09-2013
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
char carrEinde[];

char cKeuze;
int iCount1, iCount2, iCount3, iGoed, iBeurt;

void ControleerInvoer(void);
int a, b ,c, k, l, i, p, q;






int main()
{
    srand(time(NULL));

    FILE *input;
    if ((input = fopen("lingowoorden.txt", "r")) == NULL)       //invoer ophalen
    {
        printf("Geen invoer bestand");                              //wanneer er geen input is, deze waarschuwing geven
        return 0;
    }
    else
    {
        printf("Welkom bij Lingo!\n#: goede letter\n@: aanwezige letter\n\nHet eerste woord is:\n");
        for(i = 0; i < rand(); i++)
        {
            fgets(carrGekozenWoord, 6, input);

            char carrEinde = getc(input);
            if(carrEinde == EOF)
                fseek(input, 0, SEEK_SET);

            else if((carrEinde != '\n') && (carrEinde != EOF))
                ungetc(carrEinde, input);
        }

        iGoed = 0;
        iBeurt = 0;
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

        while(iGoed==0)
        {
            printf("\n");
            scanf("%s", &carrIngevoegdWoord);
            ControleerInvoer();
            if(iBeurt == 4)
            {
                printf("\nHelaas, game over! Het woord was: %s\n\n", &carrGekozenWoord);
                return 0;
            }
        }

        if(iGoed==1)
        {
            return 0;
        }
    }

    return 0;
}











void ControleerInvoer(void)
{
    if((carrIngevoegdWoord[0]==carrGekozenWoord[0])&&(carrIngevoegdWoord[1]==carrGekozenWoord[1])&&(carrIngevoegdWoord[2]==carrGekozenWoord[2])&&(carrIngevoegdWoord[3]==carrGekozenWoord[3])&&(carrIngevoegdWoord[4]==carrGekozenWoord[4]))
    {
        printf ("gefeliciteerd, het woord is goed!\n\n");
        iGoed = 1;
        return;
    }

    strcpy(carrWoord2, carrGekozenWoord);

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
    //printf("\n%s   :Rest invoer",&carrWoord);
    //printf("\n%s   :Rest opl",&carrWoord2);
    //printf("\n%s   :Goede letters",&carrGoedeLetters);

    printf("\n\n");
    for(b=0; b<5; b++)
    {
        for(c=0; c<5; c++)
        {
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
        if(carrGoedeLetters[k] != '.' || carrHeleGoedeLetters[k] == 0)
        {
            carrHeleGoedeLetters[k]=carrGoedeLetters[k];
        }
    }

    //printf("\n\n%s   :Rest invoer",&carrWoord);
    //printf("\n%s   :Rest opl",&carrWoord2);
    //printf("\n%s   :Goede letters",&carrGoedeLetters);
    printf("\n%s   :Aanwezige letters",&carrAanwezigeLetters);
    printf("\n%s   :Nieuwe kans",&carrHeleGoedeLetters);
    iGoed = 0;
    iBeurt++;

}
