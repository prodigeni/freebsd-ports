# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PPI
PORTVERSION=	1.215
PORTREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ADAMK
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Analyze and manipulate Perl code without using perl itself

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	\
		p5-Clone>=0.30:${PORTSDIR}/devel/p5-Clone \
		p5-IO-String>=1.07:${PORTSDIR}/devel/p5-IO-String \
		p5-List-MoreUtils>=0.16:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Params-Util>=1.00:${PORTSDIR}/devel/p5-Params-Util \
		p5-Task-Weaken>0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-Class-Inspector>=1.22:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-File-Remove>=1.42:${PORTSDIR}/devel/p5-File-Remove
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-NoWarnings>=0.084:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-Object>=0.07:${PORTSDIR}/devel/p5-Test-Object \
		p5-Test-SubCalls>=1.07:${PORTSDIR}/devel/p5-Test-SubCalls

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
