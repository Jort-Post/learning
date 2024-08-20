#include <iostream>
#include <string>
#include <vector>

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
        void AddContact(const Person& person) {
            people.push_back(person);
        };

        void RemoveContact(const Person& person) {
            people.erase()
        };

        
    private:
        std::vector<Person> people;
    
};

int main() {
    Person person("Jort","123456789","jort.post@icloud.com");


    
}

