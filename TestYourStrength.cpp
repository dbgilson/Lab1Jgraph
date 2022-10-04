//Lab 1: Jgraph Lab, COSC 494/594
//By: David Gilson, 10/3/22
//The point of the lab was to make something interesting/fun with the use of Jgraph.
//I had proposed a "Test Your Might" sort of game to Dr. Plank, and he accepted it.
//The goal is to press the space button as many times as you can within 5 seconds,
//and this program will generate a fun little graphic resembling a strength carnival game (game.jpg)


//Standard stack of libraries
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <time.h>
#include <thread>
#include <stdio.h>
#include <sys/ioctl.h> // For FIONREAD
#include <termios.h>
#include <stdbool.h>
#include <string>
#include <fstream>
using namespace std;

//This code helps to buffer each input in order to properly collect the number of spaces.
//Typically, we would need to press enter or end-of-line for something like getline to read the string,
//but this helps to buffer the space input and not having to press enter to actually buffer it.
int kbhit(void) {
    static bool initflag = false;
    static const int STDIN = 0;

    if (!initflag) {
        // Use termios to turn off line buffering
        struct termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initflag = true;
    }

    int nbbytes;
    ioctl(STDIN, FIONREAD, &nbbytes);  // 0 is STDIN
    return nbbytes;
}

//This class basically threads off a process to read/buffer the space inputs and then ends
//the thread after 5 seconds, essentially acting as a 5 second time to input your space presses.
class Time_Limited_Input_Reader{ 
public:
   std::string Input;
   void operator()(){
    Time_Limited_Input_Reader Input_Reader; 
	cout << "Test Your Might!" << endl;
    cout << "Starting in: " << endl;
    cout << "3" << endl;
    sleep(1);
    cout << "2" << endl;
    sleep(1);
    cout << "1" << endl;
    sleep(1);
    cout << "GOOOO!!!" << endl;
    std::thread Read_Input(&Time_Limited_Input_Reader::Read,this);
    Read_Input.detach();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    Read_Input.~thread();
   }
private:
   //Read that is threaded off and properly pushes back to the Input buffer for each space press.
   void Read(){
       char c;
    while(1){
        while (!kbhit()) {
                fflush(stdout);
            }
        c = getchar();
        Input.push_back(c);
        }
    }
};

//This function writes the jgraph file, as well as generates the .jpg picture.
//It takes the input "might" which is just an int of the number of spaces counted from the game.
void write_jgraph(int might){
    ofstream outfile;
    outfile.open("test2.jgr");
    
    string line;
    ifstream myfile("test.jgr");
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            outfile << line << endl;
        }
    }
    int might_temp = 0;


    if(might >= 50){  //Set 50 as a hard limit as to not overextend the rod past the top bell
        might_temp = 50;
    }
    else{
        might_temp = might;
    }
    outfile << "(* Rod *)\nnewcurve eps Rod.eps marksize .65 1\npts 3 " << (3 + (2.6/10)*(might_temp)) << endl;
    outfile << "(* Score *)\nnewstring hjl vjb fontsize 17 lcolor 1 0 0\nfont Courier x 2.5 y .25 : " << might << endl;
    outfile << "(* Hammer Handle *)\nnewline linethickness 10 pts 3.75 3.625 7.5 3.625" << endl;
    outfile << "(* Hammer *)\nnewline poly pcfill .5 .3 .07 color 0 0 0\npts 2.25 2.75  3.75 2.75  3.75 4.5 2.25 4.5" << endl;
    outfile << "(* Hammer Hit *)\nnewline pts 2.25 2.75  1.75 " << (2.75 + .05*might) <<  endl;
    outfile << "newline pts 2.25 2.75  1.25 " << (2.75 + .04*might) <<  endl;
    outfile << "newline pts 2.25 2.75  .75 " << (2.75 + .03*might) <<  endl;
    outfile << "newline pts 3.75 2.75  4.25 " << (2.75 + .05*might) <<  endl;
    outfile << "newline pts 3.75 2.75  4.75 " << (2.75 + .04*might) <<  endl;
    outfile << "newline pts 3.75 2.75  5.25 " << (2.75 + .03*might) <<  endl;
    
    if(might_temp >= 50){
        outfile << "(* Ding *)\nnewline pts 3 17.5 2.5 18.5" << endl;
        outfile << "newline pts 3 17.5 2.25 18.25" << endl;
        outfile << "newline pts 3 17.5 2 18" << endl;

        outfile << "newline pts 3 17.5 3.5 18.5" << endl;
        outfile << "newline pts 3 17.5 3.75 18.25" << endl;
        outfile << "newline pts 3 17.5 4 18" << endl;

        outfile << "newstring hjl vjb fontsize 20\nfont Courier x 5.25 y 19.25 : *Ding" << endl; 
    }

    myfile.close();
    outfile.close();
    system("./jgraph -P test2.jgr | ps2pdf - | convert -density 300 - -quality 100 game.jpg");
}

//Simple main that initializes the Input_Reader class, has the 5 second time of input, then calls the
//write_jgraph function to create the jgraph and .jpg.
int main(){
    Time_Limited_Input_Reader Input_Reader;
    Input_Reader();
    write_jgraph(Input_Reader.Input.size());
	return 0;
}
