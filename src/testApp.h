#pragma once

/*
This example demonstrates using vertex shader for deforming 3D objects.
It draws cloud of triangles and apply vertex shader to deform it.
The mouse position controls the following parameters:
x - amount of deformation, y - speed of deformation pulsation. 

This is based off of example 06-VertexDeformation from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 8 - Using Shaders

It has been modified to use a geometry shader instead of just vertex and fragment shader.
*/

#include "ofMain.h"

class testApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	ofShader shader;	//Shader

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	//traditional sphere primitive which will look like strips
	ofSpherePrimitive sphere;
	
	//sphere primitive made up of equal-sized triangles (like a 20+ sided dice)
	//ofIcoSpherePrimitive sphere;
	
	//vector to hold all triangles
	vector<ofMeshFace> triangles;
	
	//mesh to hold triangles for drawing as a single unit
	ofMesh testMesh;
};
