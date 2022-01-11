//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
//
//
//int main()
//{
//	// Read input image
//	cv::Mat image = cv::imread("C:/Users/lge/Desktop/개인/인턴/OpenCV/예제/2~5장/boldt.jpg");
//	if (!image.data)
//		return 0;
//
//	// Display the image
//	cv::namedWindow("Original Image");
//	cv::imshow("Original Image", image);
//
//	// define bounding rectangle 
//	cv::Rect rectangle(50, 25, 210, 180);
//	// the models (internally used)
//	cv::Mat bgModel, fgModel;
//	// segmentation result
//	cv::Mat result; // segmentation (4 possible values)
//
//	// GrabCut segmentation
//	cv::grabCut(image,    // input image
//		result,   // segmentation result
//		rectangle,// rectangle containing foreground 
//		bgModel, fgModel, // models
//		5,        // number of iterations
//		cv::GC_INIT_WITH_RECT); // use rectangle
//
//	// Get the pixels marked as likely foreground
//	cv::compare(result, cv::GC_PR_FGD, result, cv::CMP_EQ);
//	// or:
//	//	result= result&1;
//
//	// create a white image
//	cv::Mat foreground(image.size(), CV_8UC3,
//		cv::Scalar(255, 255, 255));
//
//	image.copyTo(foreground, result); // bg pixels not copied
//
//	// draw rectangle on original image
//	cv::rectangle(image, rectangle, cv::Scalar(255, 255, 255), 1);
//	cv::namedWindow("Image with rectangle");
//	cv::imshow("Image with rectangle", image);
//
//	// display result
//	cv::namedWindow("Foreground object");
//	cv::imshow("Foreground object", foreground);
//
//	cv::waitKey();
//	return 0;
//}