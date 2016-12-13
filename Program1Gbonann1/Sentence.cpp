#include <iostream>
#include <stdlib.h>
#include "Sentence.h"

using namespace std;

Sentence::Sentence(){
	cout << "Called Sentence::Sentence()" << endl;
}

Sentence::Sentence(const Sentence &s2) { //seg faults when you try to copy an empty sentence
  	cout << "Called Sentence::Sentence(s2)" << endl;
	cout << "please work";
	if (NULL != s2.numItems){
		numItems = s2.numItems;
		capacity = s2.capacity;
		Node *deepCopy;
		Node *temp = s2.wPointer;
		deepCopy = new Node(*temp);
	
		while (NULL != temp){
			deepCopy->next = new Node(*temp); //copy child node
			temp = temp->next; //iterate to next child
			deepCopy = deepCopy->next; //iterate to next node to copy to 
		}
		wPointer = deepCopy;
	}	
}
Sentence::Sentence(Word &w1) {
	cout << "Called Sentence::Sentence(w1)" << endl;
	numItems = 1;
	capacity = 1;
	wPointer = new Node();
	wPointer->data = &w1;
	wPointer->next = NULL;
	
}

Sentence::Sentence(int maxSize){
	cout << "Called Sentence::Sentence(int)" << endl;
	numItems = 0;
	capacity = maxSize;
	wPointer = new Node(); 
}

Sentence::~Sentence(){
	cout << "Called Sentence::~Sentence()" << endl;
}

void Sentence::Show(){
	cout << "Called Sentence::Show()" << endl;
	Node *temp;
	temp = this->wPointer;
	temp->data->Show();
	if (this->wPointer->hasNext()){
		temp = temp->next;	
		temp->data->Show(); 
	}
}
/**
Sentence::Node Sentence::getwPointer(){
	return *wPointer;
}
**/

Paragraph Sentence::operator+(const Paragraph& arg) const {
	cout << "Called Sentence::operator+(Paragraph)" << endl;
	Paragraph newParagraph(arg);
	//Paragraph::Node *temp; //can't do this bc its private
	//temp->data = this->wPointer;
	//temp->next = newParagraph.sPointer->data;
	return newParagraph;
}

Paragraph Sentence::operator+(Sentence& arg) {
	cout << "Called Sentence::operator+(Sentence)" << endl;
	Paragraph newParagraph(2);
	//newParagraph.sPointer->data = this; //cant access paragraph class from here
	//newParagraph.sPointer->next->data = &arg; //getter function creates even more problems.
	//newParagraph  + this;
	newParagraph  + arg;
	return newParagraph;
}

Sentence Sentence::operator+(Word& arg){
	cout << "Called Sentence::operator+(Word)" << endl;
	if (NULL != this->wPointer->data){\
		Sentence newSentence(*this); //trying to add to an empty sentence causes seg fault
		newSentence.numItems++;
		Node *temp1;
		temp1 = newSentence.wPointer; 
		while (newSentence.wPointer->hasNext()){
			temp1 = newSentence.wPointer->next; 
		}
		Node *temp;
		temp->data = &arg;
		temp->next = NULL;
		temp1->setNext(temp);
		return newSentence; 
	}
	else {
		Sentence newSentence(arg);
		return newSentence; 
	}
	
}

Sentence Sentence::operator+(const int& arg) const{
	cout << "Called Sentence::operator+(int)" << endl;
	Sentence newSentence(*this);
	if (arg == 1){
		newSentence.wPointer->data + 1;
	}
	else {
	}
	return newSentence;
}

Sentence Sentence::operator++(){
	cout << "Called Sentence::operator++" << endl;
	Sentence newSentence(*this);
	Node *temp1;
	temp1 = newSentence.wPointer;
	while (newSentence.wPointer->hasNext()){
		temp1 = newSentence.wPointer->next;	
		++temp1->data;
	}
	temp1->data = ++temp1->data;
	return newSentence;
}

Sentence Sentence::operator++(int arg){
	cout << "Called Sentence::operator++(int)" << endl;
	Sentence newSentence(*this); 
	Node *temp1;
	temp1 = newSentence.wPointer;
	while (newSentence.wPointer->hasNext()){
		temp1 = newSentence.wPointer->next;	
		temp1->data = ++temp1->data;
	}
	temp1->data++;
	return newSentence;
}
	
Sentence Sentence::operator--(){
	cout << "Called Sentence::operator--" << endl;
	Sentence newSentence(*this);
	Node *temp1;
	temp1 = newSentence.wPointer;
	while (newSentence.wPointer->hasNext()){
		temp1 = newSentence.wPointer->next;	
		temp1->data = --temp1->data;
	}
	temp1->data = --temp1->data;
	return newSentence;
}
	
Sentence Sentence::operator--(int arg) {
	cout << "Called Sentence::operator--(int)" << endl;
	Sentence newSentence(*this);
	Node *temp1;
	temp1 = newSentence.wPointer;
	while (newSentence.wPointer->hasNext()){
		temp1 = newSentence.wPointer->next;	
		temp1->data--;
	}
	temp1->data--;
	return newSentence;
}

ostream & operator<<(ostream &out, const Sentence &s){
	cout << "Called Sentence::operator<<" << endl;	
	Sentence smallerSentence = s;
	if (smallerSentence.numItems == 1){
		cout << smallerSentence.first();
	}
	while (smallerSentence.rest().numItems > 0){
		cout << smallerSentence.first();
		smallerSentence = smallerSentence.rest();		
	}	
}

Word Sentence::first(){
	cout << "Called Sentence::first()" << endl;
	Word newWord(*this->wPointer->data);
	return newWord;
}

Sentence Sentence::rest(){
	cout << "Called Sentence::rest()" << endl;
	Sentence newSentence(*this);
	newSentence.numItems--;
	Node *temp = newSentence.wPointer;
	newSentence.wPointer = newSentence.wPointer->next;
	//remove first word, delete first node
	delete temp;
	return newSentence;
}
