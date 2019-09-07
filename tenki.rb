s = gets.chomp.chars
answer = 0
gets.chomp.chars.each_with_index { |v, i| answer += 1 if v == s[i] }
puts answer