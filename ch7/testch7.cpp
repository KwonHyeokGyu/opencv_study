//#include <iostream>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//#include <vector>
//#define PI 3.1415926
//using namespace cv;
//// Ȯ���� ���� ��ȯ
//class LineFinder {
//private:
//	// �� ����
//	Mat img;
//	// ������ ���� ������ ������ ����
//	std::vector<Vec4i> lines;
//	// ����� �ػ�(accumulator resolution) �Ķ����
//	double deltaRho;
//	double deltaTheta;
//	// ������ ���ֵǱ� ���� �޾ƾ� �ϴ� ��ǥ �ּ� ����
//	int minVote;
//	// ���� �ּ� ����
//	double minLength;
//	//���� ���󰡴� �ִ� ��� ����(gap)
//	double maxGap;
//
//public:
//	// �⺻ ���� �ػ󵵴� 1������ 1ȭ���̰�, ����� ���� �ּ� ���̵� ����
//	LineFinder() :deltaRho(1), deltaTheta(PI / 180), minVote(10), minLength(0.), maxGap(0.) {}
//	// ����� �ػ� ����
//	void setAccResolution(double dRho, double dTheta) {
//		deltaRho = dRho;
//		deltaTheta = dTheta;
//	}
//	// ��ǥ �ּ� ���� ����
//	void setMinVote(int minv) {
//		minVote = minv;
//	}
//	// �� ���̿� ���� ����
//	void setLineLengthAndGap(double length, double gap) {
//		minLength = length;
//		maxGap = gap;
//	}
//	// Ȯ���� ���� ��ȯ ����
//	std::vector <Vec4i> findLines(Mat& binary) {
//		lines.clear();
//		HoughLinesP(binary, lines, deltaRho, deltaTheta, minVote, minLength, maxGap);
//		return lines;
//	}
//	// ������ ���� ���� �׸�
//	void drawDetectedLines(Mat& image, Scalar color = Scalar(255, 255, 255)) {
//		// �� �׸���
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
//	// LineFinder �ν��ٽ� ����
//	LineFinder finder;
//
//	// Ȯ���� ���� ��ȯ �Ķ���� ����
//	finder.setLineLengthAndGap(100, 20);
//	finder.setMinVote(60);
//
//	// ���� ������ �� �׸�
//	std::vector<Vec4i> lines = finder.findLines(contours);
//	finder.drawDetectedLines(src);
//
//	namedWindow("Detected Lines with HoughP");
//	imshow("Detected Lines with HoughP", src);
//
//	waitKey();
//	return 0;
//}