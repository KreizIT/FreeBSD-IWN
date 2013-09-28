FreeBSD-IWN
===========

Iwn adaptation for Intel Centrino N 2230
You will need at least :
- Freebsd 9.1
- /head/sys/net80211 from FreeBSD repo 

Activating debug is done by : 
sysctl dev.iwn.0.debug=0xffffffff

Here is branch split_6:
Include new function for PAN command
