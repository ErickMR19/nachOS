# NOTE: this is a GNU Makefile.  You must use "gmake" rather than "make".
#
# Makefile for the multiprogramming assignment
#    Defines set up assuming multiprogramming is done before the file system.
#    If not, use the "filesys first"  defines below. 
#
#
# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

DEFINES = -DUSER_PROGRAM -DFILESYS_NEEDED -DFILESYS_STUB
INCPATH = -I../bin -I../filesys -I../userprog -I../threads -I../machine
HFILES = $(THREAD_H) $(USERPROG_H)
CFILES = $(THREAD_C) $(USERPROG_C)
C_OFILES = $(THREAD_O) $(USERPROG_O)

# if file sys done first!
# DEFINES = -DUSER_PROGRAM -DFILESYS_NEEDED -DFILESYS
# INCPATH = -I../bin -I../filesys -I../userprog -I../threads -I../machine
# HFILES = $(THREAD_H) $(USERPROG_H) $(FILESYS_H)
# CFILES = $(THREAD_C) $(USERPROG_C) $(FILESYS_C)
# C_OFILES = $(THREAD_O) $(USERPROG_O) $(FILESYS_O)

include ../Makefile.common
include ../Makefile.dep
#-----------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
main.o: ../threads/main.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/system.h ../threads/thread.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../threads/../userprog/tablasemaforos.h \
 ../threads/synch.h ../threads/../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/../userprog/tablaindicadores.h ../threads/thread.h \
 ../threads/../userprog/tablaarchivos.h
scheduler.o: ../threads/scheduler.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/scheduler.h ../threads/list.h \
 ../threads/utility.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdlib.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/system.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h \
 ../threads/../userprog/tablasemaforos.h ../threads/synch.h \
 ../threads/../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/../userprog/tablaindicadores.h ../threads/thread.h \
 ../threads/../userprog/tablaarchivos.h
synch.o: ../threads/synch.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/synch.h ../threads/thread.h \
 ../threads/utility.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdlib.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/list.h \
 ../threads/system.h ../threads/scheduler.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/../userprog/tablasemaforos.h ../threads/synch.h \
 ../threads/../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/../userprog/tablaindicadores.h ../threads/thread.h \
 ../threads/../userprog/tablaarchivos.h
system.o: ../threads/system.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/utility.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/../userprog/tablasemaforos.h ../threads/synch.h \
 ../threads/../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/../userprog/tablaindicadores.h ../threads/thread.h \
 ../threads/../userprog/tablaarchivos.h ../threads/preemptive.h
thread.o: ../threads/thread.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/thread.h ../threads/utility.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/switch.h \
 ../threads/synch.h ../threads/list.h ../threads/system.h \
 ../threads/scheduler.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h \
 ../threads/../userprog/tablasemaforos.h ../threads/synch.h \
 ../threads/../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/../userprog/tablaindicadores.h ../threads/thread.h \
 ../threads/../userprog/tablaarchivos.h
utility.o: ../threads/utility.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h
threadtest.o: ../threads/threadtest.cc /usr/include/stdc-predef.h \
 /usr/include/unistd.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h /usr/include/bits/posix_opt.h \
 /usr/include/bits/environments.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/confname.h /usr/include/getopt.h \
 ../threads/copyright.h ../threads/system.h ../threads/utility.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdlib.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/../userprog/tablasemaforos.h ../threads/synch.h \
 ../threads/../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/../userprog/tablaindicadores.h ../threads/thread.h \
 ../threads/../userprog/tablaarchivos.h ../threads/dinningph.h \
 ../threads/synch.h
dinningph.o: ../threads/dinningph.cc /usr/include/stdc-predef.h \
 ../threads/dinningph.h ../threads/synch.h ../threads/copyright.h \
 ../threads/thread.h ../threads/utility.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/list.h
