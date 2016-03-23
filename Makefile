# Makefile.in generated by automake 1.14.1 from Makefile.am.
# Makefile.  Generated from Makefile.in by configure.

# Copyright (C) 1994-2013 Free Software Foundation, Inc.

# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.





am__is_gnu_make = test -n '$(MAKEFILE_LIST)' && test -n '$(MAKELEVEL)'
am__make_running_with_option = \
  case $${target_option-} in \
      ?) ;; \
      *) echo "am__make_running_with_option: internal error: invalid" \
              "target option '$${target_option-}' specified" >&2; \
         exit 1;; \
  esac; \
  has_opt=no; \
  sane_makeflags=$$MAKEFLAGS; \
  if $(am__is_gnu_make); then \
    sane_makeflags=$$MFLAGS; \
  else \
    case $$MAKEFLAGS in \
      *\\[\ \	]*) \
        bs=\\; \
        sane_makeflags=`printf '%s\n' "$$MAKEFLAGS" \
          | sed "s/$$bs$$bs[$$bs $$bs	]*//g"`;; \
    esac; \
  fi; \
  skip_next=no; \
  strip_trailopt () \
  { \
    flg=`printf '%s\n' "$$flg" | sed "s/$$1.*$$//"`; \
  }; \
  for flg in $$sane_makeflags; do \
    test $$skip_next = yes && { skip_next=no; continue; }; \
    case $$flg in \
      *=*|--*) continue;; \
        -*I) strip_trailopt 'I'; skip_next=yes;; \
      -*I?*) strip_trailopt 'I';; \
        -*O) strip_trailopt 'O'; skip_next=yes;; \
      -*O?*) strip_trailopt 'O';; \
        -*l) strip_trailopt 'l'; skip_next=yes;; \
      -*l?*) strip_trailopt 'l';; \
      -[dEDm]) skip_next=yes;; \
      -[JT]) skip_next=yes;; \
    esac; \
    case $$flg in \
      *$$target_option*) has_opt=yes; break;; \
    esac; \
  done; \
  test $$has_opt = yes
am__make_dryrun = (target_option=n; $(am__make_running_with_option))
am__make_keepgoing = (target_option=k; $(am__make_running_with_option))
pkgdatadir = $(datadir)/SampleApp
pkgincludedir = $(includedir)/SampleApp
pkglibdir = $(libdir)/SampleApp
pkglibexecdir = $(libexecdir)/SampleApp
am__cd = CDPATH="$${ZSH_VERSION+.}$(PATH_SEPARATOR)" && cd
install_sh_DATA = $(install_sh) -c -m 644
install_sh_PROGRAM = $(install_sh) -c
install_sh_SCRIPT = $(install_sh) -c
INSTALL_HEADER = $(INSTALL_DATA)
transform = $(program_transform_name)
NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
build_triplet = x86_64-unknown-linux-gnu
host_triplet = x86_64-unknown-linux-gnu
bin_PROGRAMS = assignment2$(EXEEXT)
subdir = .
DIST_COMMON = $(srcdir)/Makefile.in $(srcdir)/Makefile.am \
	$(top_srcdir)/configure $(am__configure_deps) \
	$(srcdir)/config.h.in depcomp $(noinst_HEADERS) compile \
	config.guess config.sub install-sh missing ltmain.sh
ACLOCAL_M4 = $(top_srcdir)/aclocal.m4
am__aclocal_m4_deps = $(top_srcdir)/m4/libtool.m4 \
	$(top_srcdir)/m4/ltoptions.m4 $(top_srcdir)/m4/ltsugar.m4 \
	$(top_srcdir)/m4/ltversion.m4 $(top_srcdir)/m4/lt~obsolete.m4 \
	$(top_srcdir)/configure.ac
am__configure_deps = $(am__aclocal_m4_deps) $(CONFIGURE_DEPENDENCIES) \
	$(ACLOCAL_M4)
am__CONFIG_DISTCLEAN_FILES = config.status config.cache config.log \
 configure.lineno config.status.lineno
mkinstalldirs = $(install_sh) -d
CONFIG_HEADER = config.h
CONFIG_CLEAN_FILES =
CONFIG_CLEAN_VPATH_FILES =
am__installdirs = "$(DESTDIR)$(bindir)"
PROGRAMS = $(bin_PROGRAMS)
am_assignment2_OBJECTS = assignment2-BaseApplication.$(OBJEXT) \
	assignment2-GameManager.$(OBJEXT) \
	assignment2-Physics.$(OBJEXT) assignment2-Room.$(OBJEXT) \
	assignment2-MyMotionState.$(OBJEXT) assignment2-Ball.$(OBJEXT) \
	assignment2-Paddle.$(OBJEXT)
assignment2_OBJECTS = $(am_assignment2_OBJECTS)
am__DEPENDENCIES_1 =
assignment2_DEPENDENCIES = $(am__DEPENDENCIES_1) $(am__DEPENDENCIES_1) \
	$(am__DEPENDENCIES_1) $(am__DEPENDENCIES_1) \
	$(am__DEPENDENCIES_1)
AM_V_lt = $(am__v_lt_$(V))
am__v_lt_ = $(am__v_lt_$(AM_DEFAULT_VERBOSITY))
am__v_lt_0 = --silent
am__v_lt_1 = 
assignment2_LINK = $(LIBTOOL) $(AM_V_lt) --tag=CXX $(AM_LIBTOOLFLAGS) \
	$(LIBTOOLFLAGS) --mode=link $(CXXLD) $(assignment2_CXXFLAGS) \
	$(CXXFLAGS) $(assignment2_LDFLAGS) $(LDFLAGS) -o $@
AM_V_P = $(am__v_P_$(V))
am__v_P_ = $(am__v_P_$(AM_DEFAULT_VERBOSITY))
am__v_P_0 = false
am__v_P_1 = :
AM_V_GEN = $(am__v_GEN_$(V))
am__v_GEN_ = $(am__v_GEN_$(AM_DEFAULT_VERBOSITY))
am__v_GEN_0 = @echo "  GEN     " $@;
am__v_GEN_1 = 
AM_V_at = $(am__v_at_$(V))
am__v_at_ = $(am__v_at_$(AM_DEFAULT_VERBOSITY))
am__v_at_0 = @
am__v_at_1 = 
DEFAULT_INCLUDES = -I.
depcomp = $(SHELL) $(top_srcdir)/depcomp
am__depfiles_maybe = depfiles
am__mv = mv -f
CXXCOMPILE = $(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) \
	$(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CXXFLAGS) $(CXXFLAGS)
