#include <stdio.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "LaplacianZC.h"
using namespace cv;

int main(){
	Mat src;
	src = imread("C:/Users/lge/Desktop/OpenCV/images/boldt.jpg", 0);

	LaplacianZC laplacian;
	laplacian.setAperture(7); // 7*7 라플라시안
	Mat flap = laplacian.computeLaplacian(src);
	Mat laplace = laplacian.getLaplacianImage();

	namedWindow("Laplacian Image (7*7)");
	imshow("Laplacian Image (7*7)", laplace);



	laplacian.setAperture(3); // 7*7 라플라시안
	flap = laplacian.computeLaplacian(src);
	laplace = laplacian.getLaplacianImage();

	namedWindow("Laplacian Image (3*3)");
	imshow("Laplacian Image (3*3)", laplace);

	waitKey();
	return 0;
}