#version 120

#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable
	// get the variables for speed and phase (mousex and mousey)
uniform float phase = 0.0;		//Phase for "sin" function
uniform float distortAmount = 0.25; 	//Amount of distortion
	//the geometry shader has been set to recieve triangles
	//therefor it has three points to work with
void main(void)
{
	vec3 p0 = gl_PositionIn[0].xyz;
	vec3 p1 = gl_PositionIn[1].xyz;
	vec3 p2 = gl_PositionIn[2].xyz;
	vec3 dir0 = p1 - p0;
	vec3 dir1 = p2 - p1;
	
	//	find the normal of the face (direction it is facing)
	vec3 N = normalize(cross(dir1,dir0));
	
	float distort = distortAmount * sin( phase + 0.01 * p0.y ); //deform along y axis
	
		//Move the position
	N.x /= 1.0 + distort;
	N.y /= 1.0 + distort;
	N.z /= 1.0 + distort;
	
	//uncomment this section if you would like the deformation to be along two axis instead of just one.
	/*
	float distort2 = distortAmount * sin( phase + 0.01 * p0.x ); //deform along x axis
		//Move the position
	N.x /= 1.0 + distort2;
	N.y /= 1.0 + distort2;
	N.z /= 1.0 + distort2;
	*/ 
		//remember there are three points to be moved
	for (int i = 0; i < 3; i++)
	{
		gl_Position = gl_PositionIn[i] + vec4(50*N, 0.0);
		EmitVertex();
	}
	
	EndPrimitive();

}
