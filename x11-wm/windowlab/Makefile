# Created by: Pierre-Paul Lavoie <ppl@nbnet.nb.ca>
# $FreeBSD$

PORTNAME=	windowlab
PORTVERSION=	1.40
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://nickgravgaard.com/windowlab/
EXTRACT_SUFX=	.tar
DIST_SUBDIR=	repacked

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small window manager for X11

LICENSE=	GPLv2

OPTIONS_DEFINE=	XFT DOCS

USES=		gmake
USE_XORG=	x11 xext
MAKE_ENV=	XROOT="${LOCALBASE}" SYSCONFDIR="${ETCDIR}"

PORTDOCS=	CHANGELOG README
PLIST_FILES=	bin/windowlab %%ETCDIR%%/menurc \
		man/man1/windowlab.1x.gz

XFT_USE=	XORG=xft
XFT_USES=	pkgconfig
XFT_MAKE_ENV=	EXTRA_INC="$$(pkg-config --cflags xft)" \
		EXTRA_LIBS="$$(pkg-config --libs xft)"
XFT_CFLAGS=	-DXFT

post-patch:
	@${REINPLACE_CMD} -e \
		's|^\(PREFIX\) =|\1 ?=| ; \
		 s|^\(XROOT\) =|\1 ?=| ; \
		 s|^\(SYSCONFDIR\) =|\1 ?=| ; \
		 s|^\(CC\) =|\1 ?=|' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} windowlab ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} windowlab.1x ${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} windowlab.menurc ${STAGEDIR}${ETCDIR}/menurc)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
