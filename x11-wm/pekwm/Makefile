# Created by: anders@hack.org
# $FreeBSD$

PORTNAME=	pekwm
PORTVERSION=	0.1.17
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	x11-wm
MASTER_SITES=	https://pekwm.org/projects/3/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Light, Unobtrusive, and configurable windowmanager

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng.so:${PORTSDIR}/graphics/png

USES=		pkgconfig iconv:wchar_t gmake tar:bzip2
USE_XORG=	xft xpm x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shape --enable-xinerama --enable-xrandr \
		--enable-xft --enable-image-xpm --enable-image-jpeg \
		--enable-image-png --disable-debug \
		--disable-pedantic
CFLAGS+=	-DICONV_CONST -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

.include <bsd.port.mk>
