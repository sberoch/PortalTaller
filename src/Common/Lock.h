#ifndef LOCK
#define LOCK

#include <mutex>

class Lock {
private:
	std::mutex &m;

public:
	//Crea el Lock, tomando el mutex
	explicit Lock(std::mutex &m);
	
	//Libera el mutex
	~Lock();

	Lock(const Lock&) = delete;
	Lock& operator=(const Lock&) = delete;
	Lock(Lock&&) = delete;
	Lock& operator=(Lock&&) = delete;
};

#endif
