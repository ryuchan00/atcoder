def init
  $s = $stdin.gets.chomp
end

init

def puts_and_exit
  puts 'NO'
  exit
end

puts_and_exit unless $s =~ /^(dream|dreamer|erase|eraser){1,}$/
puts 'YES'