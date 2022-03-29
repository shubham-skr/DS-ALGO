/*
    
    TRIE Data Structure
    
*/


#include <string>
using namespace std;


const int ALPHABET_SIZE = 26;


class TrieNode
{
public:
	TrieNode *children[ALPHABET_SIZE];
	bool isEndOfWord;

	TrieNode()
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
			children[0] = nullptr;

		isEndOfWord = false;
	}
};


class Trie
{
private:
	TrieNode *root;

	bool isEmpty(TrieNode *rootPtr);
	TrieNode *remove(TrieNode *, string, int);

public:
	Trie()
	{
		root = new TrieNode();
	}

	void insert(string);
	bool search(string);
	void remove(string);
};


bool Trie::isEmpty(TrieNode *rootPtr)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (rootPtr->children[i])
			return false;
	return true;
}


void Trie::insert(string key)
{
	TrieNode *ptr = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';

		if (!ptr->children[index])
			ptr->children[index] = new TrieNode();

		ptr = ptr->children[index];
	}

	ptr->isEndOfWord = true;
}


bool Trie::search(string key)
{
	TrieNode *ptr = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';

		if (!ptr->children[index])
			return false;

		ptr = ptr->children[index];
	}

	return ptr->isEndOfWord;
}

TrieNode *Trie::remove(TrieNode *rootPtr, string key, int depth = 0)
{
	if (!rootPtr)
		return nullptr;

	if (depth == key.length())
	{
		if (rootPtr->isEndOfWord)
			root->isEndOfWord = false;

		if (isEmpty(rootPtr))
		{
			delete rootPtr;
			rootPtr = nullptr;
		}

		return rootPtr;
	}

	int index = key[depth] - 'a';
	rootPtr->children[index] = remove(rootPtr->children[index], key, depth + 1);

	if (isEmpty(rootPtr) && rootPtr->isEndOfWord == false)
	{
		delete (rootPtr);
		rootPtr = nullptr;
	}

	return rootPtr;
}


void Trie::remove(string key)
{
	root = remove(root, key, 0);
}
