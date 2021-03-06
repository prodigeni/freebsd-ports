--- UnAlz.cpp.orig	2014-07-07 10:40:53.000000000 +0000
+++ UnAlz.cpp
@@ -37,7 +37,7 @@
 #	include <errno.h>
 #endif
 
-#if defined(__NetBSD__)
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #	include <sys/param.h>	// __NetBSD_Version__
 #	include <errno.h>		// iconv.h 때문에 필요 
 #endif
@@ -455,7 +455,8 @@ BOOL CUnAlz::ReadLocalFileheader()
 	size_t size;
 	char inbuf[ICONV_BUF_SIZE];
 	char outbuf[ICONV_BUF_SIZE];
-#if defined(__FreeBSD__) || defined(__CYGWIN__) ||  defined(__NetBSD__)
+#if defined(__FreeBSD__) || defined(__CYGWIN__) ||  defined(__NetBSD__) \
+ || defined(__DragonFly__)
 	const char *inptr = inbuf;
 #else
 	char *inptr = inbuf;
@@ -1907,7 +1908,11 @@ void CUnAlz::DecryptingData(int nSize, B
 ////////////////////////////////////////////////////////////////////////////////////////////////////
 UINT32 CUnAlz::CRC32(UINT32 l, BYTE c)
 {
+#ifndef Z_U4
 	const unsigned long *CRC_TABLE = get_crc_table();
+#else
+	const Z_U4 *CRC_TABLE = get_crc_table();
+#endif
 	return CRC_TABLE[(l ^ c) & 0xff] ^ (l >> 8);
 }
 
