# Created by: Anton Karpov <toxa@toxahost.ru>
# $FreeBSD$

PORTNAME=	gpsd
PORTVERSION=	3.9
CATEGORIES=	astro geography
MASTER_SITES=	SAVANNAH

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	Daemon that monitors one or more GPSes attached to a host computer

BUILD_DEPENDS=	docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl \
		xsltproc:${PORTSDIR}/textproc/libxslt

USES=		pathfix pkgconfig python scons
USE_RC_SUBR=	gpsd

MAKE_ARGS=	prefix="${PREFIX}" mandir="man" pkgconfig="libdata/pkgconfig" \
		chrpath=no
MAKE_ENV=	DESTDIR="${STAGEDIR}"

OPTIONS_DEFINE=	AIVDM ASHTECH CPPBIND DBUS EARTHMATE EVERMORE FV18 GARMIN GARMINTXT \
		GEOSTAR GPSCLOCK GTK2 IPV6 ITRAX MTK NAVCOM NETFEED NMEA NTPSHM NTRIP \
		OCEANSERVER OLDPROTO ONCORE PASSTHROUGH PPS PROFILING RECONFIGURE \
		RTCM104V2 RTCM104V3 SHMEXPORT SIRF SOCKEXPORT SUPERSTARII TIMING TNT TRIPMATE \
		TSIP QTBIND UBX USB
OPTIONS_DEFAULT=	AIVDM ASHTECH CPPBIND EARTHMATE EVERMORE FV18 GARMIN GARMINTXT GEOSTAR \
			GPSCLOCK ITRAX NAVCOM NETFEED NMEA NTPSHM NTRIP OCEANSERVER OLDPROTO \
			ONCORE PASSTHROUGH PPS RECONFIGURE RTCM104V2 RTCM104V3 SHMEXPORT SIRF \
			SOCKEXPORT SUPERSTARII TIMING TNT TRIPMATE TSIP UBX USB

AIVDM_DESC=		Aivdm support
ASHTECH_DESC=		Ashtech support
CPPBIND_DESC=		Build C++ bindings
EARTHMATE_DESC=		DeLorme EarthMate Zodiac support
EVERMORE_DESC=		Evermore binary support
FV18_DESC=		San Jose Navigation FV-18 support
GARMIN_DESC=		Garmin kernel driver support
GARMINTXT_DESC=		Garmin Simple Text support
GEOSTAR_DESC=		Geostar Protocol support
GPSCLOCK_DESC=		GPSclock support
GTK2_DESC=		Install py-gtk2 (required for xgps & xgpsspeed)
ITRAX_DESC=		iTrax support
MTK_DESC=		MTK-3301 support
NAVCOM_DESC=		Navcom support
NETFEED_DESC=		Build support for handling TCP/IP data sources
NMEA_DESC=		NMEA support
NTPSHM_DESC=		NTP time hinting support
NTRIP_DESC=		NTRIP support
OCEANSERVER_DESC=	Oceanserver support
OLDPROTO_DESC=		Old (pre-JSON) protocol support in client lib
ONCORE_DESC=		Motorola OnCore chipset support
PASSTHROUGH_DESC=	Build support for passing through JSON
PPS_DESC=		PPS time syncing support
PROFILING_DESC=		Profiling support
RECONFIGURE_DESC=	Allow gpsd to change device settings
RTCM104V2_DESC=		rtcm104v2 support
RTCM104V3_DESC=		rtcm104v3 support
SHMEXPORT_DESC=		Enable export via shared memory
SIRF_DESC=		SiRF chipset support
SOCKEXPORT_DESC=	Enable export over sockets
SUPERSTARII_DESC=	SuperStarII support
TIMING_DESC=		Build latency timing support
TNT_DESC=		True North Technologies support
TRIPMATE_DESC=		DeLorme TripMate support
TSIP_DESC=		Trimble TSIP support
QTBIND_DESC=		build QT bindings
UBX_DESC=		UBX protocol support
USB_DESC=		libusb support for USB devices

.include <bsd.port.options.mk>

# Options related to GPS protocols
.if ! ${PORT_OPTIONS:MNMEA}
SCONS_ARGS+=	nmea=no
.endif

.if ! ${PORT_OPTIONS:MASHTECH}
SCONS_ARGS+=	ashtech=no
.endif

.if ! ${PORT_OPTIONS:MEARTHMATE}
SCONS_ARGS+=	earthmate=no
.endif

.if ! ${PORT_OPTIONS:MEVERMORE}
SCONS_ARGS+=	evermore=no
.endif

.if ! ${PORT_OPTIONS:MFV18}
SCONS_ARGS+=	fv18=no
.endif

.if ! ${PORT_OPTIONS:MGARMIN}
SCONS_ARGS+=	garmin=no
.endif

