#include <iostream>

#include "SDL_Plotter.h"
#include "Shapes.h"
#include "DivideAndConquer.h"
#include "Color.h"
#include "Graph.h"
#include "Font.h"
#include "ThreadedStrassen.h"
#include <ctime>

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
    int n = 300,
        deg = 1;
    char key;
    Font font(15);

    Font f(20);

    bool on[] = {false, false, false, false};

    Graph graph(g, font, n, origin, graphSize);
    graph.setNLoc(Point(850, g.getRow() / 2 - 50));
    graph.setSmoothLoc(Point(850, g.getRow() / 2 - 80));
    graph.redraw();

    g.update();

    while(!g.getQuit()){
        g.update();
    	if(g.kbhit()){
            char c = g.getKey();

            switch(c){
                case 'B':
                    on[0] = !on[0];
                    if(on[0])
                        on[0] = graph.plot(BF_MatrixMult,COLOR::RED);
                    else
                        graph.clear(BF_MatrixMult);
                    break;
                case 'D':
                    on[1] = !on[1];
                    if(on[1])
                        on[1] = graph.plot(matrixMultDivideAndConquer,COLOR::GREEN);
                    else
                        graph.clear(matrixMultDivideAndConquer);
                    break;
                case 'S':
                    on[2] = !on[2];
                    if(on[2])
                        on[2] = graph.plot(Strassen,COLOR::BLUE);
                    else
                        graph.clear(Strassen);
                    break;
                case 'T':
                    on[3] = !on[3];
                    if(on[3])
                        on[3] = graph.plot(ThreadedStrassen,COLOR::ORANGE);
                    else
                        graph.clear(ThreadedStrassen);
                    break;
                case 'N':
                    graph.smooth();
                    break;
                case 'C':
                    graph.clear();
                    for(int i = 0; i < 4; i++)
                        on[i] = false;
                    break;
                case 'Q':
                     f.drawString(g,Point(250,500), "Quit");
                    break;
                case UP_ARROW:
                    if(n < 20)
                        n += T1;
                    else if(n < 50)
                        n += T2;
                    else
                        n += T3;

                    graph.setN(n);
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
                case RIGHT_ARROW:
                    deg++;
                    graph.setSmoothness(deg);
                    break;
                case LEFT_ARROW:
                    if(deg <= 0)
                        deg = 0; 
                    else
                        deg--;  
                    graph.setSmoothness(deg);
                    break;

            }
        }
    }

    return 0;
}
