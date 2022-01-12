Name:		libround		
Version:	1.0.4
Release:	1%{?dist}
Summary:	Library of various numerical rounding functions

Group:		System Environment/Libraries
License:	LGPLv2.1
URL:		https://github.com/ac000/libround
Source0:	libround-%{version}.tar
BuildRoot:	%(mktemp -ud %{_tmppath}/%{name}-%{version}-%{release}-XXXXXX)

BuildRequires:	glibc-devel

%description
libround is a library containing numerous numerical rounding functions.


%prep
%setup -q


%build
make %{?_smp_mflags}


%install
rm -rf $RPM_BUILD_ROOT
install -Dp -m644 libround.h $RPM_BUILD_ROOT/%{_includedir}/libround.h
install -Dp -m0755 libround.so.%{version} $RPM_BUILD_ROOT/%{_libdir}/libround.so.%{version}
cd $RPM_BUILD_ROOT/%{_libdir}
ln -s libround.so.1 libround.so
cd -

%post -p /sbin/ldconfig

%clean
rm -rf $RPM_BUILD_ROOT


%files
%defattr(-,root,root,-)
%doc README COPYING
%{_libdir}/libround.*
%{_includedir}/libround.h


%changelog

* Wed Jan 12 2021 Andrew Clayton <andrew@digital-domain.net> - 1.0.4-1
- Minor cleanups

* Sun Aug 13 2017 Andrew Clayton <andrew@digital-domain.net> - 1.0.3-1
- Various cleanups

* Sat May 6 2017 Andrew Clayton <andrew@digital-domain.net> - 1.0.2-2
- Re-work library symlinks

* Sun Jan 29 2017 Andrew Clayton <andrew@digital-domain.net> - 1.0.2-1
- Cut a 1.0.2 release

* Mon Jul 11 2016 Andrew Clayton <andrew@digital-domain.net> - 1.0.1-1
- Cut a 1.0.1 release

* Wed Jul 06 2016 Andrew Clayton <andrew@digital-domain.net> - 1.0.0-3
- Re-instate the symlink to libround.so

* Sun Jul 03 2016 Andrew Clayton <andrew@digital-domain.net> - 1.0.0-2
- Fix spec file to install a symlink for libround.so.1

* Sat May 19 2012 Andrew Clayton <andrew@digital-domain.net> - 1.0.0-1
- New major version for API breakge.

* Thu Mar 22 2012 Andrew Clayton <andrew@digital-domain.net> - 0.0.1-1
- Unexport a function
- Bump version

* Sun Sep 26 2010 Andrew Clayton <andrew@digital-domain.net> - 0.0.0-2
- Install libround.h

* Sat Sep 25 2010 Andrew Clayton <andrew@digital-domain.net> - 0.0.0-1
- Initial version.

