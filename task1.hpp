#ifndef TTASK1_HPP
#define TTASK1_HPP

#include "thread.hpp"
#include "screen.hpp"

class TTask1 : public TThread
    {
    private:
		TScreen *screen;
    public:
	TTask1(const char *name,void *shared,int policy,int priority);
	~TTask1();

	void task(void);
    };

#endif //TTASK1_HPP
