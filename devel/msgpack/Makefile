# $FreeBSD$

PORTNAME=	msgpack
PORTVERSION=	0.5.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://msgpack.org/releases/cpp/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Binary-based efficient data interchange format focused on performance

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
# required for __sync _* atomic operations on sparc
USE_GCC=	yes
.endif

.if ${ARCH} == "i386"
# Mayby not working on i386/i486/i586...
CONFIGURE_ARGS=	CFLAGS="${CFLAGS} -march=i686" CXXFLAGS="${CXXFLAGS} -march=i686"
.endif

.include <bsd.port.post.mk>
