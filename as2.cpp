#include <iostream>
#include <fstream>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
#include <GLFW/glfw3.h>

#include "lineDrawing.h"
#include "as2.h"
#include "Matrix.h"

using namespace std;

vector<Vertex> vertices; // vertices/points table
vector<Line> lines; // lines/edges table

const int WIDTH = getWidth();
const int HEIGHT = getHeight();

const int LEFT = 1; // 0001
const int RIGHT = 2; // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8; // 1000

void init() {
    setWindowTitle("Assignment 2 - Austin Schultz");

    readVerticesFile();
}

void readVerticesFile() {
    string filename = "";
    ifstream fileInput;
    
    bool validFile = false;
    while(!validFile) {
        cout << "Please enter name of the vertices file to read from: ";

        getline(cin, filename);

        cout << endl;

        fileInput.open(filename);
    
        if(!fileInput.good()) {
            cout << "Failed to open file. Please enter a valid filename." << endl;
            cout << endl;
        }
        
        else
            validFile = true;
    }

    int count = 0;
    string inputLine;
    while(getline(fileInput, inputLine)) {
        vector<string> lineVertices = split(inputLine, " ");

        Vertex vertex1;
        vertex1.x = atoi(lineVertices[0].c_str());
        vertex1.y = atoi(lineVertices[1].c_str());

        Vertex vertex2;
        vertex2.x = atoi(lineVertices[2].c_str());
        vertex2.y = atoi(lineVertices[3].c_str());

        // only add vertices to table if they aren't already in it
        int vertex1Index = vertexIsUnique(vertex1);
        int vertex2Index = vertexIsUnique(vertex2);

        Line line;

	// vertex isn't in table yet
        if(vertex1Index == -1) {
            vertices.push_back(vertex1);
            line.v1Index = count;
	    count++;
        }

	// vertex is already in table
        else
            line.v1Index = vertex1Index;
        
        if(vertex2Index == -1) {
            vertices.push_back(vertex2);
            line.v2Index = count;
	    count++;
        }

        else
            line.v2Index = vertex2Index;

        lines.push_back(line);
        
        //count += 2;
    }
}

void startProcessing() {
    while(true) {
        getAndProcessInput();
    }
}

void getAndProcessInput() {
    string selection = "";

    while(atoi(selection.c_str()) == 0 || atoi(selection.c_str()) < 1 || atoi(selection.c_str()) > 7) {
        cout << "Options:" << endl;

        cout << "1 - Translate" << endl;
        cout << "2 - Basic scale" << endl;
        cout << "3 - Basic rotate" << endl;
        cout << "4 - Scale" << endl;
        cout << "5 - Rotate" << endl;
        cout << "6 - Output vertices to file" << endl;
        cout << "7 - Quit" << endl;

        cout << "Please enter a number for the option "
             << "you would like to perform: ";
    
        getline(cin, selection);

        cout << endl;

        if(atoi(selection.c_str()) == 0 || atoi(selection.c_str()) < 1 || atoi(selection.c_str()) > 7) {
            cout << "Please input a number between 1 and 7 (inclusive)" << endl;
            cout << endl;
        }
    }

    switch(atoi(selection.c_str())) {
    case 1:
        getTranslateInfo();
        break;

    case 2:
        getBasicScaleInfo();
        break;
    case 3:
        getBasicRotateInfo();
        break;

    case 4:
        getScaleInfo();
        break;

    case 5:
        getRotateInfo();
        break;

    case 6:
        outputToFile();
        break;

    case 7:
        exit(0);
    }
}

void getTranslateInfo() {
    string translateX, translateY = "";
    
    while(!isANumber(translateX) || !isANumber(translateY)) {
        cout << "Please enter the translate x value: ";
        getline(cin, translateX);

        cout << "Please enter the translate y value: ";
        getline(cin, translateY);

        cout << endl;

        if(!isANumber(translateX) || !isANumber(translateY)) {
            cout << "Please enter valid numbers for translate x and translate y." << endl;
            cout << endl;
        }
    }

    translate(atof(translateX.c_str()), atof(translateY.c_str()));
}

