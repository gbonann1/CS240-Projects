#include <iostream>
#include <stdlib.h>
#include "Word.h"
#include "Sentence.h"

using namespace std;

Word::Word(){
	cout << "Called Word::Word()" << endl;
}

Word::Word(const Word &w2) {
  	cout << "Called Word::Word(w2)" << endl;
	charArray = w2.charArray;
	numItems = w2.numItems;
	capacity = w2.capacity;
}

Word::Word(int maxSize){
	cout << "Called Word::Word(int)" << endl;
	numItems = maxSize;
	capacity = maxSize;
	charArray = new char[capacity];
	charArray[0] = 't';
	charArray[1] = 'e'; //for testing
	charArray[2] = 's';
	charArray[3] = 't';
}

Word::Word(int maxSize, char array[]){
	numItems = maxSize;
	capacity = maxSize;
	charArray = new char[capacity];
	for (int i = 0; i < capacity; i++){
		charArray[i] = array[i];
	}
}

Word::~Word(){
	cout << "Called Word::~Word()" << endl;
}

void Word::Show(){
	cout << "Called Word::Show()" << endl;
	for (int i = 0; i < this->capacity; i++) {
		cout << this->charArray[i] << endl;
	}
}

Sentence Word::operator+(Sentence& arg) {
	cout << "Called Word::operator+(Sentence)" << endl;
	Sentence newSentence(arg);
	//Sentence::Node *temp; //can't do this bc its private
	//temp->data = this;
	//temp->next = newSentence.wPointer->data;
	return newSentence;
}
Sentence Word::operator+(Word& arg) {
	cout << "Called Word::operator+(Word)" << endl;
	Sentence newSentence(2);
	//newSentence.getwPointer()->data = this; //cant access sentence class from here
	//newSentence.getwPointer()->next->data = &arg; //getter function creates even more problems.
	//newSentence + this;
	newSentence + arg;
	return newSentence;
}

Word Word::operator+(const int& arg) const{
	cout << "Called Word::operator+(int)" << endl;
	Word newWord;
	newWord.charArray = this->charArray;
	if (arg == 1){
		newWord.charArray[0] = toupper(this->charArray[0]);
		for (int i = 1; i < this->numItems; i++){
			newWord.charArray[i] = this->charArray[i];
		}
	}
	else {
	}
	return newWord;
}

Word Word::operator++(){
	cout << "Called Word::operator++" << endl;
	if (this->charArray[0] == 'a' || this->charArray[0] == 'e' || this->charArray[0] == 'i' || this->charArray[0] == 'o' || this->charArray[0] == 'u'){
		char newArray[this->capacity + 3];
		for (int i = 0; i < this->capacity; i++){
			newArray[i] = this->charArray[i];
		}
		newArray[this->capacity] = 'w';
		newArray[this->capacity +1] = 'a';
		newArray[this->capacity +2] = 'y';
		Word newWord(this->capacity + 3, newArray);
		return newWord;
	}
	else {
		char newArray[this->capacity + 2];
		for (int i = 0; i < this->capacity - 1; i++){
			newArray[i] = this->charArray[i+1];
		}
		newArray[this->capacity-1] = this->charArray[0];
		newArray[this->capacity] = 'a';
		newArray[this->capacity +1] = 'y';
		Word newWord(this->capacity + 2, newArray);
		return newWord;
	}	
}	

Word Word::operator++(int arg) {
	cout << "Called Word::operator++(int)" << endl;
	Word newWord;
	newWord.charArray = this->charArray;
	for (int i = 0; i < this->numItems; i++){
		newWord.charArray[i] = toupper(this->charArray[i]);
	}
	return newWord;
}

Word Word::operator--(){
	cout << "Called Word::operator--" << endl;
	Word newWord(this->capacity - 2);
	newWord.charArray[0] = this->charArray[capacity - 3];
	for (int i = 1; i < newWord.capacity; i++){
		newWord.charArray[i] = this->charArray[i-1];
		newWord.numItems++;
	}
	return newWord;
}

Word Word::operator--(int arg) {
	cout << "Called Word::operator--(int)" << endl;
	Word newWord;
	newWord.charArray = this->charArray;
	for (int i = 0; i < this->numItems; i++){
		newWord.charArray[i] = tolower(this->charArray[i]);
	}
	return newWord;
}

ostream & operator<<(ostream &out, const Word &w){
	cout << "Called Word::operator<<" << endl;
	for (int i = 0; i < w.numItems; i++) {
		cout << w.charArray[i];
	}
	cout << ' ' << endl;
}
