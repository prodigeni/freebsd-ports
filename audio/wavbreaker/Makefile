# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	wavbreaker
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to split and merge wav files

LICENSE=	GPLv2

OPTIONS_DEFINE=	PULSEAUDIO NLS

USE_GNOME=	gtk20 libxml2
USES=		gmake pathfix pkgconfig desktop-file-utils
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PKG_CONFIG="${LOCALBASE}/bin/pkg-config"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-alsa
INSTALLS_ICONS=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	libpulse.so:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=--disable-pulse
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

.include <bsd.port.mk>
