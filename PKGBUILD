# Maintainer: Ernesto Rodriguez <ernesto4160@gmail.com>
pkgname="framebook"
pkgver=0.1
pkgrel=1
pkgdesc="Plasma applet that shows a slideshow of your Facebook photos."
arch=(x86_64)
url="https://github.com/netogallo/FrameBook"
license=('GPLv3')
provides=('framebook')
conflicts=('framebook')
depends=('qjson' 'imagemagick' 'kdebase-plasma')
makedepends=('qjson' 'imagemagick' 'kdebase-plasma')
checkdepends=()
optdepends=()
source=()
noextract=()
md5sums=() #generate with 'makepkg -g'

build() { 
	cd $srcdir/../		
	cmake -DCMAKE_INSTALL_PREFIX=/usr/ .
	make 
}

package() {
	cd $srcdir/../
	make DESTDIR=$pkgdir install
}
