a, b = gets.chomp.split(" ").map(&:to_i)
msg = 'Odd'
msg = 'Even' if ((a * b) % 2).zero?
puts msg