#include <exception>
#include <memory>
#include <mutex>
#include <stack>
#include <shared_mutex>
using namespace std;
class ThreadSafeCounter {
public:
	ThreadSafeCounter() = default;

	// muti read
	unsigned int get() const {
		std::shared_lock<std::shared_mutex> lock(mutex_);
		return value_;
	}

	// unique one to write and modify
	void increment() {
		std::unique_lock<std::shared_mutex> lock(mutex_);
		value_++;
	}

	void reset() {
		std::unique_lock<std::shared_mutex> lock(mutex_);
		value_ = 0;
	}

private:
	mutable std::shared_mutex mutex_;
	unsigned int value_ = 0;
};