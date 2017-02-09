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

![tests](/uploads/5da933d667f335e9a75f4659135668c4/tests.png)

2) tests.h as :

![tests_h](/uploads/96a6641c277ab0a45f80c8fa9a3710e1/tests_h.png)

3) make.tests as :

![make_tests](/uploads/216623bf5070da27fb8a4202d8382576/make_tests.png)


