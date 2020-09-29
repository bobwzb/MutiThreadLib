// MutiThreadLib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
void set(int a[], int s, int e,int val) {
	for (int i = s; i < e; i++) {
		a[i] = val;
	}
}
int main()
{
	int a[26] = { 0 };
	thread t1(set,ref(a), 0, 12, 1);
	thread t2(set,ref(a), 13, 26, 2);
	t1.join();
	t2.join();
	for (int i = 0; i < 26; i++) {
		cout << a[i];
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
