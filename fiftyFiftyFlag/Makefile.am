lib_LTLIBRARIES = fiftyFiftyFlag.la

fiftyFiftyFlag_la_SOURCES = fiftyFiftyFlag.cpp
fiftyFiftyFlag_la_CPPFLAGS= -I$(top_srcdir)/include -I$(top_srcdir)/plugins/plugin_utils
fiftyFiftyFlag_la_LDFLAGS = -module -avoid-version -shared
fiftyFiftyFlag_la_LIBADD = $(top_builddir)/plugins/plugin_utils/libplugin_utils.la

AM_CPPFLAGS = $(CONF_CPPFLAGS)
AM_CFLAGS = $(CONF_CFLAGS)
AM_CXXFLAGS = $(CONF_CXXFLAGS)

EXTRA_DIST = \
	README.fiftyFiftyFlag.txt \
	fiftyFiftyFlag.sln \
	fiftyFiftyFlag.vcxproj	\
	fiftyFiftyFlag.vcxproj.filters

MAINTAINERCLEANFILES =	\
	Makefile.in