void translate(double translateX, double translateY) {
    Matrix<double> tMatrix = getTranslationMatrix(translateX, translateY);
    
    applyTransformation(tMatrix);
}

void getBasicScaleInfo() {
    string scaleX, scaleY = "";
    
    while(!isANumber(scaleX) || !isANumber(scaleY)) {
        cout << "Please enter the scale x value: ";
        getline(cin, scaleX);

        cout << "Please enter the scale y value: ";
        getline(cin, scaleY);

        cout << endl;

        if(!isANumber(scaleX) || !isANumber(scaleY)) {
            cout << "Please enter valid numbers for scale x and scale y." << endl;
            cout << endl;
        }
    }

    basicScale(atof(scaleX.c_str()), atof(scaleY.c_str()));
}

void basicScale(double scaleX, double scaleY) {
    Matrix<double> tMatrix = getBasicScaleMatrix(scaleX, scaleY);

    applyTransformation(tMatrix);
}

void getBasicRotateInfo() {
    string angle = ""; // aka, theta (in degrees)
    
    while(!isANumber(angle)) {
        cout << "Please enter the angle (theta) value (in degrees): ";
        getline(cin, angle);
        
        cout << endl;
        
        if(!isANumber(angle)) {
            cout << "Please enter a valid number for angle." << endl;
            cout << endl;
        }
    }

    basicRotate(atof(angle.c_str()) * M_PI / 180);
}

void basicRotate(double angle) {
    Matrix<double> tMatrix = getBasicRotateMatrix(angle);

    applyTransformation(tMatrix);
}

void getScaleInfo() {
    string scaleX, scaleY = "";
    string centerX, centerY = "";
    
    while(!isANumber(scaleX) || !isANumber(scaleY) ||
           !isANumber(centerX) || !isANumber(centerY)) {
        cout << "Please enter the scale x value: ";
        getline(cin, scaleX);
        
        cout << "Please enter the scale y value: ";
        getline(cin, scaleY);

        cout << "Please enter the center x value: ";
        getline(cin, centerX);

        cout << "Please enter the center y value: ";
        getline(cin, centerY);
        
        cout << endl;

        if(!isANumber(scaleX) || !isANumber(scaleY) ||
           !isANumber(centerX) || !isANumber(centerY)) {
            cout << "Please enter valid numbers for scale x, scale y, "
                 << "center x, and center y." << endl;
            cout << endl;
        }
    }

    return scale(atof(scaleX.c_str()), atof(scaleY.c_str()),
                 atof(centerX.c_str()), atof(centerY.c_str()));
}

void scale(double scaleX, double scaleY, double centerX, double centerY) {
    Matrix<double> tMatrix = getScaleMatrix(scaleX, scaleY, centerX, centerY);

    applyTransformation(tMatrix);

    cout << "Applied scale" << endl;
}

void getRotateInfo() {
    string angle = "";
    string centerX, centerY = "";
    
    while(!isANumber(angle) || !isANumber(centerX) || !isANumber(centerY)) {
        cout << "Please enter the angle value: ";
        getline(cin, angle);
        
        cout << "Please enter the center x value: ";
        getline(cin, centerX);

        cout << "Please enter the center y value: ";
        getline(cin, centerY);

        cout << endl;

        if(!isANumber(angle) || !isANumber(centerX) || !isANumber(centerY)) {
            cout << "Please enter valid numbers for angle, center x, and center y." << endl;
            cout << endl;
        }
    }

    rotate(atof(angle.c_str()) * M_PI / 180, atof(centerX.c_str()), atof(centerY.c_str()));
}

void rotate(double angle, double centerX, double centerY) {
    Matrix<double> tMatrix = getRotateMatrix(angle, centerX, centerY);

    applyTransformation(tMatrix);
}

