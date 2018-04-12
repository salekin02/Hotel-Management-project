#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<cstdio>
#include<sstream>
#include<cstdlib>
using namespace std;
class customer
{
protected:
    char name[20];
    char city[20];
    char nationality[20];
    int cost;
    char date[20];
    char tel[20];
    int roomno;
    char room_type[20];
public:
    customer()
    {
    }
    void set_date(char d[])
    {
        strcpy(date,d);
    }
    void set_nationality(char n[])
    {
        strcpy(nationality,n);
    }
    void set_city(char c[])
    {
        strcpy(city,c);
    }
    void set_name(char x1[])
    {
        strcpy(name,x1);
    }
    void set_type(char t[])
    {
        strcpy(room_type,t);
    }
    void set_room(int p)
    {
        roomno=p;
    }
    void set_tel(char t[])
    {
        strcpy(tel,t);
    }
    void set_cost(int p)
    {
        cost=p;
    }
    char *get_tel()
    {
        return tel;
    }
    char *get_type()
    {
        return room_type;
    }
    int get_cost()
    {
        return cost;
    }
    char *get_name()
    {
        return name;
    }
    char *get_city()
    {
        return city;
    }
    char *get_nationality()
    {
        return nationality;
    }
    char *get_date()
    {
        return date;
    }
    int get_roomno()
    {
        return roomno;
    }
    ~customer()
    {
    }
};
class employee:public customer
{
protected:
    string salary,bonus;
    string work_type;
    string time_type,starting_time;

public:
    void  set_starting_time(string t)
    {
        starting_time=t;
    }
    void set_work_type(string wt)
    {
        work_type=wt;
    }
    void set_time_type(string t)
    {
        time_type=t;
    }
    void set_salary(string s)
    {
        salary=s;
    }
    void set_bonus(string b)
    {
        bonus=b;
    }
    string get_time_type()
    {
        return time_type;
    }
    string get_wtype()
    {
        return work_type;
    }
    string get_salary()
    {
        return salary;
    }
    string get_bonus()
    {
        return bonus;
    }
    string get_starting_time()
    {
        return starting_time;
    }

};
void employee_data();
void room(customer x[],int &c);
void food(customer x[]);
void room(customer x[]);
void del(customer x[]);
void show(customer x[]);
void show_all(customer x[]);
int login();
int main()
{
    customer info[100]; //object array
    int x,r,cst,i=0,c=0,j,press,p;
    char n[20],n2[15],tel[15],ct[15],nt[20],check[2],dt[15],type[15],home[2];
    string sr,st,sn,stel,sd,sc,scst,snt;
    ifstream in;
    in.open("customer.txt");
    if(!in.is_open())
        cout<<"\nPlease Try Again Later\n";
    else
    {
        while(!in.eof())
        {
            getline(in,sr);
            getline(in,sn);
            getline(in,sc);
            getline(in,snt);
            getline(in,stel);
            getline(in,sd);
            getline(in,st);
            getline(in,scst);
            istringstream(sr)>>r;
            info[i].set_room(r);
            strcpy(n,sn.c_str());
            info[i].set_name(n);
            strcpy(ct,sc.c_str());
            info[i].set_city(ct);
            strcpy(nt,snt.c_str());
            info[i].set_nationality(nt);
            strcpy(tel,stel.c_str());
            info[i].set_tel(tel);
            strcpy(dt,sd.c_str());
            info[i].set_date(dt);
            strcpy(type,st.c_str());
            info[i].set_type(type);
            istringstream(scst)>>cst;
            info[i].set_cost(cst);
            i++;
        }
    }
    i=0;
    while(1)
    {
        c++;
        if(info[i].get_roomno()==0)
            break;
        i++;
    }
    for(j=c-1; j<=100; j++)
    {
        info[j].set_room(0);
        info[j].set_name(" ");
        info[j].set_city(" ");
        info[i].set_nationality(" ");
        info[j].set_tel(" ");
        info[j].set_date(" ");
        info[j].set_type(" ");
        info[j].set_cost(0);
    }
    cout<<"\t\t\t\t\t\t***********************************\n";
    cout<<"\t\t\t\t\t\t***********************************\n";
    cout<<"\t\t\t\t\t\t**                               **\n";
    cout<<"\t\t\t\t\t\t**      Sayeman Beach Resort     **\n";
    cout<<"\t\t\t\t\t\t**                               **\n";
    cout<<"\t\t\t\t\t\t***********************************\n";
    cout<<"\t\t\t\t\t\t***********************************\n\n\n\n";
    login();
main:
    cout<<"\t1.New Reservation\n";
    cout<<"\t2.View Reservation\n";
    cout<<"\t3.Show All Reservation\n";
    cout<<"\t4.Delete Reservation\n ";
    cout<<"\t5.Show Room Status\n ";
    cout<<"\t6.BILL\n";
    cout<<"\t7.Food Menu\n";
    cout<<"\t8.Employee Details\n";
    cout<<"\t0.Exit\n";
    cout<<"\n Enter Your Choice :  ";
    cin>>press;
    if(press==1)
    {
        int a=0,i=0;
        while(1)
        {
            a++;
            if(info[i].get_roomno()==0)
                break;
            i++;
        }
        room(info,a);
    }
    else if(press==2)
        show(info);
    else if(press==3)
        show_all(info);
    else if(press==4)
        del(info);
    else if(press==5)
        room(info);
    else if(press==6)
    {
        int t,q=0;
        cout<<"Enter The Room Number: ";
        cin>>t;
        q=t-101;
        cout<<"Total Bill: "<<info[q].get_cost()<<"(BDT)"<<endl;
    }
    else if(press==8)
        employee_data();
    else if(press==7)
        food(info);
    else if(press==0)
    {
        ofstream out;
        out.open("customer.txt",ios::app);
        for(p=c-1; p<=100; p++)
        {
            if(info[p].get_roomno()==0)
                break;
            out<<endl<<info[p].get_roomno()<<endl<<info[p].get_name()<<endl<<info[p].get_city()<<endl;
            out<<info[p].get_nationality()<<endl<<info[p].get_tel()<<endl;
            out<<info[p].get_date()<<endl<<info[p].get_type()<<endl;
            out<<info[p].get_cost();
        }
        out.close();
        return 0;
    }
    else
        goto main;
    in.close();
    cout<<"Do You Want To Continue? (y/n): ";
    cin>>home;
    if(strcmp(home,"y")==0)
    {
        cout<<"\n\n";
        goto main;
    }
    else
        return 0;

}
void room(customer x[])
{
    int available=0;
    for(int p=0; p<=100; p++)
    {
        if(x[p].get_cost()==0)
            available++;
    }
    cout<<"\n"<<available<<" Rooms Are Available\n";
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"   No.\t\t\t Type\t\t\tCharge(per day)\n\n";
    cout<<"   1\t\t\tStandard\t\t BDT 2,500\n";
    cout<<"   2\t\t\tDeluxe\t\t\t BDT 3,000\n";
    cout<<"   3\t\t\tSuper Deluxe\t\t BDT 5,000\n";
    cout<<"   4\t\t\tCouple  \t\t BDT 3,500\n";
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout<<"Facilities: \n";
    cout<<"\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\t| *Air conditioning rooms\t|\n";
    cout<<"\t| *24 Hours room services\t|\n";
    cout<<"\t| *24 Hours in-room dining\t|\n";
    cout<<"\t| *LCD Cable TV\t\t\t|\n";
    cout<<"\t| *Wi-Fi & Broadband internet\t|\n";
    cout<<"\t| *Electronic safety box\t|\n";
    cout<<"\t| *Hair dryer\t\t\t|\n";
    cout<<"\t| *Daily Newspaper\t\t|\n";
    cout<<"\t| *Electric shaving point\t|\n";
    cout<<"\t| *Electric kettle (Tea/Coffee) |\n";
    cout<<"\t| *Laundry & valet\t\t|\n";
    cout<<"\t| *Parking for 100 cars\t\t|\n";
    cout<<"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
}
void room(customer x[],int &a)
{
main:
    char n[20],ct[20],t[20],d[20],nt[20],type[20];
    int choose,price,day;
    cout<<"\n\nRoom Allocation:\n";
    cout<<"-----------------\n";
    cout<<"| 1.Standard     |\n";
    cout<<"| 2.Dulxe        |\n";
    cout<<"| 3.Super Deluxe |\n";
    cout<<"| 4.Couple       |               0.Go To Home\n";
    cout<<"-----------------\n";
    cout<<"Chose a Category: ";
    cin>>choose;
    cin.ignore();
    if(choose==1)
    {
        price=2500;
        strcpy(type,"Standard");
    }
    else if(choose==2)
    {
        price=3000;
        strcpy(type,"Deluxe");
    }
    else if(choose==3)
    {
        price=5000;
        strcpy(type,"SuperDeluxe");
    }
    else if(choose==4)
    {
        price=3500;
        strcpy(type,"Couple");
    }
    if(choose==1||choose==2||choose==3||choose==4)
    {
        cout<<"\n*Information About Customer*\n";
        cout<<"------------------------------------------------------\n";
        cout<<"Enter Your Full Name: ";
        gets(n);
        cout<<"Enter Your City Name: ";
        gets(ct);
        cout<<"Enter Your Nationality: ";
        cin>>nt;
        cout<<"Enter Your Contact Number: ";
        cin>>t;
        cout<<"How Many Days you Want The Room?(1/2/3/4.....)\n: ";
        cin>>day;
        cin.ignore();
        cout<<"Enter Arrival Date(Day-Month-Year):\n";
        gets(d);
        cout<<"-------------------------------------------------------\n";
        x[a-1].set_room(a+100);
        x[a-1].set_name(n);
        x[a-1].set_city(ct);
        x[a-1].set_nationality(nt);
        x[a-1].set_tel(t);
        x[a-1].set_date(d);
        x[a-1].set_cost(price*day);
        x[a-1].set_type(type);
    }
    else if(choose!=0)
        goto main;
    cout<<"\nYour Room is Reserved\nThank You!";
    cout<<"\n\nRoom Number is: "<<(a+100)<<endl<<endl;
}
void food(customer x[])
{
    int q,room,f,cost=0,p=0;
    char n[2],m[2];
    cout<<"Menu Card:\n";
    cout<<"------------------------------------------\n";
    cout<<"| 1.Rice One Person             Tk. 60   |\n";
    cout<<"| 2.Chicken bhuna	        Tk. 125  |\n";
    cout<<"| 3.Beef bhuna	                Tk. 125  |\n";
    cout<<"| 4.Egg Curry	                Tk. 55   |\n";
    cout<<"| 5.Egg Daal Curry	        Tk. 70   |\n";
    cout<<"| 6.Beef Curry	                Tk. 225  |\n";
    cout<<"| 7.Beef Rezala	                Tk. 225  |\n";
    cout<<"| 8.Handi Kabab	                Tk. 175  |\n";
    cout<<"| 9.Shammi Kabab 1 Pcs	        Tk. 50   |\n";
    cout<<"| 10.Beef Jalli Kabab 1 pcs	Tk. 50   |\n";
    cout<<"| 11.Mutton Rezala         	Tk. 250  |\n";
    cout<<"| 12.Fish Curry 	        Tk. 150  |\n";
    cout<<"| 13.Fish Do Piaza              Tk. 190  |\n";
    cout<<"| 14.Chingri Macher Malaikari	Tk. 275  |\n";
    cout<<"| 15.Mixed Vegetable	        Tk. 150  |\n";
    cout<<"| 16.Seasonal Vegetable Curry	Tk. 150  |\n";
    cout<<"| 17.Chinese Style Vegetable	Tk. 180  |\n";
    cout<<"| 18.Daal	                Tk. 95   |\n";
    cout<<"| 19.Daal Chorchori	        Tk. 120  |\n";
    cout<<"| 20.Seasonal Salad	        Tk. 80   |\n";
    cout<<"| 21.Chapati               	Tk. 25   |\n";
    cout<<"| 22.Aloor Chop 4 Pcs           Tk. 50   |\n";
    cout<<"| 23.Tea	                Tk. 20   |\n";
    cout<<"| 24.Coffee	                Tk. 30   |\n";
    cout<<"| 25.Soft Drinks 1 Litre    	Tk. 100  |\n";
    cout<<"| 26.Soft Drinks  250 ml can	Tk. 30   |\n";
    cout<<"------------------------------------------\n";
    cout<<"\nDo You Want To Order Food? (y/n): ";
    cin>>n;
    if(strcmp(n,"y")==0)
    {
main:
        cout<<"Enter a Food Code From Menu: ";
        cin>>f;
        if(f==1)
        {
            cout<<"\t\t\t\t\t*Rice One Person\t\tTk. 60\n";

            cost+=60;
        }
        else if(f==2)
        {
            cout<<"\t\t\t\t\t*Chicken bhuna\t\t\tTk. 125  \n";
            cost+=125;
        }
        else if(f==3)
        {
            cout<<"\t\t\t\t\t*Beef bhuna\t\t\tTk. 125  \n";
            cost+=125;
        }
        else if(f==4)
        {
            cout<<"\t\t\t\t\t*Egg Curry\t\t\tTk. 55  \n";
            cost+=55;
        }
        else if(f==5)
        {
            cout<<"\t\t\t\t\t*Egg Daal Curry\t\t\tTk. 70  \n";
            cost+=70;
        }
        else if(f==6)
        {
            cout<<"\t\t\t\t\t*Beef Curry\t\t\tTk. 225  \n";
            cost+=225;
        }
        else if(f==7)
        {
            cout<<"\t\t\t\t\t*Beef Rezala\t\t\tTk. 225  \n";
            cost+=225;
        }
        else if(f==8)
        {
            cout<<"\t\t\t\t\t*Handi Kabab\t\t\tTk. 175  \n";
            cost+=175;
        }
        else if(f==9)
        {
            cout<<"\t\t\t\t\t*Shammi Kabab 1 Pcs\t\tTk. 50  \n";
            cost+=50;
        }
        else if(f==10)
        {
            cout<<"\t\t\t\t\t*Beef Jalli Kabab 1 pcs\t\tTk. 50  \n";
            cost+=50;
        }
        else if(f==11)
        {
            cout<<"\t\t\t\t\t*Mutton Rezala\t\t\tTk. 250  \n";
            cost+=250;
        }
        else if(f==12)
        {
            cout<<"\t\t\t\t\t*Fish Curry \t\t\tTk. 150  \n";
            cost+=150;
        }
        else if(f==13)
        {
            cout<<"\t\t\t\t\t*Fish Do Piaza \t\t\tTk. 150  \n";
            cost+=150;
        }
        else if(f==14)
        {
            cout<<"\t\t\t\t\t*Chingri Macher Malaikari \tTk. 275  \n";
            cost+=275;
        }
        else if(f==15)
        {
            cout<<"\t\t\t\t\t*Mixed Vegetable \t\tTk. 150  \n";
            cost+=150;
        }
        else if(f==16)
        {
            cout<<"\t\t\t\t\t*Seasonal Vegetable Curry \tTk. 150  \n";
            cost+=150;
        }
        else if(f==17)
        {
            cout<<"\t\t\t\t\t*Chinese Style Vegetable \tTk. 180  \n";
            cost+=180;
        }
        else if(f==18)
        {
            cout<<"\t\t\t\t\t*Daal \t\t\t\tTk. 95  \n";
            cost+=95;
        }
        else if(f==19)
        {
            cout<<"\t\t\t\t\t*Daal Chorchori \t\tTk. 120  \n";
            cost+=120;
        }
        else if(f==20)
        {
            cout<<"\t\t\t\t\t*Seasonal Salad \t\tTk. 80  \n";
            cost+=80;
        }
        else if(f==21)
        {
            cout<<"\t\t\t\t\t*Chapati \t\t\tTk. 25  \n";
            cost+=25;
        }
        else if(f==22)
        {
            cout<<"\t\t\t\t\t*Aloor Chop 4 Pcs \t\tTk. 60  \n";
            cost+=60;
        }
        else if(f==23)
        {
            cout<<"\t\t\t\t\t*Tea \t\t\t\tTk. 20  \n";
            cost+=20;
        }
        else if(f==24)
        {
            cout<<"\t\t\t\t\t*Coffee \t\t\tTk. 30  \n";
            cost+=30;
        }
        else if(f==25)
        {
            cout<<"\t\t\t\t\t*Soft Drinks 1 Litre \t\tTk. 100  \n";
            cost+=100;
        }
        else if(f==26)
        {
            cout<<"\t\t\t\t\t*Soft Drinks  250 ml can \tTk. 30  \n";
            cost+=30;
        }
        else
        {
            cout<<"\nWrong Code\n";
            goto main;
        }
        cout<<"Do You Want More? (y/n): ";
        cin>>m;
        if(strcmp(m,"y")==0)
            goto main;
        cout<<"For How Many Person You Want These Items? (1/2/3...): ";
        cin>>q;
        cout<<"Enter Your Room Number: ";
        cin>>room;
        p=room-101;
        x[p].set_cost(x[p].get_cost()+(cost*q));
        cout<<"________________________________________________________________";
    cout<<"\n| Dear Sir, Please Wait Few Moments To Get Your Orders.\t\t|\n";
    cout<<"|\t\t\t\t\t\t\t\t|\n";
    cout<<"| Bill of The Items Your Ordered: "<<(cost*q)<<"(BDT)\t\t\t|"<<endl;
    cout<<"| Note: This Cost Will Include With Your Room Cost\t\t|\n";
    cout<<"| Thank You!\t\t\t\t\t\t\t|\n";
    cout<<"|_______________________________________________________________|\n";
    }
}
void show(customer x[])
{
    customer *p;
    p=&x[0];
    char check[5],name[20];
    int n,i=0,choose,j;
room:
    cout<<"\t1.For a Specific Room\n";
    cout<<"\t2.For a Specific Name\n";
    cout<<" Choose Your Option: ";
    cin>>choose;
    if(choose==1)
    {
        cout<<"Enter The Room Number: ";
        cin>>n;
        i=n-101;
        if((p+i)->get_roomno()==n)
        {
            cout<<"------------------------------------\n";
            cout<<"| Room No.: "<<(p+i)->get_roomno()<<" \n";
            cout<<"| Cust Name: "<<(p+i)->get_name()<<"\n";
            cout<<"| City: "<<(p+i)->get_city()<<"\n";
            cout<<"| Nationality: "<<(p+i)->get_nationality()<<" \n";
            cout<<"| Contact Number: "<<(p+i)->get_tel()<<"\t\n";
            cout<<"| Arrival Date: "<<(p+i)->get_date()<<"\n";
            cout<<"| Room Type: "<<(p+i)->get_type()<<"\n";
            cout<<"| Room Total Cost: "<<(p+i)->get_cost()<<"\n";
            cout<<"------------------------------------\n";
        }
        else
            cout<<"This Room is Emty!\n\n";
    }
    else if(choose==2)
    {
        cout<<"Enter Cust Name You Are Looking For: ";
        cin>>name;
        cout<<"\nSearch Found: \n";
        for(j=0; j<=100; j++)
        {
            if((p+j)->get_roomno()==0)
                break;
            if((p+j)->get_name()[0]==name[0]&&(p+j)->get_name()[1]==name[1]&&(p+j)->get_name()[2]==name[2]&&(p+j)->get_name()[3]==name[3])
            {
                cout<<"------------------------------------\n";
                cout<<"| Room No.: "<<(p+j)->get_roomno()<<" \n";
                cout<<"| Cust Name: "<<(p+j)->get_name()<<"\t\n";
                cout<<"| City: "<<(p+j)->get_city()<<"\n";
                cout<<"| Nationality: "<<(p+j)->get_nationality()<<"\n";
                cout<<"| Contact Number: "<<(p+j)->get_tel()<<"\n";
                cout<<"| Arrival Date: "<<(p+j)->get_date()<<"\n";
                cout<<"| Room Type: "<<(p+j)->get_type()<<"\n";
                cout<<"| Room Total Cost: "<<(p+j)->get_cost()<<"\n";
                cout<<"------------------------------------\n";
            }
        }
        j=j-1;
        if((p+j)->get_name()[0]!=name[0]&&(p+j)->get_name()[1]!=name[1]&&(p+j)->get_name()[2]!=name[2]&&(p+j)->get_name()[3]!=name[3])
        {
            cout<<"\nNo Customer Found For This Name!\n\n";
        }
    }
    cout<<"\nWant To Check Again? (y/n): ";
    cin>>check;
    if(strcmp(check,"y")==0)
        goto room;
}
void show_all(customer x[])
{
    int n,r,i=0,cst;
    char n1[15],n2[15],tel[15],ct[15],nt[15],check[2],dt[15],type[15];
    for(i=0; i<=100; i++)
    {
        if(x[i].get_roomno()==0)
            break;
        cout<<"------------------------------------\n";
        cout<<"| Room No.: "<<x[i].get_roomno()<<" \n";
        cout<<"| Cust Name: "<<x[i].get_name()<<"\n";
        cout<<"| City: "<<x[i].get_city()<<"\n";
        cout<<"| Nationality: "<<x[i].get_nationality()<<"\n";
        cout<<"| Contact Number: "<<x[i].get_tel()<<"\n";
        cout<<"| Arrival Date: "<<x[i].get_date()<<"\n";
        cout<<"| Room Type: "<<x[i].get_type()<<"\n";
        cout<<"| Room Total Cost: "<<x[i].get_cost()<<" \n";
        cout<<"------------------------------------\n";
    }
}
int login()
{
   char pass[30];
    int i=0;
    char temp,y;
    char user[10];
    cout<<"\n\t\t\t\t\t\t\tAdminstrator Login\n";
    cout<<"\t\t\t\t\t\t--------------------------------\n";
    cout<<"\t\t\t\t\t\t>Admin username: ";
    cin>>user;
    cout<<"\t\t\t\t\t\t>Enter Password: ";
    for(i=0;;)
    {
        temp=getch();
        if(temp>='a'&&temp<='z'||temp>='A'&&temp<='Z'||temp>='0'&&temp<='9')
        {
            pass[i]=temp;
            ++i;
            cout<<"*";
        }
        if(temp=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(temp=='\r')
        {
            pass[i]='\0';
            break;
        }
    }
    cout<<endl;
    if(i<5)
    {
        cout<<"\t\t\t\t\t\t Minimum 5 Digit \n";
        cout<<"\t\t\t\t\t\t Press Enter For Enter Again  ";
        getch();
        return login();
    }
     if(strcmp(pass,"admin")==0&&strcmp(user,"admin")==0)
        cout<<"\t\t\t\t\t\tLogin Successfull\n\n";
    else
    {
        cout<<"\n\t\t\t\t\t\t=============================\n";
        cout<<"\t\t\t\t\t\tWrong username or password!  ";
        cout<<"\n\t\t\t\t\t\t=============================\n";
        cout<<"\t\t\t\t\t\tTry Again? (y/n): ";
        cin>>y;
        if(y=='y')
        {
            return login();
        }
        else
            exit(0);
    }
}
void del(customer x[])
{
    int n,j=0,cost;
    cout<<"-----------------------\n";
    cout<<"Delete a Reservation\n";
    cout<<"-----------------------\n\n";
    cout<<"Enter The Room Number: ";
    cin>>n;
    j=n-101;
    cost=x[j].get_cost();
    if(x[j].get_roomno()==n)
    {
        x[j].set_room(0);
        x[j].set_name(" ");
        x[j].set_city(" ");
        x[j].set_nationality(" ");
        x[j].set_tel(" ");
        x[j].set_date(" ");
        x[j].set_type(" ");
        x[j].set_cost(0);
    }
    cout<<"Reservation has been Deleted\n\n";
    cout<<"Total Bill: "<<cost<<"(BDT)\n\n";
}
void employee_data()
{
    employee data[60];
    int i=0,j;
    char n1[20],ct[20],dt[15];
    string n,y,t,s,b,tt,wt,type,ht;
    ifstream in;
    in.open("employee.txt");
    if(in.is_open())
    {
        while(!in.eof())
        {
            getline(in,n);
            getline(in,ht);
            getline(in,y);
            getline(in,tt);
            getline(in,t);
            getline(in,type);
            getline(in,s);
            getline(in,b);
            strcpy(n1,n.c_str());
            data[i].set_name(n1);
            strcpy(ct,ht.c_str());
            data[i].set_city(ct);
            strcpy(dt,y.c_str());
            data[i].set_date(dt);
            data[i].set_time_type(tt);
            data[i].set_starting_time(t);
            data[i].set_work_type(type);
            data[i].set_salary(s);
            data[i].set_bonus(b);
            i++;
        }
    }
    cout<<"Employee Details:\n";
    for(j=0; j<i; j++)
    {
        if(data[j].get_name()[0]==' ')
            break;
        cout<<"------------------------------------\n";
        cout<<"| Name: "<<data[j].get_name()<<"\n";
        cout<<"| Home Town: "<<data[j].get_city()<<"\n";
        cout<<"| Working Years: "<<data[j].get_date()<<"\n";
        cout<<"| Time Type: "<<data[j].get_time_type()<<"\n";
        cout<<"| Working Time: "<<data[j].get_starting_time()<<"\n";
        cout<<"| Type: "<<data[j].get_wtype()<<"\n";
        cout<<"| Salary: "<<data[j].get_salary()<<" \n";
        cout<<"| Bonus Salary: "<<data[j].get_bonus()<<" \n";
        cout<<"------------------------------------\n";
    }
}
