#include<iostream>
#include<windows.h>
#include"MMSystem.h"
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

struct PersonClass
{
       char name[100];
       int id;
       int age;
       string personType;
} Pers[20];

struct Level{
       int L1;
       int L2;
       int L3;
} TL[20];

struct countTotal
{
	    int num1;
		int num2;
		int num3;
}count;

void testQuesL1();
void testQuesL2();
void testQuesL3(countTotal);
void createAcc (PersonClass[],Level[]); 
void view(PersonClass[],Level[],int,ofstream&); 
bool findData2(PersonClass[],Level[],int);
int countData(PersonClass[],Level[]); 
void modifyLevel(PersonClass[],Level[],int,int);

int main()
{
	int choose,idNum,testL;
	char proceed;
	char cont;
	bool found=false;  
	int y;
	int chooseType;
	int lev;
	ofstream outdisplay;
	outdisplay.open("displayResult.txt");
	system("color 80");

	for(int i=0; i<119 ; i++)
	{
	Sleep(100);
	cout<<"$";}
	cout<<endl<<"\n";
	cout<<"\t\t                 \xB2\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB9"<<endl;
	cout<<"\t\t                 \xB2\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB9"<<endl;
	cout<<"\t\t                 \xB2\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB9"<<endl;
	cout<<"\t\t                 \xB2\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB9"<<endl;
	cout<<"\t\t                 \xB2\xB1\xB1\xB1                              \xB1\xB1\xB1\xB9"<<endl;
	cout<<"\t\t                 \xB2\xB1\xB1\xB1     #       #    #       #   \xB1\xB1\xB1\xB9"<<endl;
	cout<<"\t\t                 \xB2\xB1\xB1\xB1     #       #    #      #    \xB1\xB1\xB1\xB9"<<endl;
	cout<<"\t\t                 \xB2\xB1\xB1\xB1     #       #    #     #     \xB1\xB1\xB1\xB9"<<endl;
	cout<<"\t\t                 \xB2\xB1\xB1\xB1     #-------#    #   #       \xB1\xB1\xB1\xB9"<<endl;
	cout<<"\t\t                 \xB2\xB1\xB1\xB1     #       #    #     #     \xB1\xB1\xB1\xB9"<<endl;
	cout<<"\t\t                 \xB2\xB1\xB1\xB1     #       #    #      #    \xB1\xB1\xB1\xB9"<<endl;
	cout<<"\t\t                 \xB2\xB1\xB1\xB1     #       #    #       #   \xB1\xB1\xB1\xB9"<<endl;
	cout<<"\t\t                 \xB2\xB1\xB1\xB1                              \xB1\xB1\xB1\xB9"<<endl;
	cout<<"\t\t                 \xB2\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB9"<<endl;
	cout<<"\t\t                 \xB2\xB1\xB1\xB1\xB1\xB1\xB1 HASKELL KINDERGARTEN \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB9        "<<endl;
	cout<<"\t\t                 \xB2\xB1\xB1\xB1\xB1\xB1\xB1     ONLINE TEST      \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB9         "<<endl;
	cout<<"\t\t                 \xB2\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB9        "<<endl;
	cout<<endl;
		for(int i=0; i<119 ; i++)
	{
	Sleep(100);
	cout<<"$";}
	PlaySound(TEXT("coun.wav"), NULL, SND_SYNC);
	PlaySound(TEXT("welcome.wav"), NULL, SND_SYNC);
	
   
	while(cont != 'N')
	{

        system("cls");
		cout<<"\t    ===========   KINDERGARTEN QUESTION BANK SYSTEM\t==========="<<endl;


		cout<<"\n\n"<<endl;
		cout<<"\t\t**Welcome to Kindergarten Question Bank System**"<<endl;
		cout<<"\n\t\t   <1> sign up \t\t <2> login "<<endl;
		cout<<"\n Please choose ? : ";
		cin>>chooseType;
		
   		switch(chooseType)
   		{
   			case 1: system("cls");
 					cout<<"\t\t*** You have choose to create an account ***"<<endl;
    	   			createAcc(Pers,TL);
			break;
			case 2: system("cls");
       				cout<<"\n\t\t\tWelcome Student!!!"<<endl;
       				cout<<"\n Please enter your Id number : ";
       				cin>>idNum;
       				
					found=findData2(Pers,TL,idNum);  
      				if(found==false)
      				{
             			cout<<"Sorry..The id number is not valid! "<<endl;
       				}
       				else
       				{
           				system("cls");
           				cout<<"\n\t\t\tSuccessfully Login !!"<<endl;
           				cout<<"\n\t\t\t---------------------"<<endl;
           				cout<<"\n\t\t<1> Quizzes \t\t <2> View Acc "<<endl;   
           				cout<<"\n Please Choose 1 or 2 : "; 
           				cin>>y;
           				cout<<"\n==========================================";
           				cout<<"======================================";
           				switch(y)
           				{
           					case 1:	system("cls");
            						cout<<"\n\t +++++++++++++++++++++++++Test LEVEL ++++++++++++++++++++++++++++++"<<endl;
             						cout<<"\t           1 - Easy                              3 - hard"<<endl;
             						cout<<"\t                          2 - Moderate"<<endl;
             						cout<<"\n Please choose which test level you want to proceed : ";
             						cin>>testL;
             
             						if(testL==1)
									{
                  						system("cls");
                  						testQuesL1();
                 				 		lev=1;    
                  						modifyLevel(Pers,TL,idNum,lev);  
             						}
             						else if(testL==2)
									{
                  						system("cls");
                  						testQuesL2();
                  						lev=2;
                  						modifyLevel(Pers,TL,idNum,lev);
             						}
             						else if(testL==3)
									{
                  						system("cls");
                  						testQuesL3(count);
                  						lev=3;
                  						modifyLevel(Pers,TL,idNum,lev);
            				 		}
       						break;
       						case 2: view(Pers,TL,idNum,outdisplay);
       						break;
					}
			   }
            }
          
              
            cout<<"\nContinue?(Y) or logout from system(N)): ";
		    cin>>cont;
            cout<<endl;
            
           if (cont=='N' || cont=='n')
		    {
            cout<<"\t\tYou have choose to logout from system"<<endl<<endl;
            cout<<"\t\t*** Thank You and Please Come Again ***"<<endl;
            system("pause");
		    return(0);
		    }
		   }
		   
		
	outdisplay.close();     
	system("pause");
}


