#include "open.h"

int main() {
    string command, param;
    DoubleHashing double_hash;
    string thisLine;
    
    while(!cin.eof())
    {
        getline(cin, thisLine);
        if(thisLine.size() == 0)
            break;
        command = thisLine.substr(0, 1);
        param = thisLine.substr(2, thisLine.size());
 		
 		if(command != "i" && stol(param) < 0)
            continue;

        if(command == "n")
        {
            double_hash.createTable(stol(param));
            cout << "success" << endl;
        }
        
        if(command == "i")
        {
            size_t pos;
            long key = -1;
            string caller = "";

            pos = param.find(";");
            if(pos != string::npos)
            {
                key = stol(param.substr(0, pos));
                caller = param.substr(pos + 1, param.size());
            }
            if(double_hash.insert(key, caller))
                cout << "success" << endl;
            else
                cout << "failure" << endl;
        }
        else if(command == "s")
        {
            Data result = double_hash.search(stol(param));
            if(result.caller == "")
                cout << "not found" << endl;
            else
                cout << "found " << result.caller << " in " << result.key << endl;
        }
        else if(command == "d")
        {
            if(double_hash.del(stol(param)))
                cout << "success" << endl;
            else
                cout << "failure" << endl;
        }
    }
    
    return 0;
}
