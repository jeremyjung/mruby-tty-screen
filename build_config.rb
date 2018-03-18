MRuby::Build.new do |conf|
  toolchain ENV.fetch('TOOLCHAIN', :clang)

  if ARGV.include? 'test'
    conf.enable_debug
    conf.enable_test
  end

  conf.gem __dir__
  conf.gem "#{root}/mrbgems/mruby-bin-mirb"
end
