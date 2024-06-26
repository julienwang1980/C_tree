//*************************************************************************
//*************************************************************************
/**
 * \file		
 *
 * \brief		
 *
 * \copyright	
 *
 * \author		Julien Wang
*/
//*************************************************************************
//*************************************************************************
#include "timer.h"
#include <time.h>
#include <errno.h>

//-------------------------------------------------------------------------
/**
 * \fn msleep();
 *
 * \brief Sleep for the requested number of milliseconds.
 *
 * \param msec the number of milliseconds to sleep
 *
 * \return the result of sleep
 */
//-------------------------------------------------------------------------
int msleep(long msec)
{
    struct timespec ts;
    int res;

    if (msec < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}

