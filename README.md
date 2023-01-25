# get-next-line
This project is about programming a function that returns a line read from a file descriptor

## open() function in c

int open(const char *pathname, int flags);
The open() system call opens the file specified by pathname.  If the specified file does not exist, it may optionally (if O_CREAT is specified in flags) be created by open().

[List pf flags](https://man7.org/linux/man-pages/man2/open.2.html)

On success, open(), openat(), and creat() return the new file descriptor (a nonnegative integer).  On error, -1 is returned and errno is set to indicate the error.

read function

static variable

global variable

## Buffer 
is a generic term that refers to a block of memory that serves as a temporary placeholder. In computer programming, data can be placed in a software buffer before it is processed. Because writing data to a buffer is much faster than a direct operation, using a buffer while programming in C and C++ makes a lot of sense and speeds up the calculation process. Buffers come in handy when a difference exists between the rate data is received and the rate it is processed. 

## Buffer vs. Cache

A buffer is temporary storage of data that is on its way to other media or storage of data that can be modified non-sequentially before it is read sequentially. It attempts to reduce the difference between input speed and output speed. A cache also acts as a buffer, but it stores data that is expected to be read several times to reduce the need to access slower storage. 

