FreeBSD-IWN
===========

Iwn adaptation for Intel Centrino N 2230
You will need at least :
- Freebsd 9.1
- /head/sys/net80211 from FreeBSD repo 

Activating debug is done by : 
sysctl dev.iwn.0.debug=0xffffffff

Here is branch split_7:
Prepare "parameter" mode. This will remove configuration test based on 
hardware revision and use specific parameter.
See split_8.
