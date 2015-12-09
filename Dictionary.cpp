#include "dictionary"

BOOL FullDictionary(DICT &dict)
// Returns a boolean indicating if the dictionary is full.
{
	
	if((dict.numWords == dict.maxEntries)) return 1;
	else return 0;
}

BOOL InsertWord(DICT &dict, WORD inWord)
// Inserts a word into the provided dictionary.
// This is done by changing pointers as
// it's implimentation is via linked lists.
// It returns a boolean to indicate sucess.
{
	
	ENTRY* tmp = new ENTRY;
	(*tmp).count = 1;
	(*tmp).w = inWord;
	(*tmp).nextWord = NULL;

	if(dict.Words == 0)
	{
		dict.Words = tmp;	
	} else 
	{
		(*tmp).nextWord = dict.Words;
		dict.Words = tmp;		
	}

	dict.numWords++;
	return 1;
	
}
	
void Swap(ENTRY *&previous, ENTRY *&current)
// Swaps entry postions in the dictionary.
{

	ENTRY* tmp = new ENTRY;
	(*tmp).w = (*previous).w;
	(*tmp).count = (*previous).count;
	(*previous).w = (*current).w;
	(*previous).count = (*current).count;
	(*current).w = (*tmp).w;
	(*current).count = (*tmp).count;
	

}

void DumpDictionary(DICT &dict)
// Prints the ditionary out a sorted order.
{
	
	ENTRY *tmp = dict.Words;
	ENTRY *tmp2 = (*tmp).nextWord;
	ENTRY *tmp3 = dict.Words;

	for(int i = 1; i < dict.numWords; i++)
	{
		for(int k = 0; k < dict.numWords - i; k++)
		{
			if((*tmp).w > (*tmp2).w)
				Swap(tmp, tmp2);	
		tmp = tmp2;
		tmp2 = (*tmp2).nextWord;
		}
	tmp = dict.Words;
	tmp2 = (*tmp).nextWord;
	}

	cout << "Size of dictionary:	"<< dict.numWords << endl;
	cout << "Words		Count" << endl;
	for(int i = 0; i < dict.numWords; ++i)
	{
		cout << (*tmp3).w;
		for(int j = 0; j < 24 - ((*tmp3).w).length(); j++)
			cout << ' ';
		cout << (*tmp3).count << endl;
		tmp3 = (*tmp3).nextWord;		
	}
}

WORD GetNextWord(void)
// Retrieves the next work from the input stream.
// It does this via an input buffer, and it also
// checks to see if the word fits a critera that
// defines what a word is.
{
	
	WORD tmpWord;
	char buffer[256];
        int curr = 0;
        bool inWord = false;

        while (cin.good()) 
		{
              char ch = cin.get();
              if (isalpha(ch)) 
			  {
                  buffer[curr++] = tolower(ch);
                  inWord = true; 
              } else 
			  {
                   if (inWord) 
				   {
                        buffer[curr] = '\0';
		        return tmpWord = buffer;
                   }
              }
        }
        return "";
}

ENTRY* LocateWord(DICT &dict, WORD wordX)
// Returns a pointer to an entry. This 
// function is used to detect if a word
// entry exists in the dictionary. 
{
	
	ENTRY *tmp = dict.Words;
	
	for(int i = 0;  i < dict.numWords; i++)
	{
		if((*tmp).w == wordX) return tmp;
		else tmp = (*tmp).nextWord;
	}
	return 0;
}
