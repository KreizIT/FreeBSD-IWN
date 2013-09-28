# $FreeBSD$

.PATH:  ${.CURDIR}/../../dev/iwn

KMOD    = if_iwn
SRCS    = if_iwn.c if_iwn_pan.c device_if.h bus_if.h pci_if.h opt_wlan.h
+SRCS   = opt_iwn.h

.if !defined(KERNBUILDDIR)
opt_wlan.h:
	echo "#define IEEE80211_DEBUG 1" > ${.TARGET}
.endif
.if IWN_DEBUG
CFLAGS+=-DIWN_DEBUG
.endif
.include <bsd.kmod.mk>
