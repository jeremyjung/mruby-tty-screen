MRuby::Build.new do |conf|
  # Build with Visual Studio if on a Windows machine
  if ENV['VisualStudioVersion'] || ENV['VSINSTALLDIR']
    toolchain :visualcpp
  else
    toolchain ENV.fetch('TOOLCHAIN', :clang)
  end

  if ARGV.include? 'test'
    conf.enable_debug
    conf.enable_test
  end

  conf.gem __dir__
  conf.gem "#{root}/mrbgems/mruby-bin-mirb"
end
