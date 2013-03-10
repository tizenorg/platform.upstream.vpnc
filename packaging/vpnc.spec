Name:           vpnc
BuildRequires:  gnutls
BuildRequires:  libgcrypt-devel
BuildRequires:  libgnutls-devel
BuildRequires:  pkg-config
Version:        0.5.3r517
Release:        0
Summary:        A Client for Cisco VPN concentrator
License:        GPL-2.0+
Group:          Networking/Security
Url:            http://svn.unix-ag.uni-kl.de/vpnc/branches/vpnc-nortel
Requires:       /usr/sbin/ip
Requires:       /usr/bin/sed
Source:         %{name}-%{version}.tar.bz2
Source2:        vpnc.conf
Patch1:         vpnc-no-build-dates.patch

%description
A VPN client compatible with Cisco's EasyVPN equipment.

Cisco 3000, IOS routers, PIX/ASA Zecurity Appliances, and
Juniper/Netscreen as well as Nortel Contivity (experimental).

Supported Authentications: Pre-Shared-Key + XAUTH, Pre-Shared-Key
Supported IKE DH-Groups: dh1 dh2 dh5 Supported Hash Algo (IKE/IPSEC):
md5 sha1 Supported Encryptions (IKE/IPSEC): (null) (1des) 3des aes128
aes192 aes256 Perfect Forward Secrecy: nopfs dh1 dh2 dh5

It runs entirely in userspace and uses the TUN/TAP driver for access.


%prep
%setup -n %{name}

%build
export CFLAGS="%optflags"
make PREFIX=/usr

%install
mkdir -p ${RPM_BUILD_ROOT}/%{_localstatedir}/run/vpnc
%{__make} install \
	DESTDIR=${RPM_BUILD_ROOT} \
	PREFIX=/usr
rm -rfv ${RPM_BUILD_ROOT}/usr/share/doc/vpnc
mkdir -p ${RPM_BUILD_ROOT}/%{_sysconfdir}/tmpfiles.d
install -m 0644 %{SOURCE2} ${RPM_BUILD_ROOT}/%{_sysconfdir}/tmpfiles.d/

%files
%defattr(-,root,root)
%attr(0600,root,root) %config(noreplace) %ghost %{_sysconfdir}/vpnc/default.conf
%dir %{_sysconfdir}/tmpfiles.d
%config %{_sysconfdir}/tmpfiles.d/vpnc.conf
%ghost %{_localstatedir}/run/vpnc
%dir %{_sysconfdir}/vpnc
%{_sysconfdir}/vpnc/vpnc-script
%{_sbindir}/vpnc
%{_sbindir}/vpnc-disconnect
%{_bindir}/cisco-decrypt
%{_bindir}/pcf2vpnc
%{_mandir}/man1/cisco-decrypt.1.*
%{_mandir}/man1/pcf2vpnc.1.*
%{_mandir}/man8/vpnc.8.*
%license COPYING

%changelog
