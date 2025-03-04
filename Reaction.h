//
// Created by Carl Gombert on 3/4/25.
//

#ifndef REACTION_H
#define REACTION_H

#include <vector>


class Reaction {
    public:
        Reaction();
        void draw();
        void update();
    private:
        int height;
        int width;
        float alpha;
        float beta;
        float gamma;
        float bitMap[][];
        float a[][][];
        float b[][][];
        float c[][][];

};



#endif //REACTION_H
