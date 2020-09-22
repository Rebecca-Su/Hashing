#include "open.h"

//default constructor for Data object 
Data::Data()
{
	key = -1;
	caller = "";
	status = "empty";
}

//constructor for Data to set member variables
Data::Data(long in_key, string in_caller, string in_status)
{
	key = in_key;
	caller = in_caller;
	status = in_status;
}

//creates a hash table based on input size
void DoubleHashing::createTable(long in_size)
{
	vector<Data> ht;
	ht.resize(in_size - 1);
    hash_table = ht;
    size = in_size;
}

//inserts a new Data object
bool DoubleHashing::insert(long in_key, std::string in_caller)
{
    if(in_key < 0)
	    return false;

    int place = in_key % size;
    int offset = (in_key/size) % size;
	int first_del = -1;    
	Data data(in_key, in_caller, "full");
   
	if(offset % 2 == 0)
        offset = offset + 1;
  
    while(hash_table[place].status != "empty")
    {  
		if(hash_table[place].status == "deleted" && first_del == -1)
			first_del = place;
		if(hash_table[place].key == in_key) 
 			return false;

 		place = (place + offset) % size;

		if((place == in_key % size) && (first_del == -1))
	 		return false;
		else if(place == in_key % size)
			break;
    }

    if(first_del != -1)
		hash_table[first_del] = data; 

    hash_table[place] = data;
  
    return true;
}

//searches for the object based on input key
Data DoubleHashing::search(long in_key)
{
    Data data(-1, "", "search result");
    int place = in_key % size;
    int offset = (in_key/size) % size;
  
    if(offset % 2 == 0)
        offset = offset + 1;
    
    while(hash_table[place].status != "empty")
    {
        if(hash_table[place].key == in_key)
        {
            data.key = place;
        	data.caller = hash_table[place].caller;
			break;
        }
        place = (place + offset) % size;
        if(place == in_key % size)
            break;
    }
    
    return data;
}

//deletes the object correlated to the input key
bool DoubleHashing::del(long in_key)
{
    int place = in_key % size;
    int offset = (in_key/size) % size;
    
    if(offset % 2 == 0)
        offset = offset + 1;
    
    while(hash_table[place].status != "empty")
    {
        if(hash_table[place].key == in_key)
        {
			Data data(-1, "", "deleted");
			hash_table[place] = data;
            return true;
        }
        place = (place + offset) % size;
        if(place == in_key % size)
            return false;
    }
    return false;
}
