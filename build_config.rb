MRuby::Build.new do |conf|
  if Gem.win_platform?
    toolchain ENV.fetch('TOOLCHAIN', :gcc)
  else
    toolchain ENV.fetch('TOOLCHAIN', :clang)
  end

  conf.enable_debug

  if ARGV.include? 'test'
    conf.enable_test
  end

  conf.gem __dir__
  conf.gem "#{root}/mrbgems/mruby-bin-mirb"
end