void createAcc(PersonClass Pers[],Level TL[])
{
     char create;
     ofstream outFile("studentsData.txt",ios::out | ios::app); 
     
     
	
	 cout<<"\n\t\tDo You Want To Create New Account? (Y=yes/N=no) : ";    
	 cin>>create;

	 if(create=='N' || create=='n')
	 {
		exit(0);  
	 }
	 else
	 cout<<"\nPlease enter the Information : "<<endl;
	 
	 for(int x=0;x<20;x++)
	{
	 	cout<<"\nId Number : ";
	 	cin>>Pers[x].id;
	 
	 	cout<<"\nName  : ";
	 	cin>>ws;
	 	cin.getline(Pers[x].name,100);
	 
	 	cout<<"\nAge : ";
	 	cin>>Pers[x].age;

     	Pers[x].personType="Student";
        TL[x].L1=1;
        TL[x].L2=1;
        TL[x].L3=1;
        outFile << Pers[x].id << ",";
	    outFile << Pers[x].name << ",";
	    outFile << Pers[x].age << ",";
	    outFile << TL[x].L1 <<",";
        outFile << TL[x].L2 <<",";
        outFile << TL[x].L3 ;
	    outFile << endl;
	    cout<<"\n\n\nAccount "<<Pers[x].personType<<" Created......"<<endl;
	    break;
          
      }
		 
	 outFile.close();
  }

