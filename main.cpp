#include <iostream>

#include "SDL_Plotter.h"
#include "Shapes.h"
#include "DivideAndConquer.h"
#include "Color.h"
#include "Graph.h"
#include "Font.h"


#define MAX_N 500
#define T1 2
#define T2 4
#define T3 10

using namespace std;

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 800;

int main(int argc, char ** argv)
{


    SDL_Plotter g(WINDOW_HEIGHT, WINDOW_WIDTH);

    Point origin(100,700);
    Point graphSize(700,600);
    int n = 100;
    char key;
    Font font(30);


    Font f(20);

    bool on[] = {false, false, false, false};
    f.drawString(g,Point(850, WINDOW_HEIGHT/2), "B Brute Force");
    f.drawString(g,Point(850, WINDOW_HEIGHT/2 + 30),"D Divide and Conquer");
    f.drawString(g,Point(850, WINDOW_HEIGHT/2 + 60),"S Straussen");
    f.drawString(g,Point(850, WINDOW_HEIGHT/2 + 90),"T Threaded Straussen");




    Graph graph(g, font, n, origin, graphSize);
    graph.setNLoc(Point(1000, 650));

    while(!g.getQuit()){
        g.update();
    	if(g.kbhit()){
            char c = g.getKey();
            switch(c){
            case 'B':
                f.drawString(g,Point(250,500), "Brute Force");
                f.drawString(g,Point(250,500), "Brute Force");
                break;
            case 'D':
                cout << "divide and conquer...";
                graph.plot(&matrixMultDivideAndConquer);
                cout << "!" << endl;
                break;
                f.drawString(g,Point(250,500), "Divide And Conquer");
                break;
            case 'S':
                f.drawString(g,Point(250,500), "Strassen");
                break;
            case 'T':
                f.drawString(g,Point(250,500), "Threaded Strassen");
                break;
            case 'Q':
                 f.drawString(g,Point(250,500), "Quit");
                break;
            case UP_ARROW:
                if(n <= MAX_N){
                    if(n + T3 > MAX_N)
                        n = MAX_N;
                    else if(n < 20)
                        n += T1;
                    else if(n < 50)
                        n += T2;
                    else
                        n += T3;

                    graph.setN(n);
                }
                break;
            case DOWN_ARROW:
                if(n > 0){
                    if(n < 20)
                        n -= T1;
                    else if(n < 50)
                        n -= T2;
                    else
                        n -= T3;

                    graph.setN(n);
                }
            default:
                 f.drawString(g,Point(250,500), "Other");
                break;

            }



    	    key = g.getKey();
            cout << "key: " << key << endl;
            switch(key){

            }
        }
    }

    return 0;
}
