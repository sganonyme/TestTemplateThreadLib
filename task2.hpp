#ifndef TTASK2_HPP
#define TTASK2_HPP

#include "thread.hpp"
#include "screen.hpp"


class TTask2 : public TThread
    {
    private:
		TScreen *screen;
    public:
	TTask2(const char *name,void *shared,int policy,int priority);
	~TTask2();

	void task(void);
    };

#endif //TTASK1_HPP
