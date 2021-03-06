# $FreeBSD$

PORTNAME=	p4api
PORTVERSION=	${VERSION}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/pub/perforce/r${PORTVERSION}/bin.${PLATFORM}${PLATFORM_SUFX}/:tar \
		http://www.perforce.com/perforce/doc.${DOCVER}/manuals/p4api/:pdf

EXTRACT_SUFX=
DISTFILES=	${TAR_FILES}:tar p4api.pdf:pdf
DIST_SUBDIR=	perforce/${VERSION}/${ARCH}-${PLATFORM}
EXTRACT_ONLY=	${TAR_FILES}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perforce API (static libraries and header files)

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/p4api-2008.1.158777

PLATFORM=	freebsd60
VERSION=	08.1

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
PLATFORM_SUFX=	x86
.elif ${ARCH} == amd64
PLATFORM_SUFX=	x86_64
.else
IGNORE=		Unsupported platform, sorry.
.endif

TAR_FILES=	p4api.tgz

DOCVER=		${VERSION:S/.//}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/perforce
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/perforce
	cd ${WRKSRC}/include/p4; \
	 for i in *.h; \
	 do ${INSTALL_DATA} $${i} ${STAGEDIR}${PREFIX}/include/perforce; \
	 done
	cd ${WRKSRC}/lib; \
	 for i in lib*.a; \
	 do ${INSTALL_DATA} $${i} ${STAGEDIR}${PREFIX}/lib/perforce; \
	 done
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/p4api.pdf ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/sample; \
	 for i in *; \
	 do ${INSTALL_DATA} $${i} ${STAGEDIR}${EXAMPLESDIR}; \
	 done

.include <bsd.port.post.mk>
