# ./add_widgets.sh


# compile and run
mkdir -p build

cd ./build

cmake .. &&
make -j5 &&
./widgets_browser