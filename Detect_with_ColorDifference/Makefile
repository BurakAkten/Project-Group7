all: compile

compile: fileContent.o main.o
	g++ main.o -o exe fileContent.o -I/usr/local/include/opencv -I/usr/local/include -L/usr/local/lib -lopencv_stitching -lopencv_superres -lopencv_videostab -lopencv_photo -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dpm -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_img_hash -lopencv_line_descriptor -lopencv_optflow -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_dnn -lopencv_plot -lopencv_xfeatures2d -lopencv_shape -lopencv_video -lopencv_ml -lopencv_ximgproc -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_flann -lopencv_xobjdetect -lopencv_imgcodecs -lopencv_objdetect -lopencv_xphoto -lopencv_imgproc -lopencv_core

uici.o: uici.c uici.h
	gcc -c uici.c 

uiciname.o: uiciname.c uiciname.h
	gcc -c uiciname.c 

restart.o: restart.c restart.h
	gcc -c restart.c 

clean:
	 rm *.o exe


main.o: main.cpp
	g++ -c -std=c++11 main.cpp

fileContent.o: fileContent.cpp
	g++ -c -std=c++11 fileContent.cpp

clean:
	rm *.o exe
	clear

