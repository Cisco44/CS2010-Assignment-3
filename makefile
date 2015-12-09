DicProgram: Dictionary.o LabAss3.o
	g++ Dictionary.o LabAss3.o -o DicProgram

Dictionary.o: dictionary Dictionary.cpp
	g++ -c Dictionary.cpp

main.o: dictionary LabAss3.cpp
	g++ -c LabAss3.cpp

clean:
	rm *.o DicProgram
