/*
@file: ModelSphere.h/.cpp

This file creates and renders a sphere model. 

Features:
- It determines the vertices and triangles for a sphere
- Creates the vertex buffer object and the vertex buffer array
- Loads the content to the graphics card.
- Links the shader uniform and attribute variables to the content.
- Renders the sphere.

Uniform and attributes variables:
Note that this file expects to find the uniform variables
	uniform mat4 projectionMatrix;                                   
	uniform mat4 viewMatrix;                                         
	uniform mat4 modelMatrix;  
as part of the shader code

The attribute variables are:
	in vec3 in_Position;                                               
	in vec3 in_Normal;    


This file is part of CS/CPRE/ME 557 Computer Graphics at Iowa State University

Rafael Radkowski
Iowa State University
rafael@iastate.edu
+1 (515) 294-7044
MIT License

-------------------------------------------------------------------------------
Last edited:
Oct 19, 2019, RR
- Fixed a bug: the attribute location and the vertices/normal target locations were
	incorrect associated which prevented the object from being correctly rendered in some cases. 
*/
#pragma once

// stl include
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// GLEW include
#include <GL/glew.h>

// GLM include files
#define GLM_FORCE_INLINE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


// local
#include "VertexBuffers.h"			// create vertex buffer object
#include "ShaderProgram.h"			// create a shader program


using namespace std;


namespace cs557
{

	class Sphere {
	
	public:
		/*
		Create a simple coordinate system in the centroid
		@param radius - the radios of the sphere
		@param segments - number of vertical segments 
		@param rows - number of rows
		@param shader_program - overwrite the default shader program by passing a hander to the constructor
		*/
		void create(float radius, int segments = 30, int rows = 40, int shader_program = -1);


		/*
		Draw the coordinate system
		@param viewMatrix - a view matrix object
		@param modelMatrix - a model matrix object.
		*/
		void draw(glm::mat4 projectionMatrix, glm::mat4 viewMatrix, glm::mat4 modelMatrix);


		/*
		Return the shader program
		@return - int containing the shader program
		*/
		int getProgram(void){return program;}

	private:

		/*
		Create the geometry for the sphere
		@param cemter - float for the center of the sphere
		@param r - radius of the sphere
		@param spherePoints - vector to return the points of the sphere
		@param normals - param to return the normal vectors for the sphere. 
		*/
		void make_geometry(glm::vec3 cemter, double radius, double segments, double rows, 
							std::vector<glm::vec3> &spherePoints, std::vector<glm::vec3> &normals);


		int vaoID[1]; // Our Vertex Array Object
		int vboID[2]; // Our Vertex Buffer Object
		int program;
		int program_backup;

		int viewMatrixLocation;
		int modelMatrixLocation;
		int projMatrixLocation;
		

		float 	_radius;
		int 	_N;
	};
}