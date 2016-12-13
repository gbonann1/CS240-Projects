#ifndef _Sentence_H
#define _Sentence_H
class Word;
class Paragraph;
#include "Word.h"
#include "Paragraph.h"
#include <iostream>

using namespace std;

class Sentence
{
	private:
		class Node
		{
			public:
				Word *data; 
				Node *next;
				Node(){
				}
				Node(const Node& orig) {
				next = orig.next;
				data = orig.data;
				}
				~Node() {
				}

				bool hasNext(){
				    if (next != NULL)
					return true;
				    else
					return false;
				}

				void setNext(Node* newNext){
				    if(newNext == NULL)
					next = NULL;
				    else
					next = newNext;
				}
		};	
		Node *wPointer;
		int numItems;
		int capacity; 
		
	public:
		Sentence();
		Sentence(const Sentence &s2);
		Sentence(Word &w1);
		Sentence(int maxSize);
		~Sentence();
		void Show();
		//Node getwPointer();
		Paragraph operator+(const Paragraph& arg) const;
		Paragraph operator+(Sentence& arg);
		Sentence operator+(Word& arg);
		Sentence operator+(const int& arg) const;
		Sentence operator++();	
		Sentence operator++(int arg);
		Sentence operator--();
		Sentence operator--(int arg);
		friend ostream & operator<<(ostream &out, const Sentence &s);
		Word first(); 
		Sentence rest();
		
};


#endif // _Sentence_H

