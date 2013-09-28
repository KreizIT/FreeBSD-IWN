FreeBSD-IWN
===========

Iwn adaptation for Intel Centrino N 2230
You will need at least :
- Freebsd 9.1
- /head/sys/net80211 from FreeBSD repo 

Activating debug is done by : 
sysctl dev.iwn.0.debug=0xffffffff

Branch information :
-Master : Current work, consider this as experimental

-LKGV : Last Known Good Version, nearly stable version
	See RESULTS.TXT for known problems and tested NIC
	Use head_patch bring your FreeBSD -HEAD version to this version

-split_x : Branches used during FreeBSD 10 Freeze. Should be used only for 
	freebsd-wireless mailing list.
	Use head_split_x.patch bring your FreeBSD -HEAD version to version of
	branch
	Architecture code changes will be bring back to LKGV Branch when commited
	in FreeBSD Repo

-svn_merge : Obsolete 
