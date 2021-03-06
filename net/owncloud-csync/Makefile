# Created by: arrowdodger <6yearold@gmail.com>
# $FreeBSD$

PORTNAME=	owncloud-csync
PORTVERSION=	0.91.4
PORTREVISION=	2
CATEGORIES=	net kde
MASTER_SITES=	http://download.owncloud.com/desktop/stable/
DISTNAME=	ocsync-${PORTVERSION}

MAINTAINER=	6yearold@gmail.com
COMMENT=	Csync fork for Owncloud

LICENSE=	GPLv2

LIB_DEPENDS=	libiniparser.so:${PORTSDIR}/devel/iniparser \
		libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient \
		libssh.so.4:${PORTSDIR}/security/libssh \
		libneon.so:${PORTSDIR}/www/neon

USES=		cmake:outsource iconv pkgconfig tar:bzip2
USE_SQLITE=	yes
CMAKE_ARGS+=	-DUNIT_TESTING=NO \
		-DMAN_INSTALL_DIR=${MANPREFIX}/man

USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/ocsync
ETCDIR=		${PREFIX}/etc/ocsync

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	asciidoc:${PORTSDIR}/textproc/asciidoc

post-patch:
	@${REINPLACE_CMD} -e 's/^add_subdirectory(doc)//' ${WRKSRC}/CMakeLists.txt
.endif

post-install:
.for i in ocsync.conf ocsync_exclude.conf
	@${MV} ${STAGEDIR}${ETCDIR}/$i ${STAGEDIR}${ETCDIR}/$i.sample
.endfor

.include <bsd.port.mk>