interrupt.o: ../machine/interrupt.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/interrupt.h ../threads/list.h \
 ../threads/copyright.h ../threads/utility.h ../machine/sysdep.h \
 /usr/include/stdlib.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/system.h ../threads/thread.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../threads/../userprog/tablasemaforos.h ../threads/synch.h \
 ../threads/../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/../userprog/tablaindicadores.h ../threads/thread.h \
 ../threads/../userprog/tablaarchivos.h
sysdep.o: ../machine/sysdep.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/xlocale.h /usr/include/signal.h \
 /usr/include/bits/sigset.h /usr/include/bits/signum.h \
 /usr/include/time.h /usr/include/bits/siginfo.h \
 /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h \
 /usr/include/bits/sigstack.h /usr/include/sys/ucontext.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sigthread.h \
 /usr/include/sys/types.h /usr/include/endian.h \
 /usr/include/bits/endian.h /usr/include/bits/byteswap.h \
 /usr/include/bits/byteswap-16.h /usr/include/sys/select.h \
 /usr/include/bits/select.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/sys/socket.h \
 /usr/include/sys/uio.h /usr/include/bits/uio.h \
 /usr/include/bits/socket.h /usr/include/bits/socket_type.h \
 /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/asm/sockios.h \
 /usr/include/asm-generic/sockios.h /usr/include/sys/file.h \
 /usr/include/fcntl.h /usr/include/bits/fcntl.h \
 /usr/include/bits/fcntl-linux.h /usr/include/bits/stat.h \
 /usr/include/sys/un.h /usr/include/sys/mman.h /usr/include/bits/mman.h \
 /usr/include/bits/mman-linux.h /usr/include/sys/syscall.h \
 /usr/include/asm/unistd.h /usr/include/asm/unistd_64.h \
 /usr/include/bits/syscall.h /usr/include/unistd.h \
 /usr/include/bits/posix_opt.h /usr/include/bits/environments.h \
 /usr/include/bits/confname.h /usr/include/getopt.h /usr/include/stdlib.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 ../machine/interrupt.h ../threads/list.h ../threads/copyright.h \
 ../threads/utility.h ../machine/sysdep.h ../threads/system.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../machine/stats.h \
 ../machine/timer.h ../threads/../userprog/tablasemaforos.h \
 ../threads/synch.h ../threads/../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/../userprog/tablaindicadores.h ../threads/thread.h \
 ../threads/../userprog/tablaarchivos.h
stats.o: ../machine/stats.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../threads/copyright.h \
 ../machine/sysdep.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../machine/stats.h
timer.o: ../machine/timer.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/timer.h ../threads/utility.h \
 ../threads/copyright.h ../machine/sysdep.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/system.h ../threads/utility.h \
 ../threads/thread.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../threads/../userprog/tablasemaforos.h \
 ../threads/synch.h ../threads/../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/../userprog/tablaindicadores.h ../threads/thread.h \
 ../threads/../userprog/tablaarchivos.h
preemptive.o: ../threads/preemptive.cc /usr/include/stdc-predef.h \
 ../threads/preemptive.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdlib.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/../userprog/tablasemaforos.h ../threads/synch.h \
 ../threads/../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/../userprog/tablaindicadores.h ../threads/thread.h \
 ../threads/../userprog/tablaarchivos.h /usr/include/unistd.h \
 /usr/include/bits/posix_opt.h /usr/include/bits/environments.h \
 /usr/include/bits/confname.h /usr/include/getopt.h \
 /usr/include/sys/ptrace.h /usr/include/sys/wait.h /usr/include/signal.h \
 /usr/include/bits/signum.h /usr/include/bits/siginfo.h \
 /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h \
 /usr/include/bits/sigstack.h /usr/include/sys/ucontext.h \
 /usr/include/bits/sigthread.h /usr/include/sys/user.h
addrspace.o: ../userprog/addrspace.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../machine/sysdep.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/../userprog/tablasemaforos.h ../threads/synch.h \
 ../threads/../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/../userprog/tablaindicadores.h ../threads/thread.h \
 ../threads/../userprog/tablaarchivos.h ../userprog/addrspace.h \
 ../bin/noff.h
