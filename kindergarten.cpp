#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

struct PersonClass
{
       char name[100];
       int id;
       int age;
       char type;
       string personType;
} Pers;

struct Level{
       int L1;
       int L2;
       int L3;
} TL;

struct newClass{
       int newId;
       int newAge;
       char newName[100];
       char newType;
} nw;
       

void testQuesL1();
void testQuesL2();
void testQuesL3();
void createAcc (); //admin + student
void view(); //student only
void modify(); //student only
bool findData(int noAcc); //admin + student
bool findData2(int noAcc,int chooseType);
int countData(); 
void deleteData(int noAcc); //student only
void deleteAcc(); //student only
void modifyLevel(int noAcc,int lev); //student only

//main ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main(void)
{
	int choose,idNum,testL;
	char proceed;
	char cont;
	bool found=false;  
	int y;
	int chooseType;
	int lev;
	
   
	while(cont != 'N')
	{

        system("cls");
		cout<<"\t    ===========   KINDERGARTEN QUESTION BANK SYSTEM\t=";
        cout<<"========="<<endl;

		cout<<"\n\n"<<endl;
		cout<<"\t\t**Welcome to Kindergarten Question Bank System**"<<endl;
		cout<<"\n\t\t   1 - Admin \t\t 2 - Student "<<endl;
		cout<<"\n Are you an Admin or Student ? : ";
		cin>>chooseType;
		
      //if admin----------------------------------------------------------------
      if(chooseType==1){
        system("cls");
       cout<<"\n\t\t\t\tWelcome Admin!!!"<<endl;
       cout<<"\n Please enter your Id number : ";
       cin>>idNum;
       
	   found=findData2(idNum,chooseType); //use findData function
       
       if(found==false)
       {
             cout<<"Sorry..The id number is not valid! "<<endl;
       }
       else {   
        system("cls");              
		cout<<"\t\t   ....PLEASE CHOOSE WHAT U WANT TO DO....  "<<endl;

		cout<<"\n"<<endl;
	 	cout<<" \t  <1>create new account      ";
	 	cout<<" \t   <2>modify account";
    	cout<<"\n\n\t  <3>delete account";
    	cout<<" \t\t   <4>view account\n\n"<<endl;
    	cout<<"\n\n";

		cout<<"\t\tPlease Select Your Choice"<<endl;
		cout<<"\t\tEnter number 1 or 2 or 3 or 4 to choose : ";
		cin>>choose;
		cout<<"\n\n"<<endl;
		
	
		if (choose==1)//choose the transaction
		{
            system("cls");
 			cout<<"\t\t*** You have choose to create an account ***"<<endl;
    	    createAcc();             
		}
		else if (choose==2)
		{ 
            system("cls");
	 	    cout<<"\t\t*** You have choose to modify student account ***"<<endl;
	      	modify(); 
		}
		
		else if(choose==3)
		{
             system("cls"); 
			cout<<"\t\t*** You have choose to delete student account ***"<<endl;
	        deleteAcc(); 
		}
		
		else if (choose==4)
		{ 
            system("cls");
	 	    cout<<"\t\t*** You have choose to view student account ***"<<endl;
	      	view(); 
		}
		
		cout<<"\nContinue?(Y) or logout from system(N)): ";//choose to logout
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
	  }
	  //close if admin----------------------------------------------------------
 
      //if student -------------------------------------------------------------
       else if(chooseType==2){
       system("cls");
       cout<<"\n\t\t\tWelcome Student!!!"<<endl;
       cout<<"\n Please enter your Id number : ";
       cin>>idNum;
       
	   found=findData2(idNum,chooseType);  
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
           if (y==1){
             system("cls");
             cout<<"\n\t +++++++++++++++++++++++++Test LEVEL ++++++++++++++++++++++++++++++"<<endl;
             cout<<"\t           1 - Easy                              3 - hard"<<endl;
             cout<<"\t                          2 - Moderate"<<endl;
             cout<<"\n Please choose which test level you want to proceed : ";
             cin>>testL;
             
             if(testL==1){
                  system("cls");
                  testQuesL1();
                  lev=1;    
                  modifyLevel(idNum,lev);   //to update level status (completed/incomplete)
             }
             else if(testL==2){
                  system("cls");
                  testQuesL2();
                  lev=2;
                  modifyLevel(idNum,lev);
             }
             else if(testL==3){
                  system("cls");
                  testQuesL3();
                  lev=3;
                  modifyLevel(idNum,lev);
             }
       
           }
           else if (y==2){
                view();
           }       
              
            cout<<"\nContinue?(Y) or logout from system(N)): ";//choose to logout
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
         //close if student ----------------------------------------------------
    }    
 }	
	system("pause");
}
//close main +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//function* admin---------------------------------------------------------------

//--create acc--
void createAcc()
{
     char create;
     ofstream outFile("studentsData.txt",ios::out | ios::app); 
	 ofstream outFile2("adminData.txt",ios::out | ios::app); 
	
	 cout<<"\n\t\tDo You Want To Create New Account? (Y=yes/N=no) : ";    
	 cin>>create;

	 if(create=='N' || create=='n')
	 {
		exit(0);   //kalau tekan N,output terus hilang 
	 }
	 
	 cout<<"\nPlease enter the Information : "<<endl;
	 
	 cout<<"\nId Number : ";
	 cin>>Pers.id;
	 
	 cout<<"\nName  : ";
	 cin>>ws;
	 cin.getline(Pers.name,100);
	 
	 cout<<"\nAge : ";
	 cin>>Pers.age;
	 
	 cout<<"\nType of Account (A-Admin / S-Student) : ";
	 cin>>Pers.type;
	 
	 if(Pers.type=='A'){
           Pers.personType="Admin";
           
           outFile2 << Pers.id << ",";
	       outFile2 << Pers.name << ",";
	       outFile2 << Pers.age << ",";
	       outFile2 << Pers.type;
	       outFile2 << endl;}
     else {
          Pers.personType="Student";
          TL.L1=1;
          TL.L2=1;
          TL.L3=1;
          outFile << Pers.id << ",";
	      outFile << Pers.name << ",";
	      outFile << Pers.age << ",";
	      outFile << Pers.type << ",";
	      outFile << TL.L1 <<",";
          outFile << TL.L2 <<",";
          outFile << TL.L3 ;
	      outFile << endl;}
          
	
	 cout<<"\n\n\nAccount "<<Pers.personType<<" Created......"<<endl;
	 
	 outFile.close();
  }
//--create acc-- close

//--view acc--
void view()
{
     int numData=countData(),index;
     
     string level1,level2,level3;
     PersonClass *array;
     array = new PersonClass[numData];
     
     Level *array1;
     array1 = new Level[numData];
     
     ifstream inFile("studentsData.txt");
     ofstream outFile;
     
     cout<<"\nEnter Student Id no : ";
     cin>>Pers.id;
     
     for(int i=0;i<numData;i++)
	 {
		inFile >> array[i].id;
		inFile.get();
		inFile.getline(array[i].name, 100, ',');
		inFile >> array[i].age;
		inFile.get();
		inFile >> array[i].type;
		inFile.get();
		inFile >> array1[i].L1;
		inFile.get();
		inFile >> array1[i].L2;
		inFile.get();
		inFile >> array1[i].L3;
		inFile.get();
	 } 
	 
     //	Check which index is the account to be changed
	for (int i = 0; i < numData; i++)
	{
		if (array[i].id == Pers.id)
		{
			index = i;
			break;
		}
	}
	
	//check level status 
	if(array1[index].L1 == 1){
        level1="not completed!";
    }
    else{
        level1="completed!";
    }
        
    if(array1[index].L2 == 1){
        level2="not completed!";
    }
    else {
        level2="completed!";}
        
    if(array1[index].L3 == 1){
        level3="not completed!";
    }
    else{
        level3="completed!";}
	
	 cout<<"\n\t\t-----View Student------"<<endl;
	 cout<<"\n\tId   : "<< array[index].id <<endl;
	 cout<<"\n\tName : "<< array[index].name<<endl;
	 cout<<"\n\tAge  : "<< array[index].age<<endl;
	 cout<<"\n\tLevel 1  : "<< level1<<endl;
	 cout<<"\n\tLevel 2  : "<< level2<<endl;
	 cout<<"\n\tLevel 3  : "<< level3<<endl;
	 cout<<""<<endl;
	 
	 inFile.close();
}
//--view acc-- close


//--modify acc--
void modify()
{
     int numData=countData(),index,change;
     
     PersonClass *array;
     array = new PersonClass[numData];
     
     Level *array1;
     array1 = new Level[numData];
     
     newClass nw;
     
     ifstream inFile("studentsData.txt");
     ofstream outFile;
     
     cout<<"\nEnter Id no :";
     cin>>Pers.id;
     //input all acc data
     for(int i=0;i<numData;i++)
	 {
		inFile >> array[i].id;
		inFile.get();
		inFile.getline(array[i].name, 100, ',');
		inFile >> array[i].age;
		inFile.get();
		inFile >> array[i].type;
		inFile.get();
		inFile >> array1[i].L1;
		inFile.get();
		inFile >> array1[i].L2;
		inFile.get();
		inFile >> array1[i].L3;
		inFile.get();
			
	 } 
	 
     inFile.close();
     
     //	Check which index is the account to be changed
	for (int i = 0; i < numData; i++)
	{
		if (array[i].id == Pers.id)
		{
			index = i;
			break;
		}
	}
	
	 cout<<"\n";
	 cout<<" "<<endl;
	 cout<<"1. Name   "<<endl;
	 cout<<"2. Age    "<<endl;
	 cout<<"3. Type of Acc"<<endl;
	 cout<<"\n";
	 cout<<"Please enter <1/2/3> which one to modify ? : ";
	 cin>>change;
    
	 
	 if(change==1)
	 {
	 	cout<<"Enter The New Name of Account Holder : ";
		cin>>ws;   //bg hilgkn space
		cin.getline(nw.newName,100);

		strcpy(array[index].name, nw.newName);
	 }
	 else if(change==2)
	 {
	   	cout<<"\nThe New Age : ";
		cin>>nw.newAge;
		
		array[index].age = nw.newAge;
	 }
	 
	 else if(change==3)
	 {
		cout<<"Enter The New Type of Account <C/S> : ";
		cin>>nw.newType;

		array[index].type = nw.newType;
	 }
//	Update account file
	outFile.open("studentsData.txt", ios::out);
	for (int i = 0; i < numData; i++)
	{

			outFile << array[i].id << ",";
			outFile << array[i].name << ",";
			outFile << array[i].age<< ",";
			outFile << array[i].type <<",";
			outFile << array1[i].L1 <<",";
            outFile << array1[i].L2 <<",";
            outFile << array1[i].L3 ;
			outFile << endl;
		
	}
	outFile.close();
//to avoid dangling pointer	
	delete [] array;
	delete [] array1;
	
	 cout<<"\n\n\n\t\tAccount Already updated..."<<endl;
	 cout<<"\t\tThank You :)"<<endl;

	outFile.close();
}	 
	 
//--modify acc-- close	 
	 


//--find data--
bool findData(int noAcc)
{
	ifstream inFile("studentsData.txt");
	ifstream inFile2("adminData.txt");
	bool found=false;   //kalau true dye akn next,kalau false,dye akn teruskn 
	//looping n kalau tak jumpa,,display tak jumpa...
     
	while(inFile>>Pers.id) //find data utk student 
	{

		inFile.get();
		inFile.getline(Pers.name, 100, ',');
		inFile >> Pers.age;
		inFile >> Pers.type;
		inFile.get();
		inFile >> TL.L1;
		inFile >> TL.L2;
		inFile >> TL.L3;
		
		
		
		if(noAcc == Pers.id)
		{
			found = true;
		}
	 }
	 
	 while(inFile2>>Pers.id)   //find data utk admin
	{

		inFile2.get();
		inFile2.getline(Pers.name, 100, ',');
		inFile2 >> Pers.age;
		inFile2 >> Pers.type;
		inFile2.get();
		
		if(noAcc == Pers.id)
		{
			found = true;
		}
	 }
	 
	inFile.close();
	
	return found;
}
//--find data-- close 

//find data 2
//--find data--
bool findData2(int noAcc,int chooseType)
{
	ifstream inFile("studentsData.txt");
	ifstream inFile2("adminData.txt");
	bool found=false;   //kalau true dye akn next,kalau false,dye akn teruskn 
	//looping n kalau tak jumpa,,display tak jumpa...
  if(chooseType==2){
	while(inFile>>Pers.id) //find data utk student 
	{

		inFile.get();
		inFile.getline(Pers.name, 100, ',');
		inFile >> Pers.age;
		inFile.get();
		inFile >> Pers.type;
		inFile.get();
		inFile >> TL.L1;
		inFile.get();
		inFile >> TL.L2;
		inFile.get();
		inFile >> TL.L3;
		inFile.get();
		
		
		
		if(noAcc == Pers.id)
		{
			found = true;
		}
	 }
  }
  else{	 
	 while(inFile2>>Pers.id)   //find data utk admin
	{

		inFile2.get();
		inFile2.getline(Pers.name, 100, ',');
		inFile2 >> Pers.age;
		inFile2 >> Pers.type;
		inFile2.get();
		
		if(noAcc == Pers.id)
		{
			found = true;
		}
	 }
  }	 
	inFile.close();
	
	return found;
}
//
//to count the number of user data
int countData()
{
    int count=0;
    ifstream inFile("studentsData.txt");
    while(inFile>>Pers.id)
    {
		inFile.get();
		inFile.getline(Pers.name, 100, ',');
		inFile >> Pers.age;
		inFile >> Pers.type;
		inFile.get();
		inFile >> TL.L1;
		inFile >> TL.L2;
		inFile >> TL.L3;
		
		count++;
    }
    inFile.close();
    return count;
}


//--delete data--
void deleteData(int noAcc)
{
    int numData=countData();
	PersonClass *array;
	ifstream inFile("studentsData.txt");
	ofstream outFile;

	array = new PersonClass[numData];
    
    Level *array1;
    array1 = new Level[numData];

	for(int i=0;i<numData;i++)
	{
		inFile >> array[i].id;
		inFile.get();
		inFile.getline(array[i].name, 100, ',');
		inFile >> array[i].age;
		inFile >> array[i].type;
		inFile.get();
		inFile >> array1[i].L1;
		inFile >> array1[i].L2;
		inFile >> array1[i].L3;
		
		
	} 
	inFile.close();


	outFile.open("studentsData.txt", ios::out);
	for (int i = 0; i < numData; i++)
	{
		if (array[i].id != noAcc)
		{
			outFile << array[i].id  << ",";
			outFile << array[i].name    << ",";
			outFile << array[i].age  << ",";
			outFile << array[i].type <<",";
			outFile << array1[i].L1 <<",";
            outFile << array1[i].L2 <<",";
            outFile << array1[i].L3 ;
			outFile << endl;
		}
	}
	outFile.close();
}
//to whole user account                    
void deleteAcc()
{
     int noAcc;
     char sureDel;
     bool found=false;
	cout<<"\n\tPlease enter the id no that you want to delete: ";
    cin>>noAcc;
    
    found=findData(noAcc);
    if(found==false)
    {
             cout<<"Sorry..The id number is not valid! "<<endl;
    }
    else
    {
            cout<<"Are you sure you want to delete this id account? (Y-yes or N-no) ";
            cin>>sureDel;
            if(sureDel == 'Y' || sureDel == 'y' )   
            {
                      deleteData(noAcc);
                      cout<<"Your id account has been deleted..thank you! "<<endl;
            }
            else if(sureDel == 'N' || sureDel == 'n')
            {
                         system("pause");
            }
            else
            {
                cout<<"Are you sure you want to delete this id account? (Y-yes or N-no) ";
                cin>>sureDel;
            }
    }
}
//--delete data-- close 

//close Admin-------------------------------------------------------------------

//update level status

void modifyLevel(int noAcc,int lev)
{
     int numData=countData(),index;
     
     PersonClass *array;
     array = new PersonClass[numData];
     
     Level *array1;
     array1 = new Level[numData];
     
     
     ifstream inFile("studentsData.txt");
     ofstream outFile;
     
     
     
     for(int i=0;i<numData;i++)
	 {
		inFile >> array[i].id;
		inFile.get();
		inFile.getline(array[i].name, 100, ',');
		inFile >> array[i].age;
		inFile.get();
		inFile >> array[i].type;
		inFile.get();
		inFile >> array1[i].L1;
		inFile.get();
		inFile >> array1[i].L2;
		inFile.get();
		inFile >> array1[i].L3;
		inFile.get();
		
		
	 } 
	 
     inFile.close();
     
     //	Check which index is the account to be changed
	for (int i = 0; i < numData; i++)
	{
		if (array[i].id == noAcc)
		{
			index = i;
			break;
		}
	}
	if(lev==1){
      array1[index].L1 = 2;}
    else if(lev==2){
      array1[index].L2 = 2;}
    else if(lev==3){
      array1[index].L3 = 2;}
      
//	Update account file
	outFile.open("studentsData.txt", ios::out);
	for (int i = 0; i < numData; i++)
	{
			outFile << array[i].id << ",";
			outFile << array[i].name    << ",";
			outFile << array[i].age<< ",";
			outFile << array[i].type <<",";
			outFile << array1[i].L1 <<",";
            outFile << array1[i].L2 <<",";
            outFile << array1[i].L3 ;
			outFile << endl;
		
	}
	
	outFile.close();
//to avoid dangling pointer	
	delete [] array;
	delete [] array1;

	
	 cout<<"\n\n\n\t\tStatus updated..."<<endl;

	outFile.close();
}	 

//update level status -close-	 
	 
	 
//Questions---------------------------------------------------------------------
       
//Level 1 : 5 questions ********************************************************
void testQuesL1(){
     
     char L1q1,L1q4;
     int L1q2,L1q3;
     std::string L1q5;
     
     cout<<"\n\n\t\t\t\tLEVEL 1";
     cout<<"\n\t\t\t\t--------------";
     cout<<"\n\t  Anda dikehendaki menjawab semua soalan dengan betul!"<<endl;
     cout<<"\t     You have to answer all the questions correctly!"<<endl;
     //quest. 1 ......................................
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
     //end quest.1 ..................................
     
     //quest. 2 .....................................
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
     //end quest. 2 ...................................
     
     //quest. 3 .....................................
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
     //end question 3
     
     //quest. 4 .....................................
     
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
     //end question 4
     
     //quest. 5 .....................................
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
     
     while(L1q5.compare("rumah"))
     {
         cout<<"\n\t\tCuba Lagi !!"<<endl;
         cout<<"\nGambar di atas menunjukkan sebuah apa? Ejakan r_m_h :  ";
         cin>>L1q5;
     
     }
     
     if (!L1q5.compare("rumah"))
     {
         cout<<"\n\t\tBetul !!";
           
     }
     //end question 5
     
	 
	 
	 cout<<endl;
	 cout<<"\n"<<endl;
     cout<<"   ** Anda telah berjaya menjawab kesemua soalan di Level 1. Tahniah !!! **"<<endl;
     cout<<"** You have successfully answered all the questions in Level 1. Congrats !!! **"<<endl;
     
	 
}
	 
//end level 1 ******************************************************************

	 
//Level 2 : 5 questions ********************************************************
void testQuesL2(){
     
     char L2q1,L2q3;
     int L2q2,L2q4;
     std::string L2q5;
     
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
     //end quest.1 ..................................
     
     //quest. 2 .....................................
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
     //end quest. 2 ...................................
     
     //quest. 3 .....................................
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
     //end question 3
     
     //quest. 4 .....................................
     
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
     //end question 4
     
     //quest. 5 .....................................
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
     
     while(L2q5.compare("pokok"))
     {
         cout<<"\n\t\tCuba Lagi !!"<<endl;
         cout<<"\nGambar di atas menunjukkan sebuah apa? Ejakan _o_ok :  ";
         cin>>L2q5;
     
     }
     
     if (!L2q5.compare("pokok"))
     {
         cout<<"\n\t\tBetul !!";
           
     }
     //end question 5
     
	 
	 
	 cout<<endl;
	 cout<<"\n"<<endl;
     cout<<"    ** Anda telah berjaya menjawab kesemua soalan di Level 2. Tahniah !!! **"<<endl;
     cout<<"** You have successfully answered all the questions in Level 2. Congrats !!! **"<<endl;
     
	 
}


	 
//end level 2 ******************************************************************

//Level 3 : 5 questions ********************************************************
void testQuesL3(){
     
     char L3q1;
     int L3q2,L3q3,L3q4;
     std::string L3q5;
     
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
     //end quest. 2 ...................................
     
     //quest. 3 .....................................
     int num1,num2,total;
     
     cout<<endl;
     cout<<"\n\n* Question 3 *"<<endl;
     cout<<"\n\t Enter the first number (1-10) : " ;
     cin>>num1;
     cout<<"\n\t Enter the second number (1-10) : " ;
     cin>>num2;
     
     total=num1+num2;
     cout<<"\n\t _____       _____ "<<endl;
     cout<<"\n\t| "<<num1<<"  +  |      | "<<num2<<"  |  = what number "<<endl;
     cout<<"\n\t _____       _____                           should be here?"<<endl;
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
     //end question 3
     
     //quest. 4 .....................................
     
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
     //end question 4
     
     //quest. 5 .....................................
     int num3;
     cout<<endl;
     cout<<"\n\n* Soalan 5 *"<<endl;
     cout<<"\t Masukkan satu nombor (1-9) : ";
     cin>>num3;
     
     for(int i=0;i<num3;i++){
             
        cout<<"\t  __  "<<endl;
        cout<<"\t (  ) "<<endl;
        cout<<"\t (][) "<<endl;
        cout<<"\t  ][  "<<endl;
     }
     
     
     
     cout<<"\nGambar di atas menunjukkan sebuah apa? Ejakan p_k_k : ";
     cin>>L3q5;
     
     while(L3q5.compare("pokok"))
     {
         cout<<"\n\t\tCuba Lagi !!"<<endl;
         cout<<"\nGambar di atas menunjukkan sebuah apa? Ejakan _o_ok :  ";
         cin>>L3q5;
     
     }
     
     if (!L3q5.compare("pokok"))
     {
         cout<<"\n\t\tBetul !!";
           
     }
     //end question 5
     
	 
	 
	 cout<<endl;
	 cout<<"\n"<<endl;
     cout<<"    ** Anda telah berjaya menjawab kesemua soalan di Level 3. Tahniah !!! **"<<endl;
     cout<<"** You have successfully answered all the questions in Level 3. Congrats !!! **"<<endl;
     
	 
}


	 
//end level 2 ******************************************************************
