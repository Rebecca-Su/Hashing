#include "ordered.h"

//creates a hash table based on input size
void ChainedHashing::createTable(long in_size)
{
	vector<Data*> ht;
    ht.resize(in_size);
	hash_table = ht;
 	size = in_size;
}

//inserts new data object
bool ChainedHashing::insert(long in_key, std::string in_caller)
{
    int place = in_key % size;
	Data* new_node = new Data;
    Data* current = hash_table[place];
 
    new_node->key = in_key;
    new_node->caller = in_caller;
    new_node->p_next = nullptr;

    if(current == nullptr)
    {
        hash_table[place] = new_node;
        return true;
    }
    if(current->key > in_key)
    {
        new_node->p_next = current;
        hash_table[place] = new_node;
        return true;
    }

    while(current != nullptr)
    {
        if(current->key == in_key)
            return false;

        if(current->key < in_key && (current->p_next == nullptr || current->p_next->key > in_key))
        {
            new_node->p_next = current->p_next;
            current->p_next = new_node;
            return true;
        }

        current = current->p_next;
    }

    return false;
}

//searches for the object correlated to the input key
Data ChainedHashing::search(long in_key)
{
    Data data;
    int place = in_key % size;
    Data* current = hash_table[place];
    data.caller = "";

    while(current != nullptr)
    {
        if(current->key == in_key)
        {
            data.key = place;
            data.caller = current->caller;
            break;
        }
        if(current->key > in_key)
            break;
        current = current->p_next;
    }

    return data;
}

//deletes the data object correlated to the input key
bool ChainedHashing::del(long in_key)
{
    int place = in_key % size;
    Data* current = nullptr;

    if(hash_table[place]!= nullptr && hash_table[place]->key == in_key)
    {
        current = hash_table[place];
        hash_table[place] = hash_table[place]->p_next;

        delete current;
        current = nullptr;
        return true;
    }
    else if(hash_table[place]!= nullptr)
        current = hash_table[place];

    while(current != nullptr)
    {
        if(current->p_next != nullptr && current->p_next->key == in_key)
        {
            Data* to_delete = current->p_next;
            current->p_next = current->p_next->p_next;

            delete to_delete;
            to_delete = nullptr;
            return true;
        }
        if(current->key > in_key)
            return false;
        current = current->p_next;
    }
    return false;
}

//destructor to deallocate memories
ChainedHashing::~ChainedHashing()
{
    Data *current = nullptr;
    Data *traverse = nullptr;

    for(Data* data : hash_table)
    {
        current = data;
        while(current != nullptr)
        {
            traverse = current->p_next;
            delete current;
            current = traverse;
        }
    }

    delete current;
    current = nullptr;
    delete traverse;
    traverse = nullptr;
}

//prints all keys in the input position
void ChainedHashing::print(long in_pos)
{
	if(in_pos >= size)
		return;
    Data* current = hash_table[in_pos];

    while(current != nullptr)
    {
        if(current->p_next != nullptr)
            cout << current->key << " ";
        else if(current->p_next == nullptr)
            cout << current->key << endl;

        current = current->p_next;
    }
}
