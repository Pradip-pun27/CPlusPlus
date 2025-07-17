#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Reservation{
    string name;
    int age,trainNo,seatNo;
    public:
        void inputDetails(){
            cout<<"\n----------Book Ticket----------"<<endl;
            cout<<"Enter Passenger Name  :";
            // cin.ignore();
            // getline(cin,name);
            cin>>name;
            cout<<"Enter age :";
            cin>>age;
            cout<<"Enter Train Number :";
            cin>>trainNo;
            cout<<"Enter Seat Number :";
            cin>>seatNo;
        }

        bool isSeatAvailable(){
            ifstream inFile("reservation.txt");
            if(!inFile.is_open()){
                return true;
            }
            string rName;
            int rAge,rTrain,rSeat;
            while(inFile >> rName >> rAge >> rTrain >> rSeat){
                if(rTrain == trainNo && rSeat == seatNo){
                    inFile.close();
                    return false;
                }
            }
            inFile.close();
            return true;
            
        }

        void saveToFile(){
            if(!isSeatAvailable()){
                cout<<"That Seat is already Booked sry for that :)\nTry another."<<endl;
                return;
            }
        ofstream outFile("reservation.txt",ios::app);
        if(!outFile.is_open()){
            cout<<"Error! Opening file for writing!"<<endl;
            return;
        }
        outFile << name << " " << age << " " << trainNo << " " << seatNo<<endl;
        outFile.close();
        cout<<"Ticket Booked Successfully :)"<<endl;
        }

        void viewAll(){
            ifstream inFile("reservation.txt");
            if(!inFile.is_open()){
                cout<<"\n No Reservations found."<<endl;
                return;
            }
            cout<<"\n---------------------------------All Reservations---------------------------------"<<endl;
            cout<<"Train\tSeat\tName\tAge"<<endl;
            cout<<"-------------------------------"<<endl;
            string rName;
            int rAge, rTrain,rSeat;
            while (inFile >> rName >> rAge >> rTrain >> rSeat){
                cout<<rTrain<<"\t"<<rSeat<<"\t"<<rName<<"\t"<<rAge<<endl;
            }
            inFile.close();
        }

        void cancelTicket(){
            cout<<"\n----------Cancel Ticket----------"<<endl;
            cout<<"Enter Train Number =";
            cin>> trainNo;
            cout<<"Enter Seat Number to Cancel:";
            cin>>seatNo;
            ifstream inFile("reservation.txt");
            if(!inFile.is_open()){
                cout<<"No reservations to cancel."<<endl;
                return;
            }
            ofstream temp("temp.txt");
            bool found=false;
            string rName;
            int rAge, rTrain, rSeat;
            while(inFile >>rName >>rAge>> rTrain>> rSeat){
                if(rTrain == trainNo && rSeat == seatNo){
                    found =true;
                }
                else{
                    temp <<rName<<" "<<rAge<<" "<<rTrain<<" "<<rSeat<<endl;
                }
            }
            inFile.close();
            temp.close();
            if(found){
                remove("reservations.txt");
                rename("temp.txt","reservation.txt");
                cout<<"Ticket Cancelled Succcessfully."<<endl;
            }
            else{
                remove("temp.txt");
                cout<<"No Matching reservation found."<<endl;
            }
        }
};
