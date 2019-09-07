gets.to_i
a = gets.split.map(&:to_i)
b = gets.split.map(&:to_i)
c = gets.split.map(&:to_i)
old = nil
sum = 0
a.each do |i|
  i -= 1
  sum += b[i]
  sum += c[i -1] if old == (i - 1)
  old = i
end
puts sum