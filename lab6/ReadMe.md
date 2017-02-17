In the _tests/threads_ folder I creater a file `lock.c`

I first used:

`void lock_init(struct lock * lock)`
Initializes lock as a new lock. The lock is not initially owned by any thread.

then:
`void lock_acquire (struct lock * lock)`
It acquires lock for the current thread, first waiting for any current owner to release it.

Then i created my new thread using the old procedure of `thread_create` and exit it , the thread simply sort the random numbers using list api.

After this child thread execution,

I released the parent lock by function
`lock_release(struct lock * lock)`

then finally i used,
`thread_yield()`
which immediately restores the interrupt level i.e. parent thread start executing again.

![locker](/uploads/3c063782bd0e682a44782f7abccb6b51/locker.png)

**********Part-2 begins***************

For _part-2_ I made a new file named `RR_to_FCFS.c`

In this file i created 3 threads as mentioned in question ,
but the order of printing the threads was coming correct because the time for executing a thread is very less then the time given by CPU in `Round Robin` to execute,
so it seems like that it's occuring in `FCFS` Order,

But When I did looping in one of the thread (say Thread 2) to extend the _time stamp_ of execution of thread then the order of printing of these 3 threads was wrong because,
when thread 2 was executing the _time quantum_ given by CPU finishes first and hence the left proocess(execution of thread) was sent back in the queue as in `Round Robin`.
![time_slice_before](/uploads/e71479246942d658edf5bafbee883ac3/time_slice_before.png)
![no_timeslice_changes](/uploads/ca2b3b581cd7e9dcfbdc2c4cdd5bfb2e/no_timeslice_changes.png)

Then to convert this `Round Robin` to `FCFS` I changed the TIME_SLICE value from 4 to 50 in _src/threads_ , which is the given time by the CPU in `Round Robin` Process. Hence,
After these changes the order of threads execution again becomes correct i.e. `Round Robin` is changed to `FCFS`.
![after_time_slice](/uploads/7be2dd5c6e4982788e4f183f96cc9042/after_time_slice.png)


********Graph*******
