--- config.h.orig	Wed Oct 19 06:56:25 1994
+++ config.h	Fri Dec 12 13:16:55 2003
@@ -8,7 +8,7 @@
 /*
  *	For X11R6
  */
-#undef X11R6
+#define X11R6
 
 /*
  *	For System V
@@ -33,6 +33,12 @@
 #undef NO_CUSERID
 
 /*
+ *      Your system has getpwuid() in library
+ */
+
+#define HAVE_GETPWUID
+
+/*
  *	For MH scan users
  */
 
@@ -42,12 +48,12 @@
  *	For Shape Extension
  */
 
-#undef SHAPE
+#define SHAPE
 
 /*
  *	Check Environment Variable MAIL for check file
  */
-#undef GETENV_MAIL
+#define GETENV_MAIL
 
 /*
  *	Set Local Spool pathname
@@ -57,30 +63,47 @@
 /*
  *	For X pixmap
  */
-#undef XPM
-#undef DepXpmLib	/usr/local/lib/libXpm.a
+#define XPM
+
+#ifdef XPM
+#ifdef __FreeBSD__
+#undef DepXpmLib
+#else
+#define DepXpmLib	/usr/local/lib/libXpm.a
+#endif /* __FreeBSD__ */
+#endif /* XPM */
 
 /*
  *	For using I18N Xaw
  */
-#undef XI18N
-/* If you use X11R6, these settings below are not necessary */
+#ifndef XI18N
+#ifdef __FreeBSD__
+#define XI18N
+#endif
+#endif
+
+#ifdef XI18N
+#undef X11R5_Xsi	/* define if X11R5 Xsi */
+#endif
+
+#ifdef X11R5_Xsi	/* When X11R5 Xsi, define followings if you want */
 #undef DepXawLib	/usr/local/lib/I18N/libXaw.a
 #undef DepXwcharLib	/usr/local/lib/I18N/libXwchar.a
 #undef Xi18nLibDir	-L/usr/local/lib/I18N \
 			-L/usr/local/lib
 #undef Xi18nIncDir	-I/usr/local/X11/include
+#endif
 
 /*
  *	Convert JIS to Japanese EUC
  */
-#undef JCONVERT
+#define JCONVERT
 #undef GUESS_JIS
 
 /*
  *	Process MIME header, charset=ISO-2022-JP, base 64 encoding
  */
-#undef ISO_2022_JP
+#define ISO_2022_JP
 
 /*
  *	For SUN Audio
@@ -88,9 +111,19 @@
 #undef SUN_AUDIO
 #undef AudioIncDir /usr/demo/SOUND
 
+/*
+ * For BSD Audio (FreeBSD)
+ */
+#ifndef __alpha
+#define BSD_AUDIO
+#endif
+
 /* 
  * For YOUBIN Service
 */
 #undef YOUBIN
-#undef YoubinBinDir /usr/local/bin
-#undef YOUBIN_DEFAULT_SERVER_HOST "server"
+
+#ifdef YOUBIN
+#define YoubinBinDir %YOUBINBINDIR%
+#define YOUBIN_DEFAULT_SERVER_HOST "server"
+#endif /* YOUBIN */