.if ! ${PORT_OPTIONS:MGARMINTXT}
SCONS_ARGS+=	garmintxt=no
.endif

.if ! ${PORT_OPTIONS:MGEOSTAR}
SCONS_ARGS+=	geostar=no
.endif

.if ! ${PORT_OPTIONS:MITRAX}
SCONS_ARGS+=	itrax=no
.endif

.if ! ${PORT_OPTIONS:MMTK}
SCONS_ARGS+=	mtk3301=no
.endif

.if ! ${PORT_OPTIONS:MNAVCOM}
SCONS_ARGS+=	navcom=no
.endif

.if ! ${PORT_OPTIONS:MONCORE}
SCONS_ARGS+=	oncore=no
.endif

.if ! ${PORT_OPTIONS:MSIRF}
SCONS_ARGS+=	sirf=no
.endif

.if ! ${PORT_OPTIONS:MSUPERSTARII}
SCONS_ARGS+=	superstar2=no
.endif

.if ! ${PORT_OPTIONS:MTNT}
SCONS_ARGS+=	tnt=no
.endif

.if ! ${PORT_OPTIONS:MTRIPMATE}
SCONS_ARGS+=	tripmate=no
.endif

.if ! ${PORT_OPTIONS:MTSIP}
SCONS_ARGS+=	tsip=no
.endif

.if ! ${PORT_OPTIONS:MUBX}
SCONS_ARGS+=	ubx=no
.endif

# Options related to Non-GPS protocols
.if ! ${PORT_OPTIONS:MAIVDM}
SCONS_ARGS+=	aivdm=no
.endif

.if ! ${PORT_OPTIONS:MGPSCLOCK}
SCONS_ARGS+=	gpsclock=no
.endif

.if ! ${PORT_OPTIONS:MNTRIP}
SCONS_ARGS+=	ntrip=no
.endif

.if ! ${PORT_OPTIONS:MOCEANSERVER}
SCONS_ARGS+=	oceanserver=no
.endif

.if ! ${PORT_OPTIONS:MRTCM104V2}
SCONS_ARGS+=	rtcm104v2=no
.endif

.if ! ${PORT_OPTIONS:MRTCM104V3}
SCONS_ARGS+=	rtcm104v3=no
.endif

# Time service
.if ! ${PORT_OPTIONS:MNTPSHM}
SCONS_ARGS+=	ntpshm=no
.endif

.if ! ${PORT_OPTIONS:MPPS}
SCONS_ARGS+=	pps=no
.else
.	if ! ${PORT_OPTIONS:MNTPSHM}
IGNORE=		PPS requires NTPSHM
.	endif
.endif

# Export methods
.if ! ${PORT_OPTIONS:MSOCKEXPORT}
SCONS_ARGS+=	socket_export=no
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	libdbus:${PORTSDIR}/devel/dbus \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
SCONS_ARGS+=	dbus_export=yes
.endif

.if ! ${PORT_OPTIONS:MSHMEXPORT}
SCONS_ARGS+=	shm_export=no
.endif

# Communication
.if ! ${PORT_OPTIONS:MUSB}
SCONS_ARGS+=	usb=no
.endif

.if ! ${PORT_OPTIONS:MIPV6}
SCONS_ARGS+=	ipv6=no
.endif

.if ! ${PORT_OPTIONS:MNETFEED}
SCONS_ARGS+=	netfeed=no
.endif

.if ! ${PORT_OPTIONS:MPASSTHROUGH}
SCONS_ARGS+=	passthrough=no
.endif

# Other daemon options
.if ! ${PORT_OPTIONS:MTIMING}
SCONS_ARGS+=	timing=no
.endif

# Client-side options
.if ! ${PORT_OPTIONS:MOLDPROTO}
SCONS_ARGS+=	oldstyle=no
.endif

.if ${PORT_OPTIONS:MQTBIND}
USE_QT4=	network
SCONS_ARGS+=	libQgpsmm=yes
PLIST_SUB+=	QTBIND=""
.else
SCONS_ARGS+=	libQgpsmm=no
PLIST_SUB+=	QTBIND="@comment "
.endif

.if ! ${PORT_OPTIONS:MRECONFIGURE}
SCONS_ARGS+=	reconfigure=no
.endif

.if ! ${PORT_OPTIONS:MCPPBIND}
SCONS_ARGS+=	libgpsmm=no
.endif

# Build control
.if ${PORT_OPTIONS:MPROFILING}
SCONS_ARGS+=	profiling=yes
.endif

# generates .py[co] files for installed modules
# if that's not done, ${PYTHON_SITELIBDIR}/gps will be polluted
# with these files when module is imported from root user
post-install:
	(cd ${STAGEDIR}${PREFIX} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;} && \
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

.include <bsd.port.mk>
