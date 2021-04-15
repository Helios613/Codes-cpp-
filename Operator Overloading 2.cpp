#include<iostream>
using namespace std;

class Box{
	double length;
	double breadth;
	double height;
	
	public:
		double getVolume(void){
			return length*breadth*height;
		}
		
		void set(double len, double bre, double hei){
			length = len;
			breadth = bre;
			height = hei;
		}
		
		Box operator+(const Box& b){
			Box box;
			box.length = this->length + b.length;
			box.breadth = this->breadth + b.breadth;
			box.height = this->height + b.height;
			return box;
		}
};
int main(){
	Box b1, b2, b3;
	b1.set(6.0, 7.0, 5.0);
	b2.set(12.0, 10.0, 10.0);
	
	b3 = b1 + b2;
	
	cout<<"Volume of box3:"<<b3.getVolume()<<endl;
	return 0;
}
