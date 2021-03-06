#ifndef AS2_H
#define AS2_H

#include <string>
#include <vector>
#include "Matrix.h"

struct Vertex {
    int x, y;
};

struct Line {
    int v1Index, v2Index;
};

void init();
void readVerticesFile();
void startProcessing();
void getAndProcessInput();
void getTranslateInfo();
void translate(double translateX, double translateY);
void getBasicScaleInfo();
void basicScale(double scaleX, double scaleY);
void getBasicRotateInfo();
void basicRotate(double angle);
void getScaleInfo();
void scale(double scaleX, double scaleY, double centerX, double centerY);
void getRotateInfo();
void rotate(double angle, double centerX, double centerY);
void applyTransformation(Matrix<double> &tMatrix);
Matrix<double> getTranslationMatrix(double translateX, double translateY);
Matrix<double> getBasicScaleMatrix(double scaleX, double scaleY);
Matrix<double> getBasicRotateMatrix(double angle);
Matrix<double> getScaleMatrix(double scaleX, double scaleY, double centerX, double centerY);
Matrix<double> getRotateMatrix(double angle, double centerX, double centerY);
void outputToFile();
void draw();
void initLineClip();
void lineClipAndRender(int x0, int y0, int x1, int y1);
int getRegionCode(int x, int y);

// helper functions
std::vector<std::string> split(std::string str, std::string delim);
int vertexIsUnique(Vertex &vertex);
bool isANumber(std::string str);

#endif
