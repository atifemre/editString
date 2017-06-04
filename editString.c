/*
 ============================================================================
 Name        : String Editing Program
 Author      : atifemre
 Version     :
 Copyright   : 
 Description : The program edits the given string and prints that the new one by removing given number of duplicates
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 3) // if not enough arguments were passed
    {
        puts("Error --- Please Supply a String and a Number to the Program");
        return -1;
    }

    int givenNumber=atoi(argv[1]);

    int dataBase[26]={0}; //Creates a 26 index (# of letters in English alphabet) array as database of the duplicates
    char* stringGiven;
    stringGiven=argv[2];

    int stringLength=strlen(stringGiven);
    char letter=' ';

    int num=0;
    int i=0;

    for(i=0;i<stringLength;i++){ //Scan string and find # of duplicates for each letter

    	num=0;
    	letter=stringGiven[i];

    	if(letter!=' '){
    		if (letter >= 'A' && letter <= 'Z') //Each char mapped to an integer and they turned out database indexes for simplicty.
    		  num = letter - 'A';
    		else if (letter >= 'a' && letter <= 'z')
    		  num = letter - 'a';

    		dataBase[num]++;
    	}
    }

    int count=0;
    int newIndex=0;

    for(i=0;i<stringLength;i++){ //scan database and string at the sametime and construct new one by removing unwanted letters, 
                                //overrite the new string on the givenString by doing so no need to allocate new string
    	num=0;
    	letter=stringGiven[i];

    	if(letter!=' '){
    		if (letter >= 'A' && letter <= 'Z')
    			num = letter - 'A';
    		else if (letter >= 'a' && letter <= 'z')
    			num = letter - 'a';

    		count=dataBase[num];

    		if(dataBase[num]<givenNumber){

    		stringGiven[newIndex]=stringGiven[i];
    		newIndex++;
    		}
    	}else {
    		stringGiven[newIndex]=stringGiven[i];
    		newIndex++;

    	}
    }

    stringGiven[newIndex]='\0';

    printf("New String: %s\n", stringGiven);

    return 0;
}




