all: proj3.exe

proj3.exe: ColorClass.o RowColumnClass.o ColorImageClass.o constants.h \
		   Rectangle.o AnnotationPattern.o cinOneString.o readOneInt.o \
		   cinTwoInt.o cinOneInt.o main.o 
	g++ -g -Wall ColorClass.o RowColumnClass.o ColorImageClass.o Rectangle.o \
				 AnnotationPattern.o cinOneString.o readOneInt.o cinTwoInt.o \
				 cinOneInt.o main.o -o proj3.exe

ColorClass.o: ColorClass.h constants.h ColorClass.cpp
	g++ -c -g -Wall ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.h constants.h RowColumnClass.cpp
	g++ -c -g -Wall RowColumnClass.cpp -o RowColumnClass.o
ColorImageClass.o: ColorImageClass.h constants.h ColorImageClass.cpp
	g++ -c -g -Wall ColorImageClass.cpp -o ColorImageClass.o
AnnotationPattern.o: AnnotationPattern.h constants.h AnnotationPattern.cpp
	g++ -c -g -Wall AnnotationPattern.cpp -o AnnotationPattern.o
Rectangle.o: Rectangle.h constants.h Rectangle.cpp
	g++ -c -g -Wall Rectangle.cpp -o Rectangle.o
cinOneInt.o: cinOneInt.h cinOneInt.cpp
	g++ -c -g -Wall	cinOneInt.cpp -o cinOneInt.o
cinOneString.o: cinOneString.h cinOneString.cpp	
	g++ -c -g -Wall cinOneString.cpp -o cinOneString.o
readOneInt.o: readOneInt.h readOneInt.cpp
	g++ -c -g -Wall readOneInt.cpp -o readOneInt.o
cinTwoInt.o: cinTwoInt.h cinTwoInt.cpp
	g++ -c -g -Wall cinTwoInt.cpp -o cinTwoInt.o

main.o: ColorClass.h RowColumnClass.h ColorImageClass.h constants.h \
		Rectangle.h AnnotationPattern.h cinOneString.h readOneInt.h \
		cinTwoInt.h cinOneInt.h main.cpp 
	g++ -c -g -Wall main.cpp -o main.o
clean:
	rm -f *.o proj3.exe