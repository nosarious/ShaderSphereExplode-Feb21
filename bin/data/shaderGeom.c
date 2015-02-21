#version 120

#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable



uniform float thickness;
uniform vec3 lightDir;

uniform float phase = 0.0;			//Phase for "sin" function
uniform float distortAmount = 0.25; //Amount of distortion

void main(void)
{
	
	
	
	vec3 p0 = gl_PositionIn[0].xyz;
	vec3 p1 = gl_PositionIn[1].xyz;
	vec3 p2 = gl_PositionIn[2].xyz;
	vec3 dir0 = p1 - p0;
	vec3 dir1 = p2 - p1;
	
	
	
	vec3 N1 = normalize(cross(dir1,dir0));
	
	vec3 N = N1;
	
	
	float distort = distortAmount * sin( phase + 0.01 * p0.y );
	
		//if (distort<100) distort = -100;
	
		//Move the position
	N.x /= 1.0 + distort;
	N.y /= 1.0 + distort;
	N.z /= 1.0 + distort;
	
	float distort2 = distortAmount * sin( phase + 0.01 * p0.x );
	
		//if (distort<100) distort = -100;
	
		//Move the position
	N.x /= 1.0 + distort2;
	N.y /= 1.0 + distort2;
	N.z /= 1.0 + distort2;
	/*
	vec3 diff = N1 - N;
	
	if Diff >200 ;
	*/
		//Compute value of distortion for current vertex
		//float explode_factor = distortAmount * sin( phase + 0.015 * N.y );
	
	for (int i = 0; i < 3; i++)
		{
		gl_Position = gl_PositionIn[i] +
		vec4(50*N, 0.0);
		EmitVertex();
		}
	/*
	
	float thickness = 10;
	
	vec3 p0 = gl_PositionIn[0].xyz;
	vec3 p1 = gl_PositionIn[1].xyz;
	vec3 p2 = gl_PositionIn[2].xyz;
	
	vec3 up = vec3(0, 0, 1);	// arbitrary up vector
	
	vec3 dir0 = normalize(p0-p1);			// normalized direction vector from p0 to p1
	vec3 dir1 = normalize(p2-p1);			// normalized direction vector from p0 to p1
	
	vec3 diff = dir1 - dir0;
	float diff_len = length(diff);
	
	vec3 N = normalize(cross(dir1,dir0));
	
		//------ Generate a new face along the direction of the face normal
  // only if diff_len is not too small.
  //
	/*
	if (length(diff_len) > 0.001)
  {
	  vec3 N = normalize(cross(V1, V0));
	  float len = sqrt(P0.x*P0.x + P0.z*P0.z);
	  float scale = 2.0 + 1.0 * cos(time*2.0 + len);
	  P0 = vec4(P.xyz + (N * normal_length * scale) + \
			   (N * vec3(0.05, 0.05, 0.05)), 1.0);
	  gl_Position = gxl3d_ModelViewProjectionMatrix * P0;
	  vertex_color = vertex[i].color;
	  EmitVertex();
	  }
  */
	/*
	vec3 right = normalize(cross(dir, up));	// right vector
	vec3 norm = cross(right, dir);
	
	float fColMult = abs(dot(norm, lightDir));
	vec4 colMult = vec4(fColMult, fColMult, fColMult, 1.0);
		//float fColMult = abs(dot(norm, right*10));
	
	right *= thickness;
	
	gl_Position = gl_ModelViewProjectionMatrix * vec4(p0*norm, 1.0);
	gl_FrontColor = gl_FrontColorIn[0] * fColMult;
	EmitVertex();
	
	gl_Position = gl_ModelViewProjectionMatrix * vec4(p1*norm, 1.0);
	gl_FrontColor = gl_FrontColorIn[0] * fColMult;
	EmitVertex();
	
	gl_Position = gl_ModelViewProjectionMatrix * vec4(p2*norm, 1.0);
	gl_FrontColor = gl_FrontColorIn[1] * fColMult;
	EmitVertex();
	
	gl_Position = gl_ModelViewProjectionMatrix * vec4(p0, 1.0);
	gl_FrontColor = gl_FrontColorIn[1] * fColMult;
	EmitVertex();
	*/
	EndPrimitive();

}