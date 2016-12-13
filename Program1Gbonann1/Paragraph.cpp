#include <iostream>
#include <stdlib.h>
#include "Paragraph.h"

using namespace std;

Paragraph::Paragraph(){
	cout << "Called Paragraph::Paragraph()" << endl;
}

Paragraph::Paragraph(const Paragraph &p2) {
 	cout << "Called Paragraph::Paragraph(p2)" << endl;
	numItems = p2.numItems;
	capacity = p2.capacity;
	Node *deepCopy;
	Node *temp = p2.sPointer;
	deepCopy = new Node(*temp);
	while (NULL != temp){
		deepCopy->next = new Node(*temp); //copy child node
		temp = temp->next; //iterate to next child
		deepCopy = deepCopy->next; //iterate to next node to copy to 
	}
	sPointer = deepCopy;
}

Paragraph::Paragraph(int maxSize){
	numItems = 0;
	capacity = maxSize;
	sPointer = new Node();
}

Paragraph::~Paragraph(){
	cout << "Called Paragraph::~Paragraph()" << endl;
}

void Paragraph::Show(){
	cout << "Called Paragraph::Show()" << endl;
}

Story Paragraph::operator+(const Story& arg) const {
	cout << "Called Paragraph::operator+(Story)" << endl;
	Story newStory(arg);
	//Story::Node *temp;
	//temp->data = this->sPointer;
	//temp->next = arg.pPointer->data; 
	return newStory;
}

Paragraph Paragraph::operator+(const Paragraph& arg) const {
	cout << "Called Paragraph::operator+(Paragraph)" << endl;
	Paragraph newP; //seg faults here something wrong with constructor
	Node *temp1;
	newP.sPointer = this->sPointer;
	temp1 = newP.sPointer;
	while (newP.sPointer->hasNext()){ //iterate to last node in this
			temp1 = newP.sPointer->next; 
		}
	temp1->next = arg.sPointer; //set last pointer equal to first node of arg
	return newP;
	
}

Paragraph Paragraph::operator+(Sentence& arg) {
	cout << "Called Paragraph::operator+(Sentence)" << endl;
	Paragraph newP(*this);
	newP.numItems++;
	Node *temp1;
	temp1 = newP.sPointer; 
	while (newP.sPointer->hasNext()){
		temp1 = newP.sPointer->next; 
	}
	Node *temp;
	temp->data = &arg;
	temp->next = NULL;
	temp1->setNext(temp);
	return newP; 
	
}

Paragraph Paragraph::operator+(const int& arg) const{
	cout << "Called Paragraph::operator+(int)" << endl;
	Paragraph newP(*this);
	if (arg == 1){
		newP.sPointer->data + 1;
	}
	else {
	}
	return newP;
}

Paragraph Paragraph::operator++(){
	cout << "Called Paragraph::operator++" << endl;
	Paragraph newP(*this);
	Node *temp1;
	temp1 = newP.sPointer;
	while (newP.sPointer->hasNext()){
		temp1 = newP.sPointer->next;	
		temp1->data = ++temp1->data;
	}
	temp1->data = ++temp1->data;
	return newP;
}

Paragraph Paragraph::operator++(int arg){
	cout << "Called Paragraph::operator++(int)" << endl;
	Paragraph newP(*this); 
	Node *temp1;
	temp1 = newP.sPointer;
	while (newP.sPointer->hasNext()){
		temp1 = newP.sPointer->next;	
		temp1->data++;
	}
	temp1->data++;
	return newP;
}

Paragraph Paragraph::operator--(){
	cout << "Called Paragraph::operator--" << endl;
	Paragraph newP(*this);
	Node *temp1;
	temp1 = newP.sPointer;
	while (newP.sPointer->hasNext()){
		temp1 = newP.sPointer->next;	
		temp1->data = --temp1->data;
	}
	temp1->data = --temp1->data;
	return newP;
}

Paragraph Paragraph::operator--(int arg) {
	cout << "Called Paragraph::operator--(int)" << endl;
	Paragraph newP(*this); 
	Node *temp1;
	temp1 = newP.sPointer;
	while (newP.sPointer->hasNext()){
		temp1 = newP.sPointer->next;	
		temp1->data--;
	}
	temp1->data--;
	return newP;	
}	

ostream & operator<<(ostream &out, const Paragraph &p){
	cout << "Called Paragraph::operator<<" << endl;
	Paragraph smallerParagraph = p;
	if (smallerParagraph.numItems == 1){
		cout << smallerParagraph.first();
	}
	while (smallerParagraph.rest().numItems > 0){
		cout << smallerParagraph.first();
		smallerParagraph = smallerParagraph.rest();		
	}	
}

Sentence Paragraph::first(){
	cout << "Called Paragraph::first()" << endl;
	Sentence newSentence(*this->sPointer->data);
	return newSentence;
}

Paragraph Paragraph::rest(){
	cout << "Called Paragraph::rest()" << endl;
	Paragraph newP(*this);
	Node *temp = newP.sPointer;
	newP.sPointer = newP.sPointer->next;
	//remove first sentence, delete first node
	delete temp;
	return newP;
}
