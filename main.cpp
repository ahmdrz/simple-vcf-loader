#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Contact {
    int id;
    string firstname;
    string lastname;
    string mobile;
};

class String
{
    public:
        static bool contains(string input,string s,size_t from = 0,size_t end = string::npos)
        {
            size_t index = input.find(s);
            if (index != std::string::npos)
                if (from <= index && index < end)
                    return true;
            return false;
        }

        static vector<string> &split(const string &s, char delim, vector<string> &elems) {
            stringstream ss(s);
            string item;
            while (getline(ss, item, delim)) {
                elems.push_back(item);
            }
            return elems;
        }

        static vector<string> split(const string &s, char delim) {
            vector<string> elems;
            split(s, delim, elems);
            return elems;
        }

};

class ContactManager {
    private:
        vector<Contact> list;
        int ContactIterator = 0;

        int getIndex(int id) {
            int indexFounded = -1;
            for(unsigned int i=0;i<list.size() && indexFounded < 0;i++)
                if (list.at(i).id == id)
                    indexFounded = i;
            return indexFounded;
        }

    public:
        void sortByID() {
            sort(list.begin(),list.end(),ContactManager::idCompare);
        }

        void sortByFN() {
            sort(list.begin(),list.end(),ContactManager::fnCompare);
        }

        void sortByLN() {
            sort(list.begin(),list.end(),ContactManager::lnCompare);
        }

        void sortByMobile() {
            sort(list.begin(),list.end(),ContactManager::moCompare);
        }

        unsigned int getSize() {
            return list.size();
        }

        int generateID() {
            return ++ContactIterator;
        }

        void add(Contact item)
        {
            list.push_back(item);
        }

        bool remove(int id)
        {
            int indexFounded = getIndex(id);
            if (indexFounded >= 0)
                list.erase(list.begin() + indexFounded);
            else
                return false;
            return true;
        }

        bool contains(int id)
        {
            int indexFounded = -1;
            for(unsigned int i=0;i<list.size() && indexFounded < 0;i++)
                if (list.at(i).id == id)
                    indexFounded = i;
            return indexFounded >= 0;
        }

        Contact getContact(unsigned int index)
        {
            Contact item;
            if (index > list.size())
                return item;
            return list.at(index);
        }

        static bool idCompare(Contact a,Contact b) {
            return a.id > b.id;
        }

        static int fnCompare(Contact a,Contact b) {
            return a.firstname.compare(b.firstname);
        }

        static int lnCompare(Contact a,Contact b) {
            return a.lastname.compare(b.lastname);
        }

        static int moCompare(Contact a,Contact b) {
            return a.mobile.compare(b.mobile);
        }

        ContactManager searchByFirstname(string txt) {
            ContactManager anotherList;
            for (unsigned int i=0;i<list.size();i++)
            {
                Contact item = list.at(i);
                if (String::contains(item.firstname,txt))
                    anotherList.add(item);
            }
            return anotherList;
        }

        ContactManager searchByLastname(string txt) {
            ContactManager anotherList;
            for (unsigned int i=0;i<list.size();i++)
            {
                Contact item = list.at(i);
                if (String::contains(item.lastname,txt))
                    anotherList.add(item);
            }
            return anotherList;
        }

        ContactManager searchByMobile(string txt) {
            ContactManager anotherList;
            for (unsigned int i=0;i<list.size();i++)
            {
                Contact item = list.at(i);
                if (String::contains(item.mobile,txt))
                    anotherList.add(item);
            }
            return anotherList;
        }
};