void view(PersonClass Pers[],Level TL[],int idNum,ofstream& outdisplay)
{
     int index;
     
     string level1,level2,level3;
     
     ifstream inFile("studentsData.txt");
     ofstream outFile;
    
     for(int i=0;i<20;i++)
	 {
		inFile >> Pers[i].id;
		inFile.get();
		inFile.getline(Pers[i].name, 100, ',');
		inFile >> Pers[i].age;
		inFile.get();
		inFile >> TL[i].L1;
		inFile.get();
		inFile >> TL[i].L2;
		inFile.get();
		inFile >> TL[i].L3;
		inFile.get();
	 } 
	 
	for (int i = 0; i < 20; i++)
	{
		if (Pers[i].id == idNum)
		{
			index = i;
			break;
		}
	}
	
	if(TL[index].L1 == 1)
	{
        level1="not completed!";
    }
    else if(TL[index].L1==2)
	{
        level1="completed!";
    }
        
    if(TL[index].L2 == 1)
	{
        level2="not completed!";
    }
    else if(TL[index].L2==2)
	{
        level2="completed!";
	}
        
    if(TL[index].L3 == 1)
	{
        level3="not completed!";
    }
    else if(TL[index].L3==2)
	{
        level3="completed!";
	}
	
	 cout<<"\n\t\t-----View Student------"<<endl;
	 cout<<"\n\tId   : "<< Pers[index].id <<endl;
	 cout<<"\n\tName : "<< Pers[index].name<<endl;
	 cout<<"\n\tAge  : "<< Pers[index].age<<endl;
	 cout<<"\n\tLevel 1  : "<< level1<<endl;
	 cout<<"\n\tLevel 2  : "<< level2<<endl;
	 cout<<"\n\tLevel 3  : "<< level3<<endl;
	 cout<<""<<endl;
	 
	 outdisplay<<"\n\t\t-----View Student------"<<endl;
	 outdisplay<<"\n\tId   : "<< Pers[index].id <<endl;
	 outdisplay<<"\n\tName : "<< Pers[index].name<<endl;
	 outdisplay<<"\n\tAge  : "<< Pers[index].age<<endl;
	 outdisplay<<"\n\tLevel 1  : "<< level1<<endl;
	 outdisplay<<"\n\tLevel 2  : "<< level2<<endl;
	 outdisplay<<"\n\tLevel 3  : "<< level3<<endl;
	 outdisplay<<""<<endl;

}

bool findData2(PersonClass Pers[],Level TL[],int noAcc)
{
	ifstream inFile("studentsData.txt");
	bool found=false; 
	int i=0; 
	
	while(inFile>>Pers[i].id) 
	{

		inFile.get();
		inFile.getline(Pers[i].name, 100, ',');
		inFile >> Pers[i].age;
		inFile.get();
		inFile >> TL[i].L1;
		inFile.get();
		inFile >> TL[i].L2;
		inFile.get();
		inFile >> TL[i].L3;
		inFile.get();
		
		
		
		if(noAcc == Pers[i].id)
		{
			found = true;
			return found;
		}
		else
		  i++;
	 }


	inFile.close();
	

}

int countData(PersonClass Pers[],Level TL[])
{
    int count=0;
    int i=0;
    std::string line;
    ifstream inFile("studentsData.txt");
    
    while(std::getline(inFile,line))
    {
    	count++;	
    }
    inFile.close();
    return count;
}


