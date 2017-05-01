/**
* Authors: Kevin Aud|Jesse McNicoll|Connor Blandin|Jackson Swenson
* Assignment Title: Group Project
* Assignment Description: This source file contains the main function that handles
*   user input from the keyboard and calls the correct function
* Due Date: 5/1/2017
* Date Created: 4/28/2017
* Date Last Modified: 5/1/2017
*/

/**
 * Data Abstraction:
 * 		SDL_Plotter, Graph, and Font are created is created
 * 		3 variables, a, b, and c, are initialized for use with their counterparts in the formula
 * Input:
 * 		The program reads in keyboard hits from the user
 * Process:
 * 		The backbones of the UI are drawn to the screen(Label, axes, etc)
 * 		The function loops while the window is open and reads input, calling the correct functions
 * Output:
 * 		The running times of the algorithms are displayed on the screen and can be curve fit
 * Assumptions:
 * 		It is assumed that the user only wants to visualize 4 matrix multiplication algorithms
 * 		It is assumed that the user has a keyboard
 * 		It is assumed that, having been prompted to do so, the user will hit the correct key
 */


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
    int n = 200,
        deg = 5;
    char key;
    Font font(15);

    Font f(20);

    bool on[] = {false, false, false, false};

    Graph graph(g, font, n, origin, graphSize);
    graph.setNLoc(Point(850, g.getRow() / 2 - 60));
    graph.setSmoothLoc(Point(850, g.getRow() / 2 - 130));
    graph.setSmoothness(deg);
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
                    if(n > T1){
                        if(n < 20)
                            n -= T1;
                        else if(n < 50)
                            n -= T2;
                        else
                            n -= T3;

                        graph.setN(n);
                    }
                    break;
                case 'N':
                    graph.smooth();
                    break;
                case RIGHT_ARROW:
                    if(deg < n && deg < 64)
                        deg++;
                        graph.setSmoothness(deg);
                    break;
                case LEFT_ARROW:
                    if(deg > 1)
                        deg--;
                    graph.setSmoothness(deg);
                    break;

            }
        }
    }

    return 0;
}
