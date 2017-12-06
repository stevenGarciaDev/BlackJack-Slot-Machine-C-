//
//  Player.hpp
//  BlackJackSlotMachine
//
//  Created by Steven Garcia on 11/20/17.
//  Copyright © 2017 Steven Garcia. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include "Account.h"
#include "Card.h"

class Player {
    private:
        Account playerAccount;
        Card* cards = nullptr;
        int numberOfCardsInHand;
        int cardMemoryCapacity;
        int valueOfCards;
    
    public:
        Player();
        Player(Account);
        void setAccountNumber(string);
        string getAccountNumber();
        void setNumberOfCardsInHand(int);
        int getNumberOfCardsInHand() const;
        void addCard(Card&);
        int getValueOfCards();
        void stand();
        void hit(Card&);
        void split();
        void winGame();
        void loseGame();
};

#endif /* Player_h */
