//
// Created by Carl Gombert on 3/4/25.
//

#include "Reaction.h"
#include <random>
#include <iostream>

Reaction::Reaction(float alpha, float beta, float gamma) {

    this->alpha = alpha;
    this->beta = beta;
    this->gamma = gamma;

    a->reserve(WIDTH*HEIGHT*2);
    b->reserve(WIDTH*HEIGHT*2);
    c->reserve(WIDTH*HEIGHT*2);
    bitMap->reserve(WIDTH*HEIGHT*3);

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<> dis(0.0, 1.0);

    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            (*a)[x][y][p] = float(dis(gen));
            (*b)[x][y][p] = float(dis(gen));
            (*c)[x][y][p] = float(dis(gen));
        }
    }
}

Reaction::~Reaction() {
    delete bitMap;
    delete a;
    delete b;
    delete c;
}



void Reaction::update() {
    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            float sp [3] = {0, 0, 0};
            for (int i = x-1; i <= x+1; i++) {
                for(int j = y-1; j <= y+1; j++) {
                    sp[0] += (*a)[(i+WIDTH)%WIDTH][(j+HEIGHT)%HEIGHT][p];
                    sp[1] += (*b)[(i+WIDTH)%WIDTH][(j+HEIGHT)%HEIGHT][p];
                    sp[2] += (*c)[(i+WIDTH)%WIDTH][(j+HEIGHT)%HEIGHT][p];
                }
            }
            sp[0] /= 9.0;
            sp[1] /= 9.0;
            sp[2] /= 9.0;
            (*a)[x][y][q] = std::min(std::max(sp[0] + sp[0] * (alpha*sp[1] - gamma*sp[2]), float(0)), float(1));
            (*b)[x][y][q] = std::min(std::max(sp[1] + sp[1] * (beta*sp[2] - alpha*sp[0]), float(0)), float(1));
            (*c)[x][y][q] = std::min(std::max(sp[2] + sp[2] * (gamma*sp[0] - beta*sp[1]), float(0)), float(1));
            (*bitMap)[x][y][0] = (*a)[x][y][q];
            (*bitMap)[x][y][1] = (*a)[x][y][q];
            (*bitMap)[x][y][2] = (*a)[x][y][q];
        }
    }
    if (p == 0) {
        p = 1;
        q = 0;
    } else {
        p = 0;
        q = 1;
    }
}

void Reaction::draw() {
    glPointSize(1);
    glBegin(GL_POINTS);
    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {

            glColor3f((*bitMap)[x][y][0], (*bitMap)[x][y][1], (*bitMap)[x][y][2]);
            glVertex2f(x, y);


        }
    }
    glEnd();
}