LTCXXCOMPILE = $(LIBTOOL) $(AM_V_lt) --tag=CXX $(AM_LIBTOOLFLAGS) \
	$(LIBTOOLFLAGS) --mode=compile $(CXX) $(DEFS) \
	$(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) \
	$(AM_CXXFLAGS) $(CXXFLAGS)
AM_V_CXX = $(am__v_CXX_$(V))
am__v_CXX_ = $(am__v_CXX_$(AM_DEFAULT_VERBOSITY))
am__v_CXX_0 = @echo "  CXX     " $@;
am__v_CXX_1 = 
CXXLD = $(CXX)
CXXLINK = $(LIBTOOL) $(AM_V_lt) --tag=CXX $(AM_LIBTOOLFLAGS) \
	$(LIBTOOLFLAGS) --mode=link $(CXXLD) $(AM_CXXFLAGS) \
	$(CXXFLAGS) $(AM_LDFLAGS) $(LDFLAGS) -o $@
AM_V_CXXLD = $(am__v_CXXLD_$(V))
am__v_CXXLD_ = $(am__v_CXXLD_$(AM_DEFAULT_VERBOSITY))
am__v_CXXLD_0 = @echo "  CXXLD   " $@;
am__v_CXXLD_1 = 
SOURCES = $(assignment2_SOURCES)
DIST_SOURCES = $(assignment2_SOURCES)
am__can_run_installinfo = \
  case $$AM_UPDATE_INFO_DIR in \
    n|no|NO) false;; \
    *) (install-info --version) >/dev/null 2>&1;; \
  esac
HEADERS = $(noinst_HEADERS)
am__tagged_files = $(HEADERS) $(SOURCES) $(TAGS_FILES) \
	$(LISP)config.h.in
# Read a list of newline-separated strings from the standard input,
# and print each of them once, without duplicates.  Input order is
# *not* preserved.
am__uniquify_input = $(AWK) '\
  BEGIN { nonempty = 0; } \
  { items[$$0] = 1; nonempty = 1; } \
  END { if (nonempty) { for (i in items) print i; }; } \
'
# Make sure the list of sources is unique.  This is necessary because,
# e.g., the same source file might be shared among _SOURCES variables
# for different programs/libraries.
am__define_uniq_tagged_files = \
  list='$(am__tagged_files)'; \
  unique=`for i in $$list; do \
    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
  done | $(am__uniquify_input)`
ETAGS = etags
CTAGS = ctags
CSCOPE = cscope
AM_RECURSIVE_TARGETS = cscope
DISTFILES = $(DIST_COMMON) $(DIST_SOURCES) $(TEXINFOS) $(EXTRA_DIST)
distdir = $(PACKAGE)-$(VERSION)
top_distdir = $(distdir)
am__remove_distdir = \
  if test -d "$(distdir)"; then \
    find "$(distdir)" -type d ! -perm -200 -exec chmod u+w {} ';' \
      && rm -rf "$(distdir)" \
      || { sleep 5 && rm -rf "$(distdir)"; }; \
  else :; fi
am__post_remove_distdir = $(am__remove_distdir)
DIST_ARCHIVES = $(distdir).tar.gz
GZIP_ENV = --best
DIST_TARGETS = dist-gzip
distuninstallcheck_listfiles = find . -type f -print
am__distuninstallcheck_listfiles = $(distuninstallcheck_listfiles) \
  | sed 's|^\./|$(prefix)/|' | grep -v '$(infodir)/dir$$'
