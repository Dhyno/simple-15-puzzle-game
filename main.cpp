#include<iostream>
#include<time.h>>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include<iomanip>
#include"print_game.h"
using namespace std;
int count_game=0;
void show();
void print_game(char*[]);
void put_rand_num(int*);
void input_user(int*,int*);
int side_cell(int,char*);
int to_win(int*,int*);
//void int_to_char(char* []);
int main()
{
    int cons_num[16];
    int play_num[16];
    int i;
    int j;
    char ch;
    for(i=0;i<16;i++)
    {
        if (i==15)
            cons_num[i]=0;
        else
            cons_num[i]=i+1;
    }
    start_print();
    print_start();
    system("pause");
    while(1)
    {
        put_rand_num(play_num);
        input_user(play_num,cons_num);
        system("cls");
        show();
        //int_to_char(cons_num,to_print);
        play_num[16]={0};
        count_game++;
        cout<<"press any key to continue : ";
        ch=getch();
        if(ch=='n'||ch=='N')
            break;
    }
    system("cls");
    cout<<"you complete game : "<<count_game<<" time\n\n";
    return 0;
}
void put_rand_num(int* con_num)//make random number
{
    int temp_ind[15];
    con_num[16]={0};
    int temp;
    int i;
    int j;
    srand(time(0));
    int con=0;
    for(i=0;i<16;i++)//initial with neat value
    {
        if(i!=15)
            con_num[i]=i+1;
        else
            con_num[i]={0};
    }
    for(i=0;i<15;i++)//make random indeks
        temp_ind[i]=rand()%15+1;
    for(i=0;i<15;i++)//change indeks if get same indeks it not make same value at diferent indeks
    {
        int ves=i+1;
        int t_1=temp_ind[i];
        int t_2=temp_ind[ves];
        temp=con_num[t_2];
        con_num[t_2]=con_num[t_1];
        con_num[t_1]=temp;

    }
    for(i=0;i<16;i++)//put null in last indeks
    {
        if(con_num[i]==0)
        {
            con_num[i]=con_num[15];
            con_num[15]=0;
        }
    }
}
void input_user(int* con_num,int* stat_num)//get input from user
{
    char button;
    int t=16;
    int t_track;
    int temp;
    int i;
    int j;
    int complete;
    //
    char* i_t_c[16];
    char* t_char=new char[3];
    int l_ch;
    while(1)
    {
        int con=0;
        con=side_cell(t,&button);
        if(con!=1)
        {
            t_track=t;
            if(button=='w')
                t-=4;
            else if(button=='a')
                t-=1;
            else if(button=='d')
                t+=1;
            else if(button=='s')
                t+=4;
            temp=con_num[t_track-1];
            con_num[t_track-1]=con_num[t-1];
            con_num[t-1]=temp;
        }
        else if(con==2)
            cout<<"invalid input\n";
        system("cls");
        for(i=0;i<16;i++)
        {
            if(con_num[i]==0)
            {
                *t_char=NULL;
                i_t_c[i]=t_char;
            }
            else
            {
                itoa(con_num[i],t_char,10);
                i_t_c[i]=t_char;
            }
            l_ch=sizeof(t_char);
            t_char=t_char+(l_ch+1);
        }
        t_char-=80;//back to first pointer indeks

        //int_to_char(i_t_c);//equal to pointer string lateral must use char* [] / itc*[] to formal argument
        show();
        print_game(i_t_c);//equal to pointer string lateral must use char* [] / itc*[] to formal argument
        complete=to_win(con_num,stat_num);
        if(complete)
            break;
        button=getch();
    }
}
int side_cell(int p_i,char* c_b)//user cant break side cell
{
    int a=0;
    if(p_i==1 && (*c_b=='w'||*c_b=='a'))
        a=1;
    else if(p_i==4 && (*c_b=='w'||*c_b=='d'))
        a=1;
    else if(p_i==13 && (*c_b=='s'||*c_b=='a'))
        a=1;
    else if(p_i==16 && (*c_b=='s'||*c_b=='d'))
        a=1;
    else if((p_i==12||p_i==8) && *c_b=='d')
        a=1;
    else if((p_i==2||p_i==3) && *c_b=='w')
        a=1;
    else if((p_i==5||p_i==9) && *c_b=='a')
        a=1;
    else if((p_i==14||p_i==15) && *c_b=='s')
        a=1;
    else
        a=2;
    return a;
}
int to_win(int* con_num,int* stat_num)//to get win or no
{
    int w_or_l=0;
    int inc=0;
    for(int i=0;i<16;i++)
    {
        if(con_num[i]==stat_num[i])
            inc++;
    }
    if(inc==16)
        w_or_l=1;
    return w_or_l;
}

/*void int_to_char(char* [])
{

}*/

void show()
{
    cout<<"---------------------------------\n";
    cout<<"FIFTEEN PUZZLE                  |\n";
    cout<<"---------------------------------\n\n";
}
void print_game(char* con_num[])
{
    cout<<" ---------------------------\n";
    cout<<"|      |      |      |      |\n";
    cout<<setw(4)<<"  "<<con_num[0]<<"      "<<con_num[1]<<"      "<<con_num[2]<<"     "<<con_num[3]<<"  \n";
    cout<<"|      |      |      |      |\n";
    cout<<" ---------------------------\n";
    cout<<"|      |      |      |      |\n";
    cout<<setw(4)<<"   "<<con_num[4]<<"     "<<con_num[5]<<"      "<<con_num[6]<<"     "<<con_num[7]<<"   \n";
    cout<<"|      |      |      |      |\n";
    cout<<" ---------------------------\n";
    cout<<"|      |      |      |      |\n";
    cout<<setw(4)<<"   "<<con_num[8]<<"      "<<con_num[9]<<"     "<<con_num[10]<<"     "<<con_num[11]<<"   \n";
    cout<<"|      |      |      |      |"<<setw(13)<<"game : "<<count_game<<endl;
    cout<<" ---------------------------\n";
    cout<<"|      |      |      |      |\n";
    cout<<setw(4)<<"  "<<con_num[12]<<"     "<<con_num[13]<<"     "<<con_num[14]<<"     "<<con_num[15]<<"    \n";
    cout<<"|      |      |      |      |"<<setw(48)<<"press N/n to stop and any key to continue\n";;
    cout<<" ---------------------------\n";
}