void modifyLevel(PersonClass Pers[],Level TL[],int noAcc,int lev)
{
     int numData=countData(Pers,TL),index;
     
     PersonClass *array;
     array = new PersonClass[numData];
     
     Level *array1;
     array1 = new Level[numData];
     
     cout<<"numdata:"<<numData;
     
     ifstream inFile("studentsData.txt");
     ofstream outFile;
     
    for(int i=0;i<numData;i++)
	 {
		inFile >> array[i].id;
		inFile.get();
		inFile.getline(array[i].name, 100, ',');
		inFile >> array[i].age;
		inFile.get();
		inFile >> array1[i].L1;
		inFile.get();
		inFile >> array1[i].L2;
		inFile.get();
		inFile >> array1[i].L3;
		inFile.get();
		
		
	 } 
	 
     inFile.close();
     
	for (int i = 0; i < numData; i++)
	{
		if (array[i].id == noAcc)
		{
			index = i;
			break;
		}
	}
	if(lev==1)
	{
      array1[index].L1 = 2;
	}
    else if(lev==2)
	{
      array1[index].L2 = 2;
	}
    else if(lev==3)
	{
      array1[index].L3 = 2;
	}
      
	outFile.open("studentsData.txt", ios::out);
	
	for (int i = 0; i < numData; i++)
	{
			outFile << array[i].id << ",";
			outFile << array[i].name    << ",";
			outFile << array[i].age<< ",";
			outFile << array1[i].L1 <<",";
            outFile << array1[i].L2 <<",";
            outFile << array1[i].L3 ;
			outFile << endl;
		
	}
	
	outFile.close();
	cout<<"\n\n\n\t\tStatus updated..."<<endl;

	inFile.close();
	outFile.close();
}	 
	 
void testQuesL1()
{
     
     char L1q1,L1q4;
     int L1q2,L1q3;
     char L1q5[100];
     
     cout<<"\n\n\t\t\t\tLEVEL 1";
     cout<<"\n\t\t\t\t--------------";
     cout<<"\n\t  Anda dikehendaki menjawab semua soalan dengan betul!"<<endl;
     cout<<"\t     You have to answer all the questions correctly!"<<endl;
   
     cout<<"\n* Soalan 1 *"<<endl;
     cout<<"\n\t ______"<<endl;
     cout<<"\t|"<<endl;
     cout<<"\t|______"<<endl;
     cout<<"\t|"<<endl;
     cout<<"\t|______"<<endl; 
     cout<<"\n\nApakah huruf yang patut diletakkan selepas huruf E? : ";
     cin>>L1q1;
     
     while(L1q1!='F' && L1q1!='f')
     {
         cout<<"\n\t\tCuba Lagi !!"<<endl;
         cout<<"\n\nApakah huruf yang patut diletakkan selepas huruf E? : ";
         cin>>L1q1;
     }
     
     if (L1q1=='F' || L1q1=='f')
     {
         cout<<"\n\t\tBetul !!";
          
     }

     cout<<endl;
     cout<<"\n\n* Soalan 2 *"<<endl;
     cout<<"\n\t  3 4 5 _ 7 8 9  "<<endl;
     cout<<"\nApakah nombor yang perlu diisi di tempat kosong? : ";
     cin>>L1q2;
     
     while(L1q2!=6)
     {
         cout<<"\n\t\tCuba Lagi !!"<<endl;
         cout<<"\nApakah nombor yang perlu diisi di tempat kosong? : ";
         cin>>L1q2;
     }
     
     if (L1q2==6)
     {
         cout<<"\n\t\tBetul !!";
           
     }

     cout<<endl;
     cout<<"\n\n* Soalan 3 *"<<endl;
     cout<<"\n\t 8 7 6 5 4 _ 2 1  "<<endl;
     cout<<"\nApakah nombor yang perlu diisi di tempat kosong? : ";
     cin>>L1q3;
     
     while(L1q3!=3)
     {
         cout<<"\n\t\tCuba Lagi !!"<<endl;
         cout<<"\nApakah nombor yang perlu diisi di tempat kosong? : ";
         cin>>L1q3;
     }
     
     if(L1q3==3)
     {
         cout<<"\n\t\tBetul !!";
          
     }
   
     cout<<endl;
     cout<<"\n\n* Question 4 *"<<endl;
     cout<<"\n\t BOOK  "<<endl;
     cout<<"\nWhat is the first letter of the word above? : ";
     cin>>L1q4;
     
     while(L1q4!='B' && L1q4!='b')
     {
         cout<<"\n\t\tTry Again !!"<<endl;
         cout<<"\nWhat is the first letter of the word above? : ";
         cin>>L1q4;
     }
     
     if(L1q4=='B' || L1q4=='b')
     {
         cout<<"\n\t\tCorrect !!";
           
     }

     cout<<endl;
     cout<<"\n\n* Soalan 5 *"<<endl;
     cout<<"\t  _______________  "<<endl;
     cout<<"\t <_______________>' "<<endl;
     cout<<"\t |   _       _   | "<<endl;
     cout<<"\t |  |+|     |+|  | "<<endl;
     cout<<"\t |       __      | "<<endl;
     cout<<"\t |      |  |     | "<<endl;
     cout<<"\t |______|__|_____| "<<endl;
     
     cout<<"\nGambar di atas menunjukkan sebuah apa? Ejakan r_m_h : ";
     cin>>L1q5;
     
     while(strcmp(L1q5,"rumah")!=0)
     {
         cout<<"\n\t\tCuba Lagi !!"<<endl;
         cout<<"\nGambar di atas menunjukkan sebuah apa? Ejakan r_m_h :  ";
         cin>>L1q5;
     
     }
     
     if (strcmp(L1q5,"rumah")==0)
     {
         cout<<"\n\t\tBetul !!";
           
     }
	 
	 cout<<endl;
	 cout<<"\n"<<endl;
     cout<<"   ** Anda telah berjaya menjawab kesemua soalan di Level 1. Tahniah !!! **"<<endl;
     cout<<"** You have successfully answered all the questions in Level 1. Congrats !!! **"<<endl;
     PlaySound(TEXT("clap.wav"), NULL, SND_SYNC);

     
	 
}
	 
