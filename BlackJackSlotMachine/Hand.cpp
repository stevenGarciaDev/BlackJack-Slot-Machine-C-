#include "Hand.h"

#include <iostream>

using namespace std;

Hand::Hand(){
	this->numberOfCards = 0;
	this->valueOfCards = 0;
	this->cardMemoryCapacity = 10;
	this->cards = new Card[cardMemoryCapacity];
}
Hand::Hand(Card& _card){
	this->numberOfCards = 1;
	this->valueOfCards = _card.getValue();
	this->cardMemoryCapacity = 10;
	this->cards = new Card[cardMemoryCapacity];
	addCard(_card);
}

void Hand::addCard(Card& newCard){
	// ensure have enough memory in dynamic array
	if(this->numberOfCards < this->cardMemoryCapacity){
    	*(cards + numberOfCards + 1) = newCard;
    	if(newCard.getCardType() == "Ace"){
    		// Checks the value that a new Ace should be: 1 (default), or 11
    		if(this->valueOfCards + 11 == 21)
    			setValueOfCards(this->valueOfCards + 11);
		}
		else{
			setValueOfCards(this->valueOfCards + newCard.getValue());
		}
    	this->numberOfCards++;
	}
	else{
        // allocate internal memory
        allocateDynamicMemory();
		cout << "Card Memory Capacity exceeded. Unable to add new card. " << endl;
	}
}

int Hand::getValueOfCards(){
	return this->valueOfCards;
}
void Hand::setValueOfCards(int value){
	this->valueOfCards = value;
}
int Hand::getNumberOfCards() const{
	return this->numberOfCards;
}

void Hand::allocateDynamicMemory() {
    cardMemoryCapacity *= 2;
    Card* newCardPtr = new Card[cardMemoryCapacity];
    
    for (int i = 0; i < numberOfCards; i++) {
        *(newCardPtr + i) = cards[i];
    }
    
    delete cards;
    cards = newCardPtr;
}