bitmap.o: ../userprog/bitmap.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../userprog/bitmap.h ../threads/utility.h \
 ../threads/copyright.h ../machine/sysdep.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../filesys/openfile.h
exception.o: ../userprog/exception.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../machine/sysdep.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/../userprog/tablasemaforos.h ../threads/synch.h \
 ../threads/../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/../userprog/tablaindicadores.h ../threads/thread.h \
 ../threads/../userprog/tablaarchivos.h ../userprog/syscall.h \
 /usr/include/sys/stat.h /usr/include/bits/stat.h /usr/include/fcntl.h \
 /usr/include/bits/fcntl.h /usr/include/bits/fcntl-linux.h \
 /usr/include/bits/uio.h /usr/include/unistd.h \
 /usr/include/bits/posix_opt.h /usr/include/bits/environments.h \
 /usr/include/bits/confname.h /usr/include/getopt.h \
 ../userprog/tablaindicadores.h ../userprog/../threads/synch.h \
 ../userprog/../machine/machine.h ../userprog/../threads/utility.h \
 /usr/include/errno.h /usr/include/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h
progtest.o: ../userprog/progtest.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../machine/sysdep.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/../userprog/tablasemaforos.h ../threads/synch.h \
 ../threads/../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/../userprog/tablaindicadores.h ../threads/thread.h \
 ../threads/../userprog/tablaarchivos.h ../machine/console.h \
 ../userprog/addrspace.h
console.o: ../machine/console.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/console.h ../threads/utility.h \
 ../threads/copyright.h ../machine/sysdep.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../threads/system.h ../threads/utility.h \
 ../threads/thread.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../threads/../userprog/tablasemaforos.h \
 ../threads/synch.h ../threads/../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/../userprog/tablaindicadores.h ../threads/thread.h \
 ../threads/../userprog/tablaarchivos.h
machine.o: ../machine/machine.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
 ../threads/copyright.h ../machine/sysdep.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../machine/translate.h ../machine/disk.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../machine/machine.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../threads/../userprog/tablasemaforos.h \
 ../threads/synch.h ../threads/../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/../userprog/tablaindicadores.h ../threads/thread.h \
 ../threads/../userprog/tablaarchivos.h
mipssim.o: ../machine/mipssim.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
 ../threads/copyright.h ../machine/sysdep.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../machine/translate.h ../machine/disk.h \
 ../machine/mipssim.h ../threads/system.h ../threads/utility.h \
 ../threads/thread.h ../machine/machine.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h \
 ../threads/../userprog/tablasemaforos.h ../threads/synch.h \
 ../threads/../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/../userprog/tablaindicadores.h ../threads/thread.h \
 ../threads/../userprog/tablaarchivos.h
translate.o: ../machine/translate.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
 ../threads/copyright.h ../machine/sysdep.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../machine/machine.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../threads/../userprog/tablasemaforos.h \
 ../threads/synch.h ../threads/../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/../userprog/tablaindicadores.h ../threads/thread.h \
 ../threads/../userprog/tablaarchivos.h
