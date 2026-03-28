#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class book{
    public: 
        string name;
        int books;
        int rollno;

};
void sayhello(){
    cout << "Hello Roshan tum lol hoo"<< endl;

}
int main (){
    book book1;
    book1.name = "Roshan";
    book1.books = 3;
    cout << book1.name;
    sayhello();
    int age = 45;
    int *pAge= &age;
    cout << pAge <<endl;
    cout << *pAge <<endl;
    cout << *&age;
    // int age;
    //cout << "Enter your age : ";
    // cin >> age;
    // cin.ignore();
    // cout << "Enter your name : ";
    // string name;
    // getline(cin , name);
    // cout << "hello roshan";
    // cout << "Nice to meet you "<< endl;
    // cout << "i am "<< name <<" age " << age << endl; 
    // cout << name.substr(1,3);
    // cout << pow(2,5) << endl;
     return 0;
}