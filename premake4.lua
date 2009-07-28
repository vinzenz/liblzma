solution "liblzma"
   configurations { "Debug", "Release" }
   project "lzma"
      kind "StaticLib"
      language "C"
      basedir "."
      files { "**.c", "**.h" }
      includedirs { "common", "api", "check" ,"delta", "lz", "lzma", "rangecoder", "simple", "subblock", "add_include"}
      defines { "HAVE_CONFIG_H", "HAVE_STDBOOL_H" }
      buildoptions { "-std=c99" }

