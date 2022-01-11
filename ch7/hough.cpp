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
//	// ���� �����ϱ� ���� ���� ��ȯ
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
//		float theta = (*it)[1]; // �� ���� ��Ҵ� ������ theta
//
//		if (theta < PI/4. || theta > 3.*PI/4.){ // ~������
//			// ù ��° ��� �ش� ���� �����ϴ� ��
//			Point pt1(rho / cos(theta), 0);
//
//			// ������ ��� �ش� ���� �����ϴ� ��
//			Point pt2((rho - result.rows * sin(theta)) / cos(theta), result.rows);
//
//			// ��� ���� �׸�
//			line(src, pt1, pt2, Scalar(255), 1);
//		}else{ // ~����
//			// ù ���� ���� �ش� ���� �����ϴ� ��
//			Point pt1(0, rho / sin(theta));
//			// ������ ��� �ش� ���� �����ϴ� ��
//			Point pt2(result.cols, (rho - result.cols * cos(theta)) / sin(theta));
//			// ��� ���� �׸�
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
////	//�� ����
////	Mat img;
////	//������ ���� ������ ������ ����
////	std::vector<Vec4i> lines;
////	//����� �ػ�(accumulator resolution) �Ķ����
////	double deltaRho;
////	double deltaTheta;
////	//������ ���ֵǱ� ���� �޾ƾ� �ϴ� ��ǥ �ּ� ����
////	int minVote;
////	//���� �ּ� ����
////	double minLength;
////	//���� ���󰡴� �ִ� ��� ����(gap)
////	double maxGap;
////public:
////	//�⺻ ���� �ػ󵵴� 1 ������ 1ȭ���̰�, ���ݵ� ���� �ּ� ���̵� ����
////	LineFinder() :deltaRho(1), deltaTheta(PI / 180),
////		minVote(10), minLength(0.), maxGap(0.) {}
////
////	//����� �ػ� ����
////	void setAccResolution(double dRho, double dTheta) {
////		deltaRho = dRho;
////		deltaTheta = dTheta;
////	}
////
////	//��ǥ �ּ� ���� ����
////	void setMinVote(int minv) {
////		minVote = minv;
////	}
////
////	//�� ���̿� ���� ����
////	void setLineLengthAndGap(double length, double gap) {
////		minLength = length;
////		maxGap = gap;
////	}
////
////};