int main()
{    
    ContactManager manager;

    cout << "Welcome to contact manager." << endl;
    cout << "----------------------------" << endl;

    while(true)
    {
        try
        {
            string query = "";
            cout << "Command > ";
            getline(cin,query);
            size_t index = query.find(';');
            if (index != std::string::npos)
            {
                query = query.substr(0,index);
                vector<string> parts = String::split(query,' ');
                if (parts.size() != 0)
                {
                    string cmd = parts.at(0);
                    if (cmd == string("exit"))
                    {
                        cout << "Bye" << endl;
                        return 0;
                    }
                    else if (cmd == string("help"))
                    {
                        cout << "+----------------------------------+" << endl;
                        cout << "+ save    : export vcf file.       +" << endl;
                        cout << "+ load    : import vcf file.       +" << endl;
                        cout << "+ show    : display all contacts.  +" << endl;
                        cout << "+ add     : add new contact.       +" << endl;
                        cout << "+ remove  : remove contact.        +" << endl;
                        cout << "+ update  : update exists contact. +" << endl;
                        cout << "+ search  : search over contacts.  +" << endl;
                        cout << "+ sort    : sort manually.         +" << endl;
                        cout << "+----------------------------------+" << endl;
                        cout << "+ for more help type man <cmd>     +" << endl;
                        cout << "+----------------------------------+" << endl;
                    }
                    else if (cmd == string("save"))
                    {
                        string filename = "";
                        if(parts.size() > 1)
                            filename = parts.at(1);
                        else
                        {
                            cout << "File > ";
                            cin >> filename;
                        }

                        ofstream output;
                        output.open (filename);
                        for(unsigned int i=0;i<manager.getSize();i++)
                        {
                            Contact item = manager.getContact(i);
                            output << "BEGIN:VCARD\n";
                            output << "VERSION:2.1\n";
                            output << "N:" + item.firstname + ";" + item.lastname + ";;\n";
                            output << "FN:" + item.firstname + " " + item.lastname + "\n";
                            output << "TEL;CELL:" + item.mobile + "\n";
                            output << "END:VCARD\n";
                        }
                        output.close();
                    }
                    else if (cmd == string("load"))
                    {
                        string filename = "";
                        if(parts.size() > 1)
                            filename = parts.at(1);
                        else
                        {
                            cout << "File > ";
                            cin >> filename;
                        }

                        try
                        {
                            ifstream input(filename);
                            bool flagStart = false;

                            Contact item;
                            item.firstname = "";
                            item.lastname = "";
                            item.id = 0;
                            item.mobile = "";

                            int counter = 0;

                            for(string line; getline( input, line );)
                            {
                                if(String::contains(line,"BEGIN:VCARD"))
                                    flagStart = true;

                                if (String::contains(line,"END:VCARD"))
                                {
                                    item.id = manager.generateID();
                                    manager.add(item);
                                    counter++;
                                    flagStart = false;
                                }

                                if (flagStart)
                                {
                                    if (String::contains(line,"N:",0,1))
                                    {
                                        line = line.substr(2);
                                        vector<string> lineSplited = String::split(line,';');

                                        string firstname = "";
                                        string lastname = "";
                                        for (unsigned int i=0;i<lineSplited.size();i++)
                                        {
                                            if (lineSplited.at(i).length() > 1)
                                            {
                                                if (firstname.length() == 0)
                                                    firstname = lineSplited.at(i);
                                                else if (lastname.length() == 0)
                                                    lastname = lineSplited.at(i);
                                            }
                                        }
                                        item.firstname = firstname;
                                        item.lastname = lastname;
                                    }

                                    if (String::contains(line,"TEL;",0,1))
                                    {
                                        size_t indexOf2Dots = line.find(':',5);
                                        if (indexOf2Dots != string::npos)
                                        {
                                            line = line.substr(indexOf2Dots+1);
                                            item.mobile = line;
                                        }
                                    }
                                    else                                    
                                        item.mobile = "-";                                    
                                }
                            }

                            cout << "Command > " << counter << " has been loaded ! " << endl;
                        }
                        catch(exception ex)
                        {
                            cout << ex.what() << endl;
                            exit(EXIT_FAILURE);
                        }
                    }
                    else if (cmd == string("show"))
                    {
                        string mode = "all";
                        if (parts.size() > 1)
                            mode = parts.at(1);
                        else
                        {
                            cout << "Mode > ";
                            cin >> mode;
                        }

                        if (mode == "all")
                        {
                            for(unsigned int i=0;i<manager.getSize();i++)
                            {
                                Contact item = manager.getContact(i);
                                printf("   ------------------------------\n");
                                printf("   - ID        : %-15d- \n",item.id);
                                printf("   - Firstname : %-15s- \n",item.firstname.c_str());
                                printf("   - Lastname  : %-15s- \n",item.lastname.c_str());
                                printf("   - Mobile    : %-15s- \n",item.mobile.c_str());
                                printf("   ------------------------------\n");
                            }
                        }
                    }
                    else if (cmd == string("add"))
                    {
                        Contact item;
                        if (parts.size() > 3)
                        {
                            item.firstname = parts.at(1);
                            item.lastname = parts.at(2);
                            item.mobile = parts.at(3);
                        }
                        else
                        {
                            cout << "Firstname > ";
                            cin >> item.firstname;
                            cout << "Lastname  > ";
                            cin >> item.lastname;
                            cout << "Mobile    > ";
                            cin >> item.mobile;
                        }
                        item.id = manager.generateID();
                        manager.add(item);
                    }
                    else if (cmd == string("remove"))
                    {
                        int id;
                        if (parts.size() > 1) {
                            id = atoi(parts.at(1).c_str());
                        } else {
                            cout << "ID > ";
                            cin >> id;
                        }

                        if (!manager.remove(id))
                            cout << "Error > ID not found ! " << endl;
                        else
                            cout << "Command > index removed ! " << endl;
                    }
                    else if (cmd == string("update"))
                    {
                        int id;
                        if (parts.size() > 1)
                            id = atoi(parts.at(1).c_str());
                        else {
                            cout << "ID > ";
                            cin >> id;
                        }

                        if (manager.remove(id))
                        {
                            Contact item;
                            if (parts.size() > 4)
                            {
                                item.firstname = parts.at(2);
                                item.lastname = parts.at(3);
                                item.mobile = parts.at(4);
                            }
                            else
                            {
                                cout << "Firstname > ";
                                cin >> item.firstname;
                                cout << "Lastname  > ";
                                cin >> item.lastname;
                                cout << "Mobile    > ";
                                cin >> item.mobile;
                            }
                            item.id = manager.generateID();
                            manager.add(item);
                        }
                        else
                            cout << "Error > ID not found !" << endl;
                    }
                    else if (cmd == string("search"))
                    {
                        ContactManager searchList;

                        string mode = "firstname";
                        string key = "";

                        if (parts.size() > 1)
                            mode = parts.at(1);
                        else
                        {
                            cout << "Mode > ";
                            cin >> mode;
                        }

                        if (parts.size() > 2)
                            key = parts.at(2);
                        else
                        {
                            cout << "Key > ";
                            cin >> key;
                        }

                        bool flagSearch = true;

                        if (mode == "firstname") {
                            searchList = manager.searchByFirstname(key);
                        } else if (mode == "lastname") {
                            searchList = manager.searchByLastname(key);
                        } else if (mode == "mobile") {
                            searchList = manager.searchByMobile(key);
                        } else {
                            flagSearch = false;
                        }

                        if (flagSearch)
                        {
                            for(unsigned int i=0;i<searchList.getSize();i++)
                            {
                                Contact item = searchList.getContact(i);
                                printf("   ------------------------------\n");
                                printf("   - ID        : %-15d- \n",item.id);
                                printf("   - Firstname : %-15s- \n",item.firstname.c_str());
                                printf("   - Lastname  : %-15s- \n",item.lastname.c_str());
                                printf("   - Mobile    : %-15s- \n",item.mobile.c_str());
                                printf("   ------------------------------\n");
                            }
                        }
                        else
                            cout << "Error > No mode founded !" << endl;
                    }
                    else if (cmd == string("sort"))
                    {
                        string mode = "id";
                        if (parts.size() > 1)
                            mode = parts.at(1);
                        else
                        {
                            cout << "Mode > ";
                            cin >> mode;
                        }

                        bool flagFound = true;

                        if (mode == "id")
                            manager.sortByID();
                        else if (mode == "firstname")
                            manager.sortByFN();
                        else if (mode == "lastname")
                            manager.sortByLN();
                        else if (mode == "mobile")
                            manager.sortByMobile();
                        else {
                            flagFound = false;
                            cout << "Error > Mode not found !" << endl;
                        }

                        if (flagFound) cout << "Command > Sorted !" << endl;
                    }
                }
            }
            else
            {
                cout << "Error > excepted ';'" << endl;
            }

            cout << "Press any key ... " << endl;
            cin.ignore();
        }
        catch(exception ex)
        {
            cout << ex.what() << endl;
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}
