# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>
# $FreeBSD$

PORTNAME=	openca-tools-forked
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	security
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Tools to deal with SCEP and PKCS7 messages

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	openxpki
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	641e43a

USES=		gmake perl5
GNU_CONFIGURE=	yes

# security/openssl already has a verify.1 manpage.
post-stage:
.for f in sign.1 verify.1
	@${MV} ${STAGEDIR}${PREFIX}/man/man1/${f} ${STAGEDIR}${PREFIX}/man/man1/openca-${f}
.endfor

.include <bsd.port.mk>