void applyTransformation(Matrix<double> &tMatrix) {
    for(int i = 0; i < vertices.size(); i++) {
        Vertex currentVertex = vertices[i];

        Matrix<double> vertexMatrix(1, 3);
        vertexMatrix(0, 0) = currentVertex.x;
        vertexMatrix(0, 1) = currentVertex.y;
        vertexMatrix(0, 2) = 1;

        Matrix<double> result = vertexMatrix * tMatrix;

        Vertex newVertex;
        newVertex.x = result(0, 0);
        newVertex.y = result(0, 1);

        vertices[i] = newVertex;
    }
}

Matrix<double> getTranslationMatrix(double translateX, double translateY) {
    Matrix<double> tMatrix(3, 3);
    tMatrix(0, 0) = 1;
    tMatrix(0, 1) = 0;
    tMatrix(0, 2) = 0;
    tMatrix(1, 0) = 0;
    tMatrix(1, 1) = 1;
    tMatrix(1, 2) = 0;
    tMatrix(2, 0) = translateX;
    tMatrix(2, 1) = translateY;
    tMatrix(2, 2) = 1;

    return tMatrix;
}

Matrix<double> getBasicScaleMatrix(double scaleX, double scaleY) {
    Matrix<double> tMatrix(3, 3);
    tMatrix(0, 0) = scaleX;
    tMatrix(0, 1) = 0;
    tMatrix(0, 2) = 0;
    tMatrix(1, 0) = 0;
    tMatrix(1, 1) = scaleY;
    tMatrix(1, 2) = 0;
    tMatrix(2, 0) = 0;
    tMatrix(2, 1) = 0;
    tMatrix(2, 2) = 1;

    return tMatrix;
}

Matrix<double> getBasicRotateMatrix(double angle) {
    Matrix<double> tMatrix(3, 3);
    tMatrix(0, 0) = cos(angle);
    tMatrix(0, 1) = -sin(angle);
    tMatrix(0, 2) = 0;
    tMatrix(1, 0) = sin(angle);
    tMatrix(1, 1) = cos(angle);
    tMatrix(1, 2) = 0;
    tMatrix(2, 0) = 0;
    tMatrix(2, 1) = 0;
    tMatrix(2, 2) = 1;

    return tMatrix;
}

Matrix<double> getScaleMatrix(double scaleX, double scaleY, double centerX, double centerY) {
    Matrix<double> t1Matrix = getTranslationMatrix(-centerX, -centerY);
    Matrix<double> sMatrix = getBasicScaleMatrix(scaleX, scaleY);
    Matrix<double> t2Matrix = getTranslationMatrix(centerX, centerY);

    return (t1Matrix * sMatrix) * t2Matrix;
}

Matrix<double> getRotateMatrix(double angle, double centerX, double centerY) {
    Matrix<double> t1Matrix = getTranslationMatrix(-centerX, -centerY);
    Matrix<double> rMatrix = getBasicRotateMatrix(angle);
    Matrix<double> t2Matrix = getTranslationMatrix(centerX, centerY);

    return (t1Matrix * rMatrix) * t2Matrix;
}

void outputToFile() {
    string filename = "";
    ofstream fileOutput;
    
    bool validFile = false;
    while(!validFile) {
        cout << "Please enter name of the file to output to "
             << "(File will be overwritten! If it doesn't exist, "
             << "it will be created): ";

        getline(cin, filename);

        cout << endl;

        fileOutput.open(filename);
    
        if(!fileOutput.good()) {
            cout << "Failed to open file. Please try again." << endl;
            cout << endl;
        }
        
        else
            validFile = true;
    }

    for(int i = 0; i < lines.size(); i++) {
        Line currentLine = lines[i];
        Vertex vertex1 = vertices[currentLine.v1Index];
        Vertex vertex2 = vertices[currentLine.v2Index];

        fileOutput << vertex1.x << " " << vertex1.y << " "
                   << vertex2.x << " " << vertex2.y << "\n";
    }
}

void draw() {
    for(int i = 0; i < lines.size(); i++) {
	Line currentLine = lines[i];
	Vertex vertex1 = vertices[currentLine.v1Index];
	Vertex vertex2 = vertices[currentLine.v2Index];

	lineClipAndRender(vertex1.x, vertex1.y,  vertex2.x, vertex2.y);
    }
}

