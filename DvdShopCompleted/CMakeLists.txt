cmake_minimum_required(VERSION 3.16)
project(DvdShop)

set(CMAKE_CXX_STANDARD 17)

set(DVD_SHOP_SOURCES Movie.cpp Movie.h Rental.cpp Rental.h
        ChildrensMovie.cpp ChildrensMovie.h RentalStatement.cpp RentalStatement.h
        NewReleaseMovie.cpp NewReleaseMovie.h RegularMovie.cpp RegularMovie.h)
set(TEST_SOURCES doctest.h DvdShopTest.cpp MovieTest.cpp RentalTest.cpp)

add_executable(DvdShop main.cpp ${DVD_SHOP_SOURCES})
add_executable(DvdShopTest ${DVD_SHOP_SOURCES} ${TEST_SOURCES})
