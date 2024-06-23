#!/usr/bin/env ruby

third_party_path = __dir__
juce_path = "#{third_party_path}/juce"
# TODO empty build_dir
build_dir = "#{third_party_path}/build"
RELEASE_MODE='Debug'
IS_STATIC='ON'

def build(path, build_dir, target_name)

  # path to source, path to build
  # build static binary
  result = system(
    'cmake',
    '-S', path,
    '-B', build_dir,
    '-D', "CMAKE_BUILD_TYPE=#{RELEASE_MODE}",
    '-G', 'Ninja',
    '-DBUILD_SHARED_LIBS=OFF',
  )

  unless result == true
    raise 'Failed to configure build'
  end

  # List all targets with `cmake --build ./build --target help`
  result = system(
    'cmake', '--build', build_dir, '--target', target_name
  )

  unless result == true
    raise 'Failed to configure build'
  end
end

build juce_path, build_dir, 'Projucer'
