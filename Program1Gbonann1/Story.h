#ifndef _Story_H
#define _Story_H
class Paragraph;
#include "Paragraph.h"
#include <iostream>

using namespace std;

class Story
{
	private:
		class Node
		{
			public:
				Paragraph *data; 
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
		Node *pPointer;
		int numItems;
		int capacity;
		
	public:
		Story();
		Story(int maxSize);
		Story(const Story &s2);
		Story(int maxSize, char array[]);
		~Story();
		char* Read();
		void Show();
		Story operator+(const Story& arg) const;
		Story operator+(Paragraph& arg);
		Story operator+(const int& arg) const;
		Story operator++();
		Story operator++(int arg);
		Story operator--();
		Story operator--(int arg);
		friend ostream & operator<<(ostream &out, const Story &s); 
		Paragraph first();
		Story rest();
		
};


#endif // _Story_H

