//#include <iostream>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//#include <vector>
//#define PI 3.1415926
//using namespace cv;
//// 확률적 허프 변환
//class LineFinder {
//private:
//	// 원 영상
//	Mat img;
//	// 검출한 선의 끝점을 포함한 벡터
//	std::vector<Vec4i> lines;
//	// 누산기 해상도(accumulator resolution) 파라미터
//	double deltaRho;
//	double deltaTheta;
//	// 선으로 간주되기 전에 받아야 하는 투표 최소 개수
//	int minVote;
//	// 선의 최소 길이
//	double minLength;
//	//선을 따라가는 최대 허용 간격(gap)
//	double maxGap;
//
//public:
//	// 기본 누적 해상도는 1각도당 1화소이고, 가녁곧 없고 최소 길이도 없음
//	LineFinder() :deltaRho(1), deltaTheta(PI / 180), minVote(10), minLength(0.), maxGap(0.) {}
//	// 누산기 해상도 설정
//	void setAccResolution(double dRho, double dTheta) {
//		deltaRho = dRho;
//		deltaTheta = dTheta;
//	}
//	// 투표 최소 개수 설정
//	void setMinVote(int minv) {
//		minVote = minv;
//	}
//	// 선 길이와 간격 설정
//	void setLineLengthAndGap(double length, double gap) {
//		minLength = length;
//		maxGap = gap;
//	}
//	// 확률적 허프 변환 적용
//	std::vector <Vec4i> findLines(Mat& binary) {
//		lines.clear();
//		HoughLinesP(binary, lines, deltaRho, deltaTheta, minVote, minLength, maxGap);
//		return lines;
//	}
//	// 검출한 선을 영상에 그림
//	void drawDetectedLines(Mat& image, Scalar color = Scalar(255, 255, 255)) {
//		// 선 그리기
//		std::vector<Vec4i>::const_iterator it2 = lines.begin();
//
//		while (it2 != lines.end()) {
//			Point pt1((*it2)[0], (*it2)[1]);
//			Point pt2((*it2)[2], (*it2)[3]);
//			line(image, pt1, pt2, color);
//			++it2;
//		}
//	}
//};
//
//int main() {
//	Mat src = imread("road.jpg", 0);
//
//	namedWindow("Original Image");
//	imshow("Original Image", src);
//
//	Mat contours;
//	Canny(src, contours, 125, 350);
//
//	// LineFinder 인스텐스 생성
//	LineFinder finder;
//
//	// 확률적 허프 변환 파라미터 설정
//	finder.setLineLengthAndGap(100, 20);
//	finder.setMinVote(60);
//
//	// 선을 검출한 후 그림
//	std::vector<Vec4i> lines = finder.findLines(contours);
//	finder.drawDetectedLines(src);
//
//	namedWindow("Detected Lines with HoughP");
//	imshow("Detected Lines with HoughP", src);
//
//	waitKey();
//	return 0;
//}