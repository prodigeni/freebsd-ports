# Created by: Dave Grochowski <malus.x@gmail.com>
# $FreeBSD$

PORTNAME=	libdlna
PORTVERSION=	0.2.3
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://libdlna.geexbox.org/releases/ \
		http://critical.ch/distfiles/ \
		http://energy.critical.ch/distfiles/

MAINTAINER=	malus.x@gmail.com
COMMENT=	Reference DLNA open-source implementation

LIB_DEPENDS+=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg

HAS_CONFIGURE=	yes
USES=		tar:bzip2 gmake pkgconfig
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS+=	--prefix="${PREFIX}" --disable-optimize \
			--includedir="${PREFIX}/include" \
			--libdir="${PREFIX}/lib"

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		's#\(PKGCONFIG_DIR = \).*#\1${STAGEDIR}${PREFIX}/libdata/pkgconfig#' \
		${WRKSRC}/Makefile

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc" && ${OSVERSION} > 900000
BROKEN=		Does not build on powerpc-9: fails to link
.endif

.include <bsd.port.post.mk>
