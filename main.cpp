#include<iostream>
#include "/home/pradip-pun-magar/CSIT2ndsem/CPlus/AnotherClassHavingFile.cpp"
using namespace std;
void bookTicket(){
    Reservation r;
    r.inputDetails();
    r.saveToFile();

}

void cancelTicket(){
    Reservation r;
    r.cancelTicket();

}

void viewReservations(){
    Reservation r;
    r.viewAll();

}
int main() {
    int choice;
    do{
        cout<<"\n-----------------------Bus Reservation System-----------------------"<<endl;
        cout<<"1. Book Ticket"<<endl;
        cout<<"2. Cancel Ticket"<<endl;
        cout<<"3. View All Reservations"<<endl;
        cout<<"4. Exit\n\n"<<endl;
        cout<<"Enter yours Choice(1 or 2 or 3 or 4) =";
        cin>>choice;
        switch(choice){
            case 1:
                bookTicket();
                break;
            case 2:
                cancelTicket();
                break;
            case 3:
                viewReservations();
                break;
            case 4:
                cout<<"Exiting System. Bye Have a Nice Day :)\n\n\n";
                break;
            default:
                cout<<"Invalid Choice Given. Plz Try again :)"<<endl;
        }

    }while(choice!=4);
    return 0;
}