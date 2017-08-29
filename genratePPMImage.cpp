#include<opencv2/opencv.hpp>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>

using namespace cv;
using namespace std;
int main(int argc,char **argv)
{

	if(argc != 3){
		cout << "USAGE :: EXE INPUT_IMAGE OUTPUT_IMAGE(sample.ppm)" << endl;
		return 0;
	
	}
	Mat image;

	image=imread(argv[1],1);
	int rows=image.rows;
	int cols=image.cols;
	int size = rows * cols;

	vector<Mat> rgb_color;
	split(image,rgb_color);

	uchar *b=rgb_color[0].data;
	uchar *g=rgb_color[1].data;
	uchar *r=rgb_color[2].data;

       	
	ofstream file(argv[2]);

	file << "P3" << endl;
	file << image.size().width << " " << image.size().height << endl;
	file << "255" << endl;
	int count = 0;
	for(int i = 0; i < (size); i++){
	
			if( (count % cols) != 0){
				file <<(int) *r++ << " " <<(int) *g++ << " " <<(int) *b++ << " ";
			}else{
				file << endl;
			}
			
			count++;
	}
			
	file << endl;
	file.close();
}



