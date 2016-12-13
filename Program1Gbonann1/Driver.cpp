#include <iostream>
#include <stdlib.h>
#include "Word.h"
#include "Sentence.h"
#include "Paragraph.h"
#include "Story.h"

using namespace std;

int main(){
	//copy constructor seg faults when you pass it an empty sentence/para/story
	//the Sentence + Word etc. rely on the copy constructor working
	//reading in from the text file relies on Sentence + Word etc.
	//not sure how to test since I can't fill the sentence linked list
	//Story s1;
	//Story s2(10, s1.Read()); //to read in from file
	Word w1(4);
	Word w2 = ++w1;
	cout << w2;
	Word w3 = --w2;
	cout << w3;
	Sentence s1;
	//Sentence s2(s1);
	Word w4(w1);
	w4++;
	cout << w4;
	w4--;
	cout << w4;
	//Paragraph p1, p2;
	//p1 + p2;
	Story st1, st2;
	st1 + st2;
	//s1 + w1;
	//s1 = s1 + w1;
	//s1 + w1;
	//cout << s1;
	//s1 ++;
	//cout << s1.first(); 
	//cout << s1.rest();
	//p1.first();
	//s1.Show();
	/**
	Word w1, w2, w3, w4, w5(w4), w6=w5;
	Sentence s1, s2, s3, s4;// s5(s4), s6=s5;
	Paragraph p1, p2;// p3(p2), p4=p3;
	Story st1, st2;// st3(st2), st4=st3;
	w1++;
	w1--;
	--w1;
	++w1;
	s1++;
	s1--;
	++s1;
	--s1;
	s1 = w1 + w2 + w3; 
	s2 = w2 + w4;
	p1 = (s1 + s2); 
	st1 = st1 + p2 + ((p1 + p1 + p1) + 1);
	**/
	

}
