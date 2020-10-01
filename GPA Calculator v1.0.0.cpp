#include<iostream>
using namespace std;

class student{
public:
    //data declarations
    int id;
    float numbers[9],credit[9]={3, 1.5, 3, 1.5, 3, 3, 3, 0.75, 0.75},grade[9];
    float sum,gpa;
    int failCourse,i,fail=0,merit;
    //Functions
    void getId(){
        cout<<"Student ID: ";
        cin>>id;
    }
    void getGrade();
    void output();
};

//getGrade function defination
void student::getGrade(){
    //Data Input
    cout<<"CSE  1101: "; cin>>numbers[0];
    cout<<"CSE  1102: "; cin>>numbers[1];
    cout<<"CSE  1103: "; cin>>numbers[2];
    cout<<"CSE  1104: "; cin>>numbers[3];
    cout<<"MATH 1101: "; cin>>numbers[4];
    cout<<"PHY  1101: "; cin>>numbers[5];
    cout<<"HUM  1101: "; cin>>numbers[6];
    cout<<"HUM  1102: "; cin>>numbers[7];
    cout<<"Viva Voce: "; cin>>numbers[8];

    //Course Grade
    failCourse=0;
    for(i=0;i<9;i++){
        if(numbers[i]>79) grade[i]=4;
        else if(numbers[i]>=80) grade[i]=4;
        else if(numbers[i]>=75) grade[i]=3.75;
        else if(numbers[i]>=70) grade[i]=3.5;
        else if(numbers[i]>=65) grade[i]=3.25;
        else if(numbers[i]>=60) grade[i]=3;
        else if(numbers[i]>=55) grade[i]=2.75;
        else if(numbers[i]>=50) grade[i]=2.5;
        else if(numbers[i]>=45) grade[i]=2.25;
        else if(numbers[i]>=40) grade[i]=2;
        else{grade[i]=0; failCourse++;}
    }

    //GPA Calculation
    sum=0;
    for(i=0;i<9;i++){
        sum+=grade[i]*credit[i];
    }
    gpa=sum/19.5;

    //Pass Confirmation
    if(gpa<=2.20) fail=1;
}

//Output Function
void student::output(){
    if(fail==0) cout<<"GPA of Student ID:"<<id<<" is "<<gpa<<endl;
    else cout<<"GPA of Student ID:"<<id<<" is Fail"<<endl;
    cout<<"Merit Position: "<<merit<<endl;
}

int main()
{
    student s[100]={'\0'};
    int i=0,j,id,serial[100],tempInt;
    float gpaCopy[100]={'\0'},tempFloat;
    char ch,chGpa;
    cout<<"Are you want to add student (y/n?) : ";
    cin>>ch;
    while(ch=='y' || ch=='Y'){
        s[i].getId();
        s[i].getGrade();
        cout<<"Are you want to add student (y/n?) : ";
        cin>>ch;
        i++;
    }
    if(ch=='n' || ch=='N'){
        //Sorting
        for(i=0;s[i].id!='\0';i++) {
            gpaCopy[i]=s[i].gpa;
            serial[i]=s[i].id;
        }
        for(i=0;gpaCopy[i]!='\0';i++){
            for(j=i+1;gpaCopy[j]!='\0';j++){
                if(gpaCopy[j]>gpaCopy[i]){
                    //change GPA
                    tempFloat=gpaCopy[j];
                    gpaCopy[j]=gpaCopy[i];
                    gpaCopy[i]=tempFloat;
                    //change id
                    tempInt=serial[j];
                    serial[j]=serial[i];
                    serial[i]=tempInt;
                }
            }
        }
        //merit paste to student class
        for(i=0;serial[i]!='\0';i++){
            for(j=0;serial[j]!='\0';j++){
                if(s[j].id==serial[i]) s[j].merit=i+1;
            }
        }

        cout<<"Are you want to see student GPA (y/n?) : ";
        cin>>chGpa;
        while(chGpa=='y' || chGpa=='Y'){
            cout<<"Student ID: ";
            cin>>id;
            for(i=0;id!=s[i].id;i++);
            s[i].output();
            cout<<"Are you want to see student GPA (y/n?) : ";
            cin>>chGpa;
        }
        if(chGpa=='n'|| chGpa=='N') {cout<<"Thank You"; exit(0);}
    }
    return 0;
}


/*Sample Input
y
190101
80
80
80
80
80
80
80
70
50
y
190102
80
80
80
80
80
80
80
80
80
n
y
190102
y
190101
n

*/
