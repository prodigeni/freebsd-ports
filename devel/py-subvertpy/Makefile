# Created by: Carlo Strub (c-s@c-s.li)
# $FreeBSD$

PORTNAME=	subvertpy
PORTVERSION=	0.8.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/90814723/ \
		http://www.c-s.li/ports/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Python bindings for subversion

LICENSE=	GPLv2

BUILD_DEPENDS+=	svn:${PORTSDIR}/devel/subversion

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		python
USE_PYTHON=	distutils autoplist
MAKE_ENV=	HOME=/dev/null

.include <bsd.port.mk>
