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
** Opgedeeld in functies.
******************************************************************/

char strIngevoegdWoord[6];
char strGekozenWoord[6];
char strWoord[6];
char strWoord2[6];
char strHeleGoedeLetters[6];
char strSymbol[6];
char strGoedeLetters[6]= {' ', ' ', ' ', ' ', ' ', '\0'};
char strAanwezigeLetters[6]= {' ', ' ', ' ', ' ', ' ', '\0'};
char strEinde[6];

char cKeuze;
int iCount1, iCount2, iCount3, iGoed, iBeurt;

void KiesWoord(void);
void ControleerInvoer(void);
int a, b ,c, k, l, i, p, q;



int main()
{

    KiesWoord();
    iGoed = 0;
    iBeurt = 0;
    for(iCount1 = 0; iCount1<5; iCount1++)
    {
        if(iCount1 == 0)
        {
            printf("%c", strGekozenWoord[iCount1]);
        }
        else
        {
            printf(".");
        }
        strWoord2[iCount1]=strGekozenWoord[iCount1];
    }
    // strcpy(carrGekozenWoord,carrWoord);

    while(iGoed==0)
    {
        printf("\n");
        scanf("%s", &strIngevoegdWoord);
        ControleerInvoer();
        if(iBeurt == 4)
        {
            printf("\nHelaas, game over! Het woord was: %s\n\n", &strGekozenWoord);
            return 0;
        }
    }

    if(iGoed==1)
    {
        return 0;
    }


    return 0;
}


void KiesWoord(void)
{
    srand(time(NULL));

    FILE *input;
    if ((input = fopen("lingowoorden.txt", "r")) == NULL)       //invoer ophalen
    {
        printf("Geen invoer bestand");                              //wanneer er geen input is, deze waarschuwing geven

    }
    else
    {
        printf("Welkom bij Lingo!\n\nHet eerste woord is:\n");
        for(i = 0; i < rand(); i++)
        {
            fgets(strGekozenWoord, 6, input);

            char strEinde = getc(input);
            if(strEinde == EOF)
                fseek(input, 0, SEEK_SET);

            else if((strEinde != '\n') && (strEinde != EOF))
                ungetc(strEinde, input);
        }
    }
}







void ControleerInvoer(void)
{
    if((strIngevoegdWoord[0]==strGekozenWoord[0])&&(strIngevoegdWoord[1]==strGekozenWoord[1])&&(strIngevoegdWoord[2]==strGekozenWoord[2])&&(strIngevoegdWoord[3]==strGekozenWoord[3])&&(strIngevoegdWoord[4]==strGekozenWoord[4]))
    {
        printf ("gefeliciteerd, het woord is goed!\n\n");
        iGoed = 1;
        return;
    }

    strcpy(strWoord2, strGekozenWoord);

    for(a=0; a<5; a++)
    {
        if(strWoord2[a]==strIngevoegdWoord[a])
        {
            strGoedeLetters[a]=strWoord2[a];
            strWoord[a] = '.';
            strWoord2[a]='.';
        }
        else
        {
            strWoord[a]=strIngevoegdWoord[a];
            strGoedeLetters[a]='.';

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
            if(strWoord[b]==strWoord2[c] && strWoord[b] != '.')
            {
                strAanwezigeLetters[b]=strWoord[b];
                strWoord[b]='.';
                strWoord2[c]='.';
                break;
            }
            else
            {
                strAanwezigeLetters[b] = '.';
            }
        }
    }

    for(k=0; k<5; k++)
    {
        if(strGoedeLetters[k] != '.' || strHeleGoedeLetters[k] == 0)
        {
            strHeleGoedeLetters[k]=strGoedeLetters[k];
        }
    }

    //printf("\n\n%s   :Rest invoer",&carrWoord);
    //printf("\n%s   :Rest opl",&carrWoord2);
    //printf("\n%s   :Goede letters",&carrGoedeLetters);
    printf("\n%s   :Aanwezige letters",&strAanwezigeLetters);
    printf("\n%s   :Nieuwe kans",&strHeleGoedeLetters);
    iGoed = 0;
    iBeurt++;

}

