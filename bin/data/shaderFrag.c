#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

/*
void main(){
	gl_FragColor = gl_Color;
}
*/
	//out vec4 outputColor;

void main()
{
		// gl_FragCoord contains the window relative coordinate for the fragment.
		// we use gl_FragCoord.x position to control the red color value.
		// we use gl_FragCoord.y position to control the green color value.
		// please note that all r, g, b, a values are between 0 and 1.
 
	float windowWidth = 768;
	float windowHeight = 768;
 
	float r = gl_FragCoord.x / windowWidth;
	float g = gl_FragCoord.y / windowHeight;
	float b = (1-r*g);
	float a = 0.8;
	gl_FragColor = vec4(r, g, b, a);
}