distcleancheck_listfiles = find . -type f -print
ACLOCAL = ${SHELL} /v/filer4b/v38q001/ahall12/cs354R/p3drafts/appdirectory/missing aclocal-1.14
AMTAR = $${TAR-tar}
AM_DEFAULT_VERBOSITY = 1
AR = ar
AUTOCONF = ${SHELL} /v/filer4b/v38q001/ahall12/cs354R/p3drafts/appdirectory/missing autoconf
AUTOHEADER = ${SHELL} /v/filer4b/v38q001/ahall12/cs354R/p3drafts/appdirectory/missing autoheader
AUTOMAKE = ${SHELL} /v/filer4b/v38q001/ahall12/cs354R/p3drafts/appdirectory/missing automake-1.14
AWK = gawk
BULLET_CFLAGS = 
BULLET_LIBS = 
CC = gcc
CCDEPMODE = depmode=gcc3
CEGUI_CFLAGS = -I/lusr/opt/cegui-0.8.4/include/cegui-0  
CEGUI_LIBS = -L/lusr/opt/cegui-0.8.4/lib -lCEGUIBase-0  
CEGUI_OGRE_CFLAGS = -pthread -I/lusr/opt/ogre-1.9/include -I/lusr/opt/ogre-1.9/include/OGRE -I/lusr/opt/cegui-0.8.4/include/cegui-0  
CEGUI_OGRE_LIBS = -L/lusr/opt/ogre-1.9/lib -L/lusr/opt/cegui-0.8.4/lib -lCEGUIOgreRenderer-0 -lOgreMain -lpthread -lCEGUIBase-0  
CFLAGS = -g -O2
CPP = gcc -E
CPPFLAGS = 
CXX = g++
CXXCPP = g++ -E
CXXDEPMODE = depmode=gcc3
CXXFLAGS = -g -O2
CYGPATH_W = echo
DEFS = -DHAVE_CONFIG_H
DEPDIR = .deps
DLLTOOL = false
DSYMUTIL = 
DUMPBIN = 
ECHO_C = 
ECHO_N = -n
ECHO_T = 
EGREP = /bin/grep -E
EXEEXT = 
FGREP = /bin/grep -F
GREP = /bin/grep
INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_STRIP_PROGRAM = $(install_sh) -c -s
LD = /usr/bin/ld -m elf_x86_64
LDFLAGS = 
LIBOBJS = 
LIBS = 
LIBTOOL = $(SHELL) $(top_builddir)/libtool
LIPO = 
LN_S = ln -s
LTLIBOBJS = 
MAKEINFO = ${SHELL} /v/filer4b/v38q001/ahall12/cs354R/p3drafts/appdirectory/missing makeinfo
MANIFEST_TOOL = :
MKDIR_P = /bin/mkdir -p
NM = /usr/bin/nm -B
NMEDIT = 
OBJDUMP = objdump
OBJEXT = o
OGRE_CFLAGS = -pthread -I/lusr/opt/ogre-1.9/include -I/lusr/opt/ogre-1.9/include/OGRE  
OGRE_LIBS = -L/lusr/opt/ogre-1.9/lib -lOgreMain -lpthread  
OIS_CFLAGS = -I/usr/include/ois  
OIS_LIBS = -lOIS  
OTOOL = 
OTOOL64 = 
PACKAGE = SampleApp
PACKAGE_BUGREPORT = 
PACKAGE_NAME = 
PACKAGE_STRING = 
PACKAGE_TARNAME = 
PACKAGE_URL = 
PACKAGE_VERSION = 
PATH_SEPARATOR = :
PKG_CONFIG = /usr/bin/pkg-config
PKG_CONFIG_LIBDIR = 
PKG_CONFIG_PATH = 
RANLIB = ranlib
SED = /bin/sed
SET_MAKE = 
SHELL = /bin/bash
STRIP = strip
VERSION = 0.1
abs_builddir = /v/filer4b/v38q001/ahall12/cs354R/p3drafts/appdirectory
abs_srcdir = /v/filer4b/v38q001/ahall12/cs354R/p3drafts/appdirectory
abs_top_builddir = /v/filer4b/v38q001/ahall12/cs354R/p3drafts/appdirectory
abs_top_srcdir = /v/filer4b/v38q001/ahall12/cs354R/p3drafts/appdirectory
ac_ct_AR = ar
ac_ct_CC = gcc
ac_ct_CXX = g++
ac_ct_DUMPBIN = 
am__include = include
am__leading_dot = .
am__quote = 
am__tar = $${TAR-tar} chof - "$$tardir"
am__untar = $${TAR-tar} xf -
bindir = ${exec_prefix}/bin
build = x86_64-unknown-linux-gnu
build_alias = 
build_cpu = x86_64
build_os = linux-gnu
build_vendor = unknown
builddir = .
bullet_CFLAGS = -I/usr/include/bullet  
bullet_LIBS = -lBulletSoftBody -lBulletDynamics -lBulletCollision -lLinearMath  
datadir = ${datarootdir}
datarootdir = ${prefix}/share
docdir = ${datarootdir}/doc/${PACKAGE}
dvidir = ${docdir}
exec_prefix = ${prefix}
host = x86_64-unknown-linux-gnu
host_alias = 
host_cpu = x86_64
host_os = linux-gnu
host_vendor = unknown
htmldir = ${docdir}
includedir = ${prefix}/include
infodir = ${datarootdir}/info
install_sh = ${SHELL} /v/filer4b/v38q001/ahall12/cs354R/p3drafts/appdirectory/install-sh
libdir = ${exec_prefix}/lib
libexecdir = ${exec_prefix}/libexec
localedir = ${datarootdir}/locale
localstatedir = ${prefix}/var
mandir = ${datarootdir}/man
mkdir_p = $(MKDIR_P)
oldincludedir = /usr/include
pdfdir = ${docdir}
prefix = /usr/local
program_transform_name = s,x,x,
psdir = ${docdir}
sbindir = ${exec_prefix}/sbin
sharedstatedir = ${prefix}/com
srcdir = .
sysconfdir = ${prefix}/etc
target_alias = 
top_build_prefix = 
top_builddir = .
top_srcdir = .
noinst_HEADERS = BaseApplication.h GameManager.h Game.h CollisionCallbacks.h Physics.h Room.h MyMotionState.h Ball.h Paddle.h
assignment2_CPPFLAGS = -I$(top_srcdir)
assignment2_SOURCES = BaseApplication.cpp GameManager.cpp Physics.cpp Room.cpp MyMotionState.cpp Ball.cpp Paddle.cpp
assignment2_CXXFLAGS = $(OGRE_CFLAGS) $(OIS_CFLAGS) $(bullet_CFLAGS) $(CEGUI_CFLAGS)
assignment2_LDADD = $(OGRE_LIBS) $(OIS_LIBS) $(bullet_LIBS) $(CEGUI_LIBS) $(CEGUI_OGRE_LIBS)
assignment2_LDFLAGS = -lOgreOverlay -lboost_system -lSDL -lSDL_mixer
EXTRA_DIST = buildit makeit
AUTOMAKE_OPTIONS = foreign
all: config.h
	$(MAKE) $(AM_MAKEFLAGS) all-am

.SUFFIXES:
.SUFFIXES: .cpp .lo .o .obj
am--refresh: Makefile
	@:
$(srcdir)/Makefile.in:  $(srcdir)/Makefile.am  $(am__configure_deps)
	@for dep in $?; do \
	  case '$(am__configure_deps)' in \
	    *$$dep*) \
	      echo ' cd $(srcdir) && $(AUTOMAKE) --foreign'; \
	      $(am__cd) $(srcdir) && $(AUTOMAKE) --foreign \
		&& exit 0; \
	      exit 1;; \
	  esac; \
	done; \
	echo ' cd $(top_srcdir) && $(AUTOMAKE) --foreign Makefile'; \
	$(am__cd) $(top_srcdir) && \
	  $(AUTOMAKE) --foreign Makefile
.PRECIOUS: Makefile
Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@case '$?' in \
	  *config.status*) \
	    echo ' $(SHELL) ./config.status'; \
	    $(SHELL) ./config.status;; \
	  *) \
	    echo ' cd $(top_builddir) && $(SHELL) ./config.status $@ $(am__depfiles_maybe)'; \
	    cd $(top_builddir) && $(SHELL) ./config.status $@ $(am__depfiles_maybe);; \
	esac;

$(top_builddir)/config.status: $(top_srcdir)/configure $(CONFIG_STATUS_DEPENDENCIES)
	$(SHELL) ./config.status --recheck

$(top_srcdir)/configure:  $(am__configure_deps)
	$(am__cd) $(srcdir) && $(AUTOCONF)
$(ACLOCAL_M4):  $(am__aclocal_m4_deps)
	$(am__cd) $(srcdir) && $(ACLOCAL) $(ACLOCAL_AMFLAGS)
$(am__aclocal_m4_deps):

config.h: stamp-h1
	@test -f $@ || rm -f stamp-h1
	@test -f $@ || $(MAKE) $(AM_MAKEFLAGS) stamp-h1

