#include <xinu.h>
syscall cond_wait(volatile cond_t* cv, volatile mutex_t* lock)
{
	if(lock == NULL || cv == NULL)
	{
		printf("Null pointer values");
		return SYSERR;
	}

	mutex_unlock(lock);
	while(previous)
	{
		intmask mask;
		mask = disable();
		mutex_t = previous;
		previous = *cv;
		*cv = 1;
		restore(mask);
	}

	mutex_lock(lock); //Reinitialising the whole thing
	return OK;
}
