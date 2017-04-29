#include <map>
#include <vector>
#include <algorithm>
#include "Shapes.h"

#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

class Font {
private:
    map<char, vector<Line> > chars;
    int size;
public:

    Font(int size) {

        if (size % 2 == 0) {
            size++;
        }
        this->size = size;
        int middle = (size / 2) + 1;

        chars['1'].push_back(Line(Point(0,0), Point(0,size)));

        chars['2'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['2'].push_back(Line(Point(middle,0), Point(middle, middle)));
        chars['2'].push_back(Line(Point(0,middle), Point(middle,middle)));
        chars['2'].push_back(Line(Point(0,middle), Point(0,size)));
        chars['2'].push_back(Line(Point(0,size), Point(middle,size)));

        chars['3'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['3'].push_back(Line(Point(0,middle), Point(middle,middle)));
        chars['3'].push_back(Line(Point(middle,0), Point(middle,size)));
        chars['3'].push_back(Line(Point(0,size), Point(middle,size)));

        chars['4'].push_back(Line(Point(0,0), Point(0,middle)));
        chars['4'].push_back(Line(Point(middle,0), Point(middle, middle)));
        chars['4'].push_back(Line(Point(0,middle), Point(middle,middle)));
        chars['4'].push_back(Line(Point(middle,middle), Point(middle,size)));

        chars['5'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['5'].push_back(Line(Point(0,0), Point(0, middle)));
        chars['5'].push_back(Line(Point(0,middle), Point(middle,middle)));
        chars['5'].push_back(Line(Point(middle,middle), Point(middle,size)));
        chars['5'].push_back(Line(Point(0,size), Point(middle,size)));

        chars['6'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['6'].push_back(Line(Point(0,0), Point(0, size)));
        chars['6'].push_back(Line(Point(0,middle), Point(middle,middle)));
        chars['6'].push_back(Line(Point(middle,middle), Point(middle,size)));
        chars['6'].push_back(Line(Point(0,size), Point(middle,size)));

        chars['7'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['7'].push_back(Line(Point(middle,0), Point(middle,size)));

        chars['8'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['8'].push_back(Line(Point(0,0), Point(0, size)));
        chars['8'].push_back(Line(Point(0,middle), Point(middle,middle)));
        chars['8'].push_back(Line(Point(middle,0), Point(middle,size)));
        chars['8'].push_back(Line(Point(0,size), Point(middle,size)));

        chars['9'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['9'].push_back(Line(Point(middle,0), Point(middle,size)));
        chars['9'].push_back(Line(Point(0,0), Point(0,middle)));
        chars['9'].push_back(Line(Point(0,middle), Point(middle,middle)));

        chars['0'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['0'].push_back(Line(Point(0,0), Point(0, size)));
        chars['0'].push_back(Line(Point(middle,0), Point(middle,size)));
        chars['0'].push_back(Line(Point(0,size), Point(middle,size)));

        chars['a'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['a'].push_back(Line(Point(0,0), Point(0, size)));
        chars['a'].push_back(Line(Point(middle,0), Point(middle,size)));
        chars['a'].push_back(Line(Point(0,middle), Point(middle,middle)));

        chars['b'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['b'].push_back(Line(Point(0,0), Point(0, size)));
        chars['b'].push_back(Line(Point(0,middle), Point(middle,middle)));
        chars['b'].push_back(Line(Point(middle,0), Point(middle,size)));
        chars['b'].push_back(Line(Point(0,size), Point(middle,size)));

        chars['c'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['c'].push_back(Line(Point(0,0), Point(0, size)));
        chars['c'].push_back(Line(Point(0,size), Point(middle,size)));

        chars['d'].push_back(Line(Point(0,0), Point(middle, (middle / 2))));
        chars['d'].push_back(Line(Point(0,0), Point(0, size)));
        chars['d'].push_back(Line(Point(middle,(middle / 2)), Point(middle, middle + (middle / 2))));
        chars['d'].push_back(Line(Point(middle, middle + (middle / 2)), Point(0,size)));

        chars['e'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['e'].push_back(Line(Point(0,middle), Point(middle,middle)));
        chars['e'].push_back(Line(Point(0,0), Point(0,size)));
        chars['e'].push_back(Line(Point(0,size), Point(middle,size)));

        chars['f'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['f'].push_back(Line(Point(0,middle), Point(middle,middle)));
        chars['f'].push_back(Line(Point(0,0), Point(0,size)));

        chars['g'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['g'].push_back(Line(Point(0,0), Point(0, size)));
        chars['g'].push_back(Line(Point((middle / 3),middle), Point(middle,middle)));
        chars['g'].push_back(Line(Point(middle,middle), Point(middle,size)));
        chars['g'].push_back(Line(Point(0,size), Point(middle,size)));

        chars['h'].push_back(Line(Point(0,0), Point(0, size)));
        chars['h'].push_back(Line(Point(0,middle), Point(middle,middle)));
        chars['h'].push_back(Line(Point(middle,0), Point(middle,size)));

        chars['i'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['i'].push_back(Line(Point((middle / 2),0), Point((middle / 2),size)));
        chars['i'].push_back(Line(Point(0,size), Point(middle,size)));

        chars['j'].push_back(Line(Point((1 * middle) / 6,0), Point(middle + ((1 * middle) / 6),0)));
        chars['j'].push_back(Line(Point(((2 * middle)/ 3),0), Point(((2 * middle)/ 3),size)));
        chars['j'].push_back(Line(Point(0,size), Point(((2 * middle) / 3),size)));
        chars['j'].push_back(Line(Point(0,size), Point(0, middle + (middle / 2))));

        chars['k'].push_back(Line(Point(0,0), Point(0,size)));
        chars['k'].push_back(Line(Point(0,middle), Point(middle, 0)));
        chars['k'].push_back(Line(Point(0,middle), Point(middle,size)));

        chars['l'].push_back(Line(Point(0,0), Point(0,size)));
        chars['l'].push_back(Line(Point(0,size), Point(middle, size)));

        chars['m'].push_back(Line(Point(0,0), Point(0,size)));
        chars['m'].push_back(Line(Point(0,0), Point(size / 3, middle)));
        chars['m'].push_back(Line(Point(size / 3, middle), Point((2 * size) / 3, 0)));
        chars['m'].push_back(Line(Point((2 * size) / 3,0), Point((2 * size) / 3,size)));

        chars['n'].push_back(Line(Point(0,0), Point(0,size)));
        chars['n'].push_back(Line(Point(0,0), Point((2 * size) / 3,size)));
        chars['n'].push_back(Line(Point((2 * size) / 3,0), Point((2 * size) / 3,size)));

        chars['o'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['o'].push_back(Line(Point(0,0), Point(0, size)));
        chars['o'].push_back(Line(Point(middle,0), Point(middle,size)));
        chars['o'].push_back(Line(Point(0,size), Point(middle,size)));

        chars['p'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['p'].push_back(Line(Point(middle,0), Point(middle,middle)));
        chars['p'].push_back(Line(Point(0,0), Point(0,size)));
        chars['p'].push_back(Line(Point(0,middle), Point(middle,middle)));

        chars['q'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['q'].push_back(Line(Point(0,0), Point(0, size)));
        chars['q'].push_back(Line(Point(middle,0), Point(middle,size)));
        chars['q'].push_back(Line(Point(0,size), Point(middle,size)));
        chars['q'].push_back(Line(Point((3 * size) / 9, (8 * size) / 9), Point((5 * size) / 9, (10 * size) / 9)));

        chars['r'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['r'].push_back(Line(Point(0,0), Point(0, size)));
        chars['r'].push_back(Line(Point(middle,0), Point(middle,middle)));
        chars['r'].push_back(Line(Point(0,middle), Point(middle,middle)));
        chars['r'].push_back(Line(Point(size / 3,middle), Point(middle,size)));

        chars['s'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['s'].push_back(Line(Point(0,0), Point(0, middle)));
        chars['s'].push_back(Line(Point(0,middle), Point(middle,middle)));
        chars['s'].push_back(Line(Point(middle,middle), Point(middle,size)));
        chars['s'].push_back(Line(Point(0,size), Point(middle,size)));

        chars['t'].push_back(Line(Point(0,0), Point((2 * size) / 3,0)));
        chars['t'].push_back(Line(Point((size / 3),0), Point((size / 3),size)));

        chars['u'].push_back(Line(Point(0,0), Point(0, size)));
        chars['u'].push_back(Line(Point(middle,0), Point(middle,size)));
        chars['u'].push_back(Line(Point(0,size), Point(middle,size)));

        chars['v'].push_back(Line(Point(0,0), Point((middle / 2), size)));
        chars['v'].push_back(Line(Point(middle,0), Point((middle / 2),size)));

        chars['w'].push_back(Line(Point(0,0), Point((size / 6),size)));
        chars['w'].push_back(Line(Point((size / 6),size), Point(size / 3, middle)));
        chars['w'].push_back(Line(Point(size / 3, middle), Point(size / 2, size)));
        chars['w'].push_back(Line(Point(size / 2, size), Point((2 * size) / 3,0)));

        chars['x'].push_back(Line(Point(0,0), Point(middle, size)));
        chars['x'].push_back(Line(Point(middle,0), Point(0,size)));

        chars['y'].push_back(Line(Point(0,0), Point((middle / 2), middle)));
        chars['y'].push_back(Line(Point(middle,0), Point((middle / 2),middle)));
        chars['y'].push_back(Line(Point((middle / 2),size), Point((middle / 2),middle)));

        chars['z'].push_back(Line(Point(0,0), Point(middle,0)));
        chars['z'].push_back(Line(Point(middle,0), Point(0, size)));
        chars['z'].push_back(Line(Point(0,size), Point(middle,size)));

        chars[' '] = vector<Line>();

        chars[':'].push_back(Line(Point(middle,(size / 3) * 2), Point(middle - 1,(size / 3) * 2)));
        chars[':'].push_back(Line(Point(middle,size / 3), Point(middle - 1,size / 3)));
    }

    int drawChar(SDL_Plotter& p, Point loc, char c) {
        cout << "drawing " << (int)c << ' ' << loc.x << ',' << loc.y << endl;
        vector<Line>::iterator itr = chars[c].begin();
        int maxX = max(itr->p1.x, itr->p2.x);
        while(itr != chars[c].end()) {
            if (max(itr->p1.x, itr->p2.x) > maxX) {
                maxX = max(itr->p1.x, itr->p2.x);
            }
            itr->offsetDraw(p, loc);
            itr++;
        }
        return loc.x + maxX;
    }

    void drawString(SDL_Plotter& p, Point loc, string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string::iterator itr = s.begin();
        int lastX = loc.x;
        while (itr != s.end()) {
            if (*itr == ' ') {
                lastX += size;
            } else {
                lastX = drawChar(p, Point(lastX + (size / 3), loc.y), *itr);
            }
            itr++;
        }
    }

    void drawInt(SDL_Plotter &p, Point loc, int num){
        string str;
        while(num){
            str.insert(0,1,(num % 10) + '0');
            num /= 10; 
        }
        drawString(p,loc,str);
    }

    void drawLabeledInt(SDL_Plotter &p, Point loc, string label, int num){
        string str;
        cout << "getting str(num)" << endl;
        while(num){
            str.insert(0,1,(num % 10) + '0');
            num /= 10; 
        }
        cout << "adding label" << endl;
        str = label + str;
        cout << "drawing " << str << endl;
        drawString(p,loc,str);
        cout << "drawn" << endl;
    }
};

#endif
