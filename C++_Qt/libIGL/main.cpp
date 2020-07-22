//Import a PLY mesh with \libigl-master\include\igl\readPLY.cpp/h
//mesh to test : 
//Ventricular system/central canal... verify!


//Get the centroid of the mesh, see centroid.cpp
//Set a plane. This can be coded as : 
// Eigen::MatrixXd V=(x y z
//					  x y z
//					  ...);
// Eigen::MatrixXi F = ( v1 v2 v3 
//						 v1 v2 v3 
//						...

// Performs the intersection with : 
// 	https://github.com/libigl/libigl/blob/master/include/igl/cut_mesh.h
// see usage: https://github.com/libigl/libigl/issues/1212
//https://stackoverflow.com/questions/24694845/c-library-for-mesh-to-mesh-intersection-what-is-available
// using : mesh_boolean

#include <igl/readOFF.h>
#include <igl/opengl/glfw/Viewer.h>

Eigen::MatrixXd V;
Eigen::MatrixXi F;

int main(int argc, char *argv[])
{
  // Load a mesh in OFF format
  igl::readOFF("bunny.off", V, F);

  // Plot the mesh
  igl::opengl::glfw::Viewer viewer;
  viewer.data().set_mesh(V, F);
  viewer.launch();

}