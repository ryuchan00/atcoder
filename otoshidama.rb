def init
  $n, $y = $stdin.gets.chomp.split(" ").map(&:to_i)
end

init

def puts_and_exit
  puts '-1 -1 -1'
  exit
end

puts_and_exit if $y > $n * 10000 || $n * 1000 > $y

divmod_x = $y.divmod(10000)
0.upto(divmod_x[0]) do |i|
  n_reduced_from_x = $n - i
  0.upto(n_reduced_from_x) do |j|
    y_reduced_from_x = n_reduced_from_x - j
    if $y == i * 10000 + j * 5000 + y_reduced_from_x * 1000
      puts "#{i} #{j} #{y_reduced_from_x}"
      exit
    end
  end
end
puts_and_exit