#ifndef HASHMAP_H
#define HASHMAP_H

#define DEFAULT_HASH 1231

class LinkList;
using namespace std;
#include <iostream>

class HashMap {
	/* 
	 * The Hashmap class is used to create a Hashmap with interface to use. Only stores strings and such
	 */
	LinkList * rootNode;
	const int HASH_MOD_VALUE;
	int Hash(string file);
public:
	HashMap(int hashLocCount = DEFAULT_HASH);
	~HashMap();
	bool insert_Word(string fileName, string Path);
	string get_Location(string file);
	bool del_Word(string file);
};

#endif

