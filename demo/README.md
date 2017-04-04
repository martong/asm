https://gist.github.com/FiloSottile/7125822
http://asm.sourceforge.net/intro/hello.html (See section of FreeBSD for normal UNIX syscall convention)

x86_64:
by the way: "Mac OS X or likely BSD has split up the system call numbers into several different “classes.” The upper order bits of the syscall number represent the class of the system call, in the case of write and exit, it’s SYSCALL_CLASS_UNIX and hence the upper order bits are 2! Thus, every Unix system call will be (0×2000000 + unix syscall #)."
https://filippo.io/making-system-calls-from-assembly-in-mac-os-x/
