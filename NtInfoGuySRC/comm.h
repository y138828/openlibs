/*
通用代码头文件
*/
#if !defined(COMM_H_)
	#define COMM_H_
	
	#include <stdbool.h>
	
	//#define PRJNAME HOPY_NULL
	//#define _GOTO_DEBUG_
	
	#define IN /* IN */
	#define OUT /* OUT */
	
	#define PRE_STRA(x) #x
	#define PRE_STRW(x) L###x
	
	#define STRA(x) PRE_STRA(x)
	#define STRW(x) PRE_STRW(x)
	
	#if !defined(PRJNAME)
		#error UNDEFINED SYMBOL #PRJNAME#
	#endif
	
	#define SYMLNKNAMEA "\\\\.\\Symlnk_" STRA(PRJNAME)
	#define SYMLNKNAMEW L"\\??\\Symlnk_" STRW(PRJNAME)
	#define DEVNAMEW L"\\Device\\Dev_" STRW(PRJNAME)
	
	#define CTL_CODE(t,f,m,a) (((t)<<16)|((a)<<14)|((f)<<2)|(m))
	
	#define FILE_DEVICE_UNKNOWN	34
	#define METHOD_BUFFERED	0
	#define METHOD_IN_DIRECT 1
	#define METHOD_OUT_DIRECT 2
	#define METHOD_NEITHER 3
	#define FILE_READ_ACCESS 0x00000001
	#define FILE_WRITE_ACCESS 0x00000002
	
	typedef struct _SYSMMVALS
	{
		void *pSysWsMax;			//SysWsMax的地址
		unsigned long SysWsMax;		//系统工作集最大尺寸
		void *pSysWsMin;
		unsigned long SysWsMin;		//系统工作集最小尺寸
		void *pSysWsSize;
		unsigned long SysWsSize;	//系统工作集当前尺寸
	}SYSMMVALS,*PSYSMMVALS;		
	
	#define	IOCTL_CTL_GET_SSDT CTL_CODE(FILE_DEVICE_UNKNOWN,0x800,\
		METHOD_BUFFERED,FILE_READ_ACCESS + FILE_WRITE_ACCESS)
	
	#define	IOCTL_CTL_GET_SSDT_SDW CTL_CODE(FILE_DEVICE_UNKNOWN,(0x800+1),\
		METHOD_BUFFERED,FILE_READ_ACCESS + FILE_WRITE_ACCESS)
	
	#define	IOCTL_CTL_GET_TABLE_BASE CTL_CODE(FILE_DEVICE_UNKNOWN,(0x800+2),\
		METHOD_BUFFERED,FILE_READ_ACCESS + FILE_WRITE_ACCESS)
		
	#define	IOCTL_CTL_GET_IDT CTL_CODE(FILE_DEVICE_UNKNOWN,(0x800+3),\
		METHOD_BUFFERED,FILE_READ_ACCESS + FILE_WRITE_ACCESS)
		
	#define	IOCTL_CTL_GET_GDT CTL_CODE(FILE_DEVICE_UNKNOWN,(0x800+4),\
		METHOD_BUFFERED,FILE_READ_ACCESS + FILE_WRITE_ACCESS)
		
	#define	IOCTL_CTL_ENUM_SYSMODLIST CTL_CODE(FILE_DEVICE_UNKNOWN,(0x800+5),\
		METHOD_BUFFERED,FILE_READ_ACCESS + FILE_WRITE_ACCESS)
		
	#define	IOCTL_CTL_GET_SYSVAL CTL_CODE(FILE_DEVICE_UNKNOWN,(0x800+6),\
		METHOD_BUFFERED,FILE_READ_ACCESS + FILE_WRITE_ACCESS)
#endif