/*
 * Used https://www.youtube.com/watch?v=NobLtrXvh0Q and
 * https://en.wikipedia.org/wiki/Cohen%E2%80%93Sutherland_algorithm
 * as sources.
 */
void lineClipAndRender(int x0, int y0, int x1, int y1) {
    int vertex1RegionCode = getRegionCode(x0, y0);
    int vertex2RegionCode = getRegionCode(x1, y1);

    while(true) {
	// line is completely visible, so draw it
	if((vertex1RegionCode | vertex2RegionCode) == 0) {
	    drawLine(x0, y0, x1, y1);
	    break;
	}

	// line is completely invisible, ignore it
	else if((vertex1RegionCode & vertex2RegionCode) != 0)
	    break;

	// line is not completely visible or invisible, so we need to break it up
	else {
	    double intersectionX, intersectionY;
	    
	    // pick one of the points that is outside the viewport
	    int currentRegionCode;
	    if(vertex1RegionCode > vertex2RegionCode)
		currentRegionCode = vertex1RegionCode;
	    else
		currentRegionCode = vertex2RegionCode;

	    // figure out where the line intersects:

	    // this point in the top area
	    if((currentRegionCode & TOP) > 0) {
		intersectionY = HEIGHT;
		intersectionX = (intersectionY - y0)/(((double) y1 - y0)/(x1 - x0)) + x0; 
	    }

	    // this point is in the bottom area
	    else if((currentRegionCode & BOTTOM) > 0) {
		intersectionY = 0;
		intersectionX = (intersectionY - y0)/(((double) y1 - y0)/(x1 - x0)) + x0; 
	    }

	    // this point is in the left area
	    else if((currentRegionCode & LEFT) > 0) {
		intersectionX = 0;
		intersectionY = (((double) y1 - y0)/(x1 - x0)) * (intersectionX - x0) + y0;
	    }

	    // this point is in the right area
	    else {
		intersectionX = WIDTH;
		intersectionY = (((double) y1 - y0)/(x1 - x0)) * (intersectionX - x0) + y0;
	    }

	    // update the point with the intersection x and y
	    if(currentRegionCode == vertex1RegionCode) {
		x0 = intersectionX;
		y0 = intersectionY;
		vertex1RegionCode = getRegionCode(x0, y0);
	    }

	    else {
		x1 = intersectionX;
		y1 = intersectionY;
		vertex2RegionCode = getRegionCode(x1, y1);
	    }
	}
    }
}

int getRegionCode(int x, int y) {
    int regionCode = 0;

    if(x < 0)
        regionCode |= LEFT;

    if(x > WIDTH)
        regionCode |= RIGHT;

    if(y < 0)
        regionCode |= BOTTOM;

    if(y > HEIGHT)
        regionCode |= TOP;

    return regionCode;
}

// void render() {
//     for(int i = 0; i < lines.size(); i++) {
//         Line currentLine = lines[i];
//         Vertex vertex1 = vertices[currentLine.v1Index];
//         Vertex vertex2 = vertices[currentLine.v2Index];

//         drawLine(vertex1.x, vertex1.y, vertex2.x, vertex2.y);
//     }
// }

vector<string> split(string str, string delim) {
    vector<string> result;

    int start = 0;
    int end = str.find(delim);

    while(end != string::npos) {
        result.push_back(str.substr(start, end - start));
        start = end + delim.length();
        end = str.find(delim, start);
    }

    result.push_back(str.substr(start, end));

    return result;
}

int vertexIsUnique(Vertex &vertex) {
    for(int i = 0; i < vertices.size(); i++) {
        Vertex currentVertex = vertices[i];

        if(currentVertex.x == vertex.x && currentVertex.y == vertex.y)
            return i;
    }

    return -1;
}

bool isANumber(string str) {
    if(str[0] == '-')
        str = str.substr(1);

    if(str == "" || str == " ")
        return false;

    return str.find_first_not_of("0123456789.") == string::npos;
}

