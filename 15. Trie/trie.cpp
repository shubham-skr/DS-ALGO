/*

TRIE Data Structure

- efficient information reTrieval data structure
- searching a key takes O(N) time where N is key length

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

public:
	Trie()
	{
		root = new TrieNode();
	}

	void insert(string);
	bool search(string);
};


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
