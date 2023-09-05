#include <iostream>
#include <fstream> // file handling library
#include <sstream> // library for enabling operations between string buffers and string objects
#include <string>

using namespace std;

int main()
{
    int a, i=0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];

    cout<<"             Security System"<<endl<<endl;
    cout<<"*____________________________________*"<<endl<<endl; //double endl adds extra line
    cout<<"|            1. Register             |"<<endl;
    cout<<"|            2. Login                |"<<endl;
    cout<<"|            3. Change Password      |"<<endl;
    cout<<"|            4. End Program          |"<<endl<<endl;
    cout<<"*____________________________________*"<<endl;

    do{
        cout<<endl<<endl;
        cout<<"Enter your choice as a number: ";
        cin>>a;  // take user input and store it in variable a

        switch(a){
            case 1:{
                cout<<"---------Register-----------"<<endl<<endl;
                cout<<"Please enter a username: ";
                cin>>name;
                cout<<"Please enter a password: ";
                cin>>password0;
                cout<<"Please enter your age: ";
                cin>>age;

                ofstream of1; // creates an object of ofstream class which opens a file for writing
                of1.open("file.txt");
                if(of1.is_open()){
                    of1<<name<<"\n";  // write name into the file and skip a line
                    of1<<password0;
                    cout<<"Registration successful!"<<endl;
                }
               break;
            }


            case 2:{
                i=0;
                cout<<"---------Login-----------"<<endl<<endl;
                ifstream of2;  // creates an object of ifstream class which opens a file for reading
                of2.open("file.txt");
                cout<<"Please enter username: "<<endl;
                cin>>user;
                cout<<"Please enter password: "<<endl;
                cin>>pass;

                if(of2.is_open()){
                    while(!of2.eof()){  // eof means end of file so while loop will continue until end of file is reached
                        while(getline(of2, text)){  // while loop with getline function reads the file line by line
                            istringstream iss(text);  // streams string and stores it using extraction operator
                            iss>>word;  // extraction operator to store extracted string
                            creds[i]=word;
                            i++;
                        }

                        if(user==creds[0] && pass==creds[1]){
                            cout<<"--------Login Successful---------"<<endl<<endl;
                            cout<<"Here are your details: "<<endl;
                            cout<<"Username: "+name<<endl;
                            cout<<"Password: "+pass<<endl;
                            cout<<"Age: "+age<<endl;
                        }
                        else {
                            cout<<"Incorrect credentials"<<endl;
                            break;
                        }
                    }
                }
                break;
            }

            case 3:{
                i=0;
                cout<<"---------Change Password-----------"<<endl<<endl;
                ifstream of0;
                of0.open("file.txt");
                cout<<"Please enter old password: "<<endl;
                cin>>old;

                if(of0.is_open()){
                    while(of0.eof()){
                        while(getline(of0, text)){
                            istringstream iss(text);
                            iss>>word1;
                            cp[i]=word1;
                            i++;
                        }

                        if(old==cp[1]){
                            of0.close();
                            ofstream of1;

                            if(of1.is_open()){
                                cout<<"Enter new password: ";
                                cin>>password1;
                                cout<<"Enter new password again: ";
                                cin>>password2;

                                if(password1==password2){
                                    of1<<cp[0]<<"\n";
                                    of1<<password1;
                                    cout<<"Password changed";
                                }
                                else{
                                    of1<<cp[0]<<"\n";
                                    of1<<old;
                                    cout<<"Passwords do not match"<<endl;
                                }
                            }
                            else{
                                cout<<"Please enter valid password"<<endl;
                                break;
                            }
                        }
                        else {
                            cout<<"Incorrect credentials"<<endl;
                            break;
                        }
                    }
                }
            }

            case 4:{
                cout<<"---------Exiting-----------"<<endl<<endl;
                break;
            }

            default:
                cout<<"Please enter a valid choice";
        }
    }
    while(a!=4);
    return 0;
}