void testQuesL2(){
     
     char L2q1,L2q3;
     int L2q2,L2q4;
     char L2q5[100];
     
     cout<<"\n\n\t\t\t\tLEVEL 2";
     cout<<"\n\t\t\t\t--------------";
     cout<<"\n\t  Anda dikehendaki menjawab semua soalan dengan betul!"<<endl;
     cout<<"\t     You have to answer all the questions correctly!"<<endl;
     //quest. 1 ......................................
     cout<<"\n* Soalan 1 *"<<endl;
     cout<<"\t  _________"<<endl;
     cout<<"\t |         |"<<endl;
     cout<<"\t |         |"<<endl;
     cout<<"\t |         |"<<endl;
     cout<<"\t |_________|"<<endl; 
     cout<<"\n\nApakah bentuk gambar di atas? "<<endl;
     cout<<"\t a - bulat"<<endl;
     cout<<"\t b - segi tiga"<<endl;
     cout<<"\t c - segi empat"<<endl;
     cout<<"Jawapan (a/b/c) : ";
     cin>>L2q1;
     
     while(L2q1!='C' && L2q1!='c')
     {
         cout<<"\n\t\tCuba Lagi !!"<<endl;
         cout<<"\n\nApakah bentuk gambar di atas? "<<endl;
         cout<<"\t a - bulat"<<endl;
         cout<<"\t b - segi tiga"<<endl;
         cout<<"\t c - segi empat"<<endl;
         cout<<"Jawapan (a/b/c) : ";
         cin>>L2q1;
     }
     
     if (L2q1=='C' || L2q1=='c')
     {
         cout<<"\n\t\tBetul !!";
          
     }

     cout<<endl;
     cout<<"\n\n* Question 2 *"<<endl;
     cout<<"\n\t    ___    ___              ___        "<<endl;
     cout<<"\n\t   [^_^]  [^_^]            [^_^]       "<<endl;
     cout<<"\n\t       ___         +     ___    ___    "<<endl;
     cout<<"\n\t      [^_^]             [^_^]  [^_^]   "<<endl;
     cout<<"\n\t                                       "<<endl;
     cout<<"\n\t  "<<endl;
     cout<<"\nHow many smiling face are there? : ";
     cin>>L2q2;
     
     while(L2q2!=6)
     {
         cout<<"\n\t\tTry Again !!"<<endl;
         cout<<"\nHow many smiling face are there? : ";
         cin>>L2q2;
     }
     
     if (L2q2==6)
     {
         cout<<"\n\t\tCorrect !!";
           
     }

     cout<<endl;
     cout<<"\n\n* Question 3 *"<<endl;
     cout<<"\n\t  PINEAPPLE  "<<endl;
     cout<<"\nWhat is the third letter of the word above? : ";
     cin>>L2q3;
     
     while(L2q3!='N' && L2q3!='n' )
     {
         cout<<"\n\t\tTry Again !!"<<endl;
         cout<<"\nWhat is the third letter of the word above? : ";
         cin>>L2q3;
     }
     
     if(L2q3=='N' || L2q3=='n')
     {
         cout<<"\n\t\tCorrect !!";
          
     }
     
     cout<<endl;
     cout<<"\n\n* Question 4 *"<<endl;
     cout<<"\n\t 3 + 4 = ? "<<endl;
     cout<<"\nWhat is the answer for the question above? : ";
     cin>>L2q4;
     
     while(L2q4!=7)
     {
         cout<<"\n\t\tTry Again !!"<<endl;
         cout<<"\nWhat is the answer for the question above? : ";
         cin>>L2q4;
     }
     
     if(L2q4==7)
     {
         cout<<"\n\t\tCorrect !!";
           
     }

     cout<<endl;
     cout<<"\n\n* Soalan 5 *"<<endl;
     cout<<"\t   "<<endl;
     cout<<"\t   ____     "<<endl;
     cout<<"\t  (    )    "<<endl;
     cout<<"\t (      )    "<<endl;
     cout<<"\t (_]__[_)  "<<endl;
     cout<<"\t    ][    "<<endl;
     cout<<"\t    ][    "<<endl;
     cout<<"\t           "<<endl;
     
     
     cout<<"\nGambar di atas menunjukkan sebuah apa? Ejakan _o_ok : ";
     cin>>L2q5;
     
     while(strcmp(L2q5,"pokok")!=0)
     {
         cout<<"\n\t\tCuba Lagi !!"<<endl;
         cout<<"\nGambar di atas menunjukkan sebuah apa? Ejakan _o_ok :  ";
         cin>>L2q5;
     
     }
     
     if(strcmp(L2q5,"pokok")==0)
     {
         cout<<"\n\t\tBetul !!";
           
     }
	 
	 cout<<endl;
	 cout<<"\n"<<endl;
     cout<<"    ** Anda telah berjaya menjawab kesemua soalan di Level 2. Tahniah !!! **"<<endl;
     cout<<"** You have successfully answered all the questions in Level 2. Congrats !!! **"<<endl;
	 PlaySound(TEXT("clap.wav"), NULL, SND_SYNC); 
}