stamp-h1: $(srcdir)/config.h.in $(top_builddir)/config.status
	@rm -f stamp-h1
	cd $(top_builddir) && $(SHELL) ./config.status config.h
$(srcdir)/config.h.in:  $(am__configure_deps) 
	($(am__cd) $(top_srcdir) && $(AUTOHEADER))
	rm -f stamp-h1
	touch $@

distclean-hdr:
	-rm -f config.h stamp-h1
install-binPROGRAMS: $(bin_PROGRAMS)
	@$(NORMAL_INSTALL)
	@list='$(bin_PROGRAMS)'; test -n "$(bindir)" || list=; \
	if test -n "$$list"; then \
	  echo " $(MKDIR_P) '$(DESTDIR)$(bindir)'"; \
	  $(MKDIR_P) "$(DESTDIR)$(bindir)" || exit 1; \
	fi; \
	for p in $$list; do echo "$$p $$p"; done | \
	sed 's/$(EXEEXT)$$//' | \
	while read p p1; do if test -f $$p \
	 || test -f $$p1 \
	  ; then echo "$$p"; echo "$$p"; else :; fi; \
	done | \
	sed -e 'p;s,.*/,,;n;h' \
	    -e 's|.*|.|' \
	    -e 'p;x;s,.*/,,;s/$(EXEEXT)$$//;$(transform);s/$$/$(EXEEXT)/' | \
	sed 'N;N;N;s,\n, ,g' | \
	$(AWK) 'BEGIN { files["."] = ""; dirs["."] = 1 } \
	  { d=$$3; if (dirs[d] != 1) { print "d", d; dirs[d] = 1 } \
	    if ($$2 == $$4) files[d] = files[d] " " $$1; \
	    else { print "f", $$3 "/" $$4, $$1; } } \
	  END { for (d in files) print "f", d, files[d] }' | \
	while read type dir files; do \
	    if test "$$dir" = .; then dir=; else dir=/$$dir; fi; \
	    test -z "$$files" || { \
	    echo " $(INSTALL_PROGRAM_ENV) $(LIBTOOL) $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=install $(INSTALL_PROGRAM) $$files '$(DESTDIR)$(bindir)$$dir'"; \
	    $(INSTALL_PROGRAM_ENV) $(LIBTOOL) $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=install $(INSTALL_PROGRAM) $$files "$(DESTDIR)$(bindir)$$dir" || exit $$?; \
	    } \
	; done

uninstall-binPROGRAMS:
	@$(NORMAL_UNINSTALL)
	@list='$(bin_PROGRAMS)'; test -n "$(bindir)" || list=; \
	files=`for p in $$list; do echo "$$p"; done | \
	  sed -e 'h;s,^.*/,,;s/$(EXEEXT)$$//;$(transform)' \
	      -e 's/$$/$(EXEEXT)/' \
	`; \
	test -n "$$list" || exit 0; \
	echo " ( cd '$(DESTDIR)$(bindir)' && rm -f" $$files ")"; \
	cd "$(DESTDIR)$(bindir)" && rm -f $$files

clean-binPROGRAMS:
	@list='$(bin_PROGRAMS)'; test -n "$$list" || exit 0; \
	echo " rm -f" $$list; \
	rm -f $$list || exit $$?; \
	test -n "$(EXEEXT)" || exit 0; \
	list=`for p in $$list; do echo "$$p"; done | sed 's/$(EXEEXT)$$//'`; \
	echo " rm -f" $$list; \
	rm -f $$list

assignment2$(EXEEXT): $(assignment2_OBJECTS) $(assignment2_DEPENDENCIES) $(EXTRA_assignment2_DEPENDENCIES) 
	@rm -f assignment2$(EXEEXT)
	$(AM_V_CXXLD)$(assignment2_LINK) $(assignment2_OBJECTS) $(assignment2_LDADD) $(LIBS)

mostlyclean-compile:
	-rm -f *.$(OBJEXT)

distclean-compile:
	-rm -f *.tab.c

include ./$(DEPDIR)/assignment2-Ball.Po
include ./$(DEPDIR)/assignment2-BaseApplication.Po
include ./$(DEPDIR)/assignment2-GameManager.Po
include ./$(DEPDIR)/assignment2-MyMotionState.Po
include ./$(DEPDIR)/assignment2-Paddle.Po
include ./$(DEPDIR)/assignment2-Physics.Po
include ./$(DEPDIR)/assignment2-Room.Po

