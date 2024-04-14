#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/pi/do_an_ws/src/qt_gui_core/qt_gui"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/pi/do_an_ws/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/pi/do_an_ws/install/lib/python3/dist-packages:/home/pi/do_an_ws/build/qt_gui/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/pi/do_an_ws/build/qt_gui" \
    "/usr/bin/python3" \
    "/home/pi/do_an_ws/src/qt_gui_core/qt_gui/setup.py" \
     \
    build --build-base "/home/pi/do_an_ws/build/qt_gui" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/pi/do_an_ws/install" --install-scripts="/home/pi/do_an_ws/install/bin"
