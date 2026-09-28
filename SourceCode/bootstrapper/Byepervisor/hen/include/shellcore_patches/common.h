#ifndef COMMON_H
#define COMMON_H

#include <sys/types.h>

struct patch
{
    uint64_t offset;
    const char data[0x100];
    int size;
};

/*
 * The PS5 SDK's <sys/uio.h> already declares uio_rw / uio_seg / uio.
 * Only provide fallback definitions when it has not been included.
 */
#ifndef _SYS_UIO_H_
enum	uio_rw { UIO_READ, UIO_WRITE };

/* Segment flag values. */
enum uio_seg {
	UIO_USERSPACE,		/* from user data space */
	UIO_SYSSPACE,		/* from system space */
	UIO_NOCOPY		/* don't copy, already in object */
};

struct uio {
	struct	iovec *uio_iov;		/* scatter/gather list */
	int	uio_iovcnt;		/* length of scatter/gather list */
	off_t	uio_offset;		/* offset in target object */
	ssize_t	uio_resid;		/* remaining bytes to process */
	enum	uio_seg uio_segflg;	/* address space */
	enum	uio_rw uio_rw;		/* operation */
	void *uio_td;		/* owner */
};
#endif /* _SYS_UIO_H_ */

#endif // COMMON_H
