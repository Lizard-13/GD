cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0015 NEW)

project(InstanceWrapperObject)
gd_add_extension_includes()

#Defines
###
gd_add_extension_definitions(InstanceWrapperObject)

#The targets
###
include_directories(.)
file(GLOB source_files *)

gd_add_extension_target(InstanceWrapperObject "${source_files}" "JsPlatform")

#Linker files for the IDE extension
###
gd_extension_link_libraries(InstanceWrapperObject)
