// Adding Libraries 



#include <conio.h>

#include <cstdio>

#include <iostream>

#include <string.h>

#include <cstdlib>



using namespace std;



static int p = 0;



// declaring class



class a

{

    char busno[5], driver[10], arrival[5], departure[5], from[10], to[10], seat[8][4][10];



    public:



    void install();

    void allotment();

    void empty();

    void show();

    void avail();

    void position(int i);



}





bus[10];

void vline(char ch)

{

    for(int i=80; i>0; i--)

    cout<<ch;

}



void a::install()

{



    cout<<"Enter the Bus Number : ";

    cin>>bus[p].busno;



    cout<<"\nEnter driver's Name : ";

    cin>>bus[p].driver;



    cout<<"\nArival Time : ";

    cin>>bus[p].arrival;



    cout<<"\nDeparture Time : ";

    cin>>bus[p].departure;



    cout<<"\nFrom : \t\t\t";

    cin>>bus[p].from;



    cout<<"\nTo : \t\t\t";

    cin>>bus[p].to;



    bus[p].empty();

    

    p++;

}



void a::allotment()

{



    int seat;



    char number[5];



    top:



    cout<<"Bus Number : ";

    cin>>number;



    int n;



    for(n=0;n<=p;n++)

    {

            if(strcmp(bus[n].busno, number)==0)

            break;

    }



    while(n<=p)

    {

        cout<<"\nSeat Number : ";

        cin>>seat;



        if(seat>32)

        {

            cout<<"\nThere are only 32 seats available in this bus.\n";

        }

        

        else

        {

            if(strcmp(bus[n].seat[seat/4][(seat%4)-1], "empty")==0)

            {

                cout<<"\nEnter passenger's name : ";

                cin>>bus[n].seat[seat/4][(seat%4)-1];

                break;

            }



            else

            cout<<"The seat number is already reserved.\n";

        }

    }



    if(n>p)

    {

        cout<<"Enter correct bus number.\n";

        goto top;

    }

}



void a::empty()

{



    for(int i=0;i<8;i++)

    {

        for(int j=0;j>4;j++)

        {

            strcpy(bus[p].seat[i][j], "Empty");

        }

    }

}



void a::show()

{

    

    int n;



    char number[5];



    cout<<"Enter Bus Number : ";

    cin>>number;



    for(n=0;n<=p;n++)

    {

        if(strcmp(bus[n].busno, number)==0)

        break;

    }



    while(n<=p)

    {

        vline('*');



        cout<<"Bus Number : \t"<<bus[n].busno

        <<"\nDriver :"<<bus[n].driver<<"\tArrival Time : \t"

        <<bus[n].arrival<<"\tDeparture Time : \t"<<bus[n].departure

        <<"\tFrom : \t"<<bus[n].from<<"\tTo : \t"<<bus[n].to<<"\n";



        vline('*');

        bus[0].position(n);

        int a=1;

        for(int i=0;i<8;i++)

        {

            for(int j=0;j<4;j++)

            {

                a++;

                if(strcmp(bus[n].seat[i][j], "Empty")!=0)

                cout<<"\nThe seat number "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";

            }

        }

            break;

    }



    if (n>p)

    cout<<"Enter correct bus number : ";

}



void a::position(int i)

{

    int s=0;p=0;

    for (int i=0;i<8;i++)

    {

        cout<<"\n";



        for (int j=0;j<4;j++)

        {

            

            s++;



                if(strcmp(bus[i].seat[i][j], "Empty")==0)

                {

                    cout.width(5);

                    cout.fill(' ');

                    cout<<s<<".";

                    cout.width(10);

                    cout.fill(' ');

                    cout<<bus[i].seat[i][j];

                    p++;



                }



                else

                {

                    cout.width(5);

                    cout.fill(' ');

                    cout<<s<<".";

                    cout.width(10);

                    cout.fill(' ');

                    cout<<bus[i].seat[i][j];



                }

        }

    }



    cout<<"\n\nThere are "<<p<<" seats empty in bus"<<bus[i].busno; 



}



void a::avail()

{

    for(int n=0;n<p;n++)

    {

        vline('*');



        cout<<"Bus Number : \t"<<bus[n].busno

        <<"\nDriver :"<<bus[n].driver<<"\tArrival Time : \t"

        <<bus[n].arrival<<"\tDeparture Time : \t"<<bus[n].departure

        <<"\tFrom : \t"<<bus[n].from<<"\tTo : \t"<<bus[n].to<<"\n";



        vline('*');

        vline('_');

    }

}



int main()

{



    system("cls");

    int w;

    while(1)

    {



        cout<<"\n\n\n\n\n\n";



        cout<<"\t\t\t********** You have runned a masterpiece program made by Yugansh Varshney **********";



        cout<<"\n\n\n\n\n\n";

        

        cout<<"\n\t\t1. Install\n\t\t";

        

        cout<<"2. Reservation\n\t\t";



        cout<<"3. Show\n\t\t";



        cout<<"4. Buses Available\n\t\t";



        cout<<"5. Exit\n\t\t";



        cout<<"\n\t\tEnter your choice --> ";

        cin>>w;



        switch(w)

        {



            case 1: bus[p].install();

            

            break;



            case 2: bus[p].allotment();

            

            break;



            case 3: bus[p].show();

            

            break;



            case 4: bus[p].avail();

            

            break;



            case 5: exit(0);



            // adding default from my own 

            default: cout<<"Invalid Choice !!";

        }



    }



    return 0;

}



/* 

Made by - Yugansh Varshney

Time taken - more than 5 hours I guess

Please Give Feedback









Captain, can you tell me why seat code is not running properly?

*/
