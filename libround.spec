Name:		libround		
Version:	0.0.0
Release:	1%{?dist}
Summary:	Library of various numerical rounding functions

Group:		System Environment/Libraries
License:	LGPLv2.1
URL:		http://github.com/ac000/libround
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
install -Dp -m0755 libround.so.%{version} $RPM_BUILD_ROOT/%{_libdir}/libround.so.%{version}
cd $RPM_BUILD_ROOT/%{_libdir}
ln -s libround.so.%{version} libround.so
cd -

%post -p /sbin/ldconfig

%clean
rm -rf $RPM_BUILD_ROOT


%files
%defattr(-,root,root,-)
%doc README COPYING
%{_libdir}/libround.*


%changelog
* Sat Sep 25 2010 Andrew Clayton <andrew@digital-domain.net> - 0.0.0-1
- Initial version.