void testQuesL3(countTotal count)
{     
     char L3q1;
     int L3q2,L3q3,L3q4;
     char L3q5[100];
     
     cout<<"\n\n\t\t\t\tLEVEL 3";
     cout<<"\n\t\t\t\t--------------";
     cout<<"\n\t  Anda dikehendaki menjawab semua soalan dengan betul!"<<endl;
     cout<<"\t     You have to answer all the questions correctly!"<<endl;
     //quest. 1 ......................................
     cout<<"\n* Soalan 1 *"<<endl;
     cout<<"\t  _________       _________         _________     "<<endl;
     cout<<"\t |         |     |         |       |         |    "<<endl;
     cout<<"\t |    2    |  +  |         |  =    |    8    |    "<<endl;
     cout<<"\t |_________|     |_________|       |_________|    "<<endl; 
     cout<<"\n\nNombor apakah yang harus ditempatkan dalam kotak kosong diatas? "<<endl;
     cout<<"\t a - 5"<<endl;
     cout<<"\t b - 6"<<endl;
     cout<<"\t c - 7"<<endl;
     cout<<"Jawapan (a/b/c) : ";
     cin>>L3q1;
     
     while(L3q1!='B' && L3q1!='b')
     {
         cout<<"\n\t\tCuba Lagi !!"<<endl;
         cout<<"\n\nNombor apakah yang harus ditempatkan dalam kotak kosong diatas? "<<endl;
         cout<<"\t a - 5"<<endl;
         cout<<"\t b - 6"<<endl;
         cout<<"\t c - 7"<<endl;
         cout<<"Jawapan (a/b/c) : ";
         cin>>L3q1;
     }
     
     if (L3q1=='B' || L3q1=='b')
     {
         cout<<"\n\t\tBetul !!";
          
     }
     //end quest.1 ..................................
     
     //quest. 2 .....................................
     cout<<endl;
     cout<<"\n\n* Question 2 *"<<endl;
     cout<<"\n\t    ___    ___             ___              ___    "<<endl;
     cout<<"\n\t   [^_^]  [^_^]           [^_^]            [^_^]    "<<endl;
     cout<<"\n\t       ___         +    ___    ___     -          = ? "<<endl;
     cout<<"\n\t      [^_^]            [^_^]  [^_^]               "<<endl;
     cout<<"\n\t                                                  "<<endl;
     cout<<"\n\t  "<<endl;
     cout<<"\nHow many smiling face will be left? : ";
     cin>>L3q2;
     
     while(L3q2!=5)
     {
         cout<<"\n\t\tTry Again !!"<<endl;
         cout<<"\nHow many smiling face will be left? : ";
         cin>>L3q2;
     }
     
     if (L3q2==5)
     {
         cout<<"\n\t\tCorrect !!";
           
     }
     
     cout<<endl;
     cout<<"\n\n* Question 3 *"<<endl;
     cout<<"\n\t Enter the first number (1-10) : " ;
     cin>>count.num1;
     cout<<"\n\t Enter the second number (1-10) : " ;
     cin>>count.num2;
     
     int total;
     total=count.num1+count.num2;
     cout<<"\n\t _____       _____ "<<endl;
     cout<<"\n\t| "<<count.num1<<"    |   +   | "<<count.num2<<"  |  = what number should be here? "<<endl;
     cout<<"\n\t _____       _____                          									   "<<endl;
     cout<<"\nAnswer : ";
     cin>>L3q3;
     
     while(L3q3!=total)
     {
         cout<<"\n\t\tTry Again !!"<<endl;
         cout<<"\nAnswer : ";
         cin>>L3q3;
     }
     
     if(L3q3==total)
     {
         cout<<"\n\t\tCorrect !!";
          
     }

     cout<<endl;
     cout<<"\n\n* Question 4 *"<<endl;
     cout<<"\n\t 8 + 2 = ? "<<endl;
     cout<<"\nWhat is the answer for the question above? : ";
     cin>>L3q4;
     
     while(L3q4!=10)
     {
         cout<<"\n\t\tTry Again !!"<<endl;
         cout<<"\nWhat is the answer for the question above? : ";
         cin>>L3q4;
     }
     
     if(L3q4==10)
     {
         cout<<"\n\t\tCorrect !!";
           
     }


     cout<<endl;
     cout<<"\n\n* Soalan 5 *"<<endl;
     cout<<"\t Masukkan satu nombor (1-9) : ";
     cin>>count.num3;
     
     for(int i=0;i<count.num3;i++){
             
        cout<<"\t  __  "<<endl;
        cout<<"\t (  ) "<<endl;
        cout<<"\t (][) "<<endl;
        cout<<"\t  ][  "<<endl;
     }
     
     
     
     cout<<"\nGambar di atas menunjukkan sebuah apa? Ejakan p_k_k : ";
     cin>>L3q5;
     
     while(strcmp(L3q5,"pokok")!=0)
     {
         cout<<"\n\t\tCuba Lagi !!"<<endl;
         cout<<"\nGambar di atas menunjukkan sebuah apa? Ejakan _o_ok :  ";
         cin>>L3q5;
     
     }
     
     if (strcmp(L3q5,"pokok")==0)
     {
         cout<<"\n\t\tBetul !!";
           
     }

	 cout<<endl;
	 cout<<"\n"<<endl;
     cout<<"    ** Anda telah berjaya menjawab kesemua soalan di Level 3. Tahniah !!! **"<<endl;
     cout<<"** You have successfully answered all the questions in Level 3. Congrats !!! **"<<endl;
     PlaySound(TEXT("clap.wav"), NULL, SND_SYNC);

}