tablasemaforos.o: ../userprog/tablasemaforos.cc \
 /usr/include/stdc-predef.h ../userprog/tablasemaforos.h \
 ../threads/synch.h ../threads/copyright.h ../threads/thread.h \
 ../threads/utility.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdlib.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/list.h \
 ../userprog/bitmap.h ../filesys/openfile.h \
 /usr/include/c++/4.8.3/iostream \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/c++config.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/os_defines.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/cpu_defines.h \
 /usr/include/c++/4.8.3/ostream /usr/include/c++/4.8.3/ios \
 /usr/include/c++/4.8.3/iosfwd /usr/include/c++/4.8.3/bits/stringfwd.h \
 /usr/include/c++/4.8.3/bits/memoryfwd.h \
 /usr/include/c++/4.8.3/bits/postypes.h /usr/include/c++/4.8.3/cwchar \
 /usr/include/bits/wchar.h /usr/include/c++/4.8.3/exception \
 /usr/include/c++/4.8.3/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.3/bits/char_traits.h \
 /usr/include/c++/4.8.3/bits/stl_algobase.h \
 /usr/include/c++/4.8.3/bits/functexcept.h \
 /usr/include/c++/4.8.3/bits/exception_defines.h \
 /usr/include/c++/4.8.3/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.3/ext/type_traits.h \
 /usr/include/c++/4.8.3/ext/numeric_traits.h \
 /usr/include/c++/4.8.3/bits/stl_pair.h \
 /usr/include/c++/4.8.3/bits/move.h \
 /usr/include/c++/4.8.3/bits/concept_check.h \
 /usr/include/c++/4.8.3/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.3/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.3/debug/debug.h \
 /usr/include/c++/4.8.3/bits/stl_iterator.h \
 /usr/include/c++/4.8.3/bits/localefwd.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/c++locale.h \
 /usr/include/c++/4.8.3/clocale /usr/include/locale.h \
 /usr/include/bits/locale.h /usr/include/c++/4.8.3/cctype \
 /usr/include/ctype.h /usr/include/c++/4.8.3/bits/ios_base.h \
 /usr/include/c++/4.8.3/ext/atomicity.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/gthr.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
 /usr/include/bits/timex.h /usr/include/bits/setjmp.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/atomic_word.h \
 /usr/include/c++/4.8.3/bits/locale_classes.h \
 /usr/include/c++/4.8.3/string /usr/include/c++/4.8.3/bits/allocator.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/c++allocator.h \
 /usr/include/c++/4.8.3/ext/new_allocator.h /usr/include/c++/4.8.3/new \
 /usr/include/c++/4.8.3/bits/ostream_insert.h \
 /usr/include/c++/4.8.3/bits/cxxabi_forced.h \
 /usr/include/c++/4.8.3/bits/stl_function.h \
 /usr/include/c++/4.8.3/backward/binders.h \
 /usr/include/c++/4.8.3/bits/range_access.h \
 /usr/include/c++/4.8.3/bits/basic_string.h \
 /usr/include/c++/4.8.3/bits/basic_string.tcc \
 /usr/include/c++/4.8.3/bits/locale_classes.tcc \
 /usr/include/c++/4.8.3/streambuf \
 /usr/include/c++/4.8.3/bits/streambuf.tcc \
 /usr/include/c++/4.8.3/bits/basic_ios.h \
 /usr/include/c++/4.8.3/bits/locale_facets.h \
 /usr/include/c++/4.8.3/cwctype /usr/include/wctype.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/ctype_base.h \
 /usr/include/c++/4.8.3/bits/streambuf_iterator.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/ctype_inline.h \
 /usr/include/c++/4.8.3/bits/locale_facets.tcc \
 /usr/include/c++/4.8.3/bits/basic_ios.tcc \
 /usr/include/c++/4.8.3/bits/ostream.tcc /usr/include/c++/4.8.3/istream \
 /usr/include/c++/4.8.3/bits/istream.tcc /usr/include/unistd.h \
 /usr/include/bits/posix_opt.h /usr/include/bits/environments.h \
 /usr/include/bits/confname.h /usr/include/getopt.h
