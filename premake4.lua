solution "liblzma"
   configurations { "Debug", "Release" }
   project "lzma"
      kind "StaticLib"
      language "C"
      basedir "."      
      targetdir "./lib"
      files { "src/**.c", "src/**.h" }
      includedirs { "src/common", "src/api", "src/check" ,"src/delta", "src/lz", "src/lzma", "src/rangecoder", "src/simple", "src/subblock", "src/add_include"}
      defines { "HAVE_CONFIG_H", "HAVE_STDBOOL_H" }
      buildoptions { "-std=c99" }
      
      configuration { "windows", "gmake" }
   	postbuildcommands { "lib.exe -out:lib/lzma.lib -nologo $(OBJECTS)" }
	
