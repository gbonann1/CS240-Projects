#ifndef _Word_H
#define _Word_H
class Sentence;
#include "Sentence.h"
#include <iostream>

using namespace std;


class Word
{
	private:
		char *charArray;
		int numItems;
		int capacity;
		
	public:
		Word();
		Word(const Word &w2);
		Word(int maxSize);
		Word(int maxSize, char array[]);
		~Word();
		void Show();
		Sentence operator+(Sentence& arg);
		Sentence operator+(Word& arg);
		Word operator+(const int& arg) const;
		Word operator++(); //Pig Latin
		Word operator++(int arg); //Word++	
		Word operator--();
		Word operator--(int arg);	
		friend ostream & operator<<(ostream &out, const Word &w);

};


#endif // _Word_H
