# Created by: jkh
# $FreeBSD$

PORTNAME=	swig
PORTVERSION=	3.0.3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	30

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate wrappers for calling C/C++ code from other languages

LICENSE=	GPLv3

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

OPTIONS_DEFINE=	DOCS EXAMPLES

ALL_TARGET=	# empty
CFLAGS+=	-fPIC -DPIC
CONFIGURE_ARGS=	--program-suffix=${PORTVERSION:R} \
		--with-lua=${LUA_BINDIR}/lua \
		--with-luaincl=${LUA_INCDIR} \
		--with-lualib=${LUA_LIBDIR}
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:env
USES=		gmake lua

PLIST_SUB=	MAJOR_VER=${PORTVERSION:R}
PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

OCTAVE_VER_CMD=	${LOCALBASE}/bin/octave-config -v 2>/dev/null || ${TRUE}

post-patch:
	@${SETENV} OCTAVE_VER=$$(${OCTAVE_VER_CMD}) ${REINPLACE_CMD} \
		-e 's|$$RUBY |${RUBY} |' \
		-e 's|^PHP4CONFIG=.*$$|PHP4CONFIG=php-config|' \
		-e 's|OCTAVEDIR=".*"|OCTAVEDIR="${LOCALBASE}/include/octave-$${OCTAVE_VER}"|' \
		-e 's|MZSCHEME --mute-banner|MZSCHEME|' \
		-e '/^MZDYNOBJ/s|`$$|\| tail -n 1`|' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/Lib/lua/luarun.swg

post-configure:
	${REINPLACE_CMD} -e 's#null#&|| true#' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ccache-swig${PORTVERSION:R} ${STAGEDIR}${PREFIX}/bin/swig${PORTVERSION:R}
	cd ${WRKSRC}/Doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/${PORTVERSION}
	cd ${WRKSRC}/Examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/${PORTVERSION}

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
