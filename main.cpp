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

int main(int argc, char ** argv)
{

    SDL_Plotter g(800, 1280);

    Font f(25);

    f.drawString(g, Point(500, 500), "this is a test");

    f.setColor(COLOR::GREEN);
    f.drawString(g, Point(500, 600), "this is a test");

    Point origin(100,700);
    Point graphSize(700,600);
    int n = 500;
    char key;
    Font font(30);

    Graph graph(g, font, n, origin, graphSize);
    graph.setNLoc(Point(1000, 650));

    while(!g.getQuit()){
        g.update();
    	if(g.kbhit()){
    	    key = g.getKey();
            cout << "key: " << key << endl;
            switch(key){
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
                    break;

                case 'D':
                    cout << "divide and conquer...";
                    graph.plot(&matrixMultDivideAndConquer);
                    cout << "!" << endl;
                    break;
            }
        }
    }

    return 0;
}
