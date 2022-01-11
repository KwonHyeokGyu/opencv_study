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
	// 비디오 파일 엵기
	cv::VideoCapture capture("../../images/bike.avi");
	//	cv::VideoCapture capture("http://www.laganiere.name/bike.avi");
	
	// 비디오 열기에 성공했는지 확인
	if (!capture.isOpened())
		return 1;

	// 프레임률 얻기
	double rate = capture.get(cv::CAP_PROP_FPS);
	std::cout << "Frame rate: " << rate << "fps" << std::endl;

	bool stop(false);
	cv::Mat frame; // 현재 비디오 프레임
	cv::namedWindow("Extracted Frame");

	// 각 프레임 간을 밀리초 단위로 지연(delay)
	// 비디오 프레임률에 해당
	int delay = 1000 / rate;

	long long i = 0;
	std::string b = "bike";
	std::string ext = ".bmp";

	// 비디오의 모든 프레임에 대해 
	while (!stop) {

		// 다음 프레임이 있으면 읽기
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

		// 지연 도입
		// 혹은 중지하기 위해 키 입력
		if (cv::waitKey(delay) >= 0)
			stop = true;
	}

	// 비디오 파일 닫기
	// 소멸자가 호출하기 때문에 필요 없음
	capture.release();

	cv::waitKey();

	// VideoProcessor 클래스 사용

	// 인스턴스 생성
	VideoProcessor processor;

	// 비디오 파일 열기
	processor.setInput("../../images/bike.avi");

	// 비디오를 표시하는 창 선언
	processor.displayInput("Input Video");
	processor.displayOutput("Output Video");

	// 원 프레임률로 비디오 재생
	processor.setDelay(1000. / processor.getFrameRate());

	// 프레임 처리기 콜백 함수 설정
	processor.setFrameProcessor(canny);

	// 비디오 출력
	processor.setOutput("../../images/bikeCanny.avi", -1, 15);

	// 처리 멈춤
	processor.stopAtFrameNo(51);

	// 처리 시작
	processor.run();

	cv::waitKey();

	return 0;
}
