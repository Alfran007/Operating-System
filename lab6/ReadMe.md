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
_Graph 1 : BTW TIME SLICE AND NO. Of ITERATIONS IN FIXED THREADS_

 Once the thread is executing but the amount of time given by CPU (time_slice) is less ,then the thread will go back in the queue as in Round Robin
 and when it executes again in the next round we count it as the second iteration.
 
 ![Time_Slice_Vs_No._Of_Iterations_for_fixed_Threads_-_-_Graph](/uploads/916b25d191060fa56f40c5e7fc3c5c18/Time_Slice_Vs_No._Of_Iterations_for_fixed_Threads_-_-_Graph.png)
 Above graph is for 3 Threads.
 
 I counted the numbers of iterations for each time slice by keeping the number of threads fixed.
 
 _Graph 2 : BTW TIME SLICE AND NO. OF THREADS IN FIXED ITERATIONS_
 
 We have to find out that in one CPU time quanta how many threads have been executed, 
 i.e. if the time required to execute a thread is less than the TIME_SLICE then multiple 
 threads can be executed in that specific  `fixed iteration`.
 
 First I counted the number of threads in 3 iterations.
 
 ![Time_Slice_Vs_Number_Of_Threads_When_Iterations_are_Fixed_-_Graph](/uploads/06c62f143e80529c0fc216ff83bc2384/Time_Slice_Vs_Number_Of_Threads_When_Iterations_are_Fixed_-_Graph.png)
 
 I counted the number of kernel ticks changed and accordingly counted the number of threads executing with change in it. I printed the `thread_print_stats()` for that.
 Like when `TIME SLICE ` is 5
 
 ![time5](/uploads/2daab31242168672d3f623ac1ca63742/time5.png)
 
 When it is 6 it is:
 
 ![time6](/uploads/21653070ad6b0c496b3189598e1b90ec/time6.png)
 
 When it is 1 it is :
 
 ![time_1](/uploads/659c03bdaa4d0b0696f5c52ca82c1fc2/time_1.png)
 
 When it is 3 it is:
 
 ![time_3](/uploads/49380931e44ef0c6efd26c8acbab6a9e/time_3.png)
 
 With Each of these I observed the threads going back to queue in Round Robin and after waiting executing in another Time Slice.
 
 
 
 Extra Graph and observation. When i changed the number of iterations and observed the graph it looke like below:
 
 ![Time_Slice_Vs_Number_Of_Threads_When_Iterations_are_Fixed](/uploads/bbb5491b1a71cd588bbfbc5cd13c6f6e/Time_Slice_Vs_Number_Of_Threads_When_Iterations_are_Fixed.png)
 
 
 
 
 
 
 
 