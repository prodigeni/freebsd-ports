# Created by: freebsd-ports@evilcode.net
# $FreeBSD$

PORTNAME=	mediainfo
PORTVERSION=	0.7.69
CATEGORIES=	multimedia
MASTER_SITES=	http://mediaarea.net/download/binary/${PORTNAME}/${PORTVERSION}/
DISTNAME=	MediaInfo_CLI_${PORTVERSION}_GNU_FromSource

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides technical and tag information for video and audio files

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libmediainfo.so:${PORTSDIR}/multimedia/libmediainfo \
		libzen.so:${PORTSDIR}/multimedia/libzen

CONFIGURE_ARGS=	--enable-shared
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool pathfix pkgconfig tar:bzip2

PLIST_FILES=	bin/mediainfo
WRKSRC=		${WRKDIR}/MediaInfo_CLI_GNU_FromSource/MediaInfo/Project/GNU/CLI

.include <bsd.port.mk>
