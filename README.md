Team 34 members:
Chan Kwok Wai

Chen Junhao

Cheng Ching Lok

Li Pak Long

Yeung Cheuk Yik

In this group project, a classical Texas Hold’em(Poker) game was designed.

In a Texas poker game, a standard 52-card deck is used. Rank from lowest to highest: 2 3 4 5 6 7 8 9 10 J Q K A Suits: Clubs, Diamonds, Hearts, 

Spades (all suits worth the same)

Before the game starts, each player will be allocated 100BB for the poker game.

Game Rules

Before the game starts, two players (small blind and big blind) are forced to pay 0.5BB and 1BB respectively as blind bets.

Two hole cards will randomly be distributed to each player. 

Once each player gets their hole cards, the game starts with the first betting round. The first betting round is known as the pre-flop round which 

player take action only based on their hole cards. 

When the pre-flop round is over, the first three of five community cards will be distributed which is known as flop cards. Once flop cards are 

distributed, the second betting round starts, and then players have to take action again. 

Then, the fourth community card (Turn) will be distributed, and once players take action, the final round will start. The final community card 

(River) will be placed, and players will take action for the last time.

At last, players have to show their two hidden cards and compare them to find the winner(s). The winner in that round will take all the chips in the chips pool.

Compilation and execution instruction:
1. Make file
2. type ./main
3. check your cards and take action.
4. wait a period of time for the game result output
5. terminate the program --> control C

-What action can players take? 

1. Check/Fold (choose 1 in-game)
2. Bet/re-raise (choose 2 in-game)
3. Fold (choose 3 in-game)
4. Check for the community cards (choose 4 in-game and it is only feasible after the flop is distributed)

-How to determine the winner?

1. Be the only player left in-game 
  - convincing other players to fold their hole cards before the last card (River) is. Distributed.
2. Win by having the best hand
  - having the best hand when the final betting round is over.
  Using the hole cards in hand and the five community cards, whoever gets the best combinations/ranks will be the winner.

Ranking of combinations from highest to lowest:

Royal Flush (holding AKQJT of all the same suit)

Straight Flush (Five consecutive cards of the same suit) 

e.g. Q♥J♥10♥9♥8♥ and 8♠7♠6♠5♠4♠

Four of a Kind (Four cards of the same rank) 

e.g. A♥A♦A♠A♣5♦ or 9♥9♦9♣9♠4♠

Full House (Three of a Kind and a Pair) 

e.g. A♥A♦A♠6♣6♦ and 10♣10♠10♥4♠4♥

Flush (Five cards of the same suit, not in sequence)

If two flushes go head-to-head, combinations with best high cards win

A♠J♠7♠4♠2♠ (an ace-high flush) beats T♥7♥5♥3♥2♥ (a ten-high flush) 

Straight (Five consecutive cards of mixed suits) 

e.g. 9♠8♠7♣6♥5♦

Three-of-a-Kind (Three cards with the same rank with any two cards not in different ranks)

e.g. 10♥10♣10♣4♦3♠

Two Pair 

e.g. 8♠8♦7♠7♦2♣

One Pair 

e.g. 9♥9♣6♥5♦2♣

High Card

e.g. A♥K♣10♥2♦3♣ is an ace-high combination, and 7♥6♣5♥4♦2♣ is a seven-high combination.

Special implementation

When any player does not have enough chips to pay for the blind or continue the game, the game will ask whether players would like to join the minigame.

Minigame

The minigame is a guessing game. The computer will randomly draw a card from a brand-new deck (52 cards). Players have to make the decision to guess whether the next card is Smaller (press s), Larger (press l), or The Same (press t). If players make the correct guess, they can get chips according to the odds. Otherwise, players could still get 30BB to continue the game.

Functions in the project:
1. Main.cpp : a collection of functions including save game and game initialization input interface. There is while loop to handle every round of the game (Program codes in multiple files).
2. Structure.h: circular linked list (dynamic memory management)
3. Insert.cpp: building up the circular linked list
4. Drawcard.cpp: generate a random card (random event)
5. Output. cpp: output community and hand cards
6. Action.cpp: run through the circular linked list , handle every action in fore turn
7. Terminate.cpp: skipping turns once only the player can have action
8. Checkwin.cpp: use of vector and map (stl container), using value to determine who has the best hand and distribute chips.
9. Loadsave. cpp: file input and output.
10. minigame.cpp: the implementation of minigame, to check whether players are having enough chips to continue the game. Also, to calculate the odds in minigame.
(All the files have documentation and proper indentation.)






   
