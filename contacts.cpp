#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

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
        std::cout << 'Name:' << name << '\nPhone:' << phone << '\nMail:' << std::endl;
    }

    private:
        string name;
        string phone;
        string mail;

    
};

class ContactManager {
    public:
        void AddContact(const string& name, const string& phone, const string& mail) {
            Person newContact(name,phone,mail);
            people.push_back(newContact);
        };

        // MY ORIGINAL SOLUTION TO "REMOVE CONTACTS":
        // void RemoveContact(const string& name) {
        //     for (Person i : people) {
        //         if (i.getName() == name) {
        //             people.remove(i);
        //         }
        //     }
            
        // };

        // WHY THIS DOESN'T WORK:
        // • for (Person i : people) { } loops over actual values. 
        //   This means that each value of i is actually an copy of elements from the list.
        // • Why it doesn't compile: I try to use the comparison operator
        //   whilst I did not define one.

        void RemoveContact(const string& name) {
            people.erase(
                std::remove_if(people.begin(), people.end(),
                [&name](const Person& c){
                    return c.getName() == name;
                }),
                people.end()
            );
        };
        // The optimal solution is the 'erase-remove idiom' which uses two functions:
        // .erase(begin,end) -> this function actually erases values from a list, but on it's own
        // it could leave gaps in the middle of such list, therefore it's combined with:
        // std::remove(begin, end, value) -> moves all values equal to the value to the END of the list.
        // Or used in this case:
        // std::remove(begin, end, unary predicate) -> moves all values which satisfy the predicate to the END of the list
        // The predicate takes a lambda expression in the form: [capture](parameters) -> return_type { body }
        // Capture: a list which specifies which variables are available to use in the expression, in this example it is the name variable to compare it to the object attribute name.
        // parameters: a list of parameters with a type 

        void ViewContact(const string& name) {
            for (Person i : people) {
                if (i.getName() == name) {
                    i.toString();
                }
            }
        };

        void ListContacts() {
            for (Person& i : people) {
                i.toString();
            }
        };

        // FUNCTION OVERLOADING: SAME FUNCTION BUT TWO DIFFERENT DEFINITIONS BASED ON THE INPUT
        void SearchContact(const string& name) {
            for (Person i : people) {
                if (i.getName() == name ) {i.toString();}
            }
        };


        
    private:
        std::vector<Person> people;
    
};

int main() {
    
    int choice;
    bool program = true;
    ContactManager contactmanager;
    string phone, mail, name;

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
                std::cout << "Enter a name\n" << std::endl;
                std::cin >> name; 
                std::cout << "Enter a phone number\n" << std::endl;
                std::cin >> phone;
                std::cout << "Enter an email\n" << std::endl;
                std::cin >> mail;
                contactmanager.AddContact(name,phone,mail);
                
                break;
            case 2:
                std::cout << "Enter the name of the contact you'd like to remove\n" << std::endl;
                std::cin >> name;
                contactmanager.RemoveContact(name);
                break;
            case 3:
                std::cout << "Enter the name of the person you'd like to get details of\n" << std::endl;
                std::cin >> name;
                contactmanager.SearchContact(name);
                break;
            case 4:
                contactmanager.ListContacts();
                break;
            case 5:
                std::cout << "Enter the name of the person";
                std::cin >> name;
                contactmanager.SearchContact(name);
            case 6:
                program = false;
                break;
        }
    }


    return 0;
}

