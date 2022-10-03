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

class Timee_Limited_Input_Reader{ 
public:
   std::string Input;
   void operator()(){
    Timee_Limited_Input_Reader Input_Reader; 
    string SpaceCount;
	cout << "Test Your Might!" << endl;
    cout << "Starting in: " << endl;
    cout << "3" << endl;
    sleep(1);
    cout << "2" << endl;
    sleep(1);
    cout << "1" << endl;
    sleep(1);
    cout << "GOOOO!!!" << endl;
    std::thread Read_Input(&Timee_Limited_Input_Reader::Read,this);
    Read_Input.detach();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    Read_Input.~thread();
   }
private:
   
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
    if(might >= 50){
        might_temp = 50;
    }
    else{
        might_temp = might;
    }
    outfile << "(* Rod *)\nnewcurve eps Rod.eps marksize .65 1\npts 3 " << (3 + (2.6/10)*(might_temp)) << endl;
    outfile << "(* Score *)\nnewstring hjl vjb fontsize 17 lcolor 1 0 0\nfont Courier x 2.5 y .25 : " << might << endl;
    
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

int main(int argc, char **argv){
	long long arg1, arg2;

    Timee_Limited_Input_Reader Input_Reader;
    Input_Reader();
    write_jgraph(Input_Reader.Input.size());
	return 0;
}
