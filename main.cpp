#include <iostream>

#include "SDL_Plotter.h"
#include "Shapes.h"
#include "DivideAndConquer.h"
#include "Color.h"
#include "Graph.h"
#include "Font.h"
#include "ThreadedStrassen.h"
#include "polyReg.h"
#include <ctime>

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
    Font font(15);

    Font f(20);

    bool on[] = {false, false, false, false};
    f.drawString(g,Point(850, WINDOW_HEIGHT/2), "B Brute Force");
    f.drawString(g,Point(850, WINDOW_HEIGHT/2 + 30),"D Divide and Conquer");
    f.drawString(g,Point(850, WINDOW_HEIGHT/2 + 60),"S Straussen");
    f.drawString(g,Point(850, WINDOW_HEIGHT/2 + 90),"T Threaded Straussen");

    Graph graph(g, font, n, origin, graphSize);
    graph.setNLoc(Point(1000, 650));

    graph.redraw();

    g.update();

    while(!g.getQuit()){
        g.update();
    	if(g.kbhit()){
            char c = g.getKey();
            switch(c){
            case 'B':
                on[0] = !on[0];
                if(on[0]){
                    f.setColor(COLOR::RED);
                    f.drawString(g,Point(850, WINDOW_HEIGHT/2), "B Brute Force");
                    graph.plot(BF_MatrixMult,COLOR::RED);
                }
                else{
                    f.setColor(COLOR::BLACK);
                    f.drawString(g,Point(850, WINDOW_HEIGHT/2), "B Brute Force");
                    graph.clear(BF_MatrixMult);
                }
                break;
            case 'D':
                on[1] = !on[1];
                if(on[1]){
                    f.setColor(COLOR::GREEN);
                    f.drawString(g, Point(850, WINDOW_HEIGHT/2 + 30),"D Divide and Conquer");
                    graph.plot(matrixMultDivideAndConquer,COLOR::GREEN);
                }
                else{
                    graph.clear(matrixMultDivideAndConquer);
                    f.setColor(COLOR::BLACK);
                    f.drawString(g, Point(850, WINDOW_HEIGHT/2 + 30),"D Divide and Conquer");
                }
                break;
            case 'S':
                on[2] = !on[2];
                if(on[2]){
                    f.setColor(COLOR::BLUE);
                    f.drawString(g, Point(850, WINDOW_HEIGHT/2 + 60),"S Straussen");
                    graph.plot(Strassen,COLOR::BLUE);
                }
                else{
                    graph.clear(Strassen);
                    f.setColor(COLOR::BLACK);
                    f.drawString(g, Point(850, WINDOW_HEIGHT/2 + 60),"S Straussen");
                }
                break;
            case 'T':
                on[3] = !on[3];
                if(on[3]){
                    f.setColor(COLOR::PURPLE);
                    f.drawString(g,Point(850, WINDOW_HEIGHT/2 + 90),"T Threaded Straussen");
                    graph.plot(ThreadedStrassen,COLOR::PURPLE);
                }
                else{
                    graph.clear(ThreadedStrassen);
                    f.setColor(COLOR::BLACK);
                    f.drawString(g,Point(850, WINDOW_HEIGHT/2 + 90),"T Threaded Straussen");
                }
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
        }
    }

    return 0;
}
