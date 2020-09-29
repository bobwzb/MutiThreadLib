// MutiThreadLib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <mutex>
#include <thread>
#include <string>
using namespace std;

/*const int cnt = 5;
int flag = 10;
mutex mt;

void func(const int num, const string& str) {
	for (int i = 0; i < cnt; ++i) {
		while (num != flag) {
			this_thread::yield();
		}
		lock_guard<mutex> lg(mt);
		for (int j = 0; j < num; j++) {
			cout << str << endl;
		}
		this_thread::sleep_for(chrono::seconds(1));
		flag = (flag == 10 ? 100 : 10);
	}
}
int main()
{
	auto start = chrono::high_resolution_clock::now();
	thread child(func, 10, "child");
	func(100, "father");
	child.join();
	auto end = chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsed = end - start;
	cout << elapsed.count() << endl;
	return 0;

}*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
