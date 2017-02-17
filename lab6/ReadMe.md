In the tests/threads folder I creater a file lock.c

I first used:

void lock_init(struct lock * lock)
Initializes lock as a new lock. The lock is not initially owned by any thread.

then:
void lock_acquire (struct lock * lock)
It acquires lock for the current thread, first waiting for any current owner to release it.

Then i created my new thread using the old procedure of thread_create and exit it , the thread simply sort the random numbers using list api.

After this chils thread execution,

I released the parent lock by function
lock_release(struct lock * lock);

then finally i used,
thread_yield()
which immediately restores the interrupt level i.e. parent thread start executing again.

![locker](/uploads/3c063782bd0e682a44782f7abccb6b51/locker.png)

**********Part-2 begins***************

