//
// Created by Carl Gombert on 3/4/25.
//

#ifndef REACTION_H
#define REACTION_H

#include <vector>
#include <GLFW/glfw3.h>


class Reaction {
    public:
        Reaction(float alpha, float beta, float gamma);
        ~Reaction();
        void draw();
        void update();
    private:
        const static int HEIGHT = 400;
        const static int WIDTH = 400;
        float alpha = 1;
        float beta = 1;
        float gamma = 1;
        std::vector<std::vector<std::vector<float>>> *bitMap = new std::vector(WIDTH, std::vector(HEIGHT, std::vector(3, 0.0f)));
        std::vector<std::vector<std::vector<float>>> *a = new std::vector(WIDTH, std::vector(HEIGHT, std::vector(2, 0.0f)));
        std::vector<std::vector<std::vector<float>>> *b = new std::vector(WIDTH, std::vector(HEIGHT, std::vector(2, 0.0f)));
        std::vector<std::vector<std::vector<float>>> *c = new std::vector(WIDTH, std::vector(HEIGHT, std::vector(2, 0.0f)));
        int p = 0;
        int q = 1;


};



#endif //REACTION_H
