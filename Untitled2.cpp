#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <cstdlib>
#include <fstream>



using namespace std;

int C = 523; // DO - dura 191ms - 382ms
int D = 587; // RE - dura 170ms - 340ms
int E = 659; // MI - dura 152ms - 304ms
int F = 698; // FA - dura 143ms - 286ms
int G = 740; // SOL - dura 135ms - 270ms
int A = 880; // LA - dura 114ms - 228ms
int B = 988; // SI - dura 110ms - 220ms


string Pashman = R"(
   PPPPPP       AA      SSSSSSS  HH    HH  MM          MM     AA     NN    NN
   PP    PP   AA  AA   SS        HH    HH  MMM        MMM   AA  AA   NNN   NN
   PP    PP  AA    AA  SS        HH    HH  MMMM      MMMM  AA    AA  NNNN  NN
   PPPPPP    AAAAAAAA   SSSSSS   HHHHHHHH  MM MM    MM MM  AAAAAAAA  NN NN NN
   PP        AA    AA        SS  HH    HH  MM  MM  MM  MM  AA    AA  NN  NNNN
   PP        AA    AA        SS  HH    HH  MM   MMMM   MM  AA    AA  NN   NNN
   PP        AA    AA  SSSSSSS   HH    HH  MM    MM    MM  AA    AA  NN    NN
)";

