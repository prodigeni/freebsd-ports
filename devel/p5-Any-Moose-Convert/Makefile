# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Any-Moose-Convert
PORTVERSION=	0.004
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convert Moose libraries to Mouse ones, or vice versa

BUILD_DEPENDS=	p5-PerlIO-Util>=0:${PORTSDIR}/devel/p5-PerlIO-Util
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Moose>=0.90:${PORTSDIR}/devel/p5-Moose \
		p5-Mouse>=0.40:${PORTSDIR}/devel/p5-Mouse

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
