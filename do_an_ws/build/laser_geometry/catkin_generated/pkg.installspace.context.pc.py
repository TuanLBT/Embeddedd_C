# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include;/usr/include;/usr/include/eigen3".split(';') if "${prefix}/include;/usr/include;/usr/include/eigen3" != "" else []
PROJECT_CATKIN_DEPENDS = "tf;tf2".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-llaser_geometry;/usr/lib/arm-linux-gnueabihf/libboost_system.so;/usr/lib/arm-linux-gnueabihf/libboost_thread.so;-pthread;/usr/lib/arm-linux-gnueabihf/libboost_chrono.so;/usr/lib/arm-linux-gnueabihf/libboost_date_time.so;/usr/lib/arm-linux-gnueabihf/libboost_atomic.so".split(';') if "-llaser_geometry;/usr/lib/arm-linux-gnueabihf/libboost_system.so;/usr/lib/arm-linux-gnueabihf/libboost_thread.so;-pthread;/usr/lib/arm-linux-gnueabihf/libboost_chrono.so;/usr/lib/arm-linux-gnueabihf/libboost_date_time.so;/usr/lib/arm-linux-gnueabihf/libboost_atomic.so" != "" else []
PROJECT_NAME = "laser_geometry"
PROJECT_SPACE_DIR = "/home/pi/do_an_ws/install"
PROJECT_VERSION = "1.6.7"
