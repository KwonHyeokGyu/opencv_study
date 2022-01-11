#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;

class LaplacianZC {
private:
	//���ö�þ�
	cv::Mat laplace;
	//���ö�þ� Ŀ���� ���� ũ��
	int aperture;

public:
	LaplacianZC() : aperture(3) {}

	//Ŀ���� ���� ũ�� ����
	void setAperture(int a) {
		aperture = a;
	}

	//���ö�þ��� �ε� �Ҽ������� ���
	cv::Mat computeLaplacian(const cv::Mat & image){
		// ���ö�þ� ���
		cv::Laplacian(image, laplace, CV_32F, aperture);
		return laplace;
	}

	//���ö�þ� ����� 8��Ʈ �������� ���
	//0�� �׷��̷��� 128�� ����
	//scale�� �������� ������ �ִ��� �� 255�� ����
	//�� �޼ҵ带 ȣ���ϱ� ���� computreLaplacian�� ȣ���ؾ� ��
	Mat getLaplacianImage(double scale = -1.0) {
		if (scale < 0) {
			double lapmin, lapmax;

			//���ö�þ� �ּڰ��� �ִ� ���
			minMaxLoc(laplace, &lapmin, &lapmax);

			//���ö�þ��� 127�� ����
			scale = 127 / std::max(-lapmin, lapmax);
		}

		//�׷��̷��� ����
		Mat laplaceImage;
		laplace.convertTo(laplaceImage, CV_8U, scale, 128);
		return laplaceImage;
	}

	Mat getZeroCrossings(Mat laplace) {
		
		//0���� ���ȭ
		//���� ���� ������
		//��� ���� ���
		Mat signImage;
		threshold(laplace, signImage, 0, 255, THRESH_BINARY);

		// +/ -������ ���� ������ ��â
		Mat binary;
		signImage.convertTo(binary, CV_8U);

		// +/- ������ ���� ������ ��â
		Mat dilated;
		dilate(binary, dilated, Mat());

		//������ �ܰ��� ��ȯ
		return dilated - binary;
	}

};