final: UtPod_driver.o UtPod.o Song.o
	g++ -otest  UtPod_driver.o UtPod.o Song.o
driver: UtPod_driver.cpp UtPod.h Song.h
	g++ -c UtPod_driver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ -c UtPod.cpp
song.o: Song.cpp Song.h
	g++ -c Song.cpp