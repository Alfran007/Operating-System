I started by adding some packages for building the Linux kernel:

sudo apt-get install git fakeroot build-essential ncurses-dev xz-utils libssl-dev bc

Then i downloaded and extracted the .tar file of the kernel in src directory :

sudo tar -xvf linux-4.9.8.tar.xz -C/usr/src/

Then i changed the directory to :

cd /usr/src/linux-4.9.8/

then i made a new directory named hello and two files hello.c and Makefile inside this directory.

![Screenshot_from_2017-02-05_15-39-49](/uploads/7e337f2ad1a3ebe3e37a806d91ed3f06/Screenshot_from_2017-02-05_15-39-49.png)

In the hello.c file i wrote a function which would be my system_call , it simply prints something on my kernel using function printk of library <linux/kernel.h> 
i.e. it is declared in a file kernel.h which is inside linux folder.

![Screenshot_from_2017-02-07_01-26-23](/uploads/84e3d25ded11042da0ba823a0abaa564/Screenshot_from_2017-02-07_01-26-23.png)

In the above pic, the function is  asmlinkage long sys_hello(void) which will act as a system_call

![Screenshot_from_2017-02-07_01-26-33](/uploads/55feb824b353bb595dfa36b5770867ec/Screenshot_from_2017-02-07_01-26-33.png)

In the pic, Makefile is creating an object file which is a compliled file and y is the variable that system follows.

Now in linux-4.9.8 folder i edit the Makefile to add the hello directory to the kernel’s Makefile

 "core-y +=  kernel/ mm/ fs/ ipc/ security/ crypto/ block/ hello"
 
Now, in the cd arch/x86/entry/syscalls folder i edited two files syscall_64.tbl and syscall_32.tbl(to Avoid Warnings)
Reason : In this file i edited the system_call so that the kernel knows about the system call and what function to call 
when the name of function is typed while calling the system call.

![Screenshot_from_2017-02-07_01-39-33](/uploads/54d551f9c57558f9c04e2a9631d66117/Screenshot_from_2017-02-07_01-39-33.png)

Here 332 is the system call number and hello is the file name (hello.c) and the sys_hello is the function which is defined in it.

Now in cd  include/linux/ of linux-4.9.8 folder i edited syscalls.h file

and added the prototype asmlinkage long sys_hello(void); in the end
![Screenshot_from_2017-02-05_15-41-25](/uploads/793b76a8082824223ee0512c8c2dbc23/Screenshot_from_2017-02-05_15-41-25.png)

Other Changes to remove warnings:
I edited the .config file so that the certificates should not be needed to any other and the kernel version i build is a new one.
(This changes removed all Warnings)
![Screenshot_from_2017-02-05_15-44-03](/uploads/bc42240c394cf0e693e7bba08f149380/Screenshot_from_2017-02-05_15-44-03.png)

Then i make it's configuration using :

sudo make menuconfig 

Then i changed directory to cd /usr/src/linux-4.9.8/ and compiled the kernel using:

make -j 8 (8 due to multiple cores(8 in my system) so that more threads can process in parallel and improve speed)

Then i did:
make  modules_install

Then :
make  install
This step copy the the kenel from arch/x86/boot/bzImage to /boot folder and copy the .config file to /boot/config-4.9.8 and generate the System.map file
Which then update old kernel after booting up. 

Below step helps in sustaining the old version of kernel in advanced option in case to downgrade

Advanced Step:
update-initramfs -c -k 3.3.3
Reason : up to now kernel and its modules are compiled and installed. when next boot up time we need to choose latest kernel.
so we need to prepare the boot-loader and its support files.
When system turns on, after bios and boot loader load the kernel to main memory and mount initial dummy file system as a root file system of system.
this initial file system have necessary drivers for disk hardware (SCSI or IDE) and mount the correct file system as a root file system.

so we need to create initramfs file using update-initramfs or mkinitfs tool

The last step is update the boot loader here i m using GRUB boot-loader.
update-grub 
this command automatically probe the kernels in /boot folder and add the entries in its configuration file, grub.cfg

Now reboot the systm using:
sudo reboot

After rebooting verify the kernel version using the following command;

uname -r

test the system call.

i created a "userspace.c" in home folder 

![Screenshot_from_2017-02-07_02-01-37](/uploads/40f9a182b6978d9f765c15a29957c111/Screenshot_from_2017-02-07_02-01-37.png)

Ater running it gives output:

![Screenshot_from_2017-02-07_02-07-24](/uploads/3762035e20f6d468d4fb60b3eee45920/Screenshot_from_2017-02-07_02-07-24.png)

Now to check the message of the kernel i run the following command.

dmesg

This displays "***********Welcome to Alfran's World************" at the end of the kernel’s message.



![Screenshot_from_2017-02-07_02-06-06](/uploads/d7ee6ed7851a5b315c259c816076b66d/Screenshot_from_2017-02-07_02-06-06.png)


