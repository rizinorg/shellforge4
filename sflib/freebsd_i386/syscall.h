
/* $Id$ */

#ifdef SF_USER_ERRNO

#define __syscall_return(type, res) \
do { \
        if ((unsigned long)(res) >= (unsigned long)(-125)) { \
                errno = -(res); \
                res = -1; \
        } \
        return (type) (res); \
} while (0)

#else /* SF_USE_ERRNO */

#define __sfsyscall_return(type, res) \
do { \
	return (type) (res); \
} while (0)

#endif /* SF_USE_ERRNO */


/* syscall macros */

#define _sfsyscall0(type,name) \
type name(void) \
{ \
long __res; \
__asm__ volatile ("int $0x80" \
	: "=a" (__res) \
	: "0" (__NR_##name)); \
__sfsyscall_return(type,__res); \
}

#define _sfsyscall1(type,name,type1,arg1) \
type name(type1 arg1) \
{ \
long __res; \
__asm__ volatile ("pushl %2\n\t"     \
		  "pushl %%eax\n\t"  \
		  "int   $0x80\n\t"  \
		  "add   $8, %%esp"  \
	: "=a" (__res) \
	: "0" (__NR_##name),"r" ((long)(arg1))); \
__sfsyscall_return(type,__res); \
}

#define _sfsyscall2(type,name,type1,arg1,type2,arg2) \
type name(type1 arg1,type2 arg2) \
{ \
long __res; \
__asm__ volatile ("pushl %3\n\t"     \
		  "pushl %2\n\t"     \
		  "pushl %%eax\n\t"  \
		  "int   $0x80\n\t"  \
		  "add   $12, %%esp" \
	: "=a" (__res) \
	: "0" (__NR_##name),"r" ((long)(arg1)),"r" ((long)(arg2)) ); \
__sfsyscall_return(type,__res); \
}

#define _sfsyscall3(type,name,type1,arg1,type2,arg2,type3,arg3) \
type name(type1 arg1,type2 arg2,type3 arg3) \
{ \
long __res; \
__asm__ volatile ("pushl %4\n\t"     \
		  "pushl %3\n\t"     \
		  "pushl %2\n\t"     \
		  "pushl %%eax\n\t"  \
		  "int   $0x80\n\t"  \
		  "add   $16, %%esp" \
	: "=a" (__res) \
	: "0" (__NR_##name),"r" ((long)(arg1)),"r" ((long)(arg2)), \
		  "r" ((long)(arg3)) ); \
__sfsyscall_return(type,__res); \
}

#define _sfsyscall4(type,name,type1,arg1,type2,arg2,type3,arg3,type4,arg4) \
type name (type1 arg1, type2 arg2, type3 arg3, type4 arg4) \
{ \
long __res; \
__asm__ volatile ("pushl %5\n\t"     \
		  "pushl %4\n\t"     \
		  "pushl %3\n\t"     \
		  "pushl %2\n\t"     \
		  "pushl %%eax\n\t"  \
		  "int   $0x80\n\t"  \
		  "add   $20, %%esp" \
	: "=a" (__res) \
	: "0" (__NR_##name),"r" ((long)(arg1)),"c" ((long)(arg2)), \
	  "d" ((long)(arg3)),"S" ((long)(arg4)) ); \
__sfsyscall_return(type,__res); \
} 

#define _sfsyscall5(type,name,type1,arg1,type2,arg2,type3,arg3,type4,arg4, \
	  type5,arg5) \
type name (type1 arg1,type2 arg2,type3 arg3,type4 arg4,type5 arg5) \
{ \
long __res; \
__asm__ volatile ("pushl %6\n\t"     \
		  "pushl %5\n\t"     \
		  "pushl %4\n\t"     \
		  "pushl %3\n\t"     \
		  "pushl %2\n\t"     \
		  "pushl %%eax\n\t"  \
		  "int   $0x80\n\t"  \
		  "add   $24, %%esp" \
	: "=a" (__res) \
	: "0" (__NR_##name),"r" ((long)(arg1)),"r" ((long)(arg2)), \
	  "r" ((long)(arg3)),"r" ((long)(arg4)),"r" ((long)(arg5))); \
__sfsyscall_return(type,__res); \
}

#define _sfsyscall6(type,name,type1,arg1,type2,arg2,type3,arg3,type4,arg4, \
	  type5,arg5,type6,arg6) \
type name (type1 arg1,type2 arg2,type3 arg3,type4 arg4,type5 arg5, type6 arg6) \
{ \
long __res; \
__asm__ volatile ("pushl %7\n\t"     \
		  "pushl %6\n\t"     \
		  "pushl %5\n\t"     \
		  "pushl %4\n\t"     \
		  "pushl %3\n\t"     \
		  "pushl %2\n\t"     \
		  "pushl %%eax\n\t"  \
		  "int   $0x80\n\t"  \
		  "add   $28, %%esp" \
	: "=a" (__res) \
	: "0" (__NR_##name),"r" ((long)(arg1)),"r" ((long)(arg2)), \
	  "r" ((long)(arg3)),"r" ((long)(arg4)),"r" ((long)(arg5)), \
	  "r" ((long)(arg6))); \
__sfsyscall_return(type,__res); \
}

