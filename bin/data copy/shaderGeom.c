#version 120

#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable
	//layout (triangles) in;
	//layout (triangle_strip) out;
	//layout (max_vertices = 3) out;

void main(void)
{
	
	float thickness = 10;
	
	vec3 p0 = gl_PositionIn[0].xyz;
	vec3 p1 = gl_PositionIn[1].xyz;
	
	vec3 up = vec3(0, 0, 1);	// arbitrary up vector
	
	vec3 dir = normalize(p1 - p0);			// normalized direction vector from p0 to p1
	vec3 right = normalize(cross(dir, up));	// right vector
	vec3 norm = cross(right, dir);
		//float fColMult = abs(dot(norm, lightDir));
		//vec4 colMult = vec4(fColMult, fColMult, fColMult, 1.0);
	float fColMult = abs(dot(norm, right*10));
	
	right *= thickness;
	
	gl_Position = gl_ModelViewProjectionMatrix * vec4(p0 - right, 1.0);
	gl_FrontColor = gl_FrontColorIn[0] * fColMult;
	EmitVertex();
	/*
	gl_Position = gl_ModelViewProjectionMatrix * vec4(p0 + right, 1.0);
	gl_FrontColor = gl_FrontColorIn[0] * fColMult;
	EmitVertex();
	
	gl_Position = gl_ModelViewProjectionMatrix * vec4(p1 - right, 1.0);
	gl_FrontColor = gl_FrontColorIn[1] * fColMult;
	EmitVertex();
	
	gl_Position = gl_ModelViewProjectionMatrix * vec4(p1 + right, 1.0);
	gl_FrontColor = gl_FrontColorIn[1] * fColMult;
	EmitVertex();
	 */
	
}