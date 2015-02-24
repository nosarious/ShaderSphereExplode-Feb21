# ShaderSphereExplode-Feb21
openframeworks geometry shader tests - explode objects

This is an attempt to disintegrate objects over time. Eventually it should be able to recieve an 'age'
and move the triangles down the screen with a trajectory specific to each item.

This will be part of the visualization of my multiple kinect project completed for my Masters in CMD.

The goal of this project was to provide a better and more interesting example for a geometry shader than the one included in the examples with openframeworks. ( https://github.com/openframeworks/openFrameworks/tree/master/examples/gl/geometryShaderExample )
My geometry shader has the same morphing functions as the vertex shader example included in the DeMystified Vertex Deformation example. 
( https://github.com/firmread/ofDemystified/tree/master/08-Shaders/06-VertexDeformation/src )

I found their example to include too many unexplained things, such as the creation of a series of triangles, that were irrelevant to the goal, ie: how does a shader work.

My example uses an ofIcoSphere primitive, and moves it with the same intention as the vertex deformation, with input from horizontal and vertical mouse coordinates. These changes become more pronounced when the window is smaller than the screen realestate, and the mouse can go beyond the edge of the drawing window.

Some examples of images created are here (taken with Hipstamatic)
http://gersart.tumblr.com/image/111643169139 - an image showing a normal sphere primitive deformed along the y axis over time.
http://gersart.tumblr.com/image/111731653604 - an ofIcoSphere primitive prior to deformation.
http://gersart.tumblr.com/image/111646247479 - larger number of sphere primitive deforming along x-y axis over time.
http://gersart.tumblr.com/image/111800647014 - an ofIcoSphere deforming along y-axis over time.

The second one implies a certain lighting change which is not included in this example.
information on how to change variables is commented in the code.

enjoy.
