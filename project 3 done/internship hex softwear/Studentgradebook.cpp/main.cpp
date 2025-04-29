#include <iostream>

using namespace std;

int main()
{
    cout << "HI MY NAME IS GRADE BOOK CALCULATOR !" << endl;
    cout << "WHATS YOUR NAME,SURNAME,STUDENT ID,!"<< endl;
    string name,surname;
    cout<<"Please Enter your Name : ";
    cin>>name;
    cout<<"Please Enter your SURNAME : ";
    cin>>surname;
    int studentid;
    cout<<"STUDENT ID ISSUD BY ORGANIZATION : ";
    cin>>studentid;
    cout<<"****************************************************************"<<endl;
    cout<<" "<<endl;
    cout<<"It's nimce to meet you "<<name<<" so now let's calculate your Avarage"<<endl;
    cout << "Please enter your five subjects and persentage obtained!" << endl;
    cout<<" "<<endl;
    cout<<"****************************************************************"<<endl;
    cout<<" "<<endl;
    int a,b,c,d,e,cal;
    string sub1,sub2,sub3,sub4,sub5;
    cout<<"Enter your first module: ";
    cin>>sub1>>a;
    cout<<"Enter your second module: ";
    cin>>sub2>>b;
    cout<<"Enter your third module: ";
    cin>>sub3>>c;
    cout<<"Enter your fourth module: ";
    cin>>sub4>>d;
    cout<<"Enter your fith module: ";
    cin>>sub5>>e;

    cal = (((a+b+c+d+e)*100)/500);

    if (cal<=100&&cal>=90){
        cout<<"******************************"<<endl;
        cout<<" "<<endl;
        cout<<"EXELLENT OUTSTANDING  !!! :"<<endl;
        cout<<name<<" "<<surname<<endl;
        cout<<studentid<<endl;
        cout<<"your avarage scored is "<<cal<<" which is equivalent to A+";
        cout<<" "<<endl;
        cout<<"******************************"<<endl;

    }
     else if (cal<=89&&cal>=70){
        cout<<"******************************"<<endl;
         cout<<" "<<endl;
        cout<<"Well done !!! :"<<endl;
        cout<<name<<" "<<surname<<endl;
        cout<<studentid<<endl;
        cout<<"your avarage scored is "<<cal<<" which is equivalent to B";
        cout<<" "<<endl;
        cout<<"******************************"<<endl;
    }
       else if (cal<=69&&cal>=50){
        cout<<"******************************"<<endl;
        cout<<" "<<endl;
        cout<<"WelL NEXT TIME DO MORE !!! :"<<endl;
        cout<<name<<" "<<surname<<endl;
        cout<<studentid<<endl;
        cout<<"your avarage scored is "<<cal<<" which is equivalent to C";
        cout<<" "<<endl;
        cout<<"******************************"<<endl;
    }
      else if (cal<=49&&cal>=30){
        cout<<"******************************"<<endl;
        cout<<" "<<endl;
        cout<<"YOU FAID YOUR MODULES !!! :"<<endl;
        cout<<name<<" "<<surname<<endl;
        cout<<studentid<<endl;
        cout<<"your avarage scored is "<<cal<<" which is equivalent to D";
        cout<<" "<<endl;
        cout<<"******************************"<<endl;
    }
      else if (cal<=29&&cal>=0){
        cout<<"******************************"<<endl;
        cout<<" "<<endl;
        cout<<"YOU FAID YOUR MODULES !!! :"<<endl;
        cout<<name<<" "<<surname<<endl;
        cout<<studentid<<endl;
        cout<<"your avarage scored is "<<cal<<" which is equivalent to F";
        cout<<" "<<endl;
        cout<<"******************************"<<endl;
    }
    else{
        cout<<"******************************"<<endl;
        cout<<" "<<endl;
        cout<<"YOU FAID YOUR MODULES !!! :"<<endl;
        cout<<name<<" "<<surname<<endl;
        cout<<studentid<<endl;
        cout<<"your avarage scored is "<<cal<<" which is equivalent to FF";
        cout<<" "<<endl;
        cout<<"******************************"<<endl;

    }



    return 0;
}
