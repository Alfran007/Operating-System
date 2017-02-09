First I installed PintOS using command sudo apt-get install pintos
then qemu using sudo apt-get install qemu
then tcsh using sudo apt-get install tcsh

Now,I changed the files of root :
1) .tcshrc and did:

![tcshrc](/uploads/fa6a6e09938a70a2ec0eda252603d79b/tcshrc.png)


2) .bashrc

![bashrc](/uploads/94242662b515520dcced35bdcd79f6f3/bashrc.png)

Then i chanded the following files :
1) pintos in lab5/pintos/src/utils folder :
Added the new path:


![kernel](/uploads/13859e4bb46a12fa7939fb0aca14d8cc/kernel.png)


Changed the bosch to qemu:


![qemu](/uploads/ea6e96cd5a9a1b8d68f1abdd91864aa4/qemu.png)


Chanded the name of qemu-system-x86_64


![cmd](/uploads/fbb5af73a36769f27d3cba5e2c513fd8/cmd.png)


2) pintos.pm in the same directory:
Changed the path of loader: 


![loader](/uploads/ff96aba935ab56ba048bb8a62edfc9c7/loader.png)


3) pintos.gdb in same folder
Changed the bath pf macros:


![gdb](/uploads/13bc4e90285c73c9fd03a5d4402de0ab/gdb.png)


4) Makefile in same folder:


![ldlibs](/uploads/517b5e91093d44f11019c9e22266a076/ldlibs.png)

After make and running pintos -- run alarm-multiple in tcshrc i got:

![alarm_multiple](/uploads/fa62dd1fd5ea59b5281f805f372ed2d8/alarm_multiple.png)

*****************************************Part 1 begins*********************************
Adding my own file:
I chnged my directory to lab5/pintos/src/tests/threads
and made a file : print_something.c that prints something.

Changes made in files:

1) tests.c as :
In the structure the first parameter is name of function that i will call while running the command and the second parameter is the name of function that i defined.

![tests](/uploads/5da933d667f335e9a75f4659135668c4/tests.png)

2) tests.h as :
it takes the function declarations and extern it .

![tests_h](/uploads/96a6641c277ab0a45f80c8fa9a3710e1/tests_h.png)

3) make.tests as :
It contains the file location

![make_tests](/uploads/216623bf5070da27fb8a4202d8382576/make_tests.png)

Code:-

![print](/uploads/0acd3bcd139d1a8ab1e27d240ce5a381/print.png)

Output :-

![op](/uploads/89117aa49e9f030aa3ce0acf728d5450/op.png)

This above file is print_something.c which is in threads folder inside tests directory.

*******************Part2 begins**************************
Similarly i did the same procedue of random_sort.c
function should be called as "random_sort" in pintos

File : I used the random_bytes() function and include random.h file

![func_rand_sort](/uploads/fdffa1cdccd6128a01dcf5e1ebb36bc2/func_rand_sort.png)

O/p:

![random_sort](/uploads/3918ee38d6b3c2fe5f4f57684a8abe88/random_sort.png)

Extra Part:
Then I did random sort using API in a file random_sort_api.c in the same directory.
function should be called as "random_sort_api" in pintos

File:

![api](/uploads/a9d0f6d781bf14d089f58589a2f2a3e3/api.png)


O/P:

![api_op](/uploads/2f54238fb49a34e2f3697c11cca77e7f/api_op.png)

**************************Threads*********************************

I have created a file threads_creation in the same directory.
function should be called as "thread" in pintos

File:


![threads](/uploads/ad7123340054060f293f03136b563a97/threads.png)


O/P:

![thread_output](/uploads/da0553dcaaf37d1790b079612d2712b9/thread_output.png)




