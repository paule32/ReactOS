#ifndef PC_H_
#define PC_H_

/*
 * inportb()
 *	Get a byte from an I/O port
 */
typedef unsigned char  uchar;
typedef unsigned short ushort;

inline extern uchar
inportb(int port)
{
	register uchar res;
	
	__asm__ __volatile__(
		"inb %%dx,%%al\n\t"
		: "=a" (res)
		: "d" (port));
	return(res);
}

/*
 * outportb()
 *	Write a byte to an I/O port
 */
inline extern void
outportb(int port, uchar data)
{
	__asm__ __volatile__(
		"outb %%al,%%dx\n\t"
		: /* No output */
		: "a" (data), "d" (port));
}

/*
 * inportw()
 *	Get a word from an I/O port
 */
inline extern ushort
inportw(int port)
{
	register ushort res;
	
	__asm__ __volatile__(
		"inw %%dx,%%ax\n\t"
		: "=a" (res)
		: "d" (port));
	return(res);
}

/*
 * outportw()
 *	Write a word to an I/O port
 */
inline extern void
outportw(int port, ushort data)
{
	__asm__ __volatile__(
		"outw %%ax,%%dx\n\t"
		: /* No output */
		: "a" (data), "d" (port));
}
#endif
