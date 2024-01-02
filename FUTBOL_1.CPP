/*

 FIFA Club Career Mode is a football club manager game that uses datafile
 handling and pointers among other C++ concepts like classes,structures,arrays and
 user defined functions,inheritance to create the ultimate football manager game
 that gives the player the experience of being a real football club owner

				      */


#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
fstream fout("team.dat",ios::out|ios::in|ios::binary);
fstream cfout("club.dat",ios::out|ios::in|ios::binary);


class play
{

  public:
  char name[50],country[50],position[4];
  int rating;




  void showplay()    //use datafile handling here...incomplete
  {
	cout<<name<<"\t\t"<<country<<"\t\t"<<position<<"\t\t"<<rating<<endl;

  }
};




class club
{
  char city[50],country[50];


  public:

  char manager[50],name[50];

  void getloc()     //to get the details of the club - name,location - from the user
  {

    cout<<"Enter name of your club : ";
    gets(name);    cfout<<name;
    cout<<"Enter city in which the club is located : ";
    gets(city);    cfout<<city;
    cout<<"Enter country in which the club is located : ";
    gets(country); cfout<<country;
   }
  void getman()
  {
    cout<<"Let's start easy! What is your name? : ";
    gets(manager);
   }
  void settings()
  {
    lbz : cout<<"What do you want to change? \n1)Name of the club \n2)City of the club \n3)Country of the club";
    int s;
    cin>>s;
    switch(s)
    {
       case 1: cout<<"Enter name of club: ";
	       gets(name);  cfout<<name;
	       break;


       case 2: cout<<"Enter city of club: ";
	       gets(city);   cfout<<city;
	       break;


       case 3: cout<<"Enter country of club: ";
	       gets(country);  cfout<<country;
	       break;

       case 4: break;

       default:  cout<<"You seem to have selected an invalid option! Please try again";
		 goto lbz;
     }

}

  void showclub()
  {

    cout<<"Name of the club : "<<name<<endl;
    cout<<"Location of the club : "<<city<<","<<country<<endl;
    cout<<"Manager of the club : "<<manager<<endl;
  }
};





