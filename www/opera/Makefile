# $FreeBSD$

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}
PORTREVISION=	5
CATEGORIES=	www ipv6
MASTER_SITES=	ftp://ftp.opera.com/pub/opera/${MASTER_SITES_VER_PATH}/ \
		ftp://opera.inode.at/${MASTER_SITES_VER_PATH}/ \
		http://gd.tuwien.ac.at/infosys/browsers/opera/${MASTER_SITES_VER_PATH}/ \
		ftp://opera.ftp.fu-berlin.de/${MASTER_SITES_VER_PATH}/ \
		http://ftp.ntua.gr/pub/www/Opera/${MASTER_SITES_VER_PATH}/ \
		http://mirrors.dedipower.com/opera/${MASTER_SITES_VER_PATH}/ \
		ftp://ftp.tiscali.nl/pub/mirrors/opera/${MASTER_SITES_VER_PATH}/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/opera/${MASTER_SITES_VER_PATH}&,}/
DISTNAME=	${PORTNAME}-${OPERA_VER}-${OPERA_BUILD}.${ARCH}.freebsd

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Blazingly fast, full-featured, standards-compliant browser

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig
BUILD_DEPENDS=	${LOCALBASE}/bin/update-mime-database:${PORTSDIR}/misc/shared-mime-info
RUN_DEPENDS=	${LOCALBASE}/bin/update-mime-database:${PORTSDIR}/misc/shared-mime-info

BUNDLE_LIBS=	yes

ONLY_FOR_ARCHS=	i386 amd64

OPERA_VER?=	12.16
OPERA_BUILD?=	1860
MASTER_SITES_VER_PATH=	unix/${OPERA_VER:S/.//}

USES=		tar:xz desktop-file-utils shared-mime-info
USE_XORG=	x11 xext sm ice xft xrender
REINPLACE_ARGS=	-i '' # no .bak files

WEBPLUGIN_SUBDIR=	${LOCALBASE}/lib/browser_plugins/symlinks/opera

OPTIONS_DEFINE=	CUPS VIDEO GTK2 KDE4
OPTIONS_DEFAULT=	CUPS VIDEO
NO_OPTIONS_SORT=yes

CUPS_DESC=	support for printing (requires CUPS)
VIDEO_DESC=	support for HTML5 video (requires GStreamer)

CUPS_LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client

VIDEO_USE=	gstreamer=vorbis,ogg,theora,vp8,good
GTK2_USE=	gnome=gtk20,libxml2
KDE4_USE=	kde4=kdelibs

.include <bsd.port.options.mk>

.if defined(FETCH_ALL)
# distfiles for both arch
.if ${ARCH} == i386
DISTFILES=	${PORTNAME}-${OPERA_VER}-${OPERA_BUILD}.amd64.freebsd${EXTRACT_SUFX} \
		${DISTNAME}${EXTRACT_SUFX}
.else
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-${OPERA_VER}-${OPERA_BUILD}.i386.freebsd${EXTRACT_SUFX}
.endif
.endif

.if ${PORT_OPTIONS:MGTK2}
INSTALLS_ICONS=	yes
.endif

OPERA_ARCH=	${ARCH:S,i386,intel,}

.if ${OSVERSION} >= 1000054
BUILD_DEPENDS+=	${LOCALBASE}/lib/compat/libstdc++.so.6:${PORTSDIR}/misc/compat9x
PLIST_SUB+=	LIBSTDC=""
.else
PLIST_SUB+=	LIBSTDC="@comment "
.endif

post-extract:
	${GUNZIP_CMD} ${WRKSRC}/share/man/man1/opera.1.gz

do-build:
.if ${OSVERSION} >= 1000054
	${CP} ${LOCALBASE}/lib/compat/libstdc++.so.6 ${WRKSRC}
.endif

do-configure:
	@${MV} ${WRKSRC}/share/man ${WRKSRC}/man
	@${REINPLACE_CMD} -e 's|"$${0%/.}"|${PREFIX}|g' \
		-e 's|/usr/local/profile|$$HOME/.opera|' \
		${WRKSRC}/opera
	@${REINPLACE_CMD} -e 's|@@{PREFIX}|${PREFIX}|g' \
		-e 's|@@{_SUFFIX}||g' -e 's|@@{SUFFIX}||g' \
		-e 's|@@{USUFFIX}||g' \
		${WRKSRC}/share/applications/opera-browser.desktop \
		${WRKSRC}/share/mime/packages/opera-extension.xml \
		${WRKSRC}/man/man1/opera.1
	@${REINPLACE_CMD} -e 's|/usr/X11R6/lib/browser_plugins|${WEBPLUGIN_SUBDIR}|g' \
		${WRKSRC}/share/opera/defaults/pluginpath.ini

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/opera ${STAGEDIR}${PREFIX}/bin/
	${TAR} -C ${WRKSRC} -cf - lib man share | ${TAR} -C ${STAGEDIR}${PREFIX} -xf -
.if ${OSVERSION} >= 1000054
	${INSTALL_LIB} ${WRKSRC}/libstdc++.so.6 ${STAGEDIR}${PREFIX}/lib/opera
.endif
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/libmap.d
	${INSTALL_DATA} ${FILESDIR}/libmap.conf \
		${STAGEDIR}${PREFIX}/etc/libmap.d/opera.conf

.include <bsd.port.mk>
