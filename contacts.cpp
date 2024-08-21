#include <iostream>
#include <string>
#include <list>

using std::string;

class Person {
    public:
       
    // LONG VERSION OF INITIALISING
    // Person(string name, int phone, string mail) {
    //     this -> name;
    //     this -> phone;
    //     this -> mail;
    // }

    //USING AN INITIALIZER LIST
    
    Person(const string& name, const string& phone, const string& mail) 
          : name(name), phone(phone), mail(mail) {}

    string getName() const {return name;}
    string getPhone() const {return phone;}
    string getMail() const {return mail;}

    void toString() {
        std::cout << 'Name:' << name << '\nPhone' << phone << '\nmail' << std::endl;
    }

    private:
        string name;
        string phone;
        string mail;

    
};

class ContentManager {
    public:
        void AddContact(const string& name, const string& phone, const string& mail) {
            Person newContact(name,phone,mail);
            people.push_back(newContact);
        };

        void RemoveContact(const string& name) {
            for (Person i : people) {
                if (i.getName() == name) {
                    people.remove(i);
                }
            }
            
        };

        void ViewContact(const string& name) {
            for (Person i : people) {
                if (i.getName() == name) {
                    i.toString();
                }
            }
        };

        void ListContacts() {
            for (Person i : people) {
                i.toString();
            }
        };

        // FUNCTION OVERLOADING: SAME FUNCTION BUT TWO DIFFERENT DEFINITIONS BASED ON THE INPUT
        void SearchContact(const string& name) {
            for (Person i : people) {
                if (i.getName() == name ) {i.toString();}
            }
        };

        void SearchContact(const string& mail) {
            for (Person i : people) {
                if (i.getMail() == mail ) {i.toString();}
            }
        };


        
    private:
        std::list<Person> people;
    
};

int main() {
    
    int choice;
    bool program = true;

    while (program) {
        std::cout << "What do you want to do?\n"
                     "[1] Add a contact\n"
                     "[2] Remove a contact\n"
                     "[3] View a contact\n"
                     "[4] View all contacts\n"
                     "[5] Search a contact\n"
                     "[6] Exit\n" << std::endl;
        
        std::cin >> choice;

        switch(choice) {
            case 1:
                const string phone, mail, name;

                std::cout << "Enter a name, a phonenumber and an email\n" << std::endl;
                std::cin >> name >> phone >> mail >> std::endl;

                ContentManager.AddContact(name,phone,mail)
        }
    }


    
}

