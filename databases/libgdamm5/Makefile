# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/databases/libgdamm5/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libgdamm
PORTVERSION=	4.99.6
PORTREVISION=	2
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libgda5 library

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USES=		gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	libgda5 glibmm
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-documentation

OPTIONS_DEFINE=	BDB

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBDB} || exists(${LOCALBASE}/libdata/pkgconfig/libgda-bdb-5.0.pc)
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/libgda-bdb-5.0.pc:${PORTSDIR}/databases/libgda5-bdb
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/libgda-bdb-5.0.pc:${PORTSDIR}/databases/libgda5-bdb
PLIST_SUB+=	BDB=""
.else
PLIST_SUB+=	BDB=""
.endif

.include <bsd.port.mk>
