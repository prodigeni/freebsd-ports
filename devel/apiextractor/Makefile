# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apiextractor
PORTVERSION=	0.10.10
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	wg@FreeBSD.org
COMMENT=	API Extractor library to build PySide

LICENSE=	GPLv2

BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx

USE_GITHUB=	yes
GH_ACCOUNT=	PySide
GH_PROJECT=	Apiextractor
#GH_TAG=		${PORTVERSION}
GH_COMMIT=	4889efc

USES=		cmake
USE_GNOME=	libxml2 libxslt
USE_QT4=	gui moc_build qmake_build qtestlib_build \
		rcc_build uic_build xml xmlpatterns
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