tablaarchivos.o: ../userprog/tablaarchivos.cc /usr/include/stdc-predef.h \
 ../userprog/tablaarchivos.h ../threads/synch.h ../threads/copyright.h \
 ../threads/thread.h ../threads/utility.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/list.h \
 ../userprog/bitmap.h ../filesys/openfile.h \
 /usr/include/c++/4.8.3/iostream \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/c++config.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/os_defines.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/cpu_defines.h \
 /usr/include/c++/4.8.3/ostream /usr/include/c++/4.8.3/ios \
 /usr/include/c++/4.8.3/iosfwd /usr/include/c++/4.8.3/bits/stringfwd.h \
 /usr/include/c++/4.8.3/bits/memoryfwd.h \
 /usr/include/c++/4.8.3/bits/postypes.h /usr/include/c++/4.8.3/cwchar \
 /usr/include/bits/wchar.h /usr/include/c++/4.8.3/exception \
 /usr/include/c++/4.8.3/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.3/bits/char_traits.h \
 /usr/include/c++/4.8.3/bits/stl_algobase.h \
 /usr/include/c++/4.8.3/bits/functexcept.h \
 /usr/include/c++/4.8.3/bits/exception_defines.h \
 /usr/include/c++/4.8.3/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.3/ext/type_traits.h \
 /usr/include/c++/4.8.3/ext/numeric_traits.h \
 /usr/include/c++/4.8.3/bits/stl_pair.h \
 /usr/include/c++/4.8.3/bits/move.h \
 /usr/include/c++/4.8.3/bits/concept_check.h \
 /usr/include/c++/4.8.3/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.3/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.3/debug/debug.h \
 /usr/include/c++/4.8.3/bits/stl_iterator.h \
 /usr/include/c++/4.8.3/bits/localefwd.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/c++locale.h \
 /usr/include/c++/4.8.3/clocale /usr/include/locale.h \
 /usr/include/bits/locale.h /usr/include/c++/4.8.3/cctype \
 /usr/include/ctype.h /usr/include/c++/4.8.3/bits/ios_base.h \
 /usr/include/c++/4.8.3/ext/atomicity.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/gthr.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
 /usr/include/bits/timex.h /usr/include/bits/setjmp.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/atomic_word.h \
 /usr/include/c++/4.8.3/bits/locale_classes.h \
 /usr/include/c++/4.8.3/string /usr/include/c++/4.8.3/bits/allocator.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/c++allocator.h \
 /usr/include/c++/4.8.3/ext/new_allocator.h /usr/include/c++/4.8.3/new \
 /usr/include/c++/4.8.3/bits/ostream_insert.h \
 /usr/include/c++/4.8.3/bits/cxxabi_forced.h \
 /usr/include/c++/4.8.3/bits/stl_function.h \
 /usr/include/c++/4.8.3/backward/binders.h \
 /usr/include/c++/4.8.3/bits/range_access.h \
 /usr/include/c++/4.8.3/bits/basic_string.h \
 /usr/include/c++/4.8.3/bits/basic_string.tcc \
 /usr/include/c++/4.8.3/bits/locale_classes.tcc \
 /usr/include/c++/4.8.3/streambuf \
 /usr/include/c++/4.8.3/bits/streambuf.tcc \
 /usr/include/c++/4.8.3/bits/basic_ios.h \
 /usr/include/c++/4.8.3/bits/locale_facets.h \
 /usr/include/c++/4.8.3/cwctype /usr/include/wctype.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/ctype_base.h \
 /usr/include/c++/4.8.3/bits/streambuf_iterator.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/ctype_inline.h \
 /usr/include/c++/4.8.3/bits/locale_facets.tcc \
 /usr/include/c++/4.8.3/bits/basic_ios.tcc \
 /usr/include/c++/4.8.3/bits/ostream.tcc /usr/include/c++/4.8.3/istream \
 /usr/include/c++/4.8.3/bits/istream.tcc ../threads/system.h \
 ../threads/scheduler.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h \
 ../threads/../userprog/tablasemaforos.h ../threads/../userprog/bitmap.h \
 ../threads/../userprog/tablaindicadores.h ../threads/thread.h \
 ../threads/../userprog/tablaarchivos.h /usr/include/unistd.h \
 /usr/include/bits/posix_opt.h /usr/include/bits/environments.h \
 /usr/include/bits/confname.h /usr/include/getopt.h