void gotoXY(int X, int Y) //Komak baray vasat neveshtane matn
{
	COORD position;
	position.X = X;
	position.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
char menu;
char back_to_menu;
void Paakkon() //matn ro paak mikone
{
	for (int i = 0; i < 30; i++)
	{
		gotoXY(0, 0 + i);
		for (int j = 0; j < 80; j++)
			cout << " ";
	}
}

void Set_Color(int i) //Rang Matn & Background
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
void choose(){
	Paakkon();
	gotoXY(5 , 1);
	cout << Pashman;
    gotoXY(32, 16);
    cout << "1 --> Play game" << endl;
    gotoXY(32, 18);
    cout << "2 --> How to play" << endl;
    gotoXY(32, 20);
    cout << "3 --> Credits" << endl;
    gotoXY(32, 22);
    cout << "4 --> Exit" << endl;
    gotoXY(32, 24);
    menu = getch();
    }

int main() {
	string music = "Bittersweet-Melody.wav";
	fstream fp;
	fp.open(music);
   	PlaySound(music.c_str(), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
	fp.close();
    Set_Color(15);
    system("mode 80,30");
    choose();
    while(true)
	{
		if(menu == '1')
		{
        	Paakkon();
            char play_again = 'y';
                while (play_again == 'y')
                {
                    vector<char> vec = {};
                    string kalame;
                    int mahdoodyat = 0;
                    bool shans = 0;
                    srand(time(0));
                    lev :
                    gotoXY(32, 12);
                    cout << "1 --> Easy" << endl;
                    gotoXY(32, 14);
                    cout << "2 --> Medium" << endl;
                    gotoXY(32, 16);
                    cout << "3 --> Hard" << endl;
                    string easy[18] =      { "apple"   , "cheese"           , "hello"                             , "banana"         , "lion"      , "tiger"     , "orange"              , "egg"                  , "juice"   , "jam"                  , "cherry"  , "cat"       , "dog"       , "mouse"                     , "house"                   , "cow"                     , "sheep"                         , "snake" };
                    string hint_easy[18] = { "a fruit" , "mouse's favorite" , "when you see a person you say ..." , "a yellow fruit" , "an animal" , "an animal" , "a fruit and a color" , "you eat in breakfast" , "a drink" , "you eat in breakfast" , "a fruit" , "an animal" , "an animal" , "an animal(cats like that)" , "a place where you leave" , "an animal who say maaaa" , "an animal with a lot of pashm" , "a long animal" };
                    string medium[17] =      { "pineapple" , "coconut"       , "paris"  , "cucumber" , "computer"              , "soccer"  , "pencil"              , "paper"               , "corona"  , "shirt"         , "ice cream"          , "telegram"              , "pillow"       , "butterfly"          , "clock"                 , "iran"      , "eraser"             };
                    string hint_madium[17] = { "a fruit"   , "a heavy fruit" , "a city" , "a fruit"  , "an object like laptop" , "a sport" , "you write with that" , "rock ..... scissors" , "a virus" , "you wear that" , "an icy sweet thing" , "social networking app" , "a soft thing" , "a beautiful insect" , "an object on the wall" , "a country" , "opposite of pencil" };
                    string hard[12] = {"blue sky" , "big apartment" , "fat man" , "hang man" , "black batman", "slow turtle", "fast rabbit", "fast food", "curtains", "glue stick", "science book"};
                    char level;
                    gotoXY(32, 18);
                    cout << "Select level: ";
                    level = getch();
                    cout << endl;
                    string hint;
                    int ran;
                    Paakkon();
                    gotoXY(30, 12);
                    if (level == '1'){
                        ran = rand()%18;
                        kalame = easy[ran];
                        mahdoodyat = 5;
                        hint = hint_easy[ran];
                        cout << "hint: " << hint << endl;
                    }
                    else if (level == '2'){
                        ran = rand()%17;
                        kalame = medium[ran];
                        hint = hint_madium[ran];
                        cout << "hint: " << hint << endl;
                        mahdoodyat = 7;
                    }
                    else if (level == '3'){
                        ran = rand()%12;
                        kalame = hard[ran];
                        mahdoodyat = 9;
                    }
                    else{
                    	goto lev;
					}
                    char a;
                    bool arr[kalame.size()];
                    for(int i = 0; i < kalame.size(); i++){
                        if(kalame[i] == ' ')
                            arr[i] = 1;
                        else
                            arr[i] = 0;
                    }
                    cout << endl;
                    int flag = 0;
                    for (int i = 0; mahdoodyat > 0 ; i++){
                        gotoXY(30, 14);
                        cout << "life: ";
                        Set_Color(12);
                        cout << mahdoodyat << endl;
                        Set_Color(15);
                        gotoXY(30, 16);
                        cout << "word: ";
                        for(int j = 0; j < kalame.size();j++){
                            if(arr[j] == 1)
                                cout << kalame[j] << " ";
                            else
                                cout << "_ ";
                        }
                        cout << endl;
                        gotoXY(30, 18);
                        cout << "enter your letter: ";
                        a = getch();
                        a = tolower(a);
                        vec.push_back(a);
                        for(int j = 0; j < kalame.size(); j++){
                            if(a == kalame[j]){
                                arr[j] = 1;
                                shans = 1;
                            }
                        }

                        if(shans == 0)
                            mahdoodyat--;
						shans = 0;

                        cout << endl;
                        gotoXY(30, 20);
                        cout << "guessed letters: ";
                        for(int u = 0; u < vec.size(); u++){
                                cout << vec[u] << " ";
                        }
                        cout << endl;
                        bool win = 1;
                        for(int j = 0; j < kalame.size(); j++){
                            if(arr[j] == 0){
                                win = 0;
                                break;
                            }
                        }

                        if(win == 1)
						{
                            cout << endl;
                            Paakkon();
                            gotoXY(32, 12);
                            Set_Color(2);
                            cout << "You win! :D" << endl << endl;
                            Set_Color(15);
                            gotoXY(27, 14);
                            cout << "The correct answer: " << kalame << endl << endl;
                            Beep(F , 100);
                            Beep(G , 95);
                            Beep(E , 110);
                            Beep(D , 115);
                            Beep(C , 120);
                            Beep(A , 90);
                            Beep(B , 80);
                            Beep(G , 95);
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) 
					{
                        Paakkon();
                        cout << endl;
                        gotoXY(32, 12);
                        Set_Color(4);
                        cout << "You lose :(" << endl;
                        Set_Color(15);
                        gotoXY(27, 14);
                        cout << "The correct answer was: " << kalame << endl << endl;
                        Beep(G , 1000);
		          		Beep(A , 500);
		         		Beep(B , 700);
		         		Beep(G , 800);

                    }
                    gotoXY(30, 16);
                    cout << "play again? (y/n) ";
                    play_again = getch();
                    Paakkon();
                    play_again = tolower(play_again);
                    if(play_again == 'n')
                    {
                    	choose();
                    	continue;
					}
                }
        }
        if(menu == '2')
		{
            Paakkon();
	   	 	string how1 = R"(
			           :: PASHMAN ::
                      In this game, you have to guess a word!
                Any word will be given according to the difficulty.

                   But if you're not able to guess the word and,
                     lifes finish then person will be hanged
                        Difficulty levels are as follows :-

                          	EASY :: 5 Mistakes
                          	 
			   	MEDIUM :: 7 Mistakes

			   	HARD :: 9 Mistakes



			        Press y to go back:)";
    		gotoXY(36, 8);
	    	cout << how1;
            back_to_menu = getch();
            tolower(back_to_menu);
            Paakkon();
            if(back_to_menu == 'y')
                choose();
            continue;
        }
        if(menu == '3')
		{
        	Paakkon();
            string credit =
R"(
                              Produced by :

                              (P)ouria Hashtroudi

                	      (A)rian Rasti

                	      (A)bolfazl Khajavi
                	        
                	      (A)bbas Safaei
                	        
                	      (S)hayan Chapi
							
                	      (H)ossein Karami
                	        
                	      (M)ani Kermani

                              (M)ohammad Karami

                    	      (M)ohammad Reza Hoghoghi
							  )";
			gotoXY(36, 8);
            cout << credit;
            string CopyRight = R"(
            
	     	    	The right to any copy is reserved

			      )";
			Set_Color(4);
			cout << CopyRight;
			Set_Color(15);
			string back = R"(
			       Press y to go back:)";
			cout << back;
            back_to_menu = getch();
            Paakkon();
            tolower(back_to_menu);
            if(back_to_menu == 'y')
                choose();
            continue;
        }
        if(menu == '4')
        {
        	 exit(0);
		}
           
        else
        {
        	choose();
			continue;	
		}

    }




return 0;
}
