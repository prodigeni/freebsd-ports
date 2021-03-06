# $FreeBSD$

PORTNAME=	libsidplayfp
PORTVERSION=	1.6.0
CATEGORIES=	audio
MASTER_SITES=	SF/sidplay-residfp/libsidplayfp/${PORTVERSION:R}

MAINTAINER=	liangtai.s16@gmail.com
COMMENT=	Library to play Commodore 64 music derived from libsidplay2

LICENSE=	GPLv2

USES=		gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	NEWS README TODO

OPTIONS_DEFINE=	DEBUG DOCS DOXYGEN
DEBUG_CONFIGURE_ON=	--enable-debug=full
DOXYGEN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen

OPTIONS_MULTI=	OPTIMIZATION
OPTIONS_MULTI_OPTIMIZATION=	BHINTS INLINE MMX
OPTIONS_DEFAULT=	BHINTS INLINE
OPTIMIZATION_DESC=	Increase performance by optimization
BHINTS_DESC=	Enable branch hints in reSID engine
BHINTS_CONFIGURE_ENABLE=	branch-hints
INLINE_DESC=	Enable inlining in reSID engine at bigger code size
INLINE_CONFIGURE_ENABLE=	inline
MMX_DESC=	Enable MMX code in reSIDfp for old x86 non-SSE2 CPU
MMX_CONFIGURE_ENABLE=	mmx

BUILD_DEPENDS+=	xa65:${PORTSDIR}/devel/xa65

.include <bsd.port.options.mk>

SIDPLAYFP_SHLIB_VERSION=	3.1.0
STILVIEW_SHLIB_VERSION=	0.0.2
PLIST_SUB+=	\
	SIDPLAYFP_SHLIB_VER=${SIDPLAYFP_SHLIB_VERSION:C/\.[[:digit:].]+//} \
	SIDPLAYFP_SHLIB_VERSION=${SIDPLAYFP_SHLIB_VERSION} \
	STILVIEW_SHLIB_VER=${STILVIEW_SHLIB_VERSION:C/\.[[:digit:].]+//} \
	STILVIEW_SHLIB_VERSION=${STILVIEW_SHLIB_VERSION}

post-build:
.if ${PORT_OPTIONS:MDOXYGEN}
	cd ${WRKSRC} && ${MAKE} doc
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ; \
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MDOXYGEN}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html ; \
	${INSTALL_MAN} ${WRKSRC}/docs/html/* ${STAGEDIR}${DOCSDIR}/html ; \
	${RM} -f ${WRKDIR}/PLIST.doc ; \
	${FIND} ${STAGEDIR}${DOCSDIR}/html -type f | \
		${SED} 's|${STAGEDIR}${PREFIX}/||' \
		>> ${WRKDIR}/PLIST.doc
	cd ${WRKDIR} ; ${SED} -i -e '/PLIST.doc/ r PLIST.doc' ${TMPPLIST}
.endif

.include <bsd.port.mk>
