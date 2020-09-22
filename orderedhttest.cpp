#include "ordered.h"

int main() {
    string command, param;
    ChainedHashing chained_hash;
    string thisLine;
    
    while(!cin.eof())
    {
        getline(cin, thisLine);
        if(thisLine.size() == 0)
            break;
        command = thisLine.substr(0, 1);
        param = thisLine.substr(2, thisLine.size());
        
        if(command == "n")
        {
            chained_hash.createTable(stol(param));
            cout << "success" << endl;
        }
        
        if(command == "i")
        {
            size_t pos;
            string caller = "";
            long key = -1;
            
            pos = param.find(";");
            if(pos != string::npos)
            {
                key = stol(param.substr(0, pos));
                caller = param.substr(pos + 1, param.size());
            }
            if(chained_hash.insert(key, caller))
                cout << "success" << endl;
            else
                cout << "failure" << endl;
        }
        else if(command == "s")
        {
            Data result = chained_hash.search(stol(param));
            if(result.caller == "")
                cout << "not found" << endl;
            else
                cout << "found " << result.caller << " in " << result.key << endl;
        }
        else if(command == "d")
        {
            if(chained_hash.del(stol(param)))
                cout << "success" << endl;
            else
                cout << "failure" << endl;
        }
        else if(command == "p")
            chained_hash.print(stol(param));
    }
    
    return 0;
}
