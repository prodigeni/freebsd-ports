# Created by: Garrett Rooney <rooneg@electricjellyfish.net>
# $FreeBSD$
#   $MCom: ports/trunk/x11-wm/metacity/Makefile 20004 2014-10-20 14:11:09Z gusi $

PORTNAME=	metacity
PORTVERSION=	3.14.3
CATEGORIES=	x11-wm
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Window manager for the adult in you

BUILD_DEPENDS=	zenity>=3.0.0:${PORTSDIR}/x11/zenity \
		itstool:${PORTSDIR}/textproc/itstool \
		gsettings-desktop-schemas>=3.3.0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libgtop-2.0.so:${PORTSDIR}/devel/libgtop \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3
RUN_DEPENDS=	zenity>=3.0.0:${PORTSDIR}/x11/zenity \
		gsettings-desktop-schemas>=3.3.0:${PORTSDIR}/devel/gsettings-desktop-schemas

USE_XORG=	x11 xcomposite xdamage xrender xcursor xinerama xext xrandr
USES=		gettext gmake libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gtk30 intlhack libxml2:build
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.metacity.gschema.xml

.include <bsd.port.mk>
