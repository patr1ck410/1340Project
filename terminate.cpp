#include "terminate.h"
#include "drawcard.h"
#include "output.h"
void terminateactions(int cardsremaining, bool (&deck)[4][13],int (&publiccard)[5][2] )
{
    int card[2];
    for (int j = (5 - cardsremaining); j < 5; j++)
    { // draw all the public cards if terminate = true
        cardDraw(deck, card);
        publiccard[j][0] = card[0];
        publiccard[j][1] = card[1];
    }
    showpublic(publiccard, 5); // show all public card


};
