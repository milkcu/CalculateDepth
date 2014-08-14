#include <iostream>
#include <cmath>
class Vec;
class Vec {
public:
	float x, y, z;
	Vec() {
		x = 0.0;
		y = 0.0;
		z = 0.0;
	}
	Vec(float x_, float y_, float z_) {
		x = x_;
		y = y_;
		z = z_;
	}
	Vec operator+(Vec b)
	{
		Vec a = *this;
		return Vec(a.x + b.x, a.y + b.y, a.z + b.z);
	}
	Vec operator-(Vec b)
	{
		Vec a = *this;
		return Vec(a.x - b.x, a.y - b.y, a.z - b.z);
	}
	float operator*(Vec b)
	{
		//Dot Product
		Vec a = *this;
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}
	Vec operator^(Vec b)
	{
		//Cross Product
		Vec a = *this;
		return Vec(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
	}
};
float calcDepth(Vec vG, Vec vE, Vec vA, Vec vB, Vec vC);
int main(void)
{
	Vec vG(0, 40, 30);
	Vec vE(0, 0, 0);
	Vec vA(0, 20, 10);
	Vec vB(0, 20, 0);
	Vec vC(10, 20, 0);
	float depth = calcDepth(vG, vE, vA, vB, vC);
	std::cout << depth << std::endl;
	return 0;
}
float calcDepth(Vec vG, Vec vE, Vec vA, Vec vB, Vec vC)
{
	//G为给定点
	//E为相机位置
	//ABC为近界面的任意三点
	//计算出的depth为从摄像机发射出的射线与场景的交点的z坐标（未归一化为0到1之间的值）
	float depth;
	Vec vAB = vB - vA;
	Vec vAC = vC - vA;
	Vec vEG = vG - vE;
	depth = (vAB ^ vAC) * vEG;
	if(depth < 0) {
		depth = std::sqrt(-depth);
	} else {
		depth = std::sqrt(depth);
	}
	return depth;
}
