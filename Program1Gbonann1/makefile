all: Driver

Driver: Driver.o Story.o Paragraph.o Sentence.o Word.o
	g++ Driver.o Story.o Paragraph.o Sentence.o Word.o -o Driver

Driver.o: Driver.cpp Story.h Paragraph.h Sentence.h Word.h
	g++ -c Driver.cpp -o Driver.o
 
Story.o:Story.cpp 
	g++ -c Story.cpp -o Story.o

Paragraph.o:Paragraph.cpp 
	g++ -c Paragraph.cpp -o Paragraph.o

Sentence.o:Sentence.cpp 
	g++ -c Sentence.cpp -o Sentence.o

Word.o:Word.cpp 
	g++ -c Word.cpp -o Word.o

clean:
	rm -f *.o Driver
