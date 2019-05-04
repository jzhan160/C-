// DesignPrinciple.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
//Dependency Inversion Principle
struct IWorker {
public :
	virtual void work() = 0;
	virtual ~IWorker() {}
};
class generalWorker : public IWorker {
public:
	virtual void work() {
		std::cout << "do general work.\n";
	}
	virtual ~generalWorker() {}
};
class superWorker : public IWorker {
public:
	virtual void work() {
		std::cout << "do super work.\n";
	}
	virtual ~superWorker() {}
};
struct WorkerFactory{
	static IWorker* createWorker(int num) {
		if (num == 1)
			return new generalWorker();
		else return new superWorker();
	}
};
class Manager {
public:
	void callWorker(IWorker *w) {
		worker = w;
	}
	void doWork() {
		worker->work();
	}
private:
	IWorker* worker;
};
void testDIP() {
	IWorker* gWorker = WorkerFactory::createWorker(1);
	IWorker* sWorker = WorkerFactory::createWorker(2);
	Manager manager;
	manager.callWorker(gWorker);
	manager.doWork();
	manager.callWorker(sWorker);
	manager.doWork();
}
//Open and closed Principle
class Shape {
public:
	virtual void draw() {
		std::cout << "draw the shape. \n";
	}
};
class circle :public Shape {
	virtual void draw() {
		std::cout << "draw the circle. \n";
	}
};
class square :public Shape {
	virtual void draw() {
		std::cout << "draw the square. \n";
	}
};
class DrawShape {
public:
	void draw(Shape* s) {
		s->draw();
	}
};
void testOCP() {
	DrawShape da;
	da.draw(new circle());
	da.draw(new square());

}
//Liskov's Substitution Principle
class Rectangle {
public:
	virtual void setHight(int height) {
		height_ = height;
	}
	virtual void setWidth(int width) {
		width_ = width;
	}
	virtual int getArea() {
		return height_ * width_;
	}

protected:
	int height_;
	int width_;
};
class Square :  public Rectangle {
public:
	virtual void setHight(int side) {
		height_ = side;
	}
	virtual void setWidth(int side) {
		width_ = side;
	}

};
void testLSP() {
	Rectangle* square1 = new Square();
	square1->setHight(2);
	square1->setWidth(2);
	std::cout << square1->getArea() << "\n";
}
//Interface Segregation Principle
struct IFeedWorker {
public:
	virtual void eat() = 0;
	virtual ~IFeedWorker() {}
};
struct IWorkWorker {
public:

	virtual void work() = 0;
	virtual ~IWorkWorker() {}
};
class BothWorker : IWorker, IFeedWorker {
public:
	virtual void eat() {
		std::cout << "Both eating \n";
	}
	virtual void work() {
		std::cout << "And working \n";
	}
	void start() {
		std::cout << " BothWorker : \n";
		eat();
		work();
	}
};
class FeedWorker : IFeedWorker {
public:
	virtual void eat() {
		std::cout << "only eating \n";
	}
	void start() {
		std::cout << " FeedWorker : \n";

		eat();
	}
};
void testISP() {
	BothWorker bw;
	bw.start();
	FeedWorker fw;
	fw.start();
}
int main()
{   
	testDIP();
	testOCP();
	testLSP();
	testISP();
    return 0;
}

