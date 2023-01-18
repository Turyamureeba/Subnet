#include <iostream>
#include <stdio.h>
#include <string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include<unistd.h>

using namespace std;

class asg2
{
            string ip;
            int same;
            int diff;

public:
            void same_subnet();
            void diff_subnet();
            void analysis(int b);
};

int main()
{
            asg2 ob;
            int choice;
        cout<<"Subnet mask: 255.255.255.192"<<endl;
        cout<<"IP address range:"<<endl;
        cout<<"subnet A- 192.168.4.0 - 192.168.4.63"<<endl;
        cout<<"subnet B- 192.168.4.64 - 192.168.4.127"<<endl;
        cout<<"subnet C- 192.168.4.128 - 192.168.4.191"<<endl;
        cout<<"subnet D- 192.168.4.192 - 192.168.4.255"<<endl;
            do{
                        cout<<"1.Ping a machine having similar subnet"<<endl;
                        cout<<"2.Ping a machine in the subnet A from machine of subnet B"<<endl;
                        cout<<"Enter choice:";
                        cin>>choice;
                        switch(choice)
                        {
                                    case 1: ob.same_subnet();
                                                break;
                                    case 2: ob.diff_subnet();
                                                break;
                        }
            }while(choice!=3);
            return 0;
}

void asg2::same_subnet()
{
            string cmd;
            cout<<"Enter IP address to PING: ";
            cin>>ip;
            cmd="ping "+ip;
            system(cmd.c_str());
            same=system(cmd.c_str());
            analysis(same);

}

void asg2::diff_subnet()
{
            string cmd;
            cout<<"Enter IP address to PING=";
            cin>>ip;
            cmd="ping "+ip;
            system(cmd.c_str());
        diff=system(cmd.c_str());
            analysis(diff);
}

void asg2::analysis(int res)
{
            if(res==0)
            {
                        cout<<"Successful PING.Machine in same subnet"<<endl;
                cout<<"IP address: "<<ip<<endl;

            }
            else if(res==256)
            {
                        cout<<"Machine in the same is shutdown"<<endl;
                cout<<"IP address: "<<ip<<endl;

            }

            else if(res==512)
            {
                        cout<<"Machine in another subnet"<<endl;
                cout<<"IP address: "<<ip<<endl;
            }


}
