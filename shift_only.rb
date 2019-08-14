n = gets
a = gets.chomp.split(" ").map(&:to_i)
count = 0
odd = false
while true
  a.map! do |v|
    odd = true and break if v % 2 == 1
    v / 2
  end
  break if odd
  count += 1
end
puts count