.cpp.o:
	$(AM_V_CXX)$(CXXCOMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $<
	$(AM_V_at)$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po
#	$(AM_V_CXX)source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(CXXCOMPILE) -c -o $@ $<

.cpp.obj:
	$(AM_V_CXX)$(CXXCOMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ `$(CYGPATH_W) '$<'`
	$(AM_V_at)$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po
#	$(AM_V_CXX)source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(CXXCOMPILE) -c -o $@ `$(CYGPATH_W) '$<'`

.cpp.lo:
	$(AM_V_CXX)$(LTCXXCOMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $<
	$(AM_V_at)$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Plo
#	$(AM_V_CXX)source='$<' object='$@' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(LTCXXCOMPILE) -c -o $@ $<

assignment2-BaseApplication.o: BaseApplication.cpp
	$(AM_V_CXX)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -MT assignment2-BaseApplication.o -MD -MP -MF $(DEPDIR)/assignment2-BaseApplication.Tpo -c -o assignment2-BaseApplication.o `test -f 'BaseApplication.cpp' || echo '$(srcdir)/'`BaseApplication.cpp
	$(AM_V_at)$(am__mv) $(DEPDIR)/assignment2-BaseApplication.Tpo $(DEPDIR)/assignment2-BaseApplication.Po
#	$(AM_V_CXX)source='BaseApplication.cpp' object='assignment2-BaseApplication.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -c -o assignment2-BaseApplication.o `test -f 'BaseApplication.cpp' || echo '$(srcdir)/'`BaseApplication.cpp

assignment2-BaseApplication.obj: BaseApplication.cpp
	$(AM_V_CXX)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -MT assignment2-BaseApplication.obj -MD -MP -MF $(DEPDIR)/assignment2-BaseApplication.Tpo -c -o assignment2-BaseApplication.obj `if test -f 'BaseApplication.cpp'; then $(CYGPATH_W) 'BaseApplication.cpp'; else $(CYGPATH_W) '$(srcdir)/BaseApplication.cpp'; fi`
	$(AM_V_at)$(am__mv) $(DEPDIR)/assignment2-BaseApplication.Tpo $(DEPDIR)/assignment2-BaseApplication.Po
#	$(AM_V_CXX)source='BaseApplication.cpp' object='assignment2-BaseApplication.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -c -o assignment2-BaseApplication.obj `if test -f 'BaseApplication.cpp'; then $(CYGPATH_W) 'BaseApplication.cpp'; else $(CYGPATH_W) '$(srcdir)/BaseApplication.cpp'; fi`

assignment2-GameManager.o: GameManager.cpp
	$(AM_V_CXX)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -MT assignment2-GameManager.o -MD -MP -MF $(DEPDIR)/assignment2-GameManager.Tpo -c -o assignment2-GameManager.o `test -f 'GameManager.cpp' || echo '$(srcdir)/'`GameManager.cpp
	$(AM_V_at)$(am__mv) $(DEPDIR)/assignment2-GameManager.Tpo $(DEPDIR)/assignment2-GameManager.Po
#	$(AM_V_CXX)source='GameManager.cpp' object='assignment2-GameManager.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -c -o assignment2-GameManager.o `test -f 'GameManager.cpp' || echo '$(srcdir)/'`GameManager.cpp

assignment2-GameManager.obj: GameManager.cpp
	$(AM_V_CXX)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -MT assignment2-GameManager.obj -MD -MP -MF $(DEPDIR)/assignment2-GameManager.Tpo -c -o assignment2-GameManager.obj `if test -f 'GameManager.cpp'; then $(CYGPATH_W) 'GameManager.cpp'; else $(CYGPATH_W) '$(srcdir)/GameManager.cpp'; fi`
	$(AM_V_at)$(am__mv) $(DEPDIR)/assignment2-GameManager.Tpo $(DEPDIR)/assignment2-GameManager.Po
#	$(AM_V_CXX)source='GameManager.cpp' object='assignment2-GameManager.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -c -o assignment2-GameManager.obj `if test -f 'GameManager.cpp'; then $(CYGPATH_W) 'GameManager.cpp'; else $(CYGPATH_W) '$(srcdir)/GameManager.cpp'; fi`

assignment2-Physics.o: Physics.cpp
	$(AM_V_CXX)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -MT assignment2-Physics.o -MD -MP -MF $(DEPDIR)/assignment2-Physics.Tpo -c -o assignment2-Physics.o `test -f 'Physics.cpp' || echo '$(srcdir)/'`Physics.cpp
	$(AM_V_at)$(am__mv) $(DEPDIR)/assignment2-Physics.Tpo $(DEPDIR)/assignment2-Physics.Po
#	$(AM_V_CXX)source='Physics.cpp' object='assignment2-Physics.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -c -o assignment2-Physics.o `test -f 'Physics.cpp' || echo '$(srcdir)/'`Physics.cpp

assignment2-Physics.obj: Physics.cpp
	$(AM_V_CXX)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -MT assignment2-Physics.obj -MD -MP -MF $(DEPDIR)/assignment2-Physics.Tpo -c -o assignment2-Physics.obj `if test -f 'Physics.cpp'; then $(CYGPATH_W) 'Physics.cpp'; else $(CYGPATH_W) '$(srcdir)/Physics.cpp'; fi`
	$(AM_V_at)$(am__mv) $(DEPDIR)/assignment2-Physics.Tpo $(DEPDIR)/assignment2-Physics.Po
#	$(AM_V_CXX)source='Physics.cpp' object='assignment2-Physics.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -c -o assignment2-Physics.obj `if test -f 'Physics.cpp'; then $(CYGPATH_W) 'Physics.cpp'; else $(CYGPATH_W) '$(srcdir)/Physics.cpp'; fi`

assignment2-Room.o: Room.cpp
	$(AM_V_CXX)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -MT assignment2-Room.o -MD -MP -MF $(DEPDIR)/assignment2-Room.Tpo -c -o assignment2-Room.o `test -f 'Room.cpp' || echo '$(srcdir)/'`Room.cpp
	$(AM_V_at)$(am__mv) $(DEPDIR)/assignment2-Room.Tpo $(DEPDIR)/assignment2-Room.Po
#	$(AM_V_CXX)source='Room.cpp' object='assignment2-Room.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -c -o assignment2-Room.o `test -f 'Room.cpp' || echo '$(srcdir)/'`Room.cpp

assignment2-Room.obj: Room.cpp
	$(AM_V_CXX)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -MT assignment2-Room.obj -MD -MP -MF $(DEPDIR)/assignment2-Room.Tpo -c -o assignment2-Room.obj `if test -f 'Room.cpp'; then $(CYGPATH_W) 'Room.cpp'; else $(CYGPATH_W) '$(srcdir)/Room.cpp'; fi`
	$(AM_V_at)$(am__mv) $(DEPDIR)/assignment2-Room.Tpo $(DEPDIR)/assignment2-Room.Po
#	$(AM_V_CXX)source='Room.cpp' object='assignment2-Room.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -c -o assignment2-Room.obj `if test -f 'Room.cpp'; then $(CYGPATH_W) 'Room.cpp'; else $(CYGPATH_W) '$(srcdir)/Room.cpp'; fi`

assignment2-MyMotionState.o: MyMotionState.cpp
	$(AM_V_CXX)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -MT assignment2-MyMotionState.o -MD -MP -MF $(DEPDIR)/assignment2-MyMotionState.Tpo -c -o assignment2-MyMotionState.o `test -f 'MyMotionState.cpp' || echo '$(srcdir)/'`MyMotionState.cpp
	$(AM_V_at)$(am__mv) $(DEPDIR)/assignment2-MyMotionState.Tpo $(DEPDIR)/assignment2-MyMotionState.Po
#	$(AM_V_CXX)source='MyMotionState.cpp' object='assignment2-MyMotionState.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -c -o assignment2-MyMotionState.o `test -f 'MyMotionState.cpp' || echo '$(srcdir)/'`MyMotionState.cpp

assignment2-MyMotionState.obj: MyMotionState.cpp
	$(AM_V_CXX)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -MT assignment2-MyMotionState.obj -MD -MP -MF $(DEPDIR)/assignment2-MyMotionState.Tpo -c -o assignment2-MyMotionState.obj `if test -f 'MyMotionState.cpp'; then $(CYGPATH_W) 'MyMotionState.cpp'; else $(CYGPATH_W) '$(srcdir)/MyMotionState.cpp'; fi`
	$(AM_V_at)$(am__mv) $(DEPDIR)/assignment2-MyMotionState.Tpo $(DEPDIR)/assignment2-MyMotionState.Po
#	$(AM_V_CXX)source='MyMotionState.cpp' object='assignment2-MyMotionState.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -c -o assignment2-MyMotionState.obj `if test -f 'MyMotionState.cpp'; then $(CYGPATH_W) 'MyMotionState.cpp'; else $(CYGPATH_W) '$(srcdir)/MyMotionState.cpp'; fi`

assignment2-Ball.o: Ball.cpp
	$(AM_V_CXX)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -MT assignment2-Ball.o -MD -MP -MF $(DEPDIR)/assignment2-Ball.Tpo -c -o assignment2-Ball.o `test -f 'Ball.cpp' || echo '$(srcdir)/'`Ball.cpp
	$(AM_V_at)$(am__mv) $(DEPDIR)/assignment2-Ball.Tpo $(DEPDIR)/assignment2-Ball.Po
#	$(AM_V_CXX)source='Ball.cpp' object='assignment2-Ball.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -c -o assignment2-Ball.o `test -f 'Ball.cpp' || echo '$(srcdir)/'`Ball.cpp

assignment2-Ball.obj: Ball.cpp
	$(AM_V_CXX)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -MT assignment2-Ball.obj -MD -MP -MF $(DEPDIR)/assignment2-Ball.Tpo -c -o assignment2-Ball.obj `if test -f 'Ball.cpp'; then $(CYGPATH_W) 'Ball.cpp'; else $(CYGPATH_W) '$(srcdir)/Ball.cpp'; fi`
	$(AM_V_at)$(am__mv) $(DEPDIR)/assignment2-Ball.Tpo $(DEPDIR)/assignment2-Ball.Po
#	$(AM_V_CXX)source='Ball.cpp' object='assignment2-Ball.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -c -o assignment2-Ball.obj `if test -f 'Ball.cpp'; then $(CYGPATH_W) 'Ball.cpp'; else $(CYGPATH_W) '$(srcdir)/Ball.cpp'; fi`

assignment2-Paddle.o: Paddle.cpp
	$(AM_V_CXX)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -MT assignment2-Paddle.o -MD -MP -MF $(DEPDIR)/assignment2-Paddle.Tpo -c -o assignment2-Paddle.o `test -f 'Paddle.cpp' || echo '$(srcdir)/'`Paddle.cpp
	$(AM_V_at)$(am__mv) $(DEPDIR)/assignment2-Paddle.Tpo $(DEPDIR)/assignment2-Paddle.Po
#	$(AM_V_CXX)source='Paddle.cpp' object='assignment2-Paddle.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -c -o assignment2-Paddle.o `test -f 'Paddle.cpp' || echo '$(srcdir)/'`Paddle.cpp

assignment2-Paddle.obj: Paddle.cpp
	$(AM_V_CXX)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -MT assignment2-Paddle.obj -MD -MP -MF $(DEPDIR)/assignment2-Paddle.Tpo -c -o assignment2-Paddle.obj `if test -f 'Paddle.cpp'; then $(CYGPATH_W) 'Paddle.cpp'; else $(CYGPATH_W) '$(srcdir)/Paddle.cpp'; fi`
	$(AM_V_at)$(am__mv) $(DEPDIR)/assignment2-Paddle.Tpo $(DEPDIR)/assignment2-Paddle.Po
#	$(AM_V_CXX)source='Paddle.cpp' object='assignment2-Paddle.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CXXDEPMODE) $(depcomp) \
#	$(AM_V_CXX_no)$(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(assignment2_CPPFLAGS) $(CPPFLAGS) $(assignment2_CXXFLAGS) $(CXXFLAGS) -c -o assignment2-Paddle.obj `if test -f 'Paddle.cpp'; then $(CYGPATH_W) 'Paddle.cpp'; else $(CYGPATH_W) '$(srcdir)/Paddle.cpp'; fi`

mostlyclean-libtool:
	-rm -f *.lo

clean-libtool:
	-rm -rf .libs _libs

distclean-libtool:
	-rm -f libtool config.lt

ID: $(am__tagged_files)
	$(am__define_uniq_tagged_files); mkid -fID $$unique
tags: tags-am
TAGS: tags

tags-am: $(TAGS_DEPENDENCIES) $(am__tagged_files)
	set x; \
	here=`pwd`; \
	$(am__define_uniq_tagged_files); \
	shift; \
	if test -z "$(ETAGS_ARGS)$$*$$unique"; then :; else \
	  test -n "$$unique" || unique=$$empty_fix; \
	  if test $$# -gt 0; then \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      "$$@" $$unique; \
	  else \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      $$unique; \
	  fi; \
	fi
ctags: ctags-am

CTAGS: ctags
ctags-am: $(TAGS_DEPENDENCIES) $(am__tagged_files)
	$(am__define_uniq_tagged_files); \
	test -z "$(CTAGS_ARGS)$$unique" \
	  || $(CTAGS) $(CTAGSFLAGS) $(AM_CTAGSFLAGS) $(CTAGS_ARGS) \
	     $$unique

GTAGS:
	here=`$(am__cd) $(top_builddir) && pwd` \
	  && $(am__cd) $(top_srcdir) \
	  && gtags -i $(GTAGS_ARGS) "$$here"
cscope: cscope.files
	test ! -s cscope.files \
	  || $(CSCOPE) -b -q $(AM_CSCOPEFLAGS) $(CSCOPEFLAGS) -i cscope.files $(CSCOPE_ARGS)
clean-cscope:
	-rm -f cscope.files
cscope.files: clean-cscope cscopelist
cscopelist: cscopelist-am

cscopelist-am: $(am__tagged_files)
	list='$(am__tagged_files)'; \
	case "$(srcdir)" in \
	  [\\/]* | ?:[\\/]*) sdir="$(srcdir)" ;; \
	  *) sdir=$(subdir)/$(srcdir) ;; \
	esac; \
	for i in $$list; do \
	  if test -f "$$i"; then \
	    echo "$(subdir)/$$i"; \
	  else \
	    echo "$$sdir/$$i"; \
	  fi; \
	done >> $(top_builddir)/cscope.files

distclean-tags:
	-rm -f TAGS ID GTAGS GRTAGS GSYMS GPATH tags
	-rm -f cscope.out cscope.in.out cscope.po.out cscope.files

distdir: $(DISTFILES)
	$(am__remove_distdir)
	test -d "$(distdir)" || mkdir "$(distdir)"
	@srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	topsrcdirstrip=`echo "$(top_srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	list='$(DISTFILES)'; \
	  dist_files=`for file in $$list; do echo $$file; done | \
	  sed -e "s|^$$srcdirstrip/||;t" \
	      -e "s|^$$topsrcdirstrip/|$(top_builddir)/|;t"`; \
	case $$dist_files in \
	  */*) $(MKDIR_P) `echo "$$dist_files" | \
			   sed '/\//!d;s|^|$(distdir)/|;s,/[^/]*$$,,' | \
			   sort -u` ;; \
	esac; \
	for file in $$dist_files; do \
	  if test -f $$file || test -d $$file; then d=.; else d=$(srcdir); fi; \
	  if test -d $$d/$$file; then \
	    dir=`echo "/$$file" | sed -e 's,/[^/]*$$,,'`; \
	    if test -d "$(distdir)/$$file"; then \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    if test -d $(srcdir)/$$file && test $$d != $(srcdir); then \
	      cp -fpR $(srcdir)/$$file "$(distdir)$$dir" || exit 1; \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    cp -fpR $$d/$$file "$(distdir)$$dir" || exit 1; \
	  else \
	    test -f "$(distdir)/$$file" \
	    || cp -p $$d/$$file "$(distdir)/$$file" \
	    || exit 1; \
	  fi; \
	done
	-test -n "$(am__skip_mode_fix)" \
	|| find "$(distdir)" -type d ! -perm -755 \
		-exec chmod u+rwx,go+rx {} \; -o \
	  ! -type d ! -perm -444 -links 1 -exec chmod a+r {} \; -o \
	  ! -type d ! -perm -400 -exec chmod a+r {} \; -o \
	  ! -type d ! -perm -444 -exec $(install_sh) -c -m a+r {} {} \; \
	|| chmod -R a+r "$(distdir)"
dist-gzip: distdir
	tardir=$(distdir) && $(am__tar) | GZIP=$(GZIP_ENV) gzip -c >$(distdir).tar.gz
	$(am__post_remove_distdir)

dist-bzip2: distdir
	tardir=$(distdir) && $(am__tar) | BZIP2=$${BZIP2--9} bzip2 -c >$(distdir).tar.bz2
	$(am__post_remove_distdir)

dist-lzip: distdir
	tardir=$(distdir) && $(am__tar) | lzip -c $${LZIP_OPT--9} >$(distdir).tar.lz
	$(am__post_remove_distdir)

dist-xz: distdir
	tardir=$(distdir) && $(am__tar) | XZ_OPT=$${XZ_OPT--e} xz -c >$(distdir).tar.xz
	$(am__post_remove_distdir)

dist-tarZ: distdir
	@echo WARNING: "Support for shar distribution archives is" \
	               "deprecated." >&2
	@echo WARNING: "It will be removed altogether in Automake 2.0" >&2
	tardir=$(distdir) && $(am__tar) | compress -c >$(distdir).tar.Z
	$(am__post_remove_distdir)

dist-shar: distdir
	@echo WARNING: "Support for distribution archives compressed with" \
		       "legacy program 'compress' is deprecated." >&2
	@echo WARNING: "It will be removed altogether in Automake 2.0" >&2
	shar $(distdir) | GZIP=$(GZIP_ENV) gzip -c >$(distdir).shar.gz
	$(am__post_remove_distdir)

dist-zip: distdir
	-rm -f $(distdir).zip
	zip -rq $(distdir).zip $(distdir)
	$(am__post_remove_distdir)

dist dist-all:
	$(MAKE) $(AM_MAKEFLAGS) $(DIST_TARGETS) am__post_remove_distdir='@:'
	$(am__post_remove_distdir)

# This target untars the dist file and tries a VPATH configuration.  Then
# it guarantees that the distribution is self-contained by making another
# tarfile.
distcheck: dist
	case '$(DIST_ARCHIVES)' in \
	*.tar.gz*) \
	  GZIP=$(GZIP_ENV) gzip -dc $(distdir).tar.gz | $(am__untar) ;;\
	*.tar.bz2*) \
	  bzip2 -dc $(distdir).tar.bz2 | $(am__untar) ;;\
	*.tar.lz*) \
	  lzip -dc $(distdir).tar.lz | $(am__untar) ;;\
	*.tar.xz*) \
	  xz -dc $(distdir).tar.xz | $(am__untar) ;;\
	*.tar.Z*) \
	  uncompress -c $(distdir).tar.Z | $(am__untar) ;;\
	*.shar.gz*) \
	  GZIP=$(GZIP_ENV) gzip -dc $(distdir).shar.gz | unshar ;;\
	*.zip*) \
	  unzip $(distdir).zip ;;\
	esac
	chmod -R a-w $(distdir)
	chmod u+w $(distdir)
	mkdir $(distdir)/_build $(distdir)/_inst
	chmod a-w $(distdir)
	test -d $(distdir)/_build || exit 0; \
	dc_install_base=`$(am__cd) $(distdir)/_inst && pwd | sed -e 's,^[^:\\/]:[\\/],/,'` \
	  && dc_destdir="$${TMPDIR-/tmp}/am-dc-$$$$/" \
	  && am__cwd=`pwd` \
	  && $(am__cd) $(distdir)/_build \
	  && ../configure \
	    $(AM_DISTCHECK_CONFIGURE_FLAGS) \
	    $(DISTCHECK_CONFIGURE_FLAGS) \
	    --srcdir=.. --prefix="$$dc_install_base" \
	  && $(MAKE) $(AM_MAKEFLAGS) \
	  && $(MAKE) $(AM_MAKEFLAGS) dvi \
	  && $(MAKE) $(AM_MAKEFLAGS) check \
	  && $(MAKE) $(AM_MAKEFLAGS) install \
	  && $(MAKE) $(AM_MAKEFLAGS) installcheck \
	  && $(MAKE) $(AM_MAKEFLAGS) uninstall \
	  && $(MAKE) $(AM_MAKEFLAGS) distuninstallcheck_dir="$$dc_install_base" \
	        distuninstallcheck \
	  && chmod -R a-w "$$dc_install_base" \
	  && ({ \
	       (cd ../.. && umask 077 && mkdir "$$dc_destdir") \
	       && $(MAKE) $(AM_MAKEFLAGS) DESTDIR="$$dc_destdir" install \
	       && $(MAKE) $(AM_MAKEFLAGS) DESTDIR="$$dc_destdir" uninstall \
	       && $(MAKE) $(AM_MAKEFLAGS) DESTDIR="$$dc_destdir" \
	            distuninstallcheck_dir="$$dc_destdir" distuninstallcheck; \
	      } || { rm -rf "$$dc_destdir"; exit 1; }) \
	  && rm -rf "$$dc_destdir" \
	  && $(MAKE) $(AM_MAKEFLAGS) dist \
	  && rm -rf $(DIST_ARCHIVES) \
	  && $(MAKE) $(AM_MAKEFLAGS) distcleancheck \
	  && cd "$$am__cwd" \
	  || exit 1
	$(am__post_remove_distdir)
	@(echo "$(distdir) archives ready for distribution: "; \
	  list='$(DIST_ARCHIVES)'; for i in $$list; do echo $$i; done) | \
	  sed -e 1h -e 1s/./=/g -e 1p -e 1x -e '$$p' -e '$$x'
distuninstallcheck:
	@test -n '$(distuninstallcheck_dir)' || { \
	  echo 'ERROR: trying to run $@ with an empty' \
	       '$$(distuninstallcheck_dir)' >&2; \
	  exit 1; \
	}; \
	$(am__cd) '$(distuninstallcheck_dir)' || { \
	  echo 'ERROR: cannot chdir into $(distuninstallcheck_dir)' >&2; \
	  exit 1; \
	}; \
	test `$(am__distuninstallcheck_listfiles) | wc -l` -eq 0 \
	   || { echo "ERROR: files left after uninstall:" ; \
	        if test -n "$(DESTDIR)"; then \
	          echo "  (check DESTDIR support)"; \
	        fi ; \
	        $(distuninstallcheck_listfiles) ; \
	        exit 1; } >&2
distcleancheck: distclean
	@if test '$(srcdir)' = . ; then \
	  echo "ERROR: distcleancheck can only run from a VPATH build" ; \
	  exit 1 ; \
	fi
	@test `$(distcleancheck_listfiles) | wc -l` -eq 0 \
	  || { echo "ERROR: files left in build directory after distclean:" ; \
	       $(distcleancheck_listfiles) ; \
	       exit 1; } >&2
check-am: all-am
check: check-am
all-am: Makefile $(PROGRAMS) $(HEADERS) config.h
installdirs:
	for dir in "$(DESTDIR)$(bindir)"; do \
	  test -z "$$dir" || $(MKDIR_P) "$$dir"; \
	done
install: install-am
install-exec: install-exec-am
install-data: install-data-am
uninstall: uninstall-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am

installcheck: installcheck-am
install-strip:
	if test -z '$(STRIP)'; then \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	      install; \
	else \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	    "INSTALL_PROGRAM_ENV=STRIPPROG='$(STRIP)'" install; \
	fi
mostlyclean-generic:

clean-generic:

distclean-generic:
	-test -z "$(CONFIG_CLEAN_FILES)" || rm -f $(CONFIG_CLEAN_FILES)
	-test . = "$(srcdir)" || test -z "$(CONFIG_CLEAN_VPATH_FILES)" || rm -f $(CONFIG_CLEAN_VPATH_FILES)

maintainer-clean-generic:
	@echo "This command is intended for maintainers to use"
	@echo "it deletes files that may require special tools to rebuild."
clean: clean-am

clean-am: clean-binPROGRAMS clean-generic clean-libtool mostlyclean-am

distclean: distclean-am
	-rm -f $(am__CONFIG_DISTCLEAN_FILES)
	-rm -rf ./$(DEPDIR)
	-rm -f Makefile
distclean-am: clean-am distclean-compile distclean-generic \
	distclean-hdr distclean-libtool distclean-tags

dvi: dvi-am

dvi-am:

html: html-am

html-am:

info: info-am

info-am:

install-data-am:

install-dvi: install-dvi-am

install-dvi-am:

install-exec-am: install-binPROGRAMS

install-html: install-html-am

install-html-am:

install-info: install-info-am

install-info-am:

install-man:

install-pdf: install-pdf-am

install-pdf-am:

install-ps: install-ps-am

install-ps-am:

installcheck-am:

maintainer-clean: maintainer-clean-am
	-rm -f $(am__CONFIG_DISTCLEAN_FILES)
	-rm -rf $(top_srcdir)/autom4te.cache
	-rm -rf ./$(DEPDIR)
	-rm -f Makefile
maintainer-clean-am: distclean-am maintainer-clean-generic

mostlyclean: mostlyclean-am

mostlyclean-am: mostlyclean-compile mostlyclean-generic \
	mostlyclean-libtool

pdf: pdf-am

pdf-am:

ps: ps-am

ps-am:

uninstall-am: uninstall-binPROGRAMS

.MAKE: all install-am install-strip

.PHONY: CTAGS GTAGS TAGS all all-am am--refresh check check-am clean \
	clean-binPROGRAMS clean-cscope clean-generic clean-libtool \
	cscope cscopelist-am ctags ctags-am dist dist-all dist-bzip2 \
	dist-gzip dist-lzip dist-shar dist-tarZ dist-xz dist-zip \
	distcheck distclean distclean-compile distclean-generic \
	distclean-hdr distclean-libtool distclean-tags distcleancheck \
	distdir distuninstallcheck dvi dvi-am html html-am info \
	info-am install install-am install-binPROGRAMS install-data \
	install-data-am install-dvi install-dvi-am install-exec \
	install-exec-am install-html install-html-am install-info \
	install-info-am install-man install-pdf install-pdf-am \
	install-ps install-ps-am install-strip installcheck \
	installcheck-am installdirs maintainer-clean \
	maintainer-clean-generic mostlyclean mostlyclean-compile \
	mostlyclean-generic mostlyclean-libtool pdf pdf-am ps ps-am \
	tags tags-am uninstall uninstall-am uninstall-binPROGRAMS


# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
