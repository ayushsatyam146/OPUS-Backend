rm -rf build
mkdir build
cd build && cmake \.\. && cd ..
cd build && make
cd src && .\/app && cd .. && cd ..
