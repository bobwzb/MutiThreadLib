#include <exception>
#include <memory>
#include <mutex>
#include <stack>
using namespace std;

struct empty_stack: exception
{
	const char* what() const throw();
};

template<typename T>
class threadsafe_stack {
	stack<T> data;
	mutable mutex m;
public:
	threadsafe_stack(){}
	threadsafe_stack(const threadsafe_stack& other) {
		lock_guard<mutex> lock(other.m);
		data = other.data;
	}
	threadsafe_stack& operator=(const threadsafe_stack&) = delete;

	void push(T val) {
		lock_guard<mutex> lock(m);
		data.push(val);
	}

	shared_ptr<T> pop() {
		lock_guard<mutex> lock(m);
		if (data.empty()) throw empty_stack();
		shared_ptr<T> res(make_shared<T>(data.top()));
		data.pop();
		return res;
	}

	void pop(T& val) {
		lock_guard<mutex> lock(m);
		if (data.empty()) throw empty_stack();
		val = data.top();
		data.pop();
	}
	bool empty() const {
		lock_guard<mutex> lock(m);
		return data.empty();
	}
};
