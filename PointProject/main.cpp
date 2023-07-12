#include <iostream>
#include"Test_Project.h"

int main()
{
	Test test;
	if (test.Test_Project() != 1) return 0;
	else {
		cout << "PROGRAM TERMINATED !";
	}
	return 1;
}
