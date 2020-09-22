#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stol;
using std::getline;

struct Data
{
    long key;
    string caller;
	string status;
	Data();
	Data(long in_key, string in_caller, string in_status);
};

class DoubleHashing
{
public:
    void createTable(long in_size);
    bool insert(long in_key, string in_caller);
    Data search(long in_key);
    bool del(long in_key);
private:
    vector<Data> hash_table;
    long size;
};
