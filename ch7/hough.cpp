//#include <iostream>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//#include <vector>
//#define PI 3.1415926
//using namespace cv;
//
//int main() {
//	Mat src = imread("C:/Users/lge/Desktop/OpenCV/images/road.jpg", 0);
//
//	namedWindow("Original Image");
//	imshow("Original Image", src);
//
//	Mat contours;
//	Canny(src, contours, 125, 350);
//
//	// 선을 검출하기 위한 허프 변환
//	std::vector<Vec2f> lines;
//	HoughLines(contours, lines, 1, PI / 180, 60);
//
//	Mat result(contours.rows, contours.cols, CV_8U, cv::Scalar(255));
//	src.copyTo(result);
//
//	std::vector<Vec2f>::const_iterator it = lines.begin();
//	while (it != lines.end()) {
//
//		float rho = (*it)[0];
//		float theta = (*it)[1]; // 두 번재 요소는 각도인 theta
//
//		if (theta < PI/4. || theta > 3.*PI/4.){ // ~수직선
//			// 첫 번째 행과 해당 선이 교차하는 점
//			Point pt1(rho / cos(theta), 0);
//
//			// 마지막 행과 해당 선이 교차하는 점
//			Point pt2((rho - result.rows * sin(theta)) / cos(theta), result.rows);
//
//			// 흰색 선을 그림
//			line(src, pt1, pt2, Scalar(255), 1);
//		}else{ // ~수평선
//			// 첫 번재 열과 해당 선이 교차하는 점
//			Point pt1(0, rho / sin(theta));
//			// 마지막 행과 해당 선이 교차하는 점
//			Point pt2(result.cols, (rho - result.cols * cos(theta)) / sin(theta));
//			// 흰색 선을 그림
//			line(src, pt1, pt2, Scalar(255), 1);
//		}
//		++it;
//	}
//
//	namedWindow("Lines with Hough");
//	imshow("Lines with Hough", src);
//
//	waitKey();
//	return 0;
//}
//
//
//
//
////class LineFinder {
////private:
////	//원 영상
////	Mat img;
////	//검출한 선의 끝점을 포함한 벡터
////	std::vector<Vec4i> lines;
////	//누산기 해상도(accumulator resolution) 파라미터
////	double deltaRho;
////	double deltaTheta;
////	//선으로 간주되기 전에 받아야 하는 투표 최소 개수
////	int minVote;
////	//선의 최소 길이
////	double minLength;
////	//선을 따라가는 최대 허용 간격(gap)
////	double maxGap;
////public:
////	//기본 누적 해상도는 1 각도당 1화소이고, 간격도 없고 최소 길이도 없음
////	LineFinder() :deltaRho(1), deltaTheta(PI / 180),
////		minVote(10), minLength(0.), maxGap(0.) {}
////
////	//누산기 해상도 설정
////	void setAccResolution(double dRho, double dTheta) {
////		deltaRho = dRho;
////		deltaTheta = dTheta;
////	}
////
////	//투표 최소 개수 설정
////	void setMinVote(int minv) {
////		minVote = minv;
////	}
////
////	//선 길이와 간격 설정
////	void setLineLengthAndGap(double length, double gap) {
////		minLength = length;
////		maxGap = gap;
////	}
////
////};
