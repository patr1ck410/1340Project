************  POKER  ************

This project creates a classical poker game,
where players try to win by 
1. Having the best hand among all in-game players  OR
2. Convincing all other players to fold (quit).

RANKING RULES OF POKER

1. Uses a standard 52-card deck (13 ranks and 4 suits)
   Rank from lowest to highest: 2 3 4 5 6 7 8 9 10 J Q K A
   Suits: Clubs, Diamonds, Hearts, Spades (all suits worth the same)

2. Ranking of hands from highest to lowest:

   Straight Flush (Five consecutive cards of the same suit)
   Four of a Kind (Four cards of the same rank)
   Full House (Three of a Kind and a Pair)
   Flush (Five cards of the same suit, not in sequence)
   Straight (Five consecutive cards of mixed suits)
   Three of a Kind
   Two Pair
   One Pair
   High Card

3. If multiple players have the same rank, the rank is further determined by:
   Pairs, 3 / 4 of a kind:   Primarily the 2/3/4 cards of the same rank, then the rank
                             of the remaining cards, starting from highest ranked card.
   Full House :              Primarily the 3 cards of the same rank, then the pair.
   Straight Flush, Straight: Only the highest ranked card.
   Flush, High Card:         The rank of all cards, starting from highest ranked card.

   If the ranks are totally identical, the poot is split evenly among the tied players.


GAME FLOW

1. Two cards are randomly distributed to EACH player,
   and five cards are randomly distributed to the community cards.
   
2. There are 4 betting rounds, separated by 3 rounds of community cards revelation.
3. The first betting round will be the pre-flop bet, which players action base on the cards in hand but not any     
   community card. In the first betting round, two players are required to pay for the small blind (0.5)
4. In each betting round, the first player has 3 option:
   Check: Not making any bet and pass the turn to the next player
   Bet: Make a bet
   Fold: Quit the bet

   Then for all other players, they have 3 options
   Call: Make the same bet as the current highest bet of the round. If players don't have 
         the enough amount to make a full call, they could choose to all-in to stay in the bet.
   Raise: Raise the bet by betting of atleast 2 times of the previous amount in that round.
   Fold: Quit the bet.
   Check: In case if no one is making a bet yet, a player can pass their turn to another player.

   If a player has make a raise, all other players have to make a decision again to decide whether      to call / raise / fold until all players have decided to call / fold again after the last player     has raised the bet. After that, a betting round will end.
   
   If there are more than one player who didn't fold, the game will continue.
   Otherwise, the only remaining player will win.
   
5. Three community cards are revealed in the first round, another one in the second round, and the last one in the third round which is the final round.
   
6. At the end, all remaining players will show their two hidden cards to determine the winner.
   
   
Calculating Winnings: 

Main Pot: The main pot consists of all bets and raises made by players who have enough chips to cover the full amount of the all-in player's bet. This pot is contested among all players who have contributed to it. The player with the best hand among those who contributed to the main pot wins the main pot.

Side Pot(s): If there are players who have bet or raised beyond the amount of the all-in player's bet, those additional chips create a separate pot called a side pot. Only players who have contributed to the side pot are eligible to win it. 

If there are side pots, the player with the best hand among those who contributed to each side pot wins that side pot. If there are multiple side pots, they are won in descending order of creation (i.e., the first side pot created is won first, then the second, and so on, and this isn't necessarily ordered by the amount).

Remaining Chips: If there are any remaining chips from the all-in player's bet that were not matched by other players, those chips are returned to the all-in player.

Further explanation: https://www.mypokercoaching.com/side-pot-poker/





   
