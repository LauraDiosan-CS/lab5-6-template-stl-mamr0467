#pragma once
#include "Service.h"
using namespace std;

class TestService {
private:
	Service s;
	void test1();
public:
	TestService();
	void runTests();
	~TestService();
};