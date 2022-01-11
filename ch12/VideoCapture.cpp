#include <string>
#include <iostream>
#include <sstream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "videoprocessor.h"

void draw(const cv::Mat& img, cv::Mat& out) {

	img.copyTo(out);
	cv::circle(out, cv::Point(100, 100), 5, cv::Scalar(255, 0, 0), 2);
}

// processing function
void canny(cv::Mat& img, cv::Mat& out) {

	// Convert to gray
	if (img.channels() == 3)
		cv::cvtColor(img, out, cv::COLOR_BGR2GRAY);
	// Compute Canny edges
	cv::Canny(out, out, 100, 200);
	// Invert the image
	cv::threshold(out, out, 128, 255, cv::THRESH_BINARY_INV);
}

int main()
{
	// ���� ���� ����
	cv::VideoCapture capture("../../images/bike.avi");
	//	cv::VideoCapture capture("http://www.laganiere.name/bike.avi");
	
	// ���� ���⿡ �����ߴ��� Ȯ��
	if (!capture.isOpened())
		return 1;

	// �����ӷ� ���
	double rate = capture.get(cv::CAP_PROP_FPS);
	std::cout << "Frame rate: " << rate << "fps" << std::endl;

	bool stop(false);
	cv::Mat frame; // ���� ���� ������
	cv::namedWindow("Extracted Frame");

	// �� ������ ���� �и��� ������ ����(delay)
	// ���� �����ӷ��� �ش�
	int delay = 1000 / rate;

	long long i = 0;
	std::string b = "bike";
	std::string ext = ".bmp";

	// ������ ��� �����ӿ� ���� 
	while (!stop) {

		// ���� �������� ������ �б�
		if (!capture.read(frame))
			break;

		cv::imshow("Extracted Frame", frame);

		std::string name(b);
		std::ostringstream ss; ss << std::setfill('0') << std::setw(3) << i; name += ss.str(); i++;
		name += ext;

		std::cout << name << std::endl;

		//		cv::Mat test;
		//      cv::resize(frame, test, cv::Size(), 0.2,0.2);
		//		cv::imwrite(name, frame);
		//		cv::imwrite(name, test);

		// ���� ����
		// Ȥ�� �����ϱ� ���� Ű �Է�
		if (cv::waitKey(delay) >= 0)
			stop = true;
	}

	// ���� ���� �ݱ�
	// �Ҹ��ڰ� ȣ���ϱ� ������ �ʿ� ����
	capture.release();

	cv::waitKey();

	// VideoProcessor Ŭ���� ���

	// �ν��Ͻ� ����
	VideoProcessor processor;

	// ���� ���� ����
	processor.setInput("../../images/bike.avi");

	// ������ ǥ���ϴ� â ����
	processor.displayInput("Input Video");
	processor.displayOutput("Output Video");

	// �� �����ӷ��� ���� ���
	processor.setDelay(1000. / processor.getFrameRate());

	// ������ ó���� �ݹ� �Լ� ����
	processor.setFrameProcessor(canny);

	// ���� ���
	processor.setOutput("../../images/bikeCanny.avi", -1, 15);

	// ó�� ����
	processor.stopAtFrameNo(51);

	// ó�� ����
	processor.run();

	cv::waitKey();

	return 0;
}
