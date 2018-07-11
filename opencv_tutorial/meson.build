project('opencv_tutorial', 'cpp', 'c',
        default_options : ['c_std=c11', 'cpp_std=c++11'])
#add_global_arguments('-std=c11', language: 'c')
#add_global_arguments('-std=c++11', language: 'cpp')
opencv_dep = dependency('opencv')
#executable('opencv_result', 'display_image.cpp', 'main.c', dependencies: opencv_dep)
lib = shared_library('imagelib', 'display_image.cpp', dependencies: opencv_dep)
executable('opencv_result', 'main.c', link_with: lib)