#include <iostream>
#include <stdlib.h>
#include "Story.h"
#include <fstream>

using namespace std;

Story::Story(){
	cout << "Called Story::Story()" << endl;
}

Story::Story(const Story &s2) {
  	cout << "Called Story::Story(s2)" << endl;
	numItems = s2.numItems;
	capacity = s2.capacity;
	Node *deepCopy;
	Node *temp = s2.pPointer;
	deepCopy = new Node(*temp);
	while (NULL != temp){
		deepCopy->next = new Node(*temp); //copy child node
		temp = temp->next; //iterate to next child
		deepCopy = deepCopy->next; //iterate to next node to copy to 
	}
	pPointer = deepCopy;
}

Story::Story(int maxSize){
	numItems = 0;
	capacity = maxSize;
	pPointer = new Node();
}

Story::Story(int maxSize, char array[]){
	capacity = maxSize;
	numItems = maxSize;
	pPointer = new Node();
	char tempArray[26];
	Paragraph pBuild;
	Sentence sBuild;
	int startIndex = 0;
	int wordSize = 0;
	for (int i = 0; i < 10000; i++){ //10,000 max # of characters to read in
		wordSize++;
		if (array[i] = ' '){
			for (int j = 0; j < wordSize; j++){
				tempArray[j] = array[startIndex + j];
			}
			Word w1(wordSize, tempArray);
			sBuild + w1; //relies on Sentence + Word which doesn't work.. seg faults here
			startIndex += wordSize;			
			wordSize = 0;
		}
		else if (array[i] == '.' || array[i] == '!' || array[i] == '?'){
			pBuild + sBuild;
			Sentence s1;
			sBuild = s1;
		}
		else if (array[i] == '\n' && array[i+1] == '\t'){
			numItems++;
			Node *temp;
			temp = pPointer;
			for (int j = 1; j < numItems; j++){
				temp = temp->next;
				
			}
			temp->data = &pBuild;
			Paragraph p1;
			pBuild = p1;		
		}	
	}		
}

char* Story::Read(){
	ifstream readFile;
	readFile.open("Story.txt");
	char fileArray[10000];  //10,000 max # of characters to read in
	for (int i = 0; i < 10000; i++){
		if (!readFile.eof()){
			readFile >> noskipws >> fileArray[i];
		}
	}
	readFile.close();
	return fileArray;
	
	
}
Story::~Story(){
	cout << "Called Story::~Story()" << endl;
}

void Story::Show(){
	cout << "Called Story::Show()" << endl;
}

Story Story::operator+(const Story& arg) const {
	cout << "Called Story::operator+(Story)" << endl;
	Story newStory; //same code as para + para but doesn't seg fault??
	Node *temp1;
	newStory.pPointer = this->pPointer;
	temp1 = newStory.pPointer;
	while (newStory.pPointer->hasNext()){ //iterate to last node in this
			temp1 = newStory.pPointer->next; 
		}
	temp1->next = arg.pPointer; //set last pointer equal to first node of arg
	return newStory;
}

Story Story::operator+(Paragraph& arg){
	cout << "Called Story::operator+(Paragraph)" << endl;
	Story newStory(*this);
	newStory.numItems++;
	Node *temp1;
	temp1 = newStory.pPointer; 
	while (newStory.pPointer->hasNext()){
		temp1 = newStory.pPointer->next; 
	}
	Node *temp;
	temp->data = &arg;
	temp->next = NULL;
	temp1->setNext(temp);
	return newStory; 
}

Story Story::operator+(const int& arg) const{
	cout << "Called Story::operator+(int)" << endl;
	Story newStory(*this);
	if (arg == 1){
		newStory.pPointer->data + 1;
	}
	else {
	}
	return newStory;
}

Story Story::operator++(){
	cout << "Called Story::operator++" << endl;
	Story newStory(*this);
	Node *temp1;
	temp1 = newStory.pPointer;
	while (newStory.pPointer->hasNext()){
		temp1 = newStory.pPointer->next;	
		temp1->data = ++temp1->data;
	}
	temp1->data = ++temp1->data;
	return newStory;
}

Story Story::operator++(int arg){
	cout << "Called Story::operator++(int)" << endl;
	Story newStory(*this); 
	Node *temp1;
	temp1 = newStory.pPointer;
	while (newStory.pPointer->hasNext()){
		temp1 = newStory.pPointer->next;	
		temp1->data++;
	}
	temp1->data++;
	return newStory;
}

Story Story::operator--(){
	cout << "Called Story::operator--" << endl;
	Story newStory(*this);
	Node *temp1;
	temp1 = newStory.pPointer;
	while (newStory.pPointer->hasNext()){
		temp1 = newStory.pPointer->next;	
		temp1->data = --temp1->data;
	}
	temp1->data = --temp1->data;
	return newStory;
}

Story Story::operator--(int arg) {
	cout << "Called Story::operator--(int)" << endl;
	Story newStory(*this); 
	Node *temp1;
	temp1 = newStory.pPointer;
	while (newStory.pPointer->hasNext()){
		temp1 = newStory.pPointer->next;	
		temp1->data--;
	}
	temp1->data--;
	return newStory;
}	

ostream & operator<<(ostream &out, const Story &s){
	cout << "Called Story::operator<<" << endl;
	Story smallerStory = s;
	if (smallerStory.numItems == 1){
		cout << smallerStory.first();
	}
	while (smallerStory.rest().numItems > 0){
		cout << smallerStory.first();
		smallerStory = smallerStory.rest();		
	}
}

Paragraph Story::first(){
	cout << "Called Story::first()" << endl;
	Paragraph newP(*this->pPointer->data);
	return newP;
}

Story Story::rest(){
	cout << "Called Story::rest()" << endl;
	Story newStory(*this);
	Node *temp = newStory.pPointer;
	newStory.pPointer = newStory.pPointer->next;
	//remove first sentence, delete first node
	delete temp;
	return newStory;
}