void main()
{
  clrscr();
  club c;
  play team[6],marq[4],team2[6];


  {  //opponent team for simulation game
   strcpy(team2[0].name,"Karthikeyan");
   strcpy(team2[1].name,"Mayank");
   strcpy(team2[2].name,"Kapila");
   strcpy(team2[3].name,"Aryan");
   strcpy(team2[4].name,"Vishal");
   strcpy(team2[5].name,"Sai");
  }

  { //default team
    strcpy(team[0].name,"Raghu");  strcpy(team[0].country,"India"); strcpy(team[0].position,"GK");  team[0].rating=68;
    strcpy(team[1].name,"Satyaki"); strcpy(team[1].country,"India"); strcpy(team[1].position,"DEF") ; team[1].rating=61;
    strcpy(team[2].name,"Sharath"); strcpy(team[2].country,"India"); strcpy(team[2].position,"DEF"); team[2].rating= 62;
    strcpy(team[3].name,"Shiva"); strcpy(team[3].country,"India"); strcpy(team[3].position,"MID"); team[3].rating=63;
    strcpy(team[4].name,"Dhruv"); strcpy(team[4].country,"India"); strcpy(team[4].position,"MID"); team[4].rating=69;
    strcpy(team[5].name,"Nirvaan"); strcpy(team[5].country,"India"); strcpy(team[5].position,"FW"); team[5].rating=69;
  }
  { //list of marquee players

    strcpy(marq[0].name,"Courtois");strcpy(marq[0].country,"Belgium");strcpy(marq[0].position,"GK");marq[0].rating=87;
    strcpy(marq[1].name,"Varane");strcpy(marq[1].country,"France");strcpy(marq[1].position,"DEF"); marq[1].rating=85;
    strcpy(marq[2].name,"Modric"); strcpy(marq[2].country,"Croatia"); strcpy(marq[2].position,"MID"); marq[2].rating=90;
    strcpy(marq[3].name,"Muller");strcpy(marq[3].country,"Germany");strcpy(marq[3].position,"FW"); marq[3].rating=86;
  }




  char ch;

  cout<<"================================================================================";
  cout<<"Welcome to FIFA Club Career Mode Demo Edition! I am Steve and I am here to guide you in setting up your very own football club \n\nPress Y to proceed";

  cin>>ch;
  if(ch!='y' && ch!='Y')
  goto end;


  c.getman();

  cout<<"Alright,"<<c.manager<<",let's find out more about your dream club, which you're going to create\n";
  c.getloc();

  cout<<"Congratulations! You just set up your very own football club! Would you like to see your team? \n\nPress 'y' for yes ";
  cin>>ch;
  if(ch=='y' || ch=='Y')
  {
     cout<<"  Name "<<"\t\t"<<" Country "<<"\t"<<"Position"<<"\t"<<"Rating"<<endl;
     cout<<"______________________________________________________________"<<endl;
    for(int i=0; i<6 ; i++)
    {
       team[i].showplay();
    }
}


  cout<<"\nNow,you will need some marquee players,if you will need to get your team flying right away.\n";
  lb1 : cout<<endl;
	cout<<"0)Thibaut Courtois - Belgium - GK - 87"<<endl;;
	cout<<"1)Raphael Varane - France - DEF - 85"<<endl;
	cout<<"2)Luka Modric - Croatia - MID - 90"<<endl;
	cout<<"3)Thomas Muller - Germany - FW - 86"<<endl;


  cout<<"Choose one of the four above marquee players from above";
  int r;
  cin>>r;
  if(r>=0 && r<=3)
  {
     for(int i=0;i<6;i++)
     {
       if(!strcmp(team[i].position,marq[r].position))
       {
	strcpy(team[i].name,marq[r].name);
	strcpy(team[i].country,marq[r].country);
	strcpy(team[i].position,marq[r].position);
	team[i].rating=marq[r].rating;
	break;
	}
      }
   }
    else
    { cout<<endl<<"I'm sorry, the option does not exist! Please try again"<<endl;
     goto lb1;
    }


  lb:
  cout<<"Which operation would you like to perform? \nA)Play Online match \nB)Play offline simulation match \nC)View Club details \nD)Edit club settings \nE)Exit \n";
  cin>>ch;


  switch(ch)
  {
    case 'A' : case 'a' :  cout<<"OH NO! \nThis mode is available only in the full version of FIFA Club Career Mode. Buy now from your nearest retailer or from the PlayStation Network store! \n";
			   break;

    case 'B' : case 'b' :


  randomize();
  cout<<endl<<endl<<"Enter opponent teams' name";
  char oppo[50];  gets(oppo);

  char scorerA[10];
  char scorerB[10];
  int asc = 0;
  int bsc = 0;
  int sno = 0;
  int var1,var2,tiebreak;
  cout<<endl<<endl<<endl;
  cout<<"-------------"<<c.name<<" vs "<<oppo<<"----------"<<endl;


  for(int i=0; i<=90; i+=10)          //match begins
  {
     cout<<c.name<<"\t"<<i<<":00"<<"\t"<<oppo<<endl;
     var1=0; var2=0;



     var1=random(2); var2=random(2);
     if(var1==1&&var2==1)
     {
       tiebreak=random(3);
       if(tiebreak==0)
       {var1=0;var2=0;}              //so that only 1 team can score per min
       else if(tiebreak==1)
       {var1=1;var2=0;}
       else if(tiebreak==2)
       {var1=0;var2=1;}
     }

     asc = asc + var1; bsc = bsc + var2;       //counting total goals at that time


     if(i==0)                                 //score should be 0-0 at beginning
     {asc=0;bsc=0;}


     cout<<"   "<<asc<<"\t"<<"   "<<"\t"<<bsc<<endl;
      if(var1==1 && i!=0)
     {
       sno = random(6);

       cout<<"   "<<team[sno].name<<"("<<(i-10) + random(10)<<"')"<<endl;
     }                                        //assigning scorers
     else if(var2==1 && i!=0)
     {
       sno = random(6);
       cout<<"   "<<"   "<<"\t"<<"   "<<"\t"<<team2[sno].name<<"("<<(i-10) + random(10)<<"')"<<endl;
     }


     if(i==90)
     {
       cout<<"FULL TIME!!!!"<<endl<<"Score is "<<asc<<" - "<<bsc<<endl;
       if(asc>bsc)
       cout<<"MOTM : "<<team[random(6)].name;
       else if(asc<bsc)
       cout<<"MOTM : "<<team2[random(6)].name;
       else
       {
	 tiebreak=random(2);
	 if(tiebreak==0)
	 cout<<"MOTM : "<<team[random(6)].name;
	 else
	 cout<<"MOTM : "<<team2[random(6)].name;
       }
    }

     cout<<endl<<endl<<endl;
     delay(5000);
  }
  break;

    case 'C' : case 'c' :  c.showclub();
			   cout<<endl;
			   cout<<"Name "<<"\t\t"<<"Country "<<"\t"<<"Position"<<"\t"<<"Rating"<<endl;
			   cout<<"______________________________________________________________"<<endl;
			   for(int j=0; j<6 ; j++)
			   {
			     team[j].showplay();
			   }
			   break;


    case 'D' : case 'd' :  c.settings();
			   break;


    case 'E' : case 'e' :  goto end;

    default  :             cout<<"Your choice seems unclear. Please try again \n";
			   goto lb;
   }

  cout<<"Do you want to continue operations? \n\nPress 'y' if yes";
  cin>>ch;
  if(ch=='y' || ch=='Y')
  goto lb;

  end :
  cout<<"\n================================================================================";
  cout<<"Thank you for trying FIFA Club Career Mode Demo Edition.\nIf you enjoyed it,buy the full version,available in stores now  \n\nThe full version of FIFA Club Career Mode includes exciting features like playing actual eleven-a-side football , playing your team in the UEFA Champions League,hiring and firing managers and conquering the best in the world to be the ultimate football club \n\nSo what are you waiting for? :)";
  cout<<"\n================================================================================";
  getch();

}

//===========================================================================================================================
