#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("D:\\a\\lena.jpg", 1);
	if (srcMat.empty())  return -1;

	const cv::Point2f src_pt[] = {
		cv::Point2f(150, 150),
		cv::Point2f(150, 300),
		cv::Point2f(350, 300),
		cv::Point2f(350, 150)
	};
	const cv::Point2f dst_pt[] = {
		cv::Point2f(200, 150),
		cv::Point2f(200, 300),
		cv::Point2f(340, 270),
		cv::Point2f(340, 180)
	};
	const cv::Mat affine_matrix = cv::getAffineTransform(src_pt, dst_pt);
	cv::warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());
	cv::imshow("src", srcMat);
	cv::imshow("dst", dstMat);
	cv::waitKey(0);
}