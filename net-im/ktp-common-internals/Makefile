# $FreeBSD$

PORTNAME=	ktp-common-internals
PORTVERSION=	${KTP_VERSION}
CATEGORIES=	net-im kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KTP_BRANCH}/kde-telepathy/${PORTVERSION}/src

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	KDE Telepathy internal library

LIB_DEPENDS=	libtelepathy-qt4.so:${PORTSDIR}/net-im/telepathy-qt4 \
		libtelepathy-logger-qt4.so:${PORTSDIR}/net-im/telepathy-logger-qt4
RUN_DEPENDS=	${LOCALBASE}/libexec/mission-control-5:${PORTSDIR}/net-im/telepathy-mission-control

USE_KDE4=	kdeprefix kdelibs pimlibs automoc4
USE_QT4=	declarative script \
		moc_build qmake_build rcc_build uic_build
USES=		cmake gettext tar:bzip2
USE_LDCONFIG=	yes

PLIST_SUB=	KTP_VERSION=${KTP_VERSION}

.include <bsd.port.mk>
