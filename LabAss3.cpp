#include "dictionary"

/*
	Author: Da Costa, Francisco
	Student ID: 5026516
*/

DICT dictionary = {MAX,0,0};
WORD word;

int main(void){
	
	int i = 1;
	ENTRY *found; 
	while(1){
		word = GetNextWord();
		
		if("" == word){
			DumpDictionary(dictionary);
			break;
		}
		if((found = LocateWord(dictionary,word)) != 0){
			(*found).count++;
		}
		else
			if(!InsertWord(dictionary, word))
				cout << "The dictionary is full the word \"" << word
				<< "\" cannot be added." << endl;

	}
	return 0;

}