tablaindicadores.o: ../userprog/tablaindicadores.cc \
 /usr/include/stdc-predef.h ../userprog/tablaindicadores.h \
 ../threads/synch.h ../threads/copyright.h ../threads/thread.h \
 ../threads/utility.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdlib.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.3/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/list.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../threads/thread.h \
 ../threads/list.h ../userprog/tablaarchivos.h \
 /usr/include/c++/4.8.3/iostream \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/c++config.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/os_defines.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/cpu_defines.h \
 /usr/include/c++/4.8.3/ostream /usr/include/c++/4.8.3/ios \
 /usr/include/c++/4.8.3/iosfwd /usr/include/c++/4.8.3/bits/stringfwd.h \
 /usr/include/c++/4.8.3/bits/memoryfwd.h \
 /usr/include/c++/4.8.3/bits/postypes.h /usr/include/c++/4.8.3/cwchar \
 /usr/include/bits/wchar.h /usr/include/c++/4.8.3/exception \
 /usr/include/c++/4.8.3/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.3/bits/char_traits.h \
 /usr/include/c++/4.8.3/bits/stl_algobase.h \
 /usr/include/c++/4.8.3/bits/functexcept.h \
 /usr/include/c++/4.8.3/bits/exception_defines.h \
 /usr/include/c++/4.8.3/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.3/ext/type_traits.h \
 /usr/include/c++/4.8.3/ext/numeric_traits.h \
 /usr/include/c++/4.8.3/bits/stl_pair.h \
 /usr/include/c++/4.8.3/bits/move.h \
 /usr/include/c++/4.8.3/bits/concept_check.h \
 /usr/include/c++/4.8.3/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.3/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.3/debug/debug.h \
 /usr/include/c++/4.8.3/bits/stl_iterator.h \
 /usr/include/c++/4.8.3/bits/localefwd.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/c++locale.h \
 /usr/include/c++/4.8.3/clocale /usr/include/locale.h \
 /usr/include/bits/locale.h /usr/include/c++/4.8.3/cctype \
 /usr/include/ctype.h /usr/include/c++/4.8.3/bits/ios_base.h \
 /usr/include/c++/4.8.3/ext/atomicity.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/gthr.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
 /usr/include/bits/timex.h /usr/include/bits/setjmp.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/atomic_word.h \
 /usr/include/c++/4.8.3/bits/locale_classes.h \
 /usr/include/c++/4.8.3/string /usr/include/c++/4.8.3/bits/allocator.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/c++allocator.h \
 /usr/include/c++/4.8.3/ext/new_allocator.h /usr/include/c++/4.8.3/new \
 /usr/include/c++/4.8.3/bits/ostream_insert.h \
 /usr/include/c++/4.8.3/bits/cxxabi_forced.h \
 /usr/include/c++/4.8.3/bits/stl_function.h \
 /usr/include/c++/4.8.3/backward/binders.h \
 /usr/include/c++/4.8.3/bits/range_access.h \
 /usr/include/c++/4.8.3/bits/basic_string.h \
 /usr/include/c++/4.8.3/bits/basic_string.tcc \
 /usr/include/c++/4.8.3/bits/locale_classes.tcc \
 /usr/include/c++/4.8.3/streambuf \
 /usr/include/c++/4.8.3/bits/streambuf.tcc \
 /usr/include/c++/4.8.3/bits/basic_ios.h \
 /usr/include/c++/4.8.3/bits/locale_facets.h \
 /usr/include/c++/4.8.3/cwctype /usr/include/wctype.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/ctype_base.h \
 /usr/include/c++/4.8.3/bits/streambuf_iterator.h \
 /usr/include/c++/4.8.3/x86_64-redhat-linux/bits/ctype_inline.h \
 /usr/include/c++/4.8.3/bits/locale_facets.tcc \
 /usr/include/c++/4.8.3/bits/basic_ios.tcc \
 /usr/include/c++/4.8.3/bits/ostream.tcc /usr/include/c++/4.8.3/istream \
 /usr/include/c++/4.8.3/bits/istream.tcc /usr/include/unistd.h \
 /usr/include/bits/posix_opt.h /usr/include/bits/environments.h \
 /usr/include/bits/confname.h /usr/include/getopt.h \
 ../threads/scheduler.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
