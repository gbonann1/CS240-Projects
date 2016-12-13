#ifndef _Paragraph_H
#define _Paragraph_H
class Sentence;
class Story;
#include "Sentence.h"
#include "Story.h"
#include <iostream>

using namespace std;

class Paragraph
{
	private:
		class Node
		{
			public:
				Sentence *data;
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

				Node* getNext(){
				    return next;
				}

				void setNext(Node* newNext){
				    if(newNext == NULL)
					next = NULL;
				    else
					next = newNext;
				}
		};
		Node *sPointer;
		int numItems;
		int capacity;
		
	public:
		Paragraph();
		Paragraph(const Paragraph &p2);
		Paragraph(int maxSize);
		~Paragraph();
		void Show();
		Story operator+(const Story& arg) const;
		Paragraph operator+(const Paragraph& arg) const;
		Paragraph operator+(Sentence& arg);
		Paragraph operator+(const int& arg) const;
		Paragraph operator++();	
		Paragraph operator++(int arg);
		Paragraph operator--();	
		Paragraph operator--(int arg);
		friend ostream & operator<<(ostream &out, const Paragraph &p);
		Sentence first(); 
		Paragraph rest();
		
};


#endif // _Paragraph_H

