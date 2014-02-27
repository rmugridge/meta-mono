SUMMARY = "GUI toolkit for Mono"
DESCRIPTION = "GTK+ bindings for Mono"
SECTION = "devel/mono"
BUGTRACKER = "http://bugzilla.xamarin.com"
DEPENDS = "mono mono-native gtk+ atk pango cairo glib-2.0 libglade "
RDEPENDS_${PN} = "mono"
LICENSE = "LGPL-2.1"

inherit autotools

# For some reason the URL template changes from version to version,
# therefore use some variables for the directory and extension
SRC_URI = "http://download.mono-project.com/sources/gtk-sharp${SDIRVER}/gtk-sharp-${PV}.tar.${SEXT}"

SDIRVER = "${@gtk_sharp_download_version(d)}"
SEXT ??= "bz2"

def gtk_sharp_download_version(d):
    pvsplit = d.getVar('PV', True).split('.')
    return pvsplit[0] + '' + pvsplit[1]

FILESPATH =. "${FILE_DIRNAME}/gtk-sharp-${PV}:"

FILES_${PN} = "\
  ${bindir}/* \
  ${libdir}/* \
"

FILES_${PN}-dbg = "\
    ${libdir}/.debug \
    ${datadir}/* \
    /usr/src/* \
"

FILES_${PN}-doc = "\
    ${libdir}/monodoc/* \
"

FILES_${PN}-dev = "\
    ${libdir}/pkgconfig \
"
