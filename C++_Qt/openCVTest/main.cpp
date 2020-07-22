
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using std::cout; 
using std::cin; 
using std::string; 
using std::endl; 

#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>

using cv::Mat; 

class Point3D {

public: 

	Point3D(double x, double y, double z): 
	x_(x),
	y_(y),
	z_(z){};

	double X() {return x_;};
	double Y() {return y_;};
	double Z() {return z_;};

private: 

	double x_, y_, z_; 
};

int main(int argc, char *argv[]) {

	Point3D P0(2.3,4.2,5.1); 

	Point3D p01(0.7,0,0); 
	Point3D p02(0,0.7,0); 
	Point3D nNormalised(0,0,0.7); 

	cv::Mat R = (cv::Mat_<float>(3, 3) <<
		p01.X(), p02.X(), nNormalised.X(),
		p01.Y(), p02.Y(), nNormalised.Y(),
		p01.Z(), p02.Z(), nNormalised.Z());
	cv::Mat Rinv = R.inv();
	cout << "Rinv= "<<Rinv<<endl;

	cv::Mat t = (cv::Mat_<float>(3, 1) << P0.X(), P0.Y(), P0.Z()); 
	
	cv::Mat MinusRinvt(Rinv * t); 
	cout << "MinusRinvt= "<<MinusRinvt<<endl;

	cv::Mat T( cv::Mat::zeros(4,4,CV_64F) ); // see https://docs.opencv.org/2.4/modules/core/doc/basic_structures.html
	T.at<double>(3,3) = 1.; 

	Rinv.copyTo(T(cv::Rect(0, 0, 3, 3))); // x y width height
	MinusRinvt.copyTo(T(cv::Rect(3, 0, 1, 3)));	 // x y width height

	cout << "T= "<<T<<endl;

	double u(0.1); 
	double v(0.2); 
	cv::Mat p = T * (cv::Mat_<double>(4, 1) << u, v, 0, 1);
	cout << "p= "<< p <<endl;
//
//	cout << "Ok!\n" << endl;
	return 0; 
}    
        