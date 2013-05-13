#include "../headers/HashMap.h"
#include "../headers/LinkedList.h"

HashMap::HashMap(int hashLocCount)	: HASH_MOD_VALUE(hashLocCount)	{
	/*
	 *  This is used to initialize the HashMap and set its HASH value
	 */
	rootNode = new LinkList[hashLocCount];
}

HashMap::~HashMap()	{
	//Just another destructor
	if(rootNode != NULL)	{
		delete [] rootNode;
	}
}

bool HashMap::insert_Word(string fileName , string Path)	{
	//This inserts a word into the hashmap. 
	//The operation done is that the init string is before the ; and the path is after it.
	string finalString = fileName + ";" + Path;
	rootNode[Hash(fileName)].append(finalString);
	return true;
}

int HashMap::Hash(string file)	{
	//A simple hash function.
	int counter = 1;
	int accum = 0;
	int fileLength = file.length();
	for(int i = 0; i < fileLength; i+=2)	{
		accum += file[i] * counter + 1;
		counter++;
	}
	return accum % HASH_MOD_VALUE;
}

string HashMap::get_Location(string fileName)	{
	string temp = rootNode[Hash(fileName)].listContent(fileName);
	if(temp.length() == 0)	{
		return "";
	} else {
		return temp;
	}
}