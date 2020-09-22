#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stol;

struct Data
{
    long key;
    string caller;
    Data* p_next;
};

class ChainedHashing
{
public:
    void createTable(long in_size);
    bool insert(long in_key, string in_caller);
    Data search(long in_key);
    bool del(long in_key);
    void print(long in_pos);
    ~ChainedHashing();
private:
    vector<Data*> hash_table;
    long size;
};
