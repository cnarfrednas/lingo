/**
* @mainpage Lingo opdracht
*
* het programmeren van de lingo opdracht om het C programmeren weer op te frissen.
*
* @author Franc Sander van Schaick
*/

/**
* @file main.c
*
* @brief Dit is de main file van het hele gebeuren, bevat functies om random woorden uit een txt bestand te halen en de invoer te controleren.
*
**/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


char strIngevoegdWoord[6];  //!< string met het getypte woord
char strGekozenWoord[6];    //!< string met het uit de txt gewonnen woord
char strWoord[6];           //!< string welke wordt gebruikt bij het tot stand komen van strAanwezigeLetters.
char strWoord2[6];          //!< String welke wordt gebruikt bij het tot stand komen van strHeleGoedeLetters.
char strHeleGoedeLetters[6];    //!< string welke opslaat welke letters op de goed plek in het woord zitten, en aanvult naarmate men vordert.
//char strSymbol[6];
char strGoedeLetters[6]= {' ', ' ', ' ', ' ', ' ', '\0'};       //!< string welke opslaat welke letters op de goede plek in het woord staan.
char strAanwezigeLetters[6]= {' ', ' ', ' ', ' ', ' ', '\0'};   //!< string welke opslaat welke letters in het woord zitten.
char strEinde[6];   //!< Markeert het einde van het txt document

char cKeuze;
int iCount1, iCount2, iCount3, iGoed, iBeurt;

void KiesWoord(void);
void ControleerInvoer(void);
int a, b ,c, k, l, i, p, q;


/*!
    @brief De main functie.

*/


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

/*!
    @brief De woorden kies functie.

*/

void KiesWoord(void)
{
    srand(time(NULL));                                          //genereren seed zodat random ook echt random is.

    FILE *input;
    if ((input = fopen("lingowoorden.txt", "r")) == NULL)       //invoer ophalen
    {
        printf("Geen invoer bestand");                              //wanneer er geen input is, deze waarschuwing geven

    }
    else
    {
        printf("Welkom bij Lingo!\n\nHet eerste woord is:\n");
        for(i = 0; i < rand(); i++)                         // document doorlopen met random waarde, en opnieuw beginnen wanneer file eindigd.
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


/*!
    @brief De invoer controle functie.

*/




void ControleerInvoer(void)
{
    if((strIngevoegdWoord[0]==strGekozenWoord[0])&&(strIngevoegdWoord[1]==strGekozenWoord[1])&&(strIngevoegdWoord[2]==strGekozenWoord[2])&&(strIngevoegdWoord[3]==strGekozenWoord[3])&&(strIngevoegdWoord[4]==strGekozenWoord[4])) // wanneer alle letters goed zijn, mededeling dat je geweldig hebt en gewonnen hebt.
    {
        printf ("gefeliciteerd, het woord is goed!\n\n");
        iGoed = 1;
        return;
    }

    strcpy(strWoord2, strGekozenWoord); // copy maken om gekozen woord te behouden.

    for(a=0; a<5; a++)
    {
        if(strWoord2[a]==strIngevoegdWoord[a])  //kijken welke letter goed staat, wanneer letter goed is, kopieren naar string goedeletters, en de goede letter weghalen zodat deze niet nogmaals gebruikt wordt.
        {
            strGoedeLetters[a]=strWoord2[a];
            strWoord[a] = '.';
            strWoord2[a]='.';
        }
        else
        {
            strWoord[a]=strIngevoegdWoord[a];   //wanneer goede letter niet aanwezig een punt zetten op deze positie.
            strGoedeLetters[a]='.';

        }
    }
    //printf("\n%s   :Rest invoer",&carrWoord);
    //printf("\n%s   :Rest opl",&carrWoord2);
    //printf("\n%s   :Goede letters",&carrGoedeLetters);

    printf("\n\n");
    for(b=0; b<5; b++)                      // kijken naar aanwezige letters in het woord. NB: aanwezige letters zijn al uit het woord verwijderd zodat deze niet nogmaals worden weergegeven.
    {
        for(c=0; c<5; c++)
        {
            if(strWoord[b]==strWoord2[c] && strWoord[b] != '.')
            {
                strAanwezigeLetters[b]=strWoord[b];     // wanneer er een aanwezige letter is, zetten op de plek waar deze is gevonden, en vervolgens wegstrepen zodat deze niet nogmaals verwerkt wordt.
                strWoord[b]='.';
                strWoord2[c]='.';
                break;
            }
            else
            {
                strAanwezigeLetters[b] = '.';       // wanneer er geen aanwezige letter is, punt neer zetten.
            }
        }
    }

    for(k=0; k<5; k++)
    {
        if(strGoedeLetters[k] != '.' || strHeleGoedeLetters[k] == 0)  // laten zien welke letters al op de goede plek staan van voorgaande beurten.
